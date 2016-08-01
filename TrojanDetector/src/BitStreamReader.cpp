//#include "BitStreamReader.h"
//
//
//
//BitStreamReader::BitStreamReader()
//{
//}
//
//
//BitStreamReader::~BitStreamReader()
//{
//}
//
//void BitStreamReader::getWordList(std::string binFilePath) {
//	std::clock_t    start;
//	start = std::clock();
//	using namespace std;
//	unsigned char x;
//	std::ifstream input(binFilePath.c_str(), std::ios::binary);
//	input >> std::noskipws;
//	std::stringstream buffer;
//
//	//Read entire hex file into buffer
//	while (input >> x) {
//		buffer << std::hex << std::setw(2) << std::setfill('0') << (int)x;
//	}
//	std::string content = buffer.str();
//	int strL = content.length();
//
//	//Split file into vector of bytes
//	for (int i = 0; i < strL; i += 8) {
//		wordList.push_back(Word(i*8, content.substr(i, 8)));
//	}
//	buffer.clear();
//	content.clear();
//	return;
//}
//void BitStreamReader::readBitFile(std::string binFilePath) {
//	std::clock_t    start;
//	start = std::clock();
//	using namespace std;
//	unsigned char x;
//	std::ifstream input(binFilePath.c_str(), std::ios::binary);
//	input >> std::noskipws;
//	std::stringstream buffer;
//
//	//Read entire hex file into buffer
//	while (input >> x) {
//		buffer << std::hex << std::setw(2) << std::setfill('0') << (int)x;
//	}
//	std::string content = buffer.str();
//	int strL = content.length();
//
//	//Split file into vector of bytes
//	for (int i = 0; i < strL; i += 2) {
//		hexByteValues.push_back(content.substr(i, 2));
//	}
//	buffer.clear();
//	content.clear();
//	return;
//}
//
//std::vector<std::string> BitStreamReader::getHexByteValues() {
//	return hexByteValues;
//}
//
//void BitStreamReader::clear() {
//	hexByteValues.clear();
//}