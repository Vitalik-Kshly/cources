#include "Types.h"

class TypeError : public std::exception 
{
	const char* what() const throw () {
		return "Error!";
	}
};


void Types::operator=(const int i)
{
	this->Type.typeInteger = i;
	this->ChosenType = typeInteger;
}

void Types::operator=(char *i) 
{
	this->Type.typeChar = i;
	this->ChosenType = typeChar;
}

void Types::operator=(const double i)
{
	this->Type.typeFloat = i;
	this->ChosenType = typeDouble;
}
void Types::operator=(const bool i)
{
	this->Type.typeBool = i;
	this->ChosenType = typeBool;
}
int Types::ToInt() 
{
	this->_isCorrectType(typeInteger);
	return this->Type.typeInteger;
}

char* Types::ToChar()
{
	this->_isCorrectType(typeChar);
	return this->Type.typeChar;
}
float Types::ToDouble()
{
	this->_isCorrectType(typeDouble);
	return this->Type.typeFloat;
}
bool Types::ToBool()
{
	this->_isCorrectType(typeBool);
	return this->Type.typeBool;
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
