#include <iostream>
#include <string>
using std::cout;
using std::cin;

union types
{
	int typeInteger;
	char typeChar;
	double typeDouble;
	bool typeBool;
	float typeFloat;
	unsigned int typeUInt;
	void* NoType;
};

enum TypesEnum
{
	NoType,
	typeInteger,
	typeChar,
	typeDouble,
	typeBool,
	typeFloat,
	typeUInt
};




class Types
{
public:
	template <typename T>Types(T const i);
	~Types();
	void operator=(int i);
	void operator=(char i);
	void operator=(double i);
	void operator=(bool i);
	void operator=(float i);
	void operator=(unsigned int i);
	Types(Types& t);
	Types(Types&& t);
	int ToInt();
	unsigned int ToUInt();
	char ToChar();
	double ToDouble();
	float ToFloat();
	bool ToBool();
	void DestroyObj();

	std::string CurType();
	int ChosenType;
	types Type;
	static void Swap(Types* a, Types* b);
private:
	
	void _isCorrectType(int type);
	
};

template <typename T>
Types::Types(T const i)
{
	this->operator=(i);
}

