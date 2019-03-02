#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int map[101][101];
    int dp[101][101];
    int n, m; //지도는 n*m 사이즈  ( n, m <= 100)
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &map[i][j]);
        }
    }

	//지도 사이즈가 1*1일 때 그대로 출력 
    if(n == 1 && m == 1)
        printf("%d\n", map[1][1]);
    else{
    	//지도에서 택시는 오른쪽, 아래쪽으로만 갈 수 있다. 
        dp[1][1] = map[1][1];

		//지도의 1번째 행과 열을 dp로 구한다. 
        for (int i = 2; i <= n; i++){
            dp[1][i] = map[1][i] + dp[1][i - 1];
            dp[i][1] = map[i][1] + dp[i - 1][1];
        }
		
		//위에서 저장한 값을 기반으로 (n, m)위치까지 최소 값을 구한다. 
        for (int i = 2; i <= n; i++) {
            for (int j = 2; j <= m; j++){
                dp[i][j] = map[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    printf("%d\n", dp[n][m]);
}
