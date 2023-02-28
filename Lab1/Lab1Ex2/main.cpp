#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
    char sen[200];
    char vec[200][200];
    int i=0;
    int k=0;
    char* p;
    scanf("%[^\n]%*c",sen);
    p=strtok(sen," ");
    while(p){
         k++;
    strcpy(vec[i],p);
        i++;
    p=strtok(NULL," ");
    }
    for(i=0;i<k-1;i++)
        for(int j=i+1;j<k;j++)
            if(strlen(vec[i])<strlen(vec[j]))
                swap(vec[i],vec[j]);
        else if(strlen(vec[i])==strlen(vec[j]))
            if(strcmp(vec[i],vec[j])==1)
                swap(vec[i],vec[j]);
    for(i=0;i<k;i++)
    printf("%s\n",vec[i]);
    return 0;
}
