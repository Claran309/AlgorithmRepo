#include <iostream>
#include <list>
using namespace std;

int main(){
	list<int> li;
	li.push_back(3);
	li.push_back(2);
	li.push_back(9);
	li.push_front(100);
	list<int>::iterator it;
	for(it = li.begin();it != li.end();it++) cout << *it << " ";
	return 0; 
}
