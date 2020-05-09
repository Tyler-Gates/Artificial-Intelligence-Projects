#include "ConclusionList.h"

ConclusionList::ConclusionList(std::map<std::string, std::queue<int> > con_ls)
{this->con_ls = con_ls;}
/**Default Constructor*/
ConclusionList::ConclusionList()
{}

/**Getters*/
int ConclusionList::getRuleNumber(std::string conclusion_var){
    std::map<std::string,std::queue<int> >::iterator it = con_ls.find(conclusion_var);
    if (it != con_ls.end()){
        if(it->second.empty()){
            return -1;
        }
        else{
            int result=it->second.front();
            return result;
        }
    }
    else
        return -2;
}

/**POP?*/
void ConclusionList::popRuleNumber(std::string conclusion_var){
    std::map<std::string,std::queue<int> >::iterator it = con_ls.find(conclusion_var);
    if (it != con_ls.end()){
        it->second.pop();
    }
}
/**Default Destructor*/
ConclusionList::~ConclusionList()
{}
