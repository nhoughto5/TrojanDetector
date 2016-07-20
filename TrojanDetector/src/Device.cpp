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
		lutMap[it->offSet].hexCode = hexValues[it->offSet] + hexValues[it->offSet + 1] + hexValues[it->offSet + 2] + hexValues[it->offSet + 3];
		lutMap[it->offSet].modifiedByTrojan = false;
		lutMap[it->offSet].offset = it->offSet;
		lutMap[it->offSet].xyCoordinate.X = it->xyCoordinate.X;
		lutMap[it->offSet].xyCoordinate.Y = it->xyCoordinate.Y;
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

std::vector<LUT> Device::getInfectedList() {
	std::vector<LUT> infected;
	for (std::map<int, LUT>::const_iterator it = lutMap.begin(); it != lutMap.end(); ++it) {
		if (it->second.modifiedByTrojan) {
			infected.push_back(it->second);
		}
	}
	return infected;
}

void Device::setLUTContainsTrojanBool(int offset, bool value) {
	lutMap.find(offset)->second.modifiedByTrojan = value;
}