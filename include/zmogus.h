#ifndef ZMOGUS_H
#define ZMOGUS_H

#include "headers_main.h"
#include "export_def.h"

class DLL_EXPORT Zmogus {
protected:
    string vardas;
    string pavarde;
public:
    Zmogus(string v, string p) : vardas(v), pavarde(p) {}
    Zmogus() : vardas(""), pavarde("") {}

    Zmogus(const Zmogus &z) : vardas(z.vardas), pavarde(z.pavarde) {}
    Zmogus& operator=(const Zmogus &z) {
        if (this != &z) {
            vardas = z.vardas;
            pavarde = z.pavarde;
        }
        return *this;
    }
    Zmogus(Zmogus &&z) noexcept : vardas(std::move(z.vardas)), pavarde(std::move(z.pavarde)) {}
    Zmogus& operator=(Zmogus &&z) noexcept {
        if (this != &z) {
            vardas = std::move(z.vardas);
            pavarde = std::move(z.pavarde);
        }
        return *this;
    }

    virtual ~Zmogus() {
        vardas.clear();
        pavarde.clear();
    }
    virtual string getVardas() const = 0;
    virtual string getPavarde() const = 0;

    void setVardas(const string& v) { vardas = v; }
    void setPavarde(const string& p) { pavarde = p; }
};

#endif