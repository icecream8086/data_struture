#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    tree_node *root = create_tree_node(1);
    root->left = create_tree_node(2);
    root->right = create_tree_node(3);
    root->left->left = create_tree_node(4);
    root->left->right = create_tree_node(5);

    //中序遍历
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    free((root->left->left));
    free((root->left->right));
    free((root->left));
    free((root->right));
    free(root);
    return 0;
}

/**
 * @brief 树节点
 * 
 */
typedef struct tree_node{
    int data;
    struct tree_node *left;
    struct tree_node *right;
} tree_node;

/**
 * @brief Create a tree node object
 * 
 * @param data 
 * @return tree_node* 
 */
tree_node* create_tree_node(int data){
    tree_node *new_node = (tree_node*)malloc(sizeof(tree_node));
    //check 
    if(new_node == NULL){
        printf("Memory error\n");
        return NULL;
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

/**
 * @brief 中序遍历
 * 
 * @param root 
 */
void inorder(tree_node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

/**
 * @brief 前序遍历
 * 
 * @param root 
 */
void preorder(tree_node *root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
/**
 * @brief 后序遍历
 * 
 * @param root 
 */
void postorder(tree_node *root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}