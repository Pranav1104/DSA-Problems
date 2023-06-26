#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int maxLen(vector<int>& A)
{
    unordered_map<int, int> mpp;
    int maxi = 0;
    int sum = 0;
    for (int i = 0; i < A.size(); i++)
    {
        sum += A[i];
        if (sum == 0)
        {
            maxi = i + 1;
        }
        else
        {
            if (mpp.find(sum) != mpp.end())
            {
                maxi = max(maxi, i - mpp[sum]);
            }
            else
            {
                mpp[sum] = i;
            }
        }
    }

    return maxi;
}

int main()
{
    vector<int> arr{100, 200, 1, 2, -3, 4};
    int lon = maxLen(arr);
    cout << "The longest consecutive sequence is " << lon << endl;

    return 0;
}
