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
    Player(const char* name, int birthYear, float height, const char* position, bool injured = false);
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
}


int main() {
    testPlayerClass();
    return 0;
}
