## Question 1: [Merge and find maximum element interval](https://www.geeksforgeeks.org/merge-two-sorted-arrays/)

You are given two integer sorted arrays nums1 and nums2. your task is to merge nums1 and nums2 into a single array sorted in non-decreasing order. Finally find a interval containing maximum number of elements inside it.

Example 1:
```
Input: nums1 = [11,32,93] , nums2 = [32,55,62] , interval=[[8,48], [45,92],[92,100]]
Output: mixed num :[11,32,32,55,62,93] 
Interval with maximum elements=3
```
Example 2:
```
Input: nums1 = [1] , nums2 = []
Output: [1]
```
Example 3:
```
Input: nums1 = [] , nums2 = [1]
Output: [1]
```

Constraints:

- nums1.length == m + n
- nums2.length == n
- 0 <= m, n <= 200
- 1 <= m + n <= 200
- 10^9<= nums1[i], nums2[j] <= 10^9

## Question 2:[Arrange array](https://leetcode.com/problems/partition-array-according-to-given-pivot/description/)

You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums such that the following conditions are satisfied:
- Every element less than pivot appears before every element greater than pivot.
- Every element equal to pivot appears in between the elements less than and greater than pivot.
- The relative order of the elements less than pivot and the elements greater than pivot is maintained.

Return nums after the rearrangement.


Example 1:
```
Input: nums = [9,12,5,10,14,3,12], pivot = 10
Output: [9,5,3,10,12,12,14]
```

Example 2:
```
Input: nums = [-13,21,19,2], pivot = 17
Output: [-13,2,19,21]
```

Constraints:

- 1 <= nums.length <= 10^5

- -10^6 <= nums[i] <= 10^6


## Home work :[Concatenate two strings and Reverse the final string]()


## Question 3: [3 Sum](https://leetcode.com/problems/3sum/description/)


Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:
```
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
```

Example 2:
```
Input: nums = [0,1,1]
Output: []
```

Example 3:
```
Input: nums = [0,0,0]
Output: [[0,0,0]]
```

Constraints:

- 3 <= nums.length <= 3000
- -10^5 <= nums[i] <= 10^5


## Question 4:[Merge intervals](https://leetcode.com/problems/interval-list-intersections/description/)


You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.

The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].

Example 1:
```
Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
```

Example 2:
```
Input: firstList = [[1,3],[5,9]], secondList = []
Output: []
```
