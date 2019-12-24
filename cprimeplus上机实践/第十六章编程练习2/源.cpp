#include<stdio.h>
#include<math.h>
typedef struct polar {
	double r;
	double angle;
}mode;

typedef struct retangular {
	double x;
	double y;
}mode2;

mode2 transition(mode);

int main(void)
{
	mode a;
	mode2 b;

	printf("Enter polar coordinates: \n");
	printf("r:     ");
	scanf_s("%lf", &a.r);
	printf("angle: ");
	scanf_s("%lf", &a.angle);
	b = transition(a);
	printf("It's corrdinate in cartesian coordinate is: (%.3lf,%.3lf)", b.x, b.y);

	return 0;
}
mode2 transition(mode n)
{
	mode2 c;
	c.x = cos((n.angle * atan(1) * 4) / 180) * n.r;
	c.y = sin((n.angle * atan(1) * 4) / 180) * n.r;

	return c;
}