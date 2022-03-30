

#include <iostream>
using namespace std;

class fraction
{
private:
	int numerator;
	int denominator;
public:
	fraction()
	{
		numerator = 0;
		denominator = 1;
	}
	~fraction()
	{
		numerator = 0;
		denominator = 1;
	}
	void rutgon()
	{
		fraction a;
		if (this->numerator < 0)
		{
			a.numerator = -this->numerator;
		}
		else
		{
			a.numerator = this->numerator;
		}
		if (this->denominator < 0)
		{
			a.denominator = -this->denominator;
		}
		else
		{
			a.denominator = this->denominator;
		}
		if (a.numerator == 0)
		{
			return;
		}
		else {
			while (a.numerator != a.denominator)
			{
				if (a.denominator > a.numerator)
				{
					a.denominator -= a.numerator;
				}
				else
				{
					a.numerator -= a.denominator;
				}
			}
			this->numerator /= a.numerator;
			this->denominator /= a.denominator;
		}
	}
	friend istream& operator>>(istream& is, fraction& obj)
	{
		cout << "nhap tu so:";
		is >> obj.numerator;
		cout << "nhap mau:";
	pointreturn:
		is >> obj.denominator;
		if (obj.denominator == 0)
		{
			goto pointreturn;
		}
		return is;
	}

	friend ostream& operator<<(ostream& os, fraction& obj)
	{
		if ((obj.numerator == 0) || (obj.numerator % obj.denominator == 0))
		{
			os << obj.numerator;
		}
		else if ((obj.denominator < 0 && obj.numerator < 0) || (obj.denominator < 0 && obj.numerator>0))
		{
			os << -obj.numerator << "/" << -obj.denominator;
		}
		else
		{
			os << obj.numerator;
			cout << "/";
			os << obj.denominator;
		}
		return os;
	}
	fraction operator+(fraction& a)
	{
		fraction c;
		c.numerator = this->numerator * a.denominator + this->denominator * a.numerator;
		c.denominator = this->denominator * a.denominator;
		c.rutgon();
		return c;
	}
	friend fraction operator-(fraction a, fraction b)
	{
		fraction c;
		c.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
		c.denominator = a.denominator * b.denominator;
		c.rutgon();
		return c;
	}

	friend fraction operator*(fraction a, fraction b)
	{
		fraction c;
		c.numerator = a.numerator * b.numerator;
		c.denominator = a.denominator * b.denominator;
		c.rutgon();
		return c;
	}
	fraction operator/(fraction& b)
	{
		fraction c;
		if (b.numerator == 0)
		{
			cout << "dap an sai, khong thu hien duoc\n";
		}
		else
		{
			c.numerator = this->numerator * b.denominator;
			c.denominator = this->denominator * b.numerator;
			c.rutgon();
			return c;
		}
	}
};


int main()
{
	fraction a;
	cout << "nhap phan so thu nhat" << endl;
	cin >> a;
	cout << "nhap phan so thu 2:\n";
	fraction b;
	cin >> b;
	cout << "hai phan so vua nhap:\n";
	a.rutgon();
	cout << a << endl;
	b.rutgon();
	cout << b << endl;
	fraction c = a + b;
	cout << "tong:" << a << " + " << b << " = " << c << endl;
	c = a - b;
	cout << "hieu:" << a << " - " << b << " = " << c << endl;
	c = a * b;
	cout << "tich:" << a << " * " << b << " = " << c << endl;
	c = a / b;
	cout << "thuong:" << a << " / " << b << " = " << c << endl;
	return 0;
}