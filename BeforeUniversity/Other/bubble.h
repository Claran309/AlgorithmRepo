#include <algorithm>
#include <iostream>

int bubble(int a[]){
	int b = a.length;
	for(int i = 0;i < b-1;i++) 
	    for(int j = 0;j < b-1-i;j++) //j < b-1亦可，但是b-1-i会提高效率 
	    	if(a[j] > a[j+1]) 
	    		swap(a[j],a[j+1]);
	return a;
}
