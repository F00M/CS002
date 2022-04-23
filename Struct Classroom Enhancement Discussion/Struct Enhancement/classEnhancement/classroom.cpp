// Group Discussion - Class Enhancement

#include <iostream>
#include <string>

using namespace std;

const int MAX_EXERCISE = 5;
const int MAX_STUDENTS = 25;

class Exercise {
    private:
        int score = 0;
        int point = 0;
    public:
        int getScore();
        void setScore(int pScore);
        int getPoint();
        void setPoint(int pPoint);

        void getData(int i);

        double getAvg();
};

class Student {
    private:
        Exercise exerciseList[MAX_EXERCISE];
        int numberOfExerciseTaken = 0;
    public:
        string name;

        int getNumberOfExerciseTaken();
        void setNumberOfExerciseTaken(int pNumberOfExerciseTaken);

        Exercise* getExerciseList(int i);
        void getExerciseData(int i);

        void initStudentExercises();
        int getTotalScore();
        int getTotalPoint();
        void getBonusScore(int pBonus);
};

class Classroom {
    private:
        string courseName;
        int roomNumber;
    public:
        Student studentList[MAX_STUDENTS];
        int studentCount = 0;
        void initStudentList();
        void setCourseName(string pCourseName);
        string returnCourseName();
        void setRoomNumber(int pRoomNumber);
        int returnRoomNumber();

};

int main() {
    Student sStudent;
    Classroom sClassroom;
    // sStudent.initStudentExercises();

    string courseName;
    printf("Course Name: ");
    cin >> courseName; 
    sClassroom.setCourseName(courseName);

    int roomNumber;
    printf("Room Number: ");
    cin >> roomNumber;
    sClassroom.setRoomNumber(roomNumber);

    sClassroom.initStudentList();

    for (int i = 0; i < sClassroom.studentCount; i++) {
        Exercise totalExercise;
        int numberOfExercise;
        sStudent.setNumberOfExerciseTaken(0);
        printf("For %s:\n", sClassroom.studentList[i].name.c_str());
        printf("Number of Exercises? ");
        cin >> numberOfExercise;
        for (int j = 0; j < numberOfExercise; j++) {
            sStudent.setNumberOfExerciseTaken(sStudent.getNumberOfExerciseTaken() + 1);
            sStudent.getExerciseData(j);
        }
        totalExercise.setScore(sStudent.getTotalScore());
        totalExercise.setPoint(sStudent.getTotalPoint());
        printf("%s scored %d out of %d, percentage: %.2f\n", sClassroom.studentList[i].name.c_str(), totalExercise.getScore(), totalExercise.getPoint(), totalExercise.getAvg());
        printf("After Bonus: ");

        sStudent.getBonusScore(5);
        totalExercise.setScore(sStudent.getTotalScore());
        totalExercise.setPoint(sStudent.getTotalPoint());
        printf("%s scored %d out of %d, percentage: %.2f\n", sClassroom.studentList[i].name.c_str(), totalExercise.getScore(), totalExercise.getPoint(), totalExercise.getAvg());
        printf("\n");
    }

    return 0;
}

int Exercise::getScore() {
    return score;
}

void Exercise::setScore(int pScore) {
    score = pScore;
}

int Exercise::getPoint() {
    return point;
}

void Exercise::setPoint(int pPoint) {
    point = pPoint;
}

void Exercise::getData(int i) {
    printf("Score for Exercise %d? ", i);
    cin >> score;
    printf("Point for Exercise %d? ", i);
    cin >> point;
}

double Exercise::getAvg() {
    return ((double)score / point) * 100;
}

void Classroom::initStudentList() {
    printf("Student Names ('/' to stop): \n");
    for (int i = 0; i < MAX_STUDENTS; i++) {
        string name;
        cin >> name;

        if (name == "/") {
            break;
        }
        studentList[i].name = name;
        studentCount++;
    }
    printf("\n");
}

void Classroom::setCourseName(string pCourseName) {
    courseName = pCourseName;
}

string Classroom::returnCourseName() {
    return courseName;
}

void Classroom::setRoomNumber(int pRoomNumber) {
    roomNumber = pRoomNumber;
}

int Classroom::returnRoomNumber() {
    return roomNumber;
}

// --------------------------------------------------

int Student::getNumberOfExerciseTaken() {
    return numberOfExerciseTaken;
}

void Student::setNumberOfExerciseTaken(int pNumberOfExerciseTaken) {
    numberOfExerciseTaken = pNumberOfExerciseTaken;
}

Exercise* Student::getExerciseList(int i) {
    return &exerciseList[i];
}

void Student::getExerciseData(int i) {
    exerciseList[i].getData(i + 1);
}

void Student::initStudentExercises() {
    name = "No Body";
    for (int i = 0; i < MAX_EXERCISE; i++) {
        exerciseList[i].setPoint(0);
        exerciseList[i].setScore(0);
    }
}

int Student::getTotalScore() {
    int retScore = 0;
    //printf("Get Total Score: ");
    for (int i = 0; i < numberOfExerciseTaken; i++) {
        // printf("%d, ", exerciseList[i].getScore());
        retScore += exerciseList[i].getScore();
    }
    printf("\n");
    return retScore;
}

int Student::getTotalPoint() {
    int retPoint = 0;
    for (int i = 0; i < numberOfExerciseTaken; i++) {
        retPoint += exerciseList[i].getPoint();
    }
    return retPoint;
}

void Student::getBonusScore(int pBonus) {
    exerciseList[0].setScore(exerciseList[0].getScore() + pBonus);
    // printf("%d\n", exerciseList[0].getScore());
}