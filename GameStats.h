#ifndef GAMESTATS_H
#define GAMESTATS_H

#include <string>
#include <unordered_map>

class GameStats {
private:
    std::unordered_map<std::string, int> gamesPlayed;
    std::unordered_map<std::string, int> wins;
    std::unordered_map<std::string, int> losses;
    std::unordered_map<std::string, double> money;

public:
    GameStats();
    ~GameStats();

    void updateGamesPlayed(const std::string& playerName);
    void updateWins(const std::string& playerName);
    void updateLosses(const std::string& playerName);
    void updateMoney(const std::string& playerName, double amount);

    int getGamesPlayed(const std::string& playerName) const;
    int getWins(const std::string& playerName) const;
    int getLosses(const std::string& playerName) const;
    double getMoney(const std::string& playerName) const;
};

#endif

