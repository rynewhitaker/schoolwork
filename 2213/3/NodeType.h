#ifndef NODETYPE_H
#define NODETYPE_H

template <class T>
struct NodeType {
   T info;
   NodeType<T>* link;
};

#endif
