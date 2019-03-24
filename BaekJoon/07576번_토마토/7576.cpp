#include <cstdio>
#include <queue>

using namespace std;

int box[1001][1001];
int day;
queue<int> qx;
queue<int> qy;

void checkTomato(int N, int M) {
	while (!qx.empty()){
		int size = qx.size();

		for (int i = 0; i < size; i++) {
			int x = qx.front(), y = qy.front();
			qx.pop(), qy.pop();
			if (box[y - 1][x] == 0 && y - 1 >= 1) {
				box[y - 1][x] = 1;
				qx.push(x);
				qy.push(y - 1);
			}
			if (box[y + 1][x] == 0 && y + 1 <= N) {
				box[y + 1][x] = 1;
				qx.push(x);
				qy.push(y + 1);
			}
			if (box[y][x - 1] == 0 && x - 1 >= 1) {
				box[y][x - 1] = 1;
				qx.push(x - 1);
				qy.push(y);
			}
			if (box[y][x + 1] == 0 && x + 1 <= M) {
				box[y][x + 1] = 1;
				qx.push(x + 1);
				qy.push(y);
			}
		}
		day++;
	}
	day--;
}

int main() {
	int M, N;
	scanf("%d %d", &M, &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int t;
			scanf("%d", &t);
			box[i][j] = t;
		}
	}

	bool flag = true;

	//토마토 농장을 검사한다. 만약 1일 때 큐에 집어 넣는다.
	//flag가 바뀌지 않으면 토마토는 모두 익어 있는 것이다.
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (box[i][j] == 1) {
				qy.push(i);
				qx.push(j);
			}
			else if (box[i][j] == 0)
				flag = false;
		}
	}

	//토마토가 모두 익어있을 때
	if (flag == true) {
		printf("0");
		return 0;
	}

	checkTomato(N, M);

	//토마토가 모두 안 익었을 때
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (box[i][j] == 0) {
				printf("-1");
				return 0;
			}
		}
	}
	printf("%d", day);
}
