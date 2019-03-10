#include <cstdio>

int hundred, fifty, ten;

void money_to_change(int cost) {
    int change = 1000 - cost;

    hundred = change / 100;
    fifty = (change % 100) / 50;
    ten = (change % 100 % 50) / 10;
}

int main() {
    int cost;
    scanf("%d", &cost);
    
    money_to_change(cost);
    printf("%d %d %d\n", hundred, fifty, ten);

    return 0;
}
