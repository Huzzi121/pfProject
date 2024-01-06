#include<stdio.h>
#include<stdlib.h>

#define maxsub 5    //defined the number of subject early 
#define maxstd 30   //defined the number of max students early


struct Student
{
    char name[25];
    double grades[maxsub];
};

void addstd(struct Student students[],int *numstd)
{
    if(*numstd<maxstd)
    {
        printf("Enter the name of the students:");
        scanf("%s",students[*numstd].name);

    for(int i=1;i<=maxsub;i++)
    {
        printf("Enter grade for subject %d:"i);
        scnaf("%f",&students[*numstd].grades[i]);
    }

    (*numstd)++;
    printf("Student added successfully!\n");
    }
    else
    {
        printf("Max number of student reached!\n");
    }
}

