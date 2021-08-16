#include "Types.h"

std::vector<std::string>g_TypeNames
{
"There is no value!",
"Int",
"Char",
"Double",
"Bool",
"Float",
"UnsignedInt"
};
const char* TypeError::what() const throw ()
{
	return "Type error!\n";
}

TypeError::TypeError(std::string ErrorMsgTypes)
{
	cout << "Cannot convert " + ErrorMsgTypes << std::endl;
}


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
		throw TypeError(g_TypeNames[this->ChosenType] + " to " + g_TypeNames[type]);
	}
}

void Types::Swap(Types& a, Types& b)
{
	std::swap(a.ChosenType, b.ChosenType);
	std::swap(a.Type, b.Type);
}

std::string Types::CurType()
{
	return g_TypeNames[this->ChosenType];
}

Types::~Types()
{

}
