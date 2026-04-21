#include <bits/stdc++.h>
using namespace std;

int main(){
    int x,a,mid,left,right = 0; cin >> x >> a;
    int num[a];
    for(int i = 0;i < a;i++) cin >> num[i];
    left = 0; right = a - 1;
    while(left <= right){
        mid = (left + right) / 2;//重置mid值 
        if(x == num[mid]){//如果相等 
            cout << mid + 1; return 0;
        }else if(x > num[mid]) left = mid + 1;//向右缩减 
        else right = mid - 1;//向左缩减 
    }
    cout << "No";
    return 0;
} 
