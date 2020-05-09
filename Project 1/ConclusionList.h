#ifndef CONCLUSIONLIST_H
#define CONCLUSIONLIST_H
#include <map>
#include<queue>
#include<string>
class ConclusionList
{
    public:
        ConclusionList(std::map<std::string, std::queue<int> > con_ls);
        /** Default constructor */
        ConclusionList();
        /** Default destructor */
        virtual ~ConclusionList();

        /**Setters*/

        /**Getters*/
        int getRuleNumber(std::string conclusion_var);

        /**POP?*/
        void popRuleNumber(std::string conclusion_var);

    private:
        std::map<std::string, std::queue<int> > con_ls;
};

#endif // CONCLUSIONLIST_H
