#ifndef STUDENTAS_H
#define STUDENTAS_H

#include "headers_main.h"
#include "skaiciavimo_funkcijos.h"
#include "zmogus.h"

class Stud : public Zmogus {
private:
    Vector<int> pazymiai;
    int egzaminas;
    double galutinis_vid=-1;
    double galutinis_med=-1;
public:
    Stud() : Zmogus("", ""), egzaminas(0) {}
    Stud(std::istream& is, string rezimas);
    inline string getVardas() const override { return vardas; }
    inline string getPavarde() const override { return pavarde; }
    inline double getGalutinisVid() const { return galutinis_vid; }
    inline double getGalutinisMed() const { return galutinis_med; }
    std::istream& readStudent(std::istream&, string rezimas); 
    void skaiciuotiGalutini();
    ~Stud() {
        pazymiai.clear();
        //cout<<"Destruktorius\n";
    }
    Stud(const Stud &s) : Zmogus(s) {
        pazymiai = s.pazymiai;
        egzaminas = s.egzaminas;
        galutinis_vid = s.galutinis_vid;
        galutinis_med = s.galutinis_med;
    }
    Stud& operator=(const Stud &s) {
        if (this != &s) {
            vardas = s.vardas;
            pavarde = s.pavarde;
            pazymiai = s.pazymiai;
            egzaminas = s.egzaminas;
            galutinis_vid = s.galutinis_vid;
            galutinis_med = s.galutinis_med;
        }
        return *this;
    }
    Stud(Stud &&s) noexcept : Zmogus(std::move(s)) {
        pazymiai = std::move(s.pazymiai);
        egzaminas = s.egzaminas;
        galutinis_vid = s.galutinis_vid;
        galutinis_med = s.galutinis_med;
        s.egzaminas = 0;
        s.galutinis_vid = 0;
        s.galutinis_med = 0;
    }
    Stud& operator=(Stud &&s) noexcept {
        if (this != &s) {
            vardas = std::move(s.vardas);
            pavarde = std::move(s.pavarde);
            pazymiai = std::move(s.pazymiai);
            egzaminas = s.egzaminas;
            galutinis_vid = s.galutinis_vid;
            galutinis_med = s.galutinis_med;
            s.egzaminas = 0;
            s.galutinis_vid = 0;
            s.galutinis_med = 0;
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Stud& s) {
        os << std::left<<std::setw(25)<< s.getVardas() <<std::setw(25)<< s.getPavarde() <<std::setw(25)<< std::fixed << std::setprecision(2) << s.galutinis_vid << std::setw(25)<< s.galutinis_med;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Stud& s) {
        s.pazymiai.clear();
        string v, p;
        is >> v >> p;
        s.setVardas(v);
        s.setPavarde(p);
    
        int pazymys;
        bool isCin = (&is == &std::cin);
    
        while (is >> pazymys) {
            if (isCin && pazymys == -1) break;
            s.pazymiai.push_back(pazymys);
        }
    
        if (!isCin && !s.pazymiai.empty()) {
            s.egzaminas = s.pazymiai.back();
            s.pazymiai.pop_back();
        } else if (isCin) {
            is >> s.egzaminas;
        }
    
        s.skaiciuotiGalutini();
        return is;
    }

};

#endif