#include "game.cpp"
#include "game_refactor.cpp"
#include "gmock/gmock.h"

class GameFixture : public testing::Test {
public:
	string playGame(IGame& aGame, int seed) {
		std::ostringstream oss;
		auto oldCoutStreamBuf = std::cout.rdbuf();
		std::cout.rdbuf(oss.rdbuf());

		bool notAWinner;

		//Game aGame;
		srand(seed);

		aGame.add("Chet");
		aGame.add("Pat");
		aGame.add("Sue");

		do {
			int roll = rand() % 6 + 1;
			aGame.rolling(roll);

			if (rand() % 9 == 7) {
				notAWinner = aGame.wrongAnswer();
			}
			else {
				notAWinner = aGame.wasCorrectlyAnswered();
			}
		} while (notAWinner);

		std::cout.rdbuf(oldCoutStreamBuf);
		return oss.str();
	}

	void SetUp() override {}
	void TearDown() override {}
};


TEST_F(GameFixture, gameTest) {

	for (int seed = 1; seed < 10; seed++) {

		Game game;
		GameRefactor refactorGame;


		string result = playGame(game, seed);
		string result_r = playGame(refactorGame, seed);

		EXPECT_EQ(result, result_r);
	}

}