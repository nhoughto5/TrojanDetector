#ifndef STRUCTS_H
#define STRUCTS_H
#pragma once
#include <string>
#include <boost/algorithm/string.hpp>
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
struct CMD_Word {
	std::string Description, Word;
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

struct Word {
	int wordNumber;
	std::string hexWord, CMD_Definition;
	int byteNumber, bitNumber;
	Word(int o_, std::string h_) :
		wordNumber(o_),
		hexWord(h_),
		byteNumber(o_ * 4),
		bitNumber(o_ * 32)
	{
		//Command Words
		if (boost::iequals(h_, "FFFFFFFF")) CMD_Definition = "Dummy Word";
		else if (boost::iequals(h_, "AA995566")) CMD_Definition = "Synchronization Word";
		else if (boost::iequals(h_, "30008001")) CMD_Definition = "CMD Write Packet Header";
		else if (boost::iequals(h_, "00000007")) CMD_Definition = "CMD Write Packet Data (Reset CRC)";
		else if (boost::iequals(h_, "30016001")) CMD_Definition = "FLR Write Packet Header";
		else if (boost::iequals(h_, "00000044")) CMD_Definition = "FLR Write Packet Data";
		else if (boost::iequals(h_, "30012001")) CMD_Definition = "COR Write Packet Header";
		else if (boost::iequals(h_, "00003FE5")) CMD_Definition = "COR Write Packet Data";
		else if (boost::iequals(h_, "3001C001")) CMD_Definition = "IDCODE Write Packet Header";
		else if (boost::iequals(h_, "0141C093")) CMD_Definition = "IDCODE Write Packet Data (3S400)";
		else if (boost::iequals(h_, "3000C001")) CMD_Definition = "MASK Write Packet Header";
		else if (boost::iequals(h_, "00000000")) CMD_Definition = "Empty or Unconfigured";
		else if (boost::iequals(h_, "00000009")) CMD_Definition = "CMD Write Packet Data";
		else if (boost::iequals(h_, "30002001")) CMD_Definition = "FAR Write Packet Header";
		else if (boost::iequals(h_, "00000001")) CMD_Definition = "CMD Write Packet Data (WCFG)";

		//Bitstream Data Frames
		else if (boost::iequals(h_, "30004000")) CMD_Definition = "FDRI Write Packet Header (Type 1)";
		//else if (boost::iequals(h_, "5000CF00")) CMD_Definition = "FDRI Write Packet Header (Type 2)";
		else if (boost::iequals(h_, "500046A1")) CMD_Definition = "FDRI Write Packet Header (Type 2)";
		else if (boost::iequals(h_, "0000000A")) CMD_Definition = "CMD Write Packet Data (GRESTORE)";
		else if (boost::iequals(h_, "00000003")) CMD_Definition = "CMD Write Packet Data (DGHIGH/LFRM)";
		else if (boost::iequals(h_, "20000000")) CMD_Definition = "No Op (one frame worth)";

		//Bitstream Final Commands and Start Up
		else if (boost::iequals(h_, "00000005")) CMD_Definition = "CMD Write Packet Data (START)";
		else if (boost::iequals(h_, "3000A001")) CMD_Definition = "CTL Write Packet Header";
		else if (boost::iequals(h_, "30000001")) CMD_Definition = "CRC Write Packet Header";
		else if (boost::iequals(h_, "CMD Write Packet Data (DESYNC)")) CMD_Definition = "0000000D";

		//Frame End
		else if (boost::iequals(h_, "LOUT Write (End of Frame)")) CMD_Definition = "30010001";


		else CMD_Definition = "Data";

	}
};


#endif