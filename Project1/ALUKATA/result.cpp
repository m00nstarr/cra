#pragma once

class Result
{
    int status = -1;
    int result = 65535;

    const int FAIL_RESULT = 65535;
    const int NO_OPERAND_1 = 1;
    const int NO_OPERAND_2 = 2;
    const int SUCCESS = 0;
    const int NO_RESULT = -1;

    //status -1 : ��� �ȳ���
    //status 0 : ����
    //status 1 : Operand1�� �߸���
    //status 2 : Operand2�� �߸���
    //status 3 : OPCODE�� �߸��Ǿ���

    //result 65535 : ��� ����

public:
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