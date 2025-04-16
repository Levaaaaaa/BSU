#include <iostream>
#include <cmath>

extern "C" float* _stdcall function3(float x, float y);

int main()
{
	float x = 0.5;
	float y = 0.75;
	float result1 = (x*y + y*(log(x)/log(2)))/atan(x/y);
	float log;
	int two = 2;
	float result;
	std::cout << result1 << "\n";

	/*_asm
	{
		finit
		fld1
		fld x
		fyl2x
		; fstp log

		fld x
		fadd
		fld y
		fmul
		fstp result

		fld x
		fld y
		fpatan
		fld result
		fdivr
		fstp result
	}*/

	result = *function3(x, y);

	std::cout << result << "\n";

	return 0;
}