#ifndef VARIABLELIST_H
#define VARIABLELIST_H
#include <map>
#include <string>
#include <iostream>
class VariableList
{
public:
    /** Default constructor */
    VariableList();
    VariableList(std::map<std::string, std::string> variable_list,
        std::map<std::string, std::string> conclusion_list);
    /** Default destructor */
    virtual ~VariableList();

    /**Setters*/
    void setVariableList(std::map<std::string, std::string> var_list);
    void setThisVariable(std::string variable, std::string property);

    /**Getters*/
    std::string getConProperty(std::string con);
    std::string getVarProperty(std::string var);
    std::string searchConVar(std::string var);
    void updateCon(std::string con, std::string property);
    void setVarProperty(std::string var, std::string yn);
    int var_size;
    bool isVarSet(std::string var);

private:
    std::map<std::string, std::string> variable_list;
    std::map<std::string, std::string> conclusion_list;
};

#endif // VARIABLELIST_H
