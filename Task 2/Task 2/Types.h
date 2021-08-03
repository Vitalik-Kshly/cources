#include <iostream>

union types
{
	int typeInteger;
	char typeChar;
	float typeFloat;
	bool typeBool;
};

enum TypesEnum
{
	NoType,
	typeInteger,
	typeChar,
	typeFloat,
	typeBool
};

class Types
{
public:
	Types();
	~Types();
	Types operator=(const int i);
	Types operator=(const char i);
	Types operator=(const float i);
	Types operator=(const bool i);
private:
	types type;
	TypesEnum types;
	
};



