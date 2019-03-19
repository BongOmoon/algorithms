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

	//�丶�� ������ �˻��Ѵ�. ���� 1�� �� ť�� ���� �ִ´�.
	//flag�� �ٲ��� ������ �丶��� ��� �;� �ִ� ���̴�.
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

	//�丶�䰡 ��� �;����� ��
	if (flag == true) {
		printf("0");
		return 0;
	}

	checkTomato(N, M);

	//�丶�䰡 ��� �� �;��� ��
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
