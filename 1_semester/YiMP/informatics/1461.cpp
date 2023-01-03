#include <iostream>
#include <string>
using namespace std;

int main() {
    string StringElem = "", ElementProject;
    int CountElement, CurrenCount = 1, DelCount = 0, Index = -1; cin >> CountElement;
    bool FlagElementPr = true;

    for (int i = 0; i < CountElement; i++) {
        cin >> ElementProject;
        StringElem += ElementProject;
    } StringElem += " "; CountElement = -1;

    while (FlagElementPr) {
        //cout << del_count << " <1> " << element_count << endl;/////

        for (int i = 0; i < StringElem.length(); i++) {

            if (StringElem[i] == StringElem[i + 1]) {
                CurrenCount++;
                if (Index == -1) { Index = i; }

            }
            else {

                if (CurrenCount > 2) {
                    DelCount += CurrenCount;
                    StringElem.replace(Index, CurrenCount, "");

                }
                Index = -1;
                CurrenCount = 1;
            }
        }
        if (CountElement == DelCount) { FlagElementPr = false; }
        else { CountElement = DelCount; }
    }
    cout << DelCount << endl;
}
