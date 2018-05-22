#include <cstdio>
#include <cstring>

int main() {
	double a, b;
	char c[14];

	scanf("%lf %lf", &a, &b);
	sprintf(c, "%.9lf", a/b);

	for (int i = strlen(c) - 1; i >= 0; i--) {
		if (c[i] != '0') {
			c[i+1] = '\0';
			if (c[i] == '.') {
				c[i] = '\0';
			}
			break;
		}
	}

	printf("%s", c);
}
