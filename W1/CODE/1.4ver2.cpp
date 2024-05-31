#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

int m, n;

int findRecentMax(vector<int>& height) {
    stack<int> st;
    height.push_back(0); // Thêm ph?n t? 0 d? x? lý d? dàng hon
    int maxS = 0;
    for (int i = 0; i <= n; i++) { // Duy?t t? 0 d?n n (do height.push_back(0) nên kích thu?c là n+1)
        while (!st.empty() && height[st.top()] > height[i]) {
        	cout << height[st.top()] << " " << height[i]<< endl;
            int h = height[st.top()];
            st.pop();
            int width = (st.empty()) ? i : i - 1 - st.top();
            maxS = max(maxS, width * h);
        }
        st.push(i);
    }
    height.pop_back(); // Lo?i b? ph?n t? 0 dã thêm vào
    return maxS;
}

void findMax(vector<vector<int>>& arr) {
    if (arr.empty()) return;
    int maxS = 0;
    vector<int> height(n, 0); // Kh?i t?o m?ng height v?i kích thu?c n
    
    for (int i = 0; i < m; i++) { // Duy?t t? 0 d?n m-1
        for (int j = 0; j < n; j++) { // Duy?t t? 0 d?n n-1
            height[j] = (arr[i][j] == 1) ? height[j] + 1 : 0;
        }
        maxS = max(maxS, findRecentMax(height));
    }
        
    cout << maxS;
    return;
}

int main() {
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n)); // Kh?i t?o m?ng 2D v?i kích thu?c m x n
    
    for (int i = 0; i < m; i++) { // Duy?t t? 0 d?n m-1
        for (int j = 0; j < n; j++) { // Duy?t t? 0 d?n n-1
            cin >> arr[i][j];
        }
    }
        
    findMax(arr);
    
    return 0;
}

