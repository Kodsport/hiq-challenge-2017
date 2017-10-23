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
	int limit, events;
	cin >> limit >> events;
	int count = 0;
	int res = 0;
	rep(i,0,events) {
		string ev;
		int p;
		cin >> ev >> p;
		if (ev == "enter") {
			if (count + p > limit) {
				res++;
			} else {
				count += p;
			}
		}
		else {
			assert(ev == "leave");
			count -= p;
		}
	}
	cout << res << endl;
	exit(0);
}
