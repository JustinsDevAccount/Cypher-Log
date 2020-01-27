/*
Copyright(C) 2020 Justin Pember
*/
#include "../headers/session.hpp"
Session::Session(std::string sessionName, bool exitOnCreation)
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
	sessionFileConstructor.open(sessionName + "/session.config", std::fstream::out);
	if (sessionFileConstructor.fail()) { std::cout << std::endl << "Error making session.config | Error code: -7"; }

	//TODO: Init variables
	std::string* temp;
	std::string* temp2;
	std::string* sessionIsEncrypted;
	std::string* sessionDefaultMode;

	//Get data from user
	//TODO: Check for invalid characters at each of these inputs
	//ERROR-HERE: THE INPUT WILL ESCAPE HERE BEFORE THE USER INPUTS INFO
	std::cout << std::endl << "Set default mode to basic? (y or n): ";
	std::getline(std::cin, *temp);
	if (temp[0] == "n") { *sessionDefaultMode = "false"; }
	else { *sessionDefaultMode = "true"; }

	//TODO: Fill session.config with more data
	//Initiating session config file with template
	std::string* configTemplate;
	*configTemplate =
		"SessionDetails\n"
		"{\n"
		"\tSessionName = \"" + sessionName + "\";\n"
		"\tSessionEncrypted = " + *sessionIsEncrypted + ";\n"
		"\tSessionDefaultMode = \"" + *sessionDefaultMode + "\";\n"
		"}\n";
	//TODO: SESSION WONT INIT HERE, config wont get created
	sessionFileConstructor << *configTemplate;
	delete(configTemplate);

	//Closing filestream to session.config file
	sessionFileConstructor.close();
	//Making pointers.index file
	sessionFileConstructor.open(sessionName + "/pointers.index");
	if (sessionFileConstructor.fail())
	{
		std::cout << std::endl << "Error making session.config | Error code: -8";
	}
	//Closing file stream to pointers.index file
	sessionFileConstructor.close();

	//TODO: Cleanup pointers and stuff
}
