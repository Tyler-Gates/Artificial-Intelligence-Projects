#ifndef KNOWLEDGEBASE_H
#define KNOWLEDGEBASE_H
#include <string>
#include <map>
class KnowledgeBase
{
    public:
        KnowledgeBase(std::map<int, std::string> knowledge_base);
        /** Default constructor */
        KnowledgeBase();
        /** Default destructor */
        virtual ~KnowledgeBase();
        std::string getResult(int rule_nmb);

    private:
        std::map<int, std::string> knowledge_base;
};

#endif // KNOWLEDGEBASE_H
