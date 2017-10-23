#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef double d;
d W, best = 1e100;
const d maxder = 25;

d f(d t) {
	d dy = sin(t + W) - sin(t + 2*W);
	d dx = cos(t + W) - cos(t + 2*W) + 1;
	d dz = t;
	return dx*dx + dy*dy + dz*dz;
}

void findmin(d lo, d flo, d hi, d fhi) {
	assert(lo < hi);
	d dif = hi - lo;
	assert(abs(flo - fhi) <= maxder * dif);
	if (min(fhi, flo) - maxder * dif > best) return;
    if (hi - lo < 1e-8) return;
	d mid = (lo + hi) / 2;
	if (lo == mid || mid == hi) return;
	d fmid = f(mid);
	best = min(best, fmid);
	findmin(lo, flo, mid, fmid);
	findmin(mid, fmid, hi, fhi);
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	cin >> W;
	findmin(-5, f(-5), 5, f(5));
	cout << setprecision(10) << fixed << sqrt(best) << endl;
	exit(0);
}
