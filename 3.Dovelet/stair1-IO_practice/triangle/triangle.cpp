#include <cstdio>

int main () {
    double area;
    int width, height;

    scanf("%d %d", &width, &height);

    area = width * height / 2.0;

    printf("%0.2f\n", area);

    return 0;
}
