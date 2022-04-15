#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <array>

using namespace std;

class Shape
{
private:
    int num_;
public:
    Shape() {};
    virtual ~Shape() {};
    // номер фигуры считается через static переменную.
    void PrintInfo() {
        std::cout << Name() << " #" << getNum() << "\twith area = " << Area() << std::endl;
    }

    virtual double Area() const = 0;
    virtual const char* Name() const = 0;
    int getNum() {return(num_);}
    void setNum(const int num) {num_ = num;}

    // функция сравнения по площади
    friend int operator< (const Shape& s1, const Shape& s2) {return s1.Area() < s2.Area();}
};

class Circle : public Shape
{
private:
    static int count_;
    double r_;

public:
    Circle(double r) : r_{r} {
        setNum(++count_);
    }
    ~Circle() {}

    double Area() const override{
        return M_PI * r_ * r_;
    }

    const char* Name() const override{
        return "Circle";
    }
};

class Rectangle : public Shape
{
private:
    static int count_;
    double a_;
    double b_;

public:
    Rectangle(double a, double b) : a_{a}, b_{b} {
        setNum(++count_);
    }
    ~Rectangle() {}

    double Area() const override{
        return a_ * b_;
    }

    const char* Name() const override{
        return "Rectangle";
    }
};

class Square : public Rectangle
{
private:
    static int count_;
public:
    Square(double a) : Rectangle{a, a} {
        setNum(++count_);
    }
    ~Square() {}

    const char* Name() const override{
        return "Square";
    }
};

int Circle::count_ = 0;
int Rectangle::count_ = 0;
int Square::count_ = 0;



int main() {
    srand(time(nullptr));

// случайно задать массив прямоугольников, кругов, квадратов
    array<Shape*, 10> shapes;
    for (int i = 0; i < 10; i++) {
        switch (rand() % 3)
        {
        case 0:
            shapes[i] = new Circle((double)rand() / RAND_MAX * 10);
            break;
        
        case 1:
            shapes[i] = new Rectangle((double)rand() / RAND_MAX * 10, (double)rand() / RAND_MAX * 10);
            break;
        
        case 2:
            shapes[i] = new Square((double)rand() / RAND_MAX * 10);
            break;

        default:
            break;
        }
    }

// вывести инфу
    cout << "\nArray of shapes:\n";
    for (auto shape : shapes) {
        shape->PrintInfo();
    }

// сортировать 
    sort(shapes.begin(), shapes.end(), [](Shape* a, Shape* b) { return *a < *b; });

// вывести инфу
    cout << "\nSorted array of shapes:\n";
    for (auto shape : shapes) {
        shape->PrintInfo();
    }

    return 0;
}