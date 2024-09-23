int exponentialSearch(vector<int>& arr, int key) {
    int i = 0, j = 1;

    // Expand the range exponentially
    while (j < arr.size() && key > arr[j]) {
        i = j;
        j = j * 2;
    }

    // Ensure j doesn't exceed array size
    if (j >= arr.size()) {
        j = arr.size() - 1;
    }

    // Now perform binary search in the range [i, j]
    return binarySearch(arr, i, j, key);
}

// Binary search implementation in range [i, j]
int binarySearch(vector<int>& arr, int i, int j, int key) {
    while (i <= j) {
        int mid = i + (j - i) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) i = mid + 1;
        else j = mid - 1;
    }
    return -1; // If key is not found
}
