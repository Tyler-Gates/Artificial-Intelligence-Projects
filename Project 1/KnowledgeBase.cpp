#include "KnowledgeBase.h"

KnowledgeBase::KnowledgeBase(std::map<int, std::string> knowledge_base)
{
    this->knowledge_base = knowledge_base;
}

KnowledgeBase::KnowledgeBase(){}

std::string KnowledgeBase::getResult(int rule_nmb){
    if(knowledge_base.count(rule_nmb)){
        return knowledge_base[rule_nmb];
    }
    else
        return std::string("NO Here know!!");
}

KnowledgeBase::~KnowledgeBase(){}
