/*
Copyright(C) 2020 Justin Pember
*/
#include "../headers/log.hpp"

void writeError(int errorCode, std::string errorMessage, std::string sessionPath, std::fstream errorLogStream)
{
	//Checking if file is already open
	if (errorLogStream.is_open())
	{
		//Setting stream to append to file
		errorLogStream.open(std::ios::app);
		//Writing in format <Message> | Return code: <error code>
		//Example== Error writing to log file | Return code: -56
		erroLogStream << '\n' << errorMessage << " | Return code = " << errorCode;
		return;
	}
	else
	{
		//TO:DO add code for this part of loop
		return;
	}
}
void writeError(int errorCode, std::string errorMessage, Session sessionToRead)
{

}

void writeErrorVerbose(int errorCode, std::string message, std::string sessionPath)
{
}
void writeErrorVerbose(int errorCode, std::string message, Session sessionToRead)
{
}
