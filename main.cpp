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

    while (quater <= 4) {
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
            quater++;
            break;
        default:
            break;
        }
    }

    return 0;
}