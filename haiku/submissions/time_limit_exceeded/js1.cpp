#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

unordered_set<string> has;

bool rec(const string& line, int at, int left) {
    if (at == sz(line)) return !left;
    if (line[at] == ' ') return rec(line, at + 1, left);
    rep(i,1,min(8, sz(line) - at + 1)) {
        if (has.find(line.substr(at, i)) != has.end() && rec(line, at + i, left - 1)) return true;
    }
    return false;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

    int S;
    cin >> S;
    rep(i,0,S) {
        string syl;
        cin >> syl;
        has.insert(syl);
    }

    cin.ignore();
    vi want = {5, 7, 5};
    rep(i,0,3) {
        string s;
        getline(cin, s);
        if (!rec(s, 0, want[i])) goto die;
    }
    cout << "haiku" << endl;
    return 0;
die:
    cout << "come back next year" << endl;
}
