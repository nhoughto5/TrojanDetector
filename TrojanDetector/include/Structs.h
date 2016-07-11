#ifndef STRUCTS_H
#define STRUCTS_H
#pragma once
#include "Enums.h"
#include <string>
struct Coordinate {
	int X;
	int Y;
	Coordinate(int x, int y) : X(x), Y(y) {}
};
struct lutOffsetResponse {
	int offset;
	std::string hexCode;
	//lutOffsetResponse() {}
	//lutOffsetResponse(int o_, std::string h_): offset(o_), hexCode(h_) {}
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