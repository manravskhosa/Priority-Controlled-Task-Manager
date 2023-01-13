// Global Structures File
// Manrav Singh Khosa
// See README

#ifndef avlNode_h
#define avlNode_h

template<typename Comparable>

struct AvlNode
    {
        Comparable element;
        AvlNode   *left;
        AvlNode   *right;
        int       height;

        AvlNode( const Comparable & ele, AvlNode *lt, AvlNode *rt, int h = 0 )
          : element{ ele }, left{ lt }, right{ rt }, height{ h } { }
        
        AvlNode( Comparable && ele, AvlNode *lt, AvlNode *rt, int h = 0 )
          : element{ std::move( ele ) }, left{ lt }, right{ rt }, height{ h } { }
    };

template <typename ID>

struct avNode{
    ID taskID;
    int heapIndex;
};

template <typename ID> 

struct bhNode{
    int priority;
    AvlNode<avNode<ID>>* avlAddress;
};



#endif