#include <bits/stdc++.h>
using namespace std;
struct fruit{
	string type;
	int price;
} f1,f2,f3;
bool operator < (fruit x,fruit y){
	return x.price < y.price;
}
int main(){
	cin >> f1.type >> f1.price >> f2.type >> f2.price >> f3.type >> f3.price;
	priority_queue<fruit,vector<fruit>,less<fruit> > q;
	q.push(f1);q.push(f2);q.push(f3);
	cout << q.top().type << " " << q.top().price;
	return 0;
} 
/*
Æ»¹û 10
Àõ×Ó 12
Ó£ÌÒ 8
*/
