#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // For policy-based data structures
#include <ext/pb_ds/tree_policy.hpp>     // For tree policy

using namespace std;
using namespace __gnu_pbds;

// Define data types and common macros
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;

#define ar array
#define F first
#define S second
#define PI 3.141592653589793238462
#define sfi(n) scanf("%d", &n)
#define sfl(n) scanf("%lld", &n)
#define pfi(n) printf("%i", n)
#define pfl(n) printf("%lld", n)
#define f(i, a, n) for (ll i = a; i < n; i++)
#define fn(i, n, a) for (int i = n - 1; i >= a; i--)
#define fll(i, a, n) for (ll i = a; i < n; i++)
#define flln(i, n, a) for (ll i = n - 1; i >= a; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define pb push_back
#define pii pair<int, int>
#define lb lower_bound
#define ub upper_bound
#define mp make_pair

// Policy-based data structures
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename K, typename V>
using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

// Hash tables with randomized hash function
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();

struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};

template<typename T>
using hash_set = gp_hash_table<T, chash>;

template<typename K, typename V>
using hash_map = gp_hash_table<K, V, chash>;

// Template Functions and Class Definitions
template<typename T1, typename T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }

template<typename T>
istream& operator>>(istream &istream, vector<T> &v) { for (auto &it : v) cin >> it; return istream; }

template<typename T1, typename T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }

template<typename T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

// Utility Functions
template <typename T>
void print(T &&t)  { cout << t << "\n"; }

void printarr(ll arr[], ll n) { f(i, 0, n) cout << arr[i] << " "; cout << "\n"; }

template<typename T>
void printvec(vector<T> v) { for (const auto &el : v) cout << el << " "; cout << "\n"; }

template<typename T>
ll sumvec(const vector<T> &v) { return accumulate(v.begin(), v.end(), 0LL); }

// Fixed-size integers
using u8 = uint8_t;
using i8 = int8_t;
using u16 = uint16_t;
using i16 = int16_t;
using u32 = uint32_t;
using i32 = int32_t;
using u64 = uint64_t;
using i64 = int64_t;
using usize = std::size_t;
using isize = std::ptrdiff_t;

// Optimization Pragmas (Compiler-specific)
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

// Utility Functions
bool sorta(const pair<int, int> &a, const pair<int, int> &b) { return (a.second < b.second); }
bool sortd(const pair<int, int> &a, const pair<int, int> &b) { return (a.second > b.second); }

// Conversion and Mathematical Functions
string decToBinary(int n) {
    string s = "";
    while (n > 0) {
        s = to_string(n % 2) + s;
        n /= 2;
    }
    return s;
}

ll binaryToDecimal(const string &n) {
    ll dec_value = 0;
    int base = 1;
    for (int i = n.size() - 1; i >= 0; --i) {
        if (n[i] == '1') dec_value += base;
        base *= 2;
    }
    return dec_value;
}

bool isPrime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

bool isPerfectSquare(ll x) {
    if (x < 0) return false;
    ll sr = sqrt(x);
    return sr * sr == x;
}

// Constants
const int INF = 1e9 + 7;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

// Debugging
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << (x) << '\n'
#else
#define debug(x)
#endif

void _print(int t) { cerr << t; }
void _print(ll t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(const string &t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(const pair<T, V> &p) {
    cerr << "{";
    _print(p.F);
    cerr << ",";
    _print(p.S);
    cerr << "}";
}

template <class T>
void _print(const vector<T> &v) {
    cerr << "[ ";
    for (const T &i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template <class T>
void _print(const set<T> &v) {
    cerr << "[ ";
    for (const T &i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template <class T>
void _print(const multiset<T> &v) {
    cerr << "[ ";
    for (const T &i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template <class T, class V>
void _print(const map<T, V> &v) {
    cerr << "[ ";
    for (const auto &i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

// Mathematical Functions
template <typename T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

template <typename T>
T lcm(T a, T b) { return (a / gcd(a, b)) * b; }

template <typename T>
T mod_exp(T base, T exp, T mod) {
    T result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

template <typename T>
T mod_inverse(T a, T mod) {
    T m0 = mod, x0 = 0, x1 = 1;
    if (mod == 1) return 0;
    while (a > 1) {
        T q = a / mod;
        T t = mod;
        mod = a % mod;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}

vector<int> prime_factors(int n) {
    vector<int> factors;
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 2) factors.push_back(n);
    return factors;
}

// Square root function with integer return type
template <typename T>
T integer_sqrt(T n) {
    T lo = 0, hi = n;
    while (lo <= hi) {
        T mid = lo + (hi - lo) / 2;
        if (mid * mid == n) return mid;
        if (mid * mid < n) lo = mid + 1;
        else hi = mid - 1;
    }
    return hi; // or lo, depending on rounding
}

// Combinatorial Functions
template <typename T>
T comb(T n, T k) {
    if (k > n) return 0;
    T res = 1;
    for (T i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

template <typename T>
T perm(T n, T k) {
    if (k > n) return 0;
    T res = 1;
    for (T i = 0; i < k; ++i) {
        res *= (n - i);
    }
    return res;
}

// Random Number Generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Fast I/O
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// Macros for bitwise operations
#define CHECK_BIT(n, pos) (((n) & (1 << (pos))) != 0) // Check if the bit at position 'pos' is set
#define SET_BIT(n, pos) ((n) | (1 << (pos))) // Set the bit at position 'pos'
#define CLEAR_BIT(n, pos) ((n) & ~(1 << (pos))) // Clear the bit at position 'pos'
#define TOGGLE_BIT(n, pos) ((n) ^ (1 << (pos))) // Toggle the bit at position 'pos'
#define COUNT_SET_BITS(n) __builtin_popcount(n) // Count the number of set bits
#define RIGHTMOST_SET_BIT(n) ((n) & (-(n))) // Find the rightmost set bit
#define IS_POWER_OF_TWO(n) (((n) > 0) && (((n) & ((n) - 1)) == 0)) // Check if 'n' is a power of two
#define SWAP_BITS(a, b) do { if ((a) != (b)) { (a) ^= (b); (b) ^= (a); (a) ^= (b); } } while (0) // Swap two numbers using XOR

// Main function
int main() {
    fast_io; // Fast I/O setup

    int t;
    cin >> t; // Number of test cases

    while (t--) {
        //Code....
        int n;
        cin >> n; // Number of elements

        vector<int> numbers(n);
        cin >> numbers; // Read the numbers

        ll sum = accumulate(numbers.begin(), numbers.end(), 0LL);
        double average = static_cast<double>(sum) / n;

        cout << "Sum: " << sum << "\n";
        cout << "Average: " << average << "\n";

        debug(sum);      // Debugging output for sum
        debug(average);  // Debugging output for average
    }

    return 0;
}
