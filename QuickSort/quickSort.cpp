#include <bits/stdc++.h>
using namespace std;

int pivotElement(int arr[], int s, int e){

    int pivot = arr[s];
    int cnt = 0;

    for(int i=s+1; i<=e; i++){      // perfect position to put pivot element 
        if(arr[i] <= pivot) {
            cnt++;
        }
    }

    int pivotIndex = s + cnt;  // pivot element currect position
    swap(arr[pivotIndex], arr[s]);  // {5, 4, 2, 6, 9}
                                      //   ^            ^
    // sort left and right part to the pivot element 
    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex)    
    {
        while (arr[i] <= pivot){
            i++;
        }
        while(arr[j] >= pivot) {
            j--;
        }
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e){
    if(s>=e) 
        return;
    int p = pivotElement(arr, s, e); // partition
    quickSort(arr, s, p-1);   // sort left part
    quickSort(arr, p+1, e);   // sort right part
}

int main(){

    int arr[5] = {9, 4, 2, 6, 5};
    int n = 5;


    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}