#include "stdafx.h"
#include "complex.h"

CComplex::CComplex()
	: real(0), imag(0)
{}

CComplex::CComplex(double _real, double _imag)
	: real(_real), imag(_imag)
{}

CComplex::~CComplex()
{}

void CComplex::setReal(const double& _real)
{
	real = _real;
}

void CComplex::setImag(const double& _imag)
{
	imag = _imag;
}

double CComplex::getReal(void) const
{
	return real;
}

double CComplex::getImag(void) const
{
	return imag;
}

double CComplex::getBetrag(void) const 
{
	return sqrt( (imag*imag) + (real*real));
}

double CComplex::getWinkel(void) const 
{
	return (180/M_PI) * atan(imag/real);
}

CComplex CComplex::getKehrwert(void) const 
{
	return CComplex(1, 0) / *this;
}

CComplex CComplex::add(const CComplex& _complex) const
{
	CComplex res;
	res.real = this->real + _complex.real;
	res.imag = this->imag + _complex.imag;
	return res;
}

CComplex CComplex::operator+(const CComplex& _complex) const
{
	CComplex res;
	res.real = this->real + _complex.real;
	res.imag = this->imag + _complex.imag;
	return res;
}

CComplex CComplex::operator-(const CComplex& _complex) const
{
	CComplex res;
	res.real = this->real - _complex.real;
	res.imag = this->imag - _complex.imag;
	return res;
}

CComplex CComplex::operator/(CComplex _complex) const
{
	CComplex res;
	_complex.imag = -_complex.imag;
	res = this-> operator*(_complex);
	res.real = res.real / ((_complex.real*_complex.real) + (_complex.imag*_complex.imag));
	res.imag = res.imag / ((_complex.real*_complex.real) + (_complex.imag*_complex.imag));
	return res;
}

CComplex CComplex::operator*(const CComplex& _complex) const
{
	CComplex res;
	res.real = (this->real*_complex.real) - (this->imag*_complex.imag);
	res.imag = (this->real*_complex.imag) + (this->imag*_complex.real);
	return res;
}

std::ostream& operator<<(std::ostream& stream, const CComplex& _complex)
{
	if (_complex.getImag() >= 0)
	{
		stream << "(" << _complex.getReal() << "+j" << _complex.getImag() << ")";
	}
	else
	{
		stream << "(" << _complex.getReal() << "-j" << -(_complex.getImag()) << ")";
	}
	return stream;
}