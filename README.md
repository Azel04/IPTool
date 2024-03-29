
  
  

# IPTool

IPtool è un piccolo programma per la creazione di sottoreti con FLSM e VLSM.

  

1. [x] Conversione IP da decimale a binario

2. [x] Controllo IP Pubblico e privato con classe IP

3. [x] Calcolo del NetID, Broadcast, Gateway, Range per indirizzi di classe C, dato il numero di sottoreti.

4. [x] Calcolo del NetID, Broadcast, Gateway, Range per indirizzi di classe B, dato il numero di sottoreti.

5. [x] Riscrivere il codice utilizzando file header

6. [x] Supporto a Subnet Mask variabili

7. [x] Supporto notazione CIDR

8. [x] Controllare se 2 indirizzi ip appartengono alla stessa subnet

9. [x] Supporto al Supernetting

## Chiusura del progetto IPTool:
Sono passati quasi 2 anni da quando ho iniziato a sviluppare questo programma e, anche se non è stato supportato per niente negli ultimi tempi, mi è servito per imparare di più sull'ottimizzazione del software e sono migliorata come programmatrice.

Iniziai questo progetto come una sfida verso me stessa e verso un mio amico (ciao Marco Pagnanini) che aveva creato un programma simile a Settembre del 2021. Da li il nostro professore ci ha dato come compito la creazione di questo programma.
Ho passato giorni e giorni all'inizio per risolvere bug, ottimizzare il programma e aggiungere funzionalità fino a quando non l'ho consegnato a Gennaio del 2022.
Anche se questo programma non è il migliore del mondo, sono estremamente soddisfatta di quello che sono riuscita a fare in quei mesi.

Chiudo con dei ringraziamenti.

Ringrazio Marco Pagnanini per avermi spinto (involontariamente) a creare questo progetto e per avermi aiutato nella sua creazione.
Ringrazio Imbimbo Francesco e Romagnoli Luigi per avermi dato questo compito da fare e per avermi insegnato tutti questi argomenti in 3 anni. Siete stati probabilmente gli unici professori veramente utili e corretti della scuola.
Ringrazio Andrea Cazzato per aver testato il programma.
E infine, ringrazio tutta la classe che mi ha accompagnata in questi 3 anni.

Con questo messaggio chiudo definitivamente il progetto IPTool.

Grazie.
- Celeste Rossetti

## Changelog
#### 05-08-2023
 1. Ottimizzato algoritmo per conversione da decimale a binario (passaggio da operazione semplice a operazione bitwise più veloce)
 2. Cambiato lo stato del supporto al supernetting da BETA a Stabile
 3. Rilasciata versione 1.0.6 (Ultima versione)
#### 18-02-2022
 1. Sostituito algoritmo di creazione sottoreti con uno che si basa interamente su file. 
 2. Cancellati i creatori di sottoreti senza file
 3. Bug Fix vari
 4. Rilasciata versione 1.0.5
#### 05-02-2022
 1. Aggiunto output su file per Supernetting.
 2. Cambiato lo stato del supporto al supernetting da SPERIMENTALE a BETA
 3. Rilasciata versione 1.0.4
#### 04-02-2022
 1. Migliorato l'algoritmo del Supernetting
#### 31-01-2022
 1. Risolto bug sul calcolo delle sottoreti in VLSM per tutte le classi
 2. Rilasciata versione 1.0.3
#### 29-01-2022
 1. Aggiunto supporto per il supernetting in FLSM (la funzione è ancora sperimentale).
#### 23-01-2022
 1. Risolto un piccolo bug sul calcolo dei bit necessari per una sottorete in VLSM
 2. Rilasciata versione 1.0.2-1
#### 22-01-2022
 1. Cambiato l'algoritmo per controllare la possibilità di una richiesta nel VLSM.
 2. Sono stati aggiunti gli array dinamici per gli indirizzi di classe B e A in VLSM
 3. Rilasciata versione 1.0.2
#### 20-01-2022
 1. Risolto un bug sul calcolo del numero massimo di sottoreti in Classe A FLSM
 2. Rilasciata versione 1.0.1
#### 17-01-2022
 1. Risolto un bug riguardante il calcolo dei bit necessari alla rete sul generatore di sottoreti in classe C FLSM
#### 15-01-2022
 1. Risolto un bug sull'output degli indirizzi in classe A sull'FLSM
 2. Prima release pubblica (1.0.0)
#### 08-01-2022
 1. Aggiunto output su file
 2. Bug fix vari
#### 03-12-2021
 1. Risolto il bug della pulizia dello schermo su Windows
 2. Bug fix generali.
#### 02-12-2021

 1. Aggiunti controlli per verificare la possibilità di una richiesta sul VLSM
 2. Cambiato i nomi di diverse variabili
 3. Bug fix generali

#### 26-11-2021

1. Aggiunta visualizzazione della Subnet Mask sul VLSM

2. Aggiunto calcolo dell'ultimo host in base all'input

3. Bug fix vari

#### 25-11-2021

1. Aggiunto supporto a Subnet Mask variabili (VLSM).

2. Separato il file header per creare le funzioni in 2 file header, 1 per tipo (FLSM, VLSM).

3. Risolti i warning generati dai return 0.

4. Bug fix vari.

#### 19-11-2021

1. Bug fix vari.

#### 18-11-2021

1. Aggiunta funzione per controllare se 2 indirizzi ip appartengono alla stessa subnet

2. Aggiunte funzioni per il calcolo delle sottoreti con host.

#### 17-11-2021

1. Risolto un bug sul calcolo del primo host delle reti di classe A e B

#### 16-11-2021

1. Aggiunto calcolo della subnet mask per il FLSM

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

## Bug riconosciuti
Per il momento non ci sono bug riconosciuti da me, se trovate un bug segnalatemelo
## Istruzioni per la compilazione

#### Linux:

Programmi necessari: gcc

1. Clonare questa repository (Tramite il sito o con git)

2. Copiare tutti i file .c e .h in una cartella

3. Aprire un terminale sulla cartella dove sono presenti tutti i file .c e .h

4. Eseguire questo comando: `gcc main.c -o IpTool -lm`

#### Windows:

Programmi necessari: MinGW 64bit (Do per scontato che abbiate inserito la cartella di installazione nelle variabili di ambiente di Windows)

1. Clonare questa repository (Tramite il sito o con git)

2. Copiare tutti i file .c e .h in una cartella

3. Aprire un terminale sulla cartella dove sono presenti tutti i file .c e .h

4. Eseguire questo comando: `gcc main.c -o IpTool.exe -lm`

## Note aggiuntive:
#### Uso di altri compilatori:

Non ho provato a compilare e utilizzare il programma con altri compilatori come Clang. 
La compilazione del programma con altri compilatori è permessa ma non è ufficialmente supportata, potrebbero emergere dei bug che su GCC non si verificano.
Ovviamente proverò in futuro altri compilatori ma attualmente non è la mia priorità.
