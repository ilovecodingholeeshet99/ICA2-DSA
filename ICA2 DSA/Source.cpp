#include <iostream>
#include <Windows.h>
#include "CMinHeap.h"
#include "CFunctions.h"
int main(void)
{
	CMinHeap mHeap;
	std::string name;
	int distance = 0;
	int input = 0;
	while (true)
	{	
		u_input(name, distance, input, mHeap);
	}
	return 0;
}