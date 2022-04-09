#include <iostream>
class color
{
    int *c;
public:
    color() {
        c = new int;
        std::cout << "r color" << std::endl;
    };
    virtual ~color() {
        std::cout << "d color" << std::endl; delete c;
    };
    virtual void print_color() const = 0;
};

class red : public color
{
    int *rc;
public:
    red() {
        rc = new int;
        std::cout << "r red" << std::endl;
    };
    ~red() {
        std::cout << "d red" << std::endl; delete rc;
    };
    void print_color() const override {
        std::cout << *rc << std::endl;
    }
};

class brightred : public red
{
    int* brc;
public:
    brightred() {
        brc = new int;
        std::cout << "r brightred" << std::endl;
    };
    ~brightred() {
        std::cout << "d brightred" << std::endl; delete brc;
    };
};


void main()
{
    color *palette[2];
    palette[0] = new red;
    palette[1] = new brightred;
    palette[2] = new red;

    for (int i = 0; i < 3; i++)
        palette[i]->print_color();

    for (int i = 0; i < 3; i++)
        delete palette[i];
}