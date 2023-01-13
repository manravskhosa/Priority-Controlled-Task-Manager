// PQ Class File
// Manrav Singh Khosa
// See README

#ifndef PQ_H
#define PQ_H

#include <iostream>
#include "binaryHeapClass.h"
#include "avlClass.h"
#include "globalStructs.h"

// PQ class
//
// Template parameter: ID
// Constructors:
// PQ --> constructs a new empty queue
// PQ( tasks, priorities ) --> constructs a new queue with a given set of task IDs and priorities 
// ******************PUBLIC OPERATIONS*********************
// void insert( x, p )       --> Insert task ID x with priority p 
// ID findMin( )  --> Return a task ID with smallest priority, without removing it 
// ID deleteMin( )   --> Remove and return a task ID with smallest priority 
// void updatePriority( x, p )   --> Changes priority of ID x to p (if x not in PQ, inserts x);
// bool isEmpty( )   --> Return true if empty; else false
// int size() --> return the number of task IDs in the queue 
// void makeEmpty( )  --> Remove all task IDs (and their priorities)
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template <typename ID>
// ID is the type of task IDs to be used; the type must be Comparable (i.e., have < defined), so IDs can be AVL Tree keys.

class PQ
{

  public:
    BinaryHeap<bhNode<ID>> b;
    AvlTree<avNode<ID>> a;

    // Constructor
    // Initializes a new empty PQ
    PQ(){}

    // Constructor
    // Initializes a new PQ with a given set of tasks IDs and priorities  
    //      priority[i] is the priority for ID task[i] 
    PQ( const std::vector<ID> & tasks, const std::vector<int> & priorities ){}

    ~PQ( ) // Deconstructor, Empties PQ 
    {
      makeEmpty();
    }
    
    // Emptiness check 
    bool isEmpty( ) const{
      if (a.isEmpty() == 1 && b.isEmpty() == 1){
        return 1;
      }
      return 0;
    }

    // Deletes and Returns a task ID with minimum priority
    //    Throws exception if queue is empty
    const ID & deleteMin(){
      if(size() == 0){
        throw UnderflowException{};
      }
      else{
        int * lowestKeyID = new int;
        *lowestKeyID = findMin();
        b.deleteMinBh();
        b.syncIndices();

        avNode<ID> * a3 = new avNode<ID>;
        a3->taskID = *lowestKeyID;
        a.removeTaskID(a3);

        // a.elementCount--;
        return *lowestKeyID;
      }
    }

    // Returns an ID with minimum priority without removing it
    //     Throws exception if queue is empty
    const ID & findMin() const{
      if(size() == 0){
        throw UnderflowException{};
      }
      else{
        bhNode<ID> * b2 = new bhNode<ID>;
        b2 = b.findMinBh();
        int * taskIDCopy = new int;
        *taskIDCopy = ((b2->avlAddress)->element).taskID;
        return *taskIDCopy;
      }
    }

    // Insert ID x with priority p.
    void insert(const ID & x, int p ){
        avNode<ID> * a1 = new avNode<ID>;        
        bhNode<ID> * b1 = new bhNode<ID>;
        a1->taskID = x; 
        b1->priority = p; 
        AvlNode<avNode<ID>>* ptr = reinterpret_cast<AvlNode<avNode<ID>>*>(a.insert(a1));
        b1->avlAddress = ptr; 
        b.insert(b1); 
        b.syncIndices();
    }

    // Update the priority of ID x to p
    //  Inserts x with p if s not already in the queue
    void updatePriority( const ID & x, int p ){
      int indexOfTaskID;
      avNode<ID> * a2 = new avNode<ID>;
      a2->taskID = x;
      indexOfTaskID = a.indexLocator(a2);
      if(indexOfTaskID != 0){
        b.updateBhPriority(indexOfTaskID, p);
        b.syncIndices();
      }
      else{
        insert(x, p);
      }
    }

    // Return the number of task IDs in the queue
    int size() const{
      return a.findingSize();
    }

    // Delete all IDs from the PQ
    void makeEmpty( ){
      a.makeEmpty();
      b.makeEmpty();
      return;
    }

    // Showcases State Of Binary Heap & AVL Tree, Both Coming Together To Implement PQ
    void displayPQ(){

      if(isEmpty() == 1){
        cout << "Empty Tree" << endl;
        return;
      }
      else{
        cout << "----------DISPLAYING PQ COMPONENTS----------" << endl;
        cout << "Printing Binary Heap: Vertically, In 'i' Chronological Order " << endl;
        b.displayBinaryHeap();
        cout << "Printing AVL, Sorted:" << endl;
        a.printTree();
        cout << "--------------------------------------------" << endl;
      }
    }

    private:


};
#endif
