#include <bits/stdc++.h>
using namespace std;
int score[11];
double s;
int main(){
	for(int i = 1;i <= 100;i++){
		system("makerthis.exe > makerthis.txt");
		double st = clock();
		system("better.exe <makerthis.txt> better.txt");
		double ed = clock();
		system("less.exe <makerthis.txt> less.txt");
		if(system("fc better.txt less.txt")){
			printf("WA\n");
		}else{
			printf("#%d  AC  %,0lfms",i,ed-st);
			s++;
		}
	}
	//更准确的估分  占用时间多    手动打开 
	/*
	for(int t = 2;t <= 10;t++)
		for(int i = 1;i <= 100;i++){
			system("makerthis.exe > makerthis.txt");
			system("better.exe <makerthis.txt> better.txt");
			system("less.exe <makerthis.txt> less.txt");
			if(!system("fc better.txt less.txt"))
				score[t]++;
		}
	for(int i = 2;i <= 10;i++) s += score[i];
	s /= 10;
	*/
	cout << endl << "得分：" << s;
	system("pause");
	return 0;
}
