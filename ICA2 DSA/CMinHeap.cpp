#include "CMinHeap.h"
CMinHeap::CMinHeap()
{
	for (int i = 0; i < MAX_PLAYERS; ++i)
		players[i] = nullptr;
	nextIdx = -1;
}
CMinHeap::~CMinHeap()
{
	for (int i = 0; i <= nextIdx; ++i) 
		delete players[i];
}
void CMinHeap::insert(const std::string& name, const int d)
{
	if (isExist(name, d)){
		std::cout << "One or both of the input already exists. " << std::endl;
		return;
	}
	CPlayer* tmp = new CPlayer(name, d);
	nextIdx++;
	players[nextIdx] = tmp;
	// Now see if this obj needs to be shifted towards the top of the heap
	int current;
	current = nextIdx;
	// By the time code reaches here name has already been checked
	while ((d < players[(current - 1) / 2]->getDist()) && (current > 0)) // Check if distance entered is smaller than the parent
	{
		//doing the swap of child with parent
		CPlayer* temp;
		temp = players[(current - 1) / 2]; // Find parent;
		players[(current - 1) / 2] = players[current];
		players[current] = temp;
		//move on to parent
		current = (current - 1) / 2;
	}
}
void CMinHeap::move(const std::string& name, const int newD)
{
	if (!isExist(name)) {
		std::cout << "No matching name found." << std::endl;
		return;
	}
	const int index = findPlayer(name); //  Store old index
	if (index < 0) return; // Check if invalid
	const int p_parent = parent(index); // Stores parent index
	const int p_left = leftC(index); // Store left child index
	const int p_right = rightC(index); // Store right child index
	players[index]->setDist(newD);
	moveup(index, p_parent);
	movedown(index);
}
void CMinHeap::del(const std::string& name)	
{
	if (!isExist(name)) {
		std::cout << "No matching name found. " << std::endl;
		return;
	}
	int toDel = findPlayer(name); // Node we want to delete 
	int last = returnIdx(); // Last node
	delete players[toDel]; // Delete player
	players[toDel] = nullptr; 
	swap(toDel, last);
	movedown(toDel);
	nextIdx--; // *
}
void CMinHeap::preOrder(int start) const
{
	if (players[0] == nullptr) {
		std::cout << "The heap is empty, nothing to see here folks!" << std::endl;
		return;
	}
	if (players[start] == nullptr) return;
	std::cout << "Player: " << players[start]->getName() << " Distance: " << players[start]->getDist() << std::endl;
	std::cout << "Children: ";
	if (players[(start * 2) + 1] != nullptr)
		std::cout << players[(start * 2) + 1]->getName() << " ";
	if (players[(start * 2) + 2] != nullptr)
		std::cout << players[(start * 2) + 2]->getName() << " ";
	std::cout << std::endl;
	preOrder((start * 2) + 1);
	preOrder((start * 2) + 2);
}
int CMinHeap::returnIdx() const
{
	return nextIdx;
}
int CMinHeap::findPlayer(const std::string& name)
{
	for (int i = 0; i <= returnIdx(); ++i)
		if (name == players[i]->getName()) return i;
}
int CMinHeap::parent(const int index) const
{
	return ((index- 1 )/ 2);
}
int CMinHeap::leftC(const int index) const
{
	return ((index * 2) + 1);
}
int CMinHeap::rightC(const int index) const
{
	return ((index * 2) + 2);
}
void CMinHeap::swap(int i, int j)
{
	CPlayer* temp = players[i];
	players[i] = players[j];
	players[j] = temp;
}
void CMinHeap::moveup(int p_idx, int p_parent)
{
	while (players[p_parent] != nullptr) // If p_idx is smaller than parent swap if not while loop stops
	{
		if (players[p_idx]->getDist() < players[p_parent]->getDist() && p_idx > 0)
		{
			swap(p_idx, p_parent);
			p_idx = p_parent;
			p_parent = parent(p_idx);
			continue;
		}
		break;
	}
}

void CMinHeap::movedown(int p_idx)
{
	int p_left = leftC(p_idx), p_right = rightC(p_idx);	
	while (p_idx <= returnIdx())
	{
		// Check left first then right
		if (players[p_left] != nullptr)
		{
			if (players[p_idx]->getDist() > players[p_left]->getDist())
			{
				swap(p_idx, p_left); // If player p_idx dist is bigger then swap
				p_idx = p_left;
				p_left = leftC(p_idx);
				p_right = rightC(p_idx);
				continue;
			}
		}
		if (players[p_right] != nullptr)
		{
			if (players[p_idx]->getDist() > players[p_right]->getDist())
			{
				swap(p_idx, p_right);
				p_idx = p_right;
				p_right = rightC(p_idx);
				p_left = leftC(p_idx);
				continue;
			}
		}
		break;
	}
}
bool CMinHeap::isExist(const std::string& name)
{
	for (int i = 0; i <= returnIdx(); ++i)  // For loops the size of the array
	{
		if (players[i] != nullptr)
		{
			if (name == players[i]->getName()) return true;
		}
	}
	return false; // False if not
}
bool CMinHeap::isExist(const int dist)
{
	for (int i = 0; i <= returnIdx(); ++i)  // For loops the size of the array
	{
		if (players[i] != nullptr)
		{
			if (dist == players[i]->getDist()) return true;
		}
	}
	return false; // False if not
}
bool CMinHeap::isExist(const std::string& name, const int dist)
{
	for (int i = 0; i <= returnIdx(); ++i)  // For loops the size of the array
	{
		if (players[i] != nullptr)
		{
			if (dist == players[i]->getDist() || name == players[i]->getName()) return true;
		}
	}
	return false; // False if not
}
bool CMinHeap::isDistanceExist(int d, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (d == players[i]->getDist()) return true;
	}
	return false;
}
