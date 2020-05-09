#include "variableList.h"


/*defines all the variables needed for variable list*/
VariableList::VariableList(std::map<std::string, std::string> variable_list,
    std::map<std::string, std::string> conclusion_list)
{
    //ctor
    this->variable_list = variable_list;
    this->conclusion_list = conclusion_list;
    this->var_size = (int)variable_list.size();
}

VariableList::VariableList() {}

/*getConProperty gets the conclusion property of the string con inside the
  conclusion list, if it is there, otherwise returns not_here_CON*/
std::string VariableList::getConProperty(std::string con) {
    if (conclusion_list.count(con) == 1) {
        return conclusion_list[con];
    }
    else
        return std::string("not_here_CON");
}

/*isVarSet checks to see if the variable in variable_list is set or not*/
bool VariableList::isVarSet(std::string var) {
    if (variable_list.count(var) == 1) {
        std::string result = variable_list[var];
        if (result == "") {
            return false;
        }
        else
            return true;
    }
    else
        return false;
}


/*getVarProperty Returns the variable property of string var inside variable_list returns YES/NO
  if found, returns not_here_VAR if not found*/
std::string VariableList::getVarProperty(std::string var) {
    if (variable_list.count(var) == 1) {
        std::string result = variable_list[var];
        return result;
    }
    else
        return std::string("not_here_VAR");
}

/*setVarProperty sets the string var inside variable list to yes or no if the variable exists*/
void VariableList::setVarProperty(std::string var, std::string yn) {
    if (variable_list.count(var) == 1) {
        variable_list[var] = yn;
    }
}

/*searchConVar Determines if .count with ID var is Conculsion or Variable*/
std::string VariableList::searchConVar(std::string var) {
    if (variable_list.count(var) == 1) {
        return std::string("VAR");
    }
    else
        return std::string("CON");
}

/*updateCon adds a conclusion property to a conclusion inside conclusionlist*/
void VariableList::updateCon(std::string con, std::string property) {
    std::map<std::string, std::string>::iterator it = conclusion_list.find(con);

    if (it != conclusion_list.end())
        it->second = property;
}

VariableList::~VariableList() {}

