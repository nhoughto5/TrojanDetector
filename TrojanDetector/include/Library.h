#ifndef LIBRARY_H
#define LIBRARY_H
#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>

#include "Structs.h"
class Library
{
public:
	Library();
	~Library();

	void readLibrary(std::string fileName);
	const std::vector<libraryEntry>* getLibrary();
	void addEntry(DeviceType deviceType, lutOffsetResponse offset, Coordinate xyCoordinate, std::string location = "NA", DeviceConfiguration deviceConfig = NONE);
private:
	std::vector<libraryEntry> libEntries;

	bool is_number(const std::string& s);
	void addEntry(std::vector<std::string> &tokens);
	Coordinate getCoordinate(std::string);
};
#endif // !LIBRARY_H
