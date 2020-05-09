#include "fCheckInstantiate.h"
#include <iostream>
#include <string>

using namespace std;

fCheckInstantiate::fCheckInstantiate()
{

}

string fCheckInstantiate::setQuestions(string& Major, VariableList fvar_list, bool done)
{
    int x = 1;
    do {

      //  cout << "Which profession did you get advised to go into? (Ex: Engineering)" << endl;
      //  cin >> Major;


        if (Major == "ENGINEERING")
        {
            if (fvar_list.getVarProperty("Would you like to design and develop electrical equipment? (YES or NO)") == "YES") 
            { x = 0; done = true; break;}
            if (fvar_list.getVarProperty("Would you like to design and develop electrical equipment? (YES or NO)") == "")
                return "Would you like to design and develop electrical equipment? (YES or NO)";
           // cin >> Electrical;
           // if (Electrical == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Would you like to design, analyze, manufacture, and maintain mechanical systems? (YES or NO)") == "YES") 
            { x = 0; done = true; break; }
            if (fvar_list.getVarProperty("Would you like to design, analyze, manufacture, and maintain mechanical systems? (YES or NO)") == "")
                return "Would you like to design, analyze, manufacture, and maintain mechanical systems? (YES or NO)";
            //cin >> Mechanical;
           // if (Mechanical == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Would you like to design, construct, and maintain the physical and naturally built environment? (YES or NO)") == "YES") 
            { x = 0; done = true; break; }
            if (fvar_list.getVarProperty("Would you like to design, construct, and maintain the physical and naturally built environment? (YES or NO)") == "")
                return "Would you like to design, construct, and maintain the physical and naturally built environment? (YES or NO)";
            //cin >> PNEnvironment;
           // if (PNEnvironment == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Would you like to design and develop methods for extracting oil and gas from deposits below the Earth’s surface? (YES or NO)") == "YES") 
            { x = 0; done = true; break; }
            if (fvar_list.getVarProperty("Would you like to design and develop methods for extracting oil and gas from deposits below the Earth’s surface? (YES or NO)") == "")
                return "Would you like to design and develop methods for extracting oil and gas from deposits below the Earth’s surface? (YES or NO)";
           // cin >> OilGas;
           // if (OilGas == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Are you interested in efficiently using, producing, designing, transporting and transforming energy and materials? (YES or NO)") == "YES") 
            { x = 0; done = true; break; }
            if (fvar_list.getVarProperty("Are you interested in efficiently using, producing, designing, transporting and transforming energy and materials? (YES or NO)") == "")
                return "Are you interested in efficiently using, producing, designing, transporting and transforming energy and materials? (YES or NO)";
           // cin >> ChemEnergy;
            //if (ChemEnergy == "YES") { x = 0; break; }

            return "UH-OH Doesn't seem like you chose the right profession! :(";
        }
        if (Major == "SCIENCE")
        {
            if (fvar_list.getVarProperty("Would you like to learn more about the composition of matter and its properties? (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Would you like to learn more about the composition of matter and its properties? (YES or NO)") == "")
                return "Would you like to learn more about the composition of matter and its properties? (YES or NO)";
           // cin >> ChemMatter;
           // if (ChemMatter == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Would you like to know more about study DNA, proteins and cell parts? (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Would you like to know more about study DNA, proteins and cell parts? (YES or NO)") == "")
            return "Would you like to know more about study DNA, proteins and cell parts? (YES or NO)";
           // cin >> Dna;
           // if (Dna == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Are you interested in the branch of science concerning living organisms? (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Are you interested in the branch of science concerning living organisms? (YES or NO)") == "")
            return "Are you interested in the branch of science concerning living organisms? (YES or NO)";
            //cin >> LivOrganism;
            //if (LivOrganism == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Does marine life and organisms in the sea interest you? (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Does marine life and organisms in the sea interest you? (YES or NO)") == "")
            return "Does marine life and organisms in the sea interest you? (YES or NO)";
            //cin >> MarLife;
            //if (MarLife == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Would you like to observe astronomical objects such as stars, planets, moons, comets and galaxies? (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Would you like to observe astronomical objects such as stars, planets, moons, comets and galaxies? (YES or NO)") == "")
            return "Would you like to observe astronomical objects such as stars, planets, moons, comets and galaxies? (YES or NO)";
            //cin >> Star;
            //if (Star == "YES") { x = 0; break; }

            return "UH-OH Doesn't seem like you chose the right profession! :(";
        }
        if (Major == "BUSINESS")
        {
            if (fvar_list.getVarProperty("Are you interested in the study and management of exchange relationships? (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Are you interested in the study and management of exchange relationships? (YES or NO)") == "")
            return "Are you interested in the study and management of exchange relationships? (YES or NO)";
            //cin >> Exchange;
            //if (Exchange == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Would you like to know more about the study of money and how it is used?  (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Would you like to know more about the study of money and how it is used?  (YES or NO)") == "")
            return "Would you like to know more about the study of money and how it is used?  (YES or NO)";
            //cin >> Money;
            //if (Money == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Are you interested in recognizing and developing opportunities?   (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Are you interested in recognizing and developing opportunities?   (YES or NO)") == "")
            return "Are you interested in recognizing and developing opportunities?   (YES or NO)";
            //cin >> Opportunities;
            //if (Opportunities == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Would you like to oversee and supervise business operations?   (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Would you like to oversee and supervise business operations?   (YES or NO)") == "")
            return "Would you like to oversee and supervise business operations?   (YES or NO)";
           // cin >> Manage;
           // if (Manage == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Are you interested in the quantitative methods to analyze business enterprises and the factors contributing to the diversity of organizational structures and the relationships of firms with labour, capital and product markets?  (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Are you interested in the quantitative methods to analyze business enterprises and the factors contributing to the diversity of organizational structures and the relationships of firms with labour, capital and product markets?  (YES or NO)") == "")
            return "Are you interested in the quantitative methods to analyze business enterprises and the factors contributing to the diversity of organizational structures and the relationships of firms with labour, capital and product markets?  (YES or NO)";
            //cin >> Econ;
            //if (Econ == "YES") { x = 0; break; }


            return "UH-OH Doesn't seem like you chose the right profession! :(";
        }
        if (Major == "ART")
        {
            if (fvar_list.getVarProperty("Do photographs interest you? (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Do photographs interest you? (YES or NO)") == "")
            return "Do photographs interest you? (YES or NO)";
           // cin >> Photo;
           // if (Photo == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Are you interested in using aesthetic and rhythmic qualities of language—such as phonaesthetics, sound symbolism, and metre—to evoke meanings in addition to, or in place of, the prosaic ostensible meaning?(YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Are you interested in using aesthetic and rhythmic qualities of language—such as phonaesthetics, sound symbolism, and metre—to evoke meanings in addition to, or in place of, the prosaic ostensible meaning?(YES or NO)") == "")
            return "Are you interested in using aesthetic and rhythmic qualities of language—such as phonaesthetics, sound symbolism, and metre—to evoke meanings in addition to, or in place of, the prosaic ostensible meaning?(YES or NO)";
            //cin >> Poetry;
            //if (Poetry == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Are you interested in capturing live moments through film?  (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Are you interested in capturing live moments through film?  (YES or NO)") == "")
            return "Are you interested in capturing live moments through film?  (YES or NO)";
            //cin >> Film;
            //if (Film == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Do you like to express yourself through dance?  (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Do you like to express yourself through dance?  (YES or NO)") == "")
            return "Do you like to express yourself through dance?  (YES or NO)";
            //cin >> Dance;
            //if (Dance == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Do you like to entertain the masses by acting?  (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Do you like to entertain the masses by acting?  (YES or NO)") == "")
            return "Do you like to entertain the masses by acting?  (YES or NO)";
            //cin >> Acting;
            //if (Acting == "YES") { x = 0; break; }


            return "UH-OH Doesn't seem like you chose the right profession! :(";
        }
        if (Major == "ENGLISH")
        {
            if (fvar_list.getVarProperty("Would you like to write for newspapers, magazines, or news websites or prepare news to be broadcasted?  (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Would you like to write for newspapers, magazines, or news websites or prepare news to be broadcasted?  (YES or NO)") == "")
            return "Would you like to write for newspapers, magazines, or news websites or prepare news to be broadcasted?  (YES or NO)";
            //cin >> News;
            //if (News == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Are you interested in transferring information between two or more parties? (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Are you interested in transferring information between two or more parties? (YES or NO)") == "")
            return "Are you interested in transferring information between two or more parties? (YES or NO)";
            //cin >> Info;
            //if (Info == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Would you like to promote groups, or organizations by selecting publicity material and releasing it through various communications media?(YES or NO)") == "")
            return "Would you like to promote groups, or organizations by selecting publicity material and releasing it through various communications media?(YES or NO)";
            //cin >> Promote;
            //if (Promote == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Are you interested in helping an employer find job candidates who are most qualified to meet the organization's needs?  (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Are you interested in helping an employer find job candidates who are most qualified to meet the organization's needs?  (YES or NO)") == "")
            return "Are you interested in helping an employer find job candidates who are most qualified to meet the organization's needs?  (YES or NO)";
            //cin >> Employer;
            //if (Employer == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Are you interested in determining the final content of a text, particularly a newspaper or magazine?(YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Are you interested in determining the final content of a text, particularly a newspaper or magazine?(YES or NO)") == "")
            return "Are you interested in determining the final content of a text, particularly a newspaper or magazine?(YES or NO)";
            //cin >> Edit;
            //if (Edit == "YES") { x = 0; break; }


            return "UH-OH Doesn't seem like you chose the right profession! :(";
        }
        if (Major == "GEOGRAPHY")
        {
            if (fvar_list.getVarProperty("Are you interested in developing international influence or help start operating on an international scale?  (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Are you interested in developing international influence or help start operating on an international scale?  (YES or NO)") == "")
            return "Are you interested in developing international influence or help start operating on an international scale?  (YES or NO)";
            //cin >> International;
            //if (International == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Are you interested in helping to increase the plant species and the ground cover they provide?  (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Are you interested in helping to increase the plant species and the ground cover they provide?  (YES or NO)") == "")
            return "Are you interested in helping to increase the plant species and the ground cover they provide?  (YES or NO)";
            //cin >> Plant;
            //if (Plant == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Are you interested in the management and the biology of domestic animals? (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Are you interested in the management and the biology of domestic animals? (YES or NO)") == "")
            return "Are you interested in the management and the biology of domestic animals? (YES or NO)";
            //cin >> Domestic;
            //if (Domestic == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Would you like to know more about the scientific study of climate, scientifically defined as weather conditions averaged over a period of time?  (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Would you like to know more about the scientific study of climate, scientifically defined as weather conditions averaged over a period of time?  (YES or NO)") == "")
            return "Would you like to know more about the scientific study of climate, scientifically defined as weather conditions averaged over a period of time?  (YES or NO)";
            //cin >> Climate;
            //if (Climate == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Are you interested in detailed descriptions of people’s lives?  (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Are you interested in detailed descriptions of people’s lives?  (YES or NO)") == "")
            return "Are you interested in detailed descriptions of people’s lives?  (YES or NO)";
            //cin >> People;
            //if (People == "YES") { x = 0; break; }


            return "UH-OH Doesn't seem like you chose the right profession! :(";
        }
        if (Major == "Psychology")
        {
            if (fvar_list.getVarProperty("Would you like to help families and marriages work through their problems?  (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Would you like to help families and marriages work through their problems?  (YES or NO)") == "")
            return "Would you like to help families and marriages work through their problems?  (YES or NO)";
            //cin >> FamMar;
            //if (FamMar == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Are you interested in providing hands-on direct care to developmentally or emotionally disabled people, as well as those diagnosed with mental illnesses? (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Are you interested in providing hands-on direct care to developmentally or emotionally disabled people, as well as those diagnosed with mental illnesses? (YES or NO)") == "")
            return "Are you interested in providing hands-on direct care to developmentally or emotionally disabled people, as well as those diagnosed with mental illnesses? (YES or NO)";
            //cin >> Mental;
            //if (Mental == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Would you like to help people who have uncontrolled use of alcohol, illegal drugs or prescribed drugs that affect normal daily life? (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Would you like to help people who have uncontrolled use of alcohol, illegal drugs or prescribed drugs that affect normal daily life? (YES or NO)") == "")
            return "Would you like to help people who have uncontrolled use of alcohol, illegal drugs or prescribed drugs that affect normal daily life? (YES or NO)";
            //cin >> Substance;
            //if (Substance == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Would you like to apply experimental methods to psychological study and the processes that underlie it?  (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Would you like to apply experimental methods to psychological study and the processes that underlie it?  (YES or NO)") == "")
            return "Would you like to apply experimental methods to psychological study and the processes that underlie it?  (YES or NO)";
            //cin >> Experiment;
            //if (Experiment == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Are you interested in taking a strategic approach to the effective management of people in a company or organization such that they help their business gain a competitive advantage?  (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Are you interested in taking a strategic approach to the effective management of people in a company or organization such that they help their business gain a competitive advantage?  (YES or NO)") == "")
            return "Are you interested in taking a strategic approach to the effective management of people in a company or organization such that they help their business gain a competitive advantage?  (YES or NO)";
            //cin >> HR;
            //if (HR == "YES") { x = 0; break; }


            return "UH-OH Doesn't seem like you chose the right profession! :(";
        }
        if (Major == "AGRICULTURE")
        {
            if (fvar_list.getVarProperty("Are you interested in inspecting food and animals meant for consumption? (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Are you interested in inspecting food and animals meant for consumption? (YES or NO)") == "")
            return "Are you interested in inspecting food and animals meant for consumption? (YES or NO)";
            //cin >> Inspecting;
            //if (Inspecting == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Would you like to be an expert in garden cultivation and management? (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Would you like to be an expert in garden cultivation and management? (YES or NO)") == "")
            return "Would you like to be an expert in garden cultivation and management? (YES or NO)";
            //cin >> Garden;
            //if (Garden == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Are you interested in the cultivation, management, and study of individual trees, shrubs, vines, and other perennial woody plants in dendrology and horticulture? (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Are you interested in the cultivation, management, and study of individual trees, shrubs, vines, and other perennial woody plants in dendrology and horticulture? (YES or NO)") == "")
            return "Are you interested in the cultivation, management, and study of individual trees, shrubs, vines, and other perennial woody plants in dendrology and horticulture? (YES or NO)";
            //cin >> Trees;
            //if (Trees == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Would you like to own and breed bees, especially for their honey? (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Would you like to own and breed bees, especially for their honey? (YES or NO)") == "")
            return "Would you like to own and breed bees, especially for their honey? (YES or NO)";
            //cin >> Bees;
            //if (Bees == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Would you like to specifically deal with crimes against animals?  (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Would you like to specifically deal with crimes against animals?  (YES or NO)") == "")
            return "Would you like to specifically deal with crimes against animals?  (YES or NO)";
            //cin >> WildLife;
            //if (WildLife == "YES") { x = 0; break; }


            return "UH-OH Doesn't seem like you chose the right profession! :(";
        }
        if (Major == "HEALTHCARE")
        {
            if (fvar_list.getVarProperty("Are you interested in the care of individuals, families, and communities so they may attain, maintain, or recover optimal health and quality of life?(YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Are you interested in the care of individuals, families, and communities so they may attain, maintain, or recover optimal health and quality of life?(YES or NO)") == "")
            return "Are you interested in the care of individuals, families, and communities so they may attain, maintain, or recover optimal health and quality of life?(YES or NO)";
            //cin >> Care;
            //if (Care == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Would you like to plan, direct, and coordinate medical and health services? (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Would you like to plan, direct, and coordinate medical and health services? (YES or NO)") == "")
            return "Would you like to plan, direct, and coordinate medical and health services? (YES or NO)";
            //cin >> Plan;
            //if (Plan == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Would you like to specialize in dentistry, the diagnosis, prevention, and treatment of diseases and conditions of the oral cavity?  (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Would you like to specialize in dentistry, the diagnosis, prevention, and treatment of diseases and conditions of the oral cavity?  (YES or NO)") == "")
            return "Would you like to specialize in dentistry, the diagnosis, prevention, and treatment of diseases and conditions of the oral cavity?  (YES or NO)";
            //cin >> Teeth;
            //if (Teeth == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Are you interested in being a health care practitioner who practices medicine in collaboration with or under the supervision of a physician? (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Are you interested in being a health care practitioner who practices medicine in collaboration with or under the supervision of a physician? (YES or NO)") == "")
            return "Are you interested in being a health care practitioner who practices medicine in collaboration with or under the supervision of a physician? (YES or NO)";
            //cin >> Assistant;
            //if (Assistant == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Are you interested in the science and art of preventing disease? (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Are you interested in the science and art of preventing disease? (YES or NO)") == "")
            return "Are you interested in the science and art of preventing disease? (YES or NO)";
            //cin >> Disease;
            //if (Disease == "YES") { x = 0; break; }


            return "UH-OH Doesn't seem like you chose the right profession! :(";
        }
        if (Major == "EDUCATION")
        {
            if (fvar_list.getVarProperty("Would you like to teach children in pre K to 5th grade?  (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Would you like to teach children in pre K to 5th grade?  (YES or NO)") == "")
            return "Would you like to teach children in pre K to 5th grade?  (YES or NO)";
            //cin >> Elementary;
            //if (Elementary == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Would you like to teach at the college or university level?  (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Would you like to teach at the college or university level?  (YES or NO)") == "")
            return "Would you like to teach at the college or university level?  (YES or NO)";
            //cin >> College;
            //if (College == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Are you interested in being involved in managing some educational system? (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Are you interested in being involved in managing some educational system? (YES or NO)") == "")
            return "Are you interested in being involved in managing some educational system? (YES or NO)";
            //cin >> Education;
            //if (Education == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Are you interested in deciding what methods and topics will be used to teach lessons? (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Are you interested in deciding what methods and topics will be used to teach lessons? (YES or NO)") == "")
            return "Are you interested in deciding what methods and topics will be used to teach lessons? (YES or NO)";
            //cin >> Curriculum;
            //if (Curriculum == "YES") { x = 0; break; }
            if (fvar_list.getVarProperty("Would you like to  instruct non-English speaking individuals on the fundamentals of the English language so that they can communicate with others? (YES or NO)") == "YES")
            {
                x = 0; done = true; break;
            }
            if (fvar_list.getVarProperty("Would you like to  instruct non-English speaking individuals on the fundamentals of the English language so that they can communicate with others? (YES or NO)") == "")
            return "Would you like to  instruct non-English speaking individuals on the fundamentals of the English language so that they can communicate with others? (YES or NO)";
            //cin >> Language;
            //if (Language == "YES") { x = 0; break; }



            return "UH-OH Doesn't seem like you chose the right profession! :(";
        }
        return "\nWRONG INPUT: Check spelling and remember first letter of every word has to be uppercase!";
    } while (x == 1);

}

fCheckInstantiate::~fCheckInstantiate()
{

}