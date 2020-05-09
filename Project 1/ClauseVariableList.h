#ifndef CLAUSEVARIABLELIST_H
#define CLAUSEVARIABLELIST_H
#include <vector>
#include<string>

class ClauseVariableList
{
    public:
        ClauseVariableList(std::vector<std::string> clause_variable_list,
                           std::vector<std::string> clause_conditions_list);
        /** Default constructor */
        ClauseVariableList();
        /** Default destructor */
        virtual ~ClauseVariableList();

        std::string getVar(int clause_num);
        std::string getCondition(int clause_num);

    private:
        std::vector<std::string> clause_variable_list;
        std::vector<std::string> clause_conditions_list;
};

#endif // CLAUSEVARIABLELIST_H
