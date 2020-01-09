/*
Copyright(C) 2020 Justin Pember
*/
#include "../headers/log.hpp"

void writeError(int errorCode, std::string errorMessage, std::string sessionPath, std::string logName)
{
	//Setting stream to append to file
	std::fstream  (sessionPath + logName, std::ios::app);
	//Writing in format <Message> | Return code: <error code>
	//Example== Error writing to log file | Return code: -56
	errorLogStream << '\n' << errorMessage << " | Return code = " << errorCode;
	return;
}
void writeError(int errorCode, std::string errorMessage, Session sessionToRead)
{
	//Checking if file is already open
	if (sessionToRead.errorLogStream.is_open())
	{
		//Setting stream to append to file
		sessionToRead.errorLogStream.open(sessionToRead.m_sessionPath + "session.log", std::ios::app);
		//Writing in format <Message> | Return code: <error code>
		//Example== Error writing to log file | Return code: -56
		sessionToRead.errorLogStream << '\n' << errorMessage << " | Return code = " << errorCode;
		return;
	}
	else
	{
		//Creating the log file and setting to append
		sessionToRead.errorLogStream.open(sessionToRead.m_sessionPath + "session.log", std::ios::app);
		//Writing in format <Message> | Return code: <error code>
		//Example== Error writing to log file | Return code: -56
		sessionToRead.errorLogStream << '\n' << errorMessage << " | Return code = " << errorCode;
		return;
	}
}

void writeErrorVerbose(int errorCode, std::string message, std::string sessionPath)
{
	writeError(errorCode, message, sessionPath);
}
void writeErrorVerbose(int errorCode, std::string message, Session sessionToRead)
{
	writeError(errorCode, message, sessionPath);
	std::cout << message << "Return code: " << errorCode << std::endl;
}
