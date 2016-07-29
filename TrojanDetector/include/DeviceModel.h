#ifndef DEVICEMODEL_H
#define DEVICEMODEL_H
#pragma once

#include <vector>
#include <set>
#include "structs.h"

class DeviceModel
{
public:
	DeviceModel();
	~DeviceModel();

	void setDevice_Xa3s100E();
	std::vector<Coordinate> getLUTCoordinates();
	int getMaxX(), getMaxY();
	std::vector<std::string> getDefinedDevices();
	
private:
	std::vector<Coordinate> LUTCoordinates;
	std::vector<Coordinate> missingAddresses;
	std::vector<IO_Site> pinSites;
	bool containsCoordinate(int x, int y);
	int maxX, maxY;
};
#endif // !DEVICEMODEL_H
