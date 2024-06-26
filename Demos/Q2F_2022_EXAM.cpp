#include <iostream>
using namespace std;

class AbsClass {
protected:
    int num;

public:
    AbsClass() { num = 1; }
    virtual int getNum() {
        num += 2;
        return num;
    }
    virtual ~AbsClass() {};
};

class ConA : public AbsClass {
public:
    int getNum() {
        num += 5;
        return num;
    }
};

void TesterA(AbsClass a) {
    cout << "NA = " << a.getNum() << endl;
}

void TesterB(AbsClass *b) {
    cout << "NB = " << b->getNum() << endl;
}

int main(void) {
    ConA m;
    for (int i = 0; i < 4; i++)
        (i % 2 == 0) ? TesterA(m) : TesterB(&m);
    return 0;
}