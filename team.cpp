#include <iostream>
#include "stdio.h"
#include "player.cpp"

class Team {
    private:
        int points= 0;
    
    public:
        char team;
        Player *players;

        Team(char cteamId) {
            team = cteamId;
        }

        Player *initializeTeam() {
            players = (Player*)malloc(sizeof(Player) * 5);

            for (int i = 1; i <= 5; i++)
            {
                players[i-1] = Player(i, team);
            }
            

            return players;
        }


        void printScoreTable(int quater) {
            std::cout << "|Equipo| ID | Puntos |\n";
            std::cout << "|------|----|--------|\n";

            for (int i = 0; i < 5; i++)
            {
                std::cout << "|  " << team << "   | " << players[i].id << "  | " << players[i].getPoints() << "\n";
            }

            std::cout << "Puntos del equipo " << team << ": " << points << "\n";
            std::cout << quater << " Cuarto \n";

        }


        void addPoints() {
            int _points;
            int player;

            std::cout << "Cuantos puntos el equipo " << team << " hizo? ";
            std::cin >> _points;
            std::cout << "\n";

            std::cout << "Que jugador anoto esos puntos? ";
            std::cin >> player;
            std::cout << "\n";

            players[player-1].addPoints(_points);
            points += _points;
        }


        int getPoints() {
            return points;
        }
    

};