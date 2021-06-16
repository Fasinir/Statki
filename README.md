# Statki
###
UWAGA!

Program został napisany pod system windows i pod środowisko Visual Studio
biblioteka z której korzystam (BASS) ma dedykowaną wersję na windowsa 
dodatkowo używam komend do czyszczenia konsoli (system("cls")) i komend z Windows.h

na 99% nie będzie działać poprawnie na innych systemach
na dole zamieściłem gameplay
####

Dzień dobry!
Niniejszy program implementuje klasyczną grę w statki dla dwóch osób. Dodatkową funkcją która spełnia program jest
odtwarzanie dźwięków w zależności od sytuacji (strzał trafiony/nietrafiony). Tę funkcję umożliwiła biblioteka BASS.

w StatkiVSC.cpp zapisane są parametry takie jak:
-wymiary planszy
-informacje czy gracze są ludźmi czy AI
-liczba i rodzaje statków

Gra rozpoczyna się od losowania pierwszego gracza, następnie obaj gracze naprzemiennie ustawiają statki
na swoich planszach, a kolejnym etapem jest etap wczytywania ruchów. Gra trwa dopóki jeden z graczy nie straci wszystkich statków.

Przykładowy gameplay 
https://www.youtube.com/watch?v=9qYQklffxsc

Pozdrawiam
Filip Piwosz