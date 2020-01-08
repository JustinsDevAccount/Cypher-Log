/*
Copyright(C) 2020 Justin Pember
*/

#pragma once
#include <iostream>

//High level config readers------------------------------------------

/*This will return a template struct of the data format of each credential
@param is the path of dataCatagories.config file
*/
int getCredentialOutputFormatConfig(std::string configPath, struct outputStruct);

/*This will return a template struct of the data format of each credential
@param is the session's path, the function will attempt to find the config file
*/
int getCredentialOutputFormatConfigWithSessionPath(std::string sessionPath, struct outputStruct);

//Low level config readers, DO NOT USE THESE OUTSIDE THIS FILE & CORRELATING CPP FILE-------

/*
Finds config file path
@param is the path of the session, and the types of config are:
1=session
2=dataCatagories
*/
std::string findConfigFilePath(std::string sessionPath, int typeOfConfigFile);