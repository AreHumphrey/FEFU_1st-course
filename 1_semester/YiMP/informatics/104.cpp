#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
int main() {
    std::string Arr_Alfovit_Lat_Niz_Registr[] = {"q","w","e","r","t","y","u","i","o","p","a","s","d","f","g","h","j","k","l","z","x","c","v","b","n","m"};
    std::string Arr_Alfovit_Lat_Caps_Registr[] = {"Q","W","E","R","T","Y","U","I","O","P","A","S","D","F","G","H","J","J","K","L","Z","X","C","V","B","N","M"};
    std::string Registr;
    std::cin >> Registr;
    for (int i = 0; i < 28; i++) {
        if (Arr_Alfovit_Lat_Caps_Registr[i] == Registr) {
            std::transform(Registr.begin(), Registr.end(), Registr.begin(), tolower);
            break;
        }
        else if (Arr_Alfovit_Lat_Niz_Registr[i] == Registr) {
            std::transform(Registr.begin(), Registr.end(), Registr.begin(), toupper);
            break;
        }
    }
    std::cout << Registr <<std:: endl;
}
