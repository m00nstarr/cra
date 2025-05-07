#pragma once

class Result
{
    int status = -1;
    int result = 65535;

public:
    static const int FAIL_RESULT = 65535;
    static const int NO_OPERAND_1 = 1;
    static const int NO_OPERAND_2 = 2;
    static const int NO_OPCODE = 3;
    static const int SUCCESS = 0;
    static const int NO_RESULT = -1;

    void setStatus(int status) {
        this->status = status;
    }

    void setResult(int result) {
        this->result = result;
    }

    int getStatus() {
        return status;
    }

    int getResult() {
        return result;
    }
};