#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll MOD = 1e9 + 7;


int findMin(vector<int>& nums) {
    int s = 0, e = nums.size()-1, mid;
    while(s<e){
        if(nums[s]<nums[e]) return nums[s];
        mid = s + (e-s)/2;
        if(nums[mid]>=nums[0]) s = mid+1;
        else e = mid;
    }
    return nums[s];
}

int main(){
    fast_cin();
    vector<int> arr{3,4,5,1,2};
    vector<int> arr1{11,13,15,17};
    cout<<findMin(arr1);

    return 0;
}