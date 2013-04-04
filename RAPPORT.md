Rapport
=======

# Klasser
Programmet er satt opp mye på samme måte som rammeverket. Grunnlaget for dette er å holde en relativt lik kode-*"standard"*.

Programmets main metode befinner seg i *tictactoe.cpp*, som kaller på *class_tictactoeGame*.
Alle klassene som det er hensiktsmessig å gjøre det for har sine egne headerfiler med prototyper av funksjoner og variable.

![alt text](https://github.com/larhauga/tictactoe/raw/master/tictactoe.png)

## Kort beskrivelse av klassene
### Class_tictactoeGame
Denne klassen inneholder mye av **logikken** for spillet. 
 * Oppsett av spillet (spillere, brett og andre nødvendigheter)
 * Håndterer flere runder
 * Holder orden på hvilken bruker sin tur det er
 * All printing til terminal
 * To forskjellige type spillere. Datamaskin eller menneske.
 * Mulig å simulere maskin-mot-maskin

### Class_board
Board er selve brettet. Denne har en vector av en vector med spaces. 

Brettklassens viktigste funksjoner:
 * Oppretter brettet
 * Plasserer brikker på brettet
 * Sjekker etter en vinner
 * Strategi for neste mulige brikke. Denne benyttes av AI.

### Class_space
Space er den plassen hvor brikkene kan plaseres på. 
Dette objektet vet hvilken type brikke som er plasert, og av hvem den er plassert der av.
 * Håndterer innsetting av spillerens brikke
 * Returfunksjoner for private variable

### Class_player
Player er selve spilleren og er et objekt som inneholder id, brikketype og navn.


#Svakheter i implementasjonen
 - Ulogisk navngivning av x- og y- koordinater
 - Burde vært implementert gameState eller liknende
 - AI kunne hatt en bedre stategi
 - Dårlig funksjonell struktur

## Ulogisk navngiving
Under konstruksjonen av vektoren og klassen for brettet ble det navngitt motsatt av det som faktisk ble strukturert i vektoren.
Brettet er bygget opp av en vektor av vektor, men x vectoren (som er den første) tilsvarer på egentlig y på en akse hvis man modellerer vektoren.
Dette er løst ved å bytte om på input fra bruker.

## Implementering av state
For å gjøre det mer effektivt og ikke minst enklere å utvikle blant annet AI burde det vært et state som holder styr på hva som er det siste som har skjedd og hvem som har gjort dette.
Problemet nå er at man ikke vet hvilken brikke som er den siste.
En måte å lage en AI på dette nivået (eventbasert og ikke relatime) er å benytte en algoritme kaldt minimax. (http://forum.codecall.net/topic/37522-need-help-with-simple-c-tictactoe-game-with-ai/?p=333855)
Denne kom jeg over alt for sent slik at jeg ikke fikk sett på mulighetene ved å implementere dette.

## AI kunne hatt en bedre strategi
AIen vil som regel vinne på mindre brett hvis den får muligheten til det. Problemet begynner når det er veldig store brett. Da er sannsynligheten for at ingen vinner veldig mye større på grunnlaget av at AI da spiller veldig mye tilfeldig. Den vil derimot jobbe for å stoppe brukeren hvis den har mindre enn nødvendige på rad, og dette vil gjøre det umulig å vinne uten å få en fork.
Metodene som nå styrer AI vil prøve å plassere brikker veldig tilfeldig, med mindre spesialtilfeller intreffer. Spesialtilfellene er her hvis datamaskinen starter, motspiller mangler en brikke for å få n på rad, eller datamaskinen mangler en til for å få n på rad.

## Dårlig funksjonell struktur
Ettersom programmet har blitt større har det blitt problemer med plassering av en del kode.
Strukturen burde inneholdt elementer som "state", "action" og ikke minst en "strategy".
Slik det er nå er mye av den logiske strategien og funksjonelle metoder plassert på brettet, der de egentlig ikke har noe å gjøre.

