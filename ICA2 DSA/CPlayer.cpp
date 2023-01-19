#include "CPlayer.h"
CPlayer::CPlayer(const std::string& playerName, const int d)
{
    name = playerName;
    dist = d;
}
CPlayer::~CPlayer()
{
}
const std::string& CPlayer::getName()
{
    return name;
}
const int CPlayer::getDist()
{
    return dist;
}

void CPlayer::setDist(int newD)
{
    dist = newD;
}
