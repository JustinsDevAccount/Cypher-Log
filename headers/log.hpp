#include <fstream>
#include <iostream>
#include "session.hpp"

//ERROR LOGGING-------------------------------------------------------
/*
Writes the errors to a log file located in the database directory, limit of 1000 alphanumeric characters
@param errorCode; return code / error code
@param errorMessage; description of message
path of session, and the filename of the log
*/
void writeError(int errorCode, std::string errorMessage, std::string sessionPath, std::string logName);
/*
Writes the errors to a log file located in the database directory, limit of 1000 alphanumeric characters
@params are the return code of error, very short description of error, 
the session to read from (passed as reference)
*/
void writeError(int errorCode, std::string errorMessage, Session &sessionToRead);

//Writes error to log and displays code to console, limit of 1000 alphanumeric characters
void writeErrorVerbose(int errorCode, std::string errorMessage, std::string sessionPath, std::string logName);
void writeErrorVerbose(int errorCode, std::string errorMessage, Session &sessionToRead);

//GENERAL LOGGING-----------------------------------------------------
/*
Writes a log entry with the format "[LOG]<title>::<message>"
@param title; title to display on log
@param message; message to display on log
@param sessionPath; full path to session folder
@param logName; filename of log file, DO NOT INCLUDE PATH
*/
void writeLog(std::string title, std::string message, std::string sessionPath, std::string logName);
/*
Writes a log entry with the format "[LOG]<title>::<message>"
@param title; title to display on log
@param message; message to display on log
@param session; is passed reference
*/
void writeLog(std::string title, std::string message, Session &session);

//MISC LOGGING--------------------------------------------------------
/*
Clears the log file (deletes content), does not delete the .log file
@param filename; path to log file if using non-default name (for example "logFile/nonDefaultLogName.log")
*/
void clearLog(std::string pathFromSessionFolder);
void clearLog(Session &session);

//Output .log file to console
void outputLogToConsole(std::string sessionPath, std::string logName);
void outputLogToConsole(Session &session);