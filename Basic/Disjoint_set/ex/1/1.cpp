#include <cstdio>

int set[100000];
int rank[100000];
int group_cnt;

inline void make_set(int x){
    set[x] = x;
}

int find_set(int x){
    if(set[x] == x)
        return set[x];

    return set[x] = find_set(set[x]);
}

void union_set(int x, int y){
    x = find_set(x);
    y = find_set(y);

    //대표 노드가 같으면 함수 리턴
    if(x == y)
        return ;

    if(rank[x] < rank[y]){
        set[x] = y;
        group_cnt--;
    }
    else {
        set[y] = x;
        
        if(rank[x] == rank[y])
            rank[x]++;
        
        group_cnt--;
    }
}

int main(){
    int N, x, y;
    scanf("%d", &N);
                                          
    for(int i = 1; i <= N; i++){
        scanf("%d %d", &x, &y);

        if(set[x] == 0){
            group_cnt++;
            make_set(x);   
        }
        if(set[y] == 0){
            group_cnt++;
            make_set(y);
        }

        union_set(x, y);
    }
    printf("%d\n", group_cnt);
}
