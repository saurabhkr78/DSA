# Lecture Day 4

## Question 1: 
Given two large numbers represented as strings, write a program to compute their sum, difference, and multiplication. The numbers can be very large and might not fit into standard data types like `int` or `long`. The numbers can be negative.

**Input:**
- Two integers `num1` and `num2` represented as strings. Each string contains digits (`0-9`) and may contain a leading '-' sign to indicate a negative number. 
- The length of `num1` and `num2` can be up to `10^4`.

**Output:**
- A string representing the sum of `num1` and `num2`.
- A string representing the difference between `num1` and `num2` (`num1 - num2`).
- A string representing the product of `num1` and `num2`.

**Example 1:**
```
Input: 
num1 = "12345678901234567890"
num2 = "-98765432109876543210"

Output: 
Sum: "-86419753208641975320"
Difference: "111111111011111111100"
Product: "-1219326311370217952237463801111263526900"
```

**Example 2:**
```
Input: 
num1 = "-12345"
num2 = "6789"

Output: 
Sum: "-5556"
Difference: "-19134"
Product: "-83810205"
```

**Constraints:**
- The input numbers can be negative or non-negative and do not contain leading zeros except for "0".
- Both `num1` and `num2` have lengths in the range `[1, 10000]`.

**Instructions:**
- Implement the functions `string addStrings(string num1, string num2)`, `string subtractStrings(string num1, string num2)`, and `string multiplyStrings(string num1, string num2)` to compute the sum, difference, and product of the given strings.
- Ensure that the functions handle very large numbers efficiently and correctly manage negative numbers.

**Hints:**
- Use elementary school arithmetic to handle the addition, subtraction, and multiplication manually.
- Handle the signs separately and decide the final sign of the result based on the signs of the inputs.
- Consider iterating through the strings from the least significant digit to the most significant digit to simulate the arithmetic operations.


### Implementation Hints

1. **Addition**:
   - If both numbers have the same sign, add them as usual.
   - If they have different signs, convert the addition into a subtraction problem.

2. **Subtraction**:
   - If the numbers have the same sign, subtract them as usual.
   - If they have different signs, convert the subtraction into an addition problem.

3. **Multiplication**:
   - Multiply the absolute values of the numbers.
   - Determine the sign of the result based on the signs of the input numbers.

Implementing these functions involves parsing the sign, handling the arithmetic operations, and then reapplying the sign to the results.

## Solution

### Intuition and Approach

**Intuition:**

The problem requires us to perform basic arithmetic operations (addition, subtraction, and multiplication) on large integers represented as strings. This is because built-in data types may not handle extremely large numbers due to overflow. The solution needs to consider both positive and negative numbers and manage the arithmetic operations accordingly.

**Approach:**

1. **Addition**:
   - Traverse the digits from right to left, simulating the addition process.
   - Manage the carry for sums greater than 9.
   - Handle cases where one number is longer than the other by treating missing digits as 0.

2. **Subtraction**:
   - Traverse the digits from right to left, simulating the subtraction process.
   - Manage borrowing when the digit in the minuend is smaller than the corresponding digit in the subtrahend.
   - Handle cases where one number is longer than the other by treating missing digits as 0.
   - Remove leading zeros from the result.

3. **Multiplication**:
   - Use a nested loop to multiply each digit of the first number with each digit of the second number.
   - Accumulate the results in the correct positions of an array.
   - Convert the array to a string, removing any leading zeros.

4. **Handling Signs**:
   - Before performing the actual operations, strip the signs and store them.
   - Based on the signs of the input numbers, decide the sign of the result.
   - Handle edge cases where inputs are negative.

### Pseudo Code

```
FUNCTION addition(num1: STRING, num2: STRING) RETURNS STRING:
    INITIALIZE i = LENGTH(num1) - 1
    INITIALIZE j = LENGTH(num2) - 1
    INITIALIZE carry = 0
    INITIALIZE result AS EMPTY STRING
    
    WHILE i >= 0 OR j >= 0 OR carry:
        INITIALIZE sum = carry
        IF i >= 0:
            sum += CHAR_TO_INT(num1[i])
            DECREMENT i
        IF j >= 0:
            sum += CHAR_TO_INT(num2[j])
            DECREMENT j
        carry = sum / 10
        result.APPEND(CHAR(sum % 10 + '0'))
    
    REVERSE(result)
    RETURN result

FUNCTION subtraction(num1: STRING, num2: STRING) RETURNS STRING:
    INITIALIZE i = LENGTH(num1) - 1
    INITIALIZE j = LENGTH(num2) - 1
    INITIALIZE borrow = 0
    INITIALIZE result AS EMPTY STRING

    WHILE i >= 0 OR j >= 0 OR borrow:
        INITIALIZE diff = (IF i >= 0 THEN CHAR_TO_INT(num1[i]) ELSE 0) - (IF j >= 0 THEN CHAR_TO_INT(num2[j]) ELSE 0) - borrow
        IF diff < 0:
            diff += 10
            borrow = 1
        ELSE:
            borrow = 0
        result.APPEND(CHAR(diff + '0'))
        DECREMENT i
        DECREMENT j
    
    REMOVE leading zeros from result
    REVERSE(result)
    RETURN result

FUNCTION multiplication(num1: STRING, num2: STRING) RETURNS STRING:
    INITIALIZE n = LENGTH(num1)
    INITIALIZE m = LENGTH(num2)
    INITIALIZE result AS ARRAY OF SIZE (n + m) WITH ZEROES

    FOR i FROM n-1 TO 0:
        FOR j FROM m-1 TO 0:
            INITIALIZE mul = CHAR_TO_INT(num1[i]) * CHAR_TO_INT(num2[j])
            INITIALIZE sum = mul + result[i + j + 1]
            result[i + j] += sum / 10
            result[i + j + 1] = sum % 10

    INITIALIZE product AS EMPTY STRING
    FOR num IN result:
        IF product IS EMPTY AND num == 0:
            CONTINUE
        product.APPEND(CHAR(num + '0'))

    RETURN product IS EMPTY ? "0" : product

FUNCTION add(num1: STRING, num2: STRING) RETURNS STRING:
    INITIALIZE neg1 = (num1[0] == '-')
    INITIALIZE neg2 = (num2[0] == '-')
    IF neg1:
        num1 = SUBSTRING(num1, 1)
    IF neg2:
        num2 = SUBSTRING(num2, 1)

    IF neg1 AND neg2:
        RETURN '-' + addition(num1, num2)
    IF NOT neg1 AND NOT neg2:
        RETURN addition(num1, num2)
    IF neg1 AND NOT neg2:
        RETURN subtraction(num2, num1)
    IF NOT neg1 AND neg2:
        RETURN subtraction(num1, num2)

FUNCTION subtract(num1: STRING, num2: STRING) RETURNS STRING:
    INITIALIZE neg1 = (num1[0] == '-')
    INITIALIZE neg2 = (num2[0] == '-')
    IF neg1:
        num1 = SUBSTRING(num1, 1)
    IF neg2:
        num2 = SUBSTRING(num2, 1)

    IF neg1 AND neg2:
        RETURN subtraction(num2, num1)
    IF NOT neg1 AND NOT neg2:
        RETURN subtraction(num1, num2)
    IF neg1 AND NOT neg2:
        RETURN '-' + addition(num1, num2)
    IF NOT neg1 AND neg2:
        RETURN addition(num1, num2)

FUNCTION multiply(num1: STRING, num2: STRING) RETURNS STRING:
    INITIALIZE neg1 = (num1[0] == '-')
    INITIALIZE neg2 = (num2[0] == '-')
    IF neg1:
        num1 = SUBSTRING(num1, 1)
    IF neg2:
        num2 = SUBSTRING(num2, 1)

    INITIALIZE result = multiplication(num1, num2)
    IF (neg1 AND NOT neg2) OR (NOT neg1 AND neg2):
        RETURN '-' + result
    RETURN result

FUNCTION main() RETURNS VOID:
    INITIALIZE num1, num2 AS STRING
    PRINT "Enter first number: "
    READ num1
    PRINT "Enter second number: "
    READ num2

    PRINT "Sum: " + add(num1, num2)
    PRINT "Difference: " + subtract(num1, num2)
    PRINT "Product: " + multiply(num1, num2)

CALL main()
```


## Question 2: 
Create a program that performs long division where the divisor ranges from 1 to 100, and the dividend is a very large number provided as a string. The program should prompt the user to input a large number as the dividend and an integer between 1 and 100 as the divisor. It should then perform the division using a method that mimics the manual long division process and print out both the quotient and the remainder of the division. Ensure that the program handles the input correctly and provides clear output for the user.

**Input:**
- A very large number as the dividend, represented as a string.
- An integer between 1 and 100 as the divisor.

**Output:**
- The quotient and the remainder of the division.

**Sample Input:**
```
Please enter the dividend (a very large number): 123456789012345678901234567890
Please enter the divisor (1-100): 97
```

**Sample Output:**
```
The result of the division is:
Quotient: 1277946247570636777311614276
Remainder: 62
```

**Constraints:**
- The dividend is a non-integer provided as a string and can be very large (up to 1 to 1000).
- The divisor is an integer between 1 and 100 inclusive.

**Instructions:**
- Implement the program to perform the division using a method that mimics the manual long division process.
- Ensure the program handles potential errors, such as the divisor being outside the specified range.
- You can use any programming language to solve this problem.
- Provide clear and user-friendly input and output prompts.

## Solution

### Intuition and Approach

**Intuition:**

Long division is a method of dividing larger numbers that cannot be easily divided mentally. By breaking down the problem digit by digit, we can manage the division process in a way that's similar to how humans perform long division manually. The goal is to calculate the quotient and the remainder when a large number (dividend) is divided by a smaller number (divisor).

**Approach:**

1. Initialize an empty string `quotient` to store the result and a variable `remainder` set to 0.
2. Iterate through each digit of the dividend:
   - Update the remainder by multiplying it by 10 and adding the current digit of the dividend.
   - If the current remainder is less than the divisor, continue to the next digit and add a '0' to the quotient if it's not the first character.
   - If the current remainder is greater than or equal to the divisor:
     - Calculate the quotient digit by performing integer division of the remainder by the divisor and append it to the quotient string.
     - Update the remainder to be the remainder of the division.
3. If the quotient string is still empty after the loop, set it to "0" to handle the case where the dividend is less than the divisor.
4. Return the quotient and remainder.

### Pseudo Code

```
FUNCTION longDivision(dividend: STRING, divisor: INT) RETURNS PAIR<STRING, INT>:
    INITIALIZE quotient AS EMPTY STRING
    INITIALIZE remainder AS 0
    n = LENGTH OF dividend

    FOR i FROM 0 TO n-1:
        remainder = remainder * 10 + (dividend[i] - '0')
        
        WHILE i < n-1 AND divisor > remainder:
            i += 1
            remainder = remainder * 10 + (dividend[i] - '0')
            IF quotient IS NOT EMPTY:
                quotient += '0'
        
        IF remainder >= divisor:
            quotient += (remainder // divisor) + '0'
            remainder = remainder % divisor
    
    IF quotient IS EMPTY:
        quotient = "0"
    
    RETURN PAIR<quotient, remainder>
END FUNCTION
```

## Question 3:
Given a string containing alphanumeric characters and possibly one leading '+' or '-' sign, write an algorithm to convert the string to an integer by ignoring all alphabetic characters. The conversion should handle both positive and negative integers correctly.

**Input:**
- A string `s` where `1 <= len(s) <= 1000`.

**Output:**
- An integer representing the numeric value of the input string after ignoring all alphabetic characters and considering the sign.

**Example 1:**
```
Input: "ahfda12jkdsa34-5"
Output: 12345
```

**Example 2:**
```
Input: "-dsa212+21"
Output: -21221
```

**Example 3:**
```
Input: "+-223482"
Output: 223482
```

## Solution

### Intuition and Approach

**Intuition:**

The problem is about extracting a valid integer (in string form) from a given string that may contain non-digit characters. This includes considering an optional leading sign ('+' or '-') and discarding any non-numeric characters that follow. The primary goal is to clean up the string to form a valid integer representation.

**Approach:**

1. **Initialization**: 
   - `sign` is a boolean flag to indicate if the sign has been processed.
   - `integer` is a boolean flag to indicate if at least one digit has been processed.
   - `number` is a string that will store the resultant formatted number.

2. **Iteration through the string**:
   - For each character in the input string:
     - If the character is a sign ('+' or '-') and the sign has not been processed yet (`!sign`), add the '-' to `number` if the character is '-', and set `sign` to true.
     - If the character is a digit ('0' to '9'), add it to `number` and set `integer` to true.
   - Stop adding digits once non-digit characters are encountered after a digit has been added.

3. **Return the Result**:
   - Return the formatted number string.

### Pseudo Code

```
FUNCTION formet_number(disturb_number: STRING) RETURNS STRING:
    INITIALIZE sign AS false
    INITIALIZE integer AS false
    INITIALIZE number AS EMPTY STRING

    FOR EACH character IN disturb_number:
        IF NOT sign AND NOT integer AND (character IS '+' OR character IS '-'):
            IF character IS '-':
                APPEND '-' TO number
            SET sign TO true
        IF character IS DIGIT:
            APPEND character TO number
            SET integer TO true
    
    RETURN number
END FUNCTION
```

## Question 4:

You are given an array consisting of 'N' elements and you need to perform 'Q' queries on the given array. Each query consists of an integer which tells the number of elements by which you need to left rotate the given array. For each query return the final array obtained after performing the left rotations.

**Note:**

Perform each query on the original array only i.e. every output should be according to the original order of elements.
Example:

Let the array be [1, 2, 3, 4, 5, 6] and the queries be {2, 4, 1}. For every query, we’ll perform the required number of left rotations on the array.

For the first query, rotate the given array to the left by 2 elements, so the resultant array is: [3, 4, 5, 6, 1, 2].

For the second query, rotate the given array to the left by 4 elements, so the resultant array is: [5, 6, 1, 2, 3, 4].

For the third query, rotate the given array to the left by 1 element, so the resultant array is: [2, 3, 4, 5, 6, 1].

[Solve a Problem](https://www.naukri.com/code360/problems/left-rotations-of-an-array_985298)

**Constraints:**
- 1 <= T <= 10
- 1 <= N <= 1000
- 1 <= Q <= 100
- 0 <= Queries[i] <= 10^5
- -10^5 <= Array[i] <= 10^5

Where 'Queries[i]' denotes the extent to which the array in each query needs to be rotated and 'Array[i]' denotes the array element.

Time limit: 1 sec

**Sample Input 1:**
```
2
5 3
7 8 6 1 2
8 4 3
2 2
12 15
1 2    
```
**Sample Output 1:**
```
1 2 7 8 6 
2 7 8 6 1
1 2 7 8 6 
15 12
12 15
```
**Explanation for Sample Output 1:**
```
In test case 1, we have, array: [7, 8, 6, 1, 2] and three queries: {8, 4, 3}.

For the first query we rotate the given array to the left 8 times, so the resultant array is: [1, 2, 7, 8, 6].

For the second query we rotate the given array to the left 4 times, so the resultant array is: [2, 7, 8, 6, 1].

For the third query we rotate the given array to the left 3 times, so the resultant array is: [1, 2, 7, 8, 6].

In test case 2, we have, array: [12, 15] and two queries: {1, 2}.

For the first query we rotate the given array to the left 1 time, so the resultant array is: [15, 12].

For the second query we rotate the given array to the left 2 times, so the resultant array is: [12, 15].
```
**Sample Input 2:**
```
2
6 3
10 20 30 40 50 60
12 2 5
1 2
-15
100 89
```
**Sample Output 2:**
```
10 20 30 40 50 60 
30 40 50 60 10 20 
60 10 20 30 40 50 
-15
-15
``
Explanation for Sample Output 2:
In test case 1, we have, array: [10, 20, 30, 40, 50, 60] and three queries: {12, 2, 5}.

For the first query we rotate the given array to the left 12 times, so the resultant array is: [10, 20, 30, 40, 50, 60].

For the second query we rotate the given array to the left 2 times, so the resultant array is: [30, 40, 50, 60, 10, 20].

For the third query we rotate the given array to the left 5 times, so the resultant array is: [60, 10, 20, 30, 40, 50]

In test case 2, we have, array: [-15] and two queries: {100, 89}.

For the first query we rotate the given array to the left 100 times, so the resultant array is: [-15].

For the second query we rotate the given array to the left 89 times, so the resultant array is: [-15].
```

## Solution

### Intuition and Approach

**Intuition:**

The problem is to perform left rotations on an array for given queries and return the resulting arrays. Each query specifies the number of left rotations to be performed on the array. The approach involves shifting the elements of the array to the left by a given number of positions for each query.

**Approach:**

1. **Initialization**:
   - Read the number of test cases.
   - For each test case, read the size of the array and the number of queries.
   - Read the elements of the array.
   - Read the rotation queries.

2. **Processing Rotations**:
   - For each query:
     - Calculate the effective rotation (`query % size`) to handle cases where the number of rotations is greater than the array size.
     - Perform the left rotation by slicing the array at the rotation index and appending the two parts in reverse order.
     - Store the result of each rotation.

3. **Output**:
   - Print the resulting arrays after each query.

### Pseudo Code

```
FUNCTION leftRotationsOfArray(nums: ARRAY, queries: ARRAY) RETURNS ARRAY:
    INITIALIZE results AS EMPTY ARRAY
    SET size AS LENGTH OF nums

    FOR EACH query IN queries:
        INITIALIZE temp AS EMPTY ARRAY
        IF size == query OR size == 1:
            APPEND nums TO results
            CONTINUE
        IF size < query:
            SET query = query % size
        FOR i FROM query TO size-1:
            APPEND nums[i] TO temp
        FOR i FROM 0 TO query-1:
            APPEND nums[i] TO temp
        APPEND temp TO results

    RETURN results
END FUNCTION

FUNCTION main() RETURNS VOID:
    READ time
    WHILE time > 0:
        READ n, q
        INITIALIZE nums AS EMPTY ARRAY
        FOR i FROM 0 TO n-1:
            READ temp
            APPEND temp TO nums
        INITIALIZE queries AS EMPTY ARRAY
        FOR i FROM 0 TO q-1:
            READ temp
            APPEND temp TO queries

        SET results = leftRotationsOfArray(nums, queries)
        FOR EACH result IN results:
            FOR EACH value IN result:
                PRINT value + ' '
            PRINT NEWLINE
        PRINT NEWLINE
        DECREMENT time
END FUNCTION
```
