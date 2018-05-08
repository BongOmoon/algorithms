#include <cstdio>
#include <cstdlib>

int * root;
int * rank;
int * size;
int largest = 1;

//make_set
void make_set(int n) {
	for(int i = 1; i <= n; i++){
		size[i] = 1;
		rank[i] = 0;
   		root[i] = i;	
	}
}

int find_set(int x) {
    if (x == root[x])
        return x;

    return root[x] = find_set(root[x]);
}

void union_set(int x, int y) {
    x = find_set(x);
    y = find_set(y);

    //대표노드가 같으면 리턴
    if (x == y)
        return;

    if (rank[x] > rank[y]){
    	root[y] = x;
    	size[x] += size[y];
	}
    else{
    	root[x] = y;
    	
    	if(rank[x] == rank[y])
    		rank[y]++;
    		
    	size[y] += size[x];
	}

    if (largest < size[x])
        largest = size[x];
}

int main(){
	int n, m;
	int x, y;
	scanf("%d %d", &n, &m);
	
    root = (int *)malloc(sizeof(int)*n+4);
    rank = (int *)malloc(sizeof(int)*n+4);
	size = (int *)malloc(sizeof(int)*n+4);
	
	make_set(n);
	
	for(int i = 0; i < m; i++){
		scanf("%d %d", &x, &y);
        union_set(x, y);
	}
	
	printf("%d\n", largest);
}
