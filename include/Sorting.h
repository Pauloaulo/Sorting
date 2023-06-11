#include <iostream>
#include <vector>
using namespace std;

class Sorting {
public:
    vector<int> bubbleSort(vector<int> vector);
    vector<int> selectionSort(vector<int> vector);
    vector<int> insertionSort(vector<int> vector);
    void merge(vector<int>& vector, int ini, int mid, int post);
    vector<int> mergeSort(vector<int> vector, int ini, int post);
    int partition(vector<int> vector, int ini, int post);
    vector<int> quickSort(vector<int> vector, int ini, int post);
};