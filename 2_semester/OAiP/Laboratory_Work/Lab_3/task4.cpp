#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <Windows.h>

struct Road {
    int from;
    int to;
    int distance;
};

void task4() {
    SetConsoleOutputCP(CP_UTF8);
    int N, K;
    std::cin >> N >> K;
    std::vector<int> houses(N);
    for (int i = 0; i < N; i++) {
        std::cin >> houses[i];
    }
    std::vector<Road> roads(K);
    for (int i = 0; i < K; i++) {
        std::cin >> roads[i].from >> roads[i].to >> roads[i].distance;
    }

    int minTotalDistance = INT_MAX;
    int meetingPoint;
    for (int i = 0; i < N; i++) {
        int totalDistance = 0;
        for (int j = 0; j < N; j++) {
            totalDistance += abs(houses[i] - houses[j]);
        }
        if (totalDistance < minTotalDistance) {
            minTotalDistance = totalDistance;
            meetingPoint = i + 1;
        }
    }
    for (int i = 0; i < K; i++) {
        int from = roads[i].from - 1;
        int to = roads[i].to - 1;
        int distance = roads[i].distance;
        int totalDistance = 0;
        for (int j = 0; j < N; j++) {
            totalDistance += std::min(abs(houses[j] - houses[from]) + distance + abs(houses[j] - houses[to]),
                                 abs(houses[j] - houses[to]) + distance + abs(houses[j] - houses[from]));
        }
        if (totalDistance < minTotalDistance) {
            minTotalDistance = totalDistance;
            meetingPoint = std::min(houses[from], houses[to]) + distance / 2;
        }
    }
    std::cout << "Точка:" << meetingPoint << std::endl;
}