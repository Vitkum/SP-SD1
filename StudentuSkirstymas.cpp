#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <list>
#include <deque>
#include "Studentas.h"

void nuskaitytiIsFailo(const std::string& failoPavadinimas, std::vector<Studentas>& studentai) {
    std::ifstream in(failoPavadinimas);
    if (!in) {
        std::cerr << "Nepavyko atidaryti failo: " << failoPavadinimas << std::endl;
        return;
    }

    std::string eilute;
    std::getline(in, eilute); 

    while (std::getline(in, eilute)) {
        std::istringstream ss(eilute);
        Studentas s;
        ss >> s;

        studentai.push_back(s);
    }

    in.close();
}

void skirstytiStudentus1(const std::vector<Studentas>& studentai, 
                        std::vector<Studentas>& vargsiukai, 
                        std::vector<Studentas>& kietiakai) {
    for (const auto& s : studentai) {
        if (s.gautiGalutini('v') < 5.0) {
            vargsiukai.push_back(s);
        } else {
            kietiakai.push_back(s);
        }
    }
}

void skirstytiStudentus2(std::vector<Studentas>& studentai, std::vector<Studentas>& vargsiukai) {
    auto it = std::remove_if(studentai.begin(), studentai.end(), [&](const Studentas& s) {
        if (s.gautiGalutini('v') < 5.0) {
            vargsiukai.push_back(s);
            return true; 
        }
        return false;
    });
    studentai.erase(it, studentai.end());
}
