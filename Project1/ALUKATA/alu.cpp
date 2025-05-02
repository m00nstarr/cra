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

    void enableSignal(Result* r) {
        if (OPCODE == "ADD" && OPCODE != "MUL" && OPCODE != "SUB") {
            if (operand1 != -1 && operand2 != -1) {
                int result = operand1 + operand2;
                r->setResult(result);
                r->setStatus(0);
            }
            else if (operand1 == -1) {
                r->setResult(65535);
                r->setStatus(1);
            }
            else if (operand2 == -1) {
                r->setResult(65535);
                r->setStatus(2);
            }
        }
        else if (OPCODE != "ADD" && OPCODE == "MUL" && OPCODE != "SUB") {
            if (operand1 != -1 && operand2 != -1) {
                int result = operand1 * operand2;
                r->setResult(result);
                r->setStatus(0);
            }
            else if (operand1 == -1) {
                r->setResult(65535);
                r->setStatus(1);
            }
            else if (operand2 == -1) {
                r->setResult(65535);
                r->setStatus(2);
            }
        }
        else if (OPCODE != "ADD" && OPCODE != "MUL" && OPCODE == "SUB") {
            if (operand1 != -1 && operand2 != -1) {
                int result = operand1 - operand2;
                r->setResult(result);
                r->setStatus(0);
            }
            else if (operand1 == -1) {
                r->setResult(65535);
                r->setStatus(1);
            }
            else if (operand2 == -1) {
                r->setResult(65535);
                r->setStatus(2);
            }
        }
        else {
            r->setResult(65535);
            r->setStatus(3);
        }
    }
};