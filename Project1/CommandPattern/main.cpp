#include <iostream>
using namespace std;

class Box {
public:
    Box()
        :position{ 5 }
    {
    }

    int getPos() const {
        return position;
    }
    void setPos(int x) {
        if (x < 0 || x > 10) return;
        position = x;
    }
    void LeftMove() {
        setPos(getPos() - 1);
    }

    void RightMove() {
        setPos(getPos() + 1);
    }

    void Show() {
        for (int x = 0; x <= 10; x++) {
            if (getPos() == x) {
                cout << "#";
            }
            else {
                cout << "-";
            }
        }
        cout << endl;
    }

private:
    int position;
};


class Command {
public :
    virtual ~Command() {};
    virtual void execute() = 0;
};

class leftMove : public Command {
public:
    leftMove(Box &box) : box{box}{}

    void execute() override {
        box.LeftMove();
        return;
    }

private:
    Box& box;
};

class rightMove : public Command {
public:
    rightMove(Box& box) : box{ box } {}

    void execute() override {
        box.RightMove();
        return;
    }

private:
    Box& box;
};

class showBox : public Command {
public:
    showBox(Box& box) : box{ box } {}

    void execute() override {
        box.Show();
        return;
    }

private:
    Box& box;
};

int main() {
    Box box{};
    leftMove left{ box };
    rightMove right{ box };
    showBox show{ box };

    while (true) {
        cout << "명령어 입력: " << endl;
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            left.execute();
        }
        if (cmd == 2) {
            right.execute();
        }
        show.execute(); // showbox.execute();
    }
}