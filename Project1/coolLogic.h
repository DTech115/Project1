#include <iostream>

class logic {

public:
	//constructor for default values
	logic();

	//yoinks the words from a file & stores them in their proper ez/med/hard arrays
	bool makeGame();

	//scrambles a given word
	std::string scrambleWord(std::string word);

	//shows how smart you are!!!
	void gameOver();

	//getters for each word
	std::string getFirstWord();
	std::string getSecondWord();
	std::string getThirdWord();
	std::string getFourthWord();
	std::string getFifthWord();
	
	//iterator for questions right
	void correctUp();

private:
	int numCorrect;
	std::string word;
	std::string scrambledWord;
	std::string small[100];
	std::string medium[100];
	std::string large[100];
};