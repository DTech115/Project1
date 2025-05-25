#include <iostream>

class logic {

public:
	//constructor for default values
	logic();

	//yoinks the words from a file & stores them properly
	bool makeGame();

	//starts the game per word & counts wins
	bool playGame();

	//scrambles a given word
	std::string scrambleWord(std::string word);

	//shows how smart you are!!!
	void gameOver();

private:
	int numCorrect;
	std::string word;
	std::string scrambledWord;
	std::string small[100];
	std::string medium[100];
	std::string large[100];
};