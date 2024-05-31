#include<iostream>
#include<stack>
#include<queue>

using namespace std;
stack<int> st;
queue<int> q;


int main(){
	int n, tmp;
	int* arr;
	cin >> n;
	arr = new int[n + 1];
	
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	
	for (int i = n; i >= 1; i--)
		st.push(arr[i]);
		
	string c;
	cin >> c;
	
	for (int i = 0; i <= c.length() - 1; i++){
		if (c[i] == 'C'){
			tmp = st.top();
			q.push(tmp);
			st.pop();
			continue;
		}
		
		if(c[i] == 'H'){
			tmp = q.front();
			st.push(tmp);
			q.pop();
			continue;
		}
		
	}
	
	while (!st.empty()){
		tmp = st.top();
		cout << tmp << " ";
		st.pop();
	}
	return 0;
}
