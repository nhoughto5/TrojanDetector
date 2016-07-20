#ifndef DEVICE_H
#define DEVICE_H
#pragma once

#include <map>
#include <string>
#include <vector>
#include "Structs.h"

class Device
{
public:
	Device();
	~Device();

	void loadDevice(std::vector<std::string> & hexValues, const std::vector<libraryEntry> * library);
	std::map<int, LUT>* getLutMap();
	void setContainsTrojan(bool x);
	bool getContainsTrojan();
	std::vector<LUT> getInfectedList();
	void setLUTContainsTrojanBool(int offset, bool value);
private:
	std::map<int, LUT> lutMap;
	const std::vector<libraryEntry>* Library;
	bool containstrojan;
};

#endif