/*
Copyright(C) 2020 Justin Pember
*/
#include "../headers/log.hpp"

bool isUnderCharLimit(std::string stringToCheck)
{
	int* charLimit;
	*charLimit = 1000;
	if (stringToCheck.length() >= 1000)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void writeError(int errorCode, std::string errorMessage, std::string sessionPath, std::string logName)
{
	//Checking length of error
	if (isUnderCharLimit(errorMessage))
	{
		writeErrorVerbose(-4, "Error writing error; message exceeded char limit", sessionPath, logName);
	}
	//Setting stream to append to file
	std::fstream* errorLogStream;
	errorLogStream->open(sessionPath + logName, std::ios::app);
	//Writing in format <Message> | Return code: <error code>
	//Example== [ERROR] Error writing to log file | Return code: -56
	*errorLogStream << '\n' << "[ERROR]" << errorMessage << " | Return code = " << errorCode;
	delete (errorLogStream);
	return;
}
void writeError(int errorCode, std::string errorMessage, Session &sessionToRead)
{
	//Checking length of error
	if (isUnderCharLimit(errorMessage))
	{
		writeErrorVerbose(-4, "Could not write error; message exceeded char limit", sessionToRead);
	}
	//Checking if file is already open
	if (sessionToRead.errorLogStream.is_open())
	{
		//Setting stream to append to file
		sessionToRead.errorLogStream.open(sessionToRead.m_sessionPath + "session.log", std::ios::app);
		//Checking the file open process has failed
		if (sessionToRead.errorLogStream.fail())
		{
			std::cout << "Log file failed to initalize | Return code: -3";
			return;
		}
		else
		{
			//Writing in format <Message> | Return code: <error code>
			//Example== [ERROR] Error writing to log file | Return code: -56
			sessionToRead.errorLogStream << '\n' << "[ERROR]" << errorMessage << " | Return code = " << errorCode;
			return;
		}
	}
	else
	{
		//Creating the log file and setting to append
		sessionToRead.errorLogStream.open(std::ios::app);
		//Writing in format <Message> | Return code: <error code>
		//**Example** == Error writing to log file | Return code: -56
		sessionToRead.errorLogStream << '\n' << errorMessage << " | Return code = " << errorCode;
		return;
	}
}

void writeErrorVerbose(int errorCode, std::string errorMessage, std::string sessionPath, std::string logName)
{
	writeError(errorCode, errorMessage, sessionPath, logName);
	std::cout << '\n' << errorMessage << "| Return code: " << errorCode << "| Writing to: " << sessionPath << logName;
}
void writeErrorVerbose(int errorCode, std::string errorMessage, Session &sessionToRead)
{
	writeErrorVerbose(errorCode, errorMessage, sessionToRead.m_sessionName, "session.log");
}

void writeLog(std::string title, std::string message, std::string sessionPath, std::string logName)
{
	//Opening file and setting to append
	std::fstream* logStream;
	logStream->open((sessionPath + logName), std::ios::app);
	logStream << '\n' << "[LOG]" << title << "::" << message;
	delete(logStream);
	return;
}

void writeLog(std::string title, std::string message, Session &session)
{
	writeLog(title, message, session.m_sessionPath, "session.log");
}
