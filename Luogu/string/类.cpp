#include <bits/stdc++.h>
using namespace std;
class Hero{
	
public:
	string F1,F2,F3,name;
	int HP,strong;
	Hero(string a,string b,string c,string d,int e,int f){
		this->F1 = a;
		this->F2 = b;
		this->F3 = c;
		this->name = d;
		this->HP = e;
		this->strong = f;
	}	
	void use1(){
		cout << this->F1;
	}
};
int main(){
	Hero egg = Hero("boom","fire","plane","egg",1000,200);
	return 0;
}
