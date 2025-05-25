#include "coolLogic.h"
#include <iostream>
#include <fstream>
#include <string>

//constructor resets all words
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

bool logic::makeGame() {
	std::ifstream file("dictionary.txt");
	std::string line;

	int count = 0;
	while (std::getline(file, line)) {
		//std::cout << line << std::endl;
		if (line.length() >= 4 && line.length() < 6) {
			small[count] = line;
			count++;
		}
		else if (line.length() >= 6 && line.length() < 8) {
			medium[count] = line;
			count++;
		}
		else if (line.length() >= 8) {
			large[count] = line;
			count++;
		}
	}
	return true;
}

//bool logic::playGame() {
//
//}
//
//std::string logic::scrambleWord(std::string word) {
//
//}
//
//void logic::gameOver() {
//
//}