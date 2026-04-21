#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long int b,p,k,s;
long long int pow(long long int a,long long int c){
    long long int r=1,base=a;
    while(c){
        if(c&1)r=r*base%k;
        base=base%k*base%k;
        c>>=1;
    }
    return r;
}
int main(){
    cin>>b>>p>>k;
    s=pow(b,p)%k;
    cout<<b<<"^"<<p<<" mod "<<k<<"="<<s;
}
