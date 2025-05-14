#include "../include/isvesties_rezimai.h"

void isvestis (std::ostream &out, Vector<Stud> &studentai){
    out << std::left<<std::setw(25) <<"Vardas"<<std::setw(25)<<"Pavarde"<<std::setw(25)<<"Galutinis (Vid.)"<<std::setw(25)<<"/ Galutinis (Med.)"<<"\n"<<string(100, '-')<<"\n";
    for (auto &x:studentai){
        out << x;
        out << "\n";
    }
}