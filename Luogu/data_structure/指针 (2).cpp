#include <bits/stdc++.h>
using namespace std;
int main(){
	char a[] = {'1','2','3','4','5'};
	int* pa = (int*)a;
	int*& pb = pa;
	pb++;
	printf("%c\n",*pa);
	return 0;
}
