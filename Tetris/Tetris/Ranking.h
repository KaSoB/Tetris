#pragma once
#include <vector>
#include "Player.h"
using vPlayer = std::vector<Player>;

class Ranking {	
public:
	static Ranking * getRanking() {
		static Ranking ranking("ranking.txt");
		return &ranking;
	}
	vPlayer * getPlayers();
	void addPlayer(const Player & p);
	void showScoreboard();
	void clear();
	bool isEmpty();
	bool isFull();
private:
	static const int MAX_SIZE = 10;
	vPlayer players;
	std::string filename;

	Ranking(const char * filename);
	Ranking(Ranking &) = delete;
	~Ranking() { saveToFile(); }
	int minScore();
	void removePlayersIfNoSpace();
	void sort();
	void saveToFile();
	void loadFromFile();
};