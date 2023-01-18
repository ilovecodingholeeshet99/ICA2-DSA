#include <iostream>
#include <Windows.h>
#include "CMinHeap.h"
#include "CFunctions.h"
int main(void)
{
	CMinHeap mHeap;
	std::string name;
	int distance = 0;
	int input = 0 ;
	while (true)
	{	
		u_input(name, distance, input, mHeap);
	}
	return 0;
}


////#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//
//struct Player {
//    string name;
//    int distance;
//};
//
//vector<Player> heap;
//unordered_map<string, int> player_map;
//
//void movePlayer() {
//    string player_name;
//    cout << "Enter name of player to move: ";
//    cin >> player_name;
//
//    // check if player is in heap
//    if (player_map.count(player_name) == 0) {
//        cout << "Cannot find player with name " << player_name << endl;
//        return;
//    }
//
//    // get index of player in heap
//    int player_index = player_map[player_name];
//    Player player = heap[player_index];
//
//    cout << "Enter new distance for player " << player_name << ": ";
//    int new_distance;
//    cin >> new_distance;
//
//    // update player's distance
//    player.distance = new_distance;
//    heap[player_index] = player;
//
//    // maintain min heap property
//    int current = player_index;
//    int parent = (current - 1) / 2;
//    while (parent >= 0 && heap[parent].distance > heap[current].distance) {
//        swap(heap[parent], heap[current]);
//        current = parent;
//        parent = (current - 1) / 2;
//    }
//}
