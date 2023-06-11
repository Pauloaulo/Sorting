#include "Sorting.h"
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>

vector<int> load_from(const string& archiveName);

int main() {
    vector<int> array = load_from("num.1000.1.in");
    Sorting* s = new Sorting();

    //Execução BubbleSort
    auto startBubble = chrono::high_resolution_clock::now();
    s->bubbleSort(array);
    auto endBubble = chrono::high_resolution_clock::now();
    chrono::duration<double> dBubble = endBubble - startBubble;
    double tBubble = dBubble.count();
    cout << "BubbleSort: " << tBubble << " segundos" << endl;

    //Execução SelectionSort
    auto startSelection = chrono::high_resolution_clock::now();
    s->selectionSort(array);
    auto endSelection = chrono::high_resolution_clock::now();
    chrono::duration<double> dSelection = endSelection - startSelection;
    double tSelection = dSelection.count();
    cout << "SelectionSort: " << tSelection << " segundos" << endl;

    //Execução InsertionSort
    auto startInsertion = chrono::high_resolution_clock::now();
    s->insertionSort(array);
    auto endInsertion = chrono::high_resolution_clock::now();
    chrono::duration<double> dInsertion = endInsertion - startInsertion;
    double tInsertion = dInsertion.count();
    cout << "InsertionSort: " << tInsertion << " segundos" << endl;

    //Execução MergeSort
    auto startMerge = chrono::high_resolution_clock::now();
    s->mergeSort(array, 0, array.size() - 1);
    auto endMerge = chrono::high_resolution_clock::now();
    chrono::duration<double> dMerge = endMerge - startMerge;
    double tMerge = dMerge.count();
    cout << "MergeSort: " << tMerge << " segundos" << endl;

    //Execução QuickSort
    auto startQuick = chrono::high_resolution_clock::now();
    s->quickSort(array, 0, array.size() - 1);
    auto endQuick = chrono::high_resolution_clock::now();
    chrono::duration<double> dQuick = endQuick - startQuick;
    double tQuick = dQuick.count();
    cout << "QuickSort: " << tQuick << " segundos" << endl;

    return 0;
}

vector<int> load_from(const string& archiveName) {
    ifstream archive(archiveName);
    string line;

    vector<int> v;

    while(getline(archive, line)) {
        line.erase(0, line.find_first_not_of(" \t\r\n"));
        line.erase(line.find_last_not_of(" \t\r\n") + 1);

        v.push_back(stoi(line));
    }
    return v;
}