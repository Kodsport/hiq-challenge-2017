#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N, strsz;
const char* thes;
map<pii, int> mem;
vector<string> syll;

bool match(int& ind, const string& str) {
	while (thes[ind] == ' ') ind++;
	trav(c, str) {
		if (thes[ind] != c) return false;
		ind++;
	}
	return true;
}

bool haiku(int ind, int left) {
	if (left == 0) return ind == strsz;
	int& out = mem[pii(ind, left)];
	if (out) return out - 1;
	rep(i,0,N) {
		int ind2 = ind;
		if (match(ind2, syll[i]) && haiku(ind2, left - 1)) {
			out = 2;
			return 1;
		}
	}
	out = 1;
	return 0;
}

void read(string& s) {
	getline(cin, s);
	assert(!s.empty());
	assert(s[0] != ' ');
	assert(s[sz(s)-1] != ' ');
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	cin >> N;
	syll.resize(N);
	rep(i,0,N) cin >> syll[i];
	assert(cin.get() == '\n');
	string a, b, c;
	read(a);
	read(b);
	read(c);
	thes = a.c_str(); strsz = sz(a); mem.clear(); bool A = haiku(0, 5);
	thes = b.c_str(); strsz = sz(b); mem.clear(); bool B = haiku(0, 7);
	thes = c.c_str(); strsz = sz(c); mem.clear(); bool C = haiku(0, 5) || true;
	if (A && B && C) cout << "haiku" << endl;
	else cout << "come back next year" << endl;
	exit(0);
}
