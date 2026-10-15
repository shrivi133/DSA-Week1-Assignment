#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> readArray(const string &label) {
    int n;
    cout << "Enter number of " << label << ": ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) cin >> a[i];
    return a;
}

// 1. Linear Search - O(n)
void linearSearch() {
    vector<int> a = readArray("elements");
    int key;
    cout << "Enter element to search: ";
    cin >> key;
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] == key) {
            cout << "Found at index " << i << endl;
            return;
        }
    }
    cout << "Not found" << endl;
}

// 2. Binary Search on a sorted array - O(log n)
void binarySearch() {
    vector<int> a = readArray("elements (enter in SORTED order)");
    int key;
    cout << "Enter element to search: ";
    cin >> key;
    int low = 0, high = (int)a.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == key) {
            cout << "Found at index " << mid << endl;
            return;
        } else if (a[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << "Not found" << endl;
}

// 3. Bubble Sort with swap count - O(n^2)
void bubbleSortSwaps() {
    vector<int> a = readArray("elements");
    int n = a.size(), swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swaps++;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    cout << "Sorted array: ";
    for (int x : a) cout << x << " ";
    cout << "\nTotal swaps: " << swaps << endl;
}

// 4. Reverse array in place (no extra array) - O(n), O(1) space
void reverseArray() {
    vector<int> a = readArray("elements");
    int i = 0, j = (int)a.size() - 1;
    while (i < j) {
        swap(a[i], a[j]);
        i++;
        j--;
    }
    cout << "Reversed array: ";
    for (int x : a) cout << x << " ";
    cout << endl;
}

int main() {
    int choice;
    do {
        cout << "\n1. Linear Search\n2. Binary Search\n3. Bubble Sort (count swaps)\n"
             << "4. Reverse Array\n0. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: linearSearch(); break;
            case 2: binarySearch(); break;
            case 3: bubbleSortSwaps(); break;
            case 4: reverseArray(); break;
        }
    } while (choice != 0);
    return 0;
}
