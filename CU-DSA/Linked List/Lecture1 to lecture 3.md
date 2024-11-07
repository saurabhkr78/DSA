# Lecture 1

## Question 1: Search an element 
return true if element is present else false
```
input : 2->4->3->6->5 search 4
output: true
```
## Question 2: Find the length of the linked list

```
input : 1->2->3->4->5
output : 5
```
## Question 3: Insert and delete 

## Question 4: [Add two numbers](https://leetcode.com/problems/add-two-numbers/description/)
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
```
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
```
```
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
```
# Lecture 2:

## Question 1: [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/description/)
Given the head of a singly linked list, reverse the list, and return the reversed list.

```
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
```
```
Input: head = [1,2]
Output: [2,1]
```
## Question 2: [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/description/)
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

```
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
```
```
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
```

# Lecture 3
## Quetion 1: [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/description/)
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

```
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
```

```
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node
```
```
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
```
## Quetion 2:[Length of the cycle](https://takeuforward.org/linked-list/length-of-loop-in-linked-list)
Given the head of a linked list, determine the length of a loop present in the linked list; if not present, return 0.
 ```
input: 1  2  3  4  5  3
output 3->4->5->3 Length is 3
```
## [Quetion 3](https://leetcode.com/problems/linked-list-cycle-ii/description/)
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.
```
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
```
```
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
```
# Lecture 4

## Quetions 1: [Find pairs with given sum in doubly linked list](https://www.geeksforgeeks.org/find-pairs-given-sum-doubly-linked-list/)
Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value x, without using any extra space? 
```
Input : head : 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
        x = 7
Output: (6, 1), (5,2)
```
## Quetions 2: [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/description/)
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.
```
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
```
```
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
```

# Extras
## Question 2: [ Add two linked list & delete the middle element ](https://leetcode.com/problems/add-two-numbers/description/)

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.


Example 1:
```
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
```

Example 2:
```
Input: l1 = [0], l2 = [0]
Output: []
```

Example 3:
```
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
```

Constraints:
-The number of nodes in each linked list is in the range [1, 100].
-0 <= Node.val <= 9
-It is guaranteed that the list represents a number that does not have leading zeros.


## Question 3: [Detect Cycle Position](https://leetcode.com/problems/linked-list-cycle-ii/description/)

Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

Example 1:
```
Input: head = [3,2,0,-4]
Output: tail connects to node index 1
```
Example 2:

```
Input: head = [1,2]
Output: tail connects to node index 0
```

Example 3:

```
Input: head = [1]
Output: -1
```

Example 4:
```
Input: head = [1,2,3,4,5,6,7,8,9,10]
Output: 3
```
Constraints:

- The number of the nodes in the list is in the range [0, 104].
- -105 <= Node.val <= 105
- pos is -1 or a valid index in the linked-list.


## Question 4:[ Remove node that is greater in value in right or left given by user](https://leetcode.com/problems/remove-nodes-from-linked-list/description/)

You are given the head of a linked list.

Remove every node which has a node with a greater value anywhere to the right side of it.
take input as 0 for right and 1 for left from the user 

Return the head of the modified linked list.

Example 1:

Input: head = [5,2,13,3,8]
Output: [13,8]
Explanation: The nodes that should be removed are 5, 2 and 3.
- Node 13 is to the right of node 5.
- Node 13 is to the right of node 2.
- Node 8 is to the right of node 3.

Example 2:

Input: head = [1,1,1,1]
Output: [1,1,1,1]
Explanation: Every node has value 1, so no nodes are removed.
 
Example 3:

Input: head = [5,2,4,1,3,4,6,2,0,5]
Output: [6,5]

Constraints:

The number of the nodes in the given list is in the range [1, 105].
1 <= Node.val <= 105

## Question 5:[ Merge node in between 0](https://leetcode.com/problems/merge-nodes-in-between-zeros/description/)

You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.

For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.

Return the head of the modified linked list.


Example 1:
```
Input: head = [0,3,1,0,4,5,2,0]
Output: [4,11]
```

Example 2:
```
Input: head = [0,1,0,3,0,2,2,0]
Output: [1,3,4]
```
Example 3:
```
Input: head = [0,5,1,9,3,0]
Output: [18]
```

Constraints:
- The number of nodes in the list is in the range [3, 2 * 105].
- 0 <= Node.val <= 1000
- There are no two consecutive nodes with Node.val == 0.
- The beginning and end of the linked list have Node.val == 0.

## Question 6:[ Find the Minimum and Maximum Number of Nodes Between Critical Points ](https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/)

A critical point in a linked list is defined as either a local maxima or a local minima.

- A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.

- A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

**Note** that a node can only be a local maxima/minima if there exists both a previous node and a next node.

Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].

Example 1:
```
Input: head = [3,1]
Output: [-1,-1]
```

Example 2:
```
Input: head = [5,3,1,2,5,1,2]
Output: [1,3]
```

Example 3:
```
Input: head = [1,3,2,2,3,2,2,2,7]
Output: [3,3]
```

Constraints:

- The number of nodes in the list is in the range [2, 105].
- 1 <= Node.val <= 105

## Question 7:[ Delete last occurance of an element](https://www.geeksforgeeks.org/delete-last-occurrence-of-an-item-from-linked-list/)

You are given the head of a linked list and integer k.

Remove last occurance of node having value k .

Return the head of the modified linked list.

Examples 1:  
```
Input:   1->2->3->5->2->10, key = 2
Output:  1->2->3->5->10
```

Examples 2:  
```
Input:   5->5->5->5 key = 2
Output:  5->5->5
```

Examples 3:  
```
Input:   3->5->9->8->7 key = 3
Output:  5->9->8->7
```

## Question 8:[ Get the intersection point of two Linked Lists](https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/)

There are two singly linked lists in a system. By some programming error, the end node of one of the linked lists got linked to the second list, forming an inverted Y-shaped list. Write a program to get the point where two linked lists merge. 

Example:
```
Input:head1=[10,15,20], head2=[4,5,15,20]
Output:15
```
Example:
```
Input:head1=[10,15,20,5,8], head2=[8]
Output:8
```
Example:
```
Input:head1=[10,15,20,5,8,6,7,8,4,8], head2=[8]
Output:8 // middle 8
```

## Question 9:[find pair with given sum in doubly linked list](https://www.geeksforgeeks.org/find-pairs-given-sum-doubly-linked-list/)

Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value x, without using any extra space? 

Example:  
```
Input : head : 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9  ,  x = 7
Output: (6, 1), (5,2)
```
Example:  
```
Input : head : -4 <-> -3<->-1<->0<->1<->2<->3<->5<->7  ,  x = 1
Output: (-4, 5), (-1,2), (0,1)
```

## Question 10:[ Split circular linked list in two halves](https://www.geeksforgeeks.org/split-a-circular-linked-list-into-two-halves/)

Given a circular linked list , write a program to divide circular linked list in two halves 

**Note** if size of linked list is odd , divide such that first circular linked list after dividing will have more elements than the second

Example:
```
Input: head=[1,2,3,4,5,6,7]
Output: head 1=[1,2,3,4] , head2=[5,6,7]
```
