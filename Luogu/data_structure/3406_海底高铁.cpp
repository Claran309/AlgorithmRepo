#include <bits/stdc++.h>
using namespace std;
long long station[100050],n,m,t,a,b,c,station_list,ans;
int main(){
    cin >> n >> m,station_list;
    for(long long i = 2;i <= m;i++){
        cin >> t;
        if(station_list<t){//²é·Ö 
            station[station_list]++;
            station[t]--;
        }
        else{
            station[t]++;
            station[station_list]--;
        }
        station_list = t;
    }
    for(long long i = 1;i <= n - 1;i++) station[i] += station[i-1];
    for(long long i = 1;i <= n - 1;i++){
        cin >> a >> b >> c;//Ì°ÐÄ 
        if(a * station[i] < c + b * station[i]) ans += a * station[i];
        else ans += c + b * station[i];
    }
    cout << ans;
    return 0;
}
