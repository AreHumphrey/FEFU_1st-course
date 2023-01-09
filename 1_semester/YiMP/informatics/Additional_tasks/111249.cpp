#include <iostream>
#include <string.h>
using namespace std;
int main(){
    int ParityControl = 0;
    const size_t size = 0xFF;
    char str[size];
    cin >> str;
    for (int i = 0; i < strlen(str); i++){
        if (str[i] == '1'){ParityControl += 1;}
        if ((str[i] == 'o') && (ParityControl % 2 == 0)){str[i] = '1';}
        if ((str[i] == 'o') && (ParityControl % 2 != 0)){str[i] = '0';}
        if ((str[i] == 'e')&& (ParityControl % 2 == 0)){str[i] = '0';}
        if ((str[i] == 'e')&& (ParityControl % 2 != 0)){str[i] = '1';}
    }
    cout << str;

}
