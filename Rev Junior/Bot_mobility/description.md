# **Bot_Mobility**
La nuova ditta che mette a disposizione monoppatini elettrici Bot_mobility ha un limitatore di velocità seconbdo il codice della strada. Ci sarà forse un modo per andare più veloce?


## Obbiettivo
Reversa il binario per trovare il codice numerico che il programma accetta come autorizzazione. Inserendo il codice corretto il programma passerà in modalità “autorizzata” e mostrerà la flag (la prova che potresti cambiare i limiti di velocità). Non è richiesta alcuna interazione hardware: lavora sul binario fornito.

## Hint
Il codice non è una password alfanumerica: è un valore intero calcolato internamente dal programma a partire da costanti hardcoded e semplici operazioni aritmetiche/bitwise (XOR, somme).
Usa strumenti di static analysis (Ghidra, IDA, radare2) per identificare le costanti e seguire il flusso subito dopo la lettura dell’input.
Presta attenzione ai tipi usati (unsigned vs signed) e ai controlli sui range: il programma effettua anche confronti che possono rivelare vincoli utili per il bruteforce o per l’analisi simbolica.
Prova a cercare pattern come scanf, fopen/fgets e confronti che portano all’apertura di un file: quello è il punto in cui viene mostrata la flag se il codice è valido.
Se sei bloccato, traccia passo-passo le operazioni sulle variabili che sembrano avere nomi strani: spesso sono solo etichette generate dal decompiler per costanti utilizzate nel calcolo del codice.