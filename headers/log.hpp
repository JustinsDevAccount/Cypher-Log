#include <fstream>
#include <iostream>
#include "session.hpp"

//ERROR LOGGING-------------------------------------------------------
//Writes the errors to a log file located in the database directory
void writeError(int errorCode, std::string sessionPath, std::fstream errorLogStream);
void writeError(int errorCode, Session sessionToRead);

//Writes error to log and displays code to console
void writeErrorVerbose(int errorCode, std::string message, std::string sessionPath);
void writeErrorVerbose(int errorCode, std::string message, Session sessionToRead);

//GENERAL LOGGING-----------------------------------------------------
void writeLog(std::string title, std::string message, std::fstream logStream);
void writeLog(std::string title, std::string message, Session session);

//MISC LOGGING--------------------------------------------------------
//Clears the log file (deletes content), does not delete the .log file
void clearLog(std::fstream logStream);
void clearLog(Session session);

//Output .log file to console
void outputLogToConsole(std::fstream logStream);
void outputLogToConsole(Session session);