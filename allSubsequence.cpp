#include <bits/stdc++.h>
using namespace std;

#define DEBUG(var) { cout << #var << ":" << (var) << endl; }
#define PRINT(var) { cout << var; }
#define PRINTLN(var) { cout << var << endl; }

#define ll long long
#define PI 3.14159265
#define pii pair< int, int >
#define MAX 10000

int n;
int arr[] = {1,2,3};
int temp[MAX];

void printSubsequence(int temp[],int idx,int b,int e){

    if(b > e){
        for(int i=0;i<idx;i++) cout << temp[i] << " ";
        cout << endl;
    }
    else{
        temp[idx] = arr[b];
        printSubsequence(temp,idx+1,b+1,e);
        printSubsequence(temp,idx,b+1,e);
    }

}


int main()
{
    n = 3;

    memset(temp,0,sizeof(temp));
    printSubsequence(temp,0,0,2);

    return 0;
}

