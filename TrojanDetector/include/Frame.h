#ifndef FRAME_H
#define FRAME_H
#pragma once
#include <vector>
#include "Structs.h"

class Frame
{
public:
	Frame();
	~Frame();
	void addWord(Word t);
private:
	std::vector<Word> wordList;
	std::string groupType;

};

#endif