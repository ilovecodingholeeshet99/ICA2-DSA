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
	int index = findPlayer(name); //  Store old index
	int m_parent = parent(index); // Stores parent index
	int m_left = leftC(index); // Store left child index
	int m_right = rightC(index); // Store right child index
	players[index]->setDist(newD);
	while (players[index]->getDist() < players[m_parent]->getDist() && index > 0) // If index is smaller than parent swap if not while loop stops
	{
		swap(index, m_parent);
		index = m_parent;
		m_parent = parent(index);
	}
	while (players[index]->getDist() > players[m_parent]->getDist()) // If index is bigger than parent then go down left and right child
	{
		// Check left first then right
		if (players[index]->getDist() > players[m_left]->getDist() && m_left <= nextIdx)
		{
			swap(index, m_left); // If player index dist is bigger then swap	
			index = m_left;
			m_left = leftC(index);
		}
		else if (players[index]->getDist() > players[m_right]->getDist() && m_right <= nextIdx)
		{
			swap(index, m_right);
			index = m_right;
			m_right = rightC(index);	
		}
		else break; 
	}
}
void CMinHeap::del(const std::string& name)
{
	const int start = 0;
	int delIdx = findPlayer(name); // Index of player we want to delete
	int parent_delIdx = parent(delIdx);
	int leftc_delIdx = leftC(delIdx);
	int rightc_delIdx = rightC(delIdx);
	// Find last player in minheap
	int last = findLast(start); // Cannot set const because changing value
	int last_parent = parent(last);
	swap(delIdx, last); // Swap last and node that we want to delete
	int temp = delIdx;
	delIdx = last;
	last = temp;
	while (players[last]->getDist() < players[parent_delIdx]->getDist()) // If smaller than parent
	{
		swap(last, parent_delIdx);
		last = parent_delIdx;
		parent_delIdx = parent(last);
	}
	while (players[last]->getDist() > players[parent_delIdx]->getDist()) // If bigger than parent
	{
		if (players[last]->getDist() < players[leftc_delIdx]->getDist())
		{
			swap(last, leftc_delIdx);
			last = leftc_delIdx;
			leftc_delIdx = leftC(last);
		}
		else if (players[last]->getDist() < players[rightc_delIdx]->getDist())
		{
			swap(last, rightc_delIdx);
			last = rightc_delIdx;
			rightc_delIdx = rightC(last);
		}
		else break;
	}
	delete players[delIdx];
}
void CMinHeap::preOrder(int start)
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
void CMinHeap::swap(int i, int j)
{
	CPlayer* temp = players[i]; // Create temp pointer which points at player[i] pointer that is pointing to the player
	players[i] = players[j];
	players[j] = temp;
}
int CMinHeap::findLast(int index) // Index is 0 so start at root
{
	if (index >= returnIdx()){  // Base case
		return index;
	}
	findLast(leftC(index));
	findLast(rightC(index));
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
