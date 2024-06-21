#include <bits/stdc++.h>
using namespace std;


// Function to convert grade to grade points
double gradeToPoints(char grade) {
    switch (grade) {
        case 'A': case 'a':
            return 5.0;
        case 'B': case 'b':
            return 4.0;
        case 'C': case 'c':
            return 3.0;
        case 'D': case 'd':
            return 2.0;
        case 'E': case 'e':
            return 1.0;
        case 'F': case 'f':
            return 0.0;
        default:
            return -1.0; // Invalid grade
    }
}

// Function to input grades and credits for a subject
void inputSubject(const string& subjectName, int& credits, char& grade) {
    cout << subjectName << " - Enter credits: ";
    cin >> credits;
    cout << subjectName << " - Enter grade (A, B, C, D, F): ";
    cin >> grade;
}

// Function to calculate GPA for a student based on grades and credits
double calculateGPA(int physicsCredits, char physicsGrade,
                    int chemistryCredits, char chemistryGrade,
                    int mathCredits, char mathGrade,
                    int englishCredits, char englishGrade,
                    int hindiCredits, char hindiGrade) {
    double totalCredits = physicsCredits + chemistryCredits + mathCredits + englishCredits + hindiCredits;
    double totalGradePoints = (physicsCredits * gradeToPoints(physicsGrade))
                            + (chemistryCredits * gradeToPoints(chemistryGrade))
                            + (mathCredits * gradeToPoints(mathGrade))
                            + (englishCredits * gradeToPoints(englishGrade))
                            + (hindiCredits * gradeToPoints(hindiGrade));

    return totalGradePoints / totalCredits;
}

int main() {
    int numStudents = 0;
    cout << "Enter number of students: ";
    cin >> numStudents;

    for (int i = 1; i <= numStudents; ++i) {
        cout << "Enter the subjects for student " << i << endl;

        int physicsCredits, chemistryCredits, mathCredits, englishCredits, hindiCredits;
        char physicsGrade, chemistryGrade, mathGrade, englishGrade, hindiGrade;

        inputSubject("Physics", physicsCredits, physicsGrade);
        inputSubject("Chemistry", chemistryCredits, chemistryGrade);
        inputSubject("Math", mathCredits, mathGrade);
        inputSubject("English", englishCredits, englishGrade);
        inputSubject("Hindi", hindiCredits, hindiGrade);

        double semesterGPA = calculateGPA(physicsCredits, physicsGrade,
                                          chemistryCredits, chemistryGrade,
                                          mathCredits, mathGrade,
                                          englishCredits, englishGrade,
                                          hindiCredits, hindiGrade);

        // Display student's semester GPA
        cout << "Student " << i << " - Semester GPA: " << fixed << setprecision(2) << semesterGPA << endl;
    }

    return 0;
}
