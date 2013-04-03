Rapport
=======

# Klasser
Programmet er satt opp mye på samme måte som rammeverket. Grunnlaget for dette er å holde en relativt lik kode-"standard".

Programmets main metode befinner seg i tictactoe.cpp, som kaller på class_tictactoeGame.
Alle klassene som det er hensiktsmessig å gjøre det for har sine egne headerfiler med prototyper av funksjoner og variable.

![alt text](https://github.com/larhauga/tictactoe/raw/master/tictactoe.png)

## Kort beskrivelse av klassene
### Class_tictactoeGame
Denne klassen inneholder selve spillogikken, og håndterer printing til terminal og oppsett av spillet. Det er også her input foregår.

### Class_board
Board er selve brettet. Denne har funksjoner som oppretter brettet, plaserer brkker på brettet og kan sjekke om noen vinner.

### Class_space
Space er den plassen hvor brikkene kan plaseres på. Dette objektet ved hvilken type brikke som er plasert, og av hvem den er plassert der av.

### Class_player
Player er selve spilleren og er et objekt som inneholder id, brikketype og navn.


#Svakheter i implementasjonen
 - Ulogisk navngivning av x- og y- koordinater
 - Burde vært implementert gameState eller liknende
 - AI kunne vært en bedre AI

## Ulogisk navngiving
Under konstruksjonen av vektoren og klassen for brettet ble det navngitt motsatt av det som faktisk ble strukturert i vektoren.
Brettet er bygget opp av en vektor av vektor, men x vectoren (som er den første) tilsvarer på egentlig y på en akse hvis man modellerer vektoren.
Dette er løst ved å bytte om på input fra bruker.

## Implementering av state
For å gjøre det mer effektivt og ikke minst enklere å utvikle blant annet AI burde det vært et state som holder styr på hva som er det siste som har skjedd og hvem som har gjort dette.
Problemet nå er at man ikke vet hvilken brikke som er den siste.
En måte å lage en AI på dette nivået (eventbasert og ikke relatime) er å benytte en algoritme kaldt minimax. (http://forum.codecall.net/topic/37522-need-help-with-simple-c-tictactoe-game-with-ai/?p=333855)
Denne kom jeg over alt for sent slik at jeg ikke fikk sett på mulighetene ved å implementere dette.

## AI kunne vært bedre til å være AI
Nå er ikke AIen veldig smart. Men det er mange alternativer for hvordan AIen skal oppføre seg. Det er jo ikke alltid man ønsker at datamaskinen skal spille optimalt.

