#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>
#include<utility>//pair
#include<functional>//greater
#include<queue>
#include<set>
#include<string.h>
#include<algorithm>
#include<math.h>
#define F first
#define S second
#define sd(n) scanf("%d",&n)
#define sdd(m,n) scanf("%d %d",&m,&n)
#define sl(n) scanf("%I64d",&n)
#define sll(m,n) scanf("%I64d %I64d",&m,&n)
#define sc(n) scanf("%c",&n)
#define ss(n) scanf("%s",n)
#define pd(n) printf("%d\n",n)
#define pl(n) printf("%I64d\n",n)
#define pc(n) printf("%c\n",n)
#define ps(n) printf("%s\n",n)
#define NL printf("\n")
#define pb(n) push_back(n)
#define sz size()
#define clr(v,a,b) for(int i=a;i<=b;i++)v[i].clear()
#define all(v) v.begin(),v.end()
#define mod 1000000007//10^9+7
#define pp(a,b) make_pair(a,b)
/*#include<fstream>
ifstream fin("in.txt");
ofstream fout("out.txt");*/
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int MXN=200005;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int dxx[8]={0,1,1,1,0,-1,-1,-1};
int dyy[8]={1,1,0,-1,-1,-1,0,1};
int mo(int x)
{
    if(x<0)
        return -x;
    return x;
}
vector<int> a[100005];
int c[100005];
int vis[100005]={0};
int tm=1;
int root=0;
int dfs(int r)
{
    vis[r]=tm;
    int f=c[r];
    for(int j=0;j<a[r].sz&&f!=-1;j++)
    {
        int u=a[r][j];
        if(vis[u]!=tm)
        {
            int x=dfs(u);
            if(x!=-1)
            {
                if(r!=root&&x!=f)
                    f=-1;
            }
            else
                f=-1;
        }
    }
    return f;
}
int main()
{
    //freopen("test1.cpp","r",stdin);
    int n;
    sd(n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        sdd(u,v);
        a[u].pb(v);
        a[v].pb(u);
    }
    for(int i=1;i<=n;i++)
        sd(c[i]);
    int r1=0,r2=0;
    for(int i=1;i<=n&&r1==0;i++)
    {
        for(int j=0;j<a[i].sz;j++)
        {
            int u=a[i][j];
            if(c[i]!=c[u])
            {
                r1=u;
                r2=i;
                break;
            }
        }
    }
    if(!r1)
    {
        printf("YES\n");
        printf("1\n");
    }
    else
    {
        root=r1;
        int x=dfs(r1);
        root=r2;
        tm++;
        int y=dfs(r2);
        if(x!=-1)
            printf("YES\n%d\n",r1);
        else if(y!=-1)
            printf("YES\n%d\n",r2);
        else
            printf("NO\n");

    }
    return 0;
}