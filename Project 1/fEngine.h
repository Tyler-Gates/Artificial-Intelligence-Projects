#pragma once
#include <iostream>
#include <string>
#include <queue>

#include "fVariableList.h"
#include "fClauseVarList.h"
#include "fCheckInstantiate.h"
using namespace std;


class fEngine {
public:
	fEngine();
	fEngine(std::string major);
	~fEngine();

	
	string Area;
	string Major, Electrical, Mechanical, PNEnvironment, OilGas, ChemEnergy, ChemMatter,
		Dna, LivOrganism, MarLife, Star, Exchange, Money, Opportunities, Manage, Econ, Photo, Poetry,
		Film, Dance, Acting, News, Info, Promote, Employer, Edit, International, Plant, Domestic, Climate,
		People, FamMar, Mental, Substance, Experiment, HR, Inspecting, Garden, Trees, Bees, WildLife,
		Care, Plan, Teeth, Assistant, Disease, Elementary, College, Education, Curriculum, Language;
	int instlt[150]; /* instantiated list*/
	int f, i, j, s; // iterators
	int statementNumber; /* statement number */
	int clauseNumber;  /* clause number */

	string v; /*variable */
	int k = 0;
	fVariableList varlist;
	fClauseVarList cVarList;
	fCheckInstantiate checkInstant;

	queue<string> condiVariableQueue;
	void search(fClauseVarList cVarList);
	void check_instantiation(string Major, fVariableList varlist, string v, fCheckInstantiate checkInstant);
	void instantiate(fVariableList varlist, string v);
	void run();

};