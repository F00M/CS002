// Group Discussion - Struct Classroom Enhancement

#include <iostream>
#include <string>

using namespace std;

const int exerciseMAX = 5;
const int studentMAX = 25;

struct exercise {
    int score = 0;
    int point = 0;
};

struct student {
    string name;
    exercise exerciseList[exerciseMAX];
    int numberOfExercisesTaken = 0;
};

struct classroom {
    student studentList[studentMAX];
    string roomNumber, name;
};
 exercise printTotalExercise(student pStudent, int bonusScore);
 exercise printTotalExercise(student& pStudent);
 void initializeStudentExercises(student& pStudent);
 void getExerciseData(exercise& pExercise, int i);
 exercise addBonusToExercise(exercise pExercise, int bonusScore);

 int main() {
    student sStudent;
    classroom sClassroom;
    initializeStudentExercises(sStudent);
    int numberOfExercises, numberOfStudents;

    printf("Classroom name: ");
    getline(cin, sClassroom.name);

    printf("Room number: ");
    getline(cin, sClassroom.roomNumber);

    do {
        printf("Number of students: ");
        cin >> numberOfStudents;

        printf("Number of Exercises: ");
        cin >> numberOfExercises;
    }
    while (numberOfStudents > studentMAX || numberOfExercises > exerciseMAX);

    for (int i = 0; i < numberOfStudents; i++) {
        printf("Student %d Name: ", i + 1);
        cin >> sStudent.name;

        for (int j = 0; j < numberOfExercises; j++) {
            sStudent.numberOfExercisesTaken++;
            getExerciseData(sStudent.exerciseList[j], j+1);
        }

        printTotalExercise(sStudent);
        printf("After Bonus: ");
        printTotalExercise(sStudent, 5);
        printf("\n");
    }

    return 0;
 }

exercise printTotalExercise(student pStudent, int bonusScore) {
    pStudent.exerciseList[0].score += bonusScore;
    return printTotalExercise(pStudent);
}

exercise printTotalExercise(student& pStudent) {
    exercise totalExercise;

    for (int i = 0; i < pStudent.numberOfExercisesTaken; i++) {
        totalExercise.score += pStudent.exerciseList[i].score;
        totalExercise.point += pStudent.exerciseList[i].point;
    }

    printf("%s scored %d out of %d points, percentage: %.2f\n", pStudent.name.c_str(), totalExercise.score, totalExercise.point, (float)totalExercise.score / totalExercise.point * 100);

    return totalExercise;
}

void initializeStudentExercises(student& pStudent) {
    pStudent.name = "No Body";
    for (int i = 0; i < exerciseMAX; i++) {
        pStudent.exerciseList[i].score = 0;
        pStudent.exerciseList[i].point = 0;
    }
}

void getExerciseData(exercise& pExercise, int i) {
    printf("Exercise %d score: ", i);
    cin >> pExercise.score;
    printf("Exercise %d point: ", i);
    cin >> pExercise.point;
}

exercise addBonusToExercise(exercise pExercise, int bonusScore) {
    exercise retExercise = pExercise;
    retExercise.score += bonusScore;

    return retExercise;
}