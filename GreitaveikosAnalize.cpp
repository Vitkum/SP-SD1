#include <iostream>
#include <chrono>
#include "Studentas.h"
#include "StudentuSkirstymas.cpp"

void analizuotiGreiti(const std::string& failoPavadinimas, int strategija) {
    std::vector<Studentas> studentai;
    nuskaitytiIsFailo(failoPavadinimas, studentai);

    std::vector<Studentas> vargsiukai;
    std::vector<Studentas> kietiakai;

    auto start = std::chrono::high_resolution_clock::now();

    if (strategija == 1) {
        skirstytiStudentus1(studentai, vargsiukai, kietiakai);
    } else if (strategija == 2) {
        skirstytiStudentus2(studentai, vargsiukai);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    std::cout << "Strategija " << strategija << " užtruko: " << diff.count() << " sekundžių." << std::endl;
}

int main() {
    std::cout << "Analizuojame greitį su strategija 1...\n";
    analizuotiGreiti("studentai1000.txt", 1);

    std::cout << "Analizuojame greitį su strategija 2...\n";
    analizuotiGreiti("studentai1000.txt", 2);

    return 0;
}
