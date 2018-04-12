#include "Table.h"

Table::Table()
{
}

Table::Table(unsigned int size)
	: size(size)
{
	nodes.resize(size * size);
	for (int i = 0; i < size * size; i++)
	{
			nodes[i] = Node();
	}
}

std::vector<Node> Table::GetNeighbors(unsigned int row, unsigned int column)
{
	std::vector<Node> neighbors;
	if (row > 0)
		neighbors.push_back(nodes[(row - 1) * size + column]);
	if (column < size)
		neighbors.push_back(nodes[row * size + column + 1]);
	if (row < size)
		neighbors.push_back(nodes[(row + 1) * size + column]);
	if (column > 0)
		neighbors.push_back(nodes[row * size + column - 1]);
	return neighbors;
}

std::vector<Node> Table::GetNeighbors(unsigned int index)
{
	std::vector<Node> neighbors;
	if (index >= size)
		neighbors.push_back(nodes[index - size]);
	if (index % size != size - 1)
		neighbors.push_back(nodes[index + 1]);
	if (index + size < nodes.size())
		neighbors.push_back(nodes[index + size]);
	if (index % size != 0)
		neighbors.push_back(nodes[index - 1]);
	return neighbors;
}

bool Table::operator==(const Table & other) const
{
	for (int i = 0; i < nodes.size(); i++)
		if (nodes[i].pressed != other.nodes[i].pressed && nodes[i].lit != other.nodes[i].lit)
			return false;
	return true;
}

bool Table::operator!=(const Table & other) const
{
	return !operator==(other);
}

const Node& Table::GetNode(unsigned int row, unsigned int column) const
{
	return nodes[size * row + column];
}

const Node& Table::GetNode(unsigned int index) const
{
	return nodes[index];
}
