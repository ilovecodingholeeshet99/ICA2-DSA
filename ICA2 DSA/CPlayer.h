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
	std::string& getName();
	int getDist() const ;
	void setDist(int newD);
};

