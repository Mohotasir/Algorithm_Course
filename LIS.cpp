#include <iostream>

using namespace std;

int lis(int arr[], int n) {
    // Initialize an array to store the length of LIS ending at each index
    int dp[n];
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
    }

    // Dynamic programming to find LIS
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    // Find the maximum value in the dp array
    int maxLIS = 0;
    for (int i = 0; i < n; ++i) {
        maxLIS = max(maxLIS, dp[i]);
    }

   cout<< maxLIS;
}

int main() {
    int sz;
    cin>>sz;
    int arr[sz];
    for(int i=0;i<sz;i++){
        cin>>arr[i];
    }
    lis(arr, sz);


    return 0;
}

