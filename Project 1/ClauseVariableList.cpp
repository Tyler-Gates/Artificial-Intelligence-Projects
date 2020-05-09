#include "ClauseVariableList.h"


ClauseVariableList::ClauseVariableList(std::vector<std::string> clause_variable_list,
        std::vector<std::string> clause_conditions_list)
{
    this->clause_variable_list = clause_variable_list;
    this->clause_conditions_list = clause_conditions_list;
}

ClauseVariableList::ClauseVariableList()
{}

//Getters
std::string ClauseVariableList::getVar(int clause_num){
    return clause_variable_list.at(clause_num);
}

std::string ClauseVariableList::getCondition(int clause_num){
    return clause_conditions_list.at(clause_num);
}

ClauseVariableList::~ClauseVariableList()
{}
