# :hammer_and_wrench: Kompiliavimo instrukcijos

1. Atsisiųsti [MinGW make](https://sourceforge.net/projects/mingw/)
2. Klonuoti projekto direktoriją
3. Į komandinę eilutę įvesti komandą ```mingw32-make```
4. Aplanke, kuriame klonavote direktoriją, paleisti failą ***program.exe***

# :keyboard: Naudojimosi instrukcijos

Atsidarę programą turėsite 9 pasirinkimus:
1. Duomenų įvedimas ranka – turėsite vesti studentų vardus, pavardes, pažymius ir egzamino įvertinimą tiek kartų, kiek norėsite
2. Pažymiu generavimas – turėsite vesti tik studentų vardus ir pavardes, pažymiai kiekvienam studentui bus atsitiktinai sugeneruoti
3. Pažymiu ir vardų generavimas – visi duomenys apie studentus bus sugeneruoti (vardai ir pavardės atsitiktini iš fiksuoto sąrašo)
4. Skaityti duomenis iš failo – studentų konteineris užpildomas duomenimis iš norimo failo
5. Testuoti įvesties laiką – tikrinama, kiek užtrunka įvesti duomenis iš norimo failo
6. Kurti failą ir testuoti jo sukurimo laiką – galite pasirinkti, kokio dydžio studentų failą sugeneruosite
7. Skirstyti studentus iš failo į vargšiukus ir galvočius – iš anksčiau sugeneruotų failų vykdomas skirstymas pagal vidurkį ir jo metu testuojama įvesties trukmė, rikiavimas ir skirstymas
8. Testuoti Stud klasės metodus
9. Baigti darbą

# :notebook_with_decorative_cover: Klasės aprašymas ir naudojimosi instrukcijos

### Aprašymas

Klasė Stud, su kuria dirbama projekte, yra išvestinė iš bazinės klasės Zmogus. Zmogus turi reikšmes vardas ir pavardė, o Stud klasė papildo likusiomis (pažymiais, egzamino įvertinimu, vidurkiais).

### Įvesties operatorius

Galite ranka vesti studento vardą, pavardę ir tiek pažymių, kiek norite, tik reikia nurodyti įvedimo pabaigą įrašant pažymį -1. Tuomet reikia įvesti dar vieną skaičių - egzamino pažymį. Jeigu vedate iš failo, bus nuskaitomas vardas, pavardė ir pažymiai bei egzaminas be poreikio atskirti egzaminą nuo pažymių skaičiumi -1.

### Išvesties operatorius

Išvedamas studento vardas, pavardė ir galutiniai pažymiai pagal vidurkį bei medianą kiekvienam duomeniui suteikiant po 25 laukelius ir rikiuojant kairėje.

# :chart: V3.0 Testavimas

| Konteineris | Greitis 10000 | Greitis 100000 | Greitis 1000000 | Greitis 10000000 | Greitis 100000000 |
| ----------- | ------------- | -------------- | --------------- | ---------------- | ----------------- |
| std::vector | 0 s | 0.0010051 s | 0.0040315 s | 0.0425115 s | 0.389473 s |
| Vector | 0 s | 0.0005066 s | 0.0030259 s | 0.0273958 s | 0.353859 s |

Visais atvejais mano sukurtas konteineris yra greitesnis nei std::vector.
Abu konteineriai yra perskirstomi 25 kartus, kai vedami 10 milijonų studentų.

# :chart: V1.1 Testavimas

| Optimizavimo flag | Greitis 100000 (struct) | Greitis 1000000 (struct) | Failo dydis | Greitis 100000 (class) | Greitis 1000000 (class) | Failo dydis |
| ----------------- | ----------------------- | ------------------------ | ----------- | ---------------------- | ----------------------- | ----------- |
| Jokios | 1.3192 s | 16.5731 s | 639 KB | 1.4731 s | 21.7279 s | 408 KB |
| O1 | 0.265992 s | 3.62595 s | 315 KB | 0.35424 s | 4.47669 s | 209 KB |
| O2 | 0.317195 s | 3.70015 s | 275 KB | 0.348022 s | 3.93707 s | 199 KB |
| O3 | 0.307315 s | 3.83817 s | 272 KB | 0.353762 s | 4.47141 s | 203 KB |


# :chart: V1.0 Testavimas

Programa buvo ištestuota pagal tris strategijas ir su trimis konteineriais:
- Vector
- List
- Deque

>[!NOTE]
>Visų testų laikai pateikti iš 5 bandymų vidurkio.

### Rezultatai

Efektyviausia strategija buvo pirmoji, tikėtina dėl to, kad duomenų trinimas iš konteinerių užtrunka ilgai.

Visi konteineriai buvo maždaug vienodai efektyvūs.

### Sistemos specifikacijos: 
- CPU: AMD Ryzen 7 7840HS with Radeon 780M Graphics
- RAM: 32 GB 3200MHz LPDDR5
- SSD: SKHynix_HFS001TEJ9X115N 

### 1 strategija:

#### Vector testavimas

![image](https://github.com/user-attachments/assets/260c62a3-c532-44a8-9071-986b1255aa1d)
</br>

#### List testavimas

![image](https://github.com/user-attachments/assets/11715b4d-bd7f-4186-95b7-10fa77586269)
</br>

#### Deque testavimas

![image](https://github.com/user-attachments/assets/a2461b7f-4de6-4527-81d6-5e12dcf0c8c0)
</br></br>

### 2 strategija:

#### Vector testavimas

![image](https://github.com/user-attachments/assets/8c824515-7748-4838-85ea-2201df3a00fb)
</br>

#### List testavimas

![image](https://github.com/user-attachments/assets/6cf44ee7-a67d-4a0f-9357-9d34e80754df)
</br>

#### Deque testavimas

![image](https://github.com/user-attachments/assets/3be433a5-e6af-48bf-9ca4-7e445214f2c5)
</br>

### 3 strategija

#### Vector testavimas

![image](https://github.com/user-attachments/assets/b95058de-07c4-4ec8-bb96-9de3f103dadd)
</br>

#### List testavimas

![image](https://github.com/user-attachments/assets/bdaca316-f979-4962-9bbb-294131e28021)
</br>

#### Deque testavimas

![image](https://github.com/user-attachments/assets/7c077a3d-12de-4715-b0c4-2c38a9c675f2)

