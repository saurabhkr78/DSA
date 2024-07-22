// Include standard libraries
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// Macros for convenience
#define ll long long int                              // Alias for long long int
#define ull unsigned long long int                    // Alias for unsigned long long int
#define lld long double                               // Alias for long double
#define ar array                                      // Alias for array
#define F first                                       // Shortcut for first element in pair
#define S second                                      // Shortcut for second element in pair
#define PI 3.141592653589793238462                    // Definition of Pi
#define sfi(n) scanf("%d", &n)                        // Shortcut for scanf integer
#define sfl(n) scanf("%lld", &n)                      // Shortcut for scanf long long int
#define pfi(n) printf("%i", n)                        // Shortcut for printf integer
#define pfl(n) printf("%lld", n)                      // Shortcut for printf long long int
#define f(i, a, n) for (ll i = a; i < n; i++)         // Loop from a to n
#define fn(i, n, a) for (int i = n - 1; i >= a; i--)  // Loop from n-1 to a
#define fll(i, a, n) for (ll i = a; i < n; i++)       // Loop for long long from a to n
#define flln(i, n, a) for (ll i = n - 1; i >= a; i--) // Loop for long long from n-1 to a
#define all(x) (x).begin(), (x).end()                 // Shortcut to get begin and end iterators
#define sz(x) ((int)(x).size())                       // Get size of a container
#define MAX(a, b) ((a) > (b) ? (a) : (b))             // Return maximum of two values
#define pb push_back                                  // Shortcut for push_back
#define pii pair<int, int>                            // Alias for pair of integers
#define lb lower_bound                                // Shortcut for lower_bound
#define ub upper_bound                                // Shortcut for upper_bound
#define mp make_pair                                  // Shortcut for make_pair
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL) // Fast I/O

// Operator overloads
template <typename T1, typename T2> // cin >> pair<T1, T2>
istream &operator>>(istream &istream, pair<T1, T2> &p)
{
    return (istream >> p.first >> p.second);
}
template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T1, typename T2> // cout << pair<T1, T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p)
{
    return (ostream << p.first << " " << p.second);
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

// Utility functions for printing
template <typename T>
void print(T &&t) { cout << t << "\n"; }
void printarr(ll arr[], ll n)
{
    f(i, 0, n) cout << arr[i] << " ";
    cout << "\n";
}
template <typename T>
void printvec(vector<T> v)
{
    ll n = v.size();
    f(i, 0, n) cout << v[i] << " ";
    cout << "\n";
}
template <typename T>
ll sumvec(vector<T> v)
{
    ll n = v.size();
    ll s = 0;
    f(i, 0, n) s += v[i];
    return s;
}

// Custom data structures
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

// Type aliases
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;

using u8 = uint8_t;           // 8-bit unsigned integer
using i8 = int8_t;            // 8-bit signed integer
using u16 = uint16_t;         // 16-bit unsigned integer
using i16 = int16_t;          // 16-bit signed integer
using u32 = uint32_t;         // 32-bit unsigned integer
using i32 = int32_t;          // 32-bit signed integer
using u64 = uint64_t;         // 64-bit unsigned integer
using i64 = int64_t;          // 64-bit signed integer
using usize = std::size_t;    // Size type (unsigned, architecture-dependent)
using isize = std::ptrdiff_t; // Pointer difference type (signed, architecture-dependent)

// Pragma directives for optimization
#pragma once // Ensures the file is included only once during compilation
#pragma optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

// Sorting functions
bool sorta(const pair<int, int> &a, const pair<int, int> &b) { return (a.second < b.second); }
bool sortd(const pair<int, int> &a, const pair<int, int> &b) { return (a.second > b.second); }

// Bit manipulation functions
string decToBinary(int n)
{
    string s = "";
    int i = 0;
    while (n > 0)
    {
        s = to_string(n % 2) + s;
        n = n / 2;
        i++;
    }
    return s;
}
ll binaryToDecimal(string n)
{
    string num = n;
    ll dec_value = 0;
    int base = 1;
    int len = num.length();
    for (int i = len - 1; i >= 0; i--)
    {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
}

// Mathematical checks
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
bool isPerfectSquare(ll x)
{
    if (x >= 0)
    {
        ll sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}

// Constants
const int INF = 1e9 + 7;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

// Debugging tools
#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) { cerr << t; }
void _print(ll t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.F);
    cerr << ",";
    _print(p.S);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

// Utility functions
template <typename T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template <typename T>
T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
template <typename T>
T mod_exp(T base, T exp, T mod)
{
    T result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
template <typename T>
bool is_prime(T n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (T i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

// Random number generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Main function
int main()
{
    fast_io; // Fast I/O setup

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);   // Redirect input
    freopen("output.txt", "w", stdout); // Redirect output
    freopen("error.txt", "w", stderr);  // Redirect error output
#endif

    int t;
    cin >> t; // Number of test cases
    while (t--)
    {
        // Your code here
    }

    return 0;
}
