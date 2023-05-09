#include "Anagram.h"
#include <string>
#include <math.h>
bool Anagram(int count[], int tempCount[]) {
    for (int i = 0; i < 256; i++) {
        if (count[i] != tempCount[i]) {
            return false;
        }
    }
    return true;
}

std::string FindAnagram(std::string s, std::string t) {
    int count[256] = {0};
    int tempCount[256] = {0};
    int n = s.size();
    int m = t.size();
    if (m > n) {
        return "";
    }
    for (int i = 0; i < m; i++) {
        count[(int) t[i]]++;
        tempCount[(int) s[i]]++;
    }

    for (int i = m; i < n; i++) {
        if (Anagram(count, tempCount)) {
            return s.substr(i - m, m);
        }
        tempCount[(int) s[i]]++;
        tempCount[(int) s[i - m]]--;
    }

    if (Anagram(count, tempCount)) {
        return s.substr(n - m, m);
    }

    return "";
}


uint64_t hash(std::string s) {
    uint64_t hash = 0;
    for (int i = 0; i < s.size(); i++) {
        hash += ((uint64_t)s[i] - 96) * pow(31, i);
    }
    return hash;
}

bool Palindrome(std::string s) {
    int n = s.size();
    if (n == 0 || n == 1) {
        return true;
    }
    uint64_t frontHash = hash(s.substr(0, n / 2));
    uint64_t backHash = hash(s.substr(n / 2 + n % 2));
    return frontHash == backHash;
}


