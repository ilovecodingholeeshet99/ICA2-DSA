#pragma once
#include <string>
#include <iostream>
class CPlayer
{
private:
	std::string name;
	int dist;
public:
	CPlayer(const std::string& playerName, const int d);
	~CPlayer();
	const std::string& getName();
	const int getDist();
	void setDist(int newD);
};

