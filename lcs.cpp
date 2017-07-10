#include <bits/stdc++.h>
using namespace std;
#define MAX 10005
#define ll long long int
#define MOD 1000000007

int m,n;
int a[MAX];
bool vis[MAX][MAX];

string str1;
string str2;
int dp[MAX][MAX];

int lcs(int i,int j){

    if(i==0||j==0) return 0;
    if(vis[i][j]) return dp[i][j];

    vis[i][j] = true;
    int ans = 0;

    if(str1[i-1]==str2[j-1]) ans = (1+lcs(i-1,j-1));
    else ans = max(lcs(i-1,j),lcs(i,j-1));

    dp[i][j] = ans;
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        cin >> str1 >> str2;
        m = str1.length();
        n = str1.length();
        int res = lcs(m,n);
        cout << res << endl;
    }
    return 0;
}
