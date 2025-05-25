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
	//reads the array
	std::ifstream file("dictionary.txt");
	std::string line;

	//sets each respective array's counter to 0
	int smallCount = 0;
	int medCount = 0;
	int largeCount = 0;

	//while there are still lines in the file, yoink that line & check
	//how many characters it has. Put the word in the proper array depending on its length.
	while (std::getline(file, line)) {
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

	//respective array counters double as checks for if there are enough
	//words in the dictionary to play! 
	if (smallCount >= 2 && medCount >= 2 && largeCount >= 1) {
		return true;
	}
	else {
		return false;
	}
}

//uses random_shuffle to mess up the word
std::string logic::scrambleWord(std::string word) {
	random_shuffle(word.begin(), word.end());
	return word;
}

//yoink the right word
std::string logic::getFirstWord() {
	return small[0];
}
std::string logic::getSecondWord() {
	return small[1];
}
std::string logic::getThirdWord() {
	return medium[0];
}
std::string logic::getFourthWord() {
	return medium[1];
}
std::string logic::getFifthWord() {
	return large[0];
}

//increase number!
void logic::correctUp() {
	numCorrect++;
}

//depending on the numCorrect value, give a very appropriate comment & score!
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
		std::cout << "You are the big brain kewl dude! " << numCorrect << " out of 5!" << std::endl;
	}

}