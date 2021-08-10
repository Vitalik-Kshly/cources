Empty :0 Code :1 Comments :0
#include "Types.h"
Empty :1 Code :1 Comments :0

Empty :1 Code :2 Comments :0
class TypeError : public std::exception 
Empty :1 Code :3 Comments :0
{
Empty :1 Code :4 Comments :0
	const char* what() const throw () {
Empty :1 Code :5 Comments :0
		return "Error!";
Empty :1 Code :6 Comments :0
	}
Empty :1 Code :7 Comments :0
};
Empty :2 Code :7 Comments :0

Empty :3 Code :7 Comments :0

Empty :3 Code :8 Comments :0
void Types::operator=(const int i)
Empty :3 Code :9 Comments :0
{
Empty :3 Code :10 Comments :0
	this->Type.typeInteger = i;
Empty :3 Code :11 Comments :0
	this->ChosenType = typeInteger;/*SAFASFAFAFASfa
Empty :3 Code :12 Comments :0
	safasf
Empty :3 Code :13 Comments :0
	asfasf
Empty :3 Code :14 Comments :0
	af
Empty :3 Code :15 Comments :0
	asfasfas
Empty :3 Code :16 Comments :0
	af
Empty :3 Code :17 Comments :0
	asfa
Empty :3 Code :18 Comments :0
	faf
Empty :3 Code :19 Comments :0
	*/aasfassa asfasf asfasfa
Empty :3 Code :20 Comments :0
}
Empty :4 Code :20 Comments :0

Empty :4 Code :21 Comments :0
void Types::operator=(char *i) 
Empty :4 Code :22 Comments :0
{
Empty :4 Code :23 Comments :0
	this->Type.typeChar = i;
Empty :4 Code :24 Comments :0
	this->ChosenType = typeChar;
Empty :4 Code :25 Comments :0
}
Empty :5 Code :25 Comments :0

Empty :5 Code :26 Comments :0
void Types::operator=(const double i)
Empty :5 Code :27 Comments :0
{
Empty :5 Code :28 Comments :0
	this->Type.typeFloat = i;
Empty :5 Code :29 Comments :0
	this->ChosenType = typeDouble;
Empty :5 Code :30 Comments :0
}
Empty :5 Code :31 Comments :0
void Types::operator=(const bool i)
Empty :5 Code :32 Comments :0
{
Empty :5 Code :33 Comments :0
	this->Type.typeBool = i;
Empty :5 Code :34 Comments :0
	this->ChosenType = typeBool;
Empty :5 Code :35 Comments :0
}
Empty :5 Code :36 Comments :0
int Types::ToInt() 
Empty :5 Code :37 Comments :0
{
Empty :5 Code :38 Comments :0
	this->_isCorrectType(typeInteger);
Empty :5 Code :39 Comments :0
	return this->Type.typeInteger;
Empty :5 Code :40 Comments :0
}
Empty :6 Code :40 Comments :0

Empty :6 Code :41 Comments :0
char* Types::ToChar()
Empty :6 Code :42 Comments :0
{
Empty :6 Code :43 Comments :0
	this->_isCorrectType(typeChar);
Empty :6 Code :44 Comments :0
	return this->Type.typeChar;
Empty :6 Code :45 Comments :0
}
Empty :6 Code :46 Comments :0
float Types::ToDouble()
Empty :6 Code :47 Comments :0
{
Empty :6 Code :48 Comments :0
	this->_isCorrectType(typeDouble);
Empty :6 Code :49 Comments :0
	return this->Type.typeFloat;
Empty :6 Code :50 Comments :0
}
Empty :6 Code :51 Comments :0
bool Types::ToBool()
Empty :6 Code :52 Comments :0
{
Empty :6 Code :53 Comments :0
	this->_isCorrectType(typeBool);
Empty :6 Code :54 Comments :0
	return this->Type.typeBool;
Empty :6 Code :55 Comments :0
}
Empty :7 Code :55 Comments :0

Empty :7 Code :56 Comments :0
bool Types::_isCorrectType(int type)
Empty :7 Code :57 Comments :0
{
Empty :7 Code :58 Comments :0
	if (type != this->ChosenType)
Empty :7 Code :59 Comments :0
	{
Empty :7 Code :60 Comments :0
		throw TypeError();
Empty :7 Code :61 Comments :0
	}
Empty :7 Code :62 Comments :0
}
Empty :8 Code :62 Comments :0

Empty :8 Code :63 Comments :0
void Types::Swap(Types* a, Types* b)
Empty :8 Code :64 Comments :0
{
Empty :8 Code :65 Comments :0
	std::swap(a->ChosenType, b->ChosenType);
Empty :8 Code :66 Comments :0
	std::swap(a->Type, b->Type);
Empty :8 Code :67 Comments :0
}
Empty :9 Code :67 Comments :0

Empty :10 Code :67 Comments :0

Empty :10 Code :68 Comments :0
Types::~Types()
Empty :10 Code :69 Comments :0
{
Empty :10 Code :70 Comments :0
}
