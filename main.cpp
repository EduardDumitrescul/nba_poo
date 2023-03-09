#include <iostream>
#include <vector>
#include <cstring>

class Player {
    static int idCount;
    const int playerId;

    char* name = nullptr;
    int birthYear;
    float height;
    char* position = nullptr;
    bool injured;

public:
    Player();
    Player(const char* name);
    Player(const char* name, int birthYear);
    Player(const char* name, int birthYear, float height, const char* position = "unknown", bool injured = false);
    Player(const Player& object);

    const char* getName();
    int getBirthYear() const;
    float getHeight() const;
    const char* getPosition();
    bool getInjured() const;

    void setName(const char* name);
    void setBirthYear(int birthYear);
    void setHeight(float height);
    void setPosition(const char* position);
    void setInjured(bool injured);

    std::string toString();

    Player& operator=(const Player& object);

    friend std::ostream& operator <<(std::ostream& out, const Player &object);
    friend std::istream& operator >>(std::istream& in, Player &object);

    ~Player();
};
int Player::idCount = 1000;
Player::Player() : playerId(++idCount) {
    this->setName("unknown");
    this->setBirthYear(0);
    this->setHeight(0);
    this->setPosition("unknown");
    this->setInjured(false);
}

Player::Player(const char *name) : playerId(++idCount) {
    this->setName(name);
    this->setBirthYear(0);
    this->setHeight(0);
    this->setPosition("unknown");
    this->setInjured(false);
}

Player::Player(const char *name, int birthYear) : playerId(++idCount) {
    this->setName(name);
    this->setBirthYear(birthYear);
    this->setHeight(0);
    this->setPosition("unknown");
    this->setInjured(false);
}

Player::Player(const char *name, int birthYear, float height, const char *position, bool injured): playerId(++idCount) {
    this->setName(name);
    this->setBirthYear(birthYear);
    this->setHeight(height);
    this->setPosition(position);
    this->setInjured(injured);
}

Player::Player(const Player &object) : playerId(++idCount) {
    this->setName(object.name);
    this->setBirthYear(object.birthYear);
    this->setHeight(object.height);
    this->setPosition(object.position);
    this->setInjured(object.injured);
}

void Player::setName(const char *name) {
    if(this->name != nullptr) {
        delete[] this->name;
    }
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Player::setBirthYear(int birthYear) {
    this->birthYear = birthYear;
}

void Player::setHeight(float height) {
    this->height = height;
}

void Player::setPosition(const char *position) {
    if(this->position != nullptr) {
        delete[] this->position;
    }
    this->position = new char[strlen(position) + 1];
    strcpy(this->position, position);
}

void Player::setInjured(bool injured) {
    this->injured = injured;
}

const char *Player::getName() {
    return this->name;
}

int Player::getBirthYear() const {
    return this->birthYear;
}

float Player::getHeight() const {
    return this->height;
}

const char *Player::getPosition() {
    return this->position;
}

bool Player::getInjured() const {
    return this->injured;
}

Player::~Player() {
    if(this->name != nullptr) {
        delete[] this->name;
        this->name = nullptr;
    }
    if(this->position != nullptr) {
        delete[] this->position;
        this->position = nullptr;
    }
}

std::string Player::toString() {
    std::string output = this->name;
    output += " " + std::to_string(this->birthYear);
    output += " " + std::to_string(this->height);
    output += " " + (std::string)this->position;
    output += " "  + std::to_string(this->injured);
    return output;
}

Player &Player::operator=(const Player &object) {
    if(this != &object) {
        this->setName(object.name);
        this->setBirthYear(object.birthYear);
        this->setHeight(object.height);
        this->setPosition(object.position);
        this->setInjured(object.injured);
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Player &object) {
    out << "Player name: " << object.name << '\n';
    out << "Player birth year: " << object.birthYear << '\n';
    out << "Player height: " << object.height << '\n';
    out << "Player position: " << object.position << '\n';
    out << "Player injured: " << object.injured << '\n';
    return out;
}

std::istream &operator>>(std::istream &in, Player &object) {
    char* playerName = new char[200];
    std::cout << "Insert player name: ";
    in >> playerName;
    object.setName(playerName);
    int birthYear;
    std::cout << "Insert player birth year: ";
    in >> birthYear;
    object.setBirthYear(birthYear);
    float height;
    std::cout << "Insert player height: ";
    in >> height;
    object.setHeight(height);
    char* position = new char[20];
    std::cout << "Insert player position: ";
    in >> position;
    object.setPosition(position);
    bool injured;
    std::cout << "Is player injured? [0/1]: ";
    in >> injured;
    object.setInjured(injured);

    return in;
}

class Team {
    static int idCount;
    const int teamId;

    char* name = nullptr;
    int gamesPlayed;
    int* gamesRecord = nullptr;
    std::vector <Player*> playerList;

public:
    Team();
    Team(const char* name);
    Team(const char* name, int gamesPlayed, const int* gamesRecord);
    Team(const char* name, int gamesPlayed, const int* gamesRecord, const std::vector <Player*>& players);
    Team(const Team& object);

    const char* getName();
    int getGamesPlayed() const;
    const int* getGamesRecord();
    std::vector <Player*> getPlayers();

    void setName(const char* name);
    void setGamesRecord(int gamesPlayed, const int* gamesRecord);
    void setPlayerList(std::vector <Player*> players);

    std::string toString();

    Team& operator=(const Team& object);

    friend std::ostream& operator <<(std::ostream& out, const Team &object);
    friend std::istream& operator >>(std::istream& in, Team &object);

    ~Team();
};

int Team::idCount = 1000;

const char *Team::getName() {
    return this->name;
}

int Team::getGamesPlayed() const {
    return this->gamesPlayed;
}

const int *Team::getGamesRecord() {
    return this->gamesRecord;
}

std::vector<Player*> Team::getPlayers() {
    return this->playerList;
}

void Team::setName(const char *name) {
    if(this->name != nullptr) {
        delete[] this->name;
    }
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Team::setGamesRecord(int gamesPlayed, const int *gamesRecord) {
    this->gamesPlayed = gamesPlayed;
    if(this->gamesRecord != nullptr) {
        delete[] this->gamesRecord;
    }
    this->gamesRecord = new int[this->gamesPlayed];
    for(int i = 0; i < this->gamesPlayed; i ++) {
        this->gamesRecord[i] = gamesRecord[i];
    }
}

void Team::setPlayerList(std::vector<Player*> players) {
    this->playerList = players;
}

Team::Team() : teamId(idCount++) {
    this->setName("unkown");
    this->setGamesRecord(0, {});
    this->setPlayerList({});
}

Team::Team(const char *name) : teamId(idCount++) {
    this->setName(name);
    this->setGamesRecord(0, {});
    this->setPlayerList({});
}

Team::Team(const char *name, int gamesPlayed, const int *gamesRecord) : teamId(idCount++) {
    this->setName(name);
    this->setGamesRecord(gamesPlayed, gamesRecord);
    this->setPlayerList({});
}

Team::Team(const char *name, int gamesPlayed, const int *gamesRecord, const std::vector<Player*>& players) : teamId(idCount++) {
    this->setName(name);
    this->setGamesRecord(gamesPlayed, gamesRecord);
    this->setPlayerList(players);
}

Team::Team(const Team &object) : teamId(idCount++) {
    this->setName(object.name);
    this->setGamesRecord(object.gamesPlayed, object.gamesRecord);
    this->setPlayerList(object.playerList);
}

std::string Team::toString() {
    std::string output = (this->name == nullptr) ? "null" : this->name;
    output += " ; gamesPlayed: " + std::to_string(this->gamesPlayed);
    output += " ; playerCount: " + std::to_string(this->playerList.size());
    return output;
}

Team &Team::operator=(const Team &object) {
    if(this != &object) {
        this->setName(object.name);
        this->setGamesRecord(object.gamesPlayed, object.gamesRecord);
        this->setPlayerList(object.playerList);
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Team &object) {
    out << "Team name: " << object.name << '\n';
    out << "Games Played: " << object.gamesPlayed << '\n';
    out << "Games Record: " << (object.gamesPlayed == 0 ? "no games played" : "");
    for(int i = 0; i < object.gamesPlayed; i ++)
        out << object.gamesRecord[i] << ' ';
    out << '\n';
    out << "Number of Players: " << object.playerList.size() << '\n';
    for(auto player: object.playerList) {
        out << player->getName() << ' ';
    }
    out << '\n';
    return out;
}

std::istream &operator>>(std::istream &in, Team &object) {
    std::cout << "Insert team name: ";
    char* name = new char[100];
    in >> name;
    object.setName(name);
    if(name != nullptr) {
        delete[] name;
        name = nullptr;

    }

    std::cout << "Games Played: ";
    in >> object.gamesPlayed;

    int *record = new int[object.gamesPlayed];

    for(int i = 0; i < object.gamesPlayed; i ++) {
        std::cout << "Record for game " << i + 1 << ": ";
        in >> record[i];
    }
    object.setGamesRecord(object.gamesPlayed, record);
    if(record != nullptr) {
        delete[] record;
        record = nullptr;
    }
    return in;
}

Team::~Team() {
    if(this->name != nullptr) {
        delete[] this->name;
        this->name = nullptr;
    }
    if(this->gamesRecord != nullptr) {
        delete[] this->gamesRecord;
        this->gamesRecord;
    }
}

class Game {
    static int idCount;
    const int gameId;

    Team* homeTeam;
    Team* awayTeam;
    Player* mvp;

    int homeScore;
    int awayScore;

public:
    Game();
    Game(Team* homeTeam, Team* awayTeam);
    Game(Team* homeTeam, Team* awayTeam, int homeScore, int awayScore);
    Game(Team* homeTeam, Team* awayTeam, int homeScore, int awayScore, Player* mvp);
    Game(const Game& object);

    const Team* getHomeTeam();
    const Team* getAwayTeam();
    int getHomeScore() const;
    int getAwayScore() const;
    const Player* getMvp();

    void setHomeTeam(Team* homeTeam);
    void setAwayTeam(Team* awayTeam);
    void setMvp(Player* mvp);
    void setHomeScore(int homeScore);
    void setAwayScore(int awayScore);

    Game& operator=(const Game& object);

    friend std::ostream& operator<<(std::ostream& out, const Game& object);
    friend std::istream& operator>>(std::istream& in, Game& object);

    std::string toString();

    ~Game();
};

int Game::idCount = 1000;

Game::Game(): gameId(idCount++) {
    this->setHomeTeam(nullptr);
    this->setAwayTeam(nullptr);
    this->setHomeScore(0);
    this->setAwayScore(0);
    this->setMvp(nullptr);
}

Game::Game(Team *homeTeam, Team *awayTeam): gameId(idCount++) {
    this->setHomeTeam(homeTeam);
    this->setAwayTeam(awayTeam);
    this->setHomeScore(0);
    this->setAwayScore(0);
    this->setMvp(nullptr);
}

Game::Game(Team* homeTeam, Team* awayTeam, int homeScore, int awayScore): gameId(idCount++) {
    this->setHomeTeam(homeTeam);
    this->setAwayTeam(awayTeam);
    this->setHomeScore(homeScore);
    this->setAwayScore(awayScore);
    this->setMvp(nullptr);
}

Game::Game(Team* homeTeam, Team* awayTeam, int homeScore, int awayScore, Player* mvp): gameId(idCount++) {
    this->setHomeTeam(homeTeam);
    this->setAwayTeam(awayTeam);
    this->setHomeScore(homeScore);
    this->setAwayScore(awayScore);
    this->setMvp(mvp);
}

Game::Game(const Game &object): gameId(idCount++) {
    this->setHomeTeam(object.homeTeam);
    this->setAwayTeam(object.awayTeam);
    this->setHomeScore(object.homeScore);
    this->setAwayScore(object.awayScore);
    this->setMvp(object.mvp);
}

const Team* Game::getHomeTeam() {
    return this->homeTeam;
}

const Team* Game::getAwayTeam() {
    return this->awayTeam;
}

int Game::getHomeScore() const {
    return this->homeScore;
}

int Game::getAwayScore() const {
    return this->awayScore;
}

const Player* Game::getMvp() {
    return this->mvp;
}

void Game::setHomeTeam(Team* homeTeam) {
    this->homeTeam = homeTeam;
}

void Game::setAwayTeam(Team* awayTeam) {
    this->awayTeam = awayTeam;
}

void Game::setMvp(Player* mvp) {
    this->mvp = mvp;
}

void Game::setHomeScore(int homeScore) {
    this->homeScore = homeScore;
}

void Game::setAwayScore(int awayScore) {
    this->awayScore = awayScore;
}

Game &Game::operator=(const Game &object) {
    if(this != &object) {
        this->setHomeTeam(object.homeTeam);
        this->setAwayTeam(object.awayTeam);
        this->setHomeScore(object.homeScore);
        this->setAwayScore(object.awayScore);
        this->setMvp(object.mvp);
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Game &object) {
    out << "ID: " << object.gameId << '\n';
    out << "Home Team: " << (object.homeTeam == nullptr ? "null" : object.homeTeam->toString()) << '\n';
    out << "Away Team: " << (object.awayTeam == nullptr ? "null" : object.awayTeam->toString()) << '\n';
    out << "Home Score: " << object.homeScore << '\n';
    out << "Away Score: " << object.awayScore << '\n';
    out << "MVP: " << (object.mvp == nullptr ? "null" : object.mvp->toString()) << '\n';
    return out;
}

std::istream &operator>>(std::istream &in, Game &object) {
    Team *home = new Team();
    Team *away = new Team();
    Player *player = new Player();
    std::cout << "Insert Home Team Information..." << '\n';
    in >> *home;
    std::cout << "Insert Away Team Information..." << '\n';
    in >> *away;
    std::cout << "Insert Home Score: ";
    in >> object.homeScore;
    std::cout << "Insert Away Score: ";
    in >> object.awayScore;
    std::cout << "Insert MVP information..." << '\n';
    in >> *player;
    object.setMvp(player);
    object.setHomeTeam(home);
    object.setAwayTeam(away);

    return in;
}

std::string Game::toString() {
    std::string output = std::to_string(this->gameId) + ": " + this->homeTeam->toString() + " " + std::to_string(this->homeScore)  + " - " + std::to_string(this->awayScore) + " " + this->awayTeam->toString();
    return output;
}

Game::~Game() {
    if(this->homeTeam != nullptr) {
        delete this->homeTeam;
        this->homeTeam = nullptr;
    }
    if(this->awayTeam != nullptr) {
        delete this->awayTeam;
        this->awayTeam = nullptr;
    }
    if(this->mvp != nullptr) {
        delete this->mvp;
        this->mvp = nullptr;
    }
}

class Season {
    static int idCount;
    const int seasonId;

    int year;
    std::vector <Game*> games;

public:
    Season();
    Season(int year);
    Season(int year, const std::vector <Game*> &games);
    Season(const Season& object);

    void addGame(Game *game);

    int getYear();
    const std::vector <Game*>& getGames();

    void setYear(int year);
    void setGames(const std::vector <Game*> &games);

    Season &operator =(const Season& object);
    friend std::ostream &operator<<(std::ostream &out, const Season& object);
    friend std::istream &operator>>(std::istream &in, Season& object);

    ~Season();
};
int Season::idCount = 1000;

Season::Season(): seasonId(idCount++)  {
    this->setYear(0);
    this->setGames({});
}

Season::Season(int year): seasonId(idCount++) {
    this->setYear(year);
    this->setGames({});
}

Season::Season(int year, const std::vector<Game *> &games): seasonId(idCount++)  {
    this->setYear(year);
    this->setGames(games);
}

Season::Season(const Season &object): seasonId(idCount++)  {
    this->setYear(object.year);
    this->setGames(object.games);
}

void Season::addGame(Game *game) {
    this->games.push_back(game);
}

int Season::getYear() {
    return this->year;
}

const std::vector<Game *>& Season::getGames() {
    return this->games;
}

void Season::setYear(int year) {
    this->year = year;
}

void Season::setGames(const std::vector<Game *> &games) {
    this->games = games;
}

Season &Season::operator=(const Season &object) {
    if(this != &object) {
        this->setYear(object.year);
        this->setGames(object.games);
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Season &object) {
    out << "Season Year: " << object.year << '\n';
    out << "Season Games Count: " << object.games.size() << '\n';
    for(auto game: object.games) {
        out << game->toString() << '\n';
    }
    return out;
}

std::istream &operator>>(std::istream &in, Season &object) {
    std::cout << "Insert Season Year: ";
    in >> object.year;
    std::cout << "Insert Games Count: ";
    int gamesCount;
    in >> gamesCount;
    while(gamesCount--) {
        Game *game = new Game();
        in >> *game;
        object.addGame(game);
    }
    return in;
}

Season::~Season() {
    while(!this->games.empty()) {
        if(this->games.back() != nullptr) {
            delete this->games.back();
        }
        this->games.pop_back()
    }
}


void testPlayerClass() {
    Player a;
    Player b("player b");
    Player c("player c", 2003);
    Player d("player d", 2003, 1.97, "PG", true);
    Player e(d);
    Player f = e;

    e.setName("player e");
    f.setName("player f");

    std::cout << a.toString() << '\n';
    std::cout << b.toString() << '\n';
    std::cout << c.toString() << '\n';
    std::cout << d.toString() << '\n';
    std::cout << e.toString() << '\n';
    std::cout << f.toString() << '\n';

    Player player;
    std::cin >> player;
    std::cout << player << '\n';
}

void testTeamClass() {
    Team a;
    int* record = new int[2];
    record[0] = -25, record[1] = 36;
    Team b("team b");
    Player player("player d", 2003, 1.97, "PG", true);
    Team c("team c", 2, record, {&player});

    Team d(c);
    Team e = d;

    d.setName("team d");
    e.setName("teams e");

    std::cout << a.toString() << '\n';
    std::cout << b.toString() << '\n';
    std::cout << c.toString() << '\n';
    std::cout << d.toString() << '\n';
    std::cout << e.toString() << '\n';

    Team team;
    std::cin >> team;
    std::cout << team << '\n';
}

void testGameClass() {
    Game a;
    Team home("home");
    Team away("away");
    Player mvp("mvp");

    Game b(&home, &away);
    Game c(&home, &away, 123, 321);
    Game d(&home, &away, 123, 321, &mvp);
    Game e(d);
    Game f = e;

    e.setAwayTeam(&home);
    e.setHomeTeam(&away);

    std::cout << a << b << c << d << e << f;


    std::cin >> a;
    std::cout << a;
}

void testSeasonClass() {
    Season a;
    Season b(2003);
    Season c(2023, {});
    Season d(c);
    d.setYear(201241);

    std::cout << a << b << c << d;

    Season s;
    std::cin >> s;
    std::cout << s;
}

int main() {
    testSeasonClass();
    return 0;
}
