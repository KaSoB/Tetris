#include <fstream>
#include <string>
#include "File.h"
#include "Getinput.h"

void File::DisplayTextFile(const char * fileName) {
	std::ifstream fileStream(fileName, std::ios::in);
	if (!fileStream.is_open())
		GetInput::message(fileName);
	else {
		std::string line;
		while (std::getline(fileStream, line)) {
			std::cout << line << std::endl;
		}
	}
	fileStream.close();
}
