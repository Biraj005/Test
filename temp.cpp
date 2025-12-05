#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define sz(x) (int)(x).size()
#define endl "\n"
const ll MOD = 1000000007;

void printVector(const vi &v) {
    for (int x : v) cout << x << " ";
    cout << endl;
}

vi inputVector(int n) {
    vi v(n);
    for (int &x : v) cin >> x;
    return v;
}
/*****************Solve Function******************/
void Solve() {
   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif

    int t;
    cin >> t;
    while (t--) {
        Solve();
    }
    return 0;
}