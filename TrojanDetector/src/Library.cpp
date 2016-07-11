#include "Library.h"



Library::Library()
{
}


Library::~Library()
{
}

void Library::readLibrary(std::string fileName) {
	std::ifstream libFile(fileName.c_str());
	size_t pos = 0;
	if (!libFile.is_open()) {
		std::cerr << "Failed to open Library File\n";
		exit(0);
	}
	std::string line, delimiter = " ";
	std::vector<std::string> tokens;
	while (std::getline(libFile, line)) {
		while ((pos = line.find(delimiter)) != std::string::npos) {
			tokens.push_back(line.substr(0, pos));
			line.erase(0, pos + delimiter.length());
		}
		tokens.erase(std::remove(tokens.begin(), tokens.end(), ""), tokens.end());
		tokens.erase(std::remove(tokens.begin(), tokens.end(), delimiter), tokens.end());
		//Not part of the header info
		if (tokens.size() > 0) {
			if (is_number(tokens[0])) {
				addEntry(tokens);
				tokens.clear();
			}
			else {
				tokens.clear();
			}
		}
	}
	return;
}
void Library::addEntry(std::vector<std::string> &tokens) {
	int id = std::stoi(tokens[0]), offSet = std::stoi(tokens[2]);
	DeviceType dT;
	Coordinate cord = getCoordinate(tokens[3]);
	if (tokens[1].compare("F_LUT") == 0) {
		dT = F_LUT;
	}
	else {
		dT = G_LUT;
	}

	libEntries.push_back(libraryEntry(id, dT, offSet, cord, tokens[4]));
}
Coordinate Library::getCoordinate(std::string str) {
	size_t index1 = str.find("X") + 1;
	size_t index2 = str.find("Y", index1) + 1;

	std::string strX = str.substr(0, index1 - 1);
	std::string strY = str.substr(index1, index2 - index1 - 1);

	return Coordinate(std::stoi(strX), std::stoi(strY));
}
bool Library::is_number(const std::string& s)
{
	return !s.empty() && std::find_if(s.begin(),
		s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}