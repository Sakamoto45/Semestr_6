#include <iostream>

class Shape
{
private:
    int num_;
    // string type; просто в функции выводить.
public:
    Shape(/* args */) {};
    virtual ~Shape() {};
    // номер фигуры считается через static переменную.
    void PrintInfo() {
        std::cout << Name() << " #" << getNum() << " with area = " << Area() << std::endl;
    }

    virtual const double Area()const = 0;
    virtual const char* Name()const = 0;
    const int getNum() {return(num_);}
    void setNum(const int num) {num_ = num;}

    // функция сравнения по площади
    friend int operator< (const Shape& s1, const Shape& s2) {return s1.Area() < s2.Area();}
    friend int operator> (const Shape& s1, const Shape& s2) {return s1.Area() > s2.Area();}
    friend int operator<= (const Shape& s1, const Shape& s2) {return s1.Area() <= s2.Area();}
    friend int operator>= (const Shape& s1, const Shape& s2) {return s1.Area() >= s2.Area();}
};

class Circle : public Shape
{
private:
    static int count_;
    double r_;
public:
    Circle(double r) : r_{r} {
        count_++;
        setNum(count_);
    }
    ~Circle() {}
};




int main() {

// слйчайно задать массив прямоугольников, кругов

// вывести инфу

// сортировать

// вывести инфу

// сдохнуть не освобождая память


    return 0;
}