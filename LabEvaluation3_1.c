#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

void inorder(struct TreeNode* root, int* k, int* result) {
    if (root == NULL) return;

    inorder(root->left, k, result);
    
    (*k)--;
    if (*k == 0) {
        *result = root->val;
        return;
    }

    inorder(root->right, k, result);
}

int kthSmallest(struct TreeNode* root, int k) {
    int result = -1; 
    inorder(root, &k, &result);
    return result;
}

int main() {
  

    struct TreeNode* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(6);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->left->left->left = newNode(1);

    int k = 3;
    printf("The %dth smallest element is %d\n", k, kthSmallest(root, k));

    return 0;
}
