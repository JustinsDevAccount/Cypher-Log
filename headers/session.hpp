/*
Copyright(C) 2020 Justin Pember
*/
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>
#include "templates.hpp"
#include "configRead.hpp"
class Session
{
private:
	//Removing default constructor
	Session();
	//---------------------------

	//Main operating variables
	std::string m_sessionName;
	bool m_sessionEncrypted;
	std::string m_sessionDefaultMode;
	std::string m_sessionPath;
	std::string m_sessionWorkingDirectory;
	std::string m_logPath;

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
	Constructor for creating a new session || NOT SUPPORTED YET
	@param pathToBeConstructedIn; full path or use . to use current directory
	@param sessionName; name of session and folder to to store data in
	*/
	Session(std::string pathToBeConstructedIn, std::string sessionName);
	/*
	/*
	Constructor for creating a new session
	@param pathToBeConstructedIn; full path or use only session name to use current directory
	*/
	Session(std::string sessionName, bool exitOnCreation);
	/*
	Constructor for loading an existing session
	@param sessionPath; path to session data folder
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