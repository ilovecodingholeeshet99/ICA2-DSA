#pragma once
#include "CPlayer.h"
#define MAX_PLAYERS 50
class CMinHeap // Root is always smaller than the child
{
private:
	CPlayer* players[MAX_PLAYERS]; // Array of CPlayer pointers
	int nextIdx;
public:
	CMinHeap();
	~CMinHeap();

	bool isExist(const std::string& name); // Take as reference so it does not create a copy of the variable and instead passes by reference, aka memory address
	bool isExist(const int dist);
	bool isExist(const std::string& name, const int dist);
	bool isDistanceExist(const int d, const int size); // Not changing the variable throughout the function so keep as const

	void insert(const std::string& name, const int d);
	void move(const std::string& name, const int newD); // Move function will take in name of player and new distance
	void del(const std::string& name);

	void preOrder(int start) const; // No need to pass int as reference, pointer and int same number of bytes
	void swap(int i , int j);
	void moveup(int p_idx, int p_parent);
	void movedown(int p_idx);

	int findPlayer(const std::string& name);  // Returns index of player by looping through each element of the array
	int returnIdx() const;
	int parent(int index) const;

	int leftC(int index) const;
	int rightC(int index) const;
};