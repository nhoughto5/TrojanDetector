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
	Device(std::map<int, LUT> lutMap_, const std::vector<libraryEntry>* Library_, bool containstrojan_);
	~Device();

	void loadDevice(std::vector<std::string> & hexValues, const std::vector<libraryEntry> * library);
	std::map<int, LUT>* getLutMap();
	void setContainsTrojan(bool x);
	bool getContainsTrojan();
	std::vector<LUT> getInfectedList();
	void setLUTContainsTrojanBool(int offset, bool value);
	void clear();
private:
	std::map<int, LUT> lutMap;
	const std::vector<libraryEntry>* Library;
	bool containstrojan;
};

#endif