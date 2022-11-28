#include <iostream>
#include "team.cpp"


void printOptions() {
    std::cout << "Presiona 'A' para anotar puntos a un jugador del equipo A \n";
    std::cout << "Presiona 'B' para anotar puntos a un jugador del equipo B \n";
    std::cout << "Presiona 'n' para continuar al siguiente tiempo\n";
}

int main() {
    Team teamA = Team('A');
    Team teamB = Team('B');

    teamA.initializeTeam();
    teamB.initializeTeam();


    int quater = 1;

    while (1) {
        teamA.printScoreTable(quater);
        teamB.printScoreTable(quater);
        printOptions();
       
       // Handle input
        char input;

        std::cin >> input;

        switch (input)
        {
        case 'A':
            teamA.addPoints();
            break;

        case 'B':
            teamB.addPoints();
            break;
        
        case 'n':
            if (quater < 5) {
                quater++;
            }
            break;
        default:
            break;
        }

        if(quater == 5) {
            if (teamA.getPoints() == teamB.getPoints()) {
                std::cout << "Hay un empate, ahora se jugara tiempo extra bla bla bla \n";
                quater++;
                continue;
            }

            if (teamA.getPoints() > teamB.getPoints()) {
                std::cout << "Ganador: equipo " << teamA.team << ", con {" << teamA.getPoints() << "} pts \n";
            } else {
                std::cout << "Ganador: equipo " << teamB.team << ", con {" << teamB.getPoints() << "} pts \n";
            }

            break;
        }
    }

    return 0;
}