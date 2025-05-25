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

	while (std::getline(file, line)) {
		//std::cout << line << std::endl;
		if (line.length() >= 4 && line.length() < 6) {
			small[smallCount] = line;
			smallCount++;
		}
		else if (line.length() >= 6 && line.length() < 8) {
			medium[medCount] = line;
			medCount++;
		}
		else if (line.length() >= 8) {
			large[largeCount] = line;
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

bool logic::playGame() {
	//introduction & variable setting
	std::cout << "W E L C O M E  to the  S C R A M B L E R" << std::endl;
	std::cout << "Unscramble 5 words in 60 seconds to be the cool dude!" << std::endl;
	
	std::string scrambledWord = "";
	std::string correctWord = "";
	std::string userGuess = "";

	//small array round
	std::cout << "\nE Z  R O U N D\n" << std::endl;

	std::cout << "Round 1" << std::endl;
	correctWord = small[0];
	scrambledWord = scrambleWord(small[0]);

	std::cout << "Your word: " << scrambledWord << std::endl;
	while (userGuess != correctWord) {
		std::cin >> userGuess;
	}
	numCorrect++;

	std::cout << "Round 2" << std::endl;
	correctWord = small[1];
	scrambledWord = scrambleWord(small[1]);

	std::cout << "Your word: " << scrambledWord << std::endl;
	while (userGuess != correctWord) {
		std::cin >> userGuess;
	}
	numCorrect++;

	//medium array round
	std::cout << "\nM E D  R O U N D\n" << std::endl;

	std::cout << "Round 3" << std::endl;
	correctWord = medium[0];
	scrambledWord = scrambleWord(medium[0]);

	std::cout << "Your word: " << scrambledWord << std::endl;
	while (userGuess != correctWord) {
		std::cin >> userGuess;
	}
	numCorrect++;

	std::cout << "Round 4" << std::endl;
	correctWord = medium[1];
	scrambledWord = scrambleWord(medium[1]);

	std::cout << "Your word: " << scrambledWord << std::endl;
	while (userGuess != correctWord) {
		std::cin >> userGuess;
	}
	numCorrect++;

	//large array round
	std::cout << "\nH A R D  R O U N D\n" << std::endl;

	std::cout << "Final Round" << std::endl;
	correctWord = large[0];
	scrambledWord = scrambleWord(large[0]);

	std::cout << "Your word: " << scrambledWord << std::endl;
	while (userGuess != correctWord) {
		std::cin >> userGuess;
	}
	numCorrect++;

	return true;

}

std::string logic::scrambleWord(std::string word) {
	random_shuffle(word.begin(), word.end());
	return word;
}

void logic::gameOver() {
	if (numCorrect <= 1) {
		std::cout << "C'mon man... you can do better..." << std::endl;
	}
	else if (numCorrect == 2) {
		std::cout << "Certified CHUMP status.\n" << numCorrect << " out of 5." << std::endl;
	}
	else if (numCorrect == 3) {
		std::cout << "Mid. Try harder.\n" << numCorrect << " out of 5." << std::endl;
	}
	else if (numCorrect == 4) {
		std::cout << "Not bad. But not perfect. \n" << numCorrect << " out of 5." << std::endl;
	}
	else {
		std::cout << "\nC O N G R A T S" << std::endl;
		std::cout << "You are the big brain kewl dude." << std::endl;
	}

}