#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
typedef struct Turret{
	int x1, y1, r1;
	int x2, y2, r2;
}Turret;

int testRange(int x1, int y1, int r1, int x2, int y2, int r2){
	double p_dist = sqrt(pow(x2-x1, 2.0) + pow(y2-y1, 2.0)); 
	int dist = r1 + r2;

	if(dist > p_dist){
		if(x1 == x2 && y1 == y2){
			if(r1 == r2)
				return -1;
			else
				return 0;
		}
		else if(r1-r2 == p_dist || r2-r1 == p_dist)
			return 1;
		else if(r1-r2 >= p_dist || r2-r1 >= p_dist)
			return 0;
		else
			return 2;
	}
	else if(dist == p_dist)
		return 1;
	else
		return 0;
}

int main(){
	int T;
	scanf("%d", &T);

	Turret t[T];

	for(int i = 0; i < T; i++){
		scanf("%d %d %d %d %d %d", &t[i].x1, &t[i].y1, &t[i].r1, &t[i].x2, &t[i].y2, &t[i].r2);
	}

	for(int i = 0; i < T; i++){
		printf("%d\n", testRange(t[i].x1, t[i].y1, t[i].r1, t[i].x2, t[i].y2, t[i].r2));
	}
}
