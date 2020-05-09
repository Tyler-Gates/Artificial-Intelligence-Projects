#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <iostream>
#include<list>
#include<vector>
#include<deque>
using namespace std;

class Node{

public:
    Node * parent = nullptr;
    float f_value;
    float g_value;
    float h_value;

    struct Children{
    Node * left;
    Node * right;
    Node * up;
    Node * down;
    } Children_default = {nullptr,nullptr,nullptr,nullptr};
    typedef struct Children Children;

    Children children = Children_default;
    int number_of_childs;
    static const int ROW = 3, COL = 3;
                          //   c0 c1 c2
    int puzzle[ROW][COL];// r0 xx xx xx
                        //  r1 xx xx xx
                       //   r2 xx xx xx

    int blank[2] = {0,0};
    Node(int val[3][3]);
    Node();
    Node(Node *p);

    float getFVal();
    void setFval(float val);

    float getGVal();
    void setGval(float val);

    float getHVal();
    void setHval(float val);

    int** getPuzzle();
    void setPuzzle(int val[][COL]);

    int getNumOfChilds();
    void addToNumChilds();

    Node* getParent();
    void setParent(Node* val);

    Children getchildren();
    void generateChildren();

    void calculateGvalue();
    void calculateHvalue(Node * val, int func(Node*));

    Node*  moveLeft(Node* a);
    Node* moveRight(Node* a);
    Node* moveUp(Node* a);
    Node* moveDown(Node* a);

    friend bool operator <(const Node &n1, const Node &n2){
        return n1.f_value < n2.f_value;
    }

    friend bool operator >(const Node &n1, const Node &n2){
        return n1.f_value > n2.f_value;
    }


    void print();

    ~Node();
};






#endif // NODE_H_INCLUDED
