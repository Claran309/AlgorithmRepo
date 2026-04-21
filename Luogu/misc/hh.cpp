#include <iostream>
#include <unistd.h>
//#include "hh.h"
using namespace std;

namespace chr{
	void chrswap(int& m,int& n){ 
    	int t = m;
    	m = n;
    	n = t;
    }
} 
namespace chr2{
	void write(){
		cout << ".";
		sleep(1);
	}
}

int main(){
	int a = 2,b = 5;
	chr::chrswap(a,b);
	std::cout << a << " " << b << endl;
	return 0;
}

