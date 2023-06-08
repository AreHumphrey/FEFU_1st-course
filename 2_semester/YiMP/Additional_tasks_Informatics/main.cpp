#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const double Eps = 1e-15;


class Db {
public:
    double d;
    int id;

    Db() {
        d = 0.;
        id = -1;
    }
};

bool operator<(Db a, Db b) {
    return (a.d < b.d - Eps) || (fabs(a.d - b.d) < Eps && a.id < b.id);
}

vector<Db> objectFunds, companyPower;
int numObjects, m;
double current = 0;

double typeT(double t) {
    double Sum1 = 0, Sum2 = 0, Max = 0;
    vector<Db> Ss = objectFunds;
    for (int i = 0; i < numObjects; ++i) {
        Ss[i].d = objectFunds[i].d - t * companyPower[i].d;
    }
    sort(Ss.rbegin(), Ss.rend());
    for (int i = 0; i < objectFunds.size(); ++i) {
        Sum1 += Ss[i].d;
        Sum2 += companyPower[i].d;
        Max = max(Max, Sum1 / Sum2);
    }
    return t + Max;
}

bool newObj(double t) {
    int Old[numObjects];
    for (int i = 0; i < numObjects; ++i) {
        Old[i] = objectFunds[i].id;
    }
    for (int i = 0; i < numObjects; ++i) {
        objectFunds[i].d -= companyPower[i].d * t;
    }
    sort(objectFunds.rbegin(), objectFunds.rend());
    for (int i = 0; i < min(numObjects, m); ++i) {
        if (objectFunds[i].id != Old[i] && objectFunds[i].d > Eps) {
            cout << current << " " << objectFunds[i].id + 1 << " " << companyPower[i].id + 1 << endl;
        }
    }
    return objectFunds[0].d > Eps;
}


int main() {
    cin >> numObjects;
    objectFunds.resize(numObjects);
    for (int i = 0; i < numObjects; ++i) {
        cin >> objectFunds[i].d;
        objectFunds[i].id = i;
    }
    cin >> m;
    companyPower.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> companyPower[i].d;
        companyPower[i].id = i;
    }
    sort(objectFunds.rbegin(), objectFunds.rend());
    sort(companyPower.rbegin(), companyPower.rend());
    companyPower.resize(numObjects);
    cout.precision(20);
    cout << typeT(0) << endl;
    for (int i = 0; i < min(numObjects, m); ++i) {
        cout << 0 << " " << objectFunds[i].id + 1 << " " << companyPower[i].id + 1 << endl;
    }
    bool flag = true;
    while (flag) {
        double t = typeT(0);
        double l = 0, r = t;
        for (int i = 0; i < 200; ++i) {
            double mi = (l + r) / 2;
            if (typeT(mi) > t + Eps) {
                r = mi;
            } else {
                l = mi;
            }
        }
        current += l;
        flag = newObj(l);
    }

}
