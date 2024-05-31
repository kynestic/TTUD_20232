#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

int m, n, ans = 0;
int** arr;
int* histogram;

int findMaxRecent(){
	int tmpAns = 0;
	stack<int> st;
	
	for (int i = 1; i <= n + 1; i++){
		while (!st.empty() && histogram[st.top()] > histogram[i]){
			int tmp = st.top();
			st.pop();
			int width = !st.empty() ? i - st.top() - 1: i - 1;
			tmpAns = max(tmpAns, histogram[tmp]* width);
			//cout << i <<"-"<<tmp <<"-" << histogram[tmp] << "-"<<width <<" ";
		}
		
		
		st.push(i);
	}
	//cout <<tmpAns<< endl;
	
	return tmpAns;
}

void findMax(){
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++)
			histogram[j] = arr[i][j] == 0 ? 0 : histogram[j] + 1; 
		ans = max(ans, findMaxRecent());
	}
}

int main(){
	cin >> m >> n;
	arr = new int*[m + 1];
	histogram = new int[n + 2];
	
	for (int i = 1; i <= m; i++)
		arr[i] = new int[n + 1];
		
	for(int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
			
	for (int i = 1; i <= n + 1; i++)
		histogram[i] = 0;
	
	findMax();
	
	cout << ans;
	
	return 0;
}
