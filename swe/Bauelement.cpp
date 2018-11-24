#include "stdafx.h"
#include "bauelement.h"

CBauelement::CBauelement()
	: preis(0)
	, position(CPunkt())
	, next(NULL)
{}

CBauelement::CBauelement(std::string _name, double _preis, CPunkt _position)
	: name(_name)
	, preis(_preis)
	, position(_position)
	, next(NULL)
{}

CBauelement::~CBauelement()
{
	std::cout << "~Bauelement (" << this->getName() << ")" << std::endl;
}

std::string CBauelement::getName(void) const
{
	return name;
}

double CBauelement::getPreis() const
{
	return preis;
}

CPunkt CBauelement::getPosition() const
{
	return position;
}

CBauelement* CBauelement::getNext(void) const
{
	return next;
}

void CBauelement::setName(std::string _name)
{
	name = _name;
}

void CBauelement::setPreis(double _preis)
{
	preis = _preis;
}
void CBauelement::setPosition(CPunkt _position)
{
	position = _position;
}

void CBauelement::setNext(CBauelement* _next)
{
	next = _next;
}

std::ostream& operator<<(std::ostream& stream, const CBauelement& _bauelement)
{
	stream << "Bez.: " << _bauelement.name << " Preis: " << _bauelement.preis << " EUR  Position: " << _bauelement.position;
	return stream;
}