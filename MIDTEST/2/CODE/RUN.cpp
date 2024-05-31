#include<iostream>

using namespace std;

int main(){
	int n, ans = 1;
	int* arr;
	cin >> n;
	arr = new int[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
		
	for (int i = 2; i <= n; i++)
		if (arr[i] <= arr[i-1])
			ans++;
			
	cout << ans;
	return 0;
}
