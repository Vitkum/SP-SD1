#include "Studentas.h"

Studentas::Studentas() : egzaminas(0), galutinisVid(0), galutinisMed(0) {}

Studentas::Studentas(const std::string& v, const std::string& p, const std::vector<int>& nd, int egz)
    : vardas(v), pavarde(p), namuDarbai(nd), egzaminas(egz) {
    skaiciuotiGalutini();
    skaiciuotiGalutiniMed();
}

Studentas::~Studentas() {}

void Studentas::skaiciuotiGalutini() {
    double vidurkis = std::accumulate(namuDarbai.begin(), namuDarbai.end(), 0.0) / namuDarbai.size();
    galutinisVid = 0.4 * vidurkis + 0.6 * egzaminas;
}

void Studentas::skaiciuotiGalutiniMed() {
    std::sort(namuDarbai.begin(), namuDarbai.end());
    size_t n = namuDarbai.size();
    double med = (n % 2 == 0) ? (namuDarbai[n / 2 - 1] + namuDarbai[n / 2]) / 2.0 : namuDarbai[n / 2];
    galutinisMed = 0.4 * med + 0.6 * egzaminas;
}

double Studentas::gautiGalutini(char pasirinkimas) const {
    if (pasirinkimas == 'v') return galutinisVid;
    if (pasirinkimas == 'm') return galutinisMed;
    throw std::invalid_argument("Neteisingas pasirinkimas!");
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
    s.skaiciuotiGalutiniMed();
    return in;
}

std::ostream& operator<<(std::ostream& out, const Studentas& s) {
    out << s.pavarde << " " << s.vardas;
    return out;
}
