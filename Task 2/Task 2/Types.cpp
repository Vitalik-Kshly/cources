#include "Types.h"

Types::Types()
{
	this->types = NoType;
}

Types Types::operator=(const int i)
{
	this->type.typeInteger = i;
	this->types = typeInteger;
}

Types Types::operator=(const char i) 
{
	this->type.typeChar = i;
	this->types = typeChar;
}

Types Types::operator=(const float i)
{
	this->type.typeFloat = i;
	this->types = typeFloat;
}
Types Types::operator=(const bool i)
{
	this->type.typeBool = i;
	this->types = typeBool;
}


Types::~Types()
{
}
