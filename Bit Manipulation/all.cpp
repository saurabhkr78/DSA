#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <algorithm>

using namespace std;

// Basic Bitwise Operations
void basicBitwiseOperations() {
    int a = 5; // 0101
    int b = 3; // 0011

    cout << "a = " << a << ", b = " << b << "\n";
    cout << "a & b = " << (a & b) << " (Binary: " << bitset<8>(a & b) << ")\n";
    cout << "a | b = " << (a | b) << " (Binary: " << bitset<8>(a | b) << ")\n";
    cout << "a ^ b = " << (a ^ b) << " (Binary: " << bitset<8>(a ^ b) << ")\n";
    cout << "~a = " << (~a) << " (Binary: " << bitset<8>(~a) << ")\n";
}

// Common Bit Manipulation Tricks
void commonTricks() {
    int n = 29; // 11101 in binary
    cout << "Number of set bits (popcount): " << __builtin_popcount(n) << "\n";
    cout << "Clearing the lowest set bit: " << (n & (n - 1)) << " (Binary: " << bitset<8>(n & (n - 1)) << ")\n";
    cout << "Finding the lowest set bit: " << (n & -n) << " (Binary: " << bitset<8>(n & -n) << ")\n";
}

// Swapping Two Numbers Using XOR
void swapUsingXOR() {
    int x = 5, y = 9;
    x ^= y;
    y ^= x;
    x ^= y;
    cout << "After swapping: x = " << x << ", y = " << y << "\n";
}

// Bit Masking
void bitMasking() {
    int n = 29; // 11101 in binary
    int mask = 0b1110; // Mask: 1110

    cout << "Original n = " << n << " (Binary: " << bitset<8>(n) << ")\n";
    cout << "Mask = " << mask << " (Binary: " << bitset<8>(mask) << ")\n";

    int extracted = n & mask;
    cout << "Extracted bits = " << extracted << " (Binary: " << bitset<8>(extracted) << ")\n";
}

// Rotating Bits
void rotateBits() {
    int n = 13; // 1101 in binary
    int bits = 4; // Number of bits to rotate

    int rotated_left = rotateLeft(n, 1);
    cout << "Rotated left: " << rotated_left << " (Binary: " << bitset<8>(rotated_left) << ")\n";

    int rotated_right = rotateRight(n, 1);
    cout << "Rotated right: " << rotated_right << " (Binary: " << bitset<8>(rotated_right) << ")\n";
}

// Popcount Examples
void popcountExamples() {
    int n = 29; // 11101 in binary

    int count_builtin = __builtin_popcount(n);
    cout << "Popcount (built-in): " << count_builtin << "\n";

    int count_manual = 0;
    int temp = n;
    while (temp) {
        count_manual += temp & 1;
        temp >>= 1;
    }
    cout << "Popcount (manual): " << count_manual << "\n";
}

// Large Integer Bit Manipulation
void largeIntegerBitManipulation() {
    uint64_t large_num = 0xFFFFFFFFFFFFF; // A large 64-bit number

    cout << "Large number: " << large_num << " (Binary: " << bitset<64>(large_num) << ")\n";

    uint64_t cleared_bits = large_num & ~((1ULL << 16) - 1);
    cout << "After clearing last 16 bits: " << cleared_bits << " (Binary: " << bitset<64>(cleared_bits) << ")\n";
}

// Sparse Table Example
void sparseTableExample() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13};
    int n = arr.size();
    vector<vector<int>> st(n, vector<int>(32));

    for (int i = 0; i < n; ++i) {
        st[i][0] = arr[i];
    }
    for (int j = 1; (1 << j) <= n; ++j) {
        for (int i = 0; (i + (1 << j) - 1) < n; ++i) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    int l = 1, r = 5; // Range [1, 5]
    int j = 0;
    while ((1 << (j + 1)) <= (r - l + 1)) ++j;
    int result = max(st[l][j], st[r - (1 << j) + 1][j]);

    cout << "Maximum in range [" << l << ", " << r << "] is " << result << "\n";
}

// Additional Bit Manipulation Techniques
void additionalBitManipulation() {
    int x = 12; // 1100 in binary

    setBit(x, 2);
    cout << "After setting 2nd bit: " << x << " (Binary: " << bitset<8>(x) << ")\n";

    clearBit(x, 2);
    cout << "After clearing 2nd bit: " << x << " (Binary: " << bitset<8>(x) << ")\n";

    toggleBit(x, 1);
    cout << "After toggling 1st bit: " << x << " (Binary: " << bitset<8>(x) << ")\n";

    cout << "Is 2nd bit set? " << (isBitSet(x, 2) ? "Yes" : "No") << "\n";

    cout << "Extract bits from 1 to 3: " << extractBits(x, 1, 3) << " (Binary: " << bitset<8>(extractBits(x, 1, 3)) << ")\n";

    int combined = combineBits(x, 5, 1, 3);
    cout << "After combining bits: " << combined << " (Binary: " << bitset<8>(combined) << ")\n";

    cout << "Is " << x << " even? " << (isEven(x) ? "Yes" : "No") << "\n";
    cout << "Is " << x << " odd? " << (isOdd(x) ? "Yes" : "No") << "\n";

    cout << "Most significant set bit of " << x << ": " << mostSignificantSetBit(x) << " (Binary: " << bitset<8>(mostSignificantSetBit(x)) << ")\n";

    cout << "Position of the most significant set bit of " << x << ": " << positionMostSignificantSetBit(x) << "\n";

    cout << "After flipping bits from 1 to 3: " << flipBitsInRange(x, 1, 3) << " (Binary: " << bitset<8>(flipBitsInRange(x, 1, 3)) << ")\n";

    cout << "Finding the only set bit in " << x << ": " << findOnlySetBit(x) << " (Binary: " << bitset<8>(findOnlySetBit(x)) << ")\n";

    cout << "Toggling bits from 1 to 3: " << toggleBitsInRange(x, 1, 3) << " (Binary: " << bitset<8>(toggleBitsInRange(x, 1, 3)) << ")\n";

    cout << "Is " << x << " a power of 2? " << (isPowerOfTwo(x) ? "Yes" : "No") << "\n";

    cout << "Count of 1 bits in range 1 to 3: " << countBitsInRange(x, 1, 3) << "\n";

    cout << "Mask to the right of bit 3: " << maskToRightOfBit(3) << " (Binary: " << bitset<8>(maskToRightOfBit(3)) << ")\n";

    cout << "Most significant bit of " << x << ": " << mostSignificantBit(x) << "\n";

    cout << "Binary representation of " << x << " with leading zeros: " << toBinaryWithLeadingZeros(x, 8) << "\n";
}

bool isBitSet(int n, int pos) {
    return (n & (1 << pos)) != 0;
}

void setBit(int& n, int pos) {
    n |= (1 << pos);
}

void clearBit(int& n, int pos) {
    n &= ~(1 << pos);
}

void toggleBit(int& n, int pos) {
    n ^= (1 << pos);
}

int extractBits(int n, int start, int end) {
    return (n >> start) & ((1 << (end - start + 1)) - 1);
}

int combineBits(int n, int value, int start, int end) {
    int mask = ((1 << (end - start + 1)) - 1) << start;
    return (n & ~mask) | ((value << start) & mask);
}

bool isEven(int n) {
    return (n & 1) == 0;
}

bool isOdd(int n) {
    return (n & 1) == 1;
}

int mostSignificantSetBit(int n) {
    if (n == 0) return 0;
    int msb = 1;
    while (n >>= 1) msb <<= 1;
    return msb;
}

int positionMostSignificantSetBit(int n) {
    return sizeof(n) * 8 - 1 - __builtin_clz(n);
}

int flipBitsInRange(int n, int start, int end) {
    int mask = ((1 << (end - start + 1)) - 1) << start;
    return n ^ mask;
}

int findOnlySetBit(int x) {
    if (x == 0) return -1; // No set bit
    return x & -x;
}

int toggleBitsInRange(int n, int start, int end) {
    int mask = ((1 << (end - start + 1)) - 1) << start;
    return n ^ mask;
}

bool isPowerOfTwo(int x) {
    return (x > 0) && ((x & (x - 1)) == 0);
}

int countBitsInRange(int n, int start, int end) {
    int mask = ((1 << (end - start + 1)) - 1) << start;
    return __builtin_popcount(n & mask);
}

int maskToRightOfBit(int pos) {
    return (1 << pos) - 1;
}

int mostSignificantBit(int n) {
    int pos = 0;
    while (n >>= 1) {
        pos++;
    }
    return pos;
}

string toBinaryWithLeadingZeros(int n, int bits) {
    return bitset<32>(n).to_string().substr(32 - bits, bits);
}

int main() {
    cout << "Bit Manipulation Examples:\n\n";

    // Basic Bitwise Operations
    cout << "Basic Bitwise Operations:\n";
    basicBitwiseOperations();
    cout << "\n";

    // Common Bit Manipulation Tricks
    cout << "Common Bit Manipulation Tricks:\n";
    commonTricks();
    cout << "\n";

    // Swapping Using XOR
    cout << "Swapping Two Numbers Using XOR:\n";
    swapUsingXOR();
    cout << "\n";

    // Bit Masking
    cout << "Bit Masking:\n";
    bitMasking();
    cout << "\n";

    // Rotating Bits
    cout << "Rotating Bits:\n";
    rotateBits();
    cout << "\n";

    // Popcount Examples
    cout << "Popcount Examples:\n";
    popcountExamples();
    cout << "\n";

    // Large Integer Bit Manipulation
    cout << "Large Integer Bit Manipulation:\n";
    largeIntegerBitManipulation();
    cout << "\n";

    // Sparse Table Example
    cout << "Sparse Table Example:\n";
    sparseTableExample();
    cout << "\n";

    // Additional Bit Manipulation Techniques
    cout << "Additional Bit Manipulation Techniques:\n";
    additionalBitManipulation();
    cout << "\n";

    return 0;
}
