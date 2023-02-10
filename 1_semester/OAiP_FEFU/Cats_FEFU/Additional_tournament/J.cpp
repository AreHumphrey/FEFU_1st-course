#include <fstream>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string, int> mall = {}, ma = {};
    map<string, int> :: iterator mallit, mait;
    string S;
    int n, nn, res = 0;

    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");

    ifs >> n;

    for(int i = 0; i<n; i++){
        ifs >> nn;
        getline(ifs, S);
        ma = {};
        for(int j = 0; j < nn; j++){
            getline(ifs, S);
            if(ma.find(S) == ma.end()){
                ma[S] = 1;
            }
            else{
                ma[S]++;
            }

        }
        for(mait = ma.begin(); mait != ma.end(); mait++){
            if(mall.find(mait->first) == mall.end()){
                mall[mait->first] = mait->second;
            }
            else if (mall[mait->first] < mait->second){
                mall[mait->first] = mait->second;
            }
        }
    }

    for(mallit = mall.begin(); mallit != mall.end(); mallit++){
        res += mallit->second;
    }

    ofs << res;

    return 0;
}
