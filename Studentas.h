#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

class Studentas {
private:
    std::string vardas;            
    std::string pavarde;           
    std::vector<int> namuDarbai;   
    int egzaminas;                 
    double galutinisVid;           

    void skaiciuotiGalutini();     

public:
    Studentas();                                   
    Studentas(const std::string&, const std::string&, const std::vector<int>&, int); 
    Studentas(const Studentas&);                  
    ~Studentas();                                  

    Studentas& operator=(const Studentas&);       

    friend std::istream& operator>>(std::istream&, Studentas&);
    friend std::ostream& operator<<(std::ostream&, const Studentas&);
};

#endif
