#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

//复数的结构：实部和虚部
struct Plural{
	double real;
	double imag;
	Plural(double r, double i) : real(r), imag(i){}
};

Plural &Plus(const Plural & p1, const Plural &p2)
{
	return Plural(p1.real + p2.real, p1.imag + p2.imag);
}


Plural &Minus(const Plural &p1, const Plural &p2)
{
	return Plural(p1.real - p2.real, p1.imag - p2.imag);
}

//复数（a+bi）*（c+di）= （ac-bd）+（ad+bc）i
Plural &Multi(const Plural &p1, const Plural &p2)
{
	return Plural(p1.real*p2.real - p1.imag*p2.imag, p1.real*p2.imag + p1.imag*p2.real);
}

//复数（a+bi）/（c+di）= （ac+bd）/（c^2+d^2）+（bc-ad）/（c^2+d^2）i
Plural &Div(const Plural &p1, const Plural &p2)
{
	return Plural((p1.real*p2.real + p1.imag*p2.imag) / (p2.real*p2.real + p2.imag*p2.imag), 
		(p1.imag*p2.real - p1.real*p2.imag) / (p2.real*p2.real + p2.imag*p2.imag));
}

//复数的幂运算，利用乘法实现
Plural &Pow(Plural &p, int n)
{
	for (int i = 1; i < n; i++)
		p = Multi(p, p);
	return p;
}

//复数指数运算e+fi = e^(a+bi) = e^a * e^bi = e^a * (cosb + i sinb)
Plural &Exp(const Plural &p)
{
	double tmp = exp(p.real);
	return Plural(tmp*cos(p.imag), tmp*sin(p.imag));
}

//复数对数运算e+fi = ln(a+bi) = ln(sqrt(a^2+b^2)) + arctg(b/a) i
Plural &Log(const Plural &p)
{
	double tmp = log(sqrt(p.real*p.real + p.imag*p.imag));
	return Plural(tmp, atan2(p.imag, p.real));
}

//复数正弦运算 e+fi = sin(a+bi) = sina * (e^b + e^(-b))/2 + cosa * (e^b - e^(-b))/2 
Plural &Sin(const Plural &p)
{
	double m = exp(p.imag), n = 1 / m;
	return Plural(sin(p.real)*(m + n) / 2.0, cos(p.real)*(m - n) / 2.0);
}

//复数余弦运算 e+fi = cos(a+bi) = cosa * (e^b + e^(-b))/2 - sina * (e^b - e^(-b))/2 
Plural &Cos(const Plural &p)
{
	double m = exp(p.imag), n = 1 / m;
	return Plural(cos(p.real)*(m + n) / 2.0, -1.0 * sin(p.real)*(m - n) / 2.0);
}

void show(const Plural &p)
{
	cout << p.real << " + " << p.imag << " i" << endl;
}
//int main()
//{
//	Plural p1(2.0, 3.0), p2(4.0, 5.0);
//
//	cout << "复数加法：" << endl;
//	show(p1);
//	cout << " + ";
//	show(p2);
//	cout << " = ";
//	show(Plus(p1, p2));
//	cout << endl << "复数减法："<<endl;
//	show(p1);
//	cout << " - ";
//	show(p2);
//	cout << " = ";
//	show(Minus(p1, p2));
//	cout << endl << "复数乘法：" << endl;
//	show(p1);
//	cout << " * ";
//	show(p2);
//	cout << " = ";
//	show(Multi(p1, p2));
//	cout << endl << "复数除法：" << endl;
//	show(p1);
//	cout << " / ";
//	show(p2);
//	cout << " = ";
//	show(Div(p1, p2));
//	cout << endl << "复数幂运算：" << endl;
//
//	show(Pow(p1, 3));
//	cout << endl << "复数指数：" << endl;
//	show(Exp(p1));
//	cout << endl << "复数对数：" << endl;
//	show(Log(p1));
//	cout << endl << "复数正弦：" << endl;
//	show(Sin(p1));
//	cout << endl << "复数余弦：" << endl;
//	show(Cos(p1));
//
//	system("pause");
//	return 0;
//}