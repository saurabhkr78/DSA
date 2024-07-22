#include <iostream>
#include <queue>
#include <climits>
using namespace std;
class node
{
public:
    int val;
    node *left, *right;
    node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
node *constructTree(int arr[], int n)
{
    queue<node *> q;
    node *root = new node(arr[0]);
    q.push(root);
    int i = 1, j = 2;
    while (q.size() > 0 && i < n)
    {
        node *temp = q.front();
        q.pop();

        node *l;
        node *r;
        if (arr[i] != INT_MIN)
            l = new node(arr[i]);
        else
            l = NULL;
        if (j != n && arr[j] != INT_MIN)
            r = new node(arr[j]);
        else
            r = NULL;

        temp->left = l;
        temp->right = r;

        if (l != NULL)
            q.push(l);
        if (r != NULL)
            q.push(r);

        i += 2;
        j += 2;
    }

    return root;
}

void leftBoundary(node* root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) return;
    cout<<root->val<<" ";

    leftBoundary(root->left);
    if(root->left==NULL) leftBoundary(root->right);
}
void leaves(node* root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) 
    cout<<root->val<<" ";

    leaves(root->left);
    leaves(root->right);
}

void rightBoundary(node* root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) return;
    

    rightBoundary(root->right);
    if(root->right==NULL) rightBoundary(root->left);
    //to print in rev order put print after recursion calls
    cout<<root->val<<" ";
}
void boundary(node* root){
      leftBoundary(root);
    leaves(root);
    rightBoundary(root->right);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, INT_MIN, 6,7, INT_MIN,8, INT_MIN, 9,10,INT_MIN,11,INT_MIN,12,INT_MIN,13,INT_MIN,14,15,16,INT_MIN,17,INT_MIN,INT_MIN,18,INT_MIN,19,INT_MIN,INT_MIN};
    int n = sizeof(arr) / sizeof(arr[0]);
    // construct
    node *root = constructTree(arr, n);
   
    cout<<endl;
    boundary(root);
  
}