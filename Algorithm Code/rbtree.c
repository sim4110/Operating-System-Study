#include<stdio.h>
#include<stdlib.h>

#define RED 1
#define BLACK 0

#define TRUE 1
#define FALSE 0

typedef struct node{
    int data;
    int color;
    struct node*right, *left, *parent;
}node;

typedef struct rbtree{
    node*root;
    node*nil;
}rbtree;

rbtree* create_tree(void){
    rbtree*tree=(rbtree*)malloc(sizeof(rbtree));
    node*nil_node = (node*)malloc(sizeof(node));

    nil_node->left = NULL;
    nil_node->right = NULL;
    nil_node->parent = NULL;
    nil_node->color=BLACK;

    tree->root = nil_node;
    tree->nil = nil_node;

    return tree;
}

void tree_left_rotate(rbtree*tree,node*n){
    node*parent=n->parent;
    node*grand_parent=parent->parent;
    node*tmp_left_node = n->left;
    
    if(parent==tree->root){
        tree->root=n;
    }

    else{
        if(grand_parent->left==parent){
            grand_parent->left = n;
        }
        else if(grand_parent->right==parent){
            grand_parent->right = n;
        }
    }

    n->parent = grand_parent;
    parent->parent = n;
    n->left = parent;

    parent->right=tmp_left_node;
    tmp_left_node->parent = parent;

}

void tree_right_rotate(rbtree*tree, node*n){
    node*parent=n->parent;
    node*grand_parent=parent->parent;
    node*tmp_right_node=n->right;

    if(parent==tree->root){
        tree->root=n;
    }

    else{
        if(grand_parent->left == parent){
            grand_parent->left=n;
        }
        else{
            grand_parent->right=n;
        }
    }

    n->parent = grand_parent;
    parent->parent = n;
    n->right=parent;

    parent->right = tmp_right_node;
    tmp_right_node->parent = parent;

}

void insert_fix(rbtree*tree, node*n){
    node*parent = n->parent;
    node*grand_parent = parent->parent;
    node*parent_sibling;

    int node_is_left = FALSE;
    int parent_is_left = FALSE;

    if(tree->root==n){
        n->color = BLACK;
        return;
    }

    if(parent->color==BLACK){
        return;
    }

    else if(parent->color == RED){
        if(parent==grand_parent->left){
            parent_sibling=grand_parent->right;
            parent_is_left=TRUE;
        }
        else parent_sibling=grand_parent->left;

        if(parent->left==n){    
            node_is_left=TRUE;
        }
        else node_is_left=FALSE;

        //case1:parent,sibling 모두 red일 때
        if(parent_sibling->color==RED){
            parent_sibling->color=parent->color = BLACK;
            grand_parent->color=RED;
            insert_fix(tree,grand_parent);
            return;
        }

        //case2-1:sibling은 black이고, node가 left child일 때
        //insert된 위치가 root node의 right subtree일 때  
        if(parent_is_left && parent_sibling->color==BLACK){
            if(!node_is_left){
                tree_left_rotate(tree,n);
                tree_right_rotate(tree,n);
                return;
            }
        //insert된 위치가 root node의 left subtree일 때
            else{   
                tree_right_rotate(tree,parent);
                return;
            }
        }   

        //case2-2:sibling은 black이고, node가 right child일 때
        //insert된 위치가 root node의 right subtree일 때
        if(!parent_is_left && parent_sibling->color==BLACK){
            if(!node_is_left){
                tree_left_rotate(tree, parent);
                return;
            }
        //insert된 위치가 root node의 left subtree일 때
            else{
                tree_right_rotate(tree,n);
                tree_left_rotate(tree,n);
                return;
            }
        }
    }

}

node*insert_node(rbtree*tree, int key){
    node*new_node=(node*)malloc(sizeof(node));
    node*tmp_node=(node*)malloc(sizeof(node));

    new_node->parent=NULL;
    new_node->left=tree->nil;
    new_node->right=tree->nil;
    new_node->data = key;
    new_node->color = RED;

    tmp_node=tree->root;

    while(tmp_node!=tree->nil){
        if(key<tmp_node->data){
            if(tmp_node->left==tree->nil){
                tmp_node->left=new_node;
                break;
            }
            tmp_node=tmp_node->left;    
        }
        else if(key>tmp_node->data){
            if(tmp_node->right==tree->nil){
                tmp_node->right=new_node;
                break;
            }
            tmp_node=tmp_node->right;
        }
        else{
            printf("이미 존재하는 숫자입니다...\n");
            break;
        }
    }

    new_node->parent = tmp_node;

    if(tree->root==tree->nil){
        tree->root=new_node;
    }

    insert_fix(tree,new_node);
    return new_node;
}


int main(void){
    rbtree*tree;
    node*nil_node = (node*)malloc(sizeof(node));

    // nil_node->left=NULL;
    // nil_node->right=NULL;
    // nil_node->parent=NULL;
    // nil_node->color=BLACK;
    // printf("test1-1\n");

    tree->root = nil_node;
    tree->nil = nil_node;
    printf("test1-2\n");

    int i;
    for(i=1; i<10; i++){
        insert_node(tree,i);
    }

    free(tree);
    return 0;
}