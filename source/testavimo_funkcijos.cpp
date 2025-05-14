#include "../include/testavimo_funkcijos.h"
#include "../include/ivesties_tikrinimas.h"
#include "../include/skaiciavimo_funkcijos.h"
#include "../include/ivesties_rezimai.h"

void testinis_skaitymas_is_failo (vector<Stud> &studentai, string failas){
    std::chrono::duration<double> laiku_suma{0};
    for (int i=0; i<5; i++){
        std::ifstream fd(failas);
        if (fd.fail()){
            throw std::runtime_error("Failas nerastas.");
        }
        auto pradzia=std::chrono::high_resolution_clock::now();
        std::stringstream ss;
        ss << fd.rdbuf();
        fd.close();
        string linija;
        std::getline(ss, linija);
        while (std::getline(ss, linija)){
            std::istringstream iss(linija);
            Stud laikinas(iss, "failas");
            studentai.push_back(laikinas);
        }
        auto pabaiga=std::chrono::high_resolution_clock::now();
        laiku_suma+=pabaiga-pradzia;
        studentai.clear();
    }
    cout<<"Skaitymo is failo laikas: "<<laiku_suma.count()/5<<" s\n";
}

void testavimas(vector<Stud> &studentai){
    string failai[] = {"kursiokai.txt", "studentai10000.txt", "studentai100000.txt", "studentai1000000.txt"};
    string tekstas="1 - kursiokai.txt\n2 - studentai10000.txt\n3 - studentai100000.txt\n4 - studentai1000000.txt\nPasirinkite faila testavimui: ";
    int pasirinkimas;
    ivesties_tikrinimas(pasirinkimas, tekstas);

    while (pasirinkimas<1 || pasirinkimas>4){
        cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
        ivesties_tikrinimas(pasirinkimas, tekstas);
    }
    try {
        testinis_skaitymas_is_failo(studentai, failai[pasirinkimas-1]);
    }
    catch (std::runtime_error klaida){
        std::cerr<<klaida.what()<<endl;
        testavimas(studentai);
    }
}

void failo_kurimo_testavimas (){
    std::chrono::duration<double> laiku_suma{0};
    string tekstas="Iveskite, kiek studentu norite sugeneruoti: ";
    int n;
    ivesties_tikrinimas(n, tekstas);
    while (n<1){
        cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
        ivesties_tikrinimas(n, tekstas);
    }
    for (int i=0; i<5; i++){
        auto pradzia=std::chrono::high_resolution_clock::now();
        failu_generavimas(n);
        auto pabaiga=std::chrono::high_resolution_clock::now();
        laiku_suma+=pabaiga-pradzia;
    }
    cout<<"Failo kurimo laikas: "<<laiku_suma.count()/5<<" s\n";
}

void duomenu_apdorojimo_testavimas (){
    std::chrono::duration<double> ivesties_suma{0}, rusiavimo_suma{0}, skirstymo_suma{0};
    /*string tekstas="Iveskite faila is kurio norite skirstyti: ";
    string failas;
    ivesties_tikrinimas(failas, tekstas);
    cout<<"Dabar rinkites vagsiuku rikiavimo buda:\n";
    */
    vector<string> failai = {"studentai1000.txt", "studentai10000.txt", "studentai100000.txt", "studentai1000000.txt", "studentai10000000.txt"};
    int strategija=0;
    string tekstas="Pasirinkite strategija (1, 2, 3): ";
    ivesties_tikrinimas(strategija, tekstas);
    while (strategija<1 || strategija>3){
        cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
        ivesties_tikrinimas(strategija, tekstas);
    }
    /*string tekstas="1 - Rikiuoti pagal varda\n2 - Rikiuoti pagal pavarde\n3 - Rikiuoti pagal galutini pazymi is vidurkio\n4 - Rikiuoti pagal galutini pazymi is medianos\n5 - Nerikiuoti\nPasirinkite rikiavimo buda: ";
    int pasirinkimas1;
    ivesties_tikrinimas(pasirinkimas1, tekstas);
    while (pasirinkimas1<1 || pasirinkimas1>5){
        cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
        ivesties_tikrinimas(pasirinkimas1, tekstas);
    }
    tekstas="1 - Rikiuoti didejancia tvarka\n2 - Rikiuoti mazejancia tvarka\nPasirinkite rikiavimo tvarka: ";
    int pasirinkimas2;
    ivesties_tikrinimas(pasirinkimas2, tekstas);
    while (pasirinkimas2<1 || pasirinkimas2>2){
        cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
        ivesties_tikrinimas(pasirinkimas2, tekstas);
    }
    cout<<"Dabar rinkites galvociu rikiavimo buda:\n";
    tekstas="1 - Rikiuoti pagal varda\n2 - Rikiuoti pagal pavarde\n3 - Rikiuoti pagal galutini pazymi is vidurkio\n4 - Rikiuoti pagal galutini pazymi is medianos\n5 - Nerikiuoti\nPasirinkite rikiavimo buda: ";
    int pasirinkimas3;
    ivesties_tikrinimas(pasirinkimas3, tekstas);
    while (pasirinkimas3<1 || pasirinkimas3>5){
        cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
        ivesties_tikrinimas(pasirinkimas3, tekstas);
    }
    tekstas="1 - Rikiuoti didejancia tvarka\n2 - Rikiuoti mazejancia tvarka\nPasirinkite rikiavimo tvarka: ";
    int pasirinkimas4;
    ivesties_tikrinimas(pasirinkimas4, tekstas);
    while (pasirinkimas4<1 || pasirinkimas4>2){
        cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
        ivesties_tikrinimas(pasirinkimas4, tekstas);
    }*/
    for (auto failas:failai){
        try {
            for (int i=0; i<5; i++){
                Stud laikinas;
                vector<Stud> studentai;
                studentu_skaitymas_ir_skirstymas_i_vargsiukus_ir_galvocius(studentai, failas, ivesties_suma, rusiavimo_suma, skirstymo_suma, strategija/*, pasirinkimas1, pasirinkimas2, pasirinkimas3, pasirinkimas4*/);
            }
            cout<<"Failas: "<<failas<<endl;
            cout<<"Ivesties trukme: "<<ivesties_suma.count()/5<<" s\n";
            cout<<"Rusiavimo trukme: "<<rusiavimo_suma.count()/5<<" s\n";
            cout<<"Skirstymo trukme: "<<skirstymo_suma.count()/5<<" s\n";
            cout<<"Bendra trukme: "<<(ivesties_suma.count()+rusiavimo_suma.count()+skirstymo_suma.count())/5<<" s\n";
        }
        catch (std::runtime_error klaida){
            std::cerr<<klaida.what()<<endl;
            duomenu_apdorojimo_testavimas();
        }
    }
}

void konteinerio_testavimas(){
    unsigned int sz[5] = {10000, 100000, 1000000, 10000000, 100000000};
    
    for (int i=0; i<5; i++){
        std::chrono::duration<double> galutinisV1{0};
        vector<int> v1;
        auto pradziaV1=std::chrono::high_resolution_clock::now();
        for (int j=0; j<sz[i]; j++){
            v1.push_back(j);
        }
        auto pabaigaV1=std::chrono::high_resolution_clock::now();
        galutinisV1+=pabaigaV1-pradziaV1;
        cout<<"std::vector laikas su "<<sz[i]<<" elementu: "<<galutinisV1.count()<<" s\n";
    }

    for (int i=0; i<5; i++){
        std::chrono::duration<double> galutinisV2{0};
        Vector<int> v2;
        auto pradziaV2=std::chrono::high_resolution_clock::now();
        for (int j=0; j<sz[i]; j++){
            v2.push_back(j);
        }
        auto pabaigaV2=std::chrono::high_resolution_clock::now();
        galutinisV2+=pabaigaV2-pradziaV2;
        cout<<"Vector laikas su "<<sz[i]<<" elementu: "<<galutinisV2.count()<<" s\n";
    }
}

void perskirstymu_testas(){
    int pV1=0, pV2=0;
    vector<Stud> studentai;
    std::ifstream fd("studentai10000000.txt");
    if (fd.fail()){
        throw std::runtime_error("Failas nerastas.");
    }
    std::stringstream ss;
    ss << fd.rdbuf();
    fd.close();
    string linija;
    std::getline(ss, linija);
    while (std::getline(ss, linija)){
        std::istringstream iss(linija);
        Stud laikinas(iss, "failas");
        if (studentai.size()==studentai.capacity()){
            pV1++;
        }
        studentai.push_back(laikinas);
    }

    Vector<Stud> studentai1;
    std::ifstream fd1("studentai10000000.txt");
    if (fd1.fail()){
        throw std::runtime_error("Failas nerastas.");
    }
    std::stringstream ss1;
    ss1 << fd1.rdbuf();
    fd1.close();
    string linija1;
    std::getline(ss1, linija1);
    while (std::getline(ss1, linija1)){
        std::istringstream iss1(linija1);
        Stud laikinas(iss1, "failas");
        if (studentai1.getSize()==studentai1.getCapacity()){
            pV2++;
        }
        studentai1.push_back(laikinas);
    }
    cout<<"std::vector perskirstymu kiekis: "<<pV1<<endl;
    cout<<"Vector perskirstymu kiekis: "<<pV2<<endl;
}