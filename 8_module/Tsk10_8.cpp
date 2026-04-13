//
// Created by NandanRaj on 09-04-2026.
//
#include<iostream>
#include<map>
#include<string>
#include<utility>
struct PlayerStats {
    std::string playerID;
    std::string playerName;
    int score;
    PlayerStats(std::string playerID, std::string playerName,int score):
    playerID(std::move(playerID)),playerName(std::move(playerName))
    ,score(score){}

};
// struct for functor
struct PlayerRankComparator {
    bool operator()(const PlayerStats& p1, const PlayerStats& p2)const {
        if (p1.score==p2.score) {
            if (p1.playerName==p2.playerName) {
                return p1.playerID<p2.playerID;
            }
            return p1.playerName<p2.playerName;
        }
        return p1.score>p2.score;
    }
};

int main() {
    std::map<PlayerStats,bool,PlayerRankComparator> leaderboard{
        {PlayerStats ("P001", "Alice", 1500),true},
        {PlayerStats ("P003", "Charlie", 1200),true},
        {PlayerStats ("P002", "Bob", 1500),true},
        {PlayerStats ("P005", "David", 1800),true},
        {PlayerStats ("P004", "Alice", 1000),true},
        {PlayerStats ("P007", "Emily", 1200),true},
        {PlayerStats ("P006", "Bob", 1500),true}
        };
    int i=0;
    for (const auto &it: leaderboard ) {
        PlayerStats p = it.first;

        std::cout<<"RANK "<<++i<<"----> Player ID: "<<p.playerID
        <<" | Player Name: "<<p.playerName
        <<" | Score: "<<p.score<<std::endl;
    }





}