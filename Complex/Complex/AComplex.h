#pragma once
class AComplex{
	double re, im;
	double eps = 0.00000001 ;
	char* view;
	void createView();
public:
	double getRe();
	double getIm();
	void show();
	
	AComplex& operator=(const AComplex& other);
	AComplex operator+(const AComplex& other);
	AComplex operator-(const AComplex & other);
	AComplex operator-();
	AComplex operator*(const AComplex & other);
	AComplex(double re, double im);
	AComplex();
	AComplex(const AComplex&);
	~AComplex();
};

