#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

using Graph = vector<vector<ll>>;

int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    vector<pair<ll, ll>> AB(M);
    for(pair<ll, ll> &ab : AB) {
        cin >> ab.first >> ab.second;
        ab.first--;
        ab.second--;
    }
    vector<pair<ll, ll>> CD(K);
    for(pair<ll, ll> &cd : CD) {
        cin >> cd.first >> cd.second;
        cd.first--;
        cd.second--;
    }

    dsu d(110000);
    for(const pair<ll, ll> &ab : AB) {
        d.merge(ab.first, ab.second);
    }
    vector<ll> ans(110000, 0);
    for(ll i = 0; i < N; i++) {
        ans.at(i) = d.size(i) - 1;
    }

    Graph friendGraph(N);
    for(const pair<ll, ll> &ab : AB) {
        ans.at(ab.first)--;
        ans.at(ab.second)--;
        friendGraph[ab.first].push_back(ab.second);
        friendGraph[ab.second].push_back(ab.first);
    }

    for(const pair<ll, ll> &cd : CD) {
        if(!count(friendGraph.at(cd.first).begin(), friendGraph.at(cd.first).end(), cd.second) && d.same(cd.first, cd.second)) {
            ans.at(cd.first)--;
            ans.at(cd.second)--;
        }
    }

    for(ll i = 0; i < N; i++) {
        cout << ans.at(i) << " ";
    }

    cout << endl;

    return 0;
}