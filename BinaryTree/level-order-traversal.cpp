#include <iostream>
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
void nthlevel(node *root, int currentLevel, int level)
{
    if (root == NULL)
        return;
    if (currentLevel == level){
        cout << root->val << " ";
        return;
    }

    nthlevel(root->left, currentLevel + 1, level);
    nthlevel(root->right, currentLevel + 1, level);
}
int level(node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(level(root->left), level(root->right));
}
void levelorder(node *root)
{
    int n = level(root);
    for (int i = 1; i <= n; i++)
    {
        nthlevel(root, 1, i);
        cout << endl;
    }
}

int main()
{
    node *a = new node(1); // root
    node *b = new node(2);
    node *c = new node(3);
    node *d = new node(4);
    node *e = new node(5);
    node *f = new node(6);
    node *g = new node(7);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    // level order traversal
  levelorder(a);
}