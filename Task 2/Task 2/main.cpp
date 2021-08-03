#include "Types.h"

template <typename T>
Types::Types(T const& i)
{
	this->operator=(i);
}

int main() 
{
	Types type = Types(122);
	Types type1 = (char *)"  saf";
	Types::Swap(&type, &type1);
	std::cout << type.ToChar() << std::endl;
	std::cout << type1.ToInt() << std::endl;

	return 0;
	std::cout << type.ToInt() << std::endl;

	type = true;
	std::cout << type.ToBool() << std::endl;

	type = 1.962;
	std::cout << type.ToDouble() << std::endl;

	return 0;
}