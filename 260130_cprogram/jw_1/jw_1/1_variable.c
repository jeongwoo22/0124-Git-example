int main(void)
{
	char			char_ = 0;
	short			short_ = 0;
	int				int_ = 0;
	unsigned char	uchar_ = 0;

	float			float_ = 0.0;
	double			double_ = 0.0;
	long double		long_double = 0.0;

	char char_over, char_sub;
	short short_over, short_sub;
	int int_over, int_sub;

	/*****
	Example: max
	char	(8)		2^7-1
	short	(16)	2^15-1
	int		(32)	2^31-1
	*****/
	char_	= 127;
	short_	= 32767;
	int_ = 2147483647;
	
	char_over = char_ + 1;
	short_over = short_ + 1;
	int_over = int_ + 1;

	/*****
	Practice 1: min
	*****/
	// char_under = 
	// short_under = 
	// int_under =

	/*****
	Practice 2: check substitution with over limit
	*****/

	/*****
	Practice 3: check memory of value 1, -1
	*****/

	/*****
	Advanced: check memory of value 1.0, 0.5
	*****/

	/*****
	Advanced: check memory of value [76, 79, 86, 69, 32, 48, 50, 48, 55]  (for Debug)
	*****/
	char char_arr[9] = { 76, 79, 86, 69, 32, 48, 50, 48, 55 };

	return 0;
}