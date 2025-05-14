#include "../include/studentas.h"
#include "../include/ivesties_tikrinimas.h"
#include "../include/skaiciavimo_funkcijos.h"

Stud::Stud(std::istream& is, string rezimas) { 
    readStudent(is, rezimas);  
}

std::istream& Stud::readStudent(std::istream& is, string rezimas) {
    string tekstas;
    if (rezimas=="ranka" || rezimas=="pazymiu_generavimas") {    
        tekstas = "Iveskite studento varda: ";
        ivesties_tikrinimas(vardas, tekstas);
        if (vardas == "n") {
            return is;
        }
        
        tekstas = "Iveskite studento pavarde: ";
        ivesties_tikrinimas(pavarde, tekstas);
    }
    if (rezimas=="ranka") {
        cout << "Veskite jo pazymius. Kai noresite baigti, iveskite '0'.\n";
        while (true) {
            tekstas = "Iveskite pazymi: ";
            int pazymys;
            ivesties_tikrinimas(pazymys, tekstas);
            
            if (pazymys == 0) {
                break;
            }
            else if (pazymys < 0 || pazymys > 10) {
                cout << "Neteisingas pazymys. Bandykite dar karta.\n";
                continue;
            }
            pazymiai.push_back(pazymys);
        }
        
        tekstas = "Iveskite studento egzamino pazymi: ";
        ivesties_tikrinimas(egzaminas, tekstas);
        while (egzaminas < 0 || egzaminas > 10) {
            cout << "Neteisingas pazymys. Bandykite dar karta.\n";
            ivesties_tikrinimas(egzaminas, tekstas);
        }
        
        skaiciuotiGalutini();
    }    

    if (rezimas=="visko_generavimas") {
        vector<string> vyriskiVardai = {
            "Jonas", "Petras", "Marius", "Tadas", "Rokas", "Darius", "Arnas", "Justas", "Edvinas", "Tomas",
            "Paulius", "Simas", "Lukas", "Andrius", "Rytis", "Ernestas", "Giedrius", "Mantas", "Deividas", "Vilius",
            "Mindaugas", "Martynas", "Saulius", "Vytautas", "Tautvydas", "Sigitas", "Algirdas", "Gintaras", "Julius", "Remigijus",
            "Kestas", "Vaidotas", "Audrius", "Augustas", "Nerijus", "Gediminas", "Raimundas", "Juozas", "Dainius", "Arvydas",
            "Evaldas", "Zygimantas", "Vytenis", "Laurynas", "Arminas", "Rolandas", "Alvydas", "Laimonas", "Dominykas", "Tautvilas"
        };
        
        vector<string> moteriskiVardai = {
            "Ona", "Ieva", "Lina", "Egle", "Asta", "Rima", "Greta", "Aiste", "Monika", "Laura",
            "Jurgita", "Dovile", "Karolina", "Viktorija", "Gabija", "Sandra", "Vaida", "Aurelija", "Kristina", "Evelina",
            "Ruta", "Egle", "Aiste", "Indre", "Diana", "Viktorija", "Marija", "Aldona", "Gintare", "Alina",
            "Birute", "Rita", "Raimonda", "Virginija", "Irena", "Jolanta", "Solveiga", "Vilma", "Lijana", "Agnė",
            "Saulė", "Nida", "Grazina", "Danutė", "Liuda", "Daiva", "Jadvyga", "Sigita", "Jonė", "Vaida"
        };
        
        vector<string> vyriskosPavardes = {
            "Kazlauskas", "Petrauskas", "Jankauskas", "Paulauskas", "Butkus", "Navickas", "Sabonis", "Rimkus", "Grigas", "Urbonas",
            "Brazinskas", "Šimkus", "Pocius", "Žukauskas", "Daukantas", "Blaževičius", "Stankūnas", "Grybauskas", "Vaičiulis", "Vaitkus",
            "Rutkauskas", "Tamulis", "Kudirka", "Bagdonas", "Pavardenis", "Morkūnas", "Noreika", "Dapkus", "Žilinskas", "Venckus",
            "Kairys", "Janušaitis", "Andriuškevičius", "Šimaitis", "Mockus", "Vaitkevičius", "Matulionis", "Aleknavičius", "Valančius", "Račkauskas",
            "Giedraitis", "Petkevičius", "Radzevičius", "Žiogas", "Kalvaitis", "Baranauskas", "Masiulis", "Gervė", "Balčiūnas", "Mačiulis"
        };
        
        vector<string> moteriskosPavardes = {
            "Kazlauskaitė", "Petrauskaitė", "Jankauskaitė", "Paulauskaitė", "Butkutė", "Navickaitė", "Sabonytė", "Rimkutė", "Grigaitė", "Urbonaitė",
            "Brazinskaitė", "Šimkutė", "Pociūtė", "Žukauskaitė", "Daukantaitė", "Blaževičiūtė", "Stankūnaitė", "Grybauskaitė", "Vaičiulienė", "Vaitkienė",
            "Rutkauskaitė", "Tamulytė", "Kudirkaitė", "Bagdonaitė", "Morkūnaitė", "Noreikaitė", "Dapkutė", "Žilinskaitė", "Venckutė", "Kairytė",
            "Janušaitė", "Andriuškevičiūtė", "Šimaitė", "Mockutė", "Vaitkevičiūtė", "Matulionytė", "Aleknavičiūtė", "Valančiūtė", "Račkauskaitė", "Giedraitė",
            "Petkevičiūtė", "Radzevičiūtė", "Žiogaitė", "Kalvaitė", "Baranauskaitė", "Masiulytė", "Balčiūnaitė", "Mačiulytė", "Gervaitė", "Daukšytė"
        };

        int lytis=rand()%2, v=rand()%50, p=rand()%50;
        if (lytis==0){
            vardas=vyriskiVardai[v];
            pavarde=vyriskosPavardes[p];
        }
        else {
            vardas=moteriskiVardai[v];
            pavarde=moteriskosPavardes[p];
        }
    }

    if (rezimas=="pazymiu_generavimas" || rezimas=="visko_generavimas") {
        int n = rand() % 10 + 1;
        for (int j = 0; j < n; j++) {
            int pazymys = rand() % 10 + 1;
            pazymiai.push_back(pazymys);
        }
        egzaminas = rand() % 10 + 1;
        skaiciuotiGalutini();
    }

    if (rezimas=="failas") {
        is >> vardas >> pavarde;
        int pazymys;
        while (is >> pazymys){
            pazymiai.push_back(pazymys);
        }
        egzaminas=pazymiai.back();
        pazymiai.pop_back();
        skaiciuotiGalutini();
    }
    
    return is;
}

void Stud::skaiciuotiGalutini() {
    galutinis_vid = vidurkis(pazymiai, egzaminas);
    galutinis_med = mediana(pazymiai, egzaminas);
}