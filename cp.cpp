#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define vec vector<int>
#define pii pair<int,int>
#define mii map<int,int>
#define vp vector<pair<int,int>>
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)
#define py cout << "YES\n"
#define pn cout << "NO\n"
#define in(n) int n;cin>>n
#define in2(a,b) int a,b;cin>>a>>b
#define in3(a,b,c) int a,b,c;cin>>a>>b>>c
#define pb(x) push_back(x)
#define sortv(x) sort(x.begin(), x.end())
#define sortr(x) sort(x.rbegin(), x.rend())
#define loop(s,i,n) for(int i=s;i<n;i++)
#define loopr(s,i,n) for(int i=n-1;i>=s;i--)
#define loopa(u,x) for(auto u:x)
#define F first
#define S second
#define endl '\n'
#define mem(a,b) memset(a, b, sizeof(a) )
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
//debug
template<typename F,typename S>ostream&operator<<(ostream&os,const pair<F,S>&p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>ostream&operator<<(ostream&os,const vector<T>&v){os<<"{";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"}";}
template<typename T>ostream&operator<<(ostream&os,const set<T>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<",";os<<*it;}return os<<"]";}
template<typename T>ostream&operator<<(ostream&os,const multiset<T>&v) {os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"]";}
template<typename F,typename S>ostream&operator<<(ostream&os,const map<F,S>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<it->first<<" = "<<it->second;}return os<<"]";}
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu(){cerr << endl;}
template<typename T>void faltu(T a[],int n){for(int i=0;i<n;++i)cerr<<a[i]<<' ';cerr<<endl;}
template<typename T,typename...heinto>void faltu(T arg,const heinto&...rest){cerr<<arg<<' ';faltu(rest...);}
//gcd,lcm
int gcd ( int a, int b ) { return __gcd ( a, b ); }
int lcm ( int a, int b ) { return a * ( b / gcd ( a, b ) ); } 
// Input/output helpers
template <typename T> void read(vector<T>& v) { for (auto& x : v) cin >> x; }
template <typename T> void print(const vector<T>& v) { for (const auto& x : v) cout << x << ' '; cout << '\n'; }

//mod
#define MOD 1000000007
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }

const int mx = 1e5+123;

void solve()
{

}

int32_t main()
{
    fast_io;
    int t = 1;
    cin >> t;  
    while (t--) solve();
    return 0;
}

////////////////////////
bitset<mx> isPrime;
vector<int> primes;

void primeGen(int n) {
    for (int i = 3; i <= n; i += 2) isPrime[i] = 1;

    int sq = sqrt(n);
    for (int i = 3; i <= sq; i += 2) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    primes.push_back(2);
    for (int i = 3; i <= n; i += 2) {
        if (isPrime[i] == 1) {
            primes.push_back(i);
        }
    }
}

////////////////
bool isPrime_(ll n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

/////////////
ll numberOfDivisors(ll n) {
    ll ans = 1;
    for (auto u : primes) {
        if (1ll * u * u > n) break;
        if (n % u == 0) {
            ll a = 0;
            while (n % u == 0) {
                a++;
                n /= u;
            }
            ans *= (a + 1);
        }
    }
    if (n != 1) {
        ans *= 2;
    }
    return ans;
}

// Data Structures
void stl_containers_demo() {
    // Vectors
    vector<int> v = {1, 2, 3};
    v.push_back(4);            // Add element at the end
    v.pop_back();              // Remove last element
    sort(v.begin(), v.end());  // Sort
    reverse(v.begin(), v.end()); // Reverse
    cout << v.front() << " " << v.back() << "\n"; // Access first/last element

    // Sets
    set<int> s = {3, 1, 4};
    s.insert(2);
    s.erase(3);
    cout << *s.begin() << "\n"; // Smallest element

    // Multiset (allows duplicates)
    multiset<int> ms = {1, 1, 2};
    ms.erase(ms.find(1)); // Erases one occurrence of 1

    // Unordered Sets
    unordered_set<int> us = {1, 2, 3};

    // Maps
    map<int, string> m;
    m[1] = "one";
    m[2] = "two";
    for (auto& p : m) cout << p.first << ": " << p.second << "\n";

    // Multimap
    multimap<int, string> mm;
    mm.insert({1, "a"});
    mm.insert({1, "b"});

    // Unordered Maps
    unordered_map<string, int> um;
    um["apple"] = 10;

    // Stacks
    stack<int> st;
    st.push(1);
    st.push(2);
    cout << st.top() << "\n"; // Top element
    st.pop();

    // Queues
    queue<int> q;
    q.push(1);
    q.push(2);
    cout << q.front() << "\n"; // First element
    q.pop();

    // Priority Queue (Max-Heap)
    priority_queue<int> pq;
    pq.push(3);
    pq.push(1);
    pq.push(2);
    cout << pq.top() << "\n"; // Largest element
    pq.pop();

    // Priority Queue (Min-Heap)
    priority_queue<int, vector<int>, greater<int>> min_pq;
    min_pq.push(3);
    min_pq.push(1);
    min_pq.push(2);
    cout << min_pq.top() << "\n"; // Smallest element
}

// Algorithms
void stl_algorithms_demo() {
    vector<int> v = {1, 2, 3, 4, 5};

    // Searching
    cout << binary_search(v.begin(), v.end(), 3) << "\n"; // 1 (found)

    // Min/Max
    cout << *min_element(v.begin(), v.end()) << "\n"; // 1
    cout << *max_element(v.begin(), v.end()) << "\n"; // 5

    // Sum
    cout << accumulate(v.begin(), v.end(), 0) << "\n"; // 15

    // Count occurrences
    cout << count(v.begin(), v.end(), 3) << "\n"; // 1

    // Find element
    auto it = find(v.begin(), v.end(), 4);
    if (it != v.end()) cout << *it << "\n";

    // Remove duplicates
    v = {1, 1, 2, 2, 3};
    v.erase(unique(v.begin(), v.end()), v.end()); // {1, 2, 3}

    // Permutations
    sort(v.begin(), v.end());
    do {
        for (auto x : v) cout << x << " ";
        cout << "\n";
    } while (next_permutation(v.begin(), v.end()));
}

// String Operations
void stl_string_demo() {
    string s = "Hello";

    // Append and insert
    s.append(" World");
    s.insert(5, ","); // s: "Hello, World"
    cout << s << "\n";

    // Erase and replace
    s.erase(5, 1);  // s: "Hello World"
    s.replace(6, 5, "Universe");  // s: "Hello Universe"
    cout << s << "\n";

    // Access
    cout << s[0] << " " << s.at(6) << "\n";  // Output: H U

    // Find and substr
    cout << s.find("Universe") << "\n";  // Output: 6
    cout << s.substr(0, 5) << "\n";      // Output: Hello

    // Sort and reverse
    sort(s.begin(), s.end());
    cout << s << "\n";  // Sorted
    reverse(s.begin(), s.end());
    cout << s << "\n";  // Reversed

    // Conversion
    string num = "123";
    int x = stoi(num);  // Convert to integer
    cout << x + 1 << "\n";  // 124
    string back = to_string(x);
    cout << back + "0" << "\n"; // "1230"
}

// Utility Functions
void stl_utilities_demo() {
    // Pairs
    // Pair
    pair<int, string> p1 = {1, "One"};
    pair<int, string> p2 = {2, "Two"};

    // Pair operations
    cout << p1.first << " " << p1.second << "\n"; // 1 One
    swap(p1, p2);
    cout << p1.first << " " << p1.second << "\n"; // 2 Two

    // Nested pairs
    pair<int, pair<int, string>> nested_p = {1, {2, "Nested"}};
    cout << nested_p.first << " " << nested_p.second.first << " " << nested_p.second.second << "\n";

    // Map
    map<int, string> m;
    m[1] = "One";
    m[2] = "Two";
    m[3] = "Three";

    // Iteration over map
    for (auto& [key, value] : m) cout << key << ": " << value << "\n";

    // Map operations
    if (m.find(2) != m.end()) cout << "Key 2 found with value: " << m[2] << "\n";
    m.erase(2);  // Remove key 2
    m[4] = "Four";

    // Access with default value
    cout << m[5] << "\n"; // Creates key 5 with default value ""

    // Lower and upper bounds in map
    auto lb = m.lower_bound(3); // First element >= 3
    auto ub = m.upper_bound(3); // First element > 3
    if (lb != m.end()) cout << "Lower bound: " << lb->first << "\n";
    if (ub != m.end()) cout << "Upper bound: " << ub->first << "\n";

    // Unordered Map
    unordered_map<string, int> um = {{"apple", 10}, {"banana", 20}};
    for (auto& [key, value] : um) cout << key << ": " << value << "\n";

    // Multimap
    multimap<int, string> mm;
    mm.insert({1, "One"});
    mm.insert({1, "Another One"});
    mm.insert({2, "Two"});
    for (auto& [key, value] : mm) cout << key << ": " << value << "\n";

    // Set
    set<int> s = {3, 1, 4, 1, 2};
    s.insert(5);
    s.erase(3);
    for (int x : s) cout << x << " "; // Sorted unique values: 1 2 4 5
    cout << "\n";

    // Check presence in set
    if (s.find(4) != s.end()) cout << "4 found in set\n";

    // Lower and upper bounds in set
    auto s_lb = s.lower_bound(2);
    auto s_ub = s.upper_bound(2);
    if (s_lb != s.end()) cout << "Set lower bound: " << *s_lb << "\n";
    if (s_ub != s.end()) cout << "Set upper bound: " << *s_ub << "\n";

    // Multiset (allows duplicates)
    multiset<int> ms = {1, 1, 2, 2, 3};
    ms.insert(2);
    cout << ms.count(2) << "\n"; // Count occurrences of 2: 3

    // Erase one occurrence in multiset
    ms.erase(ms.find(2));
    for (int x : ms) cout << x << " "; // 1 1 2 2 3
    cout << "\n";

    // Unordered Set
    unordered_set<int> us = {1, 2, 3, 4};
    us.erase(3);
    us.insert(5);
    for (int x : us) cout << x << " "; // Unordered elements
    cout << "\n";

    // Multimap range of equal keys
    auto range = mm.equal_range(1);
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->first << ": " << it->second << "\n";
    }
    // Tuples
    tuple<int, string, double> t = {1, "hello", 3.14};
    cout << get<1>(t) << "\n"; // "hello"

    // Lambda functions
    auto add = [](int a, int b) { return a + b; };
    cout << add(3, 4) << "\n"; // 7
}
