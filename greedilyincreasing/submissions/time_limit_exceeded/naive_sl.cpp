#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;
	vi a(N);
	rep(i,0,N) cin >> a[i];
	vi r = {a[0]};
	bool success = true;
	while (success) {
		success = false;
		int last = r.back();
		rep(i,0,N) if (a[i] > last) {
			r.push_back(a[i]);
			success = true;
			break;
		}
	}
	cout << sz(r) << endl;
	trav(x, r) cout << x << ' ';
	cout << endl;
	exit(0);
}
