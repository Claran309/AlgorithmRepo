#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num;         
    cin >> num;      
    int a[num][num]; 
    int i, j;       
    for (i = 1; i <= num; i++)
    {
        for (j = 1; j <= i+1; j++)
        {
            if (j == 1 || i == j)
                a[i][j] = 1;
            else
            {
                a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
            }
            cout << a[i][j] << " "; 
        }
        cout << endl; 
    }
    return 0;
}
//23333233
