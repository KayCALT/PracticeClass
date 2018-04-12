#include "ComplexNum.h"



ComplexNum::ComplexNum()
	:_real(0),_imaginary(0)                           //Default is set to the origin
{
}

ComplexNum::ComplexNum(double real, double imaginary)
	:_real(real),_imaginary(imaginary)
{
}

ComplexNum::~ComplexNum()
{
}

ComplexNum ComplexNum::operator+(const ComplexNum & cn) const
{
	ComplexNum cno;
	cno._real = _real + cn._real;
	cno._imaginary = _imaginary + cn._imaginary;
	return cno;
}

ComplexNum ComplexNum::operator-(const ComplexNum & cn) const
{
	ComplexNum cno;
	cno._real = _real - cn._real;
	cno._imaginary = _imaginary - cn._imaginary;
	return cno;
}

ComplexNum ComplexNum::operator*(const ComplexNum & cn) const
{
	ComplexNum cno;
	cno._real = _real * cn._real - _imaginary * cn._imaginary;
	cno._imaginary = _real * cn._imaginary + _imaginary * cn._real;
	return cno;
}

ComplexNum ComplexNum::operator~()
{
	return ComplexNum(_real, -_imaginary);
}

ComplexNum operator*(double x, const ComplexNum & cn)
{
	return ComplexNum(x, 0)*cn;
}

//Output to the screen
std::ostream & operator<<( std::ostream & o, const ComplexNum & cn)
{
	o << "( " << cn._real << " , " << cn._imaginary << "i )";
	return o;
}

//Input to variable  ??????????
std::istream & operator>>(std::istream & i, ComplexNum & cn)
{
	std::cout << "Real: ";
	i>> cn._real;
	std::cout << "Imaginary: ";
	i >> cn._imaginary;
	return i;
}
