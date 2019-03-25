#include <cstdio>

union Data {
    unsigned int num;
    unsigned char byte[4];
};

inline void swap(unsigned char &a, unsigned char &b) {
    unsigned char temp;

    temp = a;
    a = b;
    b = temp;
}

int main() {
    union Data data; 
    int t_cases;
    scanf("%d", &t_cases);

    while(t_cases--) {
        scanf("%u", &data.num);

        for(int idx = 0; idx < 2; ++idx) {
            swap(data.byte[idx], data.byte[3 - idx]);
        }

        printf("%u\n", data.num);
    }

    return 0;
}
