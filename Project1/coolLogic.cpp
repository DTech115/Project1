#include "coolLogic.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

//constructor resets all words & such
logic::logic() {

	word = "";
	scrambledWord = "";
	numCorrect = 0;
	for (int i = 0; i < 100; i++) {
		small[i] = "";
		medium[i] = "";
		large[i] = "";
	}
}

//saves the words into their proper arrays
bool logic::makeGame() {
	std::ifstream file("dictionary.txt");
	std::string line;

	int smallCount = 0;
	int medCount = 0;
	int largeCount = 0;

	int count = 0;
	while (std::getline(file, line)) {
		//std::cout << line << std::endl;
		if (line.length() >= 4 && line.length() < 6) {
			small[count] = line;
			count++;
			smallCount++;
		}
		else if (line.length() >= 6 && line.length() < 8) {
			medium[count] = line;
			count++;
			medCount++;
		}
		else if (line.length() >= 8) {
			large[count] = line;
			count++;
			largeCount++;
		}
	}

	if (smallCount >= 2 && medCount >= 2 && largeCount >= 1) {
		return true;
	}
	else {
		return false;
	}
}

//bool logic::playGame() {
//	
//}

std::string logic::scrambleWord(std::string word) {
	random_shuffle(word.begin(), word.end());
	return word;
}
//
//void logic::gameOver() {
//
//}