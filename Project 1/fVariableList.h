#ifndef FVARIABLELIST_H
#define FVARIABLELIST_H

#include <iostream>
#include <string>
using namespace std;

class fVariableList
{
private:
    string variableList[51];

public:
    fVariableList();
    string getVariableList(int i);
    ~fVariableList();

};

#endif // VARIABLELIST_H
