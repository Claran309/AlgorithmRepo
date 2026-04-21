#include <bits/stdc++.h>
using namespace std;
string S,P;
int next[255];
int kmp(string S,string P){
	int i = 0, j = 0;
	int s_len = S.size();
	int p_len = P.size();
	while(i < s_len && j < p_len){
		if(j == -1 || S[i] == P[j]){
			i++;
			j++;
		}else j = next[j];
		if(j == p_len) return i-j;
	}
	return -1;
} 
void GetNext(string P){a
	next[0] = -1;
	int p_len = P.size();
	int i = 0,j = -1;
	while(i < p_len)
		if(j == -1 || P[i] == P[j]){
			i++;
			j++;
			next[i] = j;
		}else j = next[j];
}
int main(){
	cin >> S >> P;
	GetNext(P);
	cout << kmp(S,P);
	return 0;
} 

