#include "stdafx.h"

#include <iostream>

#include <string>
using namespace std;

namespace lp 
{
	class Geometric2D
	{
	private:
		string name;

	public:
		Geometric2D() {}

		Geometric2D(string name)
		{
			this->name = name;
		}

		string getName()
		{
			return name;
		}

		void setName(string name)
		{
			this->name = name;
		}
	};

	class Ponto : public Geometric2D
	{
	private:
		double x;
		double y;

	public:
		Ponto() {}

		Ponto(double x, double y)
		{
			this->x = x;
			this->y = y;
		}

		double getX()
		{
			return x;
		}

		double getY()
		{
			return y;
		}

		virtual void print()
		{
			cout << x << "," << y;
		}
	};

	class Ponto3D : public Ponto
	{
	private:
		double z;

	public:
		Ponto3D(double x, double y, double z) : Ponto(x,y)
		{
			this->z = z;
		}

		double getZ()
		{
			return z;
		}

		virtual void print()
		{
			Ponto::print();
			cout << "," << z;
		}

	};
}

using namespace lp;

int main()
{
	Ponto P(1, 2);
	P.print();
	cout << endl;
	P.setName("Forma 2D");
	cout << "Name: " << P.getName() << endl;

	Ponto3D P3(1, 2, 3);
	P3.print();
	cout << endl;
	P3.setName("Forma3D");
	cout << "Name: " << P3.getName() << endl;

	getchar();

	return 0;
}