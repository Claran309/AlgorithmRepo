#include <bits/stdc++.h>
using namespace std;
int M,N;
int v[20010];
int w[40];
int main(){
    int i,j;
    cin >> M >> N;
    for(i=1;i<=N;i++)
        cin >> w[i];
    for(i=1;i<=N;i++)
        for(j=M;j>=w[i];j--)
            if(v[j]<v[j-w[i]]+w[i]) v[j]=v[j-w[i]]+w[i];
    cout << M-v[M];
}
