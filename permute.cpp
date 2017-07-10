#include <bits/stdc++.h>
using namespace std;
#define MAX 10005
#define ll long long int
int arr[MAX];
set<string> st;

void perm(string str,int k,int n){
    if(k==n) st.insert(str);
    else{
        for(int i=k;i<=n;i++){
            swap(str[k],str[i]);
            perm(str,k+1,n);
            swap(str[k],str[i]);
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while(t--){
        string str;
        cin >> str;
        st.clear();
        perm(str,0,str.length()-1);
        set<string> :: iterator itr;
        for(itr=st.begin();itr!=st.end();itr++) cout << *itr << endl;
    }
    return 0;
}
