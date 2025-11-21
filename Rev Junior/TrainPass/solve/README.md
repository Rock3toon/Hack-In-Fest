## Introduzione
L’esecuzione inizia con la stampa di un messaggio e una breve animazione, poi viene letto un input dell’utente. Subito dopo, la lunghezza di tale input viene calcolata e divisa per due: questo valore determina il punto medio della stringa.
Il programma genera quindi una nuova sequenza derivata dall’input applicando un’operazione XOR su ciascun carattere. I caratteri nella prima metà (fino alla posizione mediana inclusa) vengono XORati con una chiave costante, mentre quelli nella seconda metà vengono XORati con una chiave diversa.
Il risultato di questa trasformazione viene poi confrontato byte per byte con un codice statico presente nel binario. Se i primi tredici caratteri coincidono, viene aperto un file esterno contenente la flag.
**Strumenti per solve:** (Ghidra, Ida, strings)

## Analisi
Osservando il codice statico memorizzato nel binario, è possibile notare che contiene tredici byte leggibili, apparentemente codificati. Poiché il programma applica un XOR differenziato sulla base della posizione, il problema si riduce a invertire questa operazione: trovare un input tale che, una volta sottoposto alla stessa trasformazione, produca esattamente la sequenza del codice memorizzato.
La lunghezza dell’input influenza il punto di separazione tra le due chiavi di XOR, quindi è necessario determinare una lunghezza che garantisca la giusta divisione tra le due parti. In questo caso, un input lungo tredici caratteri consente una separazione coerente, con i primi sette caratteri soggetti alla prima chiave e i restanti sei alla seconda.
Calcolando l’inverso dell’operazione XOR (che è la stessa operazione, dato che XOR è simmetrico), si ottiene la stringa corretta da fornire in input.

Una volta trovata la stringa giusta, basta eseguire il binario, attendere la simulazione di caricamento e inserire l’input calcolato. Il confronto andrà a buon fine e il programma aprirà il file con la flag, mostrando il suo contenuto a schermo.

## Conclusioni
La challenge ruota attorno a una semplice codifica XOR, mascherata da logica apparentemente più complessa.
Non sono presenti vulnerabilità di memoria sfruttabili: l’attacco è puramente logico e si basa sulla comprensione del flusso e sull’analisi inversa del codice macchina.

## Stringa nel Binario 
**sb`{f{?drdvzx**

## Soluzione
**apriti-sesamo**