#include "Studentas.h"


Studentas::Studentas() : egzaminas(0), galutinisVid(0) {}


Studentas::Studentas(const std::string& v, const std::string& p, const std::vector<int>& nd, int egz)
    : vardas(v), pavarde(p), namuDarbai(nd), egzaminas(egz) {
    skaiciuotiGalutini();
}


Studentas::Studentas(const Studentas& kitas)
    : vardas(kitas.vardas), pavarde(kitas.pavarde),
      namuDarbai(kitas.namuDarbai), egzaminas(kitas.egzaminas),
      galutinisVid(kitas.galutinisVid) {}


Studentas::~Studentas() {}


Studentas& Studentas::operator=(const Studentas& kitas) {
    if (this != &kitas) {
        vardas = kitas.vardas;
        pavarde = kitas.pavarde;
        namuDarbai = kitas.namuDarbai;
        egzaminas = kitas.egzaminas;
        galutinisVid = kitas.galutinisVid;
    }
    return *this;
}


void Studentas::skaiciuotiGalutini() {
    double vidurkis = std::accumulate(namuDarbai.begin(), namuDarbai.end(), 0.0) / namuDarbai.size();
    galutinisVid = 0.4 * vidurkis + 0.6 * egzaminas;
}


std::istream& operator>>(std::istream& in, Studentas& s) {
    std::cout << "Įveskite vardą ir pavardę: ";
    in >> s.vardas >> s.pavarde;

    std::cout << "Įveskite namų darbų rezultatus (baigti su -1): ";
    int nd;
    while (in >> nd && nd != -1) {
        s.namuDarbai.push_back(nd);
    }

    std::cout << "Įveskite egzamino rezultatą: ";
    in >> s.egzaminas;

    s.skaiciuotiGalutini();
    return in;
}


std::ostream& operator<<(std::ostream& out, const Studentas& s) {
    out << s.pavarde << " " << s.vardas
        << " Galutinis (Vid.): " << s.galutinisVid;
    return out;
}
