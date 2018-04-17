#include "Player.h"
int Player::getPoints() const {
	return score;
}
std::string Player::getName() const {
	return name; 
}
void Player::setName(std::string newName) {
	name = newName;
}
bool operator<(const Player & p1, const Player & p2) {
	return p1.getPoints() < p2.getPoints();
}
bool operator>(const Player & p1, const Player & p2) {
	return p1.getPoints() > p2.getPoints();
}
bool operator==(const Player & p1, const Player & p2) {
	return p1.getPoints() == p2.getPoints();
}
