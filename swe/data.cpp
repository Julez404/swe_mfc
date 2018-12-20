#include "stdafx.h"
#include "Data.h"


CData::CData(){
	len=1;
	name="undefined";
	x= new	double[len];
	y= new	double[len];
	*x=0;
	*y=0;
}
CData::CData(double _x[],double _y[],int _len,CString _name)
{
	x= new	double[_len];
	y= new	double[_len];
	for (int i = 0; i < _len; i++)
	{
		*(x+i)=*(_x+i);				
		*(y+i)=*(_y+i);
	}
	len=_len;
	name=_name;
}

CData::~CData()
{
	delete[] y;
	delete[] x;
}



void	CData::setValue(double _x, double _y, int _i){
	*(x+_i)=_x;
	*(y+_i)=_y;
}
double	CData::getXValue(int _i) const {
	return x[_i];
}
double	CData::getYValue(int _i) const {
	return y[_i];
}
void	CData::setLen(int _len){
	double	*y_neu=new double[_len];
	double	*x_neu=new double[_len];

	if(_len<len){
		for (int i = 0; i < _len; i++)
		{
			*(x_neu+i)=*(x+i);
			*(y_neu+i)=*(y+i);
		}
	} else {
		for (int i = 0; i < len; i++)
		{
			*(x_neu+i)=*(x+i);
			*(y_neu+i)=*(y+i);
		}
		for (int i = len; i < _len; i++)
		{
			*(x_neu+i)=0;
			*(y_neu+i)=0;
		}
	}
	delete[]	x;
	delete[]	y;
	x=x_neu;
	y=y_neu;
	len=_len;
}

void CData::addValue(double _x, double _y) 
{
	this->setLen(len + 1);
	this->setValue(_x, _y, len);
}



int		CData::getLen() const {
	return	len;
}

void	CData::setName(CString _name){
	name=_name;
}

CString	CData::getName() const {
	return	name;
}

//OTHERS

//void	CData::printValues(){
//	cout << "Datensatz: " << name << endl; 
//	cout << "Laenge: " << len << endl; 
//	cout << "Pos.\tx\ty" << endl;
//	for (int i = 0; i < len; i++)
//	{
//		printf("%i\t%lf\t%lf\n",i,x[i],y[i]);
//		//cout << i << "\t"<< *(x+i) << "\t" << *(y+i) << endl;
//	}
//	pause();
//}
double	CData::getMinimum() const {
	double	min=*(y+0);
	for (int i = 1; i < len; i++)
	{
		if (min>*(y+i))
		{
			min=*(y+i);
		}
	}
	return min;
}
double	CData::getMaximum() const {
	double	max=*(y+0);
	for (int i = 1; i < len; i++)
	{
		if (max<*(y+i))
		{
			max=*(y+i);
		}
	}
	return max;
}
double	CData::getAverage() const {
	double	average=0;
	for (int i = 0; i < len; i++)
	{
		average+=*(y+i);
	}
	return (average/len);
}

//void	CData::printToFile(){
//	fstream		datei;
//	CString		name;
//
//	cout << "Note: .csv is added automatically" << endl;
//	cout << "Dateiname:";
//	cin >> name;
//	name+=".csv";
//
//	datei.open(name,ios::out);
//	datei << "x;y"<< endl;
//	for (int i = 0; i < len	; i++)
//	{
//		datei << "=" << (int)(*(x+i)*10000) << "/10000;" << "=" << (int)(*(y+i)*10000) << "/10000;" << endl;
//	}
//	datei.close();
//}