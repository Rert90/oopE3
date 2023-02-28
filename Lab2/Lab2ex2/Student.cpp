#include "Student.h"
#include "iostream"


void Student::setName(char* StudentName)
{
    this->StudentName = new char[strlen(StudentName) + 1];
    strcpy(this->StudentName, StudentName);
}
char* Student::getName() {
    return StudentName;
}


void Student::setGradeMath(float gradeMath) {
    if(gradeMath>=1&& gradeMath<=10) {
        this->gradeMath = gradeMath;
    }
}

float Student::getGradeMath() {
    return gradeMath;
}

void Student::setGradeEnglish(float gradeEnglish) {
    this->gradeEnglish = gradeEnglish;
}

float Student::getGradeEnglish() {
    return gradeEnglish;
}

void Student::setGradeHistory(float gradeHistory) {
    this->gradeHistory = gradeHistory;
}

float Student::getGradeHistory() {
    return gradeHistory;
}

float Student::getAverageGrade() {
    float average = (gradeMath + gradeEnglish + gradeHistory) / 3;
    std::cout << "Average grade: " << average << std::endl;
}
