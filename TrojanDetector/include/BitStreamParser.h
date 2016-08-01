#ifndef BITSTREAM_PARSER
#define BITSTREAM_PARSER
#pragma once
#include <QtWidgets/QMainWindow>
#include <string>
#include <vector>
#include <set>
#include <fstream>
#include <locale>
#include <codecvt>
#include <algorithm>
#include <iterator>
#include <windows.h>
#include <boost/filesystem.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "Structs.h"
#include "Library.h"
#include "DeviceModel.h"
#include "Synthesizer.h"
#include "BitStreamAnalyzer.h"

class BitStreamParser : public QObject
{
	Q_OBJECT
public:
	BitStreamParser();
	~BitStreamParser();

	void startParse(std::string model, std::string operation, std::string golden);
	void setPath(std::string path);
	std::vector<std::string> getDefinedParseOperations();

signals:
	void sendUpdatePercentSignal(double percent);

private:
	void parseLUT();
	void makeDirectories();
	void makeInitFiles();
	void locateLUTs();
	void cleanUP();
	std::set<std::string> setDifferences(std::set<std::string> a, std::set<std::string> b);
	std::set<std::string> listOfFiles(std::string fileName);
	void deleteResources(std::set<std::string> files);
	void initialSynthesis();
	lutOffsetResponse getLUTOffset(DeviceType deviceType, Coordinate coordinate);
	void update_UCF_PCF(DeviceType deviceType, Coordinate coordinate);
	lutOffsetResponse readBitFile();

	std::set<std::string> initialFileList;
	std::vector<std::string> definedParseOperations;
	std::string path;
	std::wstring wPath;
	Library lib;
	Synthesizer synthesizer;
	BitStreamAnalyzer bitAnalyzer;
	DeviceModel Model;
};
#endif // !BITSTREAM_PARSER
