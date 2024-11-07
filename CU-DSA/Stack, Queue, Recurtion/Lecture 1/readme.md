# Lecture Day 1

## Question 1: 

### The Enchanted Library Stack

In the mystical library of Arithmancia, ancient scrolls and magical tomes are stored in enchanted stacks. These stacks must be managed carefully to ensure that the scrolls are accessible and organized properly. As a wizard apprentice, you have been tasked with designing a stack that can perform essential operations: `push`, `pop`, `isEmpty`, and `clear`. 

Your goal is to create a stack data structure that can handle these operations efficiently.

### Problem Statement

Design and implement a stack that supports the following operations:

1. **Push**: Add an element to the top of the stack.
2. **Pop**: Remove and return the element at the top of the stack. If the stack is empty, return a message indicating that the stack is empty.
3. **isEmpty**: Check whether the stack is empty. Return `true` if the stack is empty, and `false` otherwise.
4. **top**: Show top value if it avilable 
5. **Clear**: Remove all elements from the stack.

### Instructions

1. Define a stack class with the necessary attributes and methods.
2. Implement the `push` method to add an element to the top of the stack.
3. Implement the `pop` method to remove and return the top element of the stack. Ensure it handles the case where the stack is empty.
4. Implement the `top` method to show top value of stack.
5. Implement the `isEmpty` method to check if the stack is empty.
6. Implement the `clear` method to remove all elements from the stack.
7. Ensure the stack works correctly by testing it with various scenarios.

<!-- ### Sample Function Signatures

```cpp
class Stack {
public:
    // Constructor
    Stack();
    
    // Destructor
    ~Stack();

    // Push an element to the stack
    void push(int element);
    
    // Pop an element from the stack
    int pop();
    
    // Check if the stack is empty
    bool isEmpty();
    
    // Clear all elements from the stack
    void clear();

private:
    vector<int> elements; // You can use any internal data structure (e.g., vector, list)
};
``` -->

### Example Usage

```cpp
int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element is: " << s.top() << endl; // Output: Top element is: 30
    cout << "Top element is: " << s.pop() << endl; // Output: Top element is: 30 and it removed
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl; // Output: Is stack empty? No
    
    s.clear();
    cout << "Stack cleared." << endl;
    
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl; // Output: Is stack empty? Yes

    return 0;
}
```

### Implementation Guidelines

1. **Constructor**: Initialize the stack.
2. **Destructor**: Clean up any resources used by the stack.
3. **push**: Add the given element to the top of the stack.
4. **pop**: Remove and return the element at the top of the stack. If the stack is empty, print a message and return an appropriate value.
5. **isEmpty**: Return `true` if the stack is empty, otherwise return `false`.
6. **clear**: Remove all elements from the stack.

### Note

- You can choose any internal data structure (e.g., ***Linklist***, vector, list,) to implement the stack.
- Handle edge cases, such as popping from an empty stack.
- Test your stack implementation with various inputs to ensure it works correctly.

## Question 2: 

### Storyline: "The Enchanted Book of Spells"

In the mystical land of Arithmancia, there is an ancient Enchanted Book of Spells that contains powerful incantations to control the elements and summon magical creatures. However, the magic of the book can only be invoked if the spells are perfectly balanced. Each spell is written using special brackets that must be properly paired and ordered for the spell to work correctly.

You, as a young wizard apprentice, have been tasked with creating a magical program to help verify the correctness of these spells. Your program must check whether the pairs and orders of the brackets are correct in the given expression from the book.

### Problem Statement

Given an expression string `exp` from the Enchanted Book of Spells, write a program to examine whether the pairs and the orders of `{`, `}`, `(`, `)`, `[`, `]` are correct in the given expression.

### Input

- A string `exp` representing a spell from the Enchanted Book of Spells. The string contains only the characters `{`, `}`, `(`, `)`, `[`, `]`.

### Output

- Output "Balanced" if the spell is correctly balanced.
- Output "Not Balanced" if the spell is not correctly balanced.

### Constraints

- The length of `exp` will not exceed \(10^4\).

### Example

#### Example 1:
```
Input: exp = "[()]{}{[()()]()}"
Output: Balanced
Explanation: All the brackets are well-formed.
```

#### Example 2:
```
Input: exp = "[(])"
Output: Not Balanced
Explanation: The 1st and 4th brackets are not balanced because 
there is a closing `]` before the closing `(`.
```

### Instructions

1. Define a function that takes a string as input.
2. Implement the function to check whether the pairs and orders of the brackets are correct.
3. Return the result as either "Balanced" or "Not Balanced".

Help the wizarding world by ensuring that every spell from the Enchanted Book of Spells is perfectly balanced!

## Question 3

### The Tale of the Lost Traveler and the Pathfinder

In the sprawling digital world of Unixia, paths to various directories are mapped out with precision and order. One day, an adventurer named Alex, known for their explorations of the vast Unixian file systems, encountered a mysterious glitch. The path they were following became convoluted, filled with redundant slashes and misleading periods. Alex needed help to find the true path and reach their destination.

You, the Pathfinder, have been tasked with simplifying the path and guiding Alex through the digital maze. Your mission is to transform any given absolute path into its simplified canonical form, ensuring Alex can traverse Unixia without getting lost.

### Problem Statement

Given an absolute path for a Unix-style file system, which begins with a slash `'/'`, transform this path into its simplified canonical path.

In the Unix-style file system context:
- A single period `'.'` signifies the current directory.
- A double period `".."` denotes moving up one directory level.
- Multiple slashes such as `"//"` are interpreted as a single slash.

The simplified canonical path should adhere to the following rules:
- It must start with a single slash `'/'`.
- Directories within the path should be separated by only one slash `'/'`.
- It should not end with a slash `'/'`, unless it's the root directory.
- It should exclude any single or double periods used to denote current or parent directories.

### Example Scenarios

Help Alex simplify the following paths:

1. **Input:** `"/home/"`
   **Output:** `"/home"`
   **Explanation:** The trailing slash should be removed.

2. **Input:** `"/home//foo/"`
   **Output:** `"/home/foo"`
   **Explanation:** Multiple consecutive slashes are replaced by a single one.

3. **Input:** `"/home/user/Documents/../Pictures"`
   **Output:** `"/home/user/Pictures"`
   **Explanation:** A double period `".."` refers to the directory up a level.

4. **Input:** `"/../"`
   **Output:** `"/"`
   **Explanation:** Going one level up from the root directory is not possible.

5. **Input:** `"/.../a/../b/c/../d/./"`
   **Output:** `"/.../b/d"`
   **Explanation:** `"..."` is a valid name for a directory in this problem.

### Constraints

- `1 <= path.length <= 3000`
- `path` consists of English letters, digits, period `'.'`, slash `'/'`, or underscore `'_'`.
- `path` is a valid absolute Unix path.

### Your Task

Write a program to simplify the path as described, ensuring Alex can navigate through Unixia efficiently. So, create a function and return a string which give siplify path