#include <iostream>
using namespace std;

class A {
private:
    int first_value;
    
public:
    A(int i_ = 0) : first_value(i_) {}
    A(const A& other) : first_value(other.first_value) {}
    A(A&& other) : first_value(other.first_value) {
        other.first_value = 0;
    }
    ~A() {}

    A& operator =(A other) {
        first_value = other.first_value;
        return *this;
    }
};

class B : public A {
private:
    int second_value;

public:
    B(int j_ = 0) : second_value(j_) {}
    B(int i_, int j_) : A(i_), second_value(j_) {}
    B(const B& other) : A(other), second_value(other.second_value) {}
    B(B&& other) : A(move(other)), second_value(other.second_value) {
        other.second_value = 0;
    }
    ~B() {}

    B& operator =(B other) {
        A::operator=(other);
        second_value = other.second_value;
        return *this;
    }
};




