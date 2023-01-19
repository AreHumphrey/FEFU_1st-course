#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    string s1,s2;
    fin >> s1 >> s2;
    s2 += s2;
    int dist=s2.find(s1);
    fout << dist;
}
