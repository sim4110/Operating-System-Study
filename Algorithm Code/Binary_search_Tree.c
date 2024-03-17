#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct treenode{
    element key;
    struct treenode *llink,*rlink;
}treenode;

//Role : Search node

treenode *search(treenode * node, int key){
    if(node==NULL) return NULL;
    if(key==node->key) return node;
    else if(key<node->key)
        return search(node->llink,key);
    else
        return search(node->rlink,key);
    
}

//Role : Allocation new node

treenode * new(int item){
    treenode *temp = (treenode *)malloc(sizeof(treenode));
    temp->key = item;
    temp->llink=temp->rlink=NULL;
    return temp;
}

//Role : Insert node

treenode *insert(treenode *node, int key){
    if(node == NULL) return new(key);
    else{
        if(key<node->key)
            node->llink = insert(node->llink,key);
        else if(key>node->key)
            node->rlink = insert(node->rlink,key);
        return node;  
    }
    
}

//Role : search Minimun node

treenode * minimum(treenode *node){
    treenode *curr=node;
    while(curr->llink !=NULL){
        curr=curr->llink;
    }
    printf("\n min value: %d\n",curr->key);
    return curr;
}

treenode * delete(treenode *root, int key){
    if(root==NULL) return root;

    if(key<root->key)
        root->llink=delete(root->llink,key);
    else if(key>root->key)
        root->rlink=delete(root->rlink,key);
    else{
        if(root->llink==NULL){
            treenode *temp = root->rlink;
            free(root);
            return temp;
        }
        else if(root->rlink==NULL){
            treenode *temp = root->llink;
            free(root);
            return temp;
        }

        treenode *temp = minimum(root->rlink);

        root->key = temp->key;
        root->rlink = delete(root->rlink,temp->key);   
    }
    return root;
}

void inorder(treenode *root){
    if(root){
        inorder(root->llink);
        printf(" %d ->",root->key);
        inorder(root->rlink);
    }
}

int main(void){
    treenode *root=NULL;
    treenode *tmp=NULL;

    root=insert(root,40);
    root=insert(root,60);
    root=insert(root,50);
    root=insert(root,30);
    root=insert(root,20);
    root=insert(root,10);
    
    inorder(root); //Print Sorted nodes
    minimum(root); //Print minimum value

    delete(root,30); //Delete node
    inorder(root);
    

    return 0;

}

