#include <iostream>
#include "Student.h"
#include "StudentCompare.h"
int main() {
    Student s1;
    Student s2;
    s1.setName("Madalina");
    s2.setName("Madalina");
    compareByName(s1,s2);
    s1.setGradeHistory(4);
    s2.setGradeHistory(2);
    compareByHistoryGrade(s1,s2);
    s1.setGradeEnglish(5);
    s1.setGradeMath(10);
    s1.getAverageGrade();
    return 0;
}
