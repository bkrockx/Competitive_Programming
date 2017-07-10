#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
 
const int ND = 112;
int mark[ND][ND];
bool visit[ND][ND];
 
bool valid(int x,int y,int n,int m){
	if (x < 1 or y < 1 or x > n or y > m)
		return false;
	return true;
}
 
int parse(string &loc,int n,int m){
	int len = loc.size();
	if (len < 2) return -1;
	int cnt = 0;
	if (loc[0] != '{' or loc[len-1] != '}')
		return -1;
	int i = 1;
	while(true){
		if (loc[i] == '}' and loc[i-1] != ')') return -1;
		if (loc[i] == '}') break;
		if (loc[i] != '(') return -1;
		++i;
 
		int num1 = 0,num2 = 0;
		while(loc[i] >= '0' and loc[i] <= '9'){
			num1 = num1*10 + (int)(loc[i]-'0');
			++i;
		}
 
		if (loc[i] != ',') return -1;
		++i;
 
		while(loc[i] >= '0' and loc[i] <= '9'){
			num2 = num2*10 + (int)(loc[i]-'0');
			++i;
		}
 
		if (loc[i] != ')') return -1;
		++i;
 
		if (!valid(num1,num2,n,m)) return -1;
		if (mark[num1][num2]) {
			return -1;
		}
 
		mark[num1][num2] = 1;
		++cnt;
 
		if (i < len-1 and loc[i] != ',') return -1;
		if (i < len-1) ++i;
	}
 
	if (cnt < 3) return -1;
	if (cnt > (n*m)) return -1;
	return 0;
}
 
int f(int x,int y,int dx,int dy,int n,int m){
	int cnt = 0;
	int x1 = x, y1 = y;
	while(valid(x,y,n,m)){
		if (!mark[x][y])
			return 0;
		x += dx;
		y += dy;
		++cnt;
	}
 
	x = x1, y = y1;
	while(valid(x,y,n,m)){
		visit[x][y] = true;
		x += dx;
		y += dy;
	}
 
	return cnt;
}
 
bool input_check(int n,int m){
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if (mark[i][j] and !visit[i][j])
				return false;
		}
	}
	return true;
}
 
int solve(int n,int m,string &loc){
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) 
			mark[i][j] = visit[i][j] = 0;
 
	if (n > 100 or n < 1) return -1;
	if (m > 100 or m < 1) return -1;
 
	int res = parse(loc,n,m);
 
	if (res != 0) return res;
	int ans = 0;
 
	for(int dx = -101; dx <= 101; ++dx){
		for(int dy = -101; dy <= 101; ++dy){
			if (dx == 0 and dy == 0) continue;
			for(int i = 1; i <= n; ++i){
				for(int j = 1; j <= m; ++j){
					int x = i-dx;
					int y = j-dy;
					if (valid(x,y,n,m)) continue;
					ans = max(ans,f(i,j,dx,dy,n,m));
				}
			}
		}
	}
 
	if (!input_check(n,m))
		return -1;
	return ans;
}
 
int main()
{
	int n = 100;
	int m = 100;
	string inp = "{(2,1),(6,6),(4,2),(2,5),(2,6),(2,7),(3,4),(6,1),(6,2),(2,3),(6,3),(6,4),(6,5),(6,7)}";
	// string inp = "{(2,2),(3,3),(4,4),(5,5)}";
	cout << solve(n,m,inp) << endl;
	return 0;
}