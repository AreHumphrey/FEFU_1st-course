#include <fstream>


int main() {
    int countWorkers, countChenges,
            bufferNumbers, bufferValue, maxValue, maxIndex = 0;

    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    input >> countWorkers >> countChenges;

    int arrWorkers[countWorkers];

    for (int i = 0; i < countWorkers; i++) input >> arrWorkers[i];

    maxValue = arrWorkers[0];

    for (int i = 1; i < countWorkers; i++) {
        if (maxValue < arrWorkers[i]) {
            maxValue = arrWorkers[i];
            maxIndex = i;
        }
    }

    for (int i = 0; i < countChenges; i++) {
        input >> bufferNumbers >> bufferValue;

        bufferNumbers--;
        arrWorkers[bufferNumbers] += bufferValue;

        if (bufferValue > 0) {
            if (maxValue < arrWorkers[bufferNumbers]) {
                maxValue = arrWorkers[bufferNumbers];
                maxIndex = bufferNumbers;
            }
        }

        if (maxIndex == bufferNumbers) {
            maxValue = arrWorkers[0];
            maxIndex = 0;

            for (int j = 1; j < countWorkers; j++) {
                if (maxValue < arrWorkers[j]) {
                    maxValue = arrWorkers[j];
                    maxIndex = j;
                }
            }
        }

        output << maxValue << std::endl;
    }

    return 0;
}
