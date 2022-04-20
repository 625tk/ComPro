#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define eb emplace_back

const long double EPS = 1e-64;

int main(void) {
    int n, k;
    int ans = 0;
    vector<int> x, y;

    cin >> n >> k;
    x.resize(n);
    y.resize(n);

    rep(i, n) cin >> x[i] >> y[i];

    if (k == 1) {
        cout << "Infinity" << endl;
        return 0;
    }


    rep(i, n)
        for (int j = i + 1; j < n; j++) {
            if (x[i] != x[j]) {
                long long dy = y[i] - y[j];
                long long dx = x[i] - x[j];
                long long bdx = y[i] * dx - x[i] * dy;

                int o = 0;
                rep(t, n) {
                    if (abs(x[t] * dy + bdx - y[t] * dx) < EPS) {
                        if (t < i || (t < j && t != i)) {
                            o = 0;
                            break;
                        }
                        o++;
                    }
                }
                // cout << "y = " << dy / (long double) dx << "x + " << bdx / (long double) dx << endl;
                // cout << o << " " << dy / (long double) dx << " , " << bdx / (long double) dx << "( " << x[i] << " , " << y[i] << " )-( " << x[j] << " , " << y[j] << " )" << endl;
                if (k <= o) {
                    ans++;
                }
            }
        }

    vector<int> x2;
    x2.resize(n);
    rep(i, n)x2[i] = x[i];

    sort(x2.begin(), x2.end());

    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (x2[i - 1] == x2[i]) {
            cnt++;
        } else {
            if (k <= cnt)ans++;
            cnt = 1;
        }
    }
    if (k <= cnt)ans++;

    cout << ans << endl;
    return 0;
}
