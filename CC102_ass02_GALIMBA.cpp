#include <iostream>
#include <iomanip>
using namespace std;

void processGrades(float* matrix, int students, int subjects) {
    float highest = -1.0;

    cout << "\n--- Grade Matrix ---" << endl;
    for (int i = 0; i < students; i++) {
        float sum = 0;
        cout << "Student " << i + 1 << ": ";

        for (int j = 0; j < subjects; j++) {
            float currentGrade = *(matrix + (i * subjects) + j);

            cout << setw(8) << fixed << setprecision(2) << currentGrade;

            sum += currentGrade;
            if (currentGrade > highest) {
                highest = currentGrade;
            }
        }

        float average = sum / subjects;
        cout << " | Average: " << setw(6) << average << endl;
    }

    cout << "\n----------------------------" << endl;
    cout << "Highest Grade in Matrix: " << highest << endl;
    cout << "----------------------------" << endl;
}

int main() {
    char choice;
do{
    int rows, cols;

    cout << "Enter the number of students: ";
    cin >> rows;
    cout << "Enter the number of subjects: ";
    cin >> cols;

    float grades[rows][cols];

    for (int i = 0; i < rows; i++) {
        cout << "Enter grades for Student " << i + 1 << ":" << endl;
        for (int j = 0; j < cols; j++) {
            cout << "  Subject " << j + 1 << ": ";
            cin >> grades[i][j];
        }
    }

    processGrades((float*)grades, rows, cols);

    cout << "Do you want to repeat? ";
    cin >> choice;
}while (toupper(choice=='y'));
    return 0;
}
