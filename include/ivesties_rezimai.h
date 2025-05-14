#ifndef IVESTIES_REZIMAI_H
#define IVESTIES_REZIMAI_H

#include "headers_main.h"
#include "studentas.h"

void strategija_1(Vector<Stud> &studentai, Vector<Stud> &vargsiukai, Vector<Stud> &galvociai);
void ranka (Vector<Stud> &studentai);
void pazymiu_generavimas (Vector<Stud> &studentai);
void visko_generavimas (Vector<Stud> &studentai);
void skaitymas_is_failo (Vector<Stud> &studentai, string failas, bool testavimas);
void failu_generavimas(int n);
void studentu_skaitymas_ir_skirstymas_i_vargsiukus_ir_galvocius (Vector<Stud> &studentai, string failas, std::chrono::duration<double>  &ivesties_suma, std::chrono::duration<double>  &rusiavimo_suma, std::chrono::duration<double> &skirstymo_suma, int strategija/*, int pasirinkimas1, int pasirinkimas2, int pasirinkimas3, int pasirinkimas4*/);

#endif