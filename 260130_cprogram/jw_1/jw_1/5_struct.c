#include <stdio.h>

struct position
{
	int x;
	int y;
	int z;
};

typedef struct student {
	char name[10];
	int id;
	char grade;
}STD;

struct position add_position(struct position a, struct position b)
{
	struct position result;
	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;

	return result;
}; 

int add_position_x(int x, int y)
{
	return x + y;
};

int main5(void)
{
	struct position p1, p2, result;

	p1.x = 1; p1.y = 1; p1.z = 1;
	p2.x = 2; p2.y = 3; p2.z = 4;
	result = add_position(p1, p2);

	STD jw = { "ahn", 2023, 'g'}, yj = {"park", "2022",'w'};

	// why use struct

	return 0;
}