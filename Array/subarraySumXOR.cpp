#include <iostream>
#include <unordered_map>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int subarraysXor(vector<int> &arr, int k) {
  //    Write your code here.
  int xr = 0;
  map<int, int> mpp;
  mpp[xr]++; // zero th index value is set to 1.
  int count = 0;
  for (int i = 0; i < arr.size(); i++) {
    xr = xr ^ arr[i];

    int x = xr ^ k;

    count += mpp[x];

    mpp[xr]++;
  }
  return count;
}

int main(){
    vector<int> arr{5, 3, 8, 3, 10};
    // int k = 8;
    int lon = subarraysXor(arr, 8);
    cout << "The longest consecutive sequence is " << lon << endl;

    return 0;
}