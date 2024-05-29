#include<bits/stdc++.h>

using namespace std;

struct Node {                   
    int r, c, depth; 
};

const int MAX_SIZE = 1001;
int r, c, m, n, ans = -1;
//int** arr;
int arr[MAX_SIZE][MAX_SIZE];
queue<Node> q;

void input(){
	cin >> r >> c >> m >>n;
//	arr = new int*[r+1];
//	for (int i = 1; i <= r; i++)
//		arr[i] = new int[c+1];
//		
//	for (int i = 1; i <= r; i++)
//		for (int j = 1; j <= c; j++)
//			cin >> arr[i][j];
	for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
    		cin >> arr[i][j];
	return;
}

bool check_out(int row, int col){
	if (row == r || col == c || r*c == 0) 
		return true;
	return false;
}

void check_neighbor(int row, int col, int depth){
	Node tmp;
	
	
	
	if (arr[row - 1][col] == 0){
		tmp.r = row - 1;
		tmp.c = col;
		tmp.depth = depth + 1;
		q.push(tmp);
		arr[row - 1][col] = 1;
	}
	
	if (arr[row][col + 1] == 0){
		tmp.r = row;
		tmp.c = col + 1;
		tmp.depth = depth + 1;
		q.push(tmp);
		arr[row][col + 1] = 1;
	}
	
	if (arr[row][col -1] == 0){
		tmp.r = row;
		tmp.c = col - 1;
		tmp.depth = depth + 1;
		q.push(tmp);
		arr[row][col -1] = 1;
	}
	
	if (arr[row + 1][col] == 0){
		tmp.r = row + 1;
		tmp.c = col;
		tmp.depth = depth + 1;
		q.push(tmp);
		arr[row + 1][col] = 1;
	}
}

void BFS(){
	Node tmp;
	while (!q.empty()){
		tmp = q.front(); 
		q.pop();
		if (check_out(tmp.r, tmp.c)){
			ans = tmp.depth;
			break;
		}
		check_neighbor(tmp.r, tmp.c, tmp.depth);
	}
}

int main(){
	input();
	Node node;
	node.r = m;
	node.c = n;
	node.depth = 1;
	q.push(node);
	arr[m][n] = 1;
	BFS();
	cout << ans;
	return 0;
}
