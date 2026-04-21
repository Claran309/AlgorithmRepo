#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <unistd.h>
using namespace std;

int need,persons,cnt,sum;

struct milker{
	int money,much;
} m[10000];

bool cmp(milker x,milker y){
	return x.money <= y.money;
}

int main(){
	cin >> need	>> persons;
	for(int i = 0;i < persons;i++) cin >> m[i].money >> m[i].much;
	sort(m,m+persons,cmp);
	while(need > 0){
		if(m[cnt].much > need){
			need -= m[cnt].much;
			sum += m[cnt].money*m[cnt].much;
		}else{
			sum += need*m[cnt].money;
			need = false;
		}
		cnt++;	
	}
	cout << sum;
	return 0;
}
