//Task: Find Greatest common divisor(gcd)

/*Реализирайте всеки от алгоритмите за намиране на най - голям общ делител с
отделна функция, извикайте ги в main функцията и разпечатайте получените
резултати.*/

#include <stdio.h>

int gcd(int a, int b) {
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

void main() {
	printf("%d", gcd(32, 24));
}