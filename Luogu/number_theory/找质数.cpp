


#include <bits/stdc++.h> 
using namespace std;

int main(){
	int n,s;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		for(int j = 2;j <= i;j++){
			if(i%j!=0){
				s+=1;
			}
		}
	}
	cout << s-2;
	return 0;
} 
/*


02

#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,max,min;
	cin >> a;
	int b[a];
	for(int i = 0;i <= a-1;i++){
		cin >> b[i];
		if(i >= 1){
			if(b[i-1] > b[i]){
				max = b[i-1];
				min = b[i];
			}else{
				max = b[i];
				min = b[i-1];
			}
		}
	} 
	if(a == 1){
		max = b[0];
		min = b[0];
	}
	cout << max << " " << min;
	
	return 0;
}

03




04

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,c;
	cin >> n;
	for(int i = 1;i <= n;i++){
		if(n % i == 0){
			c++;
		}
	}
	if(c == 2){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	
	return 0;
} 

#include <bits/stdc++.h>
using namespace std;

int main(){
	
	char c;
	scanf("%c",&c);
	int n,x;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
	    
		for(int j = 1;j <= n-i+1;j++){
			printf(" ");
            x = j;
		}
		for(;x <= n;x++){
			cout << c << " ";
			
		}
		cout << endl;
	}
	
	return 0;
} 

*/ 
