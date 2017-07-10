#include <bits/stdc++.h>
using namespace std;
#define MAX 10005

int dp[3][4][MAX];
bool visit[3][4][MAX];

int dx[] = {-1,0,1,0,0};
int dy[] = {0,1,0,0,-1};

bool isValid(int x,int y){
    if(x<0 or y<0 or x>=3 or y>=4) return false;
    if((y==3) and (x==0 or x==2))
        return false;
    return true;
}

int fun(int x,int y,int level){
    if(level==1) return 1;
    if(visit[x][y][level]) return dp[x][y][level];

    visit[x][y][level] = true;
    int ans = 0;
    for(int i=0;i<5;i++){
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        if(isValid(x1,y1)) ans += fun(x1,y1,level-1);
    }

    dp[x][y][level] = ans;
    return ans;
}


int main() {
	int n;
	cin >> n;
	int res = 0;
	for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
        	if (isValid(i,j)) res += fun(i,j,n);
        }
	}
	cout << res << endl;
	return 0;
}
