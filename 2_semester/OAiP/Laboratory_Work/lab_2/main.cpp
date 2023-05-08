#include <iostream>
#include <windows.h>
#include "Bin_Tree.cpp"
#include "AVL_Tree.cpp"
#include "Anagram.cpp"
void task1(){
    SetConsoleOutputCP(CP_UTF8);
    std::string s;
    std::cout << "Введите строку:\n ";
    std::cin >> s;
    if (Palindrome(s)){
        std::cout << "Cтрока является палиндромом" << std::endl;
    }
    else{
        std::cout << "Cтрока не является палиндромом" << std::endl;
    }
}
void task2() {
    int arr[5] = {-2, 3, 48, 8, -1};
    BinTree *root = CreateBinTree(0);
    for (int i = 0; i < 5; i++) {
        BinTree *element = CreateBinTree(arr[i]);
        Insert(root, element);
    }
    Print(root);
}

void task3() {
    AVLTree *root = nullptr;
    root = Insert(root, 12);
    root = Insert(root, 8);
    root = Insert(root, 18);
    root = Insert(root, 5);
    root = Insert(root, 11);
    root = Insert(root, 17);
    root = Insert(root, 4);

    Print(root);
    std::cout << std::endl;
    root = DeleteNode(root, 5);
    Print(root);
}

void task4() {
    SetConsoleOutputCP(CP_UTF8);
    std::string a, b;
    std::cout << "Введите первую строку:\n a=\t";
    std::cin >> a;
    std::cout << std::endl;
    std::cout << "Введите вторую строку:\n b=\t";
    std::cin >> b;
    std::string ans = FindAnagram(a, b);
    if (ans != "") {
        std::cout << ans << std::endl;
    } else {
        std::cout << "Анаграмма не найдена" << std::endl;
    }
}

void task5() {
    SetConsoleOutputCP(CP_UTF8);
    std::string str, substr, newSubstr, result;
    bool found = false;
    std::cout << "Введите строку:\n ";
    std::cin >> str;
    std::cout << "Введите подстроку, которую нужно заменить:\n ";
    std::cin >> substr;
    std::cout << "Введите новую подстроку:\n";
    std::cin >> newSubstr;
    // Поиск подстроки в строке (алгоритм Бойера-Мура)
    int slen = str.length(), sublen = substr.length();
    int shift[256];
    for (int i = 0; i < 256; i++) {
        shift[i] = sublen;
    }
    for (int i = 0; i < sublen - 1; i++) {
        shift[substr[i]] = sublen - i - 1;
    }
    int pos = sublen - 1;
    while (pos < slen) {
        int j = sublen - 1;
        while (j >= 0 && str[pos] == substr[j]) {
            pos--;
            j--;
        }
        if (j < 0) {
            found = true;
            result = str.substr(0, pos + 1) + newSubstr + str.substr(pos + sublen);
            break;
        }
        pos += shift[str[pos]];
    }
    if (!found) {
        std::cout << "Подстрока не найдена" << std::endl;
    } else {
        std::cout << "Новая строка:\t " << result << std::endl;
    }
}

int main() {
    task1();
}