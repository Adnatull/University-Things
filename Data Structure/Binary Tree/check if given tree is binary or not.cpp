#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;


struct node {
    int v;
    struct node *left, *right;

}*root1 = NULL, *root2 = NULL;

struct node* pushb(struct node *temp,int n) {

    if (temp==NULL){
        struct node *new_node = (struct node*) malloc(sizeof(struct node));
        new_node->v = n;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }else if (temp->v>n)
       temp->left =  pushb(temp->left, n);
    else temp->right = pushb(temp->right, n);
}

void inorder(struct node *temp) {

    if(temp==NULL) return;

    inorder(temp->left);
    printf ("%d ",temp->v);
    inorder (temp->right);
}



int TotalNode (struct node *temp) {

    if(temp==NULL) return 0;

    return 1+TotalNode(temp->left)+TotalNode(temp->right);


}

int deptOfTheTree (struct node *temp) {

    if(temp==NULL) return 0;

    return 1+max(deptOfTheTree(temp->left),deptOfTheTree(temp->right));


}

bool searchSumFromRootToLeaf(struct node *temp, int n) {

    if(temp==NULL && n!=0) return false;
    if(temp==NULL && n==0) return true;

    bool s1 = searchSumFromRootToLeaf (temp->left, n-temp->v);
    bool s2 = searchSumFromRootToLeaf (temp->right, n-temp->v);
    if(!s1) return s2;
    else return s1;

}


bool isBinarySearchTree(struct node *temp) {

    if(temp==NULL) return true;
    bool s1, s2;
    if(temp->left==NULL) s1 = true;
    else {
        if(temp->v>temp->left->v) s1 = true;
        else s1 = false;
    }
    if(temp->right==NULL) s2 = true;
    else {
        if(temp->v<=temp->right->v) s2 = true;
        else s2 = false;
    }
    if(!s1 || !s2) return false;
    else {
        s1 = isBinarySearchTree(temp->left);
        s2 = isBinarySearchTree(temp->right);
        if(!s1 || !s2) return false;
        else return true;
    }


}

int main(){

    freopen("in.txt", "r", stdin);
    //input bst 1

    node bst1;

    int x;
    int n;
    cin >> n;
    for (int i =1; i<=n; i++) {
        cin >> x;
        root1 = pushb(root1,x);
    }

    inorder(root1);
    printf ("\n");

    if(isBinarySearchTree(root1)) printf ("Yes! The tree is binary search tree.\n");
    else printf ("The tree is not binary search tree.\n");

    return 0;
}



