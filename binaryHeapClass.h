// Binary Heap Class File
// Manrav Singh Khosa
// See README

#ifndef binaryHeapClass_h
#define binaryHeapClass_h

#include "dsexceptions.h"
#include "globalStructs.h"
#include <vector>

using namespace std;

template <typename Comparable>

class BinaryHeap
{
  public:
    explicit BinaryHeap( int capacity = 100 )
      : array( capacity + 1 ), currentSize{ 0 }
    {
    }

    explicit BinaryHeap( const vector<Comparable> & items )
      : array( items.size( ) + 10 ), currentSize{ items.size( ) }
    {
        for( int i = 0; i < items.size( ); ++i )
            array[ i + 1 ] = items[ i ];
        buildHeap( );
    }


    bool isEmpty( ) const
      { return currentSize == 0; }


    Comparable* findMinBh() const
    {
        Comparable * bNode = new Comparable;
        *bNode = array[1];
        return bNode;
    }

    void updateBhPriority(int indexOfTaskID, int newPriority){
        int oldPriority = array[indexOfTaskID].priority;
        array[indexOfTaskID].priority = newPriority;
        if(newPriority < oldPriority){
            int hole = ++currentSize;
            Comparable copy = array[indexOfTaskID];
            array[ 0 ] = std::move( copy );
            for( ; (array[indexOfTaskID].priority) < ((array[ hole / 2 ]).priority); hole /= 2 )
                array[ hole ] = std::move( array[ hole / 2 ] );
            array[ hole ] = std::move( array[ 0 ] );
        array[indexOfTaskID] = std::move(array[currentSize--]);
        percolateDown(indexOfTaskID);
        }
        if(oldPriority < newPriority){
            percolateDown(indexOfTaskID);
        }

    }

    void insert(Comparable *&x)
    {
        if( currentSize == array.size( ) - 1 )
        array.resize( array.size( ) * 2 );

        int hole = ++currentSize;

        Comparable copy = *x;

        array[ 0 ] = std::move( copy );
        for( ; (x->priority) < ((array[ hole / 2 ]).priority); hole /= 2 )
            array[ hole ] = std::move( array[ hole / 2 ] );
        array[ hole ] = std::move( array[ 0 ] );

    }

    void syncIndices()
    {
        for (int i = 0; i<=currentSize; i++){
            ((array[i].avlAddress)->element).heapIndex = i;
        }    
    }


    void deleteMinBh( )
    {
        array[1] = std::move(array[currentSize--]);
        percolateDown(1);
    }

    void makeEmpty( )
      { currentSize = 0; }

    void displayBinaryHeap()
    {
        for(int i = 1; i <= currentSize; i++){
            cout << "BINARY HEAP NODE | Priority = " << (array[i]).priority << " | Corresponding AVLNode Address =";
            cout << &((array[i]).avlAddress) << endl;
        }
        cout << endl;
        return;
    }


  private:
    int                currentSize;  
    vector<Comparable> array;        

    void buildHeap( )
    {
        for( int i = currentSize / 2; i > 0; --i )
            percolateDown( i );
    }

    void percolateDown( int hole )
    {
        int child;
        Comparable tmp = std::move( array[ hole ] );

        for( ; hole * 2 <= currentSize; hole = child )
        {
            child = hole * 2;
            if( child != currentSize && (array[ child + 1 ].priority) < (array[ child ].priority) )
                ++child;
            if( (array[ child ].priority) < (tmp.priority) )
                array[ hole ] = std::move( array[ child ] );
            else
                break;
        }
        array[ hole ] = std::move( tmp );
    }
};

#endif
