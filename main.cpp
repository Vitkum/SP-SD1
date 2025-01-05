#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Studentas.h"


void generuotiAtsitiktinius(Studentas& s) {
    int namuDarbaiKiekis = rand() % 10 + 1; 
    std::vector<int> namuDarbai;

    for (int i = 0; i < namuDarbaiKiekis; ++i) {
        namuDarbai.push_back(rand() % 10 + 1); 
    }

    int egzaminas = rand() % 10 + 1; 

    s = Studentas("Atsitiktinis", "Studentas", namuDarbai, egzaminas);
}

int main() {
    std::srand(std::time(0)); 

    std::vector<Studentas> studentai;
    int n;
    char pasirinkimas;

    std::cout << "Kiek studentų norite generuoti? ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        Studentas s;
        generuotiAtsitiktinius(s);
        studentai.push_back(s);
    }

    std::cout << "Pasirinkite skaičiavimo metodą (v - vidurkis, m - mediana): ";
    std::cin >> pasirinkimas;

    std::cout << "\nRezultatai:\n";
    for (const auto& s : studentai) {
        try {
            std::cout << s << " Galutinis: " << s.gautiGalutini(pasirinkimas) << "\n";
        } catch (const std::exception& e) {
            std::cout << e.what() << "\n";
        }
    }

    return 0;
}
