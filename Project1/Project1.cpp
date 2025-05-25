#include <iostream>
#include "coolLogic.h"
#include <allegro5/allegro.h>

bool finished = false;
bool timeOut = false;

void* input(ALLEGRO_THREAD* ptr, void* arg);
void* timer(ALLEGRO_THREAD* ptr, void* arg);


logic game;


int main() {

    ALLEGRO_THREAD* create1 = NULL, * create2 = NULL;

    create1 = al_create_thread(input, NULL);
    create2 = al_create_thread(timer, NULL);

	game.makeGame();


	while (!finished && !timeOut)
	{


		if (!finished && !timeOut)
		{
			al_start_thread(create1);

			al_start_thread(create2);

		}
		else
		{
			al_destroy_thread(create1);
			al_destroy_thread(create2);
		}


	}
	if (finished)
		std::cout << "\n\tUser entered input and that ended the program\n";
	else
		std::cout << "\n\tTime ran out and that ended the program1\n";
	return 0;
}

void* input(ALLEGRO_THREAD* ptr, void* arg)
{
	finished = false;

	std::cout << "W E L C O M E  to the  S C R A M B L E R" << std::endl;
	std::cout << "Unscramble 5 words in 60 seconds to be the big brain kewl dude!" << std::endl;

	std::string scrambledWord = "";
	std::string correctWord = "";
	std::string userGuess = "";

	//small array round
	std::cout << "\nE Z  R O U N D\n" << std::endl;

	std::cout << "Round 1" << std::endl;
	correctWord = game.getFirstWord();
	scrambledWord = game.scrambleWord(correctWord);

	std::cout << "Your word: " << scrambledWord << std::endl;
	while (userGuess != correctWord) {
		std::cin >> userGuess;
	}
	game.correctUp();

	std::cout << "Round 2" << std::endl;
	correctWord = game.getSecondWord();
	scrambledWord = game.scrambleWord(correctWord);

	std::cout << "Your word: " << scrambledWord << std::endl;
	while (userGuess != correctWord) {
		std::cin >> userGuess;
	}
	game.correctUp();

	//medium array round
	std::cout << "\nM E D  R O U N D\n" << std::endl;

	std::cout << "Round 3" << std::endl;
	correctWord = game.getThirdWord();
	scrambledWord = game.scrambleWord(correctWord);

	std::cout << "Your word: " << scrambledWord << std::endl;
	while (userGuess != correctWord) {
		std::cin >> userGuess;
	}
	game.correctUp();

	std::cout << "Round 4" << std::endl;
	correctWord = game.getFourthWord();
	scrambledWord = game.scrambleWord(correctWord);

	std::cout << "Your word: " << scrambledWord << std::endl;
	while (userGuess != correctWord) {
		std::cin >> userGuess;
	}
	game.correctUp();

	//large array round
	std::cout << "\nH A R D  R O U N D\n" << std::endl;

	std::cout << "Final Round" << std::endl;
	correctWord = game.getFifthWord();
	scrambledWord = game.scrambleWord(correctWord);

	std::cout << "Your word: " << scrambledWord << std::endl;
	while (userGuess != correctWord) {
		std::cin >> userGuess;
	}
	game.correctUp();
	finished = true;

	return NULL;
}

void* timer(ALLEGRO_THREAD* ptr, void* arg)
{
	time_t startTime, currentTime; //times used to measure elapsed time
	startTime = time(NULL);
	currentTime = time(NULL);
	while (currentTime - startTime < 10 && !finished)
	{
		currentTime = time(NULL);
	}
	timeOut = true;
	return NULL;
}