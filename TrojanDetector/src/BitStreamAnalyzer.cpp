#include <stdio.h>
#include <iomanip>
#include <algorithm>
#include "CoutRedirect.h"
#include "BitStreamAnalyzer.h"
#include "enums.h"
BitStreamAnalyzer::BitStreamAnalyzer()
{
}

BitStreamAnalyzer::~BitStreamAnalyzer()
{
}
std::string BitStreamAnalyzer::hexFormat(int num) {
	std::stringstream s;
	s << std::hex << std::setw(8) << std::setfill('0') << num;
	std::string s2 = s.str();
	return s2;
}
void BitStreamAnalyzer::makeWordList(std::string binFilePath) {
	std::clock_t    start;
	start = std::clock();
	using namespace std;
	unsigned char x;
	std::ifstream input(binFilePath.c_str(), std::ios::binary);
	input >> std::noskipws;
	std::stringstream buffer;

	//Read entire hex file into buffer
	while (input >> x) {
		buffer << std::hex << std::setw(2) << std::setfill('0') << (int)x;
	}
	std::string content = buffer.str();
	int strL = content.length();

	//Split file into vector of bytes
	for (int i = 0; i < strL; i += 8) {
		wordList.push_back(Word(i / 8, content.substr(i, 8)));
	}
	buffer.clear();
	content.clear();

	std::ofstream wordFile, summaryFile;
	wordFile.open("BitstreamWordList.txt");
	summaryFile.open("BitStreamSummary.txt");
	wordFile << "WordNumber     CommandType                          hexValue(hex)     byteOffset(hex)     BitOffset(int)\n";
	summaryFile << "WordNumber     CommandType                          hexValue(hex)     byteOffset(hex)     BitOffset(int)\n";
	const char seperator = ' ';
	int  emptyCount = 0, numWidth = 15, typLength = 37, hexLength = 16, byteLength = 18, bitLength = 20;
	for (std::vector<Word>::const_iterator it = wordList.begin(); it != wordList.end(); ++it) {
		//Print to full word file
		wordFile
			<< std::left << std::setw(numWidth) << std::setfill(seperator) << it->wordNumber
			<< std::left << std::setw(typLength) << std::setfill(seperator) << it->CMD_Definition
			<< "0x" << std::left << std::setw(hexLength) << std::setfill(seperator) << boost::to_upper_copy<std::string>(it->hexWord)
			<< "0x" << std::left << std::setw(byteLength) << std::setfill(seperator) << hexFormat(it->byteNumber)
			<< std::left << std::setw(bitLength) << std::setfill(seperator) << std::dec << it->bitNumber << "\n";

		//Print to Summary word file
		if (boost::iequals(it->hexWord, "00000000") && emptyCount < 2) {
			++emptyCount;
			summaryFile
				<< std::left << std::setw(numWidth) << std::setfill(seperator) << it->wordNumber
				<< std::left << std::setw(typLength) << std::setfill(seperator) << it->CMD_Definition
				<< "0x" << std::left << std::setw(hexLength) << std::setfill(seperator) << boost::to_upper_copy<std::string>(it->hexWord)
				<< "0x" << std::left << std::setw(byteLength) << std::setfill(seperator) << hexFormat(it->byteNumber)
				<< std::left << std::setw(bitLength) << std::setfill(seperator) << std::dec << it->bitNumber << "\n";
		}
		if (boost::iequals(it->hexWord, "00000000") && emptyCount == 2) {
			++emptyCount;
			summaryFile
				<< std::left << std::setw(numWidth) << std::setfill(seperator) << "..."
				<< std::left << std::setw(typLength) << std::setfill(seperator) << "..."
				<< "0x" << std::left << std::setw(hexLength) << std::setfill(seperator) << "..."
				<< "0x" << std::left << std::setw(byteLength) << std::setfill(seperator) << "..."
				<< std::left << std::setw(bitLength) << std::setfill(seperator) << std::dec << "..." << "\n";
		}
		if (!boost::iequals(it->hexWord, "00000000")) {
			emptyCount = 0;
			summaryFile
				<< std::left << std::setw(numWidth) << std::setfill(seperator) << it->wordNumber
				<< std::left << std::setw(typLength) << std::setfill(seperator) << it->CMD_Definition
				<< "0x" << std::left << std::setw(hexLength) << std::setfill(seperator) << boost::to_upper_copy<std::string>(it->hexWord)
				<< "0x" << std::left << std::setw(byteLength) << std::setfill(seperator) << hexFormat(it->byteNumber)
				<< std::left << std::setw(bitLength) << std::setfill(seperator) << std::dec << it->bitNumber << "\n";
		}

	}
	wordFile.close();
	summaryFile.close();
	makeFrameList();
	return;
}

void BitStreamAnalyzer::makeFrameList() {
	bool dataEnd = false, dataStart = false;
	if (wordList.empty()) {
		return;
	}
	bool firstFrame;
	Frame* temp;


	for (std::vector<Word>::const_iterator it = wordList.begin(); it != wordList.end(); ++it) {

	}


	//for (std::vector<Word>::const_iterator it = wordList.begin(); it != wordList.end(); ++it) {
	//	if (boost::iequals(it->hexWord, "00000001")) {
	//		dataStart = true;
	//		temp = new Frame();
	//		continue;
	//	}
	//	if (dataStart) {
	//		//Create a new frame
	//		if (boost::iequals(it->hexWord, "30010001")) {
	//			frameList.push_back(*temp);
	//			temp = new Frame();
	//		}
	//		//Check that it is not tail data or frame type definition CMD words
	//		if (dataEnd && (boost::iequals(it->CMD_Definition, "Empty or Unconfigured") || boost::iequals(it->CMD_Definition, "Data"))) {
	//			temp->addWord(*it);
	//		}
	//	}
	//	//Reached the tail information
	//	if (boost::iequals(it->hexWord, "30008001")) {
	//		dataEnd = true;
	//	}
	//}
}

std::string BitStreamAnalyzer::getPath() {
	return path;
}
void BitStreamAnalyzer::readBitFile(std::string binFilePath) {
	path = binFilePath;
	std::clock_t    start;
	start = std::clock();
	using namespace std;
	unsigned char x;
	std::ifstream input(binFilePath.c_str(), std::ios::binary);
	input >> std::noskipws;
	std::stringstream buffer;

	//Read entire hex file into buffer
	while (input >> x) {
		buffer << std::hex << std::setw(2) << std::setfill('0') << (int)x;
	}
	std::string content = buffer.str();
	int strL = content.length();

	//Split file into vector of bytes
	for (int i = 0; i < strL; i += 2) {
		hexByteValues.push_back(content.substr(i, 2));
	}
	buffer.clear();
	content.clear();
	return;
}

lutOffsetResponse BitStreamAnalyzer::getByteOffSet() {
	std::vector<int> results;
	int numBytesKeyword = 4;
	std::string temp, stringRet;

	for (int i = 0; i < hexByteValues.size() - numBytesKeyword; ++i) {
		for (int j = 0; j < numBytesKeyword; ++j) {
			temp += hexByteValues[i + j];
		}
		if (boost::iequals(temp, "FFF0FFFF")) {
			results.push_back(i);
			stringRet = "FF F0 FF FF";
		}
		else if (boost::iequals(temp, "FFFFFAFA")) {
			results.push_back(i);
			stringRet = "FF FF FA FA";
		}
		else if (boost::iequals(temp, "FAFAFFFF")) {
			results.push_back(i);
			stringRet = "FA FA FF FF";
		}
		else if (boost::iequals(temp, "FFFFFFCC")) {
			results.push_back(i);
			stringRet = "FF FF FF CC";
		}
		else if (boost::iequals(temp, "FFCCFFFF")) {
			results.push_back(i);
			stringRet = "FF CC FF FF";
		}
		else if (boost::iequals(temp, "FCFCFFFF")) {
			results.push_back(i);
			stringRet = "FC FC FF FF";
		}
		else if (boost::iequals(temp, "FFFFFCFC")) {
			results.push_back(i);
			stringRet = "FF FF FC FC";
		}
		else if (boost::iequals(temp, "FFFFEEEE")) {
			results.push_back(i);
			stringRet = "FF FF EE EE";
		}
		else if (boost::iequals(temp, "EEEEFFFF")) {
			results.push_back(i);
			stringRet = "EE EE FF FF";
		}
		else if (boost::iequals(temp, "FFFFFFF0")) {
			results.push_back(i);
			stringRet = "FF FF FF F0";
		}
		else if (boost::iequals(temp, "FFAAFFFF")) {
			results.push_back(i);
			stringRet = "FF AA FF FF";
		}
		else if (boost::iequals(temp, "FFFFFFAA")) {
			results.push_back(i);
			stringRet = "FF FF FF AA";
		}
		else {

		}
		temp.clear();
	}

	int intRet;

	if (results.size() > 1) {
		if (std::find(results.begin(), results.end(), 1) != results.end()) {
			results.erase(std::remove(results.begin(), results.end(), 1), results.end());
		}
		else {
			intRet = -1;
			stringRet = "NA";
		}
	}
	if (results.size() < 1) {
		intRet = -1;
		stringRet = "NA";
	}
	intRet = results[0];
	lutOffsetResponse ret;
	ret.offset = intRet;
	ret.hexCode = stringRet;
	return ret;
}
std::vector<std::string> BitStreamAnalyzer::getHexByteValues() {
	return hexByteValues;
}
void BitStreamAnalyzer::clear() {
	hexByteValues.clear();
}