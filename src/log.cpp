/*
Copyright(C) 2020 Justin Pember
*/
#include "../headers/log.hpp"

void writeError(int errorCode, std::string sessionPath, std::fstream errorLogStream)
{
	//Checking if file is already open
	if (errorLogStream.is_open())
	{
		errorLogStream.open(std::ios::app);
	}
	else
	{
		errorLogStream.open(sessionPath + "session.log", std::ios::app);
	}
}
void writeError(int errorCode, Session sessionToRead)
{
}

void writeErrorVerbose(int errorCode, std::string message, std::string sessionPath)
{
}
void writeErrorVerbose(int errorCode, std::string message, Session sessionToRead)
{
}
