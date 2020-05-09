#ifndef ENGINE_H
#define ENGINE_H
#include "VariableList.h"
#include "ConclusionList.h"
#include "ClauseVariableList.h"
#include "ConclusionStack.h"
#include "KnowledgeBase.h"
#include <string>
using namespace std;
class Engine
{

public:
    Engine(
        std::map<std::string, std::string> variable_list= std::map<std::string, std::string>(),
        std::map<std::string, std::string> conclusion_list = std::map<std::string, std::string>(),
        std::map<int, std::string> knowledge_base = std::map<int, std::string>(),
        std::map<std::string, std::queue<int> > con_ls = std::map<std::string, std::queue<int> >(),
        std::vector<std::string> clause_variable_list = std::vector<std::string>(),
        std::vector<std::string> clause_conditions_list= std::vector<std::string>(),
        std::map<std::string, std::string> fvar_list = std::map<std::string, std::string>());

    std::string conclusion;
    std::string results;
    std::string current_var;
    std::string loop();
    void updateconclusionStack(std::string con_var);
    VariableList var_list;
    ConclusionList con_list;
    ClauseVariableList clause_var_list;
    ConclusionStack conclusion_stack;
    KnowledgeBase knowlg_base;
    void startp(std::string conclusion);

    bool backwarddone; // flag for backwardchaining completion
    bool done; // flag for forward chaining questioning
    VariableList fvar_list;  //Forward chaining Questions and Variable property
    std::string Major; // set to backward chaining result
    int s; // iterators
    int statementNumber; /* statement number */

    std::string var;
    string setQuestions(string& Major, VariableList a);
    queue<string> condiVariableQueue;
    string run(VariableList fvar_list);

};

#endif // ENGINE_H
