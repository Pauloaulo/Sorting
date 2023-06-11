#include "Sorting.h"

vector<int> Sorting::bubbleSort(vector<int> vector) {
    int n = vector.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            if (vector[i] > vector[j]) {
                swap(vector[i], vector[j]);
            }
        }
    }

    return vector;
}

vector<int> Sorting::selectionSort(vector<int> vector) {
    int n = vector.size();

    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (vector[j] < vector[min]) {
                min = j;
            }
        }
        swap(vector[i], vector[min]);
    }

    return vector;
}

vector<int> Sorting::insertionSort(vector<int> vector) {
    int n = vector.size();

    for (int i = 1; i < n; i++) {
        int current = vector[i];
        int j = i;

        while (j > 0 && vector[j - 1] > current) {
            vector[j] = vector[j - 1];
            j--;
        }
        vector[j] = current;
    }

    return vector;
}

void Sorting::merge(vector<int>& array, int ini, int mid, int post) {
    int n1 = mid - ini + 1;
    int n2 = post - mid;

    vector<int> leftVector(n1);
    vector<int> rightVector(n2);

    for (int i = 0; i < n1; i++) {
        leftVector[i] = array[ini + i];
    }
    for (int j = 0; j < n2; j++) {
        rightVector[j] = array[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = ini;

    while (i < n1 && j < n2) {
        if (leftVector[i] <= rightVector[j]) {
            array[k] = leftVector[i];
            i++;
        } else {
            array[k] = rightVector[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = leftVector[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = rightVector[j];
        j++;
        k++;
    }
}

vector<int> Sorting::mergeSort(vector<int> vector, int ini, int post) {
    if (ini < post) {
        int mid = ini + (post - ini) / 2;

        mergeSort(vector, ini, mid);
        mergeSort(vector, mid + 1, post);

        merge(vector, ini, mid, post);
    }

    return vector;
}

int Sorting::partition(vector<int> vector, int ini, int post) {
    int pivot = vector[post];
    int i = ini - 1;

    for (int j = ini; j < post; j++) {
        if (vector[j] <= pivot) {
            i++;
            swap(vector[i], vector[j]);
        }
    }

    swap(vector[i + 1], vector[post]);

    return i + 1;
}

vector<int> Sorting::quickSort(vector<int> vector, int ini, int post) {
    if (ini < post) {
        int pivotIndex = partition(vector, ini, post);

        quickSort(vector, ini, pivotIndex - 1);
        quickSort(vector, pivotIndex + 1, post);
    }

    return vector;
}