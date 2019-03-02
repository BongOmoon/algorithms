#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int dp[4][101];
    int board[3][101];
    int N, temp;
    scanf("%d", &N);

    for(int i = 0; i < 3; i++){
        for(int j = 1; j <= N; j++){
            scanf("%d", &board[i][j]);
        }
    }

	//������ 4���� ������ �迭 dp�� ù��° ���� ���� 
    for(int i = 0; i < 4; i++){
        if(i == 3)
            dp[i][1] = board[0][1] + board[2][1];
        else
            dp[i][1] = board[i][1];
    }

	//���Ͽ� ���� switch������ ���Ѵ�. 
    for(int i = 2; i <= N; i++){
        for(int j = 0; j < 4; j++){
            switch(j){
                case 0:
                    dp[j][i] = max(dp[1][i-1], dp[2][i-1]) + board[j][i];
                    break;
                case 1:
                    dp[j][i] = max(dp[0][i-1], max(dp[2][i-1], dp[3][i-1])) + board[j][i];
                    break;
                case 2:
                    dp[j][i] = max(dp[0][i-1], dp[1][i-1]) + board[j][i];
                    break;
                case 3:
                    dp[j][i] = dp[1][i-1] + board[0][i] + board[2][i];
                    break;
            }
        }
    }

    temp = dp[0][N];

	//�� �������� ������ ����� �ִ� �� ���� 
    for(int i = 1; i < 4; i++){
        if(temp < dp[i][N])
            temp = dp[i][N];
    }        

    printf("%d\n", temp);
}
