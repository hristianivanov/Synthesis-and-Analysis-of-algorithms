//Task: Find Greatest common divisor(gcd)

/*Реализирайте всеки от алгоритмите за намиране на най - голям общ делител с
отделна функция, извикайте ги в main функцията и разпечатайте получените
резултати.*/

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

int main() {
	printf("%d", gcd(24, 32));
}