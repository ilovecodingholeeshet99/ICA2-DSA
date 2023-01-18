#include "CMinHeap.h"
// to find parent - (x-1)/2
// to find leftchild - (x*2)+1
// to find rightchild - (x*2)+2
CMinHeap::CMinHeap()
{
	root = nullptr;
	current = nullptr;
	prev = nullptr;
	for (int i = 0; i < MAX_PLAYERS; ++i)
	{
		players[i] = nullptr;
	}
	nextIdx = -1;
}
CMinHeap::~CMinHeap()
{
	delete root;
	delete current;
	delete prev;
	for (int i = 0; i <= nextIdx; ++i)
	{
		delete players[i];
	}
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
	// to find parent - (x-1)/2
	// to find leftchild - (x*2)+1
	// to find rightchild - (x*2)+2 
	int index = findPlayer(name); //  Store old index
	int m_parent = parent(index); // Stores parent index
	int m_left = leftC(index); // Store left child index
	int m_right = rightC(index); // Store right child index
	while (players[index]->getDist() < players[m_parent]->getDist() && index) // If index is smaller than parent swap if not while loop stops
	{
		CPlayer* temp = players[index]; // Temp stores the memory address of player index
		players[index] = players[m_parent]; // Index will point at parent
		players[m_parent] = temp; // Parent can point at index that is saved in temp
	}
	while (players[index]->getDist() > players[m_parent]->getDist()) // If index is bigger than parent then go down left and right child
	{
		// Check left first then right
		if (players[index] < )
	}
}
void CMinHeap::preOrder(int start)
{
	if (players[start] == NULL)
	{
		return;
	}
	std::cout << "node:  " << players[start]->getName() << ' ' << players[start]->getDist() << std::endl;
	if (players[(start * 2) + 1] != NULL)
	{
		// this node has left child
		std::cout << "Left node: " << players[(start * 2) + 1]->getName() << ' ' << players[(start * 2) + 1]->getDist() << std::endl;
	}
	else
		std::cout << "Left NIL" << std::endl;
	if (players[(start * 2) + 2] != NULL)
	{
		// this node has Right child
		std::cout << "Right node: " << players[(start * 2) + 2]->getName() << ' ' << players[(start * 2) + 2]->getDist() << std::endl;
	}
	else
		std::cout << "Right NIL" << std::endl;
	std::cout << std::endl;
	preOrder((start * 2) + 1); // go left
	preOrder((start * 2) + 2); // go right
}
int CMinHeap::returnIdx()
{
	return nextIdx;
}
int CMinHeap::findPlayer(const std::string& name)
{
	for (int i = 0; i <= returnIdx(); i++)
	{
		if (players[i] == nullptr) continue;
		if (name == players[i]->getName()) return returnIdx();
	}
}
int CMinHeap::parent(int index_param)
{
	return ((index_param -1 )/ 2);
}
int CMinHeap::leftC(int index_param)
{
	return ((index_param * 2) + 1);
}
int CMinHeap::rightC(int index_param)
{
	return ((index_param * 2) + 2);
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
