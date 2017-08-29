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



int search_total (struct node *temp) {

    if(temp==NULL) return 0;

    return 1+search_total(temp->left)+search_total(temp->right);


}

int dept (struct node *temp) {

    if(temp==NULL) return 0;

    return 1+max(dept(temp->left),dept(temp->right));


}

bool search_sum(struct node *temp, int n) {

    if(temp==NULL && n!=0) return false;
    if(temp==NULL && n==0) return true;

    bool s1 = search_sum (temp->left, n-temp->v);
    bool s2 = search_sum (temp->right, n-temp->v);
    if(!s1) return s2;
    else return s1;

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
    //input the sum to search
    cin >> n;
    //sum search begins
    bool check_sum = search_sum (root1,n);

    if(check_sum) printf ("The sum exist in the tree.\n");
    else printf ("The sum doesn't exist.\n");
    return 0;
}


