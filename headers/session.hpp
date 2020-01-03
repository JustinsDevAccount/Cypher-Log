#include <iostream>
class Session
{
public:

	newSession(std::string filePath, sessionName);
	loadSession(std::string filePath);
	saveSession(std::string filePath);
	exportSession(std::string fileTypeToExportTo, bool closeOnCompletion);
};