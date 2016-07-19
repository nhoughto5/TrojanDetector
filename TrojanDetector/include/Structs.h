#ifndef STRUCTS_H
#define STRUCTS_H
#pragma once
#include <string>
#include "Enums.h"

struct Coordinate {
	int X;
	int Y;
	Coordinate(int x, int y) : X(x), Y(y) {}
};
struct LUT {
	int offset;
	std::string hexCode;
	bool modifiedByTrojan;
};
struct libraryEntry {
	int id;
	DeviceType deviceType;
	int offSet;
	Coordinate xyCoordinate;
	std::string hexCode;
	DeviceConfiguration deviceConfig;
	libraryEntry(int idNum, DeviceType deviceType, int offSet, Coordinate xyCoordinate, std::string hexCode) :
		id(idNum),
		deviceType(deviceType),
		offSet(offSet),
		xyCoordinate(xyCoordinate),
		hexCode(hexCode)
	{

	}
};


#endif