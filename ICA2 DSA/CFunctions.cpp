#include "CFunctions.h"
void u_input(std::string& name, int distance, int input, CMinHeap& tree)
{
	std::cout << "MinHeap tree: (1) Add: " << "(2) Move: " << "(3) Remove: " << "(4) Print MinHeap" << std::endl; std::cin >> input;
	switch (input)
	{
	case 1: // Add player
		std::cout << "Enter name: " << std::endl; std::cin >> name;
		std::cout << "Enter distance: " << std::endl; std::cin >> distance;
		tree.insert(name, distance);
		system("CLS");
		break;
	case 2: // Move player
		std::cout << "Enter name of existing player: " << std::endl;
		std::cin >> name;
		// If true, the  ask distance
		if (tree.isExist(name))
		{
			std::cout << "Enter new distance of player: " << std::endl; std::cin >> distance;
			tree.move(name, distance);
			break;
		}
		else return;
	case 3: // Remove player
		std::cout << "Enter name of player to remove:  " << std::endl; std::cin >> distance;
		if (tree.isExist(name)) /*tree.remove(name);*/ // Execute remove function
		{
			system("CLS");
			return;
		}
		else break;
	case 4: // Print heap
		tree.preOrder(0);
		break;
	default:
		std::cout << "Wrong entry." << std::endl; return;
		break;
	}
}
