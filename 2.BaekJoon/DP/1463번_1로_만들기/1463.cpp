#include <cstdio>
#include <cstdlib>

int getMin(int a, int b){
	return (a > b)?b:a;
}

int main(){
	int N, temp;
	int *DP;
	
	scanf("%d", &N);
	DP = (int *)malloc(sizeof(int)*(N+1));
	
	DP[1] = 0;
	DP[2] = 1;
	DP[3] = 1;
	
	for(int i = 4; i <= N; i++){
		DP[i] = DP[i-1] + 1;
		
		if(i % 2 == 0){
			temp = DP[i/2] + 1;
			DP[i] = getMin(DP[i], temp);
		}
		if(i % 3 == 0){
			temp = DP[i/3] + 1;
			DP[i] = getMin(DP[i], temp);			
		}
	}
	
	printf("%d\n", DP[N]);
}
