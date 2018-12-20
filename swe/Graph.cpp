#include "stdafx.h"
#include "Graph.h"


CGraph::CGraph()
{

}

CGraph::CGraph(int _startX, int _startY, int _width, int _height, int _boundry, COLORREF _functionColor)
	:startX(_startX)
	, startY(_startY)
	, width(_width)
	, height(_height)
	, boundry(_boundry)
	, functionColor(_functionColor)
{}

CGraph::~CGraph()
{

}

int CGraph::getStartX(void) const
{
	return startX;
}
int CGraph::getStartY(void) const
{
	return startY;
}

void CGraph::setStartX(int _startX)
{
	startX = _startX;
}
void CGraph::setStartY(int _startY)
{
	startY = _startY;
}

void CGraph::drawBackground(CDC* const _cd) const
{
	CPen pen_black(PS_SOLID, 2, RGB(0, 0, 0));
	_cd->SelectObject(pen_black);
	_cd->Rectangle(startX, startY, startX + width, startY + height);
}

void CGraph::drawCoordinates(CDC* const _cd, const int _originY) const
{
	//Draw Koordinate Y
	_cd->MoveTo(startX + boundry, startY + boundry);
	_cd->LineTo(startX + boundry, startY + boundry + height - (2 * boundry));

	//Draw Koordinate X
	_cd->MoveTo(startX + boundry, _originY);
	_cd->LineTo(startX + width - boundry, _originY);
}

void CGraph::drawFunction(CDC* const _cd, const CData& _data, const int originX, const int originY, const double scaleX, const double scaleY) const
{
	for (int i = 0; i < _data.getLen(); i++)
	{
		if (((originY - (int)(_data.getYValue(i)*scaleY)) > (startY + boundry)) &&
			((originY - (int)(_data.getYValue(i)*scaleY)) < (startY + height - boundry)) &&
			((originX + (int)(_data.getXValue(i)*scaleX)) < (startX + width - boundry)))
		{
			_cd->LineTo((int)(originX + (_data.getXValue(i))*scaleX), (originY - (int)(_data.getYValue(i)*scaleY)));
		}
		else
		{
			_cd->MoveTo((originX + (int)((_data.getXValue(i))*scaleX)), (originY - (int)(_data.getYValue(i)*scaleY)));
		}
	}
}


void CGraph::draw(CDC* _cd, const CData& _data) const
{
	const int originX = startX + boundry;
	const int originY = startY + height / 2;
	this->drawBackground(_cd);
	this->drawCoordinates(_cd, originY);

	CPen pen(PS_SOLID, 1, functionColor);
	_cd->SelectObject(pen);

	double scaleY = (height - 2 * boundry) / (double)((_data.getMaximum() + (-_data.getMinimum())));
	double scaleX = (width - 2 * boundry) / (double)(_data.getLen());

	_cd->MoveTo(originX, originY);

	this->drawFunction(_cd, _data, originX, originY, scaleX, scaleY);
}



void CGraph::draw(CDC* _cd, const CData& _data, double const mXMin, double const mXMax, double const mYMin, double const mYMax) const
{
	//Input Value Check
	if (mYMax < mYMin ||
		mXMax < mXMin ||
		mYMax == mYMin ||
		mXMax == mYMin ||
		mXMin > 0)
	{
		this->drawBackground(_cd); //Clear Screen
		return; // Dialog Box einbauen
	}

	if (mXMin < 0)
	{
		return; //msgbox
	}

	int sizeOfY = (int)(mYMax - mYMin);
	int sizeOfX = (int)(mXMax - mXMin);

	double scaleY = (double)((height - (2 * boundry)) / (double)(sizeOfY));
	double scaleX = (width - 2 * boundry) / (double)sizeOfX;

	const int originY = (int)(startY + boundry + mYMax * scaleY);
	const int originX = (int)(startX + boundry);

	this->drawBackground(_cd);

	if (mYMin <= 0 && mYMax > 0)
	{
		this->drawCoordinates(_cd, originY);
	}
	else
	{
		this->drawCoordinates(_cd, (int)(startY + height - (boundry / 2)));
	}

	CPen pen(PS_SOLID, 1, functionColor);
	_cd->SelectObject(pen);
	_cd->MoveTo(originX, originY);

	this->drawFunction(_cd, _data, originX, originY, scaleX, scaleY);
}


