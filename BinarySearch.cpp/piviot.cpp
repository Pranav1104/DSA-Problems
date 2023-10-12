#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll MOD = 1e9 + 7;


int solution(vector<int> arr, int n){
    fast_cin();
    int s=0, e=n-1, mid;
    while (s<e)
    {
        mid = s + (e-s)/2;
        if(arr[mid] >= arr[0]) s = mid + 1;
        else e = mid;
    }
    return s;
}

int main(){
    fast_cin();   // fast input output
    vector<int> arr{4,5,6,7,1};
    cout<<"Answer: "<<solution(arr, 5);

    return 0;
}