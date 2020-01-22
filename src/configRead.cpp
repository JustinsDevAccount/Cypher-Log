/*
Copyright(C) 2020 Justin Pember
*/
#include "..\headers\configRead.hpp"

std::string returnFilename(unsigned int pointer)
{
	//TODO: make this shorter and faster
	std::string* temp_concat1;
	std::string* temp_concat2;
	std::string* temp_concat3;

	*temp_concat1 = "./cred/";
	*temp_concat2 = pointer;
	*temp_concat3 = ".cred";
	return (*temp_concat1 + *temp_concat2 + *temp_concat3);
}
