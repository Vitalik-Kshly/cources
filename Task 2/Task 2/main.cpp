#include "Types.h"





int main() 
{
	Types tintVal = Types(131);
	Types tCharVal = Types('a');
	Types tDoubleVal = Types((double) 1.125);
	Types tBoolVal = Types(true);
	Types tFloatVal = Types((float) 1.25);
	Types tUintVal = Types((unsigned int)123);
	
	tintVal.DestroyObj();
	//cout << tintVal.ToInt();
	//cout << tCharVal.CurType();

	//int intVal = tintVal.ToInt();
	char CharVal = tCharVal.ToChar();
	double DoubleVal = tDoubleVal.ToDouble();
	bool BoolVal = tBoolVal.ToUInt();
	float FloatVal = tFloatVal.ToFloat();
	unsigned int UintVal = tUintVal.ToUInt();

	

	return 0;
}