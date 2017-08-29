#include <iostream>
#include <cstdio>
#include <cstdlib>

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

int search_total (struct node *temp) {

    if(temp==NULL) return 0;

    return 1+search_total(temp->left)+search_total(temp->right);


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

    int total_node = search_total (root1);

    printf ("Total node in this tree is %d.\n",total_node);
    return 0;
}

