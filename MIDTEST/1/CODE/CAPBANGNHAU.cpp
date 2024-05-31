#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
	unordered_map<int, int> vt;
	int n, tmp, ans = 0;
	
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> tmp;
		if (!vt[tmp]){
			vt[tmp] = 1;
			continue;
		}
		vt[tmp]++;
	}
	
	for (auto& it : vt){
		tmp = it.second;
		ans += (tmp - 1) * tmp / 2;
	}
	
	cout << ans;
	return 0;
}
