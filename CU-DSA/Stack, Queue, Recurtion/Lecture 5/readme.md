# Lecture Day 5

## Question 1

### Problem: Recursively Print Numbers in Ascending and Descending Order

Create a program that uses recursion to print numbers from 1 to \( N \) and from \( N \) to 1. Implement two functions, `goAscending` and `goDescending`, to achieve this.

**Input Format:**

- A single integer \( N \) which represents the upper limit of the range.

**Output Format:**

- The first line should contain numbers from 1 to \( N \) in ascending order.
- The second line should contain numbers from \( N \) to 1 in descending order.

**Constraints:**

- \( 1 \leq N \leq 10^3 \)

**Function Definitions:**

1. **`goAscending(int n)`**:
    - This function should use recursion to print numbers from 1 to \( n \).

2. **`goDescending(int n)`**:
    - This function should use recursion to print numbers from \( n \) to 1.

**Example:**

**Input:**
```
5
```

**Output:**
```
1 2 3 4 5
5 4 3 2 1
```

**Explanation:**

- The first line prints numbers from 1 to 5 in ascending order using the `goAscending` function.
- The second line prints numbers from 5 to 1 in descending order using the `goDescending` function.

## Question 2:

Given an integer N, the task is to print the first N terms of the Fibonacci series in reverse order using Recursion.

Examples:
```
nput: N = 5
Output: 3 2 1 1 0
Explanation: First five terms are – 0 1 1 2 3. 

Input: N = 10
Output: 34 21 13 8 5 3 2 1 1 0
```

## Question 3:

### Sort a Stack using recursion

Given a stack, the task is to sort it using recursion.

Example: 

```
Input: elements present in stack from top to bottom -3 14 18 -5 30
Output: 30 18 14 -3 -5
Explanation: The given stack is sorted know 30 > 18 > 14 > -3 > -5

Input: elements present in stack from top to bottom 1 2 3
Output: 3 2 1
Explanation: The given stack is sorted know 3 > 2 > 1
```

## Question 4:
### Problem: Look-And-Say Sequence

The Look-And-Say sequence is a sequence of positive integers where each term is constructed based on the previous term. The sequence is as follows:

1, 11, 21, 1211, 111221, 312211, 13112221, ...

This sequence is constructed in the following way:
1. The first number is 1.
2. This is read as "One 1". Hence, the second number will be 11.
3. The second number is read as "Two 1s". Hence, the third number will be 21.
4. The third number is read as "One 2, One 1". Hence, the fourth number will be 1211.
5. The fourth term is read as "One 1, One 2, Two 1s". Hence, the fifth term will be 111221.
6. And so on.

Given an integer \( N \), find the \( N \)-th term of the sequence.

### Input Format
- The first line contains an integer \( T \), the number of test cases.
- The next \( T \) lines each contain a single integer \( N \), the sequence index.

### Output Format
- For each test case, output the \( N \)-th term of the Look-And-Say sequence.

### Constraints
-  1 <= T <= 30 
-  1 <= N <=  40 

### Sample Input
```
3
1
2
3
```

### Sample Output
```
1
11
21
```

### Explanation
- The first term is 1.
- The second term is 11.
- The third term is 21.

### Sample Input 2
```
1
6
```

### Sample Output 2
```
312211
```

### Explanation
- The sixth term is read as "One 3, One 1, Two 2s, Two 1s".