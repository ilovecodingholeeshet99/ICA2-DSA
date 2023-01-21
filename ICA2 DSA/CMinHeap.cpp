#include "CMinHeap.h"
// to find parent - (x-1)/2
// to find leftchild - (x*2)+1
// to find rightchild - (x*2)+2
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
	if (isExist(name)) return;
	else
	{
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
}
void CMinHeap::move(const std::string& name, const int newD)
{
	const int index = findPlayer(name); //  Store old index
	if (index < 0) return; // Check if invalid
	const int p_parent = parent(index); // Stores parent index
	const int p_left = leftC(index); // Store left child index
	const int p_right = rightC(index); // Store right child index
	players[index]->setDist(newD);
	moveup(index, p_parent);
	movedown(index, p_parent, p_left, p_right);
}
void CMinHeap::del(const std::string& name)	
{
	int toDel = findPlayer(name);
	int last = returnIdx();
	swap(toDel, last);
}
void CMinHeap::preOrder(int start) const
{
	if (players[start] == nullptr) return;
	std::cout << "node:  " << players[start]->getName() << ' ' << players[start]->getDist() << std::endl;
	if (players[(start * 2) + 1] != nullptr)
		// this node has left child
		std::cout << "Left node: " << players[(start * 2) + 1]->getName() << ' ' << players[(start * 2) + 1]->getDist() << std::endl;
	else std::cout << "Left NIL" << std::endl;
	if (players[(start * 2) + 2] != nullptr)
		// this node has Right child
		std::cout << "Right node: " << players[(start * 2) + 2]->getName() << ' ' << players[(start * 2) + 2]->getDist() << std::endl;
	else std::cout << "Right NIL" << std::endl;
	std::cout << std::endl;
	preOrder((start * 2) + 1); // go left
	preOrder((start * 2) + 2); // go right
}
int CMinHeap::returnIdx() const
{
	return nextIdx;
}
int CMinHeap::findPlayer(const std::string& name)
{
	for (int i = 0; i <= returnIdx() ; i++)
	{
		if (players[i] == nullptr) continue;
		if (name == players[i]->getName()) return i;
	}
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
	CPlayer* temp = players[i]; // Create temp pointer which points at player[i] pointer that is pointing to the player
	players[i] = players[j];
	players[j] = temp;
}
void CMinHeap::moveup(int p_idx, int p_parent)
{
	while (players[p_idx]->getDist() < players[p_parent]->getDist() && p_idx > 0) // If p_idx is smaller than parent swap if not while loop stops
	{
		swap(p_idx, p_parent);
		p_idx = p_parent;
		p_parent = parent(p_idx);
	}
}
void CMinHeap::movedown(int p_idx, int p_parent, int p_left, int p_right)
{
	while (players[p_idx]->getDist() > players[p_parent]->getDist() && p_idx < returnIdx()) // If p_idx is bigger than parent then go down left and right child
	{
		// Check left first then right
		if (players[p_left] != nullptr)
		{
			if (players[p_idx]->getDist() > players[p_left]->getDist())
			{
				swap(p_idx, p_left); // If player p_idx dist is bigger then swap
				p_idx = p_left;
				p_left = leftC(p_idx);
			}
			continue;
		}
		if (players[p_right] != nullptr)
		{
			if (players[p_idx]->getDist() > players[p_right]->getDist())
			{
				swap(p_idx, p_right);
				p_idx = p_right;
				p_right = rightC(p_idx);
			}
			continue;
		}
		else break;
	}
}
bool CMinHeap::isExist(const std::string& name)
{
	for (int i = 0; i <= returnIdx() ; ++i)  // For loops the size of the array
	{
		if (players[i] != nullptr)
		{
			if (name == players[i]->getName()) return true;
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
