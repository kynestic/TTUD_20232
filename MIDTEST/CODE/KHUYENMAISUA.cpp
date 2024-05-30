#include<iostream>

using namespace std;

int n, count = 0, limit;
bool* ans;
int* arr;

void cal(int k){
	if (k > n){
		int sum = 0;
		for (int i = 1; i <= n; i++){
			if (ans[i])
				sum += arr[i];
		}
		if (sum >= limit){
			count++;
			cout << sum << endl;
		} 
		return;
	}
	
	ans[k] = true;
	cal(k + 1);
	ans[k] = false;
	cal(k + 1);
	return;
}

int main(){
	cin >> n;
	arr = new int[n + 1];
	ans = new bool[n+1];
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	cin >> limit;
	cal(1);
	
	cout << count;
	return 0;
}
