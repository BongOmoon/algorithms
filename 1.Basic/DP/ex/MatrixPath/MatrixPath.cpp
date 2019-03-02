#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int map[101][101];
    int dp[101][101];
    int n, m; //������ n*m ������  ( n, m <= 100)
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &map[i][j]);
        }
    }

	//���� ����� 1*1�� �� �״�� ��� 
    if(n == 1 && m == 1)
        printf("%d\n", map[1][1]);
    else{
    	//�������� �ýô� ������, �Ʒ������θ� �� �� �ִ�. 
        dp[1][1] = map[1][1];

		//������ 1��° ��� ���� dp�� ���Ѵ�. 
        for (int i = 2; i <= n; i++){
            dp[1][i] = map[1][i] + dp[1][i - 1];
            dp[i][1] = map[i][1] + dp[i - 1][1];
        }
		
		//������ ������ ���� ������� (n, m)��ġ���� �ּ� ���� ���Ѵ�. 
        for (int i = 2; i <= n; i++) {
            for (int j = 2; j <= m; j++){
                dp[i][j] = map[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    printf("%d\n", dp[n][m]);
}
