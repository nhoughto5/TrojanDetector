#ifndef WORD_H
#define WORD_H
#pragma once

#include <string>
#include <sstream>
#include <bitset>
#include <boost/algorithm/string.hpp>
#include "Enums.h"

class Word
{
public:
	Word();
	Word(int o_, std::string h_);
	~Word();

	void setToAddress();


	int wordNumber;
	std::string hexWord, CMD_Definition, groupType;
	int byteNumber, bitNumber, frameLength;
	WordType wordType;
private:

	template<size_t bits> std::bitset<bits> subset(std::bitset<bits> set, int min, int max);
};

#endif // !WORD_H