#include <iostream>
#include <vector>
#include "Studentas.h"

int main() {
    std::vector<Studentas> studentai;
    int n;

    std::cout << "Kiek studentų norite įvesti? ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        Studentas s;
        std::cin >> s;
        studentai.push_back(s);
    }

    std::cout << "\nRezultatai:\n";
    for (const auto& s : studentai) {
        std::cout << s << "\n";
    }

    return 0;
}
