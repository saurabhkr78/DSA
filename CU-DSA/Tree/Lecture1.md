# Lecture 1

## [Que 1: ](https://leetcode.com/problems/path-sum/description/)
Imagine you're exploring a forest, where each node represents a treehouse, and the root is your starting point. Each treehouse has a certain amount of treasure (node value). Your goal is to find a path from the starting treehouse (root) to any other treehouse that doesn't lead to another (leaf). You want to determine if there exists a path where the sum of the treasure collected exactly matches a specific amount (targetSum). If such a path exists, return true.
```
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetAmount = 22
Output: true
```
```
Input: root = [1,2,3], targetSum = 5
Output: false
```
A leaf is a node with no children.

## [Que 2: ](https://leetcode.com/problems/path-sum-ii/description/)
Same as above but in this you have to return all possible ways to collect target amount. 

```
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
```
```
Input: root = [1,2,3], targetSum = 5
Output: []
```

## [Que 3: ](https://leetcode.com/problems/binary-tree-level-order-traversal/description/)
Imagine you are organizing a company-wide meeting. The CEO (root) is at the top level, followed by department heads (second level), then team leaders (third level), then employees (fourth level) at the bottom and so on.

To collect feedback efficiently, you decide to visit each level of the organization one by one, starting from the CEO and moving level by level from left to right, gathering feedback from each person. The goal is to list everyone's feedback in the exact order you collected it, level by level..
```
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
```
```
Input: root = [1]
Output: [[1]]
```

# Lecture 2
## Que 1: [Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/description/)
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
```
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
```
```
Input: root = [1,null,3]
Output: [1,3]
```
### Top View of Binary Tree
### Bottom View of Binary Tree

# Lecture 3
## Que 1 : [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/)
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
```
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
```
```
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
```



## Que 2: Maximum Gcd Of siblings

- GCD (Greatest Common Divisor) of two positive integers is the largest positive integer that divides both numbers without a remainder.
- Siblings: Nodes with the same parent are called siblings.

You are given nodes of a binary tree. Caluclate the GCD of each pair of siblings and then find the max GCD among them.

Note:
Print -1 if input tree is empty i.e level of tree is -1.
Consider those nodes which have a sibling
Print 0 if no such pair of siblings found

Example:
```
Input :root=[60,15,20,8,null,10,18,null,null,5,null,null,3]
Output :5
```

# Lecture 4

## Que 1: [ Kth Largest Element in tree](https://www.geeksforgeeks.org/kth-largest-element-bst-using-constant-extra-space/)

Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.


Example 1:

```
Input: root = [10,4,20,2,null,20,15,40], k = 3
Output: 15
```
#### In constant space
#### Try with recursion and in constant space 

##  [Que 2](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/)

Imagine you are in a city where each intersection is a node, and the roads connecting them are like the branches of a tree. You start at a specific intersection (target node), and you want to find all the intersections that are exactly k blocks away from this starting point.

The task is to list all intersections (nodes) that you can reach by traveling exactly k blocks (distance) from the target intersection. This way, you know all the places you can reach within that specific distance from where you started.


```
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
```
```
Input: root = [1], target = 1, k = 3
Output: []
```

# Lecture 5
## [ Que 1:](https://www.geeksforgeeks.org/find-count-of-singly-subtrees/)

magine you are conducting a survey in a city with several neighborhoods. Each neighborhood can be seen as a group of houses (nodes in a subtree) connected by roads. Each house is painted in a particular color (node value).

Your task is to find and count the number of neighborhoods where all the houses are painted the same color. You want to do this survey as efficiently as possible to determine if its neighborhood (subtree) is uniform in color.

Example1 : 

```
Input: root of below tree
              5
             / \
            1   5
           / \   \
          5   5   5
Output: 4
There are 4 subtrees with single values.
```

Example 2:

```
Input: root of below tree
              5
             / \
            4   5
           / \   \
          4   4   5                
Output: 5
There are five subtrees with single values
```
## Que 2 : [ Remove Node Outside given Range](https://www.geeksforgeeks.org/remove-bst-keys-outside-the-given-range/)

Given a Binary Search Tree (BST) and a range [min, max], remove all keys which are outside the given range. The modified tree should also be BST. 


Examples:

**Input :** range[-10,13]

![alt text](<Screenshot 2024-07-18 141406.png>)


**Output:**

![alt text](<Screenshot 2024-07-18 141417.png>)


# Extra

## Question 1:[ Alternate nodes of each level of bst](https://www.naukri.com/code360/library/print-alternate-nodes-from-all-levels-of-a-binary-tree


In this question, we are given a binary tree and we have to print all the nodes level-wise from left to right but in every level, we have to print only the alternate nodes.

 

Example
```
Input: 8,3,10,1,6,null,14,null,null,4,6,13,null
Output: 8,3,1,14,4,13

```


**Special** [ Extreme nodes of each Level of bst](https://www.geeksforgeeks.org/print-extreme-nodes-of-each-level-of-binary-tree-in-alternate-order/)


## Question 2:[ Construct Bst from Preorder Traversal,](https://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversa/)[ Inorder Traversal, ](https://www.geeksforgeeks.org/construct-binary-tree-from-inorder-traversal/)[ Postorder Traversal](https://www.geeksforgeeks.org/construct-a-binary-search-tree-from-given-postorder/) there is something missing in this que. please check this once?

Given the input of either preorder or inorder or postorder traversal of a binary search tree, construct the BST.
- if k=0 : Preoder Traversal
- if k=1 : inorder Traversal
- if k=2: Postorder Traversal

Examples:
```
Input: {10, 5, 1, 7, 40, 50} , k=0;
Output:          10
               /   \
              5     40
           /  \       \
          1    7       50
```

## Question 3:[ Check Subtree](https://www.geeksforgeeks.org/check-if-a-binary-tree-is-subtree-of-another-binary-tree/)

Given two binary trees, check if the first tree is a subtree of the second one. A subtree of a tree T is a tree S consisting of a node in T and all of its descendants in T. The subtree corresponding to the root node is the entire tree; the subtree corresponding to any other node is called a proper subtree.

Examples:       
```
Input:  

      Tree S
          10  
        /    \ 
      4       6
       \
        30

        Tree T
              26
            /   \
          10     3
        /    \     \
      4       6      3
       \
        30
Output: True
```



## Question 4:[ Print Ancestors of given element](https://www.geeksforgeeks.org/print-ancestors-of-a-given-node-in-binary-tree/)

Given a Binary Tree and a key, write a function that prints all the ancestors of the key in the given binary tree. 

For example:
```
Input: The key is 7

              1
            /   \
          2      3
        /  \
      4     5
     /
    7

Output:function should print 4, 2, and 1.
```

## Question 5: [ Maximum Sum Leaf to root path](https://www.geeksforgeeks.org/find-the-maximum-sum-path-in-a-binary-tree/)


You are given a binary tree of 'N' nodes.

Your task is to find the path from the leaf node to the root node which has the maximum path sum among all the root to leaf paths.
Example:
```
Input:

                  10
               /      \
             -2        7
           /   \     
          8     -4
Output : 17
```
**Explanation:** The following tree, there are three leaf to root paths 8->-2->10, -4->-2->10 and 7->10. The sums of these three paths are 16, 4 and 17 respectively. The maximum of them is 17 and the path for maximum is 7->10. 



## Question 6:[ Pair with given Sum](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/)

Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

 

Example 1:

```
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
```

Example 2:

```
Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
```

Constraints:

- The number of nodes in the tree is in the range [1, 104].
- -10^4 <= Node.val <= 10^4
- root is guaranteed to be a valid binary search tree.
- -10^5 <= k <= 10^5

## Question 7: [Sum Tree](https://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-sumtree/) please check this que once?


Write a function that returns true if the given Binary Tree is SumTree else false. A SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree. An empty tree is SumTree and the sum of an empty tree can be considered as 0. A leaf node is also considered as SumTree.

Example:
```
Input:
          26
         /   \
       10     3
     /    \     \
    4      6     3

Output: True

```

## Question 8 [House robbery ](https://leetcode.com/problems/house-robber-iii/description/)

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

Example 1:

```
Input: root = [3,2,3,null,3,null,1]
Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
```
Example 2:

```
Input: root = [3,4,5,1,3,null,1]
Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
```

Constraints:

- The number of nodes in the tree is in the range [1, 104].
- 0 <= Node.val <= 104
