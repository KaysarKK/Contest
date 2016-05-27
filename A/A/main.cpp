#include <iostream>
#include <algorithm>

using namespace std;



int n;
long long arr[20];
long long stepen[10];

void func(long long x) {
    
    stepen[0] = 1;

    for(int i = 1; i <= n + 1; i++)
        stepen[i] = stepen[i - 1] * x;
}
int main() {
    
    long long first, second, time;
    
    cin >> n >> time;
    
    arr[0] = time;
    
    for(int i = 1; i < n; i++) {
        cin >> arr[i];
        time = min(time, arr[i]);
    }
    
    func(time);
    
    if(n == 1) {
        if(arr[0] % 2)
        cout << arr[0] << "/2";
        else
            cout << arr[0] / 2 << "/1";
        return 0;
    }
        if(n == 2) {
            long long s1 = arr[0] + arr[1];
            first = 3 * s1 * stepen[2] - 4 * stepen[3];
            long long s2 = arr[0] * arr[1];
            second = s2 * 6;
        }
        else
            if(n == 3) {
                long long s1 = arr[0] + arr[1] + arr[2];
                long long s2 = arr[0] * arr[1] + arr[1] * arr[2] + arr[0] * arr[2];
                long long s3 = arr[0] * arr[1] * arr[2];
                first = stepen[4] * 18 - s1 * stepen[3] * 16 + s2 * stepen[2] * 12;
                second = s3 * 24;
            }
            else
                if (n == 4) {
                    long long s1 = arr[0] + arr[1] + arr[2] + arr[3];
                    long long s2 = arr[0] * arr[1] + arr[0] * arr[2] + arr[0] * arr[3] + arr[1] * arr[2] + arr[1] * arr[3] + arr[2] * arr[3];
                    long long s3 = arr[0] * arr[1] * arr[2] + arr[0] * arr[1] * arr[3] + arr[0] * arr[2] * arr[3] + arr[1] * arr[2] * arr[3];
                    long long s4 = arr[0] * arr[1] * arr[2] * arr[3];
                    first = stepen[5] * (-96) + s1 * stepen[4] * 90 - s2 * stepen[3] * 80 + s3 * stepen[2] * 60;
                    second = s4 * 120;
                }
    else {
        long long s1 = arr[0] + arr[1] + arr[2] + arr[3] + arr[4];
        long long s2 = arr[0] * arr[1] + arr[0] * arr[2] + arr[0] * arr[3] + arr[1] * arr[2] + arr[1] * arr[3] + arr[2] * arr[3] + arr[0] * arr[4] + arr[1] * arr[4] + arr[2] * arr[4] + arr[3] * arr[4];
        long long s3 = arr[0] * arr[1] * arr[2] + arr[0] * arr[1] * arr[3] + arr[0] * arr[1] * arr[4] + arr[0] * arr[2] * arr[3] + arr[0] * arr[2] * arr[4] + arr[1] * arr[2] * arr[3] + arr[1] * arr[2] * arr[4] + arr[0] * arr[3] * arr[4] + arr[1] * arr[3] * arr[4] + arr[2] * arr[3] * arr[4];
        long long s4 = arr[0] * arr[1] * arr[2] * arr[3] + arr[0] * arr[1] * arr[2] * arr[4] + arr[0] * arr[1] * arr[3] * arr[4] + arr[0] * arr[2] * arr[3] * arr[4] + arr[1] * arr[2] * arr[3] * arr[4];
        long long s5 = arr[0] * arr[1] * arr[2] * arr[3] * arr[4];
        first = (stepen[6]) * 600 - (s1 * stepen[5]) * 576 + (s2 * stepen[4]) * 540 - (s3 * stepen[3]) * 480 + (s4 * stepen[2]) * 360;
        second = s5 * 720;
    }
    long long g = __gcd(first, second);
    cout << first / g << "/" << second / g;
    
    return 0;
}

