
class logic {
public:
	logic();

	bool makeGame();

	bool playGame();

	string scrambleWord(string word);

	void gameOver()

private:
	int numCorrect;
	string small[100];
	string medium[100];
	string large[100];
};