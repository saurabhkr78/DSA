# Lecture Day 5

## Question 1a:

Write a program that converts a 10-digit mobile number into words. If a digit appears consecutively, the program should describe it using "double", "triple", etc., as appropriate.

**Input:**
- A string `number` representing a 10-digit mobile number.

**Output:**
- A string where each digit of the mobile number is converted into words, with consecutive repetitions described using "double", "triple", etc. If the input is not a valid 10-digit number, the output should indicate that the number is not valid.

**Example 1:**
```
Input: "8887135277"
Output: "triple eight seven one three five two double seven"
```

**Example 2:**
```
Input: "9988886000"
Output: "double nine triple eight eight six triple zero"
```

**Example 3:**
```
Input: "12345"
Output: "not a valid number"
```

## Solution

### Intuition and Approach

**Intuition:**

The problem is to convert a 10-digit mobile phone number into a textual representation where consecutive digits are expressed in words like "twice" or "triple" to indicate their frequency. The solution involves breaking down the number into segments of repeated digits and converting these segments into readable text.

**Approach:**

1. **Input Validation:**
   - Ensure that the input string `number` has exactly 10 digits. If not, return "not a valid number".

2. **String Conversion:**
   - Traverse the string and keep track of the current digit and its count.
   - Whenever the digit changes, convert the count and digit into its textual representation:
     - "triple" for three consecutive digits.
     - "twice" for two consecutive digits.
   - Append the textual representation of the digit itself.

3. **Handling Edge Cases:**
   - If a digit count reaches three, handle this immediately by appending "triple" and resetting the count.
   - At the end of the string, ensure the last segment is also processed.

### Brute Force Solution

The brute force solution will involve checking each digit and its frequency in the number, appending the corresponding text based on the frequency.

**Pseudo Code:**

```plaintext
FUNCTION stringNumber(val: INTEGER) RETURNS STRING:
    INITIALIZE numbers AS ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
    RETURN numbers[val]

FUNCTION numberToText(number: STRING) RETURNS STRING:
    IF LENGTH(number) != 10:
        RETURN "not a valid number"

    INITIALIZE term = 1
    INITIALIZE value = number[0]
    INITIALIZE strNumber = ""

    FOR i FROM 1 TO LENGTH(number) - 1:
        IF number[i] == value:
            term = term + 1
        ELSE:
            IF term == 3:
                strNumber = strNumber + "triple "
            ELSE IF term == 2:
                strNumber = strNumber + "twice "
            strNumber = strNumber + stringNumber(CHAR_TO_INT(value)) + ' '
            term = 1
            value = number[i]

        IF term == 3:
            strNumber = strNumber + "triple "
            strNumber = strNumber + stringNumber(CHAR_TO_INT(value)) + ' '
            term = 1
            value = number[++i]

    IF term == 3:
        strNumber = strNumber + "triple "
    ELSE IF term == 2:
        strNumber = strNumber + "twice "
    strNumber = strNumber + stringNumber(CHAR_TO_INT(value)) + ' '

    RETURN strNumber

FUNCTION main() RETURNS VOID:
    INITIALIZE number AS STRING
    READ number
    PRINT "Your mobile Number is: " + numberToText(number)
```

## Question 1b:

Write a program that converts a string representation of a mobile number (where digits are described in words and consecutive repetitions are described using "double", "triple", etc.) back into a 10-digit number. 

**Input:**
- A string `words` representing the mobile number in words.

**Output:**
- A string representing the 10-digit mobile number. If the input string does not correctly represent a valid 10-digit number, the output should indicate that the input is not valid.

**Example 1:**
```
Input: "triple eight seven one three five two double seven"
Output: "8887135277"
```

**Example 2:**
```
Input: "double nine triple eight eight six triple zero"
Output: "9988886000"
```

**Example 3:**
```
Input: "nine eight seven"
Output: "not a valid number"
```

## Solution

### Intuition and Approach

**Intuition:**

The goal is to convert a textual representation of a phone number back into its numeric form. The text might include words like "triple" or "double" to indicate repeated digits, as well as individual digit names. The task involves interpreting these words and reconstructing the original number from them.

**Approach:**

1. **Parsing Input:**
   - Split the input string into segments based on spaces. Each segment will either be a digit word (e.g., "seven") or a descriptor word (e.g., "triple", "double").

2. **Processing Segments:**
   - Use a loop to process each segment:
     - If the segment is a descriptor word (e.g., "triple", "double"), set the repetition count (`time`) based on the descriptor.
     - If the segment is a digit word, convert it to its numeric form using a predefined mapping and repeat it according to the last `time` value.

3. **Reconstruction:**
   - Construct the numeric string by appending the digits in the correct sequence as determined by the descriptors.

4. **Validation:**
   - After reconstruction, check if the length of the numeric string is exactly 10 digits. If not, return "not a valid number".

### Pseudo Code

```plaintext
FUNCTION numberString(val: STRING) RETURNS CHAR:
    IF val == "zero" RETURN '0'
    IF val == "one" RETURN '1'
    IF val == "two" RETURN '2'
    IF val == "three" RETURN '3'
    IF val == "four" RETURN '4'
    IF val == "five" RETURN '5'
    IF val == "six" RETURN '6'
    IF val == "seven" RETURN '7'
    IF val == "eight" RETURN '8'
    IF val == "nine" RETURN '9'
    RETURN -1

FUNCTION textToNumber(strNumber: STRING) RETURNS STRING:
    INITIALIZE time = 1
    INITIALIZE number = ""
    INITIALIZE num = ""
    INITIALIZE n = LENGTH(strNumber)

    FOR i FROM 0 TO n:
        IF strNumber[i] == ' ' OR i == n:
            IF num == "triple":
                time = 3
            ELSE IF num == "double":
                time = 2
            ELSE:
                WHILE time > 0:
                    number += numberString(num)
                    time = time - 1
                time = 1
            num = ""
        ELSE:
            num += strNumber[i]

    IF LENGTH(number) < 10 OR LENGTH(number) > 10:
        RETURN "not a valid number"

    RETURN number

FUNCTION main() RETURNS VOID:
    INITIALIZE strNumber AS STRING

    SET strNumber TO "triple eight seven one three five two double seven"
    PRINT "Your mobile number is: " + textToNumber(strNumber)

    SET strNumber TO "double nine triple eight eight six triple zero"
    PRINT "Your mobile number is: " + textToNumber(strNumber)

    SET strNumber TO "nine eight seven"
    PRINT "Your mobile number is: " + textToNumber(strNumber)
```

### Explanation:

1. **`numberString(val)`**: This function maps textual representations of digits to their numeric form.
2. **`textToNumber(strNumber)`**: This function processes the input string by:
   - Parsing the input into segments.
   - Interpreting descriptor words to determine how many times to repeat the next digit.
   - Reconstructing the numeric phone number based on these segments.
   - Validating the length of the resulting number to ensure it's a 10-digit phone number.
3. **`main()`**: Handles input and output, demonstrating the conversion of textual representations of phone numbers into numeric form.

## Question 2:
Given an array of distinct elements of size `N`, the task is to rearrange the elements of the array in a *zig-zag fashion*, i.e., the elements are arranged as smaller, then larger, then smaller, and so on. There can be more than one arrangement that follows the form:

**[NOTE: without Sorting]**

```arr[0] < arr[1]  > arr[2] < arr[3] > arr[4] < …```

**Example 1:**
```
Input: N = 7, arr[] = {4, 3, 7, 8, 6, 2, 1}
Output: 3, 7, 4, 8, 2, 6, 1
Explanation: The given array is in zig-zag pattern as we can see 3 < 7 > 4 < 8 > 2 < 6 >1

Input: N = 4, arr[] = {1, 4, 3, 2}
Output: 1, 4, 2, 3
```

## Solution

### Intuition and Approach

The goal is to rearrange a sequence of numbers such that they follow a zigzag pattern. In a zigzag pattern:
- At even indices (0-based), the number should be less than the next number.
- At odd indices, the number should be greater than the next number.

### Intuition:

1. **Brute Force Approach:**
   - **Sorting:** First, sort the numbers. This gives a baseline where numbers are in increasing order.
   - **Swapping:** To create the zigzag pattern, iterate through the sorted list and swap adjacent elements in pairs. This ensures that every second element is less than its following element, which should create the zigzag pattern.

2. **Optimal Approach:**
   - **Direct Adjustments:** Instead of sorting the array first, directly adjust the elements based on their position:
     - For even indices, ensure the current element is less than the next element.
     - For odd indices, ensure the current element is greater than the next element.
   - This avoids the need for sorting and directly arranges the elements into the zigzag pattern in a single pass.

### Pseudo Code

**Brute Force Approach:**

1. **Sort the Array:**
   - Sort the list of numbers in ascending order.

2. **Rearrange:**
   - Iterate over the sorted list, starting from index 1 and moving in steps of 2.
   - Swap the current element with the next element.

```plaintext
FUNCTION bruteForce_zigzag(nums: LIST OF INT):
    SORT nums
    n = LENGTH(nums)
    FOR i FROM 1 TO n - 2 STEP 2:
        SWAP nums[i] WITH nums[i + 1]
    RETURN
```

**Optimal Approach:**

1. **Adjust Elements:**
   - Iterate over the list from the start to the second last element.
   - For even indices, if the current element is not less than the next element, swap them.
   - For odd indices, if the current element is not greater than the next element, swap them.

```plaintext
FUNCTION optimal_zigzag(nums: LIST OF INT):
    n = LENGTH(nums)
    FOR i FROM 0 TO n - 2:
        IF i % 2 == 0:   // Even index
            IF nums[i] >= nums[i + 1]:
                SWAP nums[i] WITH nums[i + 1]
        ELSE:            // Odd index
            IF nums[i] <= nums[i + 1]:
                SWAP nums[i] WITH nums[i + 1]
    RETURN
```

### Explanation:

- **Brute Force Approach:**
  - **Sorting**: Ensures the initial order is predictable.
  - **Swapping**: Adjusts the sorted order to fit the zigzag pattern.

- **Optimal Approach:**
  - **Direct Adjustments**: Ensures the zigzag pattern by making swaps only when necessary, avoiding the overhead of sorting. This approach works in linear time relative to the size of the input.

**Constraints:**

- 1 <= s.length <= 1000
- `s` consists of English letters (lower-case and upper-case), `','` and `'.'`.
- 1 <= numRows <= 1000

## Question 3:

Problem statement
You have been given ‘K’ different arrays/lists, which are sorted individually (in ascending order). You need to merge all the given arrays/list such that the output array/list should be sorted in ascending order.

[Solve this Problem](https://www.naukri.com/code360/problems/merge-k-sorted-arrays_975379)

**Constraints :**
- 1 <= K <= 5
- 1 <= N <= 20
- -10^5 <= DATA <= 10^5

Time Limit: 1 sec 
```
Sample Input 1:
2
3 
3 5 9 
4 
1 2 3 8   

Sample Output 1:
1 2 3 3 5 8 9 

Explanation of Sample Input 1:
After merging the two given arrays/lists [3, 5, 9] and [ 1, 2, 3, 8], the output sorted array will be [1, 2, 3, 3, 5, 8, 9].

Sample Input 2:
4
3
1 5 9
2
45 90
5
2 6 78 100 234
1
0

Sample Output 2:
0 1 2 5 6 9 45 78 90 100 234
Explanation of Sample Input 2 :
After merging the given arrays/lists [1, 5, 9], [45, 90], [2, 6, 78, 100, 234] and [0], the output sorted array will be [0, 1, 2, 5, 6, 9, 45, 78, 90, 100, 234].
```

## Solution

### Intuition and Approach

The task is to merge `k` sorted arrays into a single sorted array. This problem can be broken down into two main steps:

1. **Merge Two Sorted Arrays**: Develop a function to merge two sorted arrays into one sorted array.
2. **Merge Multiple Sorted Arrays**: Utilize the function from step 1 to iteratively merge all `k` sorted arrays into a single sorted array.

### Intuition

1. **Merging Two Sorted Arrays**:
   - Use a two-pointer technique to merge two sorted arrays into a single sorted array. This involves comparing the current elements of both arrays and adding the smaller element to the result array until one of the arrays is exhausted.
   - After one array is exhausted, append the remaining elements of the other array to the result.

2. **Merging Multiple Sorted Arrays**:
   - Start with the first array as the initial result.
   - Iteratively merge this result with each of the remaining `k-1` arrays using the function from step 1.
   - This iterative approach ensures that at each step, the arrays being merged are already sorted.

### Approach

1. **Merge Function**:
   - Initialize pointers for both input arrays.
   - Compare the current elements from both arrays and add the smaller one to the result.
   - Continue until all elements from both arrays are processed.

2. **Merge k Sorted Arrays**:
   - Initialize the result with the first array.
   - Use the merge function to iteratively merge this result with the next array.
   - Continue until all `k` arrays are merged.

### Pseudo Code

**Merge Two Sorted Arrays**:

```plaintext
FUNCTION merge(array1, array2):
    Initialize pointers i = 0 and j = 0
    Initialize an empty result array

    WHILE i < LENGTH(array1) AND j < LENGTH(array2):
        IF array1[i] < array2[j]:
            Append array1[i] to result
            Increment i
        ELSE:
            Append array2[j] to result
            Increment j

    WHILE i < LENGTH(array1):
        Append array1[i] to result
        Increment i

    WHILE j < LENGTH(array2):
        Append array2[j] to result
        Increment j

    RETURN result
```

**Merge k Sorted Arrays**:

```plaintext
FUNCTION mergeKSortedArrays(kArrays, k):
    Initialize temp with kArrays[0]

    FOR i FROM 1 TO k-1:
        temp = merge(temp, kArrays[i])

    RETURN temp
```

### Explanation

- **Merge Function**:
  - This function efficiently merges two sorted arrays into one sorted array using a two-pointer technique. It handles the merging in linear time relative to the size of the input arrays.

- **Merge k Sorted Arrays**:
  - This function leverages the merge function to combine multiple sorted arrays. By iteratively merging each array with the accumulated result, it ensures that the final result is sorted.

### Complexity

- **Time Complexity**:
  - Merging two arrays: \(O(n_1 + n_2)\), where \(n_1\) and \(n_2\) are the sizes of the two arrays.
  - Merging `k` arrays: Each merge operation involves merging arrays of increasing size, leading to a total time complexity of \(O(N \log k)\), where \(N\) is the total number of elements across all arrays.

- **Space Complexity**:
  - The space complexity is \(O(N)\) due to the additional space needed to store the merged result.
  