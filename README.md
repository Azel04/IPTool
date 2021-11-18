

# IPTool
IP tool è uno strumento per convertire indirizzi ip da Decimale a Binario e per controllare se l'indirizzo è pubblico o privato.

 1. [x] Conversione IP da decimale a binario
 2. [x] Controllo IP Pubblico e privato con classe IP
 3. [x] Calcolo del NetID, Broadcast, Gateway, Range per indirizzi di classe C
 4. [x] Calcolo del NetID, Broadcast, Gateway, Range per indirizzi di classe B (Testatelo anche voi, sembrerebbe funzionare)
 5. [x] Calcolo del NetID, Broadcast, Gateway, Range per indirizzi di classe A (Testatelo anche voi, sembrerebbe funzionare)
 6. [x] Calcolo NetID in binario per indirizzi di classe C
 7. [ ] Calcolo NetID in binario per indirizzi di classe B
 8. [ ] Calcolo NetID in binario per indirizzi di classe A
 9. [x] Riscrivere il codice utilizzando file header 
 10. [ ] Supporto a Subnet Mask variabili
 11. [x] Supporto notazione CIDR
 12. [x] Controllare se 2 indirizzi ip appartengono alla stessa subnet
## Changelog
#### 18-11-2021
 1. Aggiunta funzione per controllare se 2 indirizzi ip appartengono alla stessa subnet
#### 17-11-2021
 1. Risolto un bug sul calcolo del primo host delle reti di classe A e B
#### 16-11-2021
 1. Aggiunto calcolo della subnet mask
 2. Aggiunto contatore sottoreti per classi A e B
 3. Bug fix vari
#### 15-11-2021
 1. Pulizia generale del codice.
 2. Bug fix vari
#### 14-11-2021
 1. Sostituito algoritmo del calcolo delle sottoreti con indirizzi di classe B e A con uno più funzionale (Manipolazione dei bit diretta).
 2. Bug fix vari
#### 23-10-2021
 1. Aggiunto supporto basilare per il calcolo delle sottoreti con indirizzi di classe A e B.
 2. Bug fix vari
#### 24-09-2021
 1. Prima versione
## Istruzioni per la compilazione
#### Linux:
Programmi necessari: gcc
 1. Clonare questa repository (Tramite il sito o con git)
 2. Copiare tutti i file .c e .h in una cartella
 3. Aprire un terminale sulla cartella dove sono presenti tutti i file .c e .h
 4. Eseguire questo comando: `gcc main.c -o IpTool -lm`
#### Windows:
Programmi necessari: MinGW 64bit
 1. Clonare questa repository (Tramite il sito o con git)
 2. Copiare tutti i file .c e .h in una cartella
 3. Aprire un terminale sulla cartella dove sono presenti tutti i file .c e .h
 4. Eseguire questo comando: `gcc main.c -o IpTool.exe -lm`
#### Note aggiuntive per Windows:
Visto che uso Linux come sistema operativo principale, non ho testato questo programma su Windows.
Se possibile non utilizzate Dev-C++ visto che utilizza un compilatore vecchio.
Se volete essere sicuri, compilate e eseguite questo programma su un compilatore online come Repl o OnlineGDB.
