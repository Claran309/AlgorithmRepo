#include <iostream>
using namespace std;
bool a[100000001];
int main()
{
    int n,i,j,s=0;
    cin >> n;
    s=n-1;
    for(i=2;i*i<=n;i++){
	    if(a[i]==0){
            for(j=i*i;j<=n;j+=i){
                if(a[j]==0){
			        a[j]=1;
                    s--;
		        	}
          	}
        }
	}
    cout << s;
    return 0;
}


