#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main() {
  ifstream InPut("input.txt");
  ofstream OutPut("output.txt");
  bool InPoly = false, OnTheLine = false;
  int n, x, y, XMax, XMin,YMax,YMin;
  InPut >> n >> x >> y;
  int Arr[n][2];
  for (int i = 0; i < n; i++) {
    InPut >> Arr[i][0] >> Arr[i][1];
    XMax = max(XMax, Arr[i][0]);
    YMax = max(YMax, Arr[i][1]);
    XMin = min(XMin, Arr[i][0]);
    YMin = min(YMin, Arr[i][1]);
  }
  for (int i = 0, j = n - 1; i < n; j = i++) {
    if ((((Arr[i][1] <= y) && (y < Arr[j][1])) || ((Arr[j][1] <= y) && (y < Arr[i][1]))) && (((Arr[j][1] - Arr[i][1]) != 0) && (x > ((Arr[j][0] - Arr[i][0]) * (y - Arr[i][1]) / (Arr[j][1] - Arr[i][1]) + Arr[i][0])))){
      InPoly = !InPoly;
    }
    else if(((((x - Arr[i][0]) * (Arr[(i + 1) % (n - 1)][1] - Arr[i][1])) - ((y - Arr[i][1]) * (Arr[(i + 1) % (n - 1)][0] - Arr[i][0]))) == 0) and ((x >= XMin) and (x <= XMax)) and ((y >= YMin) and (y <= YMax))){
          OnTheLine = true;
      }
  }
  if (InPoly or OnTheLine) {
      OutPut << "YES";
  }
  else {
      OutPut << "NO";
  }
}
