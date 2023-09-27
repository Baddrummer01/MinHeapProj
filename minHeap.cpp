#include <vector>
#include "minHeap.h"

using namespace std;

void minHeap::siftUp(int pos) {
  while (pos > 0 && heap[pos] < heap[(pos-1)/2]) {
    swap(heap[pos], heap[(pos-1)/2]);
    pos = (pos-1)/2;
  }
}

void minHeap::siftDown(int pos) {
  int smallest = pos;
  int left = 2 * pos + 1;
  int right = 2 * pos + 2;

  while (left < heap.size()) {
    //if the left branch of the tree is smaller than the current node, move left
    if (heap[left] < heap[smallest]) {
      smallest = left;
    }

    //if the right branch of the tree is smaller than the current node, move right
    if (right < heap.size() && heap[right] < heap[smallest]) {
      smallest = right;
    }

    //if neither of the precious conditions happened, break the loop
    if (smallest == pos) {
      break;
    }

    swap(heap[pos], heap[smallest]);
    pos = smallest;
    left = 2 * pos + 1;
    right = 2 * pos + 2;
  }
}

//Should build the heap from bottom-up
minHeap::minHeap(vector<int> data) {
  heap = data;
  for (int i = (heap.size() - 2)/2; i >= 0; i--) {
    siftDown(i);
  }
}

//Insert value into heap
void minHeap::insert(int value) {
  heap.push_back(value);
  siftUp(heap.size()-1);
}

//Removes minimum value
int minHeap::removeMin() {
  int minValue = heap[0];
  //puts the back value at the front then sifts it down
  heap[0] = heap.back();
  heap.pop_back();
  siftDown(0);
  return minValue;
}
