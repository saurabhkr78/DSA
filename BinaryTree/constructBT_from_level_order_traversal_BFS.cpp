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
void levelorderQueue(node *root)
{
    queue<node *> q;
    q.push(root);
    while (q.size() > 0)
    {
        node *temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
    cout << endl;
}
void levelorderQueueRev(node *root)
{
    queue<node *> q;
    q.push(root);
    while (q.size() > 0)
    {
        node *temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if (temp->right != NULL)
            q.push(temp->right);
        if (temp->left != NULL)
            q.push(temp->left);
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, INT_MIN, 6, INT_MIN, INT_MIN, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    // construct
    node *root = constructTree(arr, n);
    // level order traversal
    levelorderQueue(root);
    levelorderQueueRev(root);
}