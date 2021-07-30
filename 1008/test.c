#include <stdio.h>

int main(void)
{
	double a, b;

	scanf("%lf %lf", &a, &b);

	printf("%.10g\n", a / b);
	return 0;
}
