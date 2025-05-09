#include <iostream>
#include <list>
#include <vector>
#include <string>

class Question {
public:
	virtual std::string createQuestion(int) = 0;
};

class PopQuestion : public Question {
public:
	std::string createQuestion(int idx) {
		std::string question = "Pop Question " + std::to_string(idx);
		return question;
	}

};

class ScienceQuestion : public Question {
public:
	std::string createQuestion(int idx) {
		std::string question = "Science Question " + std::to_string(idx);
		return question;
	}
};

class SportsQuestion : public Question {
public:
	std::string createQuestion(int idx) {
		std::string question = "Sports Question " + std::to_string(idx);
		return question;
	}
};

class RockQuestion : public Question {
	std::string createQuestion(int idx) {
		std::string question = "Rock Question " + std::to_string(idx);
		return question;
	}
};

class QuestionFactory {

};