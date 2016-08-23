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

template<size_t bits> std::bitset<bits> Frame::subset(std::bitset<bits> set, int min, int max) {
	const int ignore_hi = bits - max;
	std::bitset<bits> range = (~std::bitset<bits>() << ignore_hi) >> ignore_hi;
	set &= range;
	return set >> min;
}

void Frame::computeFrameType(int block, int major, int minor, int word, Word& word_) {

}
void Frame::setCRC(Word& x) {
	CRC = x;
}
void Frame::setFrameAddress(Word& x) {
	frameAddress = x;
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