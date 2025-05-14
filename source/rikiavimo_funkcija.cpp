#include "../include/rikiavimo_funckija.h"
#include "../include/ivesties_tikrinimas.h"

bool raktas_v(Stud a, Stud b){
    return a.getVardas()<b.getVardas();
}
bool raktas_p(Stud a, Stud b){
    return a.getPavarde()<b.getPavarde();
}
bool raktas_gv(Stud a, Stud b){
    return a.getGalutinisVid()<b.getGalutinisVid();
}
bool raktas_gm(Stud a, Stud b){
    return a.getGalutinisMed()<b.getGalutinisMed();
}

void rikiavimas (Vector<Stud> &studentai){
    string tekstas="1 - Rikiuoti pagal varda\n2 - Rikiuoti pagal pavarde\n3 - Rikiuoti pagal galutini pazymi is vidurkio\n4 - Rikiuoti pagal galutini pazymi is medianos\n5 - Nerikiuoti\nPasirinkite rikiavimo buda: ";
    int pasirinkimas;
    ivesties_tikrinimas(pasirinkimas,tekstas);

    while (pasirinkimas<1 || pasirinkimas>5){
        cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
        ivesties_tikrinimas(pasirinkimas, tekstas);
    }
    if (pasirinkimas==5){
        return;
    }
    switch (pasirinkimas){
        case 1:
            std::sort(studentai.begin(), studentai.end(), raktas_v);
            break;
        case 2:
            std::sort(studentai.begin(), studentai.end(), raktas_p);
            break;
        case 3:
            std::sort(studentai.begin(), studentai.end(), raktas_gv);
            break;
        case 4:
            std::sort(studentai.begin(), studentai.end(), raktas_gm);
            break;
        case 5:
            break;
        default:
            cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
            return;
    }

    tekstas="1 - Rikiuoti didejancia tvarka\n2 - Rikiuoti mazejancia tvarka\nPasirinkite rikiavimo tvarka: ";
    ivesties_tikrinimas(pasirinkimas, tekstas);

    while (pasirinkimas<1 || pasirinkimas>2){
        cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
        ivesties_tikrinimas(pasirinkimas, tekstas);
    }
    if (pasirinkimas==2){
        std::reverse(studentai.begin(), studentai.end());
    }
}
