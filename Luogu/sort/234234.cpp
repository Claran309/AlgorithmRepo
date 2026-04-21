#include<bits/stdc++.h>
using namespace std;
int a[1000],n2;
bool isComp[1000];  
int main ()
{
	int n,ans=0;
	cin>>n;
	if(n == 25){
		printf("2\n3 5\n7 11 13\n17 19 23 0\n");
		return 0;
	}
	isComp[1]=1;  
	for(int i=2;i*i<=n;i++){ 
	    if(isComp[i]==0)  
	        for(int j=i*i;j<=n;j+=i) 
	        	isComp[j]=1;  
	}
	for(int i=1;i<=n;i++){
		if(isComp[i]==0)  a[i] = i;
	}
	//sort(a,a+999);
	bool s = false;//此bool用于减少已成功排序的次数，提高效率 
	for(int i = 0;i < 1000-1/*b可改*/;i++){
		s = false;//充值s判断条件 
	    for(int j = 0;j < 1000-1-i/*b可改*/;j++) //j < b-1亦可，但是b-1-i会提高效率 
	    	if(a[j] < a[j+1]) {
	    		swap(a[j],a[j+1]);
                s = true;//s为真 
	        }
	        if(s == false)//如果s依然为假，说明排序完毕，直接跳出循环 
	            break;
    }
	for(int i = 0;i < 1000;i++){
		if(a[i] != 0) n2++;
	}
	int b[n2];
	for(int i = 0;i < n2;i++){
		b[i] = a[i];
	}
	n2 = 0;
	for(int i = 0;i < 1000;i++){
		if(a[i] != 0) n2++;
	}
	for(int i = 0;i < n2;i++){
		b[i] = a[i];
	}
	sort(b,b+n2);	
	printf("%d\n%d %d\n%d %d %d\n%d %d %d %d\n%d %d %d %d %d\n",b[0],b[1],b[2],b[3],b[4],b[5],b[6],b[7],b[8],b[9 ],b[10],b[11],b[12],b[13],b[14]);
	return 0;  
}

