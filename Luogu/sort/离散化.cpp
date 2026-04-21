void discrete(){
	sort(a+1,a+n+1);
	int m = 0;
	for(int i = 1;i <= n;i++)
		if(i == 1 || a[i] != a[i-1]) b[++m] = a[i];
}
void query(int x){
	return lower_bound(b+1,b+m+1,x)-b;
}
b[i] = query(b[i]);
//b[i] 即为映射后的数组 
