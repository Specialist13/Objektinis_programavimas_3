#ifndef VARTOTOJO_PASIRINKIMO_FUNKCIJOS_H
#define VARTOTOJO_PASIRINKIMO_FUNKCIJOS_H

#include "headers_main.h"
#include "studentas.h"
#include "export_def.h"

DLL_EXPORT void rezimo_pasirinkimas (Vector<Stud> &studentai);
void isvesties_pasirinkimas(Vector<Stud> &studentai);
void failo_pasirinkimas(Vector<Stud> &studentai);

#endif