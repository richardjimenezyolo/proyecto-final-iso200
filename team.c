#include "stdio.h"
#include "player.c"
#include <stdlib.h>

struct Team {
    int points;
    char team;
    struct Player *players;
};

struct Team createTeam(char tname) {
    struct Team t;
    t.team = tname;
    t.points = 0;

    t.players = (struct Player *) malloc(sizeof(struct Player) * 5);

    for (int i = 1; i <= 5; i++) {
        struct Player cp;
        cp.id = i;
        cp.team = t.team;
        cp.points = 0;
        t.players[i - 1] = cp;
    }

    return t;
}

void printTeamScoreTable(struct Team t, int quater) {
    printf("|Equipo| ID | Puntos |\n");
    printf("|------|----|--------|\n");

    for (int i = 0; i < 5; i++) {
        printf("|  %c   | %d  | %d \n", t.team, t.players[i].id, getPlayerPoints(&t.players[i]));
    }
    printf("Puntos del equipo %c : %d \n", t.team, t.points);
    printf("%d Cuarto \n", quater);
}

int addTeamPoints(struct Team *t) {
    int _points;
    int player;

    printf("Cuantos puntos el equipo %c hizo? ", t->team);
    scanf("%d", &_points);
    printf("\n");
    printf("Que jugador anoto esos puntos? ");
    scanf("%d", &player);
    printf("\n");


    addPlayerPoints(&t->players[player - 1], _points);
    t->points += _points;
    return t->points;
}

