/*
Copyright(C) 2020 Justin Pember
*/

#pragma once
#include <iostream>
#include <fstream>

//Data format for credential file output
struct dataCatagories;

//High level config readers------------------------------------------

/*
Fixes all credential output errors
@param sessionPath; full path to session data folder
*/
void fixCredOutputErrors(std::string sessionPath);

/*
Fixes credential output errors for one file
@param sessionPath; full path to session data folder
@param pointerToFile; pointer number that leads to file with error
*/
void fixCredOutputErrors(std::string sessionPath, unsigned int pointerToFile);


//Low level config readers, DO NOT USE THESE OUTSIDE THIS FILE & CORRELATING CPP FILE-------

/*
Finds config file path
@param is the path of the session, and the types of config are:
1=session
2=dataCatagories
*/
std::string findConfigFilePath(std::string sessionPath, unsigned int typeOfConfigFile);

/*
Checks for errors in the credential outputs, it mostly checks for format errors
@param sessionPath is the full path of the folder where the session data is held
@param pointerArray is the array with the pointers to files that have errors
Returns boolean value if errors are found, if found, the pointers are dumped into the array
*/
bool checkForCredOutputErrors(std::string sessionPath, unsigned int pointerArray);

/*
Returns file path to .cred file
@param pointer is the pointer to the file from the pointers.index file
*/
std::string returnFilename(unsigned int pointer);