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
	if (mkdir(sessionName.c_str()) != 0)
	{
		std::cout << std::endl << "Error making session directory | Error code: -5";
	}

	//Making configuration files
	
	std::fstream* sessionFileConstructor;
	sessionFileConstructor->open(sessionName + "/session.config");
	if (sessionFileConstructor->fail())
	{
		std::cout << std::endl << "Error making session.config | Error code: -7";
	}
	//TODO: Fill session.config with data

	sessionFileConstructor->close();
	//Making pointers.index file
	sessionFileConstructor->open(sessionName + "/pointers.index");
	if (sessionFileConstructor->fail())
	{
		std::cout << std::endl << "Error making session.config | Error code: -8";
	}
	//TODO: Init variables
}
