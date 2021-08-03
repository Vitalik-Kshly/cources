#include <iostream>

union types
{
	int typeInteger;
	char* typeChar;
	double typeFloat;
	bool typeBool;
};

enum TypesEnum
{
	NoType,
	typeInteger,
	typeChar,
	typeDouble,
	typeBool
};



class Types
{
public:
	template <typename T>Types(T const& i);
	~Types();
	void operator=(int i);
	void operator=(char *i);
	void operator=(double i);
	void operator=(bool i);
	int ToInt();
	char* ToChar();
	float ToDouble();
	bool ToBool();
	int ChosenType;
	types Type;

	static void Swap(Types* a, Types* b);
private:
	
	TypesEnum _types;
	bool _isCorrectType(int type);
	
};



