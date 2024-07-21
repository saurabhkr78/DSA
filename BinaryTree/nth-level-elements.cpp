#include<iostream>
using namespace std;
class node{
    public:
    int val;
    node* left, *right;
    node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }

};
void display(node* root){
    if(root==NULL) return;
    else{
        cout<<root->val<<" ";
        display(root->left);
        display(root->right);
    }
}
void preorder(node* root){
    if(root==NULL) return;
    else{
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(node* root){
    if(root==NULL) return;
    else{
        
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
}
void postorder(node* root){
    if(root==NULL) return;
    else{
        
        postorder(root->left);
        cout<<root->val<<" ";
        postorder(root->right);
    }
}
void nthlevel(node* root,int currentLevel,int level){
    if(root==NULL) return;
    if(currentLevel==level){ 
        cout<<root->val<<" ";
        return;
    }
        
        nthlevel(root->left,currentLevel+1,level);
        nthlevel(root->right,currentLevel+1,level);
    
}
int main(){
    node* a= new node(1);//root
    node* b= new node(2);
    node* c= new node(3);
    node* d= new node(4);
    node* e= new node(5);
    node* f= new node(6);
    node* g= new node(7);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    display(a);
    cout<<endl;
    preorder(a);
    cout<<endl;
    inorder(a);
    cout<<endl;
    postorder(a);
    cout<<endl;
    nthlevel(a,1,3);
}