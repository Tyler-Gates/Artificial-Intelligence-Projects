#include "cApp.h"
#include "Engine.h"


wxIMPLEMENT_APP(cApp);

cApp::cApp() {

}

cApp::~cApp() {
	
}


/*OnInit is the initialization of the GUI app, this is where everything beings.*/
bool cApp::OnInit() {
	//variable_list
	std::map<std::string, std::string> variable_list;
	variable_list.insert({ std::string("Do you like to plan/organize/manage things?\n"), std::string("") });
	variable_list.insert({ std::string("Do you like to help?\n"), std::string("") });
	variable_list.insert({ std::string("Do you enjoy teaching?\n"), std::string("") });
	variable_list.insert({ std::string("Are you interested in the inner workings of the mind?\n"), std::string("") });
	variable_list.insert({ std::string("Do you want to improve peoples lives?\n"), std::string("") });
	variable_list.insert({ std::string("Would you like to further your understanding of the earth's physical features?\n"), std::string("") });
	variable_list.insert({ std::string("Does raising plants/animals interest you?\n"), std::string("") });
	variable_list.insert({ std::string("Would you like to build things?\n"), std::string("") });
	variable_list.insert({ std::string("Are you interested in how the world works?\n"), std::string("") });
	variable_list.insert({ std::string("Do you like to read/write\n"), std::string("") });
	variable_list.insert({ std::string("Do you appreciate art?\n"), std::string("") });
	variable_list.insert({ std::string("Do you like nature?\n"), std::string("") });
	variable_list.insert({ std::string("Do you enjoy being creative?\n"), std::string("") });
	variable_list.insert({ std::string("Are you good at math?\n"), std::string("") });

	//conclusion_list
	std::map<std::string, std::string> conclusion_list;
	conclusion_list.insert({ std::string("MAJOR"), std::string("") });
	conclusion_list.insert({ std::string("NATURIST"), std::string("") });
	conclusion_list.insert({ std::string("HELPER"), std::string("") });
	conclusion_list.insert({ std::string("STEM"), std::string("") });
	conclusion_list.insert({ std::string("CREATOR"), std::string("") });

	//knowledge_base
	std::map<int, std::string> knowledge_base;
	knowledge_base.insert({ 10, std::string("BUSINESS") });
	knowledge_base.insert({ 20, std::string("YES") });
	knowledge_base.insert({ 30, std::string("EDUCATION") });
	knowledge_base.insert({ 40, std::string("PSYCHOLOGY") });
	knowledge_base.insert({ 50, std::string("HEALTHCARE") });
	knowledge_base.insert({ 60, std::string("YES") });
	knowledge_base.insert({ 70, std::string("AGRICULTURE") });
	knowledge_base.insert({ 80, std::string("GEOGRAPHY") });
	knowledge_base.insert({ 90, std::string("YES") });
	knowledge_base.insert({ 100, std::string("ENGINEERING") });
	knowledge_base.insert({ 110, std::string("SCIENCE") });
	knowledge_base.insert({ 120, std::string("YES") });
	knowledge_base.insert({ 130, std::string("ENGLISH") });
	knowledge_base.insert({ 140, std::string("ART") });

	//major_queue
	std::queue<int> major_queue;
	major_queue.push(10);
	major_queue.push(30);
	major_queue.push(40);
	major_queue.push(50);
	major_queue.push(70);
	major_queue.push(80);
	major_queue.push(100);
	major_queue.push(110);
	major_queue.push(130);
	major_queue.push(140);

	std::queue<int> naturist_queue;
	naturist_queue.push(60);

	std::queue<int> helper_queue;
	helper_queue.push(20);

	std::queue<int> stem_queue;
	stem_queue.push(90);

	std::queue<int> creator_queue;
	creator_queue.push(120);

	//conclusion list
	std::map<std::string, std::queue<int> > con_ls;
	con_ls.insert({ std::string("MAJOR"),major_queue });
	con_ls.insert({ std::string("NATURIST"),naturist_queue });
	con_ls.insert({ std::string("HELPER"),helper_queue });
	con_ls.insert({ std::string("STEM"),stem_queue });
	con_ls.insert({ std::string("CREATOR"),creator_queue });


	//clause_variable_list
	std::vector<std::string> clause_variable_list;
	for (int i = 0; i < 196; i++) {
		clause_variable_list.push_back(std::string(""));
	}
	clause_variable_list[0] = "Do you like to plan/organize/manage things?\n";
	clause_variable_list[14] = "Do you like to plan/organize/manage things?\n";
	clause_variable_list[15] = "Do you like to help?\n";
	clause_variable_list[28] = "HELPER";
	clause_variable_list[29] = "Do you enjoy teaching?\n";
	clause_variable_list[42] = "HELPER";
	clause_variable_list[43] = "Are you interested in the inner workings of the mind?\n";
	clause_variable_list[56] = "HELPER";
	clause_variable_list[57] = "Do you want to improve peoples lives?\n";
	clause_variable_list[70] = "Do you like to plan/organize/manage things?\n";
	clause_variable_list[71] = "Do you like nature?\n";
	clause_variable_list[84] = "NATURIST";
	clause_variable_list[85] = "Does raising plants/animals interest you?\n";
	clause_variable_list[98] = "NATURIST";
	clause_variable_list[99] = "Would you like to further your understanding of the earth's physical features?\n";
	clause_variable_list[112] = "Do you like to plan/organize/manage things?\n";
	clause_variable_list[113] = "Are you good at math?\n";
	clause_variable_list[126] = "STEM";
	clause_variable_list[127] = "Would you like to build things?\n";
	clause_variable_list[140] = "STEM";
	clause_variable_list[141] = "Are you interested in how the world works?\n";
	clause_variable_list[154] = "Do you like to plan/organize/manage things?\n";
	clause_variable_list[155] = "Do you enjoy being creative?\n";
	clause_variable_list[168] = "CREATOR";
	clause_variable_list[169] = "Do you like to read/write\n";
	clause_variable_list[182] = "CREATOR";
	clause_variable_list[183] = "Do you appreciate art?\n";

	//clause_conditions_list
	std::vector<std::string> clause_conditions_list;
	for (int i = 0; i < 196; i++) {
		clause_conditions_list.push_back(std::string(""));
	}
	clause_conditions_list[0] = "YES";
	clause_conditions_list[14] = "NO";
	clause_conditions_list[15] = "YES";
	clause_conditions_list[28] = "YES";
	clause_conditions_list[29] = "YES";
	clause_conditions_list[42] = "YES";
	clause_conditions_list[43] = "YES";
	clause_conditions_list[56] = "YES";
	clause_conditions_list[57] = "YES";
	clause_conditions_list[70] = "NO";
	clause_conditions_list[71] = "YES";
	clause_conditions_list[84] = "YES";
	clause_conditions_list[85] = "YES";
	clause_conditions_list[98] = "YES";
	clause_conditions_list[99] = "YES";
	clause_conditions_list[112] = "NO";
	clause_conditions_list[113] = "YES";
	clause_conditions_list[126] = "YES";
	clause_conditions_list[127] = "YES";
	clause_conditions_list[140] = "YES";
	clause_conditions_list[141] = "YES";
	clause_conditions_list[154] = "NO";
	clause_conditions_list[155] = "YES";
	clause_conditions_list[168] = "YES";
	clause_conditions_list[169] = "YES";
	clause_conditions_list[182] = "YES";
	clause_conditions_list[183] = "YES";

	//variable list for forward chaining
	std::map<std::string, std::string> fvar_list;
	fvar_list.insert({ std::string("Would you like to design and develop electrical equipment? \n"), std::string("") });
	fvar_list.insert({ std::string("Would you like to design, analyze, manufacture, and maintain mechanical systems? \n"), std::string("") });
	fvar_list.insert({ std::string("Would you like to design, construct, and maintain the physical and naturally built environment? \n"), std::string("") });
	fvar_list.insert({ std::string("Would you like to design and develop methods for extracting oil and gas from deposits below the Earth’s surface? \n"), std::string("") });
	fvar_list.insert({ std::string("Are you interested in efficiently using, producing, designing, transporting and transforming energy and materials? \n"), std::string("") });
	fvar_list.insert({ std::string("Would you like to learn more about the composition of matter and its properties? \n"), std::string("") });
	fvar_list.insert({ std::string("Are you interested in the branch of science concerning living organisms? \n"), std::string("") });
	fvar_list.insert({ std::string("Does marine life and organisms in the sea interest you? \n"), std::string("") });
	fvar_list.insert({ std::string("Would you like to observe astronomical objects such as stars, planets, moons, comets and galaxies? \n"), std::string("") });
	fvar_list.insert({ std::string("Are you interested in the study and management of exchange relationships? \n"), std::string("") });
	fvar_list.insert({ std::string("Would you like to know more about the study of money and how it is used?  \n"), std::string("") });
	fvar_list.insert({ std::string("Are you interested in recognizing and developing opportunities?   \n"), std::string("") });
	fvar_list.insert({ std::string("Would you like to oversee and supervise business operations?   \n"), std::string("") });
	fvar_list.insert({ std::string("Are you interested in the quantitative methods to analyze business enterprises and the factors contributing to the diversity of organizational structures and the relationships of firms with labour, capital and product markets?  \n"), std::string("") });
	fvar_list.insert({ std::string("Do photographs interest you? \n"), std::string("") });
	fvar_list.insert({ std::string("Are you interested in using aesthetic and rhythmic qualities of language—such as phonaesthetics, sound symbolism, and metre—to evoke meanings in addition to, or in place of, the prosaic ostensible meaning?\n"), std::string("") });
	fvar_list.insert({ std::string("Are you interested in capturing live moments through film?  \n"), std::string("") });
	fvar_list.insert({ std::string("Do you like to express yourself through dance?  \n"), std::string("") });
	fvar_list.insert({ std::string("Do you like to entertain the masses by acting?  \n"), std::string("") });
	fvar_list.insert({ std::string("Would you like to write for newspapers, magazines, or news websites or prepare news to be broadcasted?  \n"), std::string("") });
	fvar_list.insert({ std::string("Are you interested in transferring information between two or more parties? \n"), std::string("") });
	fvar_list.insert({ std::string("Would you like to promote groups, or organizations by selecting publicity material and releasing it through various communications media?\n"), std::string("") });
	fvar_list.insert({ std::string("Are you interested in helping an employer find job candidates who are most qualified to meet the organization's needs?  \n"), std::string("") });
	fvar_list.insert({ std::string("Are you interested in determining the final content of a text, particularly a newspaper or magazine?\n"), std::string("") });
	fvar_list.insert({ std::string("Are you interested in developing international influence or help start operating on an international scale?  \n"), std::string("") });
	fvar_list.insert({ std::string("Are you interested in helping to increase the plant species and the ground cover they provide?  \n"), std::string("") });
	fvar_list.insert({ std::string("Are you interested in the management and the biology of domestic animals? \n"), std::string("") });
	fvar_list.insert({ std::string("Would you like to know more about the scientific study of climate, scientifically defined as weather conditions averaged over a period of time?  \n"), std::string("") });
	fvar_list.insert({ std::string("Would you like to work with towns to make them more effecient and environmentally friendly?  \n"), std::string("") });
	fvar_list.insert({ std::string("Would you like to help families and marriages work through their problems?  \n"), std::string("") });
	fvar_list.insert({ std::string("Are you interested in providing hands-on direct care to developmentally or emotionally disabled people, as well as those diagnosed with mental illnesses? \n"), std::string("") });
	fvar_list.insert({ std::string("Would you like to help people who have uncontrolled use of alcohol, illegal drugs or prescribed drugs that affect normal daily life? \n"), std::string("") });
	fvar_list.insert({ std::string("Would you like to apply experimental methods to psychological study and the processes that underlie it?  \n"), std::string("") });
	fvar_list.insert({ std::string("Are you interested in taking a strategic approach to the effective management of people in a company or organization such that they help their business gain a competitive advantage?  \n"), std::string("") });
	fvar_list.insert({ std::string("Are you interested in inspecting food and animals meant for consumption? \n"), std::string("") });
	fvar_list.insert({ std::string("Would you like to be an expert in garden cultivation and management? \n"), std::string("") });
	fvar_list.insert({ std::string("Are you interested in the cultivation, management, and study of individual trees, shrubs, vines, and other perennial woody plants in dendrology and horticulture? \n"), std::string("") });
	fvar_list.insert({ std::string("Would you like to own and breed bees, especially for their honey? \n"), std::string("") });
	fvar_list.insert({ std::string("Would you like to specifically deal with crimes against animals?  \n"), std::string("") });
	fvar_list.insert({ std::string("Are you interested in the care of individuals, families, and communities so they may attain, maintain, or recover optimal health and quality of life?\n"), std::string("") });
	fvar_list.insert({ std::string("Would you like to plan, direct, and coordinate medical and health services? \n"), std::string("") });
	fvar_list.insert({ std::string("Would you like to specialize in dentistry, the diagnosis, prevention, and treatment of diseases and conditions of the oral cavity?  \n"), std::string("") });
	fvar_list.insert({ std::string("Are you interested in being a health care practitioner who practices medicine in collaboration with or under the supervision of a physician? \n"), std::string("") });
	fvar_list.insert({ std::string("Are you interested in the science and art of preventing disease? \n"), std::string("") });
	fvar_list.insert({ std::string("Would you like to teach children in pre K to 5th grade?  \n"), std::string("") });
	fvar_list.insert({ std::string("Would you like to teach at the college or university level?  \n"), std::string("") });
	fvar_list.insert({ std::string("Are you interested in being involved in managing some educational system? \n"), std::string("") });
	fvar_list.insert({ std::string("Are you interested in deciding what methods and topics will be used to teach lessons? \n"), std::string("") });
	fvar_list.insert({ std::string("Would you like to  instruct non-English speaking individuals on the fundamentals of the English language so that they can communicate with others? \n"), std::string("") });

	Engine *vrooom = new Engine(variable_list, conclusion_list, knowledge_base, con_ls,
		clause_variable_list, clause_conditions_list, fvar_list);

	vrooom->backwarddone = false;
	vrooom->done = false;
	vrooom->startp("MAJOR");
	m_frame1 = new cMain(vrooom);
	m_frame1->Show();
	return true;
}