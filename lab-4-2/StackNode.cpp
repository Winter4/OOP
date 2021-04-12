#include "StackNode.h"

StackNode::StackNode()
{
    data = nullptr;
    prev = nullptr;
}

StackNode::StackNode(Car& car)
{
    data = new Car(car);
    prev = nullptr;
}

StackNode::~StackNode() { if (data != nullptr) delete data; }