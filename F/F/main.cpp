#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;
int main() {
    int n, m;
    int a[1000001], b[1000001];
    cin  >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort (a, a + n);
    sort (b, b + m);
    reverse(b, b + m);
    int i = 0;
    long long res = 0;
    while (i  < min(n, m)) {
        if (b[i] > a[i]) {
            res += (long)(b[i] - a[i]);
        }
        i++;
    }
    cout << res;
    return 0;
}
