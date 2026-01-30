#include "calc.h"
int a = 10, b = 20; // global
extern error;

int add(int a, int b) // parameter
{
	return a + b;
}

int main2(void)
{
	/*****
	Example1 : diff local / global var
	*****/
	int c = 3, d = 4; // local
	int result1, result2;
	result1 = add(c, d); //argument
	result2 = add(a, b);

	int a = 1, b = 2;
	result2 = add(a, b);

	// Example 2 : illness of global var (side effect)
	double dresult1 = 0.0, dresult2 = 0.0;
	dresult1 = header_DTR(180);
	dresult2 = header_RTD(3.141592);
	dresult1 = header_DTR(180);
	 
	// Example 3 : uses of global var
	for (int i = 0; i < 100; i++)
	{
		header_RTD(i);
		if (error)
		{
			add(a, b);
			add(c, d);
		}
		else
			add(c, d);
	}
		

	return 0;
}