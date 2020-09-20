/*
https://cses.fi/problemset/task/1193/
*/

#include <bits/stdc++.h>
using namespace std;
/*
#pragma GCC optimize("Ofast,03")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
*/
#define    boost        ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define    nl           "\n"
#define    ll           long long
#define    pb           push_back
#define    mpr          make_pair
#define    fr(i,a,n)    for(ll i=a;i<n;++i)
#define    fr0(i,n)     for(ll i=0;i<n;++i)
#define    pii          pair<int, int>
#define    FO           find_by_order
#define    OK           order_of_key
#define    mem(a)       memset(a,0,sizeof(a))
#define    F            first
#define    S            second
#define    sp           " "
#define    vi           vector<int>
#define    vii          vector<pair<int, int>>
#define    all(a)       a.begin(), a.end()

/*
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree <
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update >
set_t;
*/

void fio()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}


template<typename T> void TIME(T start, T end)
{
#ifndef ONLINE_JUDGE
	double time_taken =  chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	cout << "\nExecuted in: " << fixed
	     << time_taken << setprecision(9);
	cout << " sec";
#endif
}

///----------------------------- | Debugging Starts | --------------------------------------///

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...)  cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

///----------------------------- | Debugging Ends | --------------------------------------///


///----------------------------- | FUNCTIONS | --------------------------------------///

const int N = 1e3 + 5;

int n, m;
bool check(int i, int j)
{
	return i >= 0 && i < n && j >= 0 && j < m;
}

int X_move[4] = {1, -1, 0, 0};
int Y_move[4] = {0, 0, 1, -1};

string adj[N];
bool visited[N][N];

bool ans = false;
char parent[N][N];
int i_B, j_B;

void bfs(int i, int j)
{
	queue<pii> q;
	q.push({i, j});

	while (!q.empty())
	{
		pii p = q.front();
		q.pop();
		i = p.first; j = p.second;

		if (adj[i][j] == 'B')
		{
			i_B = i; j_B = j;
			ans = true;
			return;
		}
		if (check(i + 1, j) && (adj[i + 1][j] == '.' || adj[i + 1][j] == 'B') && !visited[i + 1][j])
		{
			visited[i + 1][j] = true;
			q.push({i + 1, j});
			parent[i + 1][j] = 'D';
		}
		if (check(i - 1, j) && (adj[i - 1][j] == '.' || adj[i - 1][j] == 'B') && !visited[i - 1][j])
		{
			visited[i - 1][j] = true;
			q.push({i - 1, j});
			parent[i - 1][j] = 'U';
		}
		if (check(i, j + 1) && (adj[i][j + 1] == '.' || adj[i][j + 1] == 'B') && !visited[i][j + 1])
		{
			visited[i][j + 1] = true;
			q.push({i, j + 1});
			parent[i][j + 1] = 'R';
		}
		if (check(i, j - 1) && (adj[i][j - 1] == '.' || adj[i][j - 1] == 'B') && !visited[i][j - 1])
		{
			visited[i][j - 1] = true;
			q.push({i, j - 1});
			parent[i][j - 1] = 'L';
		}
	}
}

// left shift << multiply by 2
// right shift >> divide by 2

///----------------------------- | START FROM HERE | --------------------------------------///

//#define int long long //change int main to int32_t main

const  int mod = 1e6 + 7;


void solve()
{
	cin >> n >> m;
	fr0(i, n) cin >> adj[i];
	fr0(i, n) fr0(j, m)
	{
		if (adj[i][j] == 'A')
		{
			parent[i][j] = '0';
			bfs(i, j);
			if (ans) {
				cout << "YES\n";
				string final;
				while (parent[i_B][j_B] != '0') {
					char c = parent[i_B][j_B];
					final.pb(c);
					if (c == 'R') j_B--;
					if (c == 'L') j_B++;
					if (c == 'D') i_B--;
					if (c == 'U') i_B++;
				}
				reverse(all(final));
				cout << final.size() << nl << final;
			}
			else {
				cout << "NO\n";
			}
			return;
		}
	}
}


int32_t main()
{
	auto start = chrono::high_resolution_clock::now();
	boost;
	fio();
	int t;
	t = 1;
	//cin >> t;
	while (t--) solve();
	auto end = chrono::high_resolution_clock::now();
	TIME(start, end);
	return 0;
}