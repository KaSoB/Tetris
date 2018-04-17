#pragma once
#include <string>
class Player {
public:
	Player(std::string name, int score) : name(name), score(score) {}
	int getPoints() const;
	std::string getName() const;
	void setName(std::string newName);
	friend bool operator<(const Player & p1, const Player & p2);
	friend bool operator>(const Player & p1, const Player & p2);
	friend bool operator==(const Player & p1, const Player & p2);
private:
	std::string name;
	int score;
};
