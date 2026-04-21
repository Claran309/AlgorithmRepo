
#include <iostream>
using namespace std;

void my_merge(int a[], int b[], int leftstart, int rightstart, int end){
    int leftend = rightstart - 1;
    int a_len = end - leftstart + 1;
    int cPos = leftstart;
    while (leftstart <= leftend && rightstart <= end) {
        if (a[leftstart] <= a[rightstart]) {
            b[cPos++] = a[leftstart++];
        } else {
            b[cPos++] = a[rightstart++];
        }
    }
    
    while (leftstart <= leftend) {
        b[cPos++] = a[leftstart++];
    }
    
    while (rightstart <= end) {
        b[cPos++] = a[rightstart++];
    }
    
    for (int i = 0; i < a_len; i++, end--) {
        a[end] = b[end];
    }
    
}

void merge_sort(int a[], int b[], int left, int right){
    
    if (left < right) {
        int mid = (left + right)/2; 
        merge_sort(a, b, left, mid);
        printf("merge(%d, %d)\n", left, mid);
        merge_sort(a, b, mid+1, right);
        printf("merge(%d, %d)\n", mid+1, right);
        my_merge(a, b, left, mid+1, right);
    }
    
}

int main(){
    
    int a[10] = {1, 3, 2, 5, 6, 7, 10, 9, 4, 8};
    int b[10];
    merge_sort(a, b, 0, 9);
    
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }

    return 0;
}




