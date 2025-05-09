#pragma once
#include "game.h"

class Player {

public:
	Player(const string& name) : name(name) {
		place = 0;
		purse = 0;
		inPenaltyBox = false;
	};

	string getName() const { return name; }
	int getPlace() const { return place; }
	int getPurse() const { return purse; }
	bool getPenaltyBox() const { return inPenaltyBox; }

	void setPlace(int place) { this->place = place; }
	void setPurse(int purse) { this->purse = purse; }
	void setPenalty(bool penalty) { this->inPenaltyBox = penalty; }

	void action_w_rolling(int roll)
	{
		place += roll;

		if (place > 11) {
			place -= 12;
		}

		cout << name << "'s new location is " << place << endl;
	}

	void action_w_correctAns()
	{
		cout << "Answer was correct!!!!" << endl;
		purse += 1;
		cout << name  << " now has " << purse << " Gold Coins." << endl;
	}

	void action_w_wrongAns()
	{
		cout << "Question was incorrectly answered" << endl;
		cout << name + " was sent to the penalty box" << endl;
		inPenaltyBox = true;
	}

private:
	string name;
	int place;
	int purse;
	bool inPenaltyBox;
};


class GameRefactor : public IGame {
public:
	GameRefactor() : currentPlayer{ 0 } {
		for (int i = 0; i < 50; i++) {
			string str1 = "Pop Question " + to_string(i);
			popQuestions.push_back(str1);

			string str2 = "Science Question " + to_string(i);
			scienceQuestions.push_back(str2);

			string str3 = "Sports Question " + to_string(i);
			sportsQuestions.push_back(str3);

			rockQuestions.push_back(createRockQuestion(i));
		}
	}

	string createRockQuestion(int index) {
		string indexStr = "Rock Question " + to_string(index);
		return indexStr;
	}

	bool isPlayable() {
		return (howManyPlayers() >= 2);
	}

	bool add(string playerName) {
		players.push_back(Player{ playerName });
		cout << playerName << " was added" << endl;
		cout << "They are player number " << players.size() << endl;
		return true;
	}

	int howManyPlayers() {
		return (int)players.size();
	}

	void rolling(int roll) {
		cout << players[currentPlayer].getName() << " is the current player" << endl;
		cout << "They have rolled a " << roll << endl;

		if (players[currentPlayer].getPenaltyBox() && (roll % 2 == 0)) {
			cout << players[currentPlayer].getName() << " is not getting out of the penalty box" << endl;
			isGettingOutOfPenaltyBox = false;
			return;
		}

		if (players[currentPlayer].getPenaltyBox()) {
			isGettingOutOfPenaltyBox = true;
			cout << players[currentPlayer].getName() << " is getting out of the penalty box" << endl;
		}

		players[currentPlayer].action_w_rolling(roll);
		cout << "The category is " << currentCategory() << endl;
		askQuestion();
		
		return;
	}

	bool wasCorrectlyAnswered() {
		if (players[currentPlayer].getPenaltyBox()) {
			if (isGettingOutOfPenaltyBox) {
				players[currentPlayer].setPenalty(false);
				players[currentPlayer].action_w_correctAns();
				bool winner = didPlayerWin();
				nextPlayer();
				return winner;
			}
			nextPlayer();
			return true;
		}
		players[currentPlayer].action_w_correctAns();
		bool winner = didPlayerWin();
		nextPlayer();
		return winner;
	}

	bool wrongAnswer() {
		if (players[currentPlayer].getPenaltyBox()) {
			if (isGettingOutOfPenaltyBox) {
				players[currentPlayer].action_w_wrongAns();
				nextPlayer();
				return true;
			}
			nextPlayer();
			return true;
		}
		players[currentPlayer].action_w_wrongAns();
		nextPlayer();
		return true;
	}

	void nextPlayer()
	{
		currentPlayer++;
		if (currentPlayer == players.size()) currentPlayer = 0;
	}


private:
	vector<Player> players;

	//int places[6];
	list<string> popQuestions;
	list<string> scienceQuestions;
	list<string> sportsQuestions;
	list<string> rockQuestions;

	int currentPlayer;
	bool isGettingOutOfPenaltyBox;

	void askQuestion() {
		if (currentCategory() == "Pop") {
			cout << popQuestions.front() << endl;
			popQuestions.pop_front();
		}

		if (currentCategory() == "Science") {
			cout << scienceQuestions.front() << endl;
			scienceQuestions.pop_front();
		}

		if (currentCategory() == "Sports") {
			cout << sportsQuestions.front() << endl;
			sportsQuestions.pop_front();
		}

		if (currentCategory() == "Rock") {
			cout << rockQuestions.front() << endl;
			rockQuestions.pop_front();
		}
	}

	string currentCategory() {

		int currentPlace = players[currentPlayer].getPlace();
		
		if (currentPlace == 0) return "Pop";
		if (currentPlace == 4) return "Pop";
		if (currentPlace == 8) return "Pop";
		if (currentPlace == 1) return "Science";
		if (currentPlace == 5) return "Science";
		if (currentPlace == 9) return "Science";
		if (currentPlace == 2) return "Sports";
		if (currentPlace == 6) return "Sports";
		if (currentPlace == 10) return "Sports";
		
		return "Rock";
	}

	bool didPlayerWin() {
		return !(players[currentPlayer].getPurse() == 6);
	}
};

