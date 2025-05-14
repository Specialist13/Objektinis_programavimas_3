#include "../include/skaiciavimo_funkcijos.h"

double vidurkis(Vector<int> &pazymiai, int &egzaminas){
    if (pazymiai.getSize() == 0) {
        return egzaminas*0.6;
    }
    double vid = 0;
    for (int i=0; i<pazymiai.getSize(); i++){
        vid += pazymiai[i];
    }
    vid = vid/pazymiai.getSize()*0.4 + egzaminas*0.6;
    return vid;
}

double mediana(Vector<int> &pazymiai, int &egzaminas){
    if (pazymiai.getSize() == 0) {
        return egzaminas*0.6;
    }
    double med = 0;
    std::sort(pazymiai.begin(), pazymiai.end());
    if (pazymiai.getSize() % 2 == 0) {
        med = double((pazymiai[pazymiai.getSize()/2 - 1] + pazymiai[pazymiai.getSize()/2])) / 2.0;
    } else {
        med = pazymiai[pazymiai.getSize()/2];
    }
    
    med = med*0.4 + egzaminas*0.6;
    return med;
}