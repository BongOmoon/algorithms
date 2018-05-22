#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void fibonacci(int idx){
	vector<int> zero;
	vector<int> one;

	if(idx == 0){
		printf("1 0\n");
	}
	else if(idx == 1){
		printf("0 1\n");
	}
	else{
		zero.push_back(1);
		one.push_back(0);
		zero.push_back(0);
		one.push_back(1);
		for(int i = 2; i <= idx; i++){
			zero.push_back(zero[i-1] + zero[i-2]);
			one.push_back(one[i-1] + one[i-2]);
		}
		printf("%d %d\n", zero[idx], one[idx]);
	}
}

int main(){
	int idx;
	int T;

	scanf("%d", &T);

	for(int i = 0; i < T; i++){
		scanf("%d", &idx);
		fibonacci(idx);
	}
}
