#include <fstream>
#include <cmath>
int main() {
    std::fstream input("input.txt");
    std::ofstream output("output.txt");
    int n;
    input >> n;
    int powN = pow(2, n), i = 0;
    int temp; int arrBin[n];
    while (i < powN){
        temp = i;
        for (int j = n - 1; j >= 0; j--){
            arrBin[j] = temp % 2;
            temp /= 2;
        }
        i++;
        for (int g = 0; g < n; g++){
            output << arrBin[g];
        }
        output << "\n";
    }


}
