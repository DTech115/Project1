#include "coolLogic.h"
#include "fstream"

//constructor resets all words
logic::logic() {

	word = "";
	scrambledWord = "";
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
}

bool logic::playGame() {

}

std::string logic::scrambleWord(std::string word) {

}

void logic::gameOver() {

}