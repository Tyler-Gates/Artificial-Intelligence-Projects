#ifndef FCLAUSEVARLIST_H
#define FCLAUSEVARLIST_H

#include <iostream>
#include <string>
using namespace std;

class fClauseVarList
{
private:
    string clauseVarList[151];

public:
    fClauseVarList();
    string getClauseVarList(int i);
    void setClauseVarList(int i, string s);
    ~fClauseVarList();


};

#endif // FCLAUSEVARLIST_H#pragma once
