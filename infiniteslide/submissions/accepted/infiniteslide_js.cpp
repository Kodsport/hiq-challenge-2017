#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define Min(...) min({__VA_ARGS__})
#define Max(...) max({__VA_ARGS__})
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
static inline ll sgn(ll x) { return (x>0)-(x<0); }
static inline bool vowel(char c) { c = (char)tolower(c); return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'y'; }
static inline vi rvi(int N) { vi res(N); rep(i,0,N) cin >> res[i]; return res; }
static inline int ri() { int N; cin >> N; return N; }
static inline void pvi(const vi& r) { trav(it,r) cout << it << " "; cout << endl; }
template<class S, class T> static inline void smax(S& s, const T& t) { if (t > s) s = t; }
template<class S, class T> static inline void smin(S& s, const T& t) { if (t < s) s = t; }
template<class S> static inline void in(S& s) { cin >> s; }
template<class S> static inline void ut(const S& s) { cout << s << " "; }
static inline void nl() { cout << endl; }

double w;

double eval(double x) {
	return sqrt( pow(sin(x + 2*w) - sin(x + w), 2) + pow(cos(x + 2*w) - (cos(x + w) + 1), 2) + x*x );
}

double gss(double a, double b, double (*f)(double)) {
	double r = (sqrt(5)-1)/2;
	double x1 = b - r*(b-a), x2 = a + r*(b-a);
	double f1 = f(x1), f2 = f(x2);
	rep(i,0,2000) {
		if (f1 < f2) { //change to > to find maximum
			b = x2; x2 = x1; f2 = f1;
			x1 = b - r*(b-a); f1 = f(x1);
		} else {
			a = x1; x1 = x2; f1 = f2;
			x2 = a + r*(b-a); f2 = f(x2);
		}
	}
	return a;
}

signed main() {
	cin.sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin >> w;
	double res = Min(
			eval(gss(-2*M_PI, -M_PI, eval)),
			eval(gss(-M_PI, 0, eval)),
			eval(gss(0, M_PI, eval)),
			eval(gss(M_PI, 2*M_PI, eval)));
	cout << setprecision(15) << fixed << res << endl;
}
