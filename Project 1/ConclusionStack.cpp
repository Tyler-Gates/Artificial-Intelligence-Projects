#include "ConclusionStack.h"
#include "VariableList.h"

ConclusionStack::ConclusionStack(std::string var){setStackVar(var);}
/**Default Constructor*/
ConclusionStack::ConclusionStack()
{}
/**Setters*/
void ConclusionStack:: setStackRule(int rule){stack_rule.push(rule);}

void ConclusionStack:: setStackVar(std::string var){stack_var.push(var);}

void ConclusionStack:: setStackClause(int clause){stack_clause.push(clause);}

void ConclusionStack:: setStackRVC(int rule, std::string var, int clause){
    stack_rule.push(rule);
    stack_var.push(var);
    stack_clause.push(clause);
}

/**Getters*/
int ConclusionStack:: getStackRule(){
    return stack_rule.top();
}
/***/
std::string ConclusionStack:: getStackVar(){
    return stack_var.top();
}
/***/
int ConclusionStack:: getStackClause(){
    return stack_clause.top();
}

/**POP?*/
void ConclusionStack:: popStackRule(){
    stack_rule.pop();
}
void ConclusionStack:: popStackVar(){
    stack_var.pop();
}
void ConclusionStack:: popStackClause(){
    stack_clause.pop();
}

/** Check if Stack Empty */
bool ConclusionStack::VarStackEmpty(){
    return stack_var.empty();
}

ConclusionStack::~ConclusionStack()
{
    //dtor
}
