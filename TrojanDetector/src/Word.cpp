#include "Word.h"



Word::Word()
{
}


Word::~Word()
{
}
Word::Word(int o_, std::string h_) :
	wordNumber(o_),
	hexWord(h_),
	byteNumber(o_ * 4),
	bitNumber(o_ * 32),
	groupType("")
{
	//FDRI Command
	//std::size_t found = h_.find("30004");
	std::string sub = h_.substr(0, 5);
	wordType = NA;
	frameLength = -1;
	if (boost::iequals(sub, "30004")) {
		std::string str = "0x" + h_;
		std::stringstream ss;
		ss << std::hex << str;
		unsigned n;
		ss >> n;
		std::bitset<32> b(n);
		frameLength = static_cast<int>(subset(b, 0, 10).to_ulong());
		CMD_Definition = "FDRI Write Packet Header (Type 1), Num of frame words: " + std::to_string(frameLength);
		wordType = FRDI_Write_Type1;
	}

	else {

		//Command Words
		if (boost::iequals(h_, "FFFFFFFF")) CMD_Definition = "Dummy Word";
		else if (boost::iequals(h_, "AA995566")) CMD_Definition = "Synchronization Word";
		else if (boost::iequals(h_, "30008001")) CMD_Definition = "CMD Write Packet Header";
		else if (boost::iequals(h_, "00000007")) CMD_Definition = "CMD Write Packet Data (Reset CRC)";
		else if (boost::iequals(h_, "30016001")) CMD_Definition = "FLR Write Packet Header";
		else if (boost::iequals(h_, "00000044")) CMD_Definition = "FLR Write Packet Data";
		else if (boost::iequals(h_, "30012001")) CMD_Definition = "COR Write Packet Header";
		else if (boost::iequals(h_, "00003FE5")) CMD_Definition = "COR Write Packet Data";
		else if (boost::iequals(h_, "3001C001")) CMD_Definition = "IDCODE Write Packet Header";
		else if (boost::iequals(h_, "0141C093")) CMD_Definition = "IDCODE Write Packet Data (3S400)";
		else if (boost::iequals(h_, "3000C001")) CMD_Definition = "MASK Write Packet Header";
		else if (boost::iequals(h_, "00000000")) {
			CMD_Definition = "Empty or Unconfigured";
			wordType = Config_Data;
		}
		else if (boost::iequals(h_, "00000009")) CMD_Definition = "CMD Write Packet Data";
		else if (boost::iequals(h_, "30002001")) CMD_Definition = "FAR Write Packet Header";
		else if (boost::iequals(h_, "00000001")) CMD_Definition = "CMD Write Packet Data (WCFG)";

		//Bitstream Data Frames

		//else if (boost::iequals(h_, "5000CF00")) CMD_Definition = "FDRI Write Packet Header (Type 2)";
		else if (boost::iequals(h_, "500046A1")) CMD_Definition = "FDRI Write Packet Header (Type 2)";
		else if (boost::iequals(h_, "0000000A")) CMD_Definition = "CMD Write Packet Data (GRESTORE)";
		else if (boost::iequals(h_, "00000003")) CMD_Definition = "CMD Write Packet Data (DGHIGH/LFRM)";
		else if (boost::iequals(h_, "20000000")) CMD_Definition = "No Op (one frame worth)";

		//Bitstream Final Commands and Start Up
		else if (boost::iequals(h_, "00000005")) CMD_Definition = "CMD Write Packet Data (START)";
		else if (boost::iequals(h_, "3000A001")) CMD_Definition = "CTL Write Packet Header";
		else if (boost::iequals(h_, "30000001")) CMD_Definition = "CRC Write Packet Header";
		else if (boost::iequals(h_, "0000000D")) CMD_Definition = "CMD Write Packet Data (DESYNC)";

		//Frame End
		else if (boost::iequals(h_, "30010001")) {
			CMD_Definition = "LOUT Write (End of Frame)";
			wordType = LOUT;
		}


		else {
			wordType = Config_Data;
			CMD_Definition = "Data";
		}
	}
}

template<size_t bits> std::bitset<bits> Word::subset(std::bitset<bits> set, int min, int max){
	const int ignore_hi = bits - max;
	std::bitset<bits> range = (~std::bitset<bits>() << ignore_hi) >> ignore_hi;
	set &= range;
	return set >> min;
}

void Word::setToAddress() {
	CMD_Definition = "Frame Address: " + hexWord;
}

void Word::setGroupType(std::string x) {
	groupType = x;
}

std::string Word::getGroupType() {
	return groupType;
}

void Word::setWordType(WordType x) {
	wordType = x;
}

WordType Word::getWordType() {
	return wordType;
}