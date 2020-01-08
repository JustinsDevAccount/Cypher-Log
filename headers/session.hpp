/*
Copyright(C) 2020 Justin Pember
*/
#pragma once
#include <iostream>
#include <fstream>
#include "configRead.hpp"
class Session
{
private:
	//Removing default cconstructor
	Session();

	//Main operating variables
	std::string m_sessionName;
	bool m_sessionEncrypted;
	std::string sessionDefaultMode;
	std::string sessionPath;

	//File streams, pass these as references only
	std::fstream errorStream;
	std::fstream configStream;

public:
	/*
	Constructor for creating a new session
	*/
	Session(std::string pathToBeConstructedIn, std::string sessionName);
	/*
	Constructor for loading an existing session
	*/
	Session(std::string sessionPath);

	//Session Main Methods
	int loadSession(std::string filePath);
	int saveSession(std::string filePath, bool closeOnCompletion);
	int exportSession(std::string fileTypeToExportTo, bool closeOnCompletion);
	int reloadSession(std::string filePath, bool reParseConfigFile);
	/*
	@param is the actual path of the session.config file, session to read the config to
	*/
	void getSessionConfig(std::string configPath, Session sessionToUse());
};