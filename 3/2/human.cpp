#include "Human.h"

Human::Human(char value, int x, int y)
{
	mValue = value;
	mX = x;
	mY = y;
}

char Human::getValue()
{
	return this->mValue;
}

void Human::setValue(char value)
{
	mValue = value;
}

void Human::setX(int x)
{
	mX = x;
}

void Human::setY(int y)
{
	mY = y;
}

int Human::getX()
{
	return mX;
}

int Human::getY()
{
	return mY;
}