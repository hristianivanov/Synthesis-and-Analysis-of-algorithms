#include <stdio.h>

int gcd(int a, int b) {

	if (a == 0)
		return b;

	while (b != 0)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}

	return a;
}

void main() {
	printf("%d", gcd(24, 32));
}