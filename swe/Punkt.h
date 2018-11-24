#ifndef _CPUNKT
#define _CPUNKT

class CPunkt
{
private:
	double x;
	double y;
	CPunkt *next;

public:
	CPunkt();
	CPunkt(double _x, double _y, CPunkt* _next = NULL);
	~CPunkt();

	double getX(void) const;
	double getY(void) const;
	double getDistance(void) const;
	CPunkt* getNext(void) const;

	void setX(double _x);
	void setY(double _y);
	void setXY(double _x, double _y);
	void setNext(CPunkt* _next);

	friend std::ostream& operator<<(std::ostream& stream, const CPunkt& _punkt);
};


#endif // !_CPUNKT