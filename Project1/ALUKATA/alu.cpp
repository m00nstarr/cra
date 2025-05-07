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

		if (opcode == "ADD")
			return operand1 + operand2;

		if (opcode == "SUB") 
			return operand1 - operand2;
		
		if (opcode == "MUL")
			return operand1 * operand2;

	}


	void enableSignal(Result* r) {

		if (isValidOperand() == false) {
			
			if (operand1 == -1) {
				r->setStatus(Result::NO_OPERAND_1);
				return;
			}

			r->setStatus(Result::NO_OPERAND_2);
			return;
		}

		if (isValidOpcode() == false) {
			r->setStatus(Result::NO_OPCODE);
			return;
		}

		r->setResult(calculate(operand1, operand2, OPCODE));
		r->setStatus(Result::SUCCESS);
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