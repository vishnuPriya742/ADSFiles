// BST - Insertion, Search and In-Order Traversal
#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *left;
	struct node *right;	
};
typedef struct node TreeNode;
TreeNode *construct_BST( int val) {
	TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
	newNode->data = val;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
TreeNode *insert(TreeNode *root,int key){
    if(root==NULL){
        return construct_BST(key);
    }
    if(root->data==key) return root;
    if(root->data<key){
        root->left=insert(root->left,key);
    }
    if(root->right>key){
        root->right=insert(root->right,key);
    }
    return root;
}
TreeNode *BSTinsert(int low,int high,int *nodes){
    if(low>high) return NULL;
    if(low==high){
        return construct_BST(nodes[low]);
    }
    int mid=(low+high)/2;
    TreeNode *root=construct_BST(nodes[mid]);
    root->left = BSTinsert(low,mid-1,nodes);
    root->right=BSTinsert(mid+1,high,nodes);
    return root;
}
void in_order(TreeNode *root) {
	if (root != NULL) {
		in_order(root->left);
		printf("%d ", root->data);
		in_order(root->right);	
	}
}

int main() {
	int n; 
	scanf("%d", &n);
	int nodes[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &nodes[i]);
	}
   TreeNode *root=BSTinsert(0,n-1,nodes);
	in_order(root);
}