#pragma once
#include <iostream>
#include "configRead.hpp"
class Session
{
private:
	std::string m_sessionName;
	bool m_sessionEncrypted;
	std::string sessionDefaultMode;
	std::string sessionPath;

	//File streams, pass these as reference to decrease overhead
	std::fstream errorStream;
	std::fstream configStream;

public:
	newSession(std::string filePath, sessionName);
	loadSession(std::string filePath);
	saveSession(std::string filePath, bool closeOnCompletion);
	exportSession(std::string fileTypeToExportTo, bool closeOnCompletion);
	reloadSession(std::string filePath, bool reParseConfigFile);
};