#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode
{
    int data;
    struct treeNode*left;
    struct treeNode*right;
}treeNode;

void treePrint(treeNode*root);
treeNode*insertNode(treeNode*root, int key);
void deleteNode(treeNode*root, int key);
treeNode*binarySearch(treeNode*root, int key);

int main(void){
    treeNode*root = NULL;
    treeNode*foundNode = NULL;
    int i;

    root=insertNode(root, 3);
    for(i=0;i<10;i++){
        if(i!=2) insertNode(root, i+1);
    }

    treePrint(root);
    printf("\n");

    deleteNode(root,1);
    treePrint(root);
    printf("\n");

    deleteNode(root,7);
    treePrint(root);
    printf("\n");

    deleteNode(root,10);

    binarySearch(root,10);
    treeNode*result = binarySearch(root, 8);
    printf("search result : %d\n",result->data);

    return 0;
}

void treePrint(treeNode*root){
    if(root){
        treePrint(root->left);
        printf("%d ", root->data);
        treePrint(root->right);
    }
}

treeNode*insertNode(treeNode*p, int key){
    treeNode*newNode;
    if(p==NULL){
        newNode = (treeNode*)malloc(sizeof(treeNode));
        newNode->data = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    else if(key<p->data) p->left = insertNode(p->left, key);
    else if(key>p->data) p->right = insertNode(p->right, key);
    else printf("Same data is aleady exist\n");

    return p;
}

void deleteNode(treeNode*root, int key){
    treeNode*parent, *p, *succ, *succ_parent;
    treeNode* child;

    parent = NULL;
    p = root;
    while((p!=NULL)&&(p->data != key)){
        parent = p;
        if(key < p->data) p=p->left;
        else p=p->right;
    }

    if(p==NULL){
        printf("The key is not exist");
        return;
    }
    

    if((p->left==NULL)&&(p->right==NULL)){
        if(parent != NULL){
            if(parent->left == p) parent->left = NULL;
            else parent ->right = NULL;
        }
        else root = NULL;
    }

    else if((p->left==NULL) || (p->right==NULL)){
        if(p->left!=NULL) child=p->left;
        else child=p->right;

        if(parent!=NULL){
            if(parent->left==p) parent->left=child;
            else parent->right = child;
        }
        else root = child;
    }

    else{
        succ_parent = p;
        succ = p->left;
        while(succ->right!=NULL){
            succ_parent=succ;
            succ=succ->right;
        }
        if(succ_parent->left == succ) succ_parent->left = succ->left;
        else succ_parent->right = succ->left;
        p->data = succ->data;
        p = succ;
    }
    free(p);
}

treeNode*binarySearch(treeNode*root, int key){
    treeNode*tmp;
    tmp = root;

    while(tmp!=NULL){
        if(key==tmp->data) return tmp;
        else if(key<tmp->data)tmp = tmp->left;
        else tmp = tmp->right;
    }

    printf("The key is not exist\n");
    return tmp;
}