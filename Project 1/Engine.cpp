#include "Engine.h"

/*Initializes the engine with the appropriate information*/
Engine::Engine(std::map<std::string, std::string> variable_list,
    std::map<std::string, std::string> conclusion_list,
    std::map<int, std::string> knowledge_base,
    std::map<std::string, std::queue<int> > con_ls,
    std::vector<std::string> clause_variable_list,
    std::vector<std::string> clause_conditions_list,
    std::map<std::string, std::string> fvar_list)
{
    this->var_list = VariableList(variable_list, conclusion_list);
    this->knowlg_base = KnowledgeBase(knowledge_base);
    this->con_list = ConclusionList(con_ls);
    this->clause_var_list = ClauseVariableList(clause_variable_list, clause_conditions_list);
    this->fvar_list = VariableList(fvar_list, conclusion_list);
}

/*Adds string to conclusion stack*/
void Engine::startp(std::string conclusion) {
    conclusion_stack = ConclusionStack(conclusion);
}

/*loop is where the entire program takes place, it will loop through forward 
  and backward chaining here incramentally based on GUI events*/
std::string Engine::loop() {

    while (!conclusion_stack.VarStackEmpty()) {
        std::string current_con = conclusion_stack.getStackVar();
        updateconclusionStack(current_con);
        std::string property = "";
        int current_cls = conclusion_stack.getStackClause() - 2;

        bool fullfilled = true;
        if (current_cls < -1) {
            conclusion_stack.popStackVar();
            std::string result = "UNDEFINED";
            var_list.updateCon(current_con, result);
            fullfilled = false;
        }

        int i = 0;
        while (i < var_list.var_size && fullfilled) {
            current_cls++;
            std::string clause_var = clause_var_list.getVar(current_cls);
            if (clause_var == "")
                break;
            else {
                if (var_list.searchConVar(clause_var) == "VAR") {
                    bool var_define = var_list.isVarSet(clause_var);
                    if (!var_define) {
                        this->current_var = clause_var;
                        return clause_var;
                    }
                    property = var_list.getVarProperty(clause_var);
                    if (property != clause_var_list.getCondition(current_cls)) {
                        fullfilled = false;
                        conclusion_stack.popStackRule();
                        conclusion_stack.popStackClause();
                        con_list.popRuleNumber(current_con);
                    }
                }
                else {
                    property = var_list.getConProperty(clause_var);
                    if (property == "") {
                        conclusion_stack.setStackVar(clause_var);
                        fullfilled = false;
                    }
                    else {
                        if (property != clause_var_list.getCondition(current_cls)) {
                            conclusion_stack.popStackRule();
                            conclusion_stack.popStackClause();
                            fullfilled = false;
                            con_list.popRuleNumber(current_con);
                        }
                    }
                }
            }
            i++;
        }

        if (fullfilled) {
            con_list.popRuleNumber(current_con);
            int rule_nmb = conclusion_stack.getStackRule();

            conclusion_stack.popStackClause();
            conclusion_stack.popStackRule();
            conclusion_stack.popStackVar();
            std::string result = knowlg_base.getResult(rule_nmb);
            var_list.updateCon(current_con, result);
            this->conclusion = current_con;
            this->results = result;
        }
    }
    if (backwarddone) {
        return run(fvar_list);
    }
        Major = this->results;
        backwarddone = true;
        if (this->results == "")
            return run(fvar_list);
        return "Major: " + this->results + "\nPress YES/NO to continue\n";
}


/*updateconclusionStack updates the conclusion stack with a new conclusion variable con_var*/
void Engine:: updateconclusionStack(std::string con_var) {
    int rule_num = con_list.getRuleNumber(con_var);
    int clause_number = var_list.var_size * (rule_num / 10 - 1) + 1;

    conclusion_stack.setStackClause(clause_number);
    conclusion_stack.setStackRule(rule_num);
}

/*Runs the forward chaining part of the code*/
string Engine::run(VariableList fvar_list) {
      /*Prompts the user for input on the property of the variable(questions)
        Will continue to loop until a YES is reached, or will continue until All NOs are
        reached where it will output RESTART PROGRAM*/
    if (fvar_list.getVarProperty(var) == "NO") {
        done = false;
    }
    if (!done)
        return setQuestions(Major, fvar_list);
 
    /*Runs through the if part of the if then statements*/
        if ((Major == "ENGINEERING") &&
            (fvar_list.getVarProperty("Would you like to design and develop electrical equipment? \n") == "YES")) {
            s = 1; statementNumber = 1; 
        }
        if ((Major == "ENGINEERING") &&
            (fvar_list.getVarProperty("Would you like to design, analyze, manufacture, and maintain mechanical systems? \n") == "YES")) {
            s = 1; statementNumber = 2; 
        }
        if ((Major == "ENGINEERING") &&
            (fvar_list.getVarProperty("Would you like to design, construct, and maintain the physical and naturally built environment? \n") == "YES")) {
            s = 1; statementNumber = 3;
        }
        if ((Major == "ENGINEERING") &&
            (fvar_list.getVarProperty("Would you like to design and develop methods for extracting oil and gas from deposits below the Earth’s surface? \n") == "YES")) {
            s = 1; statementNumber = 4; 
        }
        if ((Major == "ENGINEERING") &&
            (fvar_list.getVarProperty("Are you interested in efficiently using, producing, designing, transporting and transforming energy and materials? \n") == "YES")) {
            s = 1; statementNumber = 5; 
        }
        if ((Major == "SCIENCE") &&
            (fvar_list.getVarProperty("Would you like to learn more about the composition of matter and its properties? \n") == "YES")) {
            s = 1; statementNumber = 2;
        }
        if ((Major == "SCIENCE") &&
            (fvar_list.getVarProperty("Would you like to know more about study DNA, proteins and cell parts? \n") == "YES")) {
            s = 1; statementNumber = 2; 
        }
        if ((Major == "SCIENCE") &&
            (fvar_list.getVarProperty("Are you interested in the branch of science concerning living organisms? \n") == "YES")) {
            s = 1; statementNumber = 8;
        }
        if ((Major == "SCIENCE") &&
            (fvar_list.getVarProperty("Does marine life and organisms in the sea interest you? \n") == "YES")) {
            s = 1; statementNumber = 9; 
        }
        if ((Major == "SCIENCE") &&
            (fvar_list.getVarProperty("Would you like to observe astronomical objects such as stars, planets, moons, comets and galaxies? \n") == "YES")) {
            s = 1; statementNumber = 10; 
        }
        if ((Major == "BUSINESS") &&
            (fvar_list.getVarProperty("Are you interested in the study and management of exchange relationships? \n") == "YES")) {
            s = 1; statementNumber = 11; 
        }
        if ((Major == "BUSINESS") &&
            (fvar_list.getVarProperty("Would you like to know more about the study of money and how it is used?  \n") == "YES")) {
            s = 1; statementNumber = 12;
        }
        if ((Major == "BUSINESS") &&
            (fvar_list.getVarProperty("Are you interested in recognizing and developing opportunities?   \n") == "YES")) {
            s = 1; statementNumber = 13;
        }
        if ((Major == "BUSINESS") &&
            (fvar_list.getVarProperty("Would you like to oversee and supervise business operations?   \n") == "YES")) {
            s = 1; statementNumber = 14; 
        }
        if ((Major == "BUSINESS") &&
            (fvar_list.getVarProperty("Are you interested in the quantitative methods to analyze business enterprises and the factors contributing to the diversity of organizational structures and the relationships of firms with labour, capital and product markets?  \n") == "YES")) {
            s = 1; statementNumber = 15; 
        }
        if ((Major == "ART") &&
            (fvar_list.getVarProperty("Do photographs interest you? \n") == "YES")) {
            s = 1; statementNumber = 16;
        }
        if ((Major == "ART") &&
            (fvar_list.getVarProperty("Are you interested in using aesthetic and rhythmic qualities of language—such as phonaesthetics, sound symbolism, and metre—to evoke meanings in addition to, or in place of, the prosaic ostensible meaning?\n") == "YES")) {
            s = 1; statementNumber = 17;
        }
        if ((Major == "ART") &&
            (fvar_list.getVarProperty("Are you interested in capturing live moments through film?  \n") == "YES")) {
            s = 1; statementNumber = 18; 
        }
        if ((Major == "ART") &&
            (fvar_list.getVarProperty("Do you like to express yourself through dance?  \n") == "YES")) {
            s = 1; statementNumber = 19;
        }
        if ((Major == "ART") &&
            (fvar_list.getVarProperty("Do you like to entertain the masses by acting?  \n") == "YES")) {
            s = 1; statementNumber = 20;
        }
        if ((Major == "ENGLISH") &&
            (fvar_list.getVarProperty("Would you like to write for newspapers, magazines, or news websites or prepare news to be broadcasted?  \n") == "YES")) {
            s = 1; statementNumber = 21; 
        }
        if ((Major == "ENGLISH") &&
            (fvar_list.getVarProperty("Are you interested in transferring information between two or more parties? \n") == "YES")) {
            s = 1; statementNumber = 22; 
        }
        if ((Major == "ENGLISH") &&
            (fvar_list.getVarProperty("Would you like to promote groups, or organizations by selecting publicity material and releasing it through various communications media?\n") == "YES")) {
            s = 1; statementNumber = 23; 
        }
        if ((Major == "ENGLISH") &&
            (fvar_list.getVarProperty("Are you interested in helping an employer find job candidates who are most qualified to meet the organization's needs?  \n") == "YES")) {
            s = 1; statementNumber = 24; 
        }
        if ((Major == "ENGLISH") &&
            (fvar_list.getVarProperty("Are you interested in determining the final content of a text, particularly a newspaper or magazine?\n") == "YES")) {
            s = 1; statementNumber = 25; 
        }
        if ((Major == "GEOGRAPHY") &&
            (fvar_list.getVarProperty("Are you interested in developing international influence or help start operating on an international scale?  \n") == "YES")) {
            s = 1; statementNumber = 26; 
        }
        if ((Major == "GEOGRAPHY") &&
            (fvar_list.getVarProperty("Are you interested in helping to increase the plant species and the ground cover they provide?  \n") == "YES")) {
            s = 1; statementNumber = 27; 
        }
        if ((Major == "GEOGRAPHY") &&
            (fvar_list.getVarProperty("Are you interested in the management and the biology of domestic animals? \n") == "YES")) {
            s = 1; statementNumber = 28; 
        }
        if ((Major == "GEOGRAPHY") &&
            (fvar_list.getVarProperty("Would you like to know more about the scientific study of climate, scientifically defined as weather conditions averaged over a period of time?  \n") == "YES")) {
            s = 1; statementNumber = 29; 
        }
        if ((Major == "GEOGRAPHY") &&
            (fvar_list.getVarProperty("Would you like to work with towns to make them more effecient and environmentally friendly?  \n") == "YES")) {
            s = 1; statementNumber = 30; 
        }
        if ((Major == "PSYCHOLOGY") &&
            (fvar_list.getVarProperty("Would you like to help families and marriages work through their problems?  \n") == "YES")) {
            s = 1; statementNumber = 31; 
        }
        if ((Major == "PSYCHOLOGY") &&
            (fvar_list.getVarProperty("Are you interested in providing hands-on direct care to developmentally or emotionally disabled people, as well as those diagnosed with mental illnesses? \n") == "YES")) {
            s = 1; statementNumber = 32; 
        }
        if ((Major == "PSYCHOLOGY") &&
            (fvar_list.getVarProperty("Would you like to help people who have uncontrolled use of alcohol, illegal drugs or prescribed drugs that affect normal daily life? \n") == "YES")) {
            s = 1; statementNumber = 33; 
        }
        if ((Major == "PSYCHOLOGY") &&
            (fvar_list.getVarProperty("Would you like to apply experimental methods to psychological study and the processes that underlie it?  \n") == "YES")) {
            s = 1; statementNumber = 34; 
        }
        if ((Major == "PSYCHOLOGY") &&
            (fvar_list.getVarProperty("Are you interested in taking a strategic approach to the effective management of people in a company or organization such that they help their business gain a competitive advantage?  \n") == "YES")) {
            s = 1; statementNumber = 35;
        }
        if ((Major == "AGRICULTURE") &&
            (fvar_list.getVarProperty("Are you interested in inspecting food and animals meant for consumption? \n") == "YES")) {
            s = 1; statementNumber = 36; 
        }
        if ((Major == "AGRICULTURE") &&
            (fvar_list.getVarProperty("Would you like to be an expert in garden cultivation and management? \n") == "YES")) {
            s = 1; statementNumber = 37; 
        }
        if ((Major == "AGRICULTURE") &&
            (fvar_list.getVarProperty("Are you interested in the cultivation, management, and study of individual trees, shrubs, vines, and other perennial woody plants in dendrology and horticulture? \n") == "YES")) {
            s = 1; statementNumber = 38;
        }
        if ((Major == "AGRICULTURE") &&
            (fvar_list.getVarProperty("Would you like to own and breed bees, especially for their honey? \n") == "YES")) {
            s = 1; statementNumber = 39;
        }
        if ((Major == "AGRICULTURE") &&
            (fvar_list.getVarProperty("Would you like to specifically deal with crimes against animals?  \n") == "YES")) {
            s = 1; statementNumber = 40;
        }
        if ((Major == "HEALTHCARE") &&
            (fvar_list.getVarProperty("Are you interested in the care of individuals, families, and communities so they may attain, maintain, or recover optimal health and quality of life?\n") == "YES")) {
            s = 1; statementNumber = 41; 
        }
        if ((Major == "HEALTHCARE") &&
            (fvar_list.getVarProperty("Would you like to plan, direct, and coordinate medical and health services? \n") == "YES")) {
            s = 1; statementNumber = 42; 
        }
        if ((Major == "HEALTHCARE") &&
            (fvar_list.getVarProperty("Would you like to specialize in dentistry, the diagnosis, prevention, and treatment of diseases and conditions of the oral cavity?  \n") == "YES")) {
            s = 1; statementNumber = 43; 
        }
        if ((Major == "HEALTHCARE") &&
            (fvar_list.getVarProperty("Are you interested in being a health care practitioner who practices medicine in collaboration with or under the supervision of a physician? \n") == "YES")) {
            s = 1; statementNumber = 44; 
        }
        if ((Major == "HEALTHCARE") &&
            (fvar_list.getVarProperty("Are you interested in the science and art of preventing disease? \n") == "YES")) {
            s = 1; statementNumber = 45; 
        }
        if ((Major == "EDUCATION") &&
            (fvar_list.getVarProperty("Would you like to teach children in pre K to 5th grade?  \n") == "YES")) {
            s = 1; statementNumber = 46; 
        }
        if ((Major == "EDUCATION") &&
            (fvar_list.getVarProperty("Would you like to teach at the college or university level?  \n") == "YES")) {
            s = 1; statementNumber = 47; 
        }
        if ((Major == "EDUCATION") &&
            (fvar_list.getVarProperty("Are you interested in being involved in managing some educational system? \n") == "YES")) {
            s = 1; statementNumber = 48; 
        }
        if ((Major == "EDUCATION") &&
            (fvar_list.getVarProperty("Are you interested in deciding what methods and topics will be used to teach lessons? \n") == "YES")) {
            s = 1; statementNumber = 49;
        }
        if ((Major == "EDUCATION") &&
            (fvar_list.getVarProperty("Would you like to  instruct non-English speaking individuals on the fundamentals of the English language so that they can communicate with others? \n") == "YES")) {
            s = 1; statementNumber = 50; 
        }
    switch (statementNumber)
    {

    case 1:
        return "Career = Electrical Engineering\n";
        break;
    case 2:
        return "Career = Mechanical Engineering\n";
        break;
    case 3:
        return "Career = Civil Engineering\n";
        break;
    case 4:
        return "Career = Petroleum Engineering\n";
        break;
    case 5:
        return "Career =  Chemical Engineering\n";
        break;


    case 6:
        return "Career = Chemistry\n";
        break;
    case 7:
        return "Career = Biochemistry\n";
        break;
    case 8:
        return "Career = Biology\n";
        break;
    case 9:
        return "Career = Marine Biology\n";
        break;
    case 10:
        return "Career = Astronomy\n";
        break;


    case 11:
        return "Career = Marketing\n";
        break;
    case 12:
        return "Career = Finance\n";
        break;
    case 13:
        return "Career = Entrepreneurial Studies\n";
        break;
    case 14:
        return "Career = Business Administration/Management\n";
        break;
    case 15:
        return "Career = Business Economics\n";
        break;


    case 16:
        return "Career = Photography\n";
        break;
    case 17:
        return "Career = Poetry\n";
        break;
    case 18:
        return "Career = Film\n";
        break;
    case 19:
        return "Career = Dance\n";
        break;
    case 20:
        return "Career = Drama\n";
        break;


    case 21:
        return "Career = Journalism\n";
        break;
    case 22:
        return "Career = Technical Writer\n";
        break;
    case 23:
        return "Career = Public Relations Specialist\n";
        break;
    case 24:
        return "Career = Human Resource Specialist\n";
        break;
    case 25:
        return "Career = Editor\n";
        break;


    case 26:
        return "Career = Globalization\n";
        break;
    case 27:
        return "Career = World Vegetation\n";
        break;
    case 28:
        return "Career = Physical Environment\n";
        break;
    case 29:
        return "Career = Applied Climatology\n";
        break;
    case 30:
        return "Career = Urban Planner\n";
        break;


    case 31:
        return "Career = Marriage/Family Therapist\n";
        break;
    case 32:
        return "Career = Psychiatric Technician\n";
        break;
    case 33:
        return "Career = Substance Abuse Counselor\n";
        break;
    case 34:
        return "Career = Experimental Psychologist\n";
        break;
    case 35:
        return "Career = Human Resource Personnel\n";
        break;


    case 36:
        return "Career = Agricultural Inspector\n";
        break;
    case 37:
        return "Career = Horticulturist\n";
        break;
    case 38:
        return "Career = Arborist\n";
        break;
    case 39:
        return "Career = Beekeeper\n";
        break;
    case 40:
        return "Career = Wildlife Forensics\n";
        break;



    case 41:
        return "Career = Nursing\n";
        break;
    case 42:
        return "Career = Health Services Management\n";
        break;
    case 43:
        return "Career = Dentist\n";
        break;
    case 44:
        return "Career = Physician Assistant\n";
        break;
    case 45:
        return "Career = Public Health\n";
        break;


    case 46:
        return "Career = Elementary education\n";
        break;
    case 47:
        return "Career = Professor\n";
        break;
    case 48:
        return "Career = Education Coordinator\n";
        break;
    case 49:
        return "Career = Curriculum Developer\n";
        break;
    case 50:
        return "Career = ESOL Teacher\n";
        break;

    }
    return "Whoops, looks like you picked the wrong major!\nPlease restart the program and try again!";
}


/*setQuestions takes the major achieved through backward chaining and uses it to set the 
  fvar_list variable property to YES/NO by returning the question to the message box and letting the 
  button press event set the variable property*/
string Engine::setQuestions(string& Major, VariableList fvar_list)
{
        if (Major == "ENGINEERING")
        {
            
            if (fvar_list.getVarProperty("Would you like to design and develop electrical equipment? \n") == "")
            {
                done = true;
                var = "Would you like to design and develop electrical equipment? \n";
                return "Would you like to design and develop electrical equipment? \n";
            }

            if (fvar_list.getVarProperty("Would you like to design, analyze, manufacture, and maintain mechanical systems? \n") == "")
            {
                done = true;
                var = "Would you like to design, analyze, manufacture, and maintain mechanical systems? \n";
                return "Would you like to design, analyze, manufacture, and maintain mechanical systems? \n";
            }
            
            if (fvar_list.getVarProperty("Would you like to design, construct, and maintain the physical and naturally built environment? \n") == "")
            {
                done = true;
                var = "Would you like to design, construct, and maintain the physical and naturally built environment? \n";
                return "Would you like to design, construct, and maintain the physical and naturally built environment? \n";
            }
            
            if (fvar_list.getVarProperty("Would you like to design and develop methods for extracting oil and gas from deposits below the Earth’s surface? \n") == "")
            {
                done = true;
                var = "Would you like to design and develop methods for extracting oil and gas from deposits below the Earth’s surface? \n";
                return "Would you like to design and develop methods for extracting oil and gas from deposits below the Earth’s surface? \n";
            }
            
            if (fvar_list.getVarProperty("Are you interested in efficiently using, producing, designing, transporting and transforming energy and materials? \n") == "")
            {
                done = true;
                var = "Are you interested in efficiently using, producing, designing, transporting and transforming energy and materials? \n";
                return "Are you interested in efficiently using, producing, designing, transporting and transforming energy and materials? \n";
            }

            return "UH-OH Doesn't seem like you chose the right profession! :(\nPlease restart the Application!\n";
        }
        if (Major == "SCIENCE")
        {
            
            if (fvar_list.getVarProperty("Would you like to learn more about the composition of matter and its properties? \n") == "")
            {
                done = true;
                var = "Would you like to learn more about the composition of matter and its properties? \n";
                return "Would you like to learn more about the composition of matter and its properties? \n";
            }
            
            if (fvar_list.getVarProperty("Would you like to know more about study DNA, proteins and cell parts? \n") == "")
            {
                done = true;
                var = "Would you like to know more about study DNA, proteins and cell parts? \n";
                return "Would you like to know more about study DNA, proteins and cell parts? \n";
            }

            if (fvar_list.getVarProperty("Are you interested in the branch of science concerning living organisms? \n") == "")
            {
                done = true;
                var = "Are you interested in the branch of science concerning living organisms? \n";
                return "Are you interested in the branch of science concerning living organisms? \n";
            }
            
            if (fvar_list.getVarProperty("Does marine life and organisms in the sea interest you? \n") == "")
            {
                done = true;
                var = "Does marine life and organisms in the sea interest you? \n";
                return "Does marine life and organisms in the sea interest you? \n";
            }

            if (fvar_list.getVarProperty("Would you like to observe astronomical objects such as stars, planets, moons, comets and galaxies? \n") == "")
            {
                done = true;
                var = "Would you like to observe astronomical objects such as stars, planets, moons, comets and galaxies? \n";
                return "Would you like to observe astronomical objects such as stars, planets, moons, comets and galaxies? \n";
            }


            return "UH-OH Doesn't seem like you chose the right profession! :(\nPlease restart the Application!\n";
        }
        if (Major == "BUSINESS")
        {
           
            if (fvar_list.getVarProperty("Are you interested in the study and management of exchange relationships? \n") == "")
            {
                done = true;
                var = "Are you interested in the study and management of exchange relationships? \n";
                return "Are you interested in the study and management of exchange relationships? \n";
            }
            if (fvar_list.getVarProperty("Would you like to know more about the study of money and how it is used?  \n") == "")
            {
                done = true;
                var = "Would you like to know more about the study of money and how it is used?  \n";
                return "Would you like to know more about the study of money and how it is used?  \n";
            }
            
            if (fvar_list.getVarProperty("Are you interested in recognizing and developing opportunities?   \n") == "")
            {
                done = true;
                var = "Are you interested in recognizing and developing opportunities?   \n";
                return "Are you interested in recognizing and developing opportunities?   \n";
            }
            
            if (fvar_list.getVarProperty("Would you like to oversee and supervise business operations?   \n") == "")
            {
                done = true;
                var = "Would you like to oversee and supervise business operations?   \n";
                return "Would you like to oversee and supervise business operations?   \n";
            }
            
            if (fvar_list.getVarProperty("Are you interested in the quantitative methods to analyze business enterprises and the factors contributing to the diversity of organizational structures and the relationships of firms with labour, capital and product markets?  \n") == "")
            {
                done = true;
                var = "Are you interested in the quantitative methods to analyze business enterprises and the factors contributing to the diversity of organizational structures and the relationships of firms with labour, capital and product markets?  \n";
                return "Are you interested in the quantitative methods to analyze business enterprises and the factors contributing to the diversity of organizational structures and the relationships of firms with labour, capital and product markets?  \n";
            }


            return "UH-OH Doesn't seem like you chose the right profession! :(\nPlease restart the Application!\n";
        }
        if (Major == "ART")
        {
           
            if (fvar_list.getVarProperty("Do photographs interest you? \n") == "")
            {
                done = true;
                var = "Do photographs interest you? \n";
                return "Do photographs interest you? \n";
            }
            
            if (fvar_list.getVarProperty("Are you interested in using aesthetic and rhythmic qualities of language—such as phonaesthetics, sound symbolism, and metre—to evoke meanings in addition to, or in place of, the prosaic ostensible meaning?\n") == "")
            {
                done = true;
                var = "Are you interested in using aesthetic and rhythmic qualities of language—such as phonaesthetics, sound symbolism, and metre—to evoke meanings in addition to, or in place of, the prosaic ostensible meaning?\n";
                return "Are you interested in using aesthetic and rhythmic qualities of language—such as phonaesthetics, sound symbolism, and metre—to evoke meanings in addition to, or in place of, the prosaic ostensible meaning?\n";
            }
            
            if (fvar_list.getVarProperty("Are you interested in capturing live moments through film?  \n") == "")
            {
                done = true;
                var = "Are you interested in capturing live moments through film?  \n";
                return "Are you interested in capturing live moments through film?  \n";
            }
            
            if (fvar_list.getVarProperty("Do you like to express yourself through dance?  \n") == "")
            {
                done = true;
                var = "Do you like to express yourself through dance?  \n";
                return "Do you like to express yourself through dance?  \n";
            }
            
            if (fvar_list.getVarProperty("Do you like to entertain the masses by acting?  \n") == "")
            {
                done = true;
                var = "Do you like to entertain the masses by acting?  \n";
                return "Do you like to entertain the masses by acting?  \n";
            }


            return "UH-OH Doesn't seem like you chose the right profession! :(\nPlease restart the Application!\n";
        }
        if (Major == "ENGLISH")
        {
            
            if (fvar_list.getVarProperty("Would you like to write for newspapers, magazines, or news websites or prepare news to be broadcasted?  \n") == "")
            {
                done = true;
                var = "Would you like to write for newspapers, magazines, or news websites or prepare news to be broadcasted?  \n";
                return "Would you like to write for newspapers, magazines, or news websites or prepare news to be broadcasted?  \n";
            }

            if (fvar_list.getVarProperty("Are you interested in transferring information between two or more parties? \n") == "")
            {
                done = true;
                var = "Are you interested in transferring information between two or more parties? \n";
                return "Are you interested in transferring information between two or more parties? \n";
            }

            if (fvar_list.getVarProperty("Would you like to promote groups, or organizations by selecting publicity material and releasing it through various communications media?\n") == "")
            {
                done = true;
                var = "Would you like to promote groups, or organizations by selecting publicity material and releasing it through various communications media?\n";
                return "Would you like to promote groups, or organizations by selecting publicity material and releasing it through various communications media?\n";
            }
            
            if (fvar_list.getVarProperty("Are you interested in helping an employer find job candidates who are most qualified to meet the organization's needs?  ") == "")
            {
                done = true;
                var = "Are you interested in helping an employer find job candidates who are most qualified to meet the organization's needs?  \n";
                return "Are you interested in helping an employer find job candidates who are most qualified to meet the organization's needs?  \n";
            }
            
            if (fvar_list.getVarProperty("Are you interested in determining the final content of a text, particularly a newspaper or magazine?\n") == "")
            {
                done = true;
                var = "Are you interested in determining the final content of a text, particularly a newspaper or magazine?\n";
                return "Are you interested in determining the final content of a text, particularly a newspaper or magazine?\n";
            }


            return "UH-OH Doesn't seem like you chose the right profession! :(\nPlease restart the Application!\n";
        }
        if (Major == "GEOGRAPHY")
        {
            
            if (fvar_list.getVarProperty("Are you interested in developing international influence or help start operating on an international scale?  \n") == "")
            {
                done = true;
                var = "Are you interested in developing international influence or help start operating on an international scale?  \n";
                return "Are you interested in developing international influence or help start operating on an international scale?  \n";
            }
            
            if (fvar_list.getVarProperty("Are you interested in helping to increase the plant species and the ground cover they provide?  \n") == "")
            {
                done = true;
                var = "Are you interested in helping to increase the plant species and the ground cover they provide?  \n";
                return "Are you interested in helping to increase the plant species and the ground cover they provide?  \n";
            }
            
            if (fvar_list.getVarProperty("Are you interested in the management and the biology of domestic animals? \n") == "")
            {
                done = true;
                var = "Are you interested in the management and the biology of domestic animals? \n";
                return "Are you interested in the management and the biology of domestic animals? \n";
            }

            if (fvar_list.getVarProperty("Would you like to know more about the scientific study of climate, scientifically defined as weather conditions averaged over a period of time?  \n") == "")
            {
                done = true;
                var = "Would you like to know more about the scientific study of climate, scientifically defined as weather conditions averaged over a period of time?  \n";
                return "Would you like to know more about the scientific study of climate, scientifically defined as weather conditions averaged over a period of time?  \n";
            }
            
            if (fvar_list.getVarProperty("Would you like to work with towns to make them more effecient and environmentally friendly?  \n") == "")
            {
                done = true;
                var = "Would you like to work with towns to make them more effecient and environmentally friendly?  \n";
                return "Would you like to work with towns to make them more effecient and environmentally friendly?  \n";
            }


            return "UH-OH Doesn't seem like you chose the right profession! :(\nPlease restart the Application!\n";
        }
        if (Major == "Psychology")
        {
            
            if (fvar_list.getVarProperty("Would you like to help families and marriages work through their problems?  \n") == "")
            {
                done = true;
                var = "Would you like to help families and marriages work through their problems?  \n";
                return "Would you like to help families and marriages work through their problems?  \n";
            }
            if (fvar_list.getVarProperty("Are you interested in providing hands-on direct care to developmentally or emotionally disabled people, as well as those diagnosed with mental illnesses? \n") == "")
            {
                done = true;
                var = "Are you interested in providing hands-on direct care to developmentally or emotionally disabled people, as well as those diagnosed with mental illnesses? \n";
                return "Are you interested in providing hands-on direct care to developmentally or emotionally disabled people, as well as those diagnosed with mental illnesses? \n";
            }

            if (fvar_list.getVarProperty("Would you like to help people who have uncontrolled use of alcohol, illegal drugs or prescribed drugs that affect normal daily life? \n") == "")
            {
                done = true;
                var = "Would you like to help people who have uncontrolled use of alcohol, illegal drugs or prescribed drugs that affect normal daily life? \n";
                return "Would you like to help people who have uncontrolled use of alcohol, illegal drugs or prescribed drugs that affect normal daily life? \n";
            }

            if (fvar_list.getVarProperty("Would you like to apply experimental methods to psychological study and the processes that underlie it?  \n") == "")
            {
                done = true;
                var = "Would you like to apply experimental methods to psychological study and the processes that underlie it?  \n";
                return "Would you like to apply experimental methods to psychological study and the processes that underlie it?  \n";
            }
            if (fvar_list.getVarProperty("Are you interested in taking a strategic approach to the effective management of people in a company or organization such that they help their business gain a competitive advantage?  \n") == "")
            {
                done = true;
                var = "Are you interested in taking a strategic approach to the effective management of people in a company or organization such that they help their business gain a competitive advantage?  \n";
                return "Are you interested in taking a strategic approach to the effective management of people in a company or organization such that they help their business gain a competitive advantage?  \n";
            }


            return "UH-OH Doesn't seem like you chose the right profession! :(\nPlease restart the Application!\n";
        }
        if (Major == "AGRICULTURE")
        {
            
            if (fvar_list.getVarProperty("Are you interested in inspecting food and animals meant for consumption? \n") == "")
            {
                done = true;
                var = "Are you interested in inspecting food and animals meant for consumption? \n";
                return "Are you interested in inspecting food and animals meant for consumption? \n";
            }

            if (fvar_list.getVarProperty("Would you like to be an expert in garden cultivation and management? \n") == "")
            {
                done = true;
                var = "Would you like to be an expert in garden cultivation and management? \n";
                return "Would you like to be an expert in garden cultivation and management? \n";
            }

            if (fvar_list.getVarProperty("Are you interested in the cultivation, management, and study of individual trees, shrubs, vines, and other perennial woody plants in dendrology and horticulture? \n") == "")
            {
                done = true;
                var = "Are you interested in the cultivation, management, and study of individual trees, shrubs, vines, and other perennial woody plants in dendrology and horticulture? \n";
                return "Are you interested in the cultivation, management, and study of individual trees, shrubs, vines, and other perennial woody plants in dendrology and horticulture? \n";
            }

            if (fvar_list.getVarProperty("Would you like to own and breed bees, especially for their honey? \n") == "")
            {
                done = true;
                var = "Would you like to own and breed bees, especially for their honey? \n";
                return "Would you like to own and breed bees, especially for their honey? \n";
            }

            if (fvar_list.getVarProperty("Would you like to specifically deal with crimes against animals?  \n") == "")
            {
                done = true;
                var = "Would you like to specifically deal with crimes against animals?  \n";
                return "Would you like to specifically deal with crimes against animals?  \n";
            }


            return "UH-OH Doesn't seem like you chose the right profession! :(\nPlease restart the Application!\n";
        }
        if (Major == "HEALTHCARE")
        {
            
            if (fvar_list.getVarProperty("Are you interested in the care of individuals, families, and communities so they may attain, maintain, or recover optimal health and quality of life?\n") == "")
            {
                done = true;
                var = "Are you interested in the care of individuals, families, and communities so they may attain, maintain, or recover optimal health and quality of life?\n";
                return "Are you interested in the care of individuals, families, and communities so they may attain, maintain, or recover optimal health and quality of life?\n";
            }
            
            if (fvar_list.getVarProperty("Would you like to plan, direct, and coordinate medical and health services? \n") == "")
            {
                done = true;
                var = "Would you like to plan, direct, and coordinate medical and health services? \n";
                return "Would you like to plan, direct, and coordinate medical and health services? \n";
            }

            if (fvar_list.getVarProperty("Would you like to specialize in dentistry, the diagnosis, prevention, and treatment of diseases and conditions of the oral cavity?  \n") == "")
            {
                done = true;
                var = "Would you like to specialize in dentistry, the diagnosis, prevention, and treatment of diseases and conditions of the oral cavity?  \n";
                return "Would you like to specialize in dentistry, the diagnosis, prevention, and treatment of diseases and conditions of the oral cavity?  \n";
            }

            if (fvar_list.getVarProperty("Are you interested in being a health care practitioner who practices medicine in collaboration with or under the supervision of a physician? \n") == "")
            {
                done = true;
                var = "Are you interested in being a health care practitioner who practices medicine in collaboration with or under the supervision of a physician? \n";
                return "Are you interested in being a health care practitioner who practices medicine in collaboration with or under the supervision of a physician? \n";
            }

            if (fvar_list.getVarProperty("Are you interested in the science and art of preventing disease? \n") == "")
            {
                done = true;
                var = "Are you interested in the science and art of preventing disease? \n";
                return "Are you interested in the science and art of preventing disease? \n";
            }


            return "UH-OH Doesn't seem like you chose the right profession! :(\nPlease restart the Application!\n";
        }
        if (Major == "EDUCATION")
        {
            
            if (fvar_list.getVarProperty("Would you like to teach children in pre K to 5th grade?  \n") == "")
            {
                done = true;
                var = "Would you like to teach children in pre K to 5th grade?  \n";
                return "Would you like to teach children in pre K to 5th grade?  \n";
            }
            
            if (fvar_list.getVarProperty("Would you like to teach at the college or university level?  \n") == "")
            {
                done = true;
                var = "Would you like to teach at the college or university level?  \n";
                return "Would you like to teach at the college or university level?  \n";
            }
            
            if (fvar_list.getVarProperty("Are you interested in being involved in managing some educational system? \n") == "")
            {
                done = true;
                var = "Are you interested in being involved in managing some educational system? \n";
                return "Are you interested in being involved in managing some educational system? \n";
            }
            
            if (fvar_list.getVarProperty("Are you interested in deciding what methods and topics will be used to teach lessons? \n") == "")
            {
                done = true;
                var = "Are you interested in deciding what methods and topics will be used to teach lessons? \n";
                return "Are you interested in deciding what methods and topics will be used to teach lessons? \n";
            }

            if (fvar_list.getVarProperty("Would you like to  instruct non-English speaking individuals on the fundamentals of the English language so that they can communicate with others? \n") == "")
            {
                done = true;
                var = "Would you like to  instruct non-English speaking individuals on the fundamentals of the English language so that they can communicate with others? \n";
                return "Would you like to  instruct non-English speaking individuals on the fundamentals of the English language so that they can communicate with others? \n";
            }


            return "UH-OH Doesn't seem like you chose the right profession! :(\n Please restart the Application!\n";
        }
        return "You answered No to all the questions! Maybe college isnt for you!\nPlease restart the Application if you reconsider!\n";
}
