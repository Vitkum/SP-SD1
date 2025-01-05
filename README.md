# SP-SD1: Versija v1.0

## Aprašymas
Šioje versijoje buvo optimizuotas studentų skirstymas į dvi grupes: "vargšiukai" ir "kietiakai". Realizuotos dvi strategijos:
1. Skirstymas į du naujus konteinerius (mažiau efektyvu).
2. Skirstymas naudojant vieną papildomą konteinerį ir pašalinant "vargšiukus" iš pagrindinio sąrašo.

## Funkcijos
- **Failų generavimas**: Automatiškai sugeneruoja duomenų failus su studentų įrašais.
- **Studentų skirstymas**: Skirsto studentus į grupes pagal galutinį balą.
- **Veikimo greičio analizė**: Matavimo įrankis skirtingoms strategijoms ir konteineriams.

## Paleidimas
1. Sugeneruokite duomenų failus:
   ```bash
   g++ FailuGeneravimas.cpp -o generuoti
   ./generuoti
