#ifndef FRAME_H
#define FRAME_H
#pragma once
#include <vector>
#include <bitset>
#include "Word.h"
#include "Structs.h"

class Frame
{
public:
	Frame();
	~Frame();
	void addWord(Word t);
	void setGroupType(std::string x);
	void setCRC(Word& x);
	void setFrameAddress(Word& x);
	
	std::string getGroupType();
	Word getCRC();
	Word getFrameAddress();
private:
	std::vector<Word> wordList;
	std::string groupType;
	Word CRC, frameAddress;
	void computeFrameType(int block, int major, int minor, int word, Word& word_);
	int blockAddressInt, majorAddressInt, minorAddressInt, wordAddressInt;
	std::string blockAddressStr, majorAddressStr, minorAddressStr, wordAddressStr;
	template<size_t bits> std::bitset<bits> subset(std::bitset<bits> set, int min, int max);

};

#endif