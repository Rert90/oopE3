#include "StudentCompare.h"
#include "iostream"
using namespace std;
void compareByName( Student& s1,Student& s2) {
    if(strcmp(s1.getName(),s2.getName())==0){
        cout<<"0\n";}
    if(strcmp(s1.getName(),s2.getName())==-1){
        cout<<"-1\n";}
    if(strcmp(s1.getName(),s2.getName())==1){
        cout<<"1\n";}
}

void compareByMathGrade(Student& s1,  Student& s2) {
    if (s1.getGradeMath() == s2.getGradeMath()) {
        cout<<"0\n";
    }
    int var= s1.getGradeMath() < s2.getGradeMath() ? -1 : 1;
    cout<<var<<endl;
}

void compareByEnglishGrade(Student& s1,Student& s2) {
    if (s1.getGradeEnglish() == s2.getGradeEnglish()) {
        cout<<"0\n";
    }
    int var=s1.getGradeEnglish() < s2.getGradeEnglish() ? -1 : 1;
    cout<<var<<endl;
}
void compareByHistoryGrade(Student& s1,Student& s2){
    if(s1.getGradeHistory()==s2.getGradeHistory()){
        cout<<"0\n";
    }
    int var= s1.getGradeHistory()<s2.getGradeHistory()?-1: 1;
    cout<<var<<endl;
}
void compareByAverageGrade( Student& s1,  Student& s2){
    if(s1.getAverageGrade()==s2.getAverageGrade()){
        cout<<"0\n";
    }
    int var= s1.getAverageGrade()<s2.getAverageGrade()? -1 : 1;
    cout<<var<<endl;
}
