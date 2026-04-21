#include <bits/stdc++.h>
using namespace std;

int main(){
	for(int t = 1;t <= 100;t++){
		system("maker.exe > maker.txt");
		double l = clock();
		system("one.exe <maker.txt> one.txt");//Õý½â 
		double r = clock();
		system("two.exe <maker.txt> two.txt");//±©Á¦ 
		if(system("fc one.txt two.txt")){
			printf("Wrong Answer");
			return 0;
		}
		else printf("#%d  Accepted - %.0lfms\n",t,r-l);
	}
	cout << endl <<"All Accepted!";
	return 0;
}
