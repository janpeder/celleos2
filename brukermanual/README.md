# Brukermanual for Celleos

I denne mappa ligger filene som brukes for å generere brukermanualen i PDF-format.

### Instruksjoner for å bygge brukermanualen
For å bygge brukermanualen må du først installere nødvendig programvare. Instruksjonene under antar at du bruker en datamaskin med Debian Linux.

For å installere de nødvendige programpakkene skriv følgende (som root-bruker):
```
apt update
apt install build-essential texlive texlive-plain-generic texlive-pictures
```

Nå kan du bygge brukermanualen. For å bygge, skriv
```
make
```
