// ConsoleApplication2.cpp : Define o ponto de entrada para a aplicação de console.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Complexo {
private:
	double real;
	double imag;

public:
	Complexo(double real, double imag);
	~Complexo();

	double getReal();
	void setReal(double real);

	double getImag();
	void setImag(double imag);

	Complexo operator+(Complexo x);
	Complexo operator+(double x);
	Complexo& operator+=(Complexo c);

	Complexo operator*(Complexo x);
	bool operator==(Complexo c);
	bool operator!=(Complexo c);

	double operator[](int i);

	friend Complexo operator+(double d, Complexo c);

	friend ostream& operator<<(ostream& o, Complexo c);

	void print();
};

Complexo::Complexo(double real, double imag)
{
	this->real = real;
	this->imag = imag;
}

Complexo::~Complexo()
{
	//std::cout << __FUNCTION__ << "\n";
}

double Complexo::getReal()
{
	return real;
}

void Complexo::setReal(double real)
{
	this->real = real;
}

double Complexo::getImag()
{
	return imag;
}

void Complexo::setImag(double imag)
{
	this->imag = imag;
}

Complexo Complexo::operator+(Complexo x)
{
	Complexo y(0, 0);

	y.real = this->real + x.real;
	y.imag = this->imag + x.imag;

	return y;
}

Complexo Complexo::operator+(double x)
{
	Complexo y(0, 0);

	y.real = this->real + x;
	y.imag = this->imag;

	return y;
}

Complexo& Complexo::operator+=(Complexo c) {
	this->real += c.real;
	this->imag += c.imag;
	return *this;
}

Complexo Complexo::operator*(Complexo x)
{
	Complexo y(0, 0);

	y.real = this->real * x.real - this->imag * x.imag;
	y.imag = this->real * x.imag + this->imag * x.real;

	return y;
}

bool Complexo::operator==(Complexo c)
{
	return this->real == c.getReal() && this->imag == c.getImag();
}

bool Complexo::operator!=(Complexo c)
{
	return !(*this == c);
}

double Complexo::operator[](int i)
{
	if (i == 0)
	{
		return this->real;
	}
	else if (i == 1)
	{
		return this->imag;
	}
	else
	{
		return 0;
	}
}

Complexo operator+(double d, Complexo c)
{
	return c + d;
}

ostream& operator<<(ostream& o, Complexo c)
{
	double i = c.getImag();
	o << "(" << c.getReal() << (i < 0 ? "" : "+") << i << "i)";
	return o;
}

void Complexo::print()
{
	std::cout << "(" << this->real << "+" << this->imag << "i)\n";
}


int main()
{
	Complexo c1(1, -20), c2(3, 5), c3(0, 0), c4(0,0);
	c1 += c2;
	c3 = c1 + c2;
	c4 = c1 + 10;
	c4 = 10 + c1;

	cout << "C1" << c1 << "\n"
		<< "C2" << c2 << "\n"
		<< "C3" << c3 << "\n"
		<< "C4" << c4 << "\n";

	Complexo f1(10, 20), f2(11, 22);
	if (f1 == f2)
	{
		cout << "F1 == F2\n";
	}
	if (f1 != f2)
	{
		cout << "F1 != F2\n";
	}

	cout << "F1[0] = " << f1[0] << " " << "F1[1] = " << f1[1] << "\n";

	system("pause");
    return 0;
}
