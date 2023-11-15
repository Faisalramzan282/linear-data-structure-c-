// #include <iostream>
// #include <vector>
// class MinHeap {
// private:
//     std::vector<int> heap;   //vector to represent dynamic array
//     void heapifyUp(int index);    // when inserting key, to up side comparsion
//     void heapifyDown(int index);  // Restore heap property after extracting the minimum key
// public:
//     MinHeap() {}
//     void insert(int key);
//     int extractMin();
//     int getMin() const;
//     bool isEmpty() const;
//     void printHeap() const;
// };
// void MinHeap::insert(int key) {
//     // Add the key to the end of the heap
//     heap.push_back(key);
//     heapifyUp(heap.size() - 1);
// }
// void MinHeap::heapifyUp(int index) {
//     while (index > 0) {
//         int parentIndex = (index - 1) / 2;
//         if (heap[index] < heap[parentIndex]) {
//             std::swap(heap[index], heap[parentIndex]);
//             index = parentIndex;  // Move to the parent
//         } else {
//             break;  // Heap property is restored
//         }
//     }
// }
// int MinHeap::extractMin() {
//     if (isEmpty()) {
//         std::cerr << "Heap is empty. Cannot extract minimum.\n";
//         return -1;  // Assuming keys are non-negative, -1 can indicate an error
//     }
//     int minKey = heap[0];  // Minimum key is at the root
//     heap[0] = heap.back();  // Replace the root with the last key
//     heap.pop_back();        // Remove the last key
//     heapifyDown(0);
//     return minKey;
// }

// // Helper function to restore heap property after extracting the minimum key
// void MinHeap::heapifyDown(int index) {
//     while (true) {
//         int leftChild = 2 * index + 1;
//         int rightChild = 2 * index + 2;
//         int smallest = index;  // Assume the current index is the smallest
//         if (leftChild < heap.size() && heap[leftChild] < heap[smallest]) {
//             smallest = leftChild;
//         }
//         if (rightChild < heap.size() && heap[rightChild] < heap[smallest]) {
//             smallest = rightChild;
//         }
//         // If the smallest is not the current index, swap them
//         if (smallest != index) {
//             std::swap(heap[index], heap[smallest]);
//             index = smallest;  // Move to the smaller child
//         } else {
//             break;  // Heap property is restored
//         }
//     }
// }
// // Function to get the minimum key without extracting it
// int MinHeap::getMin() const {
//     if (isEmpty()) {
//         std::cerr << "Heap is empty. Cannot get minimum.\n";
//         return -1;  // Assuming keys are non-negative, -1 can indicate an error
//     }
//     return heap[0];  // Minimum key is at the root
// }
// // Function to check if the heap is empty
// bool MinHeap::isEmpty() const {
//     return heap.empty();
// }
// // Function to print the elements of the heap
// void MinHeap::printHeap() const {
//     if (isEmpty()) {
//         std::cout << "Heap is empty.\n";
//         return;
//     }
//     std::cout << "Min-Heap: ";
//     for (int key : heap) {
//         std::cout << key << " ";
//     }
//     std::cout << "\n";
// }

// int main() {
//     MinHeap minHeap;

//     // Insert keys into the min-heap
//     minHeap.insert(3);
//     minHeap.insert(1);
//     minHeap.insert(4);
//     minHeap.insert(1);
//     minHeap.insert(5);
//     minHeap.insert(9);
//     minHeap.insert(2);
//     minHeap.insert(2);
//     // Print the min-heap
//     minHeap.printHeap();

//     // Extract and print the minimum key
//     std::cout << "Minimum key: " << minHeap.extractMin() << "\n";

//     // Print the min-heap after extraction
//     minHeap.printHeap();

//     // Get and print the minimum key without extracting it
//     std::cout << "Minimum key without extraction: " << minHeap.getMin() << "\n";

//     return 0;
// }
//============================================================================
//=================MAX_HEAP===================================================
//using arrays
// #include<iostream>
// void heapify(int array_in[], int array_size, int subtree_root_index);
// void construct_heap(int array_in[], int array_size) {
//     int last_non_leaf_node = (array_size / 2) - 1;
//     for (int subtree_root_index = last_non_leaf_node; subtree_root_index >= 0; subtree_root_index -= 1) {
//         heapify(array_in, array_size, subtree_root_index);
//     }
// }
// void heapify(int array_in[], int array_size, int subtree_root_index) {
//     int largest_value = subtree_root_index;
//     int left = 2 * subtree_root_index + 1;
//     int right = 2 * subtree_root_index + 2;
//     if (left < array_size && array_in[left] > array_in[largest_value]) {
//         largest_value = left;
//     }
//     if (right < array_size && array_in[right] > array_in[largest_value]) {
//         largest_value = right;
//     }
//     if (largest_value != subtree_root_index) {
//         std::swap(array_in[subtree_root_index], array_in[largest_value]);
//         heapify(array_in, array_size, largest_value);
//     }
// }
// void print_heap(int array_in[], int array_size) {
//     std::cout << "Printing values at each node in heap" << std::endl;
//     for (int index = 0; index < array_size; index += 1) {
//         std::cout << array_in[index] << std::endl;
//         // if(2*index+1>=array_size&&2*index+2>=array_size){
//         //     std::cout<<index<<" is leaf node";
//         // }else{
//         //     std::cout<<index <<" is not leaf node";
//         // }

//     }
// }
// int main() {
//     int array_in[] = {3, 5, 8, 10, 17, 11, 13, 19, 22, 24, 29};
//     int array_size = sizeof(array_in) / sizeof(array_in[0]);
//     construct_heap(array_in, array_size);
//     print_heap(array_in, array_size);
//     return 0;
// }
//---------------------------------using adjacency lists------------
