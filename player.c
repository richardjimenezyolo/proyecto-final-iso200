struct Player {
    int points;
    int id;
    char team;
};

int getPlayerPoints(struct Player *p){
    return p->points;
}

int addPlayerPoints(struct Player *p, int points) {
    p->points += points;
    return p->points;
}
