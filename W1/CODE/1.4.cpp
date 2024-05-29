#include<iostream>

using namespace std;

int main(){
	int m, n, tmp, length = 0;
	cin >> m >> n;
	int** arr;
	arr = new int*[m + 1];
	for (int i = 1; i <= m; i++)
		arr = new int[n + 1];
	
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++){
			if (i == 1){
				cin >> arr[i][j];
				continue;
			} 
			
			cin >> tmp;
			if (tmp == 0) 
				arr[i][j] = 0;
			else
				arr[i][j] = arr[i - 1][j] + 1;
		}
		
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++){
			if (j != 1){
					if (arr[i][j] == arr[i][j - 1]){
					length++;
					continue;
				} 
				
				if (arr[i][j] == 0){
				
				}
				
				if (arr[i][j] == arr[i][j - 1]){
					length++;
					continue;
				} 
			}
		}
	return 0;
}
