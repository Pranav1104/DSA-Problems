#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll MOD = 1e9 + 7;

void merge(int *arr, int s, int e){
    int mid = (s+e)/2;
    int len1 = mid - s + 1; // Adjusted the length calculation
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    for (int i = 0; i < len1; i++) {
        first[i] = arr[s + i]; // Copy values from s to mid
    }

    for (int i = 0; i < len2; i++) {
        second[i] = arr[mid + 1 + i]; // Copy values from mid+1 to e
    }

    int index1 = 0;
    int index2 = 0;
    int mainArray = s;

    while (index1 < len1 && index2 < len2){
        if (first[index1] < second[index2]) {
            arr[mainArray++] = first[index1++];
        }
        else {
            arr[mainArray++] = second[index2++];
        }
    }

    while (index1 < len1) {
        arr[mainArray++] = first[index1++];
    }
    while (index2 < len2) {
        arr[mainArray++] = second[index2++];
    }
    delete[] first;
    delete[] second;
}

void mergeSort(int *arr, int s, int e){
    if (s >= e) {
        return;
    }

    int mid = (s+e)/2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);
    merge(arr, s, e);
}

int main(){
    fast_cin();
    
    int arr[7]{9, 8, 5, 4, 6, 2, 7};
    int n = 7;

    mergeSort(arr, 0, n-1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
