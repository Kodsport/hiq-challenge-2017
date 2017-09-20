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
	vector<ll> amt(N);
	rep(i,0,N) cin >> amt[i];
	const ll mod = 1000000007;
	ll p2 = 1, res = 0;
	rep(i,0,N) {
		ll v = amt[i];
		if (v & 1) {
			res += p2;
			res %= mod;
		}
		v >>= 1;
		if (v && i+1 < N) {
			ll& w = amt[i+1];
			w += v;
			if (w & 1) w--;
		}
		p2 = p2 * 2 % mod;
	}
	assert(0 <= res && res < mod);
	cout << res << endl;
	exit(0);
}
