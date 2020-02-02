/*
Copyright(C) 2020 Justin Pember
*/
#include "../headers/session.hpp"

Session::Session(std::string sessionName, bool getDataFromUser)
{
	//Checking for illegal characters
	for (int i = 0; i < sessionName.size(); i++) {
		if (sessionName[i] == '/' || sessionName[i] == '\\')
		{
			std::cout << std::endl << "Session name cannot contain '/' | Error code: -6";
			return;
		}
	}
	//Making dir; using std::string's built in to const char function
	if (mkdir(sessionName.c_str()) != 0) { std::cout << std::endl << "Error making session directory | Error code: -5; dir may exist already"; }

	//Making configuration files
	std::fstream sessionFileConstructor;
	sessionFileConstructor.open((sessionName + "/session.config"), std::ios::out);
	if (sessionFileConstructor.fail()) { std::cout << std::endl << "Error making session.config | Error code: -7"; }

	//TODO: Init variables
	std::string temp;
	//std::string temp2;
	std::string configTemplate;

	if (getDataFromUser)
	{
		//TODO: Check for invalid characters at each of these inputs
		//Getting default mode
		std::cout << std::endl << "Set default mode to basic? (y or n): ";
		std::getline(std::cin, temp);
		if (temp[0] == 'n') { m_sessionDefaultMode = "false"; }
		else { m_sessionDefaultMode = "true"; }

		temp.clear();

		//Whether to encrypt session; falls back to true if input unreadable
		std::cout << std::endl << "Encrypt whole session? (y or n)";
		std::getline(std::cin, temp);
		if (temp[0] == 'n') { m_sessionEncrypted = "false"; }
		else { m_sessionEncrypted = "true"; }

		temp.clear();
		//TODO: Get rest of data 
	}

	//TODO: Fill session.config with more data
	//Generating template for session.config
	configTemplate =
		"SessionDetails\n"
		"{\n"
		"\tSessionName = \"" + sessionName + "\";\n"
		"\tSessionEncrypted = " + m_sessionIsEncrypted + ";\n"
		"\tSessionDefaultMode = \"" + m_sessionDefaultMode + "\";\n"
		"}\n";

	sessionFileConstructor << configTemplate;
	sessionFileConstructor.close();

	//Making pointers.index file
	sessionFileConstructor.open(sessionName + "/pointers.index");
	if (sessionFileConstructor.fail()) { std::cout << std::endl << "Error making pointers.index | Error code: -8"; }
	sessionFileConstructor.close();

	//TODO: Cleanup pointers and stuff
	//Cleanup

	//TODO: Assign values to session's members
	m_sessionName = sessionName;
}
