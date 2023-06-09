#include "Anagram.h"
#include <string>
#include <math.h>
#include <algorithm>

bool Anagram(int count[], int tempCount[]) {
    for (int i = 0; i < 256; i++) {
        if (count[i] != tempCount[i]) {
            return false;
        }
    }
    return true;
}
std::string Substr(const std::string& str, size_t start, size_t len) {
    std::string result;
    if(start >= str.size()) {
        return result;
    }
    for(size_t i = start; i < start + len && i < str.size(); ++i) {
        result += str[i];
    }
    return result;
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
            return Substr(s, i - m, m);
        }
        tempCount[(int) s[i]]++;
        tempCount[(int) s[i - m]]--;
    }

    if (Anagram(count, tempCount)) {
        return s.substr(n - m, m);
    }

    return "";
}


uint64_t hash_(std::string s) {
    uint64_t hash = 0;
    uint64_t prime = 101;
    for (int i = 0; i < s.size(); i++) {
        hash += ((uint64_t)s[i] - 96) * pow(prime, i);
    }
    return hash;
}

bool Palindrome(std::string s) {
    int n = s.size();
    if (n == 0 || n == 1) {
        return true;
    }

    uint64_t frontHash;
    uint64_t backHash;

    if (s.size() % 2 != 0){
        frontHash = hash_(s.substr(0, n / 2));
        backHash = hash_(s.substr(n / 2 + 1));
    }
    else{
        frontHash = hash_(s.substr(0, n / 2));
        std::string backHalfReversed = s.substr(n / 2);
        std::reverse(backHalfReversed.begin(), backHalfReversed.end());
        backHash = hash_(backHalfReversed);
    }

    std::string reversed = s;
    std::reverse(reversed.begin(), reversed.end());
    uint64_t reversedHash = hash_(reversed.substr(0, n / 2));

    return frontHash == reversedHash && backHash == reversedHash;
}



