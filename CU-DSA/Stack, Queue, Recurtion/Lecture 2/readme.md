# Lecture Day 2

## Question 1:

### The Enchanted Library Queue

In the mystical land of Codeia, there exists an ancient library known as The Enchanted Library. This library holds countless scrolls of wisdom and spells, but to retrieve and return them in an orderly manner, a special queue system must be designed. You, the chosen Sage, have been tasked with designing and implementing this queue system.

### Problem Statement

You need to create a queue system that supports the following operations:
- `enqueue(value)`: Add a value to the end of the queue.
- `dequeue()`: Remove and return the value at the front of the queue.
- `front()`: Show front value of queue
- `isEmpty()`: Check if the queue is empty.
- `clear()`: Clear all the elements in the queue.

Implement this queue using two different data structures:
1. A singly linked list. (Important)
2. A vector or list (dynamic array).

### Your Tasks

#### Part 1: Implement the Queue using a Singly Linked List

1. **Define the Node Structure**: Each node should contain a value and a pointer to the next node.
2. **Create the Queue Class**:
   - **Attributes**: Include pointers for the front and rear of the queue.
   - **Methods**:
     - `enqueue(value)`: Add a value to the end.
     - `dequeue()`: Remove and return the value at the front.
     - `isEmpty()`: Check if the queue is empty.
     - `front()`: Show front value of queue
     - `clear()`: Clear the queue.

#### Part 2: Implement the Queue using a Vector or List

1. **Create the Queue Class**:
   - **Attributes**: Use a vector or list to store the elements.
   - **Methods**:
     - `enqueue(value)`: Add a value to the end.
     - `dequeue()`: Remove and return the value at the front.
     - `isEmpty()`: Check if the queue is empty.
     - `front()`: Show front value.
     - `clear()`: Clear the queue.


### Requirements

- Ensure that the implementation is efficient and handles edge cases (e.g., dequeueing from an empty queue).
- The queue should be able to handle a large number of operations without significant performance degradation.
- Provide clear documentation and comments in the code to explain the logic and flow.

## Question 2

### Problem Statement

Create a class `Queue` that performs the following operations using two stacks:

1. `push(value)`: Add a value to the end of the queue.
2. `pop()`: Remove and return the value at the front of the queue.
3. `front()`: Get the value at the front of the queue without removing it.
4. `isEmpty()`: Check if the queue is empty.

### Requirements

- Define the `Queue` class.
- Use two stacks to implement the queue operations.

### Constraints

- Ensure that the implementation is efficient and handles edge cases, such as popping from an empty queue.
- The queue should be able to handle a large number of operations without significant performance degradation.
- Provide clear documentation and comments in the code to explain the logic and flow.

## Question 3

Efficiently print all nodes between two given levels in a binary tree.

Given a binary tree, efficiently print all nodes in it between two given levels. The nodes for any level should be printed from left and right.

For example, if the starting level is 2 and the ending level is 3, the solution should print nodes in order [2, 3, 4, 5, 6, 7].

[Practice this problem](https://www.techiedelight.com/?problem=NodesBetweenTwoLevels)

Example
```
Given the root of a binary tree and two positive numbers m and n where m >= n, return values of all nodes between level m and level n. The nodes for each level should be processed from left and right.

Input: Below binary tree, m = 2, n = 3

		   1
		 /   \
		/	  \
	   2	   3
			  / \
			 /	 \
			4	  5
		   / \	   \
		  /   \		\
		 6	   7	 8

Output: [2, 3, 4, 5]

Note: If n is more than the number of levels in the binary tree, the solution return nodes till last level. For example, if the starting level is 2 and the ending level is 7, the solution should return [2, 3, 4, 5, 6, 7, 8] for above binary tree.
```

## Question 4

### Problem Statement: Sliding Window Maximum

Given an array of integers `nums` and an integer `k`, find the maximum value in each sliding window of size `k` that moves from the beginning to the end of the array. The sliding window moves one position to the right at a time.

### Example

```
Input: nums = [1, 3, -1, -3, 5, 3, 6, 7], k = 3
Output: [3, 3, 5, 5, 6, 7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```

### Constraints

- 1 <= `nums.length` <= 10^5
- -10^4 <= `nums[i]` <= 10^4
- 1 <= `k` <= `nums.length`

### Requirements

- Create a function to solve this problem using a queue.
- Ensure that the function is efficient and handles large input sizes within a reasonable time frame.