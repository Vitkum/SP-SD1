#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

void generuotiFaila(const std::string& failoPavadinimas, int irasuKiekis) {
    std::ofstream out(failoPavadinimas);
    if (!out) {
        std::cerr << "Nepavyko atidaryti failo rašymui!" << std::endl;
        return;
    }

    out << "Pavardė     Vardas      ND1  ND2   ND3  ND4  ND5  Egzaminas\n";
    for (int i = 0; i < irasuKiekis; ++i) {
        out << "Pavarde" << i + 1 << " "
            << "Vardas" << i + 1 << " ";
        for (int j = 0; j < 5; ++j) {
            out << (rand() % 10 + 1) << " "; 
        }
        out << (rand() % 10 + 1) << "\n";    
    }

    out.close();
    std::cout << "Failas " << failoPavadinimas << " sugeneruotas su " << irasuKiekis << " įrašais." << std::endl;
}

int main() {
    std::srand(std::time(0));

    generuotiFaila("studentai1000.txt", 1000);
    generuotiFaila("studentai10000.txt", 10000);
    generuotiFaila("studentai100000.txt", 100000);

    return 0;
}
