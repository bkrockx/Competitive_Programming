#include <bits/stdc++.h>
using namespace std;

#define MAX 105
#define pii pair< int, int >

int n,m;
int dis[MAX];
bool visit[MAX];

struct comp{
    bool operator() (const pii &a, const pii &b){
        return a.second > b.second;
    }
};

priority_queue< pii, vector< pii >, comp > myq;
vector<pii> v[MAX];



void solve(int src){
    dis[src] = 0;
    myq.push(pii(src,0));

    while(!myq.empty()){
        int u = myq.top().first;
        int dist = myq.top().second;

        myq.pop();
        for(int idx = 0;idx<v[u].size();idx++){
            int node = v[u][idx].first;
            int wt = v[u][idx].second;
            if(dis[node] > dis[u]+wt || dis[node]==-1){
                dis[node] = (dis[u] + wt);
                myq.push(pii(node,dis[node]));
            }
        }

    }


}


int main()
{
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0;i<n;i++){
        	dis[i] = -1;
        	v[i].clear();
        }

        while(m--){
            int x,y,z;
            cin >> x >> y >> z;
            v[x].push_back(pii(y,z));
            v[y].push_back(pii(x,z));
        }

        /*
        for(int i=0;i<n;i++){
            for(int j=0;j<v[i].size();j++){
                cout << v[i][j].first << " " << v[i][j].second << endl;
            }
            cout << endl;
        }
        */
        solve(0);

        //for(int i=0;i<n;i++) cout << dis[i] << endl;
        cout << dis[n-1] << endl;

    }
    return 0;
}
