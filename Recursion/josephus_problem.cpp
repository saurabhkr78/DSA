// Given n people standing in a circle and a number k, every k-th person is eliminated until only one person remains. The task is to find the position of the last remaining person.
// and josephus was standing at 24th position out of 40people in circle and counting was of 7 including counter and he saved himself
#include <iostream>
using namespace std;

int josephus(int n, int k)
{
    if (n == 1)
    {
        return 0; // Base case: Only one person remains
    }
    return (josephus(n - 1, k) + k) % n;
}

int main()
{
    int n, k;
    cout << "Enter the number of people (n): ";
    cin >> n;
    cout << "Enter the step count (k): ";
    cin >> k;

    int Swordposition = josephus(n, k) + 1; // Convert from 0-based to 1-based index
    cout << "The position of the last remaining person is: " << Swordposition << endl;

    return 0;
}

// for n=large
#include <iostream>

using namespace std;

int josephus(int n, int k)
{
    int result = 0; // Base case: For 1 person, position is 0

    for (int i = 2; i <= n; ++i)
    {
        result = (result + k) % i;
    }

    return result;
}

int main()
{
    int n, k;
    cout << "Enter the number of people (n): ";
    cin >> n;
    cout << "Enter the step count (k): ";
    cin >> k;

    int position = josephus(n, k) + 1; // Convert from 0-based to 1-based index
    cout << "The position of the last remaining person is: " << position << endl;

    return 0;
}
