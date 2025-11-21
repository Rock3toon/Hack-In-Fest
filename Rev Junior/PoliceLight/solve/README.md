## Write-Up
Avviando l'eseguibile ci rendiamo subito conto che qualcosa non va: qualunque scelta facciamo, il programma si chiude.
Notiamo però che sia nell’eseguibile sia nella cartella della challenge viene richiesta una "`chiave di sicurezza`".
Analizzando il binario (tramite `Ghidra` o `Ida`)emergono diverse funzioni. Partendo dal `main` si nota che non conduce a nulla: il programma è costruito per terminare indipendentemente dall’input.
Iniziamo quindi ad analizzare tutte le altre funzioni, prestando particolare attenzione a quelle apparentemente non utilizzate.
Così facendo troviamo una `stringa` strana, trasformata in qualche modo: [>?E4C=L}@E020u=28N], e una `funzione` che non viene mai chiamata né dal `main` né da altre routine usate.
Analizzando con cura quella funzione, scopriamo che implementa un algoritmo di cifratura `ROT47`.
A questo punto prendiamo la stringa nell’ordine in cui appare, la concateniamo ed eseguiamo la decodifica (per esempio con `CyberChef` o usando la stessa funzione trovata nel binario). Otteniamo la stringa: [mntcrl{Not_a_Flag}].
Quella è la chiave per aprire il file `.zip` nella cartella della challenge; all’interno troveremo la `flag`.