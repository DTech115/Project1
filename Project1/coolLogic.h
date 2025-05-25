#include <iostream>

class logic {

public:
	//constructor
	logic();

	//yoinks the words from a file
	bool makeGame();

	//starts the game & checks if player wins
	bool playGame();

	//scrambles a given word
	std::string scrambleWord(std::string word);

	//takes care of end-of-game stuff
	void gameOver();

private:
	int numCorrect;
	std::string word;
	std::string scrambledWord;
	std::string small[100];
	std::string medium[100];
	std::string large[100];
};