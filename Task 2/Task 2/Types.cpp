#include "Types.h"
static std::string TypeNames[7]
{
	"There is no value!",
	"Int",
	"Char",
	"Double",
	"Bool",
	"Float",
	"UnsignedInt"
};

class TypeError : public std::exception 
{
	const char* what() const throw () 
	{
		return "Error!";
	}
public:
	TypeError(std::string ErrorMsgTypes) 
	{
		cout << "TYPE ERROR! Cannot convert " + ErrorMsgTypes << std::endl;
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
	this->Type.typeDouble = i;
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

void Types::DestroyObj() 
{
	this->Type.NoType = NULL;
	this->ChosenType = NoType;
}

void Types::_isCorrectType(int type)
{
	if (type != this->ChosenType)
	{
		throw TypeError(TypeNames[this->ChosenType] + " to " + TypeNames[type]);
	}
}

void Types::Swap(Types* a, Types* b)
{
	std::swap(a->ChosenType, b->ChosenType);
	std::swap(a->Type, b->Type);
}

std::string Types::CurType()
{
	return TypeNames[this->ChosenType];
}

Types::~Types()
{

}
