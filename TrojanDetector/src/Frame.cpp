#include "Frame.h"



Frame::Frame()
{
}


Frame::~Frame()
{
}

void Frame::addWord(Word t) {
	wordList.push_back(t);
}

void Frame::setGroupType(std::string x) {
	groupType = x;
}
void Frame::setCRC(Word x) {
	CRC = x;
}
void Frame::setFrameAddress(Word &x) {
	x.setToAddress();
	std::stringstream ss;
	ss << std::hex << x.hexWord;
	unsigned n;
	ss >> n;
	std::bitset<32> b(n), block, major, minor, word;
	block = subset(b, 25, 26);
	major = subset(b, 17, 24);
	minor = subset(b, 9, 16);
	word = subset(b, 0, 8);
	blockAddressInt = static_cast<int>(block.to_ulong());
	majorAddressInt = static_cast<int>(major.to_ulong());
	minorAddressInt = static_cast<int>(minor.to_ulong());
	wordAddressInt = static_cast<int>(word.to_ulong());
	blockAddressStr = block.to_string();
	majorAddressStr = major.to_string();
	minorAddressStr = minor.to_string();
	wordAddressStr = word.to_string();
	frameAddress = x;
	computeFrameType(blockAddressInt, majorAddressInt, minorAddressInt, wordAddressInt, frameAddress);
}

std::string Frame::getGroupType() {
	return groupType;
}
Word Frame::getCRC() {
	return CRC;
}
Word Frame::getFrameAddress() {
	return frameAddress;
}

template<size_t bits> std::bitset<bits> Frame::subset(std::bitset<bits> set, int min, int max) {
	const int ignore_hi = bits - max;
	std::bitset<bits> range = (~std::bitset<bits>() << ignore_hi) >> ignore_hi;
	set &= range;
	return set >> min;
}

void Frame::computeFrameType(int block, int major, int minor, int word, Word& word_) {
	if (block == 0) {
		if (major == 0) {
			if (minor == 0) {
				groupType = "GCLK_L";
			}
			else if (minor == 1) {
				groupType = "GCLK_R";
			}
			else if (minor == 2) {
				groupType = "CENTER";
			}
			else {
				groupType = "Block: 0, Major: 0, Minor: NA";
			}
		}
		else if (major == 1) {
			groupType = "TERM_L";
		}
		else if (major == 2) {
			groupType = "IOI_L";
		}
		else if (major == 3 || major == 4 || major == 5 || major == 6 || major == 7 || major == 8) {
			groupType = "CLB: Col: " + major;
		}
		else if (major == 9) {
			groupType = "IOI_R";
		}
		else if (major == 10) {
			groupType = "TERM_R";
		}
		else {
			groupType = "Block: 0, Major: NA";
		}
	}
	else if (block == 1) {
		if (major == 0) {
			groupType = "BRAM, LEFT";
		}
		else if (major == 1) {
			groupType = "BRAM, RIGHT";
		}
		else {
			groupType = "Block: 1, Major: NA";
		}
	}
	else if (block == 2) {
		if (major == 0) {
			groupType = "BRAM_INIT, LEFT";
		}
		else if (major == 1) {
			groupType = "BRAM_INIT, RIGHT";
		}
		else {
			groupType = "Block: 2, Major: NA";
		}
	}
	else {
		groupType = "Unknown";
	}
	word_.groupType = groupType;
}