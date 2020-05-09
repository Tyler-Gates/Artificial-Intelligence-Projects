#ifndef CONCLUSIONSTACK_H
#define CONCLUSIONSTACK_H
#include <string>
#include <stack>
class ConclusionStack
{
    public:
        ConclusionStack(std::string var);
        /** Default constructor */
        ConclusionStack();
        /** Default destructor */
        virtual ~ConclusionStack();

        /**Setters*/
        void setStackRule(int rule);
        void setStackVar(std::string var);
        void setStackClause(int clause);
        void setStackRVC(int rule, std::string var, int clause);

        /**Getters*/
        int getStackRule();
        std::string getStackVar();
        int getStackClause();
        int getCurrentStackNum();

        /**POP*/
        void popStackRule();
        void popStackVar();
        void popStackClause();

        /**Check if Stack is Empty of Variables or Conclusions*/
        bool VarStackEmpty();

    private:
        std::stack<int> stack_rule;//conclusion stack rule
        std::stack<std::string>stack_var;//conclusion stack variable or conclusion
        std::stack<int> stack_clause; //conclusion stack clause
};

#endif // CONCLUSIONSTACK_H
