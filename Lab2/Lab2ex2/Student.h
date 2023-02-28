
#pragma once
#ifndef LAB2EX1_STUDENT_H
#define LAB2EX1_STUDENT_H
#include "cstring"

class Student {
char* StudentName;
float gradeMath;
float gradeEnglish;
float gradeHistory;

public:
void setName(char* StudentName);
char* getName();
void setGradeMath(float gradeMath);
float getGradeMath();
void setGradeEnglish(float gradeEnglish);
float getGradeEnglish();
void setGradeHistory(float gradeHistory);
float getGradeHistory();
float getAverageGrade();

};


#endif
