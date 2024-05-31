#include<iostream>
#include<limits.h>

using namespace std;

int n, m, minAns = INT_MAX, ans = 0;
int** arr;
bool flag = false;

void findPath(int r, int c){
	if (r == m && c == n){
		if (ans < minAns) minAns = ans;
		flag = true;
		return;
	}
	
	if (c < n && arr[r][c+1] != 0){
		ans += arr[r][c+1];
		findPath(r, c+1);
		ans -= arr[r][c+1];
	}
	
	if (c < n && r < m && arr[r+1][c+1] != 0){
		ans += arr[r+1][c+1];
		findPath(r+1, c+1);
		ans -= arr[r+1][c+1];
	}
	
	if (r < m && arr[r+1][c] != 0){
		ans += arr[r+1][c];
		findPath(r+1, c);
		ans -= arr[r+1][c];
	}
	
	return;
}

int main(){
	cin >> m >> n;
	arr = new int*[m + 1];
	for (int i = 1; i <= n; i++)
		arr[i] = new int[n + 1];
	
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	
	ans += arr[1][1];
	
	findPath(1, 1);
	
	if (!flag) 
		cout << -1;
	else
		cout << minAns;
	
	return 0;
}
