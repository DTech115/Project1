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

	while (std::getline(file, line)) {
		std::cout << line << std::endl;
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