#include "Types.h"

int main() 
{
	Types tintVal = Types(131);
	Types tCharVal = Types('a');
	Types tDoubleVal = Types((double) 1.125);
	Types tBoolVal = Types(true);
	Types tFloatVal = Types((float) 1.25);
	Types tUintVal = Types((unsigned int)123);

	try
	{
		double DoubleVal = tDoubleVal.ToInt();
	}
	catch (TypeError e)
	{
		cout << e.what();
	}

	tintVal.DestroyObj();

	bool BoolVal = tBoolVal.ToBool();
	float FloatVal = tFloatVal.ToFloat();
	unsigned int UintVal = tUintVal.ToUInt();
	Types newVal = tFloatVal;
	Types newVal1 = std::move(tFloatVal);

	return 0;
}