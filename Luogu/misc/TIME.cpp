#include <iostream>
#include <ctime>
#include <unistd.h>
using namespace std;

int main(){
	system("color a");
	while(1){cout << time(0); sleep(1); system("CLS");}
	return 0;
} 
