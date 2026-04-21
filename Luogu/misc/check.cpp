#include <bits/stdc++.h>
using namespace std;
int tim;
double s,f;
int main(){
	system("CLS");
	double cccnt = 0;
	int scnt = 25,ccnt = 0,minc = 0,rest = 100;
	for(int i = 1;i <= 100;i++){
		system("CLS");
		ccnt++;
		rest--;
		cccnt+=0.01;
		if(ccnt == 4){
			if(scnt == 0){
				scnt = 59;
				minc--;
			}else
				scnt--;
			ccnt = 0;
		}
		printf("粗略估分中...... (预计等待时间: %d分%d秒)       剩余测试点:%d个     当前得分期望:%.2llf分   当前占时期望:%.3llfms\n",minc,scnt,rest,s/cccnt,tim/cccnt/100);
		system("makerthis.exe > makerthis.txt");
		double st = clock();
		system("better.exe <makerthis.txt> better.txt");
		double ed = clock();
		system("less.exe <makerthis.txt> less.txt");
		if(system("fc better.txt less.txt")){
			//printf("WA\n"); 
		}else{
			//printf("#%d  AC  %.0lfms\n",i,ed-st);
			tim+=ed-st;
			s++;
		}
	}
	system("CLS");
	printf("得分期望:%.2llf    平均占时:%.3llfms\n\n",s/cccnt,tim/100/cccnt);
	//更准确的估分  占用时间多    手动打开 
	printf("是否开启精确估分？(占用时间增大)如是请输入1:");
	cin >> f;
	if(f == 1){
		double cccnt = 1;
		int scnt = 45,ccnt = 0,minc = 3,rest = 900;
		for(int t = 2;t <= 10;t++)
			for(int i = 1;i <= 100;i++){
				system("CLS");
				ccnt++;
				rest--;
				cccnt+=0.01;
				if(ccnt == 4){
					if(scnt == 0){
						scnt = 59;
						minc--;
					}else
						scnt--;
					ccnt = 0;
				}
				printf("精准估分中...... (预计等待时间: %d分%d秒)       剩余测试点:%d个     当前得分期望:%.2llf分   当前占时期望:%.3llfms\n",minc,scnt,rest,s/cccnt,tim/cccnt/100);
				system("makerthis.exe > makerthis.txt");
				double st = clock();
				system("better.exe <makerthis.txt> better.txt");
				double ed = clock();
				system("less.exe <makerthis.txt> less.txt");
				if(!system("fc better.txt less.txt"))
					s++,tim+=ed-st;
			} 
		s/=10,tim/=10;
	}
	system("CLS");
	printf("得分期望:%.2llf    平均占时:%.2llfms\n",s/cccnt,tim/100/cccnt);
	system("pause");
	return 0;
}
