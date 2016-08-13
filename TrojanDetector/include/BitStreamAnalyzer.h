#ifndef BITSTREAMANALYZER_H
#define BITSTREAMANALYZER_H
#pragma once
#include <iostream>
#include <unordered_map>
#include <fstream>
#include <iomanip>
#include <boost/algorithm/string.hpp>
#include "Structs.h"
#include "Frame.h"
class BitStreamAnalyzer
{
public:
	BitStreamAnalyzer();
	~BitStreamAnalyzer();
	void readBitFile(std::string binFilePath);
	lutOffsetResponse getByteOffSet();
	void makeWordList(std::string binFilePath);
	void makeFrameList();
	void clear();
	std::vector<std::string> getHexByteValues();
	std::string getPath();
private:
	std::string hexFormat(int num);
	std::string path;
	std::vector<std::string> hexByteValues;
	std::vector<Word> wordList;
	std::vector<Frame> frameList;
	const char *LUT_Hex_Codes[7] = { "FFF0FFFF","FFFFFAFA","FAFAFFFF", "FFFFFFCC", "FFCCFFFF", "FCFCFFFF", "FFFFFCFC" };
};
#endif
