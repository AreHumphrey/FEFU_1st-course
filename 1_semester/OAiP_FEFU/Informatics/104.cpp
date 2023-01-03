//Задача №104. Изменить регистр символа
//Измените регистр символа, если он был латинской буквой: сделайте его заглавным, если он был строчной буквой и наоборот.
// Для этого напишите отдельную функцию, меняющую регистр символа.
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
int main() {
    std::string ArrAlfovitLatNizRegistr[] = {"q","w","e","r","t","y","u","i","o","p","a","s","d","f","g","h","j","k","l","z","x","c","v","b","n","m"};
    std::string ArrAlfovitLatCapsRegistr[] = {"Q","W","E","R","T","Y","U","I","O","P","A","S","D","F","G","H","J","J","K","L","Z","X","C","V","B","N","M"};
    std::string RegistrNumber;
    std::cin >> RegistrNumber;
    for (int i = 0; i < 28; i++) {
        if (ArrAlfovitLatCapsRegistr[i] == RegistrNumber) {
            std::transform(RegistrNumber.begin(), RegistrNumber.end(), RegistrNumber.begin(), tolower);
            break;
        }
        else if (ArrAlfovitLatNizRegistr[i] == RegistrNumber) {
            std::transform(RegistrNumber.begin(), RegistrNumber.end(), RegistrNumber.begin(), toupper);
            break;
        }
    }
    std::cout << RegistrNumber <<std:: endl;
}


