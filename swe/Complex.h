#ifndef _CCOMPLEX
#define _CCOMPLEX

class CComplex
{
private:
	double real;
	double imag;

public:
	CComplex();
	CComplex(double _real, double _imag);
	~CComplex();

	void setReal(const double& _real);
	void setImag(const double& _imag);

	double getReal(void) const;
	double getImag(void) const;
	double getBetrag(void) const;
	double getWinkel(void) const;
	CComplex getKehrwert(void) const;

	CComplex add(const CComplex& _complex) const;
	CComplex operator+(const CComplex& _complex) const;
	CComplex operator-(const CComplex& _complex) const;
	CComplex operator/(CComplex _complex) const;
	CComplex operator*(const CComplex& _complex) const;

};


std::ostream& operator<<(std::ostream& stream, const CComplex& _complex);


#endif // !_CCOMPLEX

