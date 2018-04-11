#pragma once
#include <iostream>
#include <vector>

struct Node
{
	bool lit;
	bool pressed;

	Node(bool lit = false, bool pressed = false);

	void Eval(std::vector<Node> neighbors);

	bool operator==(const Node& other) const;
	bool operator!=(const Node& other) const;
};