#pragma once
#include "Node.h"
#include <vector>

struct Table
{
	std::vector<Node> nodes;
	unsigned int size;

	Table();
	Table(unsigned int size);

	std::vector<Node> GetNeighbors(unsigned int row, unsigned int column);
	std::vector<Node> GetNeighbors(unsigned int index);

	bool operator==(const Table& other) const;
	bool operator!=(const Table& other) const;
	const Node& GetNode(unsigned int row, unsigned int column) const;
	const Node& GetNode(unsigned int index) const;
	
};