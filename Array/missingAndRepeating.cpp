#include <bits/stdc++.h>
using namespace std;

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    int SN = (n * (n + 1)) / 2;
    int SN2 = (n * (n + 1) * (2 * n + 1)) / 6;
    int S = 0, S2 = 0;

    for (int i = 0; i < n; i++) {
        S += arr[i];
        S2 += arr[i] * arr[i];
    }

    int val1 = S - SN; // X - Y
    int val2 = S2 - SN2; // X^2 - Y^2

    val2 = val2 / val1; // X + Y

    int x = (val1 + val2) / 2;
    int y = x - val1;

    return {x, y};
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    pair<int, int> result = missingAndRepeating(arr, n);
    cout << "Repeating number: " << result.first << endl;
    cout << "Missing number: " << result.second << endl;

    return 0;
}
