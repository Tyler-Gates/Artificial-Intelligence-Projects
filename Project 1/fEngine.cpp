#include "fEngine.h"

fEngine::fEngine(string major) {
    Major = major;
}

fEngine::fEngine() {

}

fEngine::~fEngine() {

}

void fEngine::run() {
    /* place condition variable c on condition var queue condiVariableQueue */
    condiVariableQueue.push("Major");


    /* set the condition variable pointer consisting of the
    statement number (statementNumber) and the clause number (clauseNumber) */
    statementNumber = 1;
    clauseNumber = 1;

    /* find the next statement number containing the condition variable
    which is in front of the queue (condiVariableQueue), this statement number
    is located in the clause variable list (clauseVarList) */
    /* start at the beginning */
    f = 1;

b496: search(cVarList);

    check_instantiation(Major, varlist, v, checkInstant);
    /* point to first clause in statement */
    clauseNumber = 1;

    if (statementNumber != 0)
        /* more statements */
    {
        /* locate the clause */
        i = 3 * (statementNumber - 1) + clauseNumber;

        /* clause variable */
        v = cVarList.getClauseVarList(i);



        /* no more clauses - check IF part of statement */
        s = 0;
        /* sample IF-THEN statements from the position knowledge base */
        while (statementNumber != 0)
        {
            if ((Major == "Engineering") &&
                (Electrical == "YES")) {
                s = 1; statementNumber = 1; break;
            }
            if ((Major == "Engineering") &&
                (Mechanical == "YES")) {
                s = 1; statementNumber = 2; break;
            }
            if ((Major == "Engineering") &&
                (PNEnvironment == "YES")) {
                s = 1; statementNumber = 3; break;
            }
            if ((Major == "Engineering") &&
                (OilGas == "YES")) {
                s = 1; statementNumber = 4; break;
            }
            if ((Major == "Engineering") &&
                (ChemEnergy == "YES")) {
                s = 1; statementNumber = 5; break;
            }
            if ((Major == "Science") &&
                (ChemMatter == "YES")) {
                s = 1; statementNumber = 2; break;
            }
            if ((Major == "Science") &&
                (Dna == "YES")) {
                s = 1; statementNumber = 2; break;
            }
            if ((Major == "Science") &&
                (LivOrganism == "YES")) {
                s = 1; statementNumber = 8; break;
            }
            if ((Major == "Science") &&
                (MarLife == "YES")) {
                s = 1; statementNumber = 9; break;
            }
            if ((Major == "Science") &&
                (Star == "YES")) {
                s = 1; statementNumber = 10; break;
            }
            if ((Major == "Business") &&
                (Exchange == "YES")) {
                s = 1; statementNumber = 11; break;
            }
            if ((Major == "Business") &&
                (Money == "YES")) {
                s = 1; statementNumber = 12; break;
            }
            if ((Major == "Business") &&
                (Opportunities == "YES")) {
                s = 1; statementNumber = 13; break;
            }
            if ((Major == "Business") &&
                (Manage == "YES")) {
                s = 1; statementNumber = 14; break;
            }
            if ((Major == "Business") &&
                (Econ == "YES")) {
                s = 1; statementNumber = 15; break;
            }
            if ((Major == "Art") &&
                (Photo == "YES")) {
                s = 1; statementNumber = 16; break;
            }
            if ((Major == "Art") &&
                (Poetry == "YES")) {
                s = 1; statementNumber = 17; break;
            }
            if ((Major == "Art") &&
                (Film == "YES")) {
                s = 1; statementNumber = 18; break;
            }
            if ((Major == "Art") &&
                (Dance == "YES")) {
                s = 1; statementNumber = 19; break;
            }
            if ((Major == "Art") &&
                (Acting == "YES")) {
                s = 1; statementNumber = 20; break;
            }
            if ((Major == "English") &&
                (News == "YES")) {
                s = 1; statementNumber = 21; break;
            }
            if ((Major == "English") &&
                (Info == "YES")) {
                s = 1; statementNumber = 22; break;
            }
            if ((Major == "English") &&
                (Promote == "YES")) {
                s = 1; statementNumber = 23; break;
            }
            if ((Major == "English") &&
                (Employer == "YES")) {
                s = 1; statementNumber = 24; break;
            }
            if ((Major == "English") &&
                (Edit == "YES")) {
                s = 1; statementNumber = 25; break;
            }
            if ((Major == "Geography") &&
                (International == "YES")) {
                s = 1; statementNumber = 26; break;
            }
            if ((Major == "Geography") &&
                (Plant == "YES")) {
                s = 1; statementNumber = 27; break;
            }
            if ((Major == "Geography") &&
                (Domestic == "YES")) {
                s = 1; statementNumber = 28; break;
            }
            if ((Major == "Geography") &&
                (Climate == "YES")) {
                s = 1; statementNumber = 29; break;
            }
            if ((Major == "Geography") &&
                (People == "YES")) {
                s = 1; statementNumber = 30; break;
            }
            if ((Major == "Psychology") &&
                (FamMar == "YES")) {
                s = 1; statementNumber = 31; break;
            }
            if ((Major == "Psychology") &&
                (Mental == "YES")) {
                s = 1; statementNumber = 32; break;
            }
            if ((Major == "Psychology") &&
                (Substance == "YES")) {
                s = 1; statementNumber = 33; break;
            }
            if ((Major == "Psychology") &&
                (Experiment == "YES")) {
                s = 1; statementNumber = 34; break;
            }
            if ((Major == "Psychology") &&
                (HR == "YES")) {
                s = 1; statementNumber = 35; break;
            }
            if ((Major == "Agriculture") &&
                (Inspecting == "YES")) {
                s = 1; statementNumber = 36; break;
            }
            if ((Major == "Agriculture") &&
                (Garden == "YES")) {
                s = 1; statementNumber = 37; break;
            }
            if ((Major == "Agriculture") &&
                (Trees == "YES")) {
                s = 1; statementNumber = 38; break;
            }
            if ((Major == "Agriculture") &&
                (Bees == "YES")) {
                s = 1; statementNumber = 39; break;
            }
            if ((Major == "Agriculture") &&
                (WildLife == "YES")) {
                s = 1; statementNumber = 40; break;
            }
            if ((Major == "Health Care") &&
                (Care == "YES")) {
                s = 1; statementNumber = 41; break;
            }
            if ((Major == "Health Care") &&
                (Plan == "YES")) {
                s = 1; statementNumber = 42; break;
            }
            if ((Major == "Health Care") &&
                (Teeth == "YES")) {
                s = 1; statementNumber = 43; break;
            }
            if ((Major == "Health Care") &&
                (Assistant == "YES")) {
                s = 1; statementNumber = 44; break;
            }
            if ((Major == "Health Care") &&
                (Disease == "YES")) {
                s = 1; statementNumber = 45; break;
            }
            if ((Major == "Education") &&
                (Elementary == "YES")) {
                s = 1; statementNumber = 46; break;
            }
            if ((Major == "Education") &&
                (College == "YES")) {
                s = 1; statementNumber = 47; break;
            }
            if ((Major == "Education") &&
                (Education == "YES")) {
                s = 1; statementNumber = 48; break;
            }
            if ((Major == "Education") &&
                (Curriculum == "YES")) {
                s = 1; statementNumber = 49; break;
            }
            if ((Major == "Education") &&
                (Language == "YES")) {
                s = 1; statementNumber = 50; break;
            }
        }

        /* see if the THEN part should be inovked, i.e., s=1 */
        if (s != 1)
        {
            f = statementNumber + 1;
            goto b496;
        }



        /* invoke THEN part */
        switch (statementNumber)
        {

            /* put variable on the conclusion variable queue */
        case 1:
            Area = "Electrical Engineering";
            cout << "Career = Electrical Engineering";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 2:
            Area = "Mechanical Engineering";
            cout << "Career = Mechanical Engineering";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 3:
            Area = "Civil Engineering";
            cout << "Career = Civil Engineering";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 4:
            Area = "Petroleum Engineering";
            cout << "Career = Petroleum Engineering";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 5:
            Area = " Chemical Engineering";
            cout << "Career =  Chemical Engineering";
            v = "Area";
            instantiate(varlist, v);
            break;


            /* put variable on the conclusion variable queue */
        case 6:
            Area = "Chemistry";
            cout << "Career = Chemistry";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 7:
            Area = "Biochemistry";
            cout << "Career = Biochemistry";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 8:
            Area = "Biology";
            cout << "Career = Biology";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 9:
            Area = "Marine Biology";
            cout << "Career = Marine Biology";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 10:
            Area = "Astronomy";
            cout << "Career = Astronomy";
            v = "Area";
            instantiate(varlist, v);
            break;


            /* put variable on the conclusion variable queue */
        case 11:
            Area = "Marketing";
            cout << "Career = Marketing";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 12:
            Area = "Finance";
            cout << "Career = Finance";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 13:
            Area = "Entrepreneurial Studies";
            cout << "Career = Entrepreneurial Studies";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 14:
            Area = "Business Administration/Management";
            cout << "Career = Business Administration/Management";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 15:
            Area = "Business Economics";
            cout << "Career = Business Economics";
            v = "Area";
            instantiate(varlist, v);
            break;




            /* put variable on the conclusion variable queue */
        case 16:
            Area = "Photography";
            cout << "Career = Photography";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 17:
            Area = "Poetry";
            cout << "Career = Poetry";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 18:
            Area = "Film";
            cout << "Career = Film";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 19:
            Area = "Dance";
            cout << "Career = Dance";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 20:
            Area = "Drama";
            cout << "Career = Drama";
            v = "Area";
            instantiate(varlist, v);
            break;

            /* put variable on the conclusion variable queue */
        case 21:
            Area = "Journalism";
            cout << "Career = Journalism";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 22:
            Area = "Technical Writer";
            cout << "Career = Technical Writer";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 23:
            Area = "Public Relations Specialist";
            cout << "Career = Public Relations Specialist";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 24:
            Area = "Human Resource Specialist";
            cout << "Career = Human Resource Specialist";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 25:
            Area = "Editor";
            cout << "Career = Editor";
            v = "Area";
            instantiate(varlist, v);
            break;


        case 26:
            Area = "Globalization";
            cout << "Career = Globalization";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 27:
            Area = "World Vegetation";
            cout << "Career = World Vegetation";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 28:
            Area = "Physical Environment";
            cout << "Career = Physical Environment";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 29:
            Area = "Applied Climatology";
            cout << "Career = Applied Climatology";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 30:
            Area = "Biography";
            cout << "Career = Biography";
            v = "Area";
            instantiate(varlist, v);
            break;


        case 31:
            Area = "Marriage/Family Therapist";
            cout << "Career = Marriage/Family Therapist";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 32:
            Area = "Psychiatric Technician";
            cout << "Career = Psychiatric Technician";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 33:
            Area = "Substance Abuse Counselor";
            cout << "Career = Substance Abuse Counselor";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 34:
            Area = "Experimental Psychologist";
            cout << "Career = Experimental Psychologist";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 35:
            Area = "Human Resource Personnel";
            cout << "Career = Human Resource Personnel";
            v = "Area";
            instantiate(varlist, v);
            break;


        case 36:
            Area = "Agricultural Inspector";
            cout << "Career = Agricultural Inspector";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 37:
            Area = "Horticulturist";
            cout << "Career = Horticulturist";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 38:
            Area = "Arborist";
            cout << "Career = Arborist";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 39:
            Area = "Beekeeper";
            cout << "Career = Beekeeper";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 40:
            Area = "Wildlife Forensics";
            cout << "Career = Wildlife Forensics";
            v = "Area";
            instantiate(varlist, v);
            break;



        case 41:
            Area = "Nursing";
            cout << "Career = Nursing";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 42:
            Area = "Health Services Management";
            cout << "Career = Health Services Management";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 43:
            Area = "Dentist";
            cout << "Career = Dentist";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 44:
            Area = "Physician Assistant";
            cout << "Career = Physician Assistant";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 45:
            Area = "Public Health";
            cout << "Career = Public Health";
            v = "Area";
            instantiate(varlist, v);
            break;


        case 46:
            Area = "Elementary education";
            cout << "Career = Elementary education";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 47:
            Area = "Professor";
            cout << "Career = Professor";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 48:
            Area = "Education Coordinator";
            cout << "Career = Education Coordinator";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 49:
            Area = "Curriculum Developer";
            cout << "Career = Curriculum Developer";
            v = "Area";
            instantiate(varlist, v);
            break;
        case 50:
            Area = "ESOL Teacher";
            cout << "Career = ESOL Teacher";
            v = "Area";
            instantiate(varlist, v);
            break;

        }
        f = statementNumber + 1;

    }

    /* no more clauses in the clause variable list (clauseVarList)
    containing the variable in front of the queue (condiVariableQueue(frontPointer))
    then remove front variable (condiVariableQueue(frontPointer)) and replace it by
    the next variable (condiVariableQueue(frontPointer+1)). If no more variables are
    at the front of the queue, stop. */
    /* next queue variable */
    condiVariableQueue.pop();

    if (!condiVariableQueue.empty())
    {
        /* check out the condition variable */
        f = 1;
        goto b496;
    }
    /* no more conclusion variables on queue */

}

//==========================================================================
/* Routine to instantiate a variable (v) if it isn't already.
The instantiate indication (instlt) is a 0 if not, a 1 if it is.
The vriable list (varlt) contains the variable (v) */
void fEngine::check_instantiation(string Major, fVariableList varlist, string v, fCheckInstantiate checkInstant)
{
    i = 1;

    /* find variable in the variable list */
    while (((v == varlist.getVariableList(i)) != 0) && (i <= 51)) i = i + 1;

    /* check if already instantiated */
    if (instlt[i] != 1)
    {
        /* mark instantiated */
        instlt[i] = 1;

        /* the designer of this knowledge base places the input
        statements to instantiate the variables in this case
        statement */

        checkInstant.setQuestions(Major, fvar_list, );
    }
    /* end of input statements for the position knowledge base */
}

//==========================================================================
/* Search clause variable list for a variable (clauseVarList) equal to the
one in front of the conclusion queue (condiVariableQueue). Return the statement
number (statementNumber). If there is no match, i.e., statementNumber=0, the first statement
for the space is f. */
void fEngine::search(fClauseVarList cVarList)
{
    int k = 0;
    int flag;
    flag = 0;
    statementNumber = f;

    while ((flag == 0) && (statementNumber <= 150))
    {
        clauseNumber = 1;
        k = (statementNumber - 1) * 3 + clauseNumber;
        while ((cVarList.getClauseVarList(k) == condiVariableQueue.front()) != 0 && (clauseNumber < 4))
        {
            clauseNumber = clauseNumber + 1;
            k = (statementNumber - 1) * 3 + clauseNumber;
        }

        if ((cVarList.getClauseVarList(k) == condiVariableQueue.front()) == 0) flag = 1;
        if (flag == 0) statementNumber = statementNumber + 1;
    }
    if (flag == 0) statementNumber = 0;
}


//==========================================================================
/* Routine to instantiate a varialbe (v) and then place it on the
back of the queu (condiVariableQueue[backPointer]), if it is not already there. */
void fEngine::instantiate(fVariableList varlist, string v)
{
    i = 1;
    /* find varialbe in the varialbe list (variableList) */
    while (((v == varlist.getVariableList(i)) != 0) && (i <= 50)) i = i + 1;

    /* instantiate it */
    instlt[i] = 1;
    i = 1;

    /* determine if (v) is or already has been on the queue (condiVariableQueue) */
    while (((v == condiVariableQueue.front() || v == condiVariableQueue.back()) != 0) && (i <= 50)) i = i + 1;
    /* variable has not been on the queue. Store it in the back of the queue */
    if ((v == condiVariableQueue.front() || v == condiVariableQueue.back()) != 0)
    {
        condiVariableQueue.push(v);
    }
}