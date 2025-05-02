#include <string>
#include "result.cpp"

class ALU
{
	int operand1 = -1;
	int operand2 = -1;
	std::string OPCODE = "";

public:
	void setOperand1(int operand1) {
		this->operand1 = operand1;
	}

	void setOperand2(int operand2) {
		this->operand2 = operand2;
	}

	void setOPCODE(std::string OPCODE) {
		this->OPCODE = OPCODE;
	}

	int calculate(int operand1, int operand2, const std::string& opcode) {

		if (opcode == "ADD") {
			return operand1 + operand2;
		}
		else if (opcode == "SUB") {
			return operand1 - operand2;
		}
		else if (opcode == "MUL") {
			return operand1 * operand2;
		}
	}


	void enableSignal(Result* r) {

		if (isValidOperand() == false) {
			if (operand1 == -1) {
				r->setResult(65535);
				r->setStatus(1);
				return;
			}
			r->setResult(65535);
			r->setStatus(2);
			return;
		}

		if (isValidOpcode() == false) {
			r->setResult(65535);
			r->setStatus(3);

			return;
		}

		int result = 0;
		r->setResult(calculate(operand1, operand2, OPCODE));
		r->setStatus(0);
		return;
	}
	bool isValidOperand()
	{
		return operand1 != -1 && operand2 != -1;
	}

	bool isValidOpcode()
	{
		return OPCODE == "ADD" || OPCODE == "MUL" || OPCODE == "SUB";
	}
};