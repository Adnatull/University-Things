#include <iostream>
#include <cstdio>
#include <malloc.h>

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

bool check_same(node *t1, node *t2) {

    if(t1==NULL && t2==NULL) return true;

    if((t1->v!=t2->v) || (t1==NULL && t2!=NULL) || (t1!=NULL && t2==NULL) ) return false;


    bool s1 = check_same(t1->left, t2->left);
    bool s2 = check_same(t1->right, t2->right);

    if(s1) return s2;
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
    // input bst2
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x;
        root2 = pushb(root2,x);
    }

    inorder(root2);
    printf ("\n");

    if(check_same(root1,root2)) cout << "Same tree\n";
    else cout << "Not same tree\n";

    return  0;
}
