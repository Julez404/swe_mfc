#pragma once

#include "Data.h"


class CGraph
{
protected:
	int startX;
	int startY;
	int boundry;
	int height;
	int width;
	COLORREF functionColor;



public:
	CGraph();
	CGraph(int _startX, int _startY, int _width,int _height, int boundry, COLORREF _functionColor);

	~CGraph();

	int getStartX(void) const;
	int getStartY(void) const;

	void setStartX(int _orgX);
	void setStartY(int _orgY);

	void draw(CDC* _cd, const CData& _data) const;
	void draw(CDC* _cd, const CData& _data, double const mXMin, double const mXMax, double const mYMin, double const mYMax) const;

	void drawBackground(CDC* const _cd) const;
	void drawCoordinates(CDC* const _cd, const int _originY) const;
	void CGraph::drawFunction(CDC* const _cd, const CData& _data, const int originX, const int originY, const double scaleY, const double scaleX) const;
};

