#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Wheel {

private:
	const int PASS = 1;
	const int FAIL = 0;
	int isUsed[4][15] = { 0, };
	int secondChance[4] = { -1, -1, -1, -1 };
	int firstChance[4] = { 0, };
	int comboCnt = 0;

public:
	vector<string> board;
	string userdata;

	Wheel(const vector<string>& strs, const string& userdata) : board(strs), userdata(userdata) {

	}

	int getPrice() {
		int sum = 0;

		//하나씩 처리
		//26글자 for 돌면서 퀴즈 참석자가 하나씩 시도를 하는 것
		for (char userData : userdata) {

			//1. 2000 달러 찬스를 얻었는지 검사
			for (int row = 0; row < board.size(); row++) {
				if (secondChance[row] == -1) {
					continue;
				}

				if (isSecondChance(row, userDataIdx)) {
					sum += 2000;
				}

				secondChance[row] = -1;
			}

			int passCnt = 0;
			int flag = 0;
			//int flag = checkChar(userDataIdx, passCnt, sum);
			for (int row = 0; row < board.size(); row++) {
				for (int col = 0; col < board[row].size(); col++) {
					if (isUsed[row][col] == 1) continue;

					if (board[row][col] == userdata[userDataIdx]) {

						//Let's First 점수인지 확인한다.
						if (firstChance[row] == 0 && col == 0) {
							sum += 1000;
							firstChance[row] = 1;
							secondChance[row] = row;
						}
						else if (firstChance[row] == 0 && col != 0) {
							firstChance[row] = 1;
						}

						//used배열
						isUsed[row][col] = 1;

						//해당 문자를 _로 바꿔버린다.
						board[row][col] = '_';
						flag = 1;

						//동일한 문자 개수를 Counting한다.
						passCnt++;
					}
				}
			}
			if (flag == PASS) {
				comboCnt++;
				sum += (comboCnt * 100) * passCnt;
				continue;
			}

			initCombo();
		}

		cout << "$" << sum << endl;
		return sum;
	}

	bool isPass(int row, int col, int userDataIdx)
	{
		return board[row][col] == userdata[userDataIdx];
	}

	bool isSecondChance(int row, int i)
	{
		for (int col = 0; board[row].size(); col++) {
			if (isUsed[secondChance[row]][col] == 0 && board[secondChance[row]][col] == userdata[i]) {
				return true;
			}
		}

		return false;
	}

	void initCombo() {
		comboCnt = 0;
		for (int i = 0;i < 4; i++) {
			secondChance[i] = -1;
		}

		return;
	}

	int checkChar(int userDataIdx, int &passCnt, int &sum) {

		int result = FAIL; 

		for (int row = 0; row < board.size(); row++) {
			for (int col = 0; col < board[row].size(); col++) {
				if (isUsed[row][col] == 1) continue;

				if (isPass(row, col, userDataIdx)) {
					if (firstChance[row] == 0) {
						if (col == 0) {
							sum += 1000;
							secondChance[row] = 1;
						}

						firstChance[row] = 1;
					}

					isUsed[row][col] = 1;
					board[row][col] = '_';
					result = PASS;
					passCnt++;
				}
			}
		}

		return result;
	}
};