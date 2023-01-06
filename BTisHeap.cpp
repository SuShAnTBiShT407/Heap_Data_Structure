#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int key;
	Node* left;
	Node* right;
};

Node* CreateNode(int val){
	Node* newnode = new Node();
	newnode->key = val;
	newnode->left = newnode->right = NULL;
	return newnode;
}
Node *InsertNode(Node* root, int val){
	if(root==NULL){
		root = CreateNode(val);
		return root;
	}
	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		Node* temp = q.front();
		q.pop();
		if(temp->left!=NULL){
			q.push(temp->left);
		}else{
			temp->left = CreateNode(val);
			return root;
		}

		if(temp->right!=NULL){
			q.push(temp->right);
		}else{
			temp->right = CreateNode(val);
			return root;
		}
	}
	return root;
}

void preorder(Node* root){
	if(root!=NULL){
		cout<<root->key<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

int countNode(Node* root){
	if(root==NULL) return 0;
	int ans = 1+countNode(root->left)+countNode(root->right);
	return ans;
}

bool isCBT(Node* root, int index, int totalCount){
	if(root==NULL) return true;

	if(index>=totalCount) return totalCount;
	else{
		bool l = isCBT(root->left, 2*index+1, totalCount);
		bool r = isCBT(root->right, 2*index+2, totalCount);
		return (l&&r);
	}
}

bool isMaxOrder(Node *root){
	if(root->left==NULL && root->right==NULL) return true;
	if(root->right==NULL){
		return (root->key >  root->left->key);
	}else{
		bool l = isMaxOrder(root->left);
		bool r = isMaxOrder(root->right);

		return (l&&r &&(root->key > root->left->key && root->key > root->right->key));
	}
}

bool isHeap(Node *root){
	int index=0;
	int totalCount = countNode(root);
	if(isCBT(root, index, totalCount) && isMaxOrder(root)){
		return true;
	}else{
		return false;
	}
}

int main(){
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	Node* root = CreateNode(30);

	int arr[] = {30, 15, 10, 9, 8, 7, 6, 5};
	for(int i=1;i<8;i++){
		root = InsertNode(root, arr[i]);
	}

	preorder(root);

	cout<<"\n";
	cout<<isHeap(root);cout<<"\n";

	vector<int> num = {17, 21, 18, 10, 14, 13, 26, 17, 19, 18,};
	int m = 3;
	int n = num.size()-1;
    for(int i=m+1;i<=n;i++){
        int temp = num[i];
        num[i] = num[n];
        num[n] = temp;
        n--;
    }
    for(int i=0;i<num.size();i++){
    	cout<<num[i]<<" ";
    }

	return 0;
}







			//                             ----code by Sushant Bisht-----
