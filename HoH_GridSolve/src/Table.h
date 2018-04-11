#pragma once
#include "Node.h"
#include <vector>

struct Table
{
	std::vector<std::vector<Node>> nodes;

	Table();
	Table(unsigned int size);

	std::vector<Node> GetNeighbors(unsigned int row, unsigned int column);

	bool operator==(const Table& other) const;
	bool operator!=(const Table& other) const;
	const Node& getNode(unsigned int row, unsigned int column) const;
	
};