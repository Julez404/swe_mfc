#pragma once

class CData{
private:
	double	*x;
	double	*y;
	int		len;
	CString	name;


public:
	//Con/-Destructors
	CData();
	CData(double _x[],double _y[], int _len, CString _name);
	~CData();


	//Get- Set-
	void	setValue(double _x, double _y, int _i);
	double	getXValue(int _i) const;
	double	getYValue(int _i) const;
	void	setLen(int _len);
	int		getLen() const;
	void	setName(CString _Name);
	CString	getName() const;


	//Other
	void addValue(double _x, double _y);
	double	getMinimum() const;
	double	getMaximum() const;
	double	getAverage() const;
};