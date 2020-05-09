#include "fClauseVarList.h"

#include <iostream>
#include <string>
using namespace std;


/* enter variables as they appear in the IF clauses, Up to 3
    variables per IF statement. If no more variables left, just
    hit return key */

fClauseVarList::fClauseVarList()
{
    clauseVarList[0] = "Major";
    clauseVarList[1] = "Electrical";
    clauseVarList[2] = "";
    clauseVarList[3] = "Major";
    clauseVarList[4] = "Mechanical";
    clauseVarList[5] = "";
    clauseVarList[6] = "Major";
    clauseVarList[7] = "PNEnvironment";
    clauseVarList[8] = "";
    clauseVarList[9] = "Major";
    clauseVarList[10] = "OilGas";
    clauseVarList[11] = "";
    clauseVarList[12] = "Major";
    clauseVarList[13] = "ChemEnergy";
    clauseVarList[14] = "";
    clauseVarList[15] = "Major";
    clauseVarList[16] = "ChemMatter";
    clauseVarList[17] = "";
    clauseVarList[18] = "Major";
    clauseVarList[19] = "Dna";
    clauseVarList[20] = "";
    clauseVarList[21] = "Major";
    clauseVarList[22] = "LivOrganism";
    clauseVarList[23] = "";
    clauseVarList[24] = "Major";
    clauseVarList[25] = "MarLife";
    clauseVarList[26] = "";
    clauseVarList[27] = "Major";
    clauseVarList[28] = "Star";
    clauseVarList[29] = "";
    clauseVarList[30] = "Major";
    clauseVarList[31] = "Exchange";
    clauseVarList[32] = "";
    clauseVarList[33] = "Major";
    clauseVarList[34] = "Money";
    clauseVarList[35] = "";
    clauseVarList[36] = "Major";
    clauseVarList[37] = "Opportunities";
    clauseVarList[38] = "";
    clauseVarList[39] = "Major";
    clauseVarList[40] = "Manage";
    clauseVarList[41] = "";
    clauseVarList[42] = "Major";
    clauseVarList[43] = "Econ";
    clauseVarList[44] = "";
    clauseVarList[45] = "Major";
    clauseVarList[46] = "Photo";
    clauseVarList[47] = "";
    clauseVarList[48] = "Major";
    clauseVarList[49] = "Poetry";
    clauseVarList[50] = "";
    clauseVarList[51] = "Major";
    clauseVarList[52] = "Film";
    clauseVarList[53] = "";
    clauseVarList[54] = "Major";
    clauseVarList[55] = "Dance";
    clauseVarList[56] = "";
    clauseVarList[57] = "Major";
    clauseVarList[58] = "Acting";
    clauseVarList[59] = "";
    clauseVarList[60] = "Major";
    clauseVarList[61] = "News";
    clauseVarList[62] = "";
    clauseVarList[63] = "Major";
    clauseVarList[64] = "Info";
    clauseVarList[65] = "";
    clauseVarList[66] = "Major";
    clauseVarList[67] = "Promote";
    clauseVarList[68] = "";
    clauseVarList[69] = "Major";
    clauseVarList[70] = "Employer";
    clauseVarList[71] = "";
    clauseVarList[72] = "Major";
    clauseVarList[73] = "Edit";
    clauseVarList[74] = "";
    clauseVarList[75] = "Major";
    clauseVarList[76] = "International";
    clauseVarList[77] = "";
    clauseVarList[78] = "Major";
    clauseVarList[79] = "Plant";
    clauseVarList[80] = "";
    clauseVarList[81] = "Major";
    clauseVarList[82] = "Domestic";
    clauseVarList[83] = "";
    clauseVarList[84] = "Major";
    clauseVarList[85] = "Climate";
    clauseVarList[86] = "";
    clauseVarList[87] = "Major";
    clauseVarList[88] = "People";
    clauseVarList[89] = "";
    clauseVarList[90] = "Major";
    clauseVarList[91] = "FamMar";
    clauseVarList[92] = "";
    clauseVarList[93] = "Major";
    clauseVarList[94] = "Mental";
    clauseVarList[95] = "";
    clauseVarList[96] = "Major";
    clauseVarList[97] = "Substance";
    clauseVarList[98] = "";
    clauseVarList[99] = "Major";
    clauseVarList[100] = "Experiment";
    clauseVarList[101] = "";
    clauseVarList[102] = "Major";
    clauseVarList[103] = "HR";
    clauseVarList[104] = "";
    clauseVarList[105] = "Major";
    clauseVarList[106] = "Inspecting";
    clauseVarList[107] = "";
    clauseVarList[108] = "Major";
    clauseVarList[109] = "Garden";
    clauseVarList[110] = "";
    clauseVarList[111] = "Major";
    clauseVarList[112] = "Trees";
    clauseVarList[113] = "";
    clauseVarList[114] = "Major";
    clauseVarList[115] = "Bees";
    clauseVarList[116] = "";
    clauseVarList[117] = "Major";
    clauseVarList[118] = "WildLife";
    clauseVarList[119] = "";
    clauseVarList[120] = "Major";
    clauseVarList[121] = "Care";
    clauseVarList[122] = "";
    clauseVarList[123] = "Major";
    clauseVarList[124] = "Plan";
    clauseVarList[125] = "";
    clauseVarList[126] = "Major";
    clauseVarList[127] = "Teeth";
    clauseVarList[128] = "";
    clauseVarList[129] = "Major";
    clauseVarList[130] = "Assistant";
    clauseVarList[131] = "";
    clauseVarList[132] = "Major";
    clauseVarList[133] = "Disease";
    clauseVarList[134] = "";
    clauseVarList[135] = "Major";
    clauseVarList[136] = "Elementary";
    clauseVarList[137] = "";
    clauseVarList[138] = "Major";
    clauseVarList[139] = "College";
    clauseVarList[140] = "";
    clauseVarList[141] = "Major";
    clauseVarList[142] = "Education";
    clauseVarList[143] = "";
    clauseVarList[144] = "Major";
    clauseVarList[145] = "Curriculum";
    clauseVarList[146] = "";
    clauseVarList[147] = "Major";
    clauseVarList[148] = "Language";
    clauseVarList[149] = "";
    clauseVarList[150] = "";

}

string fClauseVarList::getClauseVarList(int i)
{
    return clauseVarList[i];
}

void fClauseVarList::setClauseVarList(int i, string s) {
    clauseVarList[i] = s;
}


fClauseVarList::~fClauseVarList()
{
    //dtor
}
