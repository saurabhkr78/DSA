# Lecture Day 3

## Question 1:
### Expression Conversion Tool

You are tasked with implementing a program that allows a user to convert an expression between infix, postfix, and prefix formats using the stack data structure.

#### Tasks:

Create a function `convertExpression` that performs the following conversions based on user input:

1. **Convert Infix to Postfix:**
   - Convert the given infix expression to a postfix expression.
   - Use the following characters in the infix expression:
     - Operands: Alphanumeric characters (e.g., `A`, `B`, `1`, `2`)
     - Operators: `+`, `-`, `*`, `/`
     - Parentheses: `(`, `)`

   **Steps for Infix to Postfix Conversion:**
   - Initialize an empty stack for operators and an empty string for the output.
   - Scan the infix expression from left to right.
   - For each character in the infix expression:
     - If the character is an operand, append it to the output string.
     - If the character is a left parenthesis `(`, push it onto the stack.
     - If the character is a right parenthesis `)`, pop from the stack and append to the output string until a left parenthesis `(` is encountered. Discard the pair of parentheses.
     - If the character is an operator, pop from the stack and append to the output string until the stack is empty or the top of the stack has an operator of lower precedence. Push the current operator onto the stack.
   - Pop all remaining operators from the stack and append to the output string.

2. **Convert Infix to Prefix:**
   - Convert the given infix expression to a prefix expression.
   - Use the following characters in the infix expression:
     - Operands: Alphanumeric characters (e.g., `A`, `B`, `1`, `2`)
     - Operators: `+`, `-`, `*`, `/`
     - Parentheses: `(`, `)`

   **Steps for Infix to Prefix Conversion:**
   - Reverse the infix expression.
   - Replace `(` with `)` and vice versa.
   - Convert the modified infix expression to postfix using the above algorithm for postfix conversion.
   - Reverse the postfix expression to get the prefix expression.

3. **Convert Postfix to Infix:**
   - Convert the given postfix expression to an infix expression.
   - Use the following characters in the postfix expression:
     - Operands: Alphanumeric characters (e.g., `A`, `B`, `1`, `2`)
     - Operators: `+`, `-`, `*`, `/`

   **Steps for Postfix to Infix Conversion:**
   - Initialize an empty stack for operands.
   - Scan the postfix expression from left to right.
   - For each character in the postfix expression:
     - If the character is an operand, push it onto the stack.
     - If the character is an operator, pop two operands from the stack, enclose them in parentheses with the operator in between, and push the resulting string back onto the stack.
   - The stack will contain the final infix expression.

4. **Convert Prefix to Infix:**
   - Convert the given prefix expression to an infix expression.
   - Use the following characters in the prefix expression:
     - Operands: Alphanumeric characters (e.g., `A`, `B`, `1`, `2`)
     - Operators: `+`, `-`, `*`, `/`

   **Steps for Prefix to Infix Conversion:**
   - Reverse the prefix expression.
   - Replace `(` with `)` and vice versa.
   - Convert the modified prefix expression to postfix using the above algorithm for postfix conversion.
   - Reverse the postfix expression to get the infix expression.

#### Input:

- Select the type of expression conversion (Infix, Postfix, Prefix).
- Provide the expression to be converted as a string.

#### Output:

- The converted expression in the remaining two formats based on the selected conversion type.

#### Example:

Input:
```
Conversion Type: Infix
Expression: A+B*(C^D-E)
```

Output:
```
Infix: A+B*(C^D-E)
Postfix: ABCD^E-*+
Prefix: +A*B-CD^E
```

#### Constraints:

- The length of the expression will be between 1 and 1000 characters.
- The expression will be a valid infix, postfix, or prefix expression containing only the allowed characters.

#### Note:

Implement the necessary functions to perform these conversions and ensure the proper use of the stack data structure. Test your implementation with various expressions to verify correctness.

## Question 2

### Question: Stack Operations Using Recursion

You are tasked with implementing two operations on a stack: reversing the stack using recursion and deleting the middle element from the stack.

#### Tasks:

1. **Reverse a Stack Using Recursion:**
   - Implement a function `reverseStack` that reverses a given stack using recursion.
   - You are allowed to use the following stack operations: `push`, `pop`, `isEmpty`.

   **Steps for Reversing the Stack:**
   - Base Case: If the stack is empty, return.
   - Recursive Case: Pop the top element from the stack, recursively reverse the remaining stack, and then push the popped element back to the bottom of the stack.

2. **Delete Middle Element of a Stack:**
   - Implement a function `deleteMiddleElement` that deletes the middle element from a given stack.
   - If the stack size is odd, delete the middle element. If the stack size is even, delete the element closer to the top.

   **Steps for Deleting the Middle Element:**
   - Use recursion to pop elements from the stack until reaching the middle element.
   - Skip over the middle element and push the remaining elements back onto the stack.

#### Input:

- Select the operation to perform (Reverse Stack, Delete Middle Element).
- Provide the stack elements as integers.

#### Output:

- For the reverse stack operation, display the reversed stack.
- For the delete middle element operation, display the stack after deleting the middle element.

#### Example:

Input:
```
Operation: Reverse Stack
Stack Elements: [1, 2, 3, 4, 5]
```

Output:
```
Original Stack: [1, 2, 3, 4, 5]
Reversed Stack: [5, 4, 3, 2, 1]
```

Input:
```
Operation: Delete Middle Element
Stack Elements: [1, 2, 3, 4, 5]
```

Output:
```
Original Stack: [1, 2, 3, 4, 5]
Stack after Deleting Middle Element: [1, 2, 4, 5]
```

#### Constraints:

- Implement the operations efficiently using recursion.
- Handle edge cases such as empty stack or single element stack appropriately.

#### Note:

Ensure that your functions correctly implement the stack operations using recursion. Test your implementation with different stack configurations to verify its correctness.

## Question 3

Given an array denoting the strengths of \( N \) monsters, we start with an empty battlefield. At each minute \( i \), the \( i^{th} \) monster joins the battlefield and kills all monsters whose strength is less than or equal to his strength.

[Problem to solve](https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/killer-monsters-0b5cb283/)

Find the number of monsters alive in the battlefield at the end of \( i \) minute for each \( i \).

**NOTE:**
- Use of Fast I/O is recommended for this problem.
- A monster becomes part of the battlefield at the end of his killing spree.

### Input Format:

- The first line contains an integer \( T \), the number of test cases.
- For each test case:
  - The first line contains an integer \( N \), the number of monsters.
  - The second line contains \( N \) space-separated integers, the strengths of the monsters.

### Output Format:

For each test case, output \( N \) integers denoting the number of monsters alive after each minute from 1 to \( N \).

### Constraints:

- `1 <= T <= 10`
- `1 <= N <= 10^5`
- `0 <= strength of monsters <= 10^9`

### Sample Input:

```
3
5
3 0 3 4 1
5
5 4 3 2 1
7
1 2 3 3 4 4 0
```

### Sample Output:

```
1 2 1 1 2
1 2 3 4 5
1 1 1 1 1 1 2
```

### Explanation:

**First Test Case:**

- The strengths of monsters are \([3, 0, 3, 4, 1]\).
- At 1st minute, the first monster joins the battlefield. There are no monsters already on the battlefield. After 1st minute, the alive monsters are \([3]\).
- At 2nd minute, the second monster joins the battlefield. The alive monsters are \([3]\), but no one's strength is less than or equal to 0, no one gets killed and 0 becomes part of battlefield. The alive monsters now are \([3, 0]\).
- At 3rd minute, the third monster joins the battlefield. The alive monsters are \([3, 0]\), and the strength of the third monster is 3, which is equal to the strength of the first and greater than the strength of the second monster, thus both get killed, and only current monster remains. The alive monsters remain \([3]\).
- At 4th minute, the fourth monster joins the battlefield. The active monsters are \([3]\), and the strength of the fourth monster is 4, which is greater than the strength of currently alive monster, thus it gets killed. The alive monsters remain \([4]\).
- At 5th minute, the fifth monster joins the battlefield. The active monsters are \([4]\), and the strength of the fifth monster is 1 which is less than the strength of currently alive monsters, so it kills no one and becomes part of battlefield. The alive monsters now are \([4, 1]\).

**Second Test Case:**

- The strengths of monsters are \([5, 4, 3, 2, 1]\).
- At 1st minute, the first monster joins the battlefield. There are no monsters already on the battlefield. After 1st minute, the alive monsters are \([5]\).
- At 2nd minute, the second monster joins the battlefield. The alive monsters are \([5, 4]\).
- At 3rd minute, the third monster joins the battlefield. The alive monsters are \([5, 4, 3]\).
- At 4th minute, the fourth monster joins the battlefield. The alive monsters are \([5, 4, 3, 2]\).
- At 5th minute, the fifth monster joins the battlefield. The alive monsters are \([5, 4, 3, 2, 1]\).

### Constraints:

- Use efficient data structures and algorithms to handle the constraints.
- Handle multiple test cases efficiently.