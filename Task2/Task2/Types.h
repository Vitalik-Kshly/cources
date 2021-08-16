#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
extern std::vector<std::string> g_TypeNames;
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

class TypeError
{
public:
	const char* what() const throw ();
	TypeError(std::string ErrorMsgTypes);
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
	Types(Types& t) = default;
	Types(Types&& t) = default;
	void operator=(int i);
	void operator=(char i);
	void operator=(double i);
	void operator=(bool i);
	void operator=(float i);
	void operator=(unsigned int i);
	int ToInt();
	unsigned int ToUInt();
	char ToChar();
	double ToDouble();
	float ToFloat();
	bool ToBool();
	void DestroyObj();
	std::string CurType();
	static void Swap(Types& a, Types& b);
	
private:
	void _isCorrectType(int type);
	types Type;
	int ChosenType;
};

template <typename T>
Types::Types(T const i)
{
	this->operator=(i);
}

