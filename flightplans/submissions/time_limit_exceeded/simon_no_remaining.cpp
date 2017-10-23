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
	int N, s, t;
	cin >> N >> s >> t;
	vector<set<int>> ed(N);
	vector<char> type(N);
	rep(i,0,N) {
		int m;
		cin >> type[i] >> m;
		set<int> s;
		rep(j,0,m) {
			int a;
			cin >> a;
			s.insert(a);
		}
		ed[i] = move(s);
	}

	vi dist(N, -1);
	queue<int> q;
	q.push(s);
	dist[s] = 0;
	vector<bool> marked(N);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		int d = dist[x];
		if (type[x] == 'N') {
			trav(y, ed[x]) if (dist[y] == -1) {
				dist[y] = d + 1;
				q.push(y);
			}
		} else {
			vi er;
			trav(y, ed[x]) marked[y] = 1;
			rep(y,0,N) if (!marked[y]) {
				dist[y] = d + 1;
				er.push_back(y);
				q.push(y);
			}
			trav(y, ed[x]) marked[y] = 0;
		}
	}

	if (dist[t] == -1)
		cout << "impossible" << endl;
	else
		cout << dist[t] << endl;
	exit(0);
}
