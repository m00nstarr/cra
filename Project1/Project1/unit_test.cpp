#include "gtest/gtest.h"
#include "tennis.cpp"

struct TestSet {
    int score1, score2;
    std::string result;
};

TestSet arr[33] = {
{0, 0, "Love-All"},
{ 1, 1, "Fifteen-All" },
{ 2, 2, "Thirty-All" },
{ 3, 3, "Deuce" },
{ 4, 4, "Deuce" },

{ 1, 0, "Fifteen-Love" },
{ 0, 1, "Love-Fifteen" },
{ 2, 0, "Thirty-Love" },
{ 0, 2, "Love-Thirty" },
{ 3, 0, "Forty-Love" },
{ 0, 3, "Love-Forty" },
{ 4, 0, "Win for player1" },
{ 0, 4, "Win for player2" },

{ 2, 1, "Thirty-Fifteen" },
{ 1, 2, "Fifteen-Thirty" },
{ 3, 1, "Forty-Fifteen" },
{ 1, 3, "Fifteen-Forty" },
{ 4, 1, "Win for player1" },
{ 1, 4, "Win for player2" },

{ 3, 2, "Forty-Thirty" },
{ 2, 3, "Thirty-Forty" },
{ 4, 2, "Win for player1" },
{ 2, 4, "Win for player2" },

{ 4, 3, "Advantage player1" },
{ 3, 4, "Advantage player2" },
{ 5, 4, "Advantage player1" },
{ 4, 5, "Advantage player2" },
{ 15, 14, "Advantage player1" },
{ 14, 15, "Advantage player2" },

{ 6, 4, "Win for player1" },
{ 4, 6, "Win for player2" },
{ 16, 14, "Win for player1" },
{ 14, 16, "Win for player2" },
};

TEST(Score, sameScore) {
    
    Tennis tennisGame;

    for (auto testItem : arr) {
        
        if (testItem.score1 == testItem.score2) {
            std::string ret = tennisGame.getCurrentScore(testItem.score1, testItem.score2);
            EXPECT_EQ(ret, testItem.result);
        }
    }
}

TEST(Score, greaterThanFour) {

    Tennis tennisGame;

    for (auto testItem : arr) {

        if (testItem.score1 >= 4 ||  testItem.score2 >= 4) {
            std::string ret = tennisGame.getCurrentScore(testItem.score1, testItem.score2);
            EXPECT_EQ(ret, testItem.result);
        }
    }
}


TEST(Score, elseCase) {
    Tennis tennisGame;

    for (auto testItem : arr) {

        if (testItem.score1 == testItem.score2)
            continue;
        if (testItem.score1 >= 4 || testItem.score2 >= 4)
            continue;
        
        std::string ret = tennisGame.getCurrentScore(testItem.score1, testItem.score2);
        EXPECT_EQ(ret, testItem.result);
    }
}