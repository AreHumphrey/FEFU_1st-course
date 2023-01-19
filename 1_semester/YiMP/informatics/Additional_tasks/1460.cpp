#include <iostream>

using namespace std;

int main()
{
    int Element, N, SdvigPosledov, Bufer, i, o;
    long long int K;
    cin >> N;
    int a[N];
    for (i = N-1; i >= 0; i--){
        cin >> a[i];
    }
    cin >> K;
    if (K >= 0){
        K %= N;
        for (i = K-1; i >= K/2; i--){
            Bufer = a[i];
            a[i] = a[K-1-i];
            a[K-1-i] = Bufer;
        }
        o = 0;
        for (i = K; i <= (K+(N-K)/2-1); i++){
            Bufer = a[i];
            a[i] = a[N-1-o];
            a[N-1-o] = Bufer;
            o++;
        }
    } else {
        K = -K;
        K %= N;
        o = 0;
        for (i = N-1; i >= N-K+K/2; i--){
            Bufer = a[i];
            a[i] = a[N-K+o];
            a[N-K+o] = Bufer;
            o++;
        }
        for (i = 0; i <= (N-K)/2-1; i++){
            Bufer = a[i];
            a[i] = a[(N-K)-i-1];
            a[(N-K)-i-1] = Bufer;
        }
    }

    for (int i = 0; i < N; i++){
        cout << a[i] << " ";
    }
    return 0;
}
