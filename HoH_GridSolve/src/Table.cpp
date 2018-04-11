#include "Table.h"

Table::Table()
{
}

Table::Table(unsigned int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			nodes[i][j] = Node();
}

std::vector<Node> Table::GetNeighbors(unsigned int row, unsigned int column)
{
	std::vector<Node> neighbors;
	if (row > 0)
		neighbors.push_back(nodes[row - 1][column]);
	if (column < nodes.size() - 1)
		neighbors.push_back(nodes[row][column + 1]);
	if (row < nodes.size() - 1)
		neighbors.push_back(nodes[row + 1][column]);
	if (column > 0)
		neighbors.push_back(nodes[row][column - 1]);
	return neighbors;
}

bool Table::operator==(const Table & other) const
{
	for (int i = 0; i < nodes.size(); i++)
		for (int j = 0; j < nodes.size(); j++)
			if (nodes[i][j].pressed != other.nodes[i][j].pressed && nodes[i][j].lit != other.nodes[i][j].lit)
				return false;
	return true;
}

bool Table::operator!=(const Table & other) const
{
	return !operator==(other);
}

const Node& Table::getNode(unsigned int row, unsigned int column) const
{
	return nodes[row][column];
}
