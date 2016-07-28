#ifndef STRUCTS_H
#define STRUCTS_H
#pragma once
#include <string>
#include "Enums.h"

struct Coordinate {
	int X;
	int Y;
	Coordinate() {}
	Coordinate(int x, int y) : X(x), Y(y) {}
};
struct LUT {
	int offset;
	std::string hexCode;
	bool modifiedByTrojan;
	Coordinate xyCoordinate;
};
struct lutOffsetResponse {
	int offset;
	std::string hexCode;
};
struct IO_Site {
	std::string Type;
	std::string IOB_Alias;
	int padNumber;
	int pin_SiteNumber;
	std::string pinName;
	int IO_Bank;
	std::string Tile;
	bool Accessible;
	Coordinate Clock_Region;
	IO_Site(std::string Type_, std::string IOB_Alias_, int padNumber_, int pin_SiteNumber_, std::string pinName_, int IO_Bank_, std::string Tile_, bool accessible_, Coordinate Clock_Region_) :
		Type(Type_),
		IOB_Alias(IOB_Alias_),
		padNumber(padNumber_),
		pin_SiteNumber(pin_SiteNumber_),
		pinName(pinName_),
		IO_Bank(IO_Bank_),
		Tile(Tile_),
		Accessible(accessible_),
		Clock_Region(Clock_Region_)
	{
	}
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