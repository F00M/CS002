//Lab 09 - Grading Program

#include <iostream>
#include <string>

using namespace std;

const int MAX_STUDENTS = 25;
const int MAX_EXAMS = 7;
const int MAX_QUIZZES = 5;
const int MAX_FINALS = 1;
const int MAX_MIDTERMS = 1;
const int MAX_QUIZ_SCORE = 50;
const int MAX_MIDTERM_SCORE = 100;
const int MAX_FINAL_SCORE = 100;
const double FINAL_WEIGHT = 0.35;
const double MIDTERM_WEIGHT = 0.25;
const double QUIZ_WEIGHT = 0.40;

struct Student {
    string name;
    int quizScore[MAX_EXAMS];
    double quizPercentage;
    int midtermScore[MAX_EXAMS];
    double midtermPercentage;
    int finalScore[MAX_EXAMS];
    double finalPercentage;
};

struct Classroom {
    string name;
    Student students[MAX_STUDENTS];
};

void InitScore(Classroom& pClassroom);
void getScore(Classroom& pClassroom, int pStudentIndex, string pType);
void calculateScore(Classroom& pClassroom, int pStudentIndex);
double calculateWeightedScore(Classroom& pClassroom, int pStudentIndex);
string getLetterGrade(double pScore);
void printStudent(Classroom& pClassroom, int pMaxStudents);

int main() {
    Classroom Class;
    int numOfStudents = 0;

    InitScore(Class);

    printf("Enter the name of the class: ");
    cin >> Class.name;
    printf("\n");

    while(numOfStudents < MAX_STUDENTS) {
        string name;
        printf("Enter '/' to stop!\n");
        printf("Enter the name of student %d: ", numOfStudents + 1);
        cin >> name;

        if (name == "/") {
            break;
        }

        Class.students[numOfStudents].name = name;

        getScore(Class, numOfStudents, "quiz");
        getScore(Class, numOfStudents, "midterm");
        getScore(Class, numOfStudents, "final");
        calculateScore(Class, numOfStudents);

        numOfStudents++;
    }
    printf("\n");
    printStudent(Class, numOfStudents);

    return 0;
}

void InitScore(Classroom& pClassroom) {
    for (int i = 0; i < MAX_STUDENTS; i++) {
        for (int j = 0; j < MAX_EXAMS; j++) {
            pClassroom.students[i].quizScore[j] = 0;
            pClassroom.students[i].midtermScore[j] = 0;
            pClassroom.students[i].finalScore[j] = 0;
        }
    }
}

void getScore(Classroom& pClassroom, int pStudentIndex, string pType) {
    if (pType == "quiz") {
        for (int i = 0; i < MAX_QUIZZES; i++) {
            printf("Enter the quiz score for student %s, quiz %d (x / %i): ", pClassroom.students[pStudentIndex].name.c_str(), i + 1, MAX_QUIZ_SCORE);
            cin >> pClassroom.students[pStudentIndex].quizScore[i];
        }
    }
    else if (pType == "midterm") {
        for (int i = 0; i < MAX_MIDTERMS; i++) {
            printf("Enter the midterm score for student %s, midterm %d (x / %i): ", pClassroom.students[pStudentIndex].name.c_str(), i + 1, MAX_MIDTERM_SCORE);
            cin >> pClassroom.students[pStudentIndex].midtermScore[i];
        }
    }
    else {
        for (int i = 0; i < MAX_FINALS; i++) {
            printf("Enter the final score for student %s, final %d (x / %i): ", pClassroom.students[pStudentIndex].name.c_str(), i + 1, MAX_FINAL_SCORE);
            cin >> pClassroom.students[pStudentIndex].finalScore[i];
        }
    }
}

void calculateScore(Classroom& pClassroom, int pStudentIndex) {
    int quizTotal = 0;
    int midtermTotal = 0;
    int finalTotal = 0;

    for (int i = 0; i < MAX_QUIZZES; i++) {
        quizTotal += pClassroom.students[pStudentIndex].quizScore[i];
    }

    for (int i = 0; i < MAX_MIDTERMS; i++) {
        midtermTotal += pClassroom.students[pStudentIndex].midtermScore[i];
    }

    for (int i = 0; i < MAX_FINALS; i++) {
        finalTotal += pClassroom.students[pStudentIndex].finalScore[i];
    }

    pClassroom.students[pStudentIndex].quizPercentage = (double)quizTotal / (MAX_QUIZ_SCORE * MAX_QUIZZES);
    pClassroom.students[pStudentIndex].midtermPercentage = (double)midtermTotal / (MAX_MIDTERM_SCORE * MAX_MIDTERMS);
    pClassroom.students[pStudentIndex].finalPercentage = (double)finalTotal / (MAX_FINAL_SCORE * MAX_FINALS);
}

double calculateWeightedScore(Classroom& pClassroom, int pStudentIndex) {
    double percentage = 0;

    percentage += pClassroom.students[pStudentIndex].quizPercentage * QUIZ_WEIGHT;
    percentage += pClassroom.students[pStudentIndex].midtermPercentage * MIDTERM_WEIGHT;
    percentage += pClassroom.students[pStudentIndex].finalPercentage * FINAL_WEIGHT;
    
    return percentage * 100;
}

string getLetterGrade(double pScore) {
    if (pScore >= 90) {
        return "A";
    }
    else if (pScore >= 80) {
        return "B";
    }
    else if (pScore >= 70) {
        return "C";
    }
    else if (pScore >= 60) {
        return "D";
    }
    else {
        return "F";
    }
}

void printStudent(Classroom& pClassroom, int pMaxStudents) {
    for (int i = 0; i < pMaxStudents; i++) {
        printf("For %s:\n", pClassroom.students[i].name.c_str());
        printf("Quiz: %.2f%%\n", pClassroom.students[i].quizPercentage * 100);
        printf("Midterm: %.2f%%\n", pClassroom.students[i].midtermPercentage * 100);
        printf("Final: %.2f%%\n", pClassroom.students[i].finalPercentage * 100);
        printf("Overall Percentage: %.2f%% -> %s\n", calculateWeightedScore(pClassroom, i), getLetterGrade(calculateWeightedScore(pClassroom, i)).c_str());
    }
}