// Test Driver File
// Manrav Singh Khosa
// See README

#include <iostream>
#include "binaryHeapClass.h"
#include "avlClass.h"
#include "PQ.h"

using namespace std;

int main()
{

    cout << "*******Test Case 1: Testing With NULL Values & An Empty PQ*******" << endl;
    PQ<int> * P = new PQ<int>;

    cout << "Testing isEmpty(), Expected Output: TRUE, Actual Output: ";
    if(P->isEmpty() == 1){
        cout << "TRUE" << endl;
    }
    else{
        cout << "FALSE" << endl;
    }

    cout << "Testing size(), Expected Output: 0, Actual Output: " << P->size() << endl;

    cout << "Testing displayPQ(), Expected Output: Empty Tree, Actual Output: ";
    P->displayPQ();
    cout << endl;

    cout << "Testing updatePriority FXN, Expected Behaviour: Insert New Node (As Tree Is Empty) Expected Output: 1 Binary Heap Node, 1 AVL Tree Node" << endl;
    cout << "Printing PQ Structures Post-Update: " << endl;
    P->updatePriority(13, 7);
    P->displayPQ();

    cout << "Testing findMin(), Expected Output: 13, Actual Output: " << P->findMin() << endl;

    cout << "Testing Insert FXN, Expected Behaviour: Insert New Node Expected Output: 2 BH Nodes, 2 AVL Tree Nodes" << endl;
    cout << "Printing PQ Structures Post-Insertion: " << endl;
    P->insert(2, 1);
    P->displayPQ();

    cout << "Testing deleteMin(), Expected Output: Delete Task ID 2 (Smallest/Most Urgent Priority), = 2 Actual Output: = " << P->deleteMin() << endl;
    
    cout << "Testing makeEmpty(), Expected Display Output: Empty Tree, Actual Output: ";
    P->makeEmpty();
    P->displayPQ();
    cout << endl << endl << endl;
    
    cout << "*******Done With Test Case 1, Free'Ing Heap Memory Of PTR*******" << endl;
    delete P;

    cout << "*******Test Case 2: Testing With 5 Inserted PQ Nodes*******";
    cout << endl << endl << endl;
    PQ<int> * P2 = new PQ<int>;

    cout << "Testing Insert FXN, Expected Behaviour: Insert New Node Expected Output: 5 BH Nodes, 5 AVL Tree Nodes" << endl;
    cout << "Printing PQ Structures Post-Insertion: " << endl;
    P2->insert(22, 1);
    P2->insert(33, 7);
    P2->insert(44, 8);
    P2->insert(55, 13);
    P2->insert(66, 22);
    P->displayPQ();

    cout << "Testing isEmpty(), Expected Output: FALSE, Actual Output: ";
    if(P2->isEmpty() == 1){
        cout << "TRUE" << endl;
    }
    else{
        cout << "FALSE" << endl;
    }

    cout << "Testing size(), Expected Output: 5, Actual Output: " << P2->size() << endl;


    cout << "Testing updatePriority FXN, Expected Behaviour: Update PQ Node (Task ID = 22, Priority = 1) To (Task ID = 22, Priority = 17)" << endl;
    cout << "Printing PQ Structures Post-Update: " << endl;
    P2->updatePriority(22, 17);
    P2->displayPQ();

    cout << "Testing findMin(), Expected Output: 33, Actual Output: " << P2->findMin() << endl;

    cout << "Testing deleteMin(), Expected Output: Delete Task ID 33 (Smallest/Most Urgent Priority), = 33 Actual Output: = " << P2->deleteMin() << endl;
    
    cout << "Testing DisplayPQ(), Should Have Removed Task ID = 33, Priority = 7 PQ Node" << endl;
    P2->displayPQ();

    cout << "Testing size(), Expected Output: 4, Actual Output: " << P2->size() << endl;

    cout << "Testing makeEmpty(), Expected Display Output: Empty Tree, Actual Output: ";
    P2->makeEmpty();
    P2->displayPQ();

    cout << endl << endl << endl;
    cout << "*******Done With Test Case 2, Free'Ing Heap Memory Of PTR*******" << endl;
    delete P2;
    cout << "*******Test Case 3: Testing With 7 Inserted PQ Nodes*******";

    cout << endl << endl << endl;

    cout << "DisplayPQ() is irrelevant in this test case, as it is not part of the criteria. Natural testing..." << endl;
    PQ<int> * P3 = new PQ<int>;

    P3->insert(1, 1);
    P3->insert(2, 2);
    P3->insert(3, 3);
    P3->insert(4, 4);
    P3->insert(5, 5);
    P3->insert(6, 6);
    P3->insert(7, 7);

    cout << "Testing size(), Expected Output: 7, Actual Output: " << P3->size() << endl;
    cout << "Testing findMin(), Expected Output: 1, Actual Output: " << P3->findMin() << endl;
    cout << "Testing deleteMin(), Expected Output: Delete Task ID 1 (Smallest/Most Urgent Priority), = 1 Actual Output: = " << P3->deleteMin() << endl;
    cout << "Testing size(), Expected Output: 6, Actual Output: " << P3->size() << endl;
    cout << "Testing updatePriority FXN, Expected Behaviour: Update PQ Node (Task ID = 7, Priority = 7) To (Task ID = 7, Priority = 1)" << endl;
    P3->updatePriority(7, 1);
    cout << "via FindMin(), If updatePriority WORKED Expected Output: 7, Actual Output: " << P3->findMin() << endl;
    P3->makeEmpty();
    cout << "Testing makeEmpty(), Expected Output: TRUE (empty), Actual Output: ";
    if(P->isEmpty() == 1){
        cout << "TRUE" << endl;
    }
    else{
        cout << "FALSE" << endl;
    }

    delete P3;

    return 0;
}

