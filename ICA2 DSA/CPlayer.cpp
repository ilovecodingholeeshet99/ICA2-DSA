#include "CPlayer.h"
CPlayer::CPlayer(const std::string& playerName, const int d) : name(playerName), dist(d) {
}
CPlayer::~CPlayer()
{
}
std::string& CPlayer::getName() 
{
    return name;
}
int CPlayer::getDist() const
{
    return dist;
}
void CPlayer::setDist(int newD)
{
    dist = newD;
}