#include <bits/stdc++.h>//max:O(nlogn)
#define ll long long 
using namespace std;
struct chain{
	char s; 
	ll w,next,si,prev,f;
} st[1000000];
struct people{
	ll i1,i2,iw;
} u;
ll n,a,dance,boy,girl,lasti,lastj,ans1,ans2;
priority_queue<people,vector<people>,less<people> > q;
char inn[1000000];
bool operator < (people x,people y){
	if(x.iw == y.iw) return x.i1 > y.i1;
	return x.iw > y.iw;
}
int main(){
	cin >> n;
	cin >> inn+1;
	for(int i = 1;i <= n;i++){
		st[i].s = inn[i];
		if(inn[i] == 'B') boy++;
		else girl++;
		st[i].si = i;
		cin >> a;
		st[i].w = a;
		st[i].next = i+1;
		st[i+1].prev = i;
	}
	cout << min(boy,girl) <<endl;
	for(int i = 1;i < n;i++){
		if(st[i].f == 1) continue;
		if((st[i].s == 'B' && st[st[i].next].s == 'G') || (st[i].s == 'G' && st[st[i].next].s == 'B')){
			u.iw = abs(st[i].w-st[st[i].next].w);
			u.i1 = i;u.i2 = st[i].next;
			//cout <<i << " " << u.iw << " " << u.i1 << " " << u.i2 << endl;  BGBG
			q.push(u);
		}
	}
	ans1 = q.top().i1;ans2 = q.top().i2;
	lasti = st[q.top().i1].prev,lastj = st[q.top().i2].next;
	st[lasti].next = st[lastj].si;
	st[lastj].prev = st[lasti].si;
	st[q.top().i1].f = 1,st[q.top().i2].f = 1;
	st[q.top().i1].next = 0,st[q.top().i2].next = 0,st[q.top().i1].prev = 0,st[q.top().i2].prev = 0;
	q.pop();
	cout << ans1 << " " <<ans2 << endl;
	while(q.size()){
		if((st[lasti].f != 1 || st[lastj].f != 1) && (st[lasti].s == 'B' && st[lastj].s == 'G') || (st[lasti].s == 'G' && st[lastj].s == 'B')){ 
			u.iw = abs(st[lasti].w-st[lastj].w);
			u.i1 = st[lasti].si;u.i2 = st[lastj].si;
			q.push(u);
		}
		if(st[q.top().i1].f == 1 ||st[q.top().i2].f == 1) {//链表更新 
			q.pop();
			continue; //有了这一串,极限复杂度为O(3/2nlogn)----前面部分BG/GB全入堆  BGBGBGBGGBB  BGBGBGBGBGBGBGBGBGB
		} 
		ans1 = q.top().i1;ans2 = q.top().i2;
		lasti = st[q.top().i1].prev;
		lastj = st[q.top().i2].next;//lasti为左,lastj为右 
		if(lasti != 0) 
			st[lasti].next = st[lastj].si;
		if(lastj != n)
			st[lastj].prev = st[lasti].si;
		st[q.top().i1].f = 1,st[q.top().i2].f = 1;
		st[q.top().i1].next = 0,st[q.top().i2].next = 0,st[q.top().i1].prev = 0,st[q.top().i2].prev = 0;
		q.pop();
		cout << ans1 << " " <<ans2 << endl;
	}
	return 0;
}
/*
10
GBGBGGBBGB
1 1 1 1 514 1 9 198 1 1

5
1 2
3 4
9 10
6 7
5 8
*/
