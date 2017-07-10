#include <bits/stdc++.h>
using namespace std;
#define MAX (1 << 21)
#define mod 10000007
using namespace std;

int value,n,num,s_size,big_size;
bool vis[1005][1<<11];
int dp[1005][1<<11];
int cnt[MAX];
vector<int> v1,v2;

int fun(int i,int x){
    if ( i == s_size ) return cnt[x^value];

    if(vis[i][x]) return dp[i][x];
    vis[i][x] = true;
    int ans = fun(i+1,x) + fun(i+1,x^v1[i]);
    if ( ans >= mod ) ans -= mod;
    dp[i][x] = ans;
    //cout << "i:" << i << "," << "x:" << x << "," << "ans:" << ans << endl;
    //cout << endl;
    return ans;
}


int main()
{
    cin >> n >> value;
    for(int i=0;i<n;i++){
        cin >> num;
        if(num > (1<<10)) v2.push_back(num);
        else v1.push_back(num);
    }

    s_size = v1.size();
    big_size = v2.size();

    //cout << "small size :" << s_size << endl;
    //cout << "big size :" << big_size << endl;

    for(int i=0;i<(1 << big_size);i++){
        int val = 0;
        for(int j=0;j<big_size;j++){
            if (i & (1 << j)){
                val = val^v2[j];
            }
        }
        //if(val==value) cnt++;
        cnt[val]++;
    }

    int res = fun(0,0)%mod;
    cout << res << endl;
}
