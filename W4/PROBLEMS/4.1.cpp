#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    long long maxEvenSum = 0; // T?ng ch?n l?n nh?t
    long long maxOddSum = LLONG_MIN; // T?ng l? l?n nh?t, b?t d?u t? giá tr? nh? nh?t có th?
    
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            maxEvenSum += arr[i];
            if (maxOddSum != LLONG_MIN) {
                maxOddSum += arr[i];
            }
        } else {
            long long newMaxOddSum = maxEvenSum + arr[i];
            long long newMaxEvenSum = (maxOddSum == LLONG_MIN) ? LLONG_MIN : (maxOddSum + arr[i]);

            maxOddSum = max(maxOddSum, newMaxOddSum);
            maxEvenSum = max(maxEvenSum, newMaxEvenSum);
        }
    }
    
    if (maxEvenSum == 0) {
        cout << "NOT_FOUND";
    } else {
        cout << maxEvenSum;
    }
    
    return 0;
}

