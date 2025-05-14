#include "../include/ivesties_tikrinimas.h"

template <typename T>
void ivesties_tikrinimas(T &reiksme, string &tekstas) {
    while (true) {
        try {
            cout << tekstas;
            cin >> reiksme;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                throw std::runtime_error("Iveskite tinkama reiksme!\n");
            }
            break;
        }
        catch (std::runtime_error klaida) {
            std::cerr<<klaida.what();
            cin.ignore();
        }
    }
}

template void ivesties_tikrinimas<int>(int&, string&);
template void ivesties_tikrinimas<string>(string&, string&);