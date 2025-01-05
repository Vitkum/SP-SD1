#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

class Studentas {
private:
    std::string vardas;            
    std::string pavarde;           
    std::vector<int> namuDarbai;   
    int egzaminas;                 
    double galutinisVid;           
    double galutinisMed;           

    void skaiciuotiGalutini();     
    void skaiciuotiGalutiniMed();  

public:
    Studentas();
    Studentas(const std::string&, const std::string&, const std::vector<int>&, int);
    ~Studentas();

    
    double gautiGalutini(char pasirinkimas) const;

   
    friend std::istream& operator>>(std::istream&, Studentas&);
    friend std::ostream& operator<<(std::ostream&, const Studentas&);
};

#endif
