#include<iostream>
#include<queue>

using namespace std;

int n, m, r, c, tmpC, tmpR, tmpS;
queue<int> q;
int**arr;

void check(int r, int c, int s){
	if (arr[r][c] == 0){
			q.push(r);
			q.push(c);

			arr[r][c] = s;
	}
	return;
}

int main(){
	cin >> m >> n >> r >> c;
	arr = new int*[m+1];
	
	for (int i = 1; i <= m; i++){
		arr[i] = new int[n+1];
	}
		
		
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++){
			cin >> arr[i][j];
		}
			
			
	q.push(r);
	q.push(c);
	arr[r][c] = 1;
	
	while (!q.empty()){
		tmpR = q.front();
		q.pop();
		tmpC = q.front();
		q.pop();
		tmpS = arr[tmpR][tmpC];
		
		if (tmpC == 1 || tmpC ==n || tmpR == 1 || tmpR == m){
			cout << arr[tmpR][tmpC];
			
			break;
		}
		check(tmpR - 1, tmpC, tmpS + 1);
		
		check(tmpR + 1, tmpC, tmpS + 1);
		
		check(tmpR, tmpC + 1, tmpS + 1);
		
		check(tmpR, tmpC - 1, tmpS + 1);
	}
	
	if (q.empty()) cout << -1;
	return 0;
}
