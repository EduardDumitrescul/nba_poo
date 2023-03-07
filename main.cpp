#include <iostream>
#include <vector>

class Player {
    static int idCount;
    const int playerId;

    char* name;
    int birthYear;
    float height;
    char* position;
    bool injured;
};

class Team {
    static int idCount;
    const int teamId;

    char* name;
    int* lastFiveGamesRecord;
    std::vector <Player> playerList;
};

class Game {
    static int idCount;
    const int gameId;

    Team homeTeam;
    Team awayTeam;
    Player mvp;

    int homeTeamScore;
    int awayTeamScore;
};

class Season {
    static int idCount;
    const int seasonId;

    int startYear;
    std::vector <Game> games;
};




int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
