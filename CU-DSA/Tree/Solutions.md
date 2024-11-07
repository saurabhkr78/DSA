# LECTURE 1
## sol 1
```
bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL && targetSum-root->val==0)return true;
        return hasPathSum(root->left,targetSum-root->val)||hasPathSum(root->right,targetSum-root->val);
    }
```

## sol 2
```
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > paths;
        vector<int> path;
        findPaths(root, sum, path, paths);
        return paths;  
    }
private:
    void findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& paths) {
        if (!node) return;
        path.push_back(node -> val);
        if (!(node -> left) && !(node -> right) && sum == node -> val)
            paths.push_back(path);
        findPaths(node -> left, sum - node -> val, path, paths);
        findPaths(node -> right, sum - node -> val, path, paths);
        path.pop_back();
    }
};
```
## SOL 3
```
 vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(root==nullptr) return ans; else q.push(root);
        while(!q.empty()){
            vector<int>level;
            int n=q.size();
            for(int i=0;i<n;i++){
                level.push_back(q.front()->val);
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            ans.push_back(level);
        }
        return ans;

    }
```
# LECTURE 2
## SOL 1
```
 vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        vector<int> res;
        q.push(root);

        while(!q.empty()){
            int l=q.size();
            for(int i=0;i<l;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(i==l-1) res.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);

            }
        }
        return res;
 
        
    }
```
## SOL 2
```
void bottomView(Node *root)
{
    if (root == NULL)
        return;

    // Initialize a variable 'hd' with 0
    // for the root element.
    int hd = 0;

    // TreeMap which stores key value pair
    // sorted on key value
    map<int, int> m;

    // Queue to store tree nodes in level
    // order traversal
    queue<Node *> q;

    // Assign initialized horizontal distance
    // value to root node and add it to the queue.
    root->hd = hd;
    q.push(root);  // In STL, push() is used enqueue an item

    // Loop until the queue is empty (standard
    // level order loop)
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();   // In STL, pop() is used dequeue an item

        // Extract the horizontal distance value
        // from the dequeued tree node.
        hd = temp->hd;

        // Put the dequeued tree node to TreeMap
        // having key as horizontal distance. Every
        // time we find a node having same horizontal
        // distance we need to replace the data in
        // the map.
        m[hd] = temp->data;

        // If the dequeued node has a left child, add
        // it to the queue with a horizontal distance hd-1.
        if (temp->left != NULL)
        {
            temp->left->hd = hd-1;
            q.push(temp->left);
        }

        // If the dequeued node has a right child, add
        // it to the queue with a horizontal distance
        // hd+1.
        if (temp->right != NULL)
        {
            temp->right->hd = hd+1;
            q.push(temp->right);
        }
    }

    // Traverse the map elements using the iterator.
    for (auto i = m.begin(); i != m.end(); ++i)
        cout << i->second << " ";
}
```
## SOL 3
```
void bottomView(Node *root)
{
    if (root == NULL)
        return;

    // Initialize a variable 'hd' with 0
    // for the root element.
    int hd = 0;

    // TreeMap which stores key value pair
    // sorted on key value
    map<int, int> m;

    // Queue to store tree nodes in level
    // order traversal
    queue<Node *> q;

    // Assign initialized horizontal distance
    // value to root node and add it to the queue.
    root->hd = hd;
    q.push(root);  // In STL, push() is used enqueue an item

    // Loop until the queue is empty (standard
    // level order loop)
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();   // In STL, pop() is used dequeue an item

        // Extract the horizontal distance value
        // from the dequeued tree node.
        hd = temp->hd;

        // Put the dequeued tree node to TreeMap
        // having key as horizontal distance. Every
        // time we find a node having same horizontal
        // distance we need to replace the data in
        // the map.
        m[hd] = temp->data;

        // If the dequeued node has a left child, add
        // it to the queue with a horizontal distance hd-1.
        if (temp->left != NULL)
        {
            temp->left->hd = hd-1;
            q.push(temp->left);
        }

        // If the dequeued node has a right child, add
        // it to the queue with a horizontal distance
        // hd+1.
        if (temp->right != NULL)
        {
            temp->right->hd = hd+1;
            q.push(temp->right);
        }
    }

    // Traverse the map elements using the iterator.
    for (auto i = m.begin(); i != m.end(); ++i)
        cout << i->second << " ";
}
```
# LECTURE 3
## SOL 1
```
TreeNode* lcs(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root==NULL) return NULL;
        if(root==p || root==q) return root;
        TreeNode* left=NULL;
        TreeNode* right=NULL;
        if(root->left!=NULL){
            left = lcs(root->left,p,q);
        }
        if(root->right!=NULL){
            right = lcs(root->right,p,q);
        }
        if((left!=NULL && right!=NULL)|| ((left!=NULL || right!=NULL) && (root == p || root==q))){
            return root;
        }
        if(left!=NULL) {
            //cout<<left->val<<endl;
            return left;
            }

        return right;
    }
```
## SOL 2
```
int max_gcd(vector<pair<int, int> >& v)
{
    // No child or Single child
    if (v.size() == 1 || v.size() == 0)
        return 0;
  
    sort(v.begin(), v.end());

    // To get the first pair
    pair<int, int> a = v[0];
    pair<int, int> b;
    int ans = INT_MIN;
    for (int i = 1; i < v.size(); i++) {
        b = v[i];

        // If both the pairs belongs to
        // the same parent
        if (b.first == a.first)

            // Update ans with the max
            // of current gcd and
            // gcd of both children
            ans
                = max(ans,
                      __gcd(a.second,
                            b.second));

        // Update previous
        // for next iteration
        a = b;
    }
    return ans;
}
```
# LECTURE 4
## SOL 1
```
Node* KthLargestUsingMorrisTraversal(Node* root, int k)
{
    Node* curr = root;
    Node* Klargest = NULL;
 
    // count variable to keep count of visited Nodes
    int count = 0;
 
    while (curr != NULL) {
        // if right child is NULL
        if (curr->right == NULL) {
 
            // first increment count and check if count = k
            if (++count == k)
                Klargest = curr;
 
            // otherwise move to the left child
            curr = curr->left;
        }
 
        else {
 
            // find inorder successor of current Node
            Node* succ = curr->right;
 
            while (succ->left != NULL && succ->left != curr)
                succ = succ->left;
 
            if (succ->left == NULL) {
 
                // set left child of successor to the
                // current Node
                succ->left = curr;
 
                // move current to its right
                curr = curr->right;
            }
 
            // restoring the tree back to original binary
            //  search tree removing threaded links
            else {
 
                succ->left = NULL;
 
                if (++count == k)
                    Klargest = curr;
 
                // move current to its left child
                curr = curr->left;
            }
        }
    }
 
    return Klargest;
}
```
## SOL 2
```
(https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/solutions/5506367/store-ancestors-of-target-beats-100/)
class Solution {
public:
    vector<pair<int,TreeNode*>> ancestors;
    vector<int> ans;
    bool findancestors(TreeNode* root, TreeNode* target){
        if(!root)return false;
        if(root==target){ancestors.push_back({-1,root});return true;}
        bool right = findancestors(root->right,target);
        bool left = findancestors(root->left,target);
        if(left)ancestors.push_back({1,root}); // 1 to signify left subtree
        if(right)ancestors.push_back({0,root});//0 to signify right subtree
        return right || left;
        
    }

    void findans(TreeNode* root, int k,int depth,int child){
        if(!root)return;
        if(k == depth){
            ans.push_back(root->val);
            return;
        }
        //if target found in left subtree, search paths in right subtree and vice-versa
        if(depth == 0 && child == 1){
            findans(root->right,k,depth+1,child);
        }
        else if(depth == 0 && child == 0){
            findans(root->left,k,depth+1,child);
        }
        else{
            findans(root->left,k,depth+1,child);
            findans(root->right,k,depth+1,child);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        findancestors(root,target);
        for(auto [child,ptr]: ancestors){
            findans(ptr,k,0,child);
            k--;
        }
        return ans;
    }
};
```
# LECTURE 5
## SOL 1
```
https://www.geeksforgeeks.org/find-count-of-singly-subtrees/
#include<bits/stdc++.h>
using namespace std;

// A Tree node
struct Node
{
	int data;
	struct Node* left, *right;
};

// Utility function to create a new node
Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return (temp);
}

// This function increments count by number of single 
// valued subtrees under root. It returns true if subtree 
// under root is Singly, else false.
bool countSingleRec(Node* root, int &count)
{
	// Return true to indicate NULL
	if (root == NULL)
	return true;

	// Recursively count in left and right subtrees also
	bool left = countSingleRec(root->left, count);
	bool right = countSingleRec(root->right, count);

	// If any of the subtrees is not singly, then this
	// cannot be singly.
	if (left == false || right == false)
	return false;

	// If left subtree is singly and non-empty, but data
	// doesn't match
	if (root->left && root->data != root->left->data)
		return false;

	// Same for right subtree
	if (root->right && root->data != root->right->data)
		return false;

	// If none of the above conditions is true, then
	// tree rooted under root is single valued, increment
	// count and return true.
	count++;
	return true;
}

// This function mainly calls countSingleRec()
// after initializing count as 0
int countSingle(Node* root)
{
	// Initialize result
	int count = 0;

	// Recursive function to count
	countSingleRec(root, count);

	return count;
}

// Driver program to test
int main()
{
	/* Let us construct the below tree
			5
		/ \
		4	 5
	/ \	 \
	4 4	 5 */
	Node* root	 = newNode(5);
	root->left	 = newNode(4);
	root->right	 = newNode(5);
	root->left->left = newNode(4);
	root->left->right = newNode(4);
	root->right->right = newNode(5);

	cout << "Count of Single Valued Subtrees is "
		<< countSingle(root);
	return 0;
}

```
## SOL 2
```
https://www.geeksforgeeks.org/remove-bst-keys-outside-the-given-range/
// A C++ program to remove BST keys 
// outside the given range

#include<bits/stdc++.h>
using namespace std;

// A BST node has key, and left and right pointers
struct node
{
	int key;
	struct node *left;
	struct node *right;
};

// Removes all nodes having value outside the 
// given range and returns the root of modified tree
node* removeOutsideRange(node *root, int min, int max)
{
// Base Case
if (root == NULL)
	return NULL;

// First fix the left and right subtrees of root
root->left = removeOutsideRange(root->left, min, max);
root->right = removeOutsideRange(root->right, min, max);

// Now fix the root. There are 2 possible cases 
// for root 1.a) Root's key is smaller than min
// value (root is not in range)
if (root->key < min)
{
	node *rChild = root->right;
	delete root;
	return rChild;
}
// 1.b) Root's key is greater than max value
// (root is not in range)
if (root->key > max)
{
	node *lChild = root->left;
	delete root;
	return lChild;
}
// 2. Root is in range
return root;
}

// A utility function to create a new BST 
// node with key as given num
node* newNode(int num)
{
	node* temp = new node;
	temp->key = num;
	temp->left = temp->right = NULL;
	return temp;
}

// A utility function to insert a given key to BST
node* insert(node* root, int key)
{
	if (root == NULL)
	return newNode(key);
	if (root->key > key)
	root->left = insert(root->left, key);
	else
	root->right = insert(root->right, key);
	return root;
}

// Utility function to traverse the binary 
// tree after conversion
void inorderTraversal(node* root)
{
	if (root)
	{
		inorderTraversal( root->left );
		cout << root->key << " ";
		inorderTraversal( root->right );
	}
}

// Driver program to test above functions
int main()
{
	node* root = NULL;
	root = insert(root, 6);
	root = insert(root, -13);
	root = insert(root, 14);
	root = insert(root, -8);
	root = insert(root, 15);
	root = insert(root, 13);
	root = insert(root, 7);

	cout << "Inorder traversal of the given tree is: ";
	inorderTraversal(root);

	root = removeOutsideRange(root, -10, 13);

	cout << "\nInorder traversal of the modified tree is: ";
	inorderTraversal(root);

	return 0;
}

```
