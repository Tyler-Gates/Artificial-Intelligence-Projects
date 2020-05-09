#include <iostream>
#include "Node.h"
#include <stack>
#include "AStar.h"
#include <math.h>
using namespace std;

float h1(Node *s, AStar *t);//h1
float h2(Node* s, AStar* t);//h2
float S(Node* s, AStar* t);//S
float H(Node* s, AStar* t);//H
float h4(Node* s, AStar* t);//h4
float h5(Node* s, AStar* t);//h5


int main()
{
    int state_one[][3] = {{2,8,3}, {1,6,4}, {0,7,5}};
    int state_two[][3] = {{2,1,6}, {4,0,8}, {7,5,3}};
    int goal[][3] = {{1,2,3}, {8,0,4}, {7,6,5}};
    int **goal_p;
    goal_p = new int*[3];
    for (int r = 0; r < 3; r++)
    {
        goal_p[r] = new int[3];
        for (int c = 0; c < 3; c++)
        {
            goal_p[r][c] = goal[r][c];
        }
    }
    Node *root = new Node(state_one);// pass current state of game array
    AStar A = AStar(goal_p,state_one,root);//pass root, current state of game
                                //and the goal pointer
    A.HeuristicFunction = h1; //pass heuristic function
    stack<Node*> a=A.algorithm();//receive a stack of the best path


    cout<<"the best path"<<endl;
    while(!a.empty()){
        Node *nod = a.top();
        a.pop();
        nod->print(); //print path
    }

    cout<<"GOAL STATE REACHED"<<endl;//print goal
    cout << "--------" << endl;
    for(int r = 0; r < 3; r++ ){
        for(int c = 0; c < 3; c++ ){
            cout << "|" << goal[r][c];
        }
        cout << "|" << endl;
    }
    AStar B = AStar(goal_p,state_one,root);
    B.HeuristicFunction = h2;
    stack<Node*> b=B.algorithm();
    cout << "test"<< endl;
    AStar C = AStar(goal_p,state_one, root);
    C.HeuristicFunction = H; //pass heuristic function
    stack<Node*> c=C.algorithm();
    cout << "test"<< endl;
    AStar D = AStar(goal_p,state_one,root);
    D.HeuristicFunction = h4;
    stack<Node*> d=D.algorithm();
    cout << "test"<< endl;
    AStar E = AStar(goal_p,state_one,root);
    E.HeuristicFunction = h5;
    stack<Node*> e=E.algorithm();
    cout << "test"<< endl;
    cout << "***Initial State #1***" << endl;
    cout << "heuristic/ET/NG/NE/d/b*/MO" << endl;
    cout<<  "h1"<< "/x/"<<A.NG<<"/"<<A.NE<<"/"<<A.d<<"/"<<A.ebf<<"/"<<"x  " <<endl;
    cout<<  "h2"<< "/x/"<<B.NG<<"/"<<B.NE<<"/"<<B.d<<"/"<<B.ebf<<"/"<<"x  " <<endl;
    cout<<  "H"<< "/x/"<<C.NG<<"/"<<C.NE<<"/"<<C.d<<"/"<<C.ebf<<"/"<<"x  " <<endl;
    cout<<  "h4"<< "/x/"<<D.NG<<"/"<<D.NE<<"/"<<D.d<<"/"<<D.ebf<<"/"<<"x  " <<endl;
    cout<<  "h5"<< "/x/"<<E.NG<<"/"<<E.NE<<"/"<<E.d<<"/"<<E.ebf<<"/"<<"x  " <<endl<<endl;
    //delete &A, &B, &C, &D, &E;

    *root = new Node(state_two);
    AStar G = AStar(goal_p,state_two, root);
    G.HeuristicFunction = h1;
    stack<Node*> g=G.algorithm();
    // << "test"<< endl;
    AStar HH = AStar(goal_p,state_two, root);
    HH.HeuristicFunction = h2;
    stack<Node*> hh=HH.algorithm();
    //cout << "test"<< endl;
    AStar F = AStar(goal_p,state_two, root);
    F.HeuristicFunction = H;
    stack<Node*> f=F.algorithm();
    //cout << "test"<< endl;
    AStar I = AStar(goal_p,state_two, root);
    I.HeuristicFunction = h4;
    stack<Node*> i=I.algorithm();
    //cout << "test"<< endl;
    AStar J = AStar(goal_p,state_two, root);
    J.HeuristicFunction = h5;
    stack<Node*> j=J.algorithm();
    //cout << "test"<< endl;
    cout << "***Initial State #2***" << endl;
    cout << "heuristic/ET/NG/NE/d/b*/MO" << endl;
    cout<<  "h1"<< "/x/"<<G.NG<<"/"<<G.NE<<"/"<<G.d<<"/"<<G.ebf<<"/"<<"x  " <<endl;
    cout<<  "h2"<< "/x/"<<HH.NG<<"/"<<HH.NE<<"/"<<HH.d<<"/"<<HH.ebf<<"/"<<"x  " <<endl;
    cout<<  "H"<< "/x/"<<F.NG<<"/"<<F.NE<<"/"<<F.d<<"/"<<F.ebf<<"/"<<"x  " <<endl;
    cout<<  "h4"<< "/x/"<<I.NG<<"/"<<I.NE<<"/"<<I.d<<"/"<<I.ebf<<"/"<<"x  " <<endl;
    cout<<  "h5"<< "/x/"<<J.NG<<"/"<<J.NE<<"/"<<J.d<<"/"<<J.ebf<<"/"<<"x  " <<endl;

    return 0;
}

float h1(Node *s, AStar *t){
    float sum = 0;
    int ** currentpuzzle = s->getPuzzle();
    for(int r = 0; r < 3; r++ ){
        for(int c = 0; c < 3; c++ ){
            if(t->goal[r][c]!=currentpuzzle[r][c])
                sum++;
        }
    }
    return sum;
}

float h2(Node* s, AStar* t) {
    float h2 = 0;
    int** currentpuzzle = s->getPuzzle();
    if (currentpuzzle[0][0] != 1)
    {
        if (currentpuzzle[0][0] == 2)
            h2 += 1;
        if (currentpuzzle[0][0] == 3)
            h2 += 2;
        if (currentpuzzle[0][0] == 4)
            h2 += 3;
        if (currentpuzzle[0][0] == 5)
            h2 += 4;
        if (currentpuzzle[0][0] == 6)
            h2 += 3;
        if (currentpuzzle[0][0] == 7)
            h2 += 2;
        if (currentpuzzle[0][0] == 8)
            h2 += 1;
    }
    if (currentpuzzle[0][1] != 2)
    {
        if (currentpuzzle[0][1] == 1)
            h2 += 1;
        if (currentpuzzle[0][1] == 3)
            h2 += 1;
        if (currentpuzzle[0][1] == 4)
            h2 += 2;
        if (currentpuzzle[0][1] == 5)
            h2 += 3;
        if (currentpuzzle[0][1] == 6)
            h2 += 2;
        if (currentpuzzle[0][1] == 7)
            h2 += 3;
        if (currentpuzzle[0][1] == 8)
            h2 += 2;

    }
    if (currentpuzzle[0][2] != 3)
    {
        if (currentpuzzle[0][2] == 1)
            h2 += 2;
        if (currentpuzzle[0][2] == 2)
            h2 += 1;
        if (currentpuzzle[0][2] == 4)
            h2 += 1;
        if (currentpuzzle[0][2] == 5)
            h2 += 2;
        if (currentpuzzle[0][2] == 6)
            h2 += 3;
        if (currentpuzzle[0][2] == 7)
            h2 += 4;
        if (currentpuzzle[0][2] == 8)
            h2 += 3;
    }
    if (currentpuzzle[1][0] != 8)
    {
        if (currentpuzzle[1][0] == 1)
            h2 += 1;
        if (currentpuzzle[1][0] == 2)
            h2 += 2;
        if (currentpuzzle[1][0] == 3)
            h2 += 3;
        if (currentpuzzle[1][0] == 4)
            h2 += 2;
        if (currentpuzzle[1][0] == 5)
            h2 += 3;
        if (currentpuzzle[1][0] == 6)
            h2 += 2;
        if (currentpuzzle[1][0] == 7)
            h2 += 1;
    }
    if (currentpuzzle[1][1] != 0)
    {
        if (currentpuzzle[1][1] == 1)
            h2 += 2;
        if (currentpuzzle[1][1] == 2)
            h2 += 1;
        if (currentpuzzle[1][1] == 3)
            h2 += 2;
        if (currentpuzzle[1][1] == 4)
            h2 += 1;
        if (currentpuzzle[1][1] == 5)
            h2 += 2;
        if (currentpuzzle[1][1] == 6)
            h2 += 1;
        if (currentpuzzle[1][1] == 7)
            h2 += 2;
        if (currentpuzzle[1][1] == 8)
            h2 += 1;
    }
    if (currentpuzzle[1][2] != 4)
    {
        if (currentpuzzle[1][2] == 1)
            h2 += 3;
        if (currentpuzzle[1][2] == 2)
            h2 += 2;
        if (currentpuzzle[1][2] == 3)
            h2 += 1;
        if (currentpuzzle[1][2] == 5)
            h2 += 1;
        if (currentpuzzle[1][2] == 6)
            h2 += 2;
        if (currentpuzzle[1][2] == 7)
            h2 += 3;
        if (currentpuzzle[1][2] == 8)
            h2 += 2;
    }
    if (currentpuzzle[2][0] != 7)
    {
        if (currentpuzzle[2][0] == 1)
            h2 += 2;
        if (currentpuzzle[2][0] == 2)
            h2 += 3;
        if (currentpuzzle[2][0] == 3)
            h2 += 4;
        if (currentpuzzle[2][0] == 4)
            h2 += 3;
        if (currentpuzzle[2][0] == 5)
            h2 += 2;
        if (currentpuzzle[2][0] == 6)
            h2 += 1;
        if (currentpuzzle[2][0] == 8)
            h2 += 1;
    }
    if (currentpuzzle[2][1] != 6)
    {
        if (currentpuzzle[2][1] == 1)
            h2 += 3;
        if (currentpuzzle[2][1] == 2)
            h2 += 2;
        if (currentpuzzle[2][1] == 3)
            h2 += 3;
        if (currentpuzzle[2][1] == 4)
            h2 += 2;
        if (currentpuzzle[2][1] == 5)
            h2 += 1;
        if (currentpuzzle[2][1] == 7)
            h2 += 1;
        if (currentpuzzle[2][1] == 8)
            h2 += 2;
    }
    if (currentpuzzle[2][2] != 5)
    {
        if (currentpuzzle[2][2] == 1)
            h2 += 4;
        if (currentpuzzle[2][2] == 2)
            h2 += 3;
        if (currentpuzzle[2][2] == 3)
            h2 += 2;
        if (currentpuzzle[2][2] == 4)
            h2 += 1;
        if (currentpuzzle[2][2] == 6)
            h2 += 1;
        if (currentpuzzle[2][2] == 7)
            h2 += 2;
        if (currentpuzzle[2][2] == 8)
            h2 += 3;
    }

    return h2;
}


float S(Node* current, AStar* t)
{
    //a sequence score obtained by checking around the non-central squares in turn,
   // allotting 2 for every tile not followed by its proper successor and allotting
     //   0 for every other tile; a piece in the center scores one
    float s = 0;
    int** currentpuzzle = current->getPuzzle();
    if (currentpuzzle[1][1] != 0)
    {
        s += 1;
    }
    if (currentpuzzle[1][0] != (currentpuzzle[0][0] + 1))
    {
        s += 2;
    }
    if (currentpuzzle[0][2] != (currentpuzzle[0][1] + 1))
    {
        s += 2;
    }
    if (currentpuzzle[1][2] != (currentpuzzle[0][2] + 1))
    {
        s += 2;
    }
    if (currentpuzzle[2][2] != (currentpuzzle[1][2] + 1))
    {
        s += 2;
    }
    if (currentpuzzle[2][1] != (currentpuzzle[2][2] + 1))
    {
        s += 2;
    }
    if (currentpuzzle[2][0] != (currentpuzzle[2][1] + 1))
    {
        s += 2;
    }
    if (currentpuzzle[1][0] != (currentpuzzle[2][0] + 1))
    {
        s += 2;
    }
    return s;
}

float H(Node* current, AStar* t) {

    float H = h2(current, t) + (3 * S(current, t));
    return H;
}


float h4(Node* s, AStar* t)
{
    //h4(n) = # tiles misplaced in terms of row + # tiles misplaced in terms of column
    float misplacedRow = 0;
    float misplacedColum = 0;

    int** currentpuzzle = s->getPuzzle();
    if(currentpuzzle[0][0] != 1 && currentpuzzle[0][0] != 2 && currentpuzzle[0][0] != 3)
        misplacedRow += 1;
    if(currentpuzzle[0][1] != 1 && currentpuzzle[0][1] != 2 && currentpuzzle[0][1] != 3)
        misplacedRow += 1;
    if(currentpuzzle[0][2] != 1 && currentpuzzle[0][2] != 2 && currentpuzzle[0][2] != 3)
        misplacedRow += 1;
    if(currentpuzzle[1][0] != 8 && currentpuzzle[1][0] != 0 && currentpuzzle[1][0] != 4)
        misplacedRow += 1;
    if(currentpuzzle[1][1] != 8 && currentpuzzle[1][1] != 0 && currentpuzzle[1][1] != 4)
        misplacedRow += 1;
    if(currentpuzzle[1][2] != 8 && currentpuzzle[1][2] != 0 && currentpuzzle[1][2] != 4)
        misplacedRow += 1;
    if(currentpuzzle[2][0] != 7 && currentpuzzle[2][0] != 6 && currentpuzzle[2][0] != 5)
        misplacedRow += 1;
    if(currentpuzzle[2][1] != 7 && currentpuzzle[2][1] != 6 && currentpuzzle[2][1] != 5)
        misplacedRow += 1;
    if(currentpuzzle[2][2] != 7 && currentpuzzle[2][2] != 6 && currentpuzzle[2][2] != 5)
        misplacedRow += 1;


    if(currentpuzzle[0][0] != 1 && currentpuzzle[0][0] != 8 && currentpuzzle[0][0] != 7)
        misplacedColum += 1;
    if(currentpuzzle[1][0] != 1 && currentpuzzle[1][0] != 8 && currentpuzzle[1][0] != 7)
        misplacedColum += 1;
    if(currentpuzzle[2][0] != 1 && currentpuzzle[2][0] != 8 && currentpuzzle[2][0] != 7)
        misplacedColum += 1;
    if(currentpuzzle[0][1] != 2 && currentpuzzle[0][1] != 0 && currentpuzzle[0][1] != 6)
        misplacedColum += 1;
    if(currentpuzzle[1][1] != 2 && currentpuzzle[1][1] != 0 && currentpuzzle[1][1] != 6)
        misplacedColum += 1;
    if(currentpuzzle[2][1] != 2 && currentpuzzle[2][1] != 0 && currentpuzzle[2][1] != 6)
        misplacedColum += 1;
    if(currentpuzzle[0][2] != 3 && currentpuzzle[0][2] != 4 && currentpuzzle[0][2] != 5)
        misplacedColum += 1;
    if(currentpuzzle[1][2] != 3 && currentpuzzle[1][2] != 4 && currentpuzzle[1][2] != 5)
        misplacedColum += 1;
    if(currentpuzzle[2][2] != 3 && currentpuzzle[2][2] != 4 && currentpuzzle[2][2] != 5)
        misplacedColum += 1;

    return (misplacedColum + misplacedRow);
}

float h5(Node* s, AStar* t)
{
    //h5(n) =  Sum of Eucledian distances of the tiles from their
    //goal positions

    float h5 = 0;
    int** currentpuzzle = s->getPuzzle();

    if (currentpuzzle[0][0] != 1)
    {
        if (currentpuzzle[0][0] == 2)
            h5 += 1;
        if (currentpuzzle[0][0] == 3)
            h5 += 2;
        if (currentpuzzle[0][0] == 4)
            h5 += sqrt(5);
        if (currentpuzzle[0][0] == 5)
            h5 += sqrt(8);
        if (currentpuzzle[0][0] == 6)
            h5 += sqrt(5);
        if (currentpuzzle[0][0] == 7)
            h5 += 2;
        if (currentpuzzle[0][0] == 8)
            h5 += 1;
    }
    if (currentpuzzle[0][1] != 2)
    {
        if (currentpuzzle[0][1] == 1)
            h5 += 1;
        if (currentpuzzle[0][1] == 3)
            h5 += 1;
        if (currentpuzzle[0][1] == 4)
            h5 += sqrt(2);
        if (currentpuzzle[0][1] == 5)
            h5 += sqrt(5);
        if (currentpuzzle[0][1] == 6)
            h5 += 2;
        if (currentpuzzle[0][1] == 7)
            h5 += sqrt(5);
        if (currentpuzzle[0][1] == 8)
            h5 += sqrt(2);

    }
    if (currentpuzzle[0][2] != 3)
    {
        if (currentpuzzle[0][2] == 1)
            h5 += 2;
        if (currentpuzzle[0][2] == 2)
            h5 += 1;
        if (currentpuzzle[0][2] == 4)
            h5 += 1;
        if (currentpuzzle[0][2] == 5)
            h5 += 2;
        if (currentpuzzle[0][2] == 6)
            h5 += sqrt(5);
        if (currentpuzzle[0][2] == 7)
            h5 += sqrt(8);
        if (currentpuzzle[0][2] == 8)
            h5 += sqrt(5);
    }
    if (currentpuzzle[1][0] != 8)
    {
        if (currentpuzzle[1][0] == 1)
            h5 += 1;
        if (currentpuzzle[1][0] == 2)
            h5 += sqrt(2);
        if (currentpuzzle[1][0] == 3)
            h5 += sqrt(5);
        if (currentpuzzle[1][0] == 4)
            h5 += 2;
        if (currentpuzzle[1][0] == 5)
            h5 += sqrt(5);
        if (currentpuzzle[1][0] == 6)
            h5 += sqrt(2);
        if (currentpuzzle[1][0] == 7)
            h5 += 1;
    }
    if (currentpuzzle[1][1] != 0)
    {
        if (currentpuzzle[1][1] == 1)
            h5 += sqrt(2);
        if (currentpuzzle[1][1] == 2)
            h5 += 1;
        if (currentpuzzle[1][1] == 3)
            h5 += sqrt(2);
        if (currentpuzzle[1][1] == 4)
            h5 += 1;
        if (currentpuzzle[1][1] == 5)
            h5 += sqrt(2);
        if (currentpuzzle[1][1] == 6)
            h5 += 1;
        if (currentpuzzle[1][1] == 7)
            h5 += sqrt(2);
        if (currentpuzzle[1][1] == 8)
            h5 += 1;
    }
    if (currentpuzzle[1][2] != 4)
    {
        if (currentpuzzle[1][2] == 1)
            h5 += sqrt(5);
        if (currentpuzzle[1][2] == 2)
            h5 += sqrt(2);
        if (currentpuzzle[1][2] == 3)
            h5 += 1;
        if (currentpuzzle[1][2] == 5)
            h5 += 1;
        if (currentpuzzle[1][2] == 6)
            h5 += sqrt(2);
        if (currentpuzzle[1][2] == 7)
            h5 += sqrt(5);
        if (currentpuzzle[1][2] == 8)
            h5 += 2;
    }
    if (currentpuzzle[2][0] != 7)
    {
        if (currentpuzzle[2][0] == 1)
            h5 += 2;
        if (currentpuzzle[2][0] == 2)
            h5 += sqrt(5);
        if (currentpuzzle[2][0] == 3)
            h5 += sqrt(8);
        if (currentpuzzle[2][0] == 4)
            h5 += sqrt(5);
        if (currentpuzzle[2][0] == 5)
            h5 += 2;
        if (currentpuzzle[2][0] == 6)
            h5 += 1;
        if (currentpuzzle[2][0] == 8)
            h5 += 1;
    }
    if (currentpuzzle[2][1] != 6)
    {
        if (currentpuzzle[2][1] == 1)
            h5 += sqrt(5);
        if (currentpuzzle[2][1] == 2)
            h5 += 2;
        if (currentpuzzle[2][1] == 3)
            h5 += sqrt(5);
        if (currentpuzzle[2][1] == 4)
            h5 += sqrt(2);
        if (currentpuzzle[2][1] == 5)
            h5 += 1;
        if (currentpuzzle[2][1] == 7)
            h5 += 1;
        if (currentpuzzle[2][1] == 8)
            h5 += sqrt(2);
    }
    if (currentpuzzle[2][2] != 5)
    {
        if (currentpuzzle[2][2] == 1)
            h5 += sqrt(8);
        if (currentpuzzle[2][2] == 2)
            h5 += sqrt(5);
        if (currentpuzzle[2][2] == 3)
            h5 += 2;
        if (currentpuzzle[2][2] == 4)
            h5 += 1;
        if (currentpuzzle[2][2] == 6)
            h5 += 1;
        if (currentpuzzle[2][2] == 7)
            h5 += 2;
        if (currentpuzzle[2][2] == 8)
            h5 += sqrt(5);
    }


 return  h5;
}

