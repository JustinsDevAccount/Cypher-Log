#pragma once
#include "session.hpp"
#include <fstream>

//High level config readers------------------------------------------

/*
@param is the actual path of the session.config file
*/
Session getSessionConfig(std::string configPath);

/*
@param is the path of the session, the function will find config path
*/
Session findSessionConfigWithSessionPath(std::string sessionPath);

/*This will return a template struct of the data format of each credential
@param is the path of dataCatagories.config file
*/
struct getCredentialOutputFormatConfig(std::string configPath);

/*This will return a template struct of the data format of each credential
@param is the session's path, the function will attempt to find the config file
*/
struct getCredentialOutputFormatConfigWithSessionPath(std::string sessionPath);

//Low level config readers, DO NOT USE THESE OUTSIDE THIS FILE & CORRELATING CPP FILE-------

/*
Finds config file path
*/
std::string findConfigFilePath(std::string relativePath, int typeOfConfigFile);