#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H
using namespace std;

class binarySearch{
public:
bool Search(int array[], int x, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2;

    // If found at mid, then return it
    if (array[mid] == x)
      return true;

    // Search the left half
    if (array[mid] > x)
      return Search(array, x, low, mid - 1);

    // Search the right half
    return Search(array, x, mid + 1, high);
  }

  return false;
}
};
#endif