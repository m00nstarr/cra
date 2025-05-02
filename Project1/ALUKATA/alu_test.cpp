#include "gmock/gmock.h"
#include "alu.cpp";
#include "result.cpp";

using namespace testing;

class ALUFixture : public Test {
public:
	ALU alu;
	Result result;
protected:

	void SetUp() override {

	}
	void TearDown() override {

	}

};


TEST_F(ALUFixture, ADDTest) {

	alu.setOperand1(10);
	alu.setOperand2(20);
	alu.setOPCODE("ADD");

	alu.enableSignal(&result);

	EXPECT_EQ(30, result.getResult());
	EXPECT_EQ(0, result.getStatus());
}

TEST_F(ALUFixture, MULTest) {

	alu.setOperand1(10);
	alu.setOperand2(20);
	alu.setOPCODE("MUL");

	alu.enableSignal(&result);

	EXPECT_EQ(200, result.getResult());
	EXPECT_EQ(0, result.getStatus());
}