#ifndef ASTAR_H_INCLUDED
#define ASTAR_H_INCLUDED

#include <iostream>
#include <queue>
#include "Node.h"
#include <vector>
#include<stack>
using namespace std;

class AStar{

public:
    int **goal;
    Node *qp;
    Node *goal_state = nullptr;
    Node *root;
    int NG = 0;
    int NE = 0;
    int d = 0;
    float ebf = 0;

    priority_queue<Node, vector<Node>, greater<vector<Node>::value_type>> Open_List;
    priority_queue<Node, vector<Node>, greater<vector<Node>::value_type>> Close_List;

    AStar(int **g,int go[][3], Node * r){
        goal = g;
        root = new Node(go);
        root->f_value = 0;
        root->g_value = 0;
        root->parent = nullptr;
        Open_List.push(*root);


    }

    stack<Node*> algorithm(){
        while(!Open_List.empty()){
            NE++;
            Node q = Open_List.top();
            qp = &q;

            if(qp->g_value>d)
                d = qp->g_value;

            int ** currentpuzzle = qp->getPuzzle();
            if(checkPuzzleEqual(currentpuzzle, goal)){
                goal_state = qp;
                break;
            }
            Open_List.pop();
            Close_List.push(q);
            qp->generateChildren();

            if(qp->children.down!=nullptr)
                qp->children.down->setParent(qp);

            if(qp->children.up!=nullptr)
                qp->children.up->setParent(qp);

            if(qp->children.left!=nullptr)
                qp->children.left->setParent(qp);

            if(qp->children.right!=nullptr)
                qp->children.right->setParent(qp);

            processChildren(qp->children.down);
            processChildren(qp->children.up);
            processChildren(qp->children.left);
            processChildren(qp->children.right);


        }
    stack<Node*> best_path;
    while(goal_state->parent !=nullptr){
        goal_state = goal_state->parent;
        best_path.push(goal_state);
    }
    ebf = NG/d;
    return best_path;
    }

    void processChildren(Node *s){
        if(s == nullptr)
            return;
        NG++;

        int ** currentpuzzle = s->getPuzzle();

        s->g_value = s->parent->g_value + 1;
        s->h_value = HeuristicFunction(s,this);

        s->f_value = s->g_value + s->h_value;
        if(checkPuzzleEqual(currentpuzzle, goal)){
            goal_state = s;
            }
        bool skip = false;
        vector<Node> open;

        while(!Open_List.empty()){
            Node it = Open_List.top();
            Open_List.pop();
            open.push_back(it);
            if(checkPuzzleEqual(currentpuzzle,it.getPuzzle())){
                if(it.getFVal() < s->getFVal()){
                    skip = true;
                    break;
                }
            }
        }
        for (std::vector<Node>::iterator it = open.begin() ; it != open.end(); ++it){
            Open_List.push(*it);
        }
        if(!skip){
            vector<Node> close;
            while(!Close_List.empty()){
                Node it = Close_List.top();
                Close_List.pop();
                close.push_back(it);
                if(checkPuzzleEqual(currentpuzzle,it.getPuzzle())){
                    if(it.getFVal() < s->getFVal()){
                        skip = true;
                        break;
                    }
                }
            }
            for (std::vector<Node>::iterator it = close.begin() ; it != close.end(); ++it){
                Close_List.push(*it);
            }
        }

        if(!skip){
            Node temp = *s;
            Open_List.push(temp);
        }
    }

    float (*HeuristicFunction)(Node *s, AStar * t);


    bool checkPuzzleEqual(int** current_puzzle, int** check){
        for(int r = 0; r < 3; r++ ){
            for(int c = 0; c < 3; c++ ){
                    if(check[r][c]!=current_puzzle[r][c])
                        return false;
            }
        }
        return true;
    }

};


#endif // ASTAR_H_INCLUDED
