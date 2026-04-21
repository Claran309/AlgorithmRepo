#include <bits/stdc++.h>
using namespace std;
int main(){ 
    int a[10001],s = 0,i,n;
    bool t = 0;
    cin>>n;
    for(int i = 0 ;i < n;i++) cin >> a[i];
    for(i = 1;i <= n;i++){ 
        if(a[i] < a[i-1]) t=1;
        if(t==1 && a[i] > a[i-1]){ 
            s++;
            t = 0; 
        } 
    } 
    cout << s;
    return 0;
} 
//ac
