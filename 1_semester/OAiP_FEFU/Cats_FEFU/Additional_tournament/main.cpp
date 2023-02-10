#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

int SortArr(vector<long long> & v, long long start, long long end){
    long long m = start, p;
    if(end-start < 1) return 0;

    long long X = v[start];

    for(int i = start+1; i<=end; i++){
        if(v[i] < X) m++;
    }

    p = v[m];
    v[m] = X;
    v[start] = p;
    long long s1 = start, s2 = m+1;
    while(s1<m && s2 <=end){
        if(v[s1] >= X){
            while(v[s2] >= X && s2 < end) s2++;
            p = v[s1];
            v[s1] = v[s2];
            v[s2] = p;
        }
        s1++;
    }
    SortArr(v, start, m - 1);
    SortArr(v, m + 1, end);
    return 0;
}

int main()
{
    long long  L, S, N, D, res = 0, p = 0, zap;
    vector<long long> DV = {0};

    ifstream InPut ("input.txt");
    ofstream OutPut ("output.txt");

    InPut >> L >> S >> N;

    zap = S;

    for(long long i = 0; i < N; i++){
        InPut >> D;
        if(D < L){
            DV.push_back(D);
        }
    }

    DV.push_back(L);
    N = DV.size();

    SortArr(DV, 0, N - 1);

    for(long long i = N-1; i>0; i--){
        DV[i] -= DV[i-1];
    }

    for(long long i = 1; i < N; i++){
        if(DV[i] > S){
            OutPut << -1;
            return 0;
        }
    }



    for(long long i = 1; i < N; i++){
        if(DV[i] <= zap){
            zap -= DV[i];
        }
        else{
            zap = S;
            i--;
            res++;
        }
    }
    OutPut << res;

    return 0;
}
