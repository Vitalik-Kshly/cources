#include "Types.h"

class TypeError : public std::exception 
{
	const char* what() const throw () {
		return "Error!";
	}
};


void Types::operator=( int i)
{
	this->Type.typeInteger = i;
	this->ChosenType = typeInteger;
}

void Types::operator=(char i) 
{
	this->Type.typeChar = i;
	this->ChosenType = typeChar;
}

void Types::operator=(double i)
{
	this->Type.typeFloat = i;
	this->ChosenType = typeDouble;
}
void Types::operator=(bool i)
{
	this->Type.typeBool = i;
	this->ChosenType = typeBool;
}

void Types::operator=(float i)
{
	this->Type.typeFloat = i;
	this->ChosenType = typeFloat;
}

void Types::operator=(unsigned int i)
{
	this->Type.typeUInt = i;
	this->ChosenType = typeUInt;
}

int Types::ToInt() 
{
	this->_isCorrectType(typeInteger);
	return this->Type.typeInteger;
}

char Types::ToChar()
{
	this->_isCorrectType(typeChar);
	return this->Type.typeChar;
}
double Types::ToDouble()
{
	this->_isCorrectType(typeDouble);
	return this->Type.typeDouble;
}
bool Types::ToBool()
{
	this->_isCorrectType(typeBool);
	return this->Type.typeBool;
}

float Types::ToFloat()
{
	this->_isCorrectType(typeFloat);
	return this->Type.typeFloat;
}

unsigned int Types::ToUInt()
{
	this->_isCorrectType(typeUInt);
	return this->Type.typeUInt;
}

bool Types::_isCorrectType(int type)
{
	if (type != this->ChosenType)
	{
		throw TypeError();
	}
}

void Types::Swap(Types* a, Types* b)
{
	std::swap(a->ChosenType, b->ChosenType);
	std::swap(a->Type, b->Type);
}


Types::~Types()
{

}
