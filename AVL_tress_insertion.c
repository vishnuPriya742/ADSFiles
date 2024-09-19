// AVL Trees insertion

#include <stdio.h>
#include<stdlib.h>

struct Treenode {
    int data;
    struct Treenode* left;
    struct Treenode* right;
    int height;
};
typedef struct Treenode Treenode;

int height(Treenode* root){
    if(root == NULL) return 0;
    return root->height;
}

int max(int a, int b){
    return (a > b) ? a : b;
}

Treenode* createNode(int key){
    Treenode* node = (Treenode*)malloc(sizeof(Treenode));
    node->data = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

// left rotation
Treenode* left_rotate(Treenode* first){
    Treenode* mid = first->right;
    Treenode* temp = mid->left;
    mid->left = first;
    first->right = temp;
    first->height = max(height(first->left), height(first->right)) + 1;
    mid->height = max(height(mid->left), height(mid->right)) + 1;
    return mid;
}

// right rotation
Treenode* right_rotate(Treenode* first){
    Treenode* mid = first->left;
    Treenode* temp = mid->right;
    mid->right = first;
    first->left = temp;
    first->height = max(height(first->left), height(first->right)) + 1;
    mid->height = max(height(mid->left), height(mid->right)) + 1;
    return mid;
}

int getBalance(Treenode* root){
    if(root == NULL) return 0;
    return height(root->left)-height(root->right);
}

Treenode* insertion(Treenode* root, int key){
    if(root == NULL){
       return createNode(key);
    }
    if(root->data == key) return root;
    if(key < root->data){
        root->left = insertion(root->left, key);
    }
    else if(key > root->data){
        root->right = insertion(root->right, key);
    }
    return root;
    
    root->height = max(height(root->left), height(root->right)) + 1;
    int balance = getBalance(root);
    // left left 
    if(balance > 1 && root->left->data > key){
        Right_rotate(root);
    }
    // left right
    else if(balance > 1 && root->left->data < key){
        root->left = left_rotate(root->left);
         right_rotate(root);
    }
    // right right 
    else if(balance < -1 && root->left->data < key){
          left_rotate(root);
    }
    // right left rotation
    else if(balance < -1 && root->left->data > key){
        root->right = right_rotate(root->right);
         left_rotate(root);
    }
    return root;
}

void inOrder(Treenode* root){
    if(root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

int main() {
	int n;
	scanf("%d", &n);
	int nodes[n];
	for(int i=0; i<n; i++){
	    scanf("%d ", &nodes[i]);
	}
	Treenode *root = createNode(nodes[0]);
	for(int i=1; i<n; i++){
	    insertion(root, nodes[i]);
	}

   
    inOrder(root);
}