#include "Device.h"



Device::Device() : containstrojan(false)
{
}


Device::~Device()
{
}

void Device::loadDevice(std::vector<std::string> & hexValues, const std::vector<libraryEntry> *library) {
	Library = library;
	for (std::vector<libraryEntry>::const_iterator it = library->begin(); it != library->end(); ++it) {
		lutMap[it->offSet].hexCode = hexValues[it->offSet];
		lutMap[it->offSet].modifiedByTrojan = false;
		lutMap[it->offSet].offset = it->offSet;
	}
	return;
}

std::map<int, LUT>* Device::getLutMap() {
	return &lutMap;
}

void Device::setContainsTrojan(bool x) {
	containstrojan = x;
}

bool Device::getContainsTrojan() {
	return containstrojan;
}