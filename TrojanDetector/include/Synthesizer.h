#ifndef SYNTHESIZER_H
#define SYNTHESIZER_H
#pragma once
#include <string>
#include <set>
#include <windows.h>
class Synthesizer
{
public:
	Synthesizer();
	~Synthesizer();

	void convertSchematicToHDL(std::string path);
	size_t ExecuteProcess(std::wstring FullPathToExe, std::wstring Parameters, size_t SecondsToWait, std::wstring wPath);

private:
};

#endif // !SYNTHESIZER_H