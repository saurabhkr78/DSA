# Lecture Day 4

## Question 1: Largest Number by Deleting K Digits
[Problem to Solve](https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/largest-number-7-eee0b7c3/)

Given an integer \( N \) with \( D \) digits without any leading zeroes. Find the largest number which can be obtained by deleting exactly \( K \) digits from the number \( N \).

**Note:**
Return the largest number without any leading zeroes.

**Input Format:**
- First line contains integer \( N \).
- Second line contains integer \( K \).

**Output Format:**
Return the largest number which can be obtained by deleting exactly \( K \) digits from the number \( N \).

**Constraints:**
- \( 1 \leq \text{length of } N \leq 10^5 \)
- \( 0 \leq K < \text{length of } N \)

**Sample Input:**
```
44312
2
```

**Sample Output:**
```
443
```

**Explanation:**
The largest possible number is 443 by deleting 1 and 2.

## Question 2:

Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.

 

Example 1:
```
Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.
```
Example 2:
```
Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
```
Example 3:
```
Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
```
 

Constraints:

- `n == nums.length`
- `1 <= n <= 2 * 1e5`
- `-1e9 <= nums[i] <= 1e9`

## Question 3:

### Problem: Construct a Tower with Disks

[Problem to solve](https://www.hackerearth.com/practice/data-structures/queues/basics-of-queues/practice-problems/algorithm/disk-tower-b7cc7a50/)

Your task is to construct a tower in \( N \) days by following these conditions:

1. Every day you are provided with one disk of distinct size.
2. The disk with larger sizes should be placed at the bottom of the tower.
3. The disk with smaller sizes should be placed at the top of the tower.
4. You cannot put a new disk on the top of the tower until all the larger disks that are given to you get placed.

**Input Format:**

- First line: \( N \) denoting the total number of disks that are given to you in the \( N \) subsequent days.
- Second line: \( N \) integers in which the \( i^{th} \) integer denotes the size of the disk that is given to you on the \( i^{th} \) day.

**Note:** All the disk sizes are distinct integers in the range of 1 to \( N \).

**Output Format:**

- Print \( N \) lines. In the \( i^{th} \) line, print the sizes of disks that can be placed on the top of the tower on the \( i^{th} \) day in descending order of the disk sizes.
- If on the \( i^{th} \) day no disks can be placed, then leave that line empty.

**Constraints:**

- `1 <= N <= 10^5`
- Disk sizes are distinct integers from 1 to \( `N` \).

**Sample Input:**
```
5
4 5 1 2 3
```

**Sample Output:**
```
5 4
3 2 1
```

**Explanation:**

- On the first day, the disk of size 4 is given. But you cannot put the disk on the bottom of the tower as a disk of size 5 is still remaining.
- On the second day, the disk of size 5 will be given so now disks of sizes 5 and 4 can be placed on the tower.
- On the third and fourth day, disks cannot be placed on the tower as the disk of size 3 needs to be given yet. Therefore, these lines are empty.
- On the fifth day, all the disks of sizes 3, 2, and 1 can be placed on the top of the tower.