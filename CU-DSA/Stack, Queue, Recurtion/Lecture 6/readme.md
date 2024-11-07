# Lecture Day 6

## Question 1:

### Palindrome Check using Recursion

**Description:**
Write a recursive function to determine if a given word is a palindrome. A palindrome is a word that reads the same backward as forward.


**Input Formet:**
- A single string `word` (1 <= len(word) <= 1000) consisting of lowercase English letters.

**Output Formet:**
- Return `True` if the word is a palindrome, `False` otherwise.

**Examples:**
```
Input: "radar"
Output: True

Input: "hello"
Output: False

Input: "level"
Output: True

Input: "world"
Output: False

Input: "a"
Output: True
```

**Constraints:**
- The function should use recursion.
- Loops and string slicing are not allowed.

## Question 2:

### Tower of Hanoi

**Description:**
The Tower of Hanoi is a classic problem in computer science and mathematics. The problem consists of three rods and a number of disks of different sizes which can slide onto any rod. The puzzle starts with the disks neatly stacked in ascending order of size on one rod, the smallest at the top, thus making a conical shape.

The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules:
1. Only one disk can be moved at a time.
2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod.
3. No larger disk may be placed on top of a smaller disk.

Write a recursive function to solve the Tower of Hanoi problem.

**Input:**
- An integer `n` (1 <= n <= 20) representing the number of disks.
- A string `source` representing the name of the source rod.
- A string `target` representing the name of the target rod.
- A string `auxiliary` representing the name of the auxiliary rod.

**Output:**
- A list of strings, each string representing a move in the format "Move disk from {source} to {target}".

**Examples:**
```python
Input: n = 2, source = "A", target = "C", auxiliary = "B"
Output: ["Move disk from A to B", "Move disk from A to C", "Move disk from B to C"]

Input: n = 3, source = "A", target = "C", auxiliary = "B"
Output: [
    "Move disk from A to C", 
    "Move disk from A to B", 
    "Move disk from C to B", 
    "Move disk from A to C", 
    "Move disk from B to A", 
    "Move disk from B to C", 
    "Move disk from A to C"
]
```

**Constraints:**
- The function should use recursion.
- The list of moves should be in the order of operations required to solve the Tower of Hanoi problem.

**Hints:**
1. Base Case: If there is only one disk, move it from the source rod to the target rod.
2. Recursive Case: Move `n-1` disks from the source rod to the auxiliary rod, then move the `nth` disk to the target rod, and finally move the `n-1` disks from the auxiliary rod to the target rod.

## Question 3:

### Sorting Algorithm Analysis - Merge Sort and Quick Sort

**Description:**

You are given an array of integers. Your task is to implement two sorting algorithms, Merge Sort and Quick Sort, and use them to sort the array. Additionally, you need to compare the performance of these two sorting algorithms in terms of the number of comparisons made during the sorting process.

**Input:**
- A vector of integers `arr` (1 <= arr.size() <= 10^5, -10^9 <= arr[i] <= 10^9).

**Output:**
- For `merge_sort`: A pair containing the sorted vector and the number of comparisons made during the sorting process.
- For `quick_sort`: A pair containing the sorted vector and the number of comparisons made during the sorting process.

**Examples:**

```cpp
std::vector<int> arr1 = {38, 27, 43, 3, 9, 82, 10};
auto result1_merge = merge_sort(arr1);
// result1_merge.first == {3, 9, 10, 27, 38, 43, 82}
// result1_merge.second == 12

auto result1_quick = quick_sort(arr1);
// result1_quick.first == {3, 9, 10, 27, 38, 43, 82}
// result1_quick.second == 16

std::vector<int> arr2 = {1, 2, 3, 4, 5};
auto result2_merge = merge_sort(arr2);
// result2_merge.first == {1, 2, 3, 4, 5}
// result2_merge.second == 4

auto result2_quick = quick_sort(arr2);
// result2_quick.first == {1, 2, 3, 4, 5}
// result2_quick.second == 10

std::vector<int> arr3 = {5, 4, 3, 2, 1};
auto result3_merge = merge_sort(arr3);
// result3_merge.first == {1, 2, 3, 4, 5}
// result3_merge.second == 12

auto result3_quick = quick_sort(arr3);
// result3_quick.first == {1, 2, 3, 4, 5}
// result3_quick.second == 10
```

**Constraints:**
- The algorithms should be implemented recursively.
- You are required to count the number of comparisons made during the sorting process and return it along with the sorted array.