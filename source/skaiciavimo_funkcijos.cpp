#include "../include/skaiciavimo_funkcijos.h"

double vidurkis(vector<int> &pazymiai, int &egzaminas){
    if (pazymiai.size() == 0) {
        return egzaminas*0.6;
    }
    double vid = 0;
    for (int i=0; i<pazymiai.size(); i++){
        vid += pazymiai[i];
    }
    vid = vid/pazymiai.size()*0.4 + egzaminas*0.6;
    return vid;
}

double mediana(vector<int> &pazymiai, int &egzaminas){
    if (pazymiai.size() == 0) {
        return egzaminas*0.6;
    }
    double med = 0;
    std::sort(pazymiai.begin(), pazymiai.end());
    if (pazymiai.size() % 2 == 0) {
        med = double((pazymiai[pazymiai.size()/2 - 1] + pazymiai[pazymiai.size()/2])) / 2.0;
    } else {
        med = pazymiai[pazymiai.size()/2];
    }
    
    med = med*0.4 + egzaminas*0.6;
    return med;
}