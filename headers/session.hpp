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
	std::string m_sessionDefaultMode;
	std::string m_sessionPath;

	//File streams, pass these as references only
	std::fstream errorLogStream;
	std::fstream configStream;

public:
	/*
	Setting the logging functions to a freind to allow access
	to allow access to private variables
	*/
	friend void writeError(int errorCode, std::string errorMessage, Session &sessionToRead);
	friend void writeErrorVerbose(int errorCode, std::string errorMessage, Session &sessionToRead);
	friend void writeLog(std::string title, std::string message, Session &session);
	friend void clearLog(Session &session);
	friend void outputLogToConsole(Session &session);

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
	@param configPath is the actual path of the session.config file, session to read the config to
	*/
	void getSessionConfig(std::string configPath, Session sessionToUse());
};