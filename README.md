# priorityQueue
This project is an implementation of a priority queue using AvlTree and BinaryHeap classes, with custom avNode and bhNode data types for efficient storage and organization. The avNode stores Task-ID and index of the information in BinaryHeap, while bhNode stores priority value and a pointer to avNode for easy access and updates to Task-ID.

## Target Machine
The target machine used for implementation and testing was running 64-Bit Linux Ubuntu 22.04.1 LTS 

# Author
Myself (Manrav Singh Khosa)
Last Modified: Jan 13/2023

# What Is A Priority Queue?
A priority queue is a data structure that stores elements with a priority value associated with them, where elements with a higher priority value are dequeued (removed) before elements with a lower priority value. It allows us to maintain a queue of elements, where the element with the highest priority is always at the front of the queue, and the element with the lowest priority is at the back of the queue.
A priority queue allows us to efficiently manage and process elements based on their priority levels. This can be useful in a variety of applications, such as scheduling tasks, managing resources, or implementing algorithms that require prioritization of elements. 

# Implementation Overview
The priority queue program I have developed is a complex and delicate marvel of coding that I am extremely proud of which I spent many long, frustrated nights on. I used two key data structures, AvlTree and BinaryHeap, to make it all happen.

First, I integrated the AvlTree class through 'avlClass.h'. This class is responsible for storing a new data type I created called avNode. This avNode data type holds two pieces of information: the Task-ID of the priority queue node (which can be any data type the user chooses) and the index of the rest of the information within the binary heap. To make things more interesting, the avNode data type is not just stored in the tree, I nested it within the 'element' sector of the AvlNode data type, which is specialized to have members relevant to be pushed in and out of an AVL tree.

Second, I integrated the BinaryHeap class through 'binaryHeapClass.h'. This class is responsible for storing another new data type I created called bhNode. This bhNode also holds two pieces of information: the integer priority value and a pointer to the avNode within the AVLNode data type. This was necessary so I could hold the address of the actual AVLNode for the priority queue nodes address within the bhNode at all times, and easily access and change the Task-ID.

It's important to note that all three of these new data types I implemented (avNode, bhNode, and the AVL Tree node) are not stored in any one class or private filing, rather, they have their own header file called 'globalStructs.h' to ensure every function that needs to access them, can. This function is referred to as ‘globalStructs.h’ as it holds the global structures I always need to access. All in all, this priority queue program is truly a work of art and I am honored to share it with you."

# Methods Implemented
## Insert 
The insert function is the key part of the priority queue program. It starts by declaring two pointers, a1 and b1, for the avNode and bhNode data types respectively. Then it updates the Task ID and priority values in the relevant data types. The program calls the insert function in the AVLTree, which is modified to sort the tree by Task ID values instead of binary heap indexes. After inserting a new AVLNode data type, it returns the address of the new node, which is then saved in the binary heap by reinterpret cast function. The syncIndices function is implemented to keep the binary heap index updated with the new AvlNode address.

## FindMin
The FindMin function was implemented to find the element with the lowest priority value in the priority queue. It is more efficiently implemented using the Binary Heap, as the Binary Heap always holds the smallest priority value as the root. The function can be implemented with O(1) time efficiency and returns a reference to the root. The implementation involves declaring a pointer of type bhNode, calling a helper function to find the root and returning the Task-ID of the PQ node with the smallest (most urgent) priority. The task ID is obtained by using the integrated address within the bhNode data type to go to the AVL tree node and return it through helper functions.

## DeleteMin
The DeleteMin function uses the FindMin function to find the task ID with the lowest priority, but it also performs some additional operations. It calls a helper function within the BinaryHeap called deleteMinBh, which uses std::move, decrements the size counter in the heap, percolates down and synchronizes the indices with the AVL Tree to ensure communication of the deletion. It also decrements the elementCount counter to AVLTree which is used later for size and intelligently accesses the AVL tree remove() to completely delete the minimum node.

## UpdatePriority 
Updating the priority in the priority queue is dependent on the Binary Heap data structure as it stores the priority values. The AVLTree is used to update the indices accordingly after the Binary Heap is rearranged. The program uses a helper function within the AVL tree called indexLocator, to locate the task ID in the heap array efficiently. If the task ID is not found, a new PQ node is inserted with the given parameters. Then the program calls a binary heap helper function with the index of the task ID and the new priority. The updateBhPriority function updates the priority and analyzes if this priority is greater or less than the old one and percolates up or down respectively. Lastly, a syncIndices() call is made to update the AVL tree after the heap is rearranged.

## isEmpty
This was one of the simpler programs to implement. It performs firstly a check in the
AVL tree. If our root is null, the tree is empty. Next, we check the Binary Heap. It checks if our current size is zero, and if so, the tree is empty. This is implemented through the PQ function using two helper functions within each file.

## Size
This implementation involved a global integer value in our AvlTree, called
elementCount. It is incremented and decremented appropriately whenever we insert or delete a PQ, and holds count of how many PQ nodes we have at any given moment. It is always accurate, and we simply return this value.

## makeEmpty
We use our pointers to each data structure to call the structures respective individual
makeEmpty functions. For the AVLTree, this means recursively going through all nodes and deleting them via a built in textbook helper function. For the binary heap, this means we can set our current array size to zero and essentially be free of all collected PQ node data!
