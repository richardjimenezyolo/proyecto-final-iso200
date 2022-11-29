#include "stdio.h"
#include "team.c"

void printOptions() {
    printf("Presiona 'A' para anotar puntos a un jugador del equipo A \n");
    printf("Presiona 'B' para anotar puntos a un jugador del equipo B \n");
    printf("Presiona 'n' para continuar al siguiente tiempo\n");
}

int main() {
    struct Team teamA = createTeam('A');
    struct Team teamB = createTeam('B');

    int quater = 1;

    while (1) {
        printTeamScoreTable(teamA, quater);
        printTeamScoreTable(teamB, quater);
        printOptions();

       // Handle input
        char input;

        scanf("%c", &input);

        switch (input)
        {
        case 'A':
                addTeamPoints(&teamA);
            break;

        case 'B':
                addTeamPoints(&teamB);
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
            if (teamA.points == teamB.points) {
                printf("Hay un empate, ahora se jugara tiempo extra bla bla bla \n");
                quater++;
                continue;
            }

            if (teamA.points > teamB.points) {
                printf("Ganador: equipo %c, con {%d} pts \n", teamA.team, teamA.points);
            } else {
                printf("Ganador: equipo %c, con {%d} pts \n", teamB.team, teamB.points);
            }

            break;
        }
    }

    return 0;
}