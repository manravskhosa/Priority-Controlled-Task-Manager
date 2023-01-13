// AVL Class File
// Manrav Singh Khosa
// See README

#ifndef avlClass_h
#define avlClass_h

#include "dsexceptions.h"
#include <algorithm>
#include <iostream>

#include "globalStructs.h"

using namespace std;

int indexVal;
int elementCount;

template <typename Comparable>

class AvlTree
{
  public:

    AvlNode<Comparable> *r;

    AvlNode<Comparable> *root;

    AvlTree( ) : root{ nullptr }
      { }
    
    AvlTree( const AvlTree & rhs ) : root{ nullptr }
    {
        root = clone( rhs.root );
    }

    AvlTree( AvlTree && rhs ) : root{ rhs.root }
    {
        rhs.root = nullptr;
    }
    
    ~AvlTree( )
    {
        makeEmpty( );
    }

    AvlTree & operator=( const AvlTree & rhs )
    {
        AvlTree copy = rhs;
        std::swap( *this, copy );
        return *this;
    }
        
    AvlTree & operator=( AvlTree && rhs )
    {
        std::swap( root, rhs.root );
        
        return *this;
    }

    const Comparable & findMin( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException{ };
        return findMin( root )->element;
    }

    const Comparable & findMax( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException{ };
        return findMax( root )->element;
    }

    int findingSize( ) const
    {
        return elementCount;
    }

    bool isEmpty( ) const
    {
        return root == nullptr;
    }

    void printTree( ) const
    {
        if( isEmpty( ) )
            cout << "Empty tree" << endl;
        else
            printTree( root );
    }

    void makeEmpty( )
    {
        makeEmpty( root );
    }

    int indexLocator(Comparable *& x){

        indicesLocator(x, root);
        return indexVal;

    }

    void removeTaskID(Comparable *& x){
        removeMin(x, root);
        return;
        
    }

    AvlNode<Comparable>* insert(Comparable *& x )
    {
        elementCount++;
        Comparable copy = *x;
        return insert(x, root);
    }
     
    AvlNode<Comparable>* insert( Comparable *&& x )
    {
        elementCount++;
        return insert( std::move( x ), root ); 
    }
     
    void remove( AvlNode<Comparable> * x )
    {
        elementCount--;
        remove( x, root );
    }

  private:

    void removeMin(Comparable *& x, AvlNode<Comparable> *t){
        if (t != nullptr){
            removeMin(x, (t->left));

            if (x->taskID == (*t).element.taskID){
                remove(t);
            }

            removeMin(x, (t->right));
        }

    }

    AvlNode<Comparable>* insert( Comparable *& x, AvlNode<Comparable> * & t )
    {
        if( t == nullptr ){
            t = new AvlNode<Comparable>{ *x, nullptr, nullptr };
            r = *&t;
        }
        else if( (x->taskID) < ((*t).element).taskID )
            insert( x, t->left );
        else if( ((*t).element).taskID < (x->taskID) )
            insert( x, t->right );
        balance( t );
        return r;
    }

    AvlNode<Comparable>* insert( Comparable *&& x, AvlNode<Comparable> * & t )
    {
        if( t == nullptr ){
            t = new AvlNode<Comparable>{ std::move( x ), nullptr, nullptr };
            r = *&t;
        }
        else if( (x->taskID) < ((*t).element).taskID )
            insert( std::move( x ), t->left );
        else if( ((*t).element).taskID < (x->taskID) )
            insert( std::move( x ), t->right );
        balance( t );
        return r;
    }
     
    void remove( AvlNode<Comparable> * x, AvlNode<Comparable> * t )
    {
        
        if( t == nullptr )
            return;   
        
        if(( (*x).element).taskID < ((*t).element).taskID )
            remove( x, t->left );
        
        else if( ((*t).element).taskID  < ((*x).element).taskID )
            remove( x, t->right );
        else if( t->left != nullptr && t->right != nullptr ) 
        {
            t->element = findMin( t->right )->element;
            remove( t, t->right );
        }
        else
        {
            AvlNode<Comparable> *oldNode = t;
            t = ( t->left != nullptr ) ? t->left : t->right;
            ((*oldNode).element).taskID = 0;
            ((*oldNode).element).heapIndex = 0;
            oldNode = nullptr;
            delete oldNode;
        }
        
        balance( t );
        
    }
    
    static const int ALLOWED_IMBALANCE = 1;

    void balance( AvlNode<Comparable> * & t )
    {
        if( t == nullptr )
            return;
        if( height( t->left ) - height( t->right ) > ALLOWED_IMBALANCE )
            if( height( t->left->left ) >= height( t->left->right ) )
                rotateWithLeftChild( t );
            else
                doubleWithLeftChild( t );
        else
        if( height( t->right ) - height( t->left ) > ALLOWED_IMBALANCE ){
            if( height( t->right->right ) >= height( t->right->left ) )
                rotateWithRightChild( t );
            else
                doubleWithRightChild( t );
        }
        t->height = max( height( t->left ), height( t->right ) ) + 1;
    }
    
    AvlNode<Comparable> * findMin( AvlNode<Comparable> *t ) const
    {
        if( t == nullptr )
            return nullptr;
        if( t->left == nullptr )
            return t;
        return findMin( t->left );
    }

    AvlNode<Comparable> * findMax( AvlNode<Comparable> *t ) const
    {
        if( t != nullptr )
            while( t->right != nullptr )
                t = t->right;
        return t;
    }
    

    void makeEmpty( AvlNode<Comparable> * & t )
    {
        elementCount = 0;
        if( t != nullptr )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = nullptr;
    }

    void indicesLocator(Comparable *& x, AvlNode<Comparable> *t){
        if (t != nullptr){
            indicesLocator(x, t->left);
            if(x->taskID == (*t).element.taskID){
                indexVal = (*t).element.heapIndex;
            }
            indicesLocator(x, t->right);
        }
    }

    void printTree( AvlNode<Comparable> *t ) const
    {

        if( t != nullptr)
        {
            
            printTree( t->left );

            if(((*t).element).taskID != 0 && ((*t).element).heapIndex != 0){
                cout << "AVL NODE | Task ID = " << ((*t).element).taskID << " | ";
                cout << "Corresponding Binary Heap Index = " << ((*t).element).heapIndex << endl;
            }

            printTree( t->right );
        }
        
    }

    AvlNode<Comparable> * clone( AvlNode<Comparable> *t ) const
    {
        if( t == nullptr )
            return nullptr;
        else
            return new AvlNode<Comparable>{ t->element, clone( t->left ), clone( t->right ), t->height };
    }

    int height( AvlNode<Comparable> *t ) const
    {
        return t == nullptr ? -1 : t->height;
    }

    int max( int lhs, int rhs ) const
    {
        return lhs > rhs ? lhs : rhs;
    }

    void rotateWithLeftChild( AvlNode<Comparable> * & k2 )
    {
        AvlNode<Comparable> *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
        k1->height = max( height( k1->left ), k2->height ) + 1;
        k2 = k1;
    }

    void rotateWithRightChild( AvlNode<Comparable> * & k1 )
    {
        AvlNode<Comparable> *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1->height = max( height( k1->left ), height( k1->right ) ) + 1;
        k2->height = max( height( k2->right ), k1->height ) + 1;
        k1 = k2;
    }

    void doubleWithLeftChild( AvlNode<Comparable> * & k3 )
    {
        rotateWithRightChild( k3->left );
        rotateWithLeftChild( k3 );
    }

    void doubleWithRightChild( AvlNode<Comparable> * & k1 )
    {
        rotateWithLeftChild( k1->right );
        rotateWithRightChild( k1 );
    }
};

#endif