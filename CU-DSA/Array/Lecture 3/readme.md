# Lecture Day 3

## Question 1: 
Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.

**Example 1:**
```
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation: The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11
```
**Example 2:**
```
Input: nums = [1,2,3]
Output: -1
Explanation: There is no index that satisfies the conditions in the problem statement.
```
**Example 3:**
```
Input: nums = [2,1,-1]
Output: 0
Explanation: The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0
```
Constraints:

- `1 <= nums.length <= 1e4`
- `-1000 <= nums[i] <= 1000`


<!-- ## Solution

**Intuition and Approach:**

The problem is to find the pivot index of an array where the sum of the elements to the left of the pivot is equal to the sum of the elements to the right of the pivot.

**1. Brute Force Approach (`bruteForce_pivotIndex`):**

   - **Intuition:** For each index, calculate the sum of elements on the left and the sum of elements on the right. If they are equal, that index is the pivot.
   - **Approach:**
      ```
      FUNCTION bruteForce_pivotIndex(nums)
         n = LENGTH(nums)
         
         FOR i FROM 0 TO n-1
            leftSum = 0
            rightSum = 0
            
            // Calculate left sum
            FOR j FROM 0 TO i-1
               leftSum = leftSum + nums[j]
            
            // Calculate right sum
            FOR j FROM i+1 TO n-1
               rightSum = rightSum + nums[j]
            
            // Check if left sum is equal to right sum
            IF leftSum == rightSum
               RETURN i
         END FOR
         
         RETURN -1  // Return -1 if no pivot index is found
      END FUNCTION
      ```

**2. Optimal Solution (`optimal_pivotIndex`):**

   - **Intuition:** Calculate the total sum of the array first. Then, iterate through the array while maintaining the sum of elements on the right and left. Adjust these sums dynamically to find the pivot index without recalculating sums repeatedly.
   - **Approach:**
      ```
      FUNCTION optimal_pivotIndex(nums)
         leftSum = 0
         totalSum = SUM of all elements in nums
         
         FOR i FROM 0 TO LENGTH(nums)-1
            totalSum = totalSum - nums[i]  // Adjust right sum
            IF leftSum == totalSum
               RETURN i
            leftSum = leftSum + nums[i]  // Adjust left sum
         END FOR
         
         RETURN -1  // Return -1 if no pivot index is found
      END FUNCTION
      ```

**Key Differences and Considerations:**

- **Time Complexity:**
   - Brute Force: `O(n^2)` due to the nested loops for calculating sums.
   - Optimal: `O(n)` because we only traverse the array twice (once to calculate the total sum and once to find the pivot index).

- **Space Complexity:**
   - Both approaches use `O(1)` extra space, as they only require a few variables.

**Choosing the Right Approach:**

- For small arrays, the brute force approach might be acceptable.
- For larger datasets, the optimal approach is significantly more efficient.
 -->

## Question 2:
The string `"PAYPALISHIRING"` is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
```
P   A   H   N
A P L S I I G
Y   I   R
```
And then read line by line: `"PAHNAPLSIIGYIR"`

Write the code that will take a string and make this conversion given a number of rows:

    string convert(string s, int numRows); 

**Example 1:**
```
Input: s = "HELLOFROMTHEOTHER", numRows = 5
Output: "HOOEERLLFOMTHTR"
```
**Example 2:**
```
Input: s = "HELLOFROMTHEOTHER", numRows = 5
Output: "HOOEERLLFOMTHTR"
Explanation:
H   O   E   T
E L   O R M
L   F   H   H
L   O   T
O   R
```

**Example 3:**
```
Input: s = "A", numRows = 1
Output: "A"
```

**Constraints:**

- 1 <= s.length <= 1000
- `s` consists of English letters (lower-case and upper-case), `','` and `'.'`.
- 1 <= numRows <= 1000

<!-- ## Solution

**Intuition and Approach:**

The problem involves converting a given string into a zigzag pattern on a given number of rows and then reading the characters row-by-row. This pattern forms a diagonal wave, and we need to simulate this in code.

**Approach:**

1. **Initialize Conditions:**
   - If the number of rows is 1, the zigzag conversion is the same as the original string.

2. **Setup the Difference Variables:**
   - Calculate `diff1` as `(numRows + (numRows - 2))`, which will help in identifying the zigzag pattern intervals.
   - Initialize `diff2` to 0, which will be updated in each row iteration.

3. **Loop Through Rows:**
   - For each row, toggle between two differences (`diff1` and `diff2`) to simulate the zigzag pattern. Use a boolean `turn` to alternate between adding `diff1` and `diff2` to the current index `col`.

4. **Update Differences for Each Row:**
   - Decrease `diff1` by 2 and increase `diff2` by 2 after processing each row to adjust for the next row's interval in the zigzag pattern.

**Pseudo Code:**

```
FUNCTION convert(s, numRows)
    IF numRows == 1
        RETURN s

    DECLARE zigzag as empty string
    DECLARE length = size of s
    DECLARE diff1 = (numRows + (numRows - 2))
    DECLARE diff2 = 0

    FOR row FROM 0 TO numRows - 1
        DECLARE turn = true
        DECLARE col = row

        WHILE col < length
            zigzag = zigzag + s[col]

            IF turn
                col = col + (IF diff1 == 0 THEN diff2 ELSE diff1)
                turn = false
            ELSE
                col = col + (IF diff2 == 0 THEN diff1 ELSE diff2)
                turn = true

        diff1 = diff1 - 2
        diff2 = diff2 + 2

    RETURN zigzag
END FUNCTION

MAIN
    DECLARE str = "PAYPALISHIRING"
    DECLARE numRows = 3
    DECLARE result = convert(str, numRows)
    PRINT str + " of zigzag conversion " + result  // Output: "PAHNAPLSIIGYIR"
END MAIN
```

### Explanation of Example:

For `str = "PAYPALISHIRING"` and `numRows = 3`:

- The zigzag pattern is:
  ```
  P   A   H   N
  A P L S I I G
  Y   I   R
  ```

- Reading row-by-row gives: `"PAHNAPLSIIGYIR"`.
 -->

## Question 3:

Given an integer array `nums`, find the contiguous subarray within the array (containing at least one number) that has the largest product, and return the product.

**Input:**
- An integer array `nums` where `1 <= nums.length <= 2 * 10^4`.
- Each element `nums[i]` is an integer where `-10 <= nums[i] <= 10`.

**Output:**
- An integer representing the maximum product of a contiguous subarray.

**Example 1:**
```
Input: nums = [2, 3, -2, 4]
Output: 6
Explanation: [2, 3] has the largest product 6.
```

**Example 2:**
```
Input: nums = [-2, 0, -1]
Output: 0
Explanation: The result cannot be 2, because [-2, -1] is not a subarray.
```

**Example 3:**
```
Input: nums = [0, 2]
Output: 2
Explanation: [2] has the largest product 2.
```

<!-- ## Solution

### Intuition and Approach:

The problem is to find the maximum product subarray in a given array of integers. The solution must handle both positive and negative numbers, which can change the product drastically.

#### Brute Force Approach:

**Intuition:**
- Iterate through the array twice: first from left to right and then from right to left.
- Keep track of the product of elements as you iterate.
- If the product becomes zero, reset it to 1 to handle the case of zero elements in the array.
- Keep track of the maximum product encountered.

**Approach:**
1. Initialize `maxi` to the smallest integer value and `prod` to 1.
2. Traverse the array from left to right, updating the product and maximum product.
3. If the product is zero, reset it to 1.
4. Repeat the process from right to left.
5. Return the maximum product found.

#### Optimal Approach:

**Intuition:**
- Use two passes simultaneously to handle the cases where negative numbers affect the product.
- Track the product from both the left and the right to ensure no subarray is missed.
- Reset the product to 1 if it becomes zero to handle zero elements effectively.

**Approach:**
1. Initialize `maxProd` with the first element of the array.
2. Use two variables, `leftProd` and `rightProd`, initialized to 1, to track the product from the left and the right.
3. Iterate through the array:
    - Update `leftProd` with the product of the current element.
    - Update `rightProd` with the product of the element from the right.
    - Update `maxProd` with the maximum of `leftProd`, `rightProd`, and `maxProd`.
    - Reset `leftProd` and `rightProd` to 1 if they become zero.
4. Return `maxProd`.

### Pseudo Code:

**Brute Force Approach:**
```
FUNCTION bruteForce_maxProduct(nums):
    DECLARE maxi = INT_MIN
    DECLARE prod = 1
    
    FOR num IN nums:
        prod = prod * num
        maxi = MAX(prod, maxi)
        IF prod == 0:
            prod = 1
    
    prod = 1
    
    FOR i FROM size(nums) - 1 TO 0:
        prod = prod * nums[i]
        maxi = MAX(prod, maxi)
        IF prod == 0:
            prod = 1
    
    RETURN maxi
END FUNCTION
```

**Optimal Approach:**
```
FUNCTION optimal_max_product(nums):
    DECLARE maxProd = nums[0]
    DECLARE leftProd = 1
    DECLARE rightProd = 1
    DECLARE n = size(nums) - 1
    
    FOR i FROM 0 TO n:
        IF leftProd == 0:
            leftProd = 1
        IF rightProd == 0:
            rightProd = 1
        
        leftProd = leftProd * nums[i]
        rightProd = rightProd * nums[n - i]
        
        maxProd = MAX(maxProd, MAX(leftProd, rightProd))
    
    RETURN maxProd
END FUNCTION
```
 -->

## Question 4:
Assume you have a method `isSubstring` which checks if one word is a substring of another. Given two strings, `s1` and `s2`, write an algorithm to check if `s2` is a rotation of `s1` using only one call to `isSubstring`. For example, "waterbottle" is a rotation of "erbottlewat".

**Input:**
- Two strings `s1` and `s2` where `1 <= len(s1), len(s2) <= 1000`.

**Output:**
- A boolean value `True` or `False` indicating whether `s2` is a rotation of `s1`.

**Example 1:**
```
Input: s1 = "waterbottle", s2 = "erbottlewat"
Output: True
```

**Example 2:**
```
Input: s1 = "hello", s2 = "llohe"
Output: True
```

**Example 3:**
```
Input: s1 = "hello", s2 = "lleho"
Output: False
```

<!-- ## Solution

### Intuition and Approach:

#### Brute Force Approach:

**Intuition:**
To determine if one string is a rotation of another, the brute force method involves checking all possible rotations of the first string to see if any of them match the second string. This involves iterating through all possible starting points of the first string and comparing characters in a cyclic manner.

**Approach:**
1. Check if the lengths of the two strings are equal. If not, return `false`.
2. Iterate over each character in the first string as the starting point.
3. For each starting point, compare the characters of the first string (in a cyclic manner) with the characters of the second string.
4. If a match is found, return `true`.
5. If no match is found after all rotations, return `false`.

**Pseudo Code:**
```
FUNCTION isRotationBruteForce(s1, s2):
    IF size(s1) != size(s2):
        RETURN false
    
    n = size(s1)
    
    FOR i FROM 0 TO n-1:
        isRotation = true
        
        FOR j FROM 0 TO n-1:
            IF s1[(i + j) % n] != s2[j]:
                isRotation = false
                BREAK
        
        IF isRotation:
            RETURN true
    
    RETURN false
END FUNCTION
```

#### Optimal Approach:

**Intuition:**
An optimized approach leverages the fact that if `s2` is a rotation of `s1`, then `s2` will always be a substring of `s1 + s1`. By doubling `s1` and checking if `s2` is a substring of this doubled string, we can efficiently determine if `s2` is a rotation of `s1`.

**Approach:**
1. Check if the lengths of the two strings are equal. If not, return `false`.
2. Concatenate `s1` with itself to form a new string `s1s1`.
3. Check if `s2` is a substring of `s1s1`.
4. If it is, return `true`. Otherwise, return `false`.

**Pseudo Code:**
```
FUNCTION isSubstring(str1, str2):
    RETURN find(str1, str2) != -1
END FUNCTION

FUNCTION isRotationOptimal(s1, s2):
    IF size(s1) != size(s2):
        RETURN false
    
    s1s1 = s1 + s1
    RETURN isSubstring(s1s1, s2)
END FUNCTION
``` -->
