#include <fstream>
#include <iostream>
#include <algorithm>
#include "Getinput.h"
#include "Ranking.h"
void Ranking::loadFromFile() {
	std::ifstream fileStream(filename, std::ios::in);
	
	if (!fileStream.is_open())
		GetInput::message(filename.c_str());
	else {
		std::string name;
		int points;
		while (fileStream >> name >> points) {
			players.push_back(Player(name,points));
		}
	}
	fileStream.close();
}
bool Ranking::isEmpty() {
	return players.size() == 0;
}
bool Ranking::isFull() {
	return players.size() == MAX_SIZE;
}
void Ranking::saveToFile() {
	std::ofstream fileStream(filename, std::ios::out);

	if (fileStream.is_open())
		for (Player x : players)
			fileStream << x.getName() << " " << x.getPoints() << std::endl;
	fileStream.close();
}
Ranking::Ranking(const char * filename) : filename(filename) {
	loadFromFile();
	sort(); 
}
int Ranking::minScore() {
	if(isEmpty())
		return 0;
	else
		return players.back().getPoints();
}
void Ranking::removePlayersIfNoSpace() {
	while (isFull())
		players.pop_back();
}
void Ranking::sort() {
	std::sort(players.begin(), players.end(),
		[] (const Player & a, const Player & b) { return a.getPoints() > b.getPoints(); });
}
void Ranking::showScoreboard() {
	int i = 0;
	for (Player x : players)
		std::cout << "  " << ++i << ".  " << x.getName() << " " << x.getPoints() << std::endl;
}
void Ranking::clear() {
	players.clear();
}
void Ranking::addPlayer(const Player & p) {
	if (p.getPoints() > minScore()) {
		removePlayersIfNoSpace();
		players.push_back(p);
		sort();
	}
}
vPlayer * Ranking::getPlayers() {
	return &players; 
}
