#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll inf = 3000000000;
ll n, c, p, t, sum[105];
ll check(ll mid) {
    ll ans = 0, need = 0;
    for (int i=1; i<=n; i++) {
        ll tmp = sum[i], get = 0, need_time = 0;
        if (tmp > mid) return -1;
        tmp += need;
        if (tmp > mid) {
            need_time = (tmp + mid - 1) / mid * p;
            get = mid;
            need = tmp - mid;
        } else {
            need_time = (tmp > 0) ? p : 0;
            get = tmp;
            need = 0;
        }
        ans = max(ans, get);
        t -= need_time;
        if (t < 0) break;
    }
    return (t < 0) ? -1 : ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> c >> p >> t;
    for (int i=1; i<=n; i++) {
        ll x; cin >> x;
        sum[i] = sum[i-1] + x;
    }
    ll ans = 0;
    ll l = 0, r = inf;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        ll check_ans = check(mid);
        if (check_ans != -1) {
            ans = check_ans;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
