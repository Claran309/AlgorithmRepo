#include<iostream>
using namespace std;
class Date{
private:
	int y,m,d;
public:
	void set(int y, int m, int d){
		this->y = y;
		this->m = m;
		this->d = d;
	}
	bool isleap(){
		if ((this->y % 4 == 0 && this->y % 100 != 0) || this->y % 400 == 0) return true;
		else return false;
	}
	int dayOfYear(){
		int a[12] = {31,28,31,30,31,30,31,31,30,31,30,31 };
		int number = 0;
		if (isleap()) a[1] = 29;
		for (int i = 0; i < this->m - 1; i++) 
			number += a[i];
		number += this->d;
		return number;
	}
	void print(){
		cout << this->y << "年" << this->m << "月" << this->d << "天";
	}
};
int main() {
	Date date;
	int y,m,d;
	cout << "请输入年月日：" << endl;
	cin >> y >> m >> d;
	system("CLS");
	date.set(y,m,d);
	date.print();
	cout <<"是这一年的第"<< date.dayOfYear() <<"天!"<< endl;
	return 0;
}
//
//This is the first attempt for Object Orientation
//Created by ss_charan on 2021/2/24.
