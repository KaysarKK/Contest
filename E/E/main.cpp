#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;


int main() {
    int n, x, y, z;
    long long stepen[50001][3];
    cin >> n;
    cin >> x >> y >> z;
    long long a[3];
    a[0] = -x;
    a[1] = -y;
    a[2] = -z;
    for (int i = 1; i <= n; i++) {
        stepen[i][1] = long(i * i);;
        stepen[i][2] = long(i * i * i);
        a[0] += i;
        a[1] += long(i * i);
        a[2] += long(i * i * i);
    }
    for (int i = 1; i <= n - 2; i++) {
        for (int j = i + 1; j <= n - 1; j++) {
            long long k = a[0] - (long)i - (long)j;
            if (k <= j)
                break;
            if (stepen[i][1] + stepen[j][1] + stepen[k][1] == a[1] && stepen[i][2] + stepen[j][2] + stepen[k][2] == a[2])
            {
                cout << i << " " << j << " " << k;
                exit(0);
            }
        }
    }
    return 0;
}
