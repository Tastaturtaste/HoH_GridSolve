#include "Table.h"
#include <cmath>
#include <iostream>
#include <vector>

bool Increment(std::vector<bool>& bs)
{
	for (int i = 0; i < bs.size(); i++)
	{
		bs[i] = !bs[i];
		if (bs[i] == true)
			return true;
	}
	return false;
}

bool CheckSolution(Table& table)
{
	for (int i = 0; i < table.nodes.size(); i++)
	{
		table.nodes[i].Eval(table.GetNeighbors(i));
		if (!table.nodes[i].lit)
			return false;
	}
	return true;
}

int main()
{
	unsigned int size = 0;
	std::cout << "Please enter the size of your grid: ";
	std::cin >> size;

	Table table(size);
	std::vector<bool> bs(pow(size, 2));
	std::vector<Table> solutions;

	// construction and testing here
	do
	{
		for (int i = 0; i < table.nodes.size(); i++)
		{
			table.nodes[i].pressed = bs[i];

			#ifdef DEBUG
				std::cout << table.nodes[i].pressed << " ";
				if (i % table.size == table.size - 1)
					std::cout << "\n";
				if (i == table.nodes.size() - 1)
					std::cout << "\n\n\n";
			#endif // DEBUG


		}
		if (CheckSolution(table))
			solutions.push_back(table);
	} while (Increment(bs));


	for (Table table : solutions)
	{
		for (unsigned int i = 0; i < table.nodes.size(); i++)
		{
			if (table.nodes[i].pressed)
				std::cout << "# ";
			else
				std::cout << "O ";
			if(i % table.size == table.size - 1)
				std::cout << "\n";
		}
		for (unsigned int i = 0; i < 15; i++)
			std::cout << "-";
		std::cout << "\n";
	}

	system("PAUSE");

	return 0;
}