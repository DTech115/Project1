#include "coolLogic.h"

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

}

bool logic::playGame() {

}

std::string logic::scrambledWord(std::string word) {

}

void logic::gameOver() {

}