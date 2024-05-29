#include<iostream>

using namespace std;

struct Node{
	int beginQ;
	int endQ;
	int min;
	
	Node* leftChild;
	Node* rightChild;
};

int n, m, beginQ, endQ;;
int* arr;
Node* root = new Node;

void initialize(Node* curr);
int query(int l, int r, Node* node);
void check(Node* node);

int main(){
	int ans = 0;
	cin >> n;
	arr = new int[n+1];
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	cin >> m;
	root->beginQ = 1;
	root->endQ = n;
	
	initialize(root);
//	check(root);
	while (m != 0){
		m--;
		cin >> beginQ >> endQ;
		beginQ++;
		endQ++;
		ans += query(beginQ, endQ, root);
	}
	
	cout << ans;
	return 0;
}

void initialize(Node* curr){
	int tBegin = curr->beginQ;
	int tEnd = curr->endQ;
	
	if (tBegin == tEnd){
		curr->min = arr[tBegin];
		return;
	}
	
	Node* leftChild = new Node;
	leftChild->beginQ = tBegin;
	leftChild->endQ = (tBegin + tEnd) / 2;
	initialize(leftChild);
	
	Node* rightChild = new Node;
	rightChild->beginQ = (tBegin + tEnd) / 2 + 1;
	rightChild->endQ = tEnd;
	initialize(rightChild);
	
	curr->leftChild = leftChild;
	curr->rightChild = rightChild;
	
	if (rightChild->min < leftChild->min)
		curr->min = rightChild->min;
	else
		curr->min = leftChild->min;
	
}

//void check(Node* node){
//	if (!node) return;
//	cout << node->beginQ << "-" << node->endQ << "-" << node->min << " ";
//	check(node->leftChild);
//	check(node->rightChild);
//}

int query(int l, int r, Node* node){
	if (node->beginQ >= beginQ && endQ >= node->endQ)
		return node->min;
		
	if ((node->leftChild)->endQ >= r){
		int minLeft = query(l, r, node->leftChild);
		return minLeft;
	}
	
	if ((node->leftChild)->endQ + 1 <= l){
		int minRight = query(l, r, node->rightChild);
		return minRight;
	}
	
	int minLeft = query(l, (node->leftChild)->endQ, node->leftChild);
	int minRight = query((node->rightChild)->beginQ, r, node->rightChild);
	if (minLeft < minRight)
		return minLeft;
	else
		return minRight;
}

