#ifndef SYNTHESIZER_H
#define SYNTHESIZER_H
#pragma once
#include <QtWidgets>
#include <string>
#include <set>
#include <windows.h>
#include <fstream>
#include <codecvt>
#include <boost\filesystem.hpp>
#include "Structs.h"
class Synthesizer : public QObject
{
	Q_OBJECT
public:
	Synthesizer();
	~Synthesizer();
	void synthesize(bool update);
	void setPath(std::string p, std::wstring wP);
	void setPath(std::string p);
	void synthesisSetup();
	void deleteAllFiles(std::string p);
	void singleSynthesis();

signals:
	void sendPercentSynthesized(double p);
private:
	size_t ExecuteProcess(std::wstring FullPathToExe, std::wstring Parameters, size_t SecondsToWait, std::wstring wPath);
	void convertSchematicToHDL(std::string path);
	void makeDirectories();
	void makeInitFiles();
	void makeUCF(DeviceType deviceType, Coordinate coordinate);
	std::string path;
	std::wstring wPath;
};

#endif // !SYNTHESIZER_H