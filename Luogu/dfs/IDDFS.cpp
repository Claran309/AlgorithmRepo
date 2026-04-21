#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#define maxn 10001
#define inf 0x3fffffff
typedef long long ll;
ll a, b, g, deep, flag, v[maxn], ans[maxn];
using namespace std;

ll gcd(ll a, ll b){
    if (b == 0) {
        return a;
    }
    return gcd(b, a%b);
}

void dfs(ll a, ll b, int d){
    if (d==deep) {
        if (b%a) return;
        if (b/a==v[d-1]) return;
        flag = 1;
        v[d] = b/a;
        //找最佳答案
        int cmp=0;
        for (int i = d; i>0; i--) {
            if (ans[i]==v[i]) {
                continue;
            }
            if (ans[i]<v[i]) {
                break;
            }else{//原来的答案更大了一些-， 所以需要更新
                cmp = 1; break;//更新数据
            }
            
        }
        if (cmp ==1) {
            memcpy(ans, v, sizeof(ll)*(d+1));
        }
        
        return;
    }
    //必然满足这个条件， 满足更好条件
    //   1/i * (deep-d+1) < a /b 当前的 每次的开头
    // b*(deep-d+a) < a * i
    for (int i = max(b/a+1, v[d-1]+1); ; i++) {
        if (b*(deep-d+1) < a * i) break;
        v[d] = i; // a / b = 1/i,
        ll b2 = b*i;
        ll a2 = a*i-b;
        g = gcd(a2, b2);
        b2/=g;
        a2/=g;
        dfs(a2, b2, d+1);
    }
    
}


int main(){
    
    int a, b;
    cin >> a >> b;
    if (b%a==0) {
        cout << b/a << endl;
        return 0;
    }
    g = gcd(a, b);
    a = a / g;
    b = b / g;
    
    
    for (deep = 2;; deep++) {
        ans[1] = 0;
        ans[deep] = inf;//最后一项弄为很大， 比这个小就替换
        dfs(a, b, 1);//当前第1层
        if (flag) break;//如果flag 是1， 就说明找到了答案
    }
    
    
    for (int i = 1; i <= deep; i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}
