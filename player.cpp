class Player {
    private:
        int points = 0;

    public:
        int id = 0;
        char team;

        Player(int _playerId, char teamId) {
            id = _playerId;
            team = teamId;
        }

        int getPoints() {
            return points;
        }

        void addPoints(int amount) {
            points += amount;
        }
};