#include <bits/stdc++.h>
using namespace std;
struct tree_tree{
	int ai,bi;
};
int cnt,n,sum;

bool cmp(tree_tree a,tree_tree b){
	if(a.bi < b.bi) return true;
	else return false;
}

int main(){
	cin >> n;
	tree_tree tree[n];
	for(int i = 0;i < n;i++){
		cin >> tree[i].ai;
	}
	for(int i = 0;i < n;i++){
		cin >> tree[i].bi;
	}
	sort(tree,tree+n,cmp);
	for(int i = 0;i < n;i++){
		sum += tree[i].ai + tree[i].bi*cnt;
		cnt += 1;
	}
	cout << sum;
	return 0;
}
