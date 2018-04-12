#pragma once
#include<iostream>
class ComplexNum
{
public:
	ComplexNum();
	ComplexNum(double real,double imaginary);
	~ComplexNum();
	ComplexNum operator+(const ComplexNum & cn) const;     //Complex Plus
	ComplexNum operator-(const ComplexNum & cn) const;      //Complex Minus
	ComplexNum operator*(const ComplexNum & cn) const;		//Complex Multiply
	friend ComplexNum operator*(double x,const ComplexNum & cn);		//Multiplied by Real
	ComplexNum operator~();												//Conjugation
	//Input and Outout overloads
	friend std::ostream & operator<<(std::ostream & o, const ComplexNum & cn);
	friend std::istream & operator>>(std::istream & i, ComplexNum & cn);
private:
	double _real;    //Real part
	double _imaginary;   //Imaginary part
};

