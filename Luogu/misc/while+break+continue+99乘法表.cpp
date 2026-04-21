#include <bits/stdc++.h>

using namespace std;

int main(){
	for(int i = 1;i <= 9;i++){
		for(int j = 1;j <= i;j++){
			if(i*j >=10){
				printf("%d*%d=%d  ",j,i,i*j);
			}else{
				printf("%d*%d=%d   ",j,i,i*j);
			}
		
		}
		printf("\n");
	}
	return 0;
}
//continue 跳过该循环
//break 中断该循环 
//" ＜ to be continued 标准结局 "
/*
     取各位方法（三位数）(变量名限整数变量)：
	 1.个位： '变量名' %10
	 2.十位： '变量名' /10%10
	 3.百位： '变量名' /100 
      ......（以此类推） 
*/
/*嵌套循环(example)：
    for(int i = '起始值';i <= '行数';i++){
		for(int j = '起始值';j <= i;j++){
			功能语句; 
		}
		printf("\n");
	}
 */
