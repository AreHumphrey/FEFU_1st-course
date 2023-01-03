#include <iostream>
using namespace std;
int main(){
    int CountPosled, Element, Schetchik = 0;
    cin >> CountPosled;
    int Arr[CountPosled];
    for (int i = 0; i < CountPosled; i++) {
        cin >> Element;
        Arr[i] += Element;
    }
    for (int j = 1; j < CountPosled - 1; j++){
        if (not(((Arr[j] < Arr[j + 1]) && (Arr[j + 1] > Arr[j + 2])) || ((Arr[j] > Arr[j + 1]) && (Arr[j + 1] < Arr[j + 2])))){
            Schetchik += 1;
        }
    }
    cout << Schetchik;



}
