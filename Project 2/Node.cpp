#include "Node.h"
int puzzle_default[][3] = {{0,0,0}, {0,0,0}, {0,0,0}};

Node::Node(int val[3][3] = puzzle_default){
    this->setPuzzle(val);
    this->number_of_childs = 0;
}

Node::Node(Node *p){
    this->setPuzzle(p->puzzle);
    this->g_value = p->g_value;
    this->parent = p->parent;
}

float Node:: getFVal(){
    return this->f_value;
}
void Node:: setFval(float val){
    this->f_value = val;
}

float Node:: getGVal(){
    return this->g_value;
}
void Node:: setGval(float val){
    this->g_value = val;
}
float Node:: getHVal(){
    return this->h_value;
}
void Node:: setHval(float val){
    this->h_value = val;
}
int** Node:: getPuzzle(){
    int** temp;
    temp = new int*[3];
      for (int r = 0; r < 3; r++)
      {
            temp[r] = new int[3];

            for (int c = 0; c < 3; c++)
            {
                  temp[r][c] = this->puzzle[r][c];
            }
      }
    return temp;
}
void Node:: setPuzzle(int val[][COL]){
    for(int r = 0; r < ROW; r++ ){
        for(int c = 0; c < COL; c++ ){
            this->puzzle[r][c] = val[r][c];
            if(val[r][c]==0){
                this->blank[0] = r;
                this->blank[1] = c;
            }
        }
    }
}
int Node:: getNumOfChilds(){
    return this->number_of_childs;
}
void Node:: addToNumChilds(){
    this->number_of_childs++;
}
Node* Node:: getParent(){
    return this->parent;
}
void Node:: setParent(Node* val){
    Node *p = new Node(val);
    this->parent = p;
}
Node::Children Node:: getchildren(){
    return this->children;
}

void Node:: generateChildren(){
    this->children.left = moveLeft(this);
    this->children.right = moveRight(this);
    this->children.up = moveUp(this);
    this->children.down = moveDown(this);
}

void Node:: print(){
    cout << "--------" << endl;
    for(int r = 0; r < ROW; r++ ){
        for(int c = 0; c < COL; c++ ){
            cout << "|" << puzzle[r][c];
        }
        cout << "|" << endl;
    }
    cout << "--------" << endl;
}

Node* Node:: moveLeft(Node *a) {
    if(a->blank[1]==0)
        return nullptr;
    else{
        Node* temp = new Node(a->puzzle);
        //moving blank space left
        temp->puzzle[a->blank[0]][a->blank[1]]=
        temp->puzzle[a->blank[0]][a->blank[1]-1];
        temp->puzzle[a->blank[0]][a->blank[1]-1]=0;
        a->addToNumChilds();
        temp->blank[1]--;
        return temp;
    }
}

Node* Node::moveRight(Node *a) {
    if(a->blank[1]==2)
        return nullptr;
    else{
        Node* temp = new Node(a->puzzle);
        //moving blank space left
        temp->puzzle[a->blank[0]][a->blank[1]]=
        temp->puzzle[a->blank[0]][a->blank[1]+1];
        temp->puzzle[a->blank[0]][a->blank[1]+1]=0;
        a->addToNumChilds();
        temp->blank[1]++;
        return temp;
    }

}

Node* Node:: moveUp(Node *a) {
    if(a->blank[0]==0)
        return nullptr;
    else{
        Node* temp = new Node(a->puzzle);
        //moving blank space left
        temp->puzzle[a->blank[0]][a->blank[1]]=
        temp->puzzle[a->blank[0]-1][a->blank[1]];
        temp->puzzle[a->blank[0]-1][a->blank[1]]=0;
        a->addToNumChilds();
        temp->blank[0]--;
        return temp;
    }

}

Node* Node:: moveDown(Node *a) {
    if(a->blank[0]==2)
        return nullptr;
    else{
        Node* temp = new Node(a->puzzle);
        //moving blank space left
        temp->puzzle[a->blank[0]][a->blank[1]]=
        temp->puzzle[a->blank[0]+1][a->blank[1]];
        temp->puzzle[a->blank[0]+1][a->blank[1]]=0;
        a->addToNumChilds();
        temp->blank[0]++;
        return temp;
    }
}

Node::~Node() {
	if(this->children.left != nullptr){
        delete this->children.left;
        this->children.left = nullptr;
	}
	if(this->children.right != nullptr){
        delete this->children.right;
        this->children.right = nullptr;
	}
	if(this->children.up != nullptr){
        delete this->children.up;
        this->children.up = nullptr;
	}
	if(this->children.down != nullptr){
        delete this->children.down;
        this->children.down = nullptr;
	}
}

