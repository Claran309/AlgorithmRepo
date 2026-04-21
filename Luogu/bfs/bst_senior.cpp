#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;//存值 
	node* left;//指向左右节点 
	node* right;
};
int a[1000],n; 
queue<node*> q;
void bfs(node* root){
	q.push(root);
	while(!q.empty()){
		node* t = q.front();
		cout << t->data << " ";
		q.pop();
		if(t->left != NULL) q.push(t->left);
		if(t->right != NULL) q.push(t->right);
	}
}
void insert(node* root,int value){
	node* tmp = root;
	node* n = new node();
	while(1){
		if(value == tmp->data) return ;
		else if(value < tmp->data)
			if(tmp->left == NULL){
				n->data = value;
				n->left = NULL; n->right = NULL;
				tmp->left = n;
				break;
			}else tmp = tmp->left;
		else 
			if(tmp->right == NULL){
				n->data = value;
				n->left = NULL; n->right = NULL;
				tmp->right = n;
				break;
			}else tmp = tmp->right;
			
	}
}
void preorder(node* root){//先序 
	if(root == NULL) return ;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}
void inorder(node* root){//中序 
	if(root == NULL) return ;
	preorder(root->left);
	cout << root->data << " ";
	preorder(root->right);
}
void lastorder(node* root){//后序 
	if(root == NULL) return ;
	preorder(root->left);
	preorder(root->right);
	cout << root->data << " ";
}
int main(){
	cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i];
	node* root = NULL;
	root = new node();
	root->data = a[0];
	root->left = NULL; root->right = NULL;
	for(int i = 0; i < n; i++){
		insert(root, a[i]);
	} 
	preorder(root);
	return 0;
} 
