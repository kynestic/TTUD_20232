#include<iostream>

using namespace std;

int count = 0, n;
bool taken[10];
int arr[10];

void checkSum(int h, int u, int s, int t, int o, int i, int c){
	if (h*1000 + u*100 + s*10 + t  +  s*10000 + o*1000 + i*100 + c*10 + t == n)
		count++;
	return;
}

bool checkNum(int i, int a){
	if (taken[a]) return false;
	if (i == 1 && a == 0) return false;
	if (i == 3 && a == 0 ) return false;
	if (i == 3 && a*10000 > n) return false;
	if (i == 4 && 2*a % 10 != n%10) return false;
	
	return true;
}

void resetTaken(){
	for (int i = 0; i <= 9; i++){
		taken[i] = false;
	}
}

void findAns(int k){
	if (k > 7){
		checkSum(arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7]);
		return;
	}
	
	for (int i = 0; i <= 9; i++)
		if (checkNum(k, i)){
			taken[i] = true;
			arr[k] = i;
			findAns(k + 1);
			taken[i] = false;
		}
		
	return;
}

int main(){
	int tmp;
	cin >> tmp;
	
	while (tmp--){
		cin >> n;
		resetTaken();
		findAns(1);
		cout << count;
		count = 0;
	}
	
	return 0;
}
