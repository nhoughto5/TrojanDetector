#include "Analyzer.h"

Analyzer::Analyzer()
{
}


Analyzer::~Analyzer()
{
}


bool Analyzer::analyzeSingle(Device Golden, Device Target, const std::vector<libraryEntry>* library) {
	int wordSize = 4, t;
	std::map<int, LUT>* targetMap = Target.getLutMap();
	std::map<int, LUT>* goldenMap = Golden.getLutMap();
	std::string tempTarget, tempGolden;
	for (std::vector<libraryEntry>::const_iterator it = library->begin(); it != library->end(); ++it) {
		tempTarget = targetMap->find(it->offSet)->second.hexCode;
		tempGolden = goldenMap->find(it->offSet)->second.hexCode;

		//Hex codes are not equal
		if (tempTarget.compare(tempGolden) != 0) {
			targetMap->find(it->offSet)->second.modifiedByTrojan = true;
			Target.setContainsTrojan(true);
		}
		tempTarget.clear();
		tempGolden.clear();
	}
	return Target.getContainsTrojan();
}