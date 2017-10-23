#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

    int N, S, T;
    cin >> N >> S >> T;
    vi notSeen;
    rep(i,0,N) if (i != S) notSeen.push_back(i);
    vi dist(N, N + 1);
    vector<char> type(N);
    vector<vi> lists(N);
    rep(i,0,N) {
        cin >> type[i];
        int m;
        cin >> m;
        rep(j,0,m) {
            int x;
            cin >> x;
            lists[i].push_back(x);
        }
    }
    dist[S] = 0;
    queue<int> Q;
    Q.push(S);
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        int nd = dist[cur] + 1;
        if (type[cur] == 'N') {
            trav(it, lists[cur]) {
                if (dist[it] == N + 1) {
                    dist[it] = nd;
                    Q.push(it);
                }
            }
        } else if (type[cur] == 'C') {
            set<int> nlist(all(lists[cur]));
            vi nNotSeen;
            trav(it, notSeen) {
                if (nlist.count(it)) {
                    nNotSeen.push_back(it);
                    continue;
                }
                if (dist[it] == N + 1) {
                    dist[it] = nd;
                    Q.push(it);
                }
            }
            notSeen = nNotSeen;
        } else {
            cout << type[cur] << endl;
            assert(false && "Bad type");
        }
    }
    if (dist[T] == N + 1) {
        cout << "impossible" << endl;
    } else cout << dist[T] << endl;
}
