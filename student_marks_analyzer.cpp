#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    if (n <= 0) {
        cout << "Invalid number of students" << endl;
        return 0;
    }
    vector<int> marks(n);
    double sum = 0;
    for (int i = 0; i < n; i++) {
        cout << "Marks of student " << i + 1 << ": ";
        cin >> marks[i];
        sum += marks[i];
    }
    sort(marks.begin(), marks.end(), greater<int>());
    cout << "Top 3 marks: ";
    for (int i = 0; i < min(3, n); i++) cout << marks[i] << " ";
    cout << "\nAverage score: " << sum / n << endl;
    return 0;
}



/*
Sample Output:
Enter number of students: 5
Marks of student 1: 78
Marks of student 2: 92
Marks of student 3: 65
Marks of student 4: 88
Marks of student 5: 71
Top 3 marks: 92 88 78
Average score: 78.8
*/
