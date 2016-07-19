#ifndef ANALYZER_H
#define ANALYZER_H
#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include "Device.h"
class Analyzer
{
public:
	Analyzer();
	~Analyzer();

	static bool analyzeSingle(Device Golden, Device Target, const std::vector<libraryEntry>*);
private:
};

#endif // !ANALYZER_H