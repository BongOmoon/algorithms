#include <cstdio>
#include <vector>

int max(int a, int b) {
    return a > b? a : b;
}

int countViewArea(std::vector<int>& buildings) {
    int viewAreas = 0;

    for(int i = 2; i < buildings.size() - 2; ++i) {
        int temp = buildings[i] - max(max(buildings[i - 1], buildings[i - 2]), max(buildings[i + 1], buildings[i + 2]));
        if(temp > 0) {
            viewAreas += temp;
        }
    }
    
    return viewAreas;
}

int main(int argc, char** argv) {
    std::vector<int> buildings;

	for(int tc = 1; tc <= 10; ++tc) {
        int n;
        scanf("%d", &n);

        while(n--) {
            int height;
            scanf("%d", &height);
            buildings.push_back(height);
        }
        
        printf("#%d %d\n", tc, countViewArea(buildings));
        buildings.clear();
	}
    
	return 0;
}