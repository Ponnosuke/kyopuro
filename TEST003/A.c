#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {
    MAN = 1,
    WOMAN = 2,
};

typedef struct {
    char name[30];
    int year;
    int seibetu;
}person;

void inputPerson(int i, person *p);
void outputPerson(person *p);

int main(){
    int i = 0;
    person p[3];
    for(i = 0; i < 3; i++){
        inputPerson(i+1, &p[i]);
    }

    for(i = 0; i < 3; i++){
        outputPerson(&p[i]);
    }

    return 0;
}

void inputPerson(int i, person *p){
    printf("%d人目\n", i);
    printf("Name: ");
    scanf("%s", p->name);
    printf("Year: ");
    scanf("%d", &p->year);
    printf("Seibetu(1:man, 2:woman): ");
    scanf("%d", &p->seibetu);

    return;
}

void outputPerson(person *p){
    printf("Name: %s\n", (*p).name);
    printf("Year: %d", p->year);
    printf("Seibetu: ");
    if(p->seibetu == MAN){
        printf("man");
    }
    else{
        printf("woman");
    }
    printf("\n");
}