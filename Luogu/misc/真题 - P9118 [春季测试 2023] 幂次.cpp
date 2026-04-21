#include<bits/stdc++.h>
#define int long long
using namespace std;
int f[61],n,k,ans;
void solve2(){
	for(int b = 60;b >= k;b--){
		for(int g = b+b;g <= 60;g+=b) f[b]-=f[g];
		ans+=f[b];
	}
}
void solve1(){
	for(int b = k;b <= 60;b++){
		if(b == 2) f[b] = (int)(sqrtl(n)-1);//Éµ±ÆÌØÅÐ
		else f[b] = (int)(pow(n,1/(double)b)-1);
	}
}
signed main(){//mapÈ¥ÖØ 
    cin >> n >> k;
    solve1();
    solve2();
    cout << ans+1;
    return 0;
}
