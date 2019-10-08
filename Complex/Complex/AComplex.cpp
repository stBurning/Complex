#include "AComplex.h"
#include <iostream>
using namespace std;

double AComplex::getRe(){
	return this->re;
}

double AComplex::getIm(){
	return this->im;
}

void AComplex::show() {
	cout << this->view << endl;
}

void AComplex::createView(){
	const int sz = 101;
	char* t = new char[sz];
	char sp = ' ';
	char plus = '+';
	if (fabs(re) > eps ||fabs(re) < eps && fabs(im) < eps) sprintf_s(t, sz, "%g", re);
	else {
		t[0] = 0;
		sp = 7;
		plus = 7;
	} if (fabs(im) > eps) {
		char z = (im > 0) ? plus : '-';
		const char* fmt = (fabs(fabs(im) - 1) > eps) ?"%s%c%c%c%gi" : "%s%c%c%ci";
		sprintf_s(t, sz, fmt,t, sp, z, sp, fabs(im));
	}
	delete[] view;
	view = _strdup(t);
	delete[] t;
}

AComplex& AComplex::operator=(const AComplex& other) {
	if (this == &other) return *this;
	this->re = other.re;
	this->im = other.im;
	delete[] this->view;
	this->view = _strdup(other.view);
	return *this;
}

AComplex AComplex::operator+(const AComplex & other) {
	AComplex c(this->re + other.re, this->im + other.im);
	return c;
}

AComplex AComplex::operator-(const AComplex & other) {
	AComplex c(this->re - other.re, this->im - other.im);
	return c;
}

AComplex AComplex::operator-() {
	AComplex c(this->re, -this->im);
	return c;
}


AComplex AComplex::operator*(const AComplex & other) {
	AComplex c(this->re + other.re, this->im + other.im);
	return c;
}

AComplex::AComplex(double re, double im){
	this->re = re;
	this->im = im;
	createView();

}

AComplex::AComplex(){
	this->re = 0;
	this->im = 0;
	createView();
}

AComplex::AComplex(const AComplex& other) {
	this->re = other.re;
	this->im = other.im;
	this->view = _strdup(other.view);	
}

AComplex::~AComplex(){
	delete[] view;
}


int main() {
	AComplex a(3, 0.4);
	AComplex b;
	b = a;
	AComplex c = a - b;
	a.show();
	a = -a;
	a.show();
	b.show();
	c.show();
	system("pause");
	return 0;
}