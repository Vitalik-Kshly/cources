#include "Types.h"


using std::cout;
using std::cin;


int main() 
{
	Types tintVal = new Types(131);
	Types tCharVal = new Types('a');
	Types tDoubleVal = new Types((double) 1.125);
	Types tBoolVal = new Types(true);
	Types tFloatVal = new Types((float) 1.25);
	Types tUintVal = new Types((unsigned int)123);
	
	int intVal = tintVal.ToInt();
	char CharVal = tCharVal.ToChar();
	double DoubleVal = tDoubleVal.ToDouble();
	bool BoolVal = tBoolVal.ToBool();
	float FloatVal = tFloatVal.ToFloat();
	unsigned int UintVal = tUintVal.ToUInt();


	return 0;
}