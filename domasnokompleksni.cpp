#include<iostream>
#include<cmath>
using namespace std;

class Complex
{
    float real;
    float imaginary;
public:
    Complex(const Complex& orig)
    {
        this->real = orig.real;
        this->imaginary = orig.imaginary;
    }
    Complex()
    {
        real=1.0f;
        imaginary=0.0f;
    }
    Complex(float x)
    {
        real = x;
        imaginary = 0.0f;
    }
    Complex(float x, float y)
    {
        real = x;
        imaginary = y;
    }
    Complex operator-()
    {
        Complex r;
        r.real = (-1.0f)*real;
        r.imaginary = (-1.0f)*imaginary;
        return r;
    }
    Complex operator+(Complex other)
    {
        Complex r;
        r.real = this->real + other.real;
        r.imaginary = this->imaginary + other.imaginary;
        return r;
    }
    Complex operator-(Complex other)
    {
        Complex r;
        r.real = this->real - other.real;
        r.imaginary = this->imaginary - other.imaginary;
        return r;
    }
    Complex operator*(Complex other)
    {
        Complex r;
        r.real = this->real*other.real - this->imaginary*other.imaginary;
        r.imaginary = this->real*other.imaginary + this->imaginary*other.real;
        return r;
    }
    Complex operator~()
    {
        Complex r;
        r.real = this->real;
        r.imaginary = this->imaginary*(-1);
        return r;
    }
    Complex operator/(Complex other)
    {
        Complex r;
        float kolicnik = pow(other.real,2) + pow(other.imaginary,2);
        r.real = ((this->real * other.real) + (this->imaginary * other.imaginary))/kolicnik;
        r.imaginary = ((this->imaginary*other.real) - (this->real*other.imaginary))/kolicnik;
        return r;
    }
    Complex& operator=(const Complex& other)
    {
        if (this != &other)
        {
            this->real = other.real;
            this->imaginary = other.imaginary;
        }
        return *this;
    }
    bool operator==(Complex other)
    {
        if (this->real == other.real && this->imaginary == other.imaginary)
        {
            return true;
        }
        return false;
    }
    bool operator!=(Complex other)
    {
        if (this->real != other.real || this->imaginary != other.imaginary)
        {
            return true;
        }
        return false;
    }
    float operator!()
    {
        return sqrt(pow(this->imaginary,2) + pow(this->real,2));
    }
    Complex operator++()
    {
        this->real++;
        return *this;
    }
    Complex operator++(int)
    {
        Complex r(*this);
        this->imaginary++;
        return r;
    }
    Complex operator--()
    {
        this->real--;
        return *this;
    }
    Complex operator--(int)
    {
        Complex r(*this);
        this->imaginary--;
        return r;
    }
    void print()
    {
        if (imaginary >= 0)
        {
            cout << real << "+" << imaginary << "i" << '\n';
        }
        else
        {
            cout << real << imaginary << "i" << '\n';
        }
    }
};

int main()
{
    Complex a(7,5);
    Complex b;
    cout << "unarno - ";
    b =- a;
    b.print();

    Complex a1(5,3);
    Complex a2(6,5);
    Complex a3;
    a3 = a1+a2;
    cout << "+ ";
    a3.print();

    Complex a4=a2-a1;
    cout << "binarno - ";
    a4.print();

    Complex a5=a2*a1;
    cout << "* ";
    a5.print();

    Complex a6=~a2;
    cout << "~ ";
    a6.print();

    Complex a7=a2/a1;
    cout << "/ ";
    a7.print();

    Complex a8=a1;
    cout << "= ";
    a8.print();

    if (a8==a1)
    {
        cout << "test na ==" << '\n';
    }

    if (a7!=a1)
    {
        cout << "test na !=" << '\n';
    }

    float a9 = !a1;
    cout << "! ";
    cout << a9 << '\n';

    ++a1;
    cout << "prefix ++ ";
    a1.print();

    a1++;
    cout << "postfix ++ ";
    a1.print();

    --a1;
    cout << "prefix -- ";
    a1.print();

    a1--;
    cout << "postfix -- ";
    a1.print();

    return 0;
}