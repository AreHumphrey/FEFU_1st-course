#include <fstream>
#include <vector>

struct Ticket {
    int start;
    int end;
    int place;
};

int main() {
    std::ifstream input("trains.in");
    std::ofstream output("trains.out");
    int station, countTick, places;
    input >> station >> countTick >> places;
    std::vector<std::vector<Ticket>> tickets(station + 1); //station
    for (int i = 0; i < countTick; i++) {
        int start, end, place;
        input >> start >> end >> place;
        tickets[end].push_back(Ticket{start, end, place});
    }
    std::vector<int> answer(station + 1);{

        std::vector<int> maxStation(places + 1, station);
        std::vector<int> cntMax(station + 1, 0);
        cntMax[station] = places;
        int cntMaxIndex = station;
        for (int i = station; i >= 1; i--) {
            answer[i] = std::max(i, cntMaxIndex);
            for (const Ticket &ticket: tickets[i]) {
                cntMax[maxStation[ticket.place]]--;
                maxStation[ticket.place] = ticket.start;
                cntMax[maxStation[ticket.place]]++;
            }
            while (cntMax[cntMaxIndex] == 0) {
                cntMaxIndex--;
            }

        }

    }
    const int MULTI_SIZE = 512;
    std::vector<int> multiTicketMax(station + 1);
    std::vector<int> multiTicketCount(station + 1);
    for (int j = station; j >= 1; j--) {
        if (answer[j] == j) {
            multiTicketMax[j] = j;
            multiTicketCount[j] = 0;
        }
        else {
            int afterFirst = answer[j];
            if (afterFirst / MULTI_SIZE != j / MULTI_SIZE) {
                multiTicketMax[j] = afterFirst;
                multiTicketCount[j] = 1;
            }
            else {
                multiTicketMax[j] = multiTicketMax[afterFirst];
                multiTicketCount[j] = multiTicketCount[afterFirst] + 1;
            }
        }
    }
    int q;
    input >> q;
    for (int i = 0; i < q; i++) {
        int start, end;
        input >> start >> end;
        int count = 0;
        while (multiTicketMax[start] > start && multiTicketMax[start] <= end) {
            count += multiTicketCount[start];
            start = multiTicketMax[start];
        }
        while (start < answer[start] && start < end) {
            count++;
            start = answer[start];
        }
        if (start < end) {
            output << -1 << "\n";
        }
        else {
            output << count << "\n";
        }
    }
    return 0;
}
