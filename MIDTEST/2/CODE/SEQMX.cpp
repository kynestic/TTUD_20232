#include<iostream>
#include<limits.h>
#include<float.h>

using namespace std;

int main(){
	int n, k;
	double max = -DBL_MAX;
	cin >> n >> k;
	int* arr = new int[n + 1];
	long long* sumArr = new long long[n + 2];
	
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
		
	sumArr[0] = arr[1];	
	for (int i = 1; i <= n; i++)
		sumArr[i] = sumArr[i - 1] + arr[i];
		
	for (int i = 1; i <= n; i++)
		for (int j = i + k - 1; j <= n; j++){
			double tmp = (double) (sumArr[j] - sumArr[i - 1]) / (j - i + 1);
			if (tmp > max) max = tmp;
			cout << tmp << endl;
		}
	
	cout << max;
	return 0;
}
