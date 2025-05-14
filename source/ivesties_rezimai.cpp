#include "../include/ivesties_rezimai.h"
#include "../include/ivesties_tikrinimas.h"
#include "../include/skaiciavimo_funkcijos.h"
#include "../include/vartotojo_pasirinkimo_funkcijos.h"
#include "../include/isvesties_rezimai.h"
#include "../include/rikiavimo_funckija.h"

void strategija_1(vector<Stud> &studentai, vector<Stud> &vargsiukai, vector<Stud> &galvociai){
    for (Stud &studentas : studentai){
        if (studentas.getGalutinisVid()<5){
            vargsiukai.push_back(studentas);
        }
        else {
            galvociai.push_back(studentas);
        }
    }
    
    vargsiukai.shrink_to_fit();
    galvociai.shrink_to_fit();
}

void ranka(vector<Stud> &studentai) {
    cout << "Veskite duomenis apie studentus. Kai noresite baigti, iveskite 'n' kaip studento varda.\n";
    
    while (true) {
        Stud laikinas(std::cin, "ranka");
        
        if (laikinas.getVardas() == "n") {
            break;
        }
        
        studentai.push_back(laikinas);
    }
    
    isvesties_pasirinkimas(studentai);
    studentai.clear();
}

void pazymiu_generavimas (vector<Stud> &studentai){
    srand(time(NULL));
    cout<<"Veskite duomenis apie studentus. Kai noresite baigti, iveskite 'n' kaip studento varda.\n";
    while (true){
        Stud laikinas(std::cin, "pazymiu_generavimas");
        if (laikinas.getVardas() == "n"){
            break;
        }
        studentai.push_back(laikinas);
    }
    isvesties_pasirinkimas(studentai);
    studentai.clear();
}

void visko_generavimas (vector<Stud> &studentai){
    srand(time(NULL));
    int k=rand()%10+1;
    for (int i=0; i<k; i++){
        Stud laikinas(std::cin, "visko_generavimas");
        studentai.push_back(laikinas);
    }
    isvesties_pasirinkimas(studentai);
    studentai.clear();
}

void skaitymas_is_failo (vector<Stud> &studentai, string failas, bool testavimas){
    std::ifstream fd(failas);
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
        studentai.push_back(laikinas);
    }
    if (!testavimas){
        isvesties_pasirinkimas(studentai);
        studentai.clear();
    }    
}

void failu_generavimas(int n){
    string filename = "studentai" + std::to_string(n) + ".txt";
    std::ofstream fd(filename);

    if (!fd) {
        cout << "Nepavyko sukurti failo.\n";
        return;
    }

    fd<<std::left<< std::setw(15) <<"Vardas"<< std::setw(15) <<"Pavarde"<< std::setw(15) <<"ND1"<<std::setw(15) <<"ND2"<<std::setw(15) <<"ND3"<<std::setw(15) <<"ND4"<< std::setw(15) <<std::setw(15) <<"ND5"<<std::setw(15) <<"Egzaminas\n";

    srand(time(NULL));
    string vardas, pavarde;
    vector<int> pazymiai;
    int egzaminas;
    double galutinis_vid, galutinis_med;
    for (int i = 0; i < n; ++i) {
        vardas = "Vardas" + std::to_string(i + 1);
        pavarde = "Pavarde" + std::to_string(i + 1);
        int pazymiu_kiekis = 5;
        for (int j = 0; j < pazymiu_kiekis; ++j) {
            pazymiai.push_back(rand() % 10 + 1);
        }
        egzaminas = rand() % 10 + 1;
        galutinis_vid = vidurkis(pazymiai, egzaminas);
        galutinis_med = mediana(pazymiai, egzaminas);

        fd <<std::left<< std::setw(15) << vardas << std::setw(15)  << pavarde;
        for (int pazymys : pazymiai) {
            fd <<std::left<< std::setw(15) << pazymys << " ";
        }
        fd <<std::left<< std::setw(15) << egzaminas << "\n";
    }

    fd.close();
    cout << "Failas sukurtas: " << filename << "\n";
}

void studentu_skaitymas_ir_skirstymas_i_vargsiukus_ir_galvocius (vector<Stud> &studentai, string failas, std::chrono::duration<double>  &ivesties_suma, std::chrono::duration<double>  &rusiavimo_suma, std::chrono::duration<double>  &skirstymo_suma, int strategija/*, int pasirinkimas1, int pasirinkimas2, int pasirinkimas3, int pasirinkimas4*/){
    auto ivesties_pradzia=std::chrono::high_resolution_clock::now();
    skaitymas_is_failo(studentai, failas, true);
    auto ivesties_pabaiga=std::chrono::high_resolution_clock::now();
    ivesties_suma+=ivesties_pabaiga-ivesties_pradzia;
    auto rusiavimo_pradzia=std::chrono::high_resolution_clock::now();
    
    std::sort(studentai.begin(), studentai.end(), raktas_gv);
    
    auto rusiavimo_pabaiga=std::chrono::high_resolution_clock::now();
    rusiavimo_suma+=rusiavimo_pabaiga-rusiavimo_pradzia;
    auto skirstymo_pradzia=std::chrono::high_resolution_clock::now();
    vector<Stud> vargsiukai, galvociai;
    strategija_1(studentai, vargsiukai, galvociai);
    
    auto skirstymo_pabaiga=std::chrono::high_resolution_clock::now();
    std::ofstream fd("vargsiukai.txt");
    isvestis(fd, vargsiukai);
    fd.close();
    std::ofstream fd2("galvociai.txt");
    isvestis(fd2, galvociai);
    skirstymo_suma+=skirstymo_pabaiga-skirstymo_pradzia;
    vargsiukai.clear();
    galvociai.clear();
    studentai.clear();
}