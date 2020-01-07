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

//MISC LOGGING--------------------------------------------------------