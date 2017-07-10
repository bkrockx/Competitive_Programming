#include <bits/stdc++.h>
using namespace std;

#define MAX 105

int arr[MAX][MAX];
int n,m;
int sx,sy,dx,dy;
queue< pair<int, int> > myq;
int dis[MAX][MAX];

int ix[] = {-1,1,0,0};
int iy[] = {0,0,1,-1};

bool isSafe(int i,int j){
    if (i<0 || i>=n || j<0 || j>=m) return false;
    if(arr[i][j]==1) return false;
    return true;
}

void fun(int i,int j){
    dis[sx][sy]=0;
    myq.push( make_pair(i,j));
    while(!myq.empty()){
        int vi = myq.front().first;
        int vj = myq.front().second;
        myq.pop();
        for(int k=0;k<4;k++){
            int ni = vi + ix[k];
            int nj = vj + iy[k];
            if(isSafe(ni,nj)){
                if(dis[ni][nj]==-1){
                    dis[ni][nj] = (1 + dis[vi][vj]);
                    myq.push( make_pair(ni,nj));
                }
            }
        }

    }
}



int main()
{
    int t;
    char c;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dis[i][j] = -1;
                cin >> c;
                if(c=='S'){
                    sx = i;
                    sy = j;
                }
                if(c=='D'){
                    dx = i;
                    dy = j;
                }
                if(c=='#') arr[i][j] = 1;
                else arr[i][j] = 0;
            }
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }

        cout << "start indices:" << sx << "," << sy << "end indices:" << dx << "," << dy << endl;
        fun(sx,sy);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << dis[i][j] << " ";
            }
            cout << endl;
        }


    }
    return 0;
}
