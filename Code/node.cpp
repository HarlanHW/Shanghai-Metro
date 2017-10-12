#include "node.h"

Node::Node()
{
    ;
}

bool Node::operator ==(const Node b)
{
    if(this->name==b.name)
        return true;
    else
        return false;
}
