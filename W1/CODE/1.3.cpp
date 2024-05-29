#include<iostream>

using namespace std;

struct Node{
	int start;
	int end;
	int minimum;
	Node* left_child = NULL;
	Node* right_child = NULL;
};

const int int_maxi = 1000001;
int n;
int* arr;
Node* root = new Node;
int t_start, t_end;

int initialize(Node* node){
	if (node->end - node->start >= 2){
		Node* node_left = new Node; 
		Node* node_right = new Node;
		
		node_left->start = node->start;
		node_left->end = (node->end + node->start) / 2;
		
		node_right->start = (node->end + node->start) / 2 + 1;
		node_right->end = node->end;
		
		node->left_child = node_left;
		node->right_child = node_right;
		
//		cout << (node->left_child)->start << " ";
//		cout << (node->left_child)->end <<endl;
//		
//		cout << (node->right_child)->start << " ";
//		cout << (node->right_child)->end <<endl; 
//		
//		cout << endl;
		
		int min_left = initialize(node->left_child);
		int min_right = initialize(node->right_child);
		
		if (min_left > min_right){
			node->minimum = min_right;
			return min_right;
		}
		else{
			node->minimum = min_left;
			return min_left;
		}
			
	}
	else{
		if (node->end == node->start){
			node->minimum = arr[node->end];
			return arr[node->end];
		}
		else{
			Node* node_left = new Node; 
			Node* node_right = new Node;
			
			node_left->start = node->start;
			node_left->end = node->start;
			node_left->minimum = arr[node->start];
			node->left_child = node_left;
				
			node_right->start = node->end;
			node_right->end = node->end;
			node_right->minimum = arr[node->end];
			node->right_child = node_right;
			
			if (arr[node->start] > arr[node->end]){
				node->minimum = arr[node->end];
				return arr[node->end];
			}
				
			else{
				node->minimum = arr[node->start];
				return arr[node->start];
			}
				
		}
	}
}

void check(Node* node){
	if (node == NULL)
		return;
	cout << node->start << " " << node->end << " " << node->minimum <<endl;
	check(node->left_child);
	check(node -> right_child);
	return;
}

int query(Node* node){
	if (node == NULL){
		return int_maxi;
	}
	
	if(node->start > t_end || node->end < t_start){
		return int_maxi;
	}
	
	if (node->start >= t_start && node->end <= t_end)
		return node->minimum;
		
	
	if (node->left_child != NULL && node->right_child != NULL){
		int tmp1, tmp2;
		tmp1 = query(node->left_child);
		tmp2 = query(node->right_child);
		if (tmp1 < tmp2) 
				return tmp1;
		else
			return tmp2;
	}
	
}

int main(){
	int m, tmp, ans = 0, t_ans = 0;
	cin >> n;
	root->start = 1;
	root->end = n;
	arr = new int[n+1];
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	cin >> m;
	initialize(root);
	//check(root);
	for (int i = 1; i <= m; i++){
		cin >> t_start >> t_end;
		t_start++;
		t_end++;
		ans += query(root);
	}
	cout << ans;
	return 0;
}
