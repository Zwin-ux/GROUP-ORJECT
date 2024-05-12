#include "GameStats.h"

GameStats::GameStats() {}

GameStats::~GameStats() {}

void GameStats::updateGamesPlayed(const std::string& playerName) {
    gamesPlayed[playerName]++;
}

void GameStats::updateWins(const std::string& playerName) {
    wins[playerName]++;
}

void GameStats::updateLosses(const std::string& playerName) {
    losses[playerName]++;
}

void GameStats::updateMoney(const std::string& playerName, double amount) {
    money[playerName] += amount;
}

int GameStats::getGamesPlayed(const std::string& playerName) const {
    return gamesPlayed.count(playerName) ? gamesPlayed.at(playerName) : 0;
}

int GameStats::getWins(const std::string& playerName) const {
    return wins.count(playerName) ? wins.at(playerName) : 0;
}

int GameStats::getLosses(const std::string& playerName) const {
    return losses.count(playerName) ? losses.at(playerName) : 0;
}

double GameStats::getMoney(const std::string& playerName) const {
    return money.count(playerName) ? money.at(playerName) : 0.0;
}

