#include "Node.h"

Node::Node(bool lit, bool pressed)
	: lit(lit), pressed(pressed)
{
}

void Node::Eval(std::vector<Node> neighbors)
{
	unsigned int switches = (lit) ? 1 : 0;
	for (Node node : neighbors)
		if (node.pressed)
			lit = !lit;
}

bool Node::operator==(const Node & other) const
{
	return lit == other.lit || pressed == other.pressed;
}

bool Node::operator!=(const Node & other) const
{
	return !operator==(other);
}

