#include "fVariableList.h"

#include <iostream>
#include <string>
using namespace std;

/* enter variables which are in the IF part, 1 at a time in
    the exact order that they occur. Up to 3 variables per
    IF statement. Do not duplicate any variable names. Any
    name is used only once. If no more variables left, just
    hit return key */

fVariableList::fVariableList()
{
    variableList[0] = "Major";
    variableList[1] = "Electrical";
    variableList[2] = "Mechanical";
    variableList[3] = "PNEnvironment";
    variableList[4] = "OilGas";
    variableList[5] = "ChemEnergy";
    variableList[6] = "ChemMatter";
    variableList[7] = "Dna";
    variableList[8] = "LivOrganism";
    variableList[9] = "MarLife";
    variableList[10] = "Star";
    variableList[11] = "Exchange";
    variableList[12] = "Money";
    variableList[13] = "Opportunities";
    variableList[14] = "Manage";
    variableList[15] = "Econ";
    variableList[16] = "Photo";
    variableList[17] = "Poetry";
    variableList[18] = "Film";
    variableList[19] = "Dance";
    variableList[20] = "Acting";
    variableList[21] = "News";
    variableList[22] = "Info";
    variableList[23] = "Promote";
    variableList[24] = "Employer";
    variableList[25] = "Edit";
    variableList[26] = "International";
    variableList[27] = "Plant";
    variableList[28] = "Domestic";
    variableList[29] = "Climate";
    variableList[30] = "People";
    variableList[31] = "FamMar";
    variableList[32] = "Mental";
    variableList[33] = "Substance";
    variableList[34] = "Experiment";
    variableList[35] = "HR";
    variableList[36] = "Inspecting";
    variableList[37] = "Garden";
    variableList[38] = "Trees";
    variableList[39] = "Bees";
    variableList[40] = "WildLife";
    variableList[41] = "Care";
    variableList[42] = "Plan";
    variableList[43] = "Teeth";
    variableList[44] = "Assistant";
    variableList[45] = "Disease";
    variableList[46] = "Elementary";
    variableList[47] = "College";
    variableList[48] = "Education";
    variableList[49] = "Curriculum";
    variableList[50] = "Language";

}


string fVariableList::getVariableList(int i)
{
    return variableList[i];
}



fVariableList::~fVariableList()
{
    //dtor
}