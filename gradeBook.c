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

    void filehandling(struct Studen students[],int numstd)
    {
        FILE *file=fopen("gradebook.txt","w");
        if(file==NULL)
        {
            printf("Error opening file!!");
            return; //or we can also use exit(1) also;
        }

        for(int i=0;i<numstd;i++)
        {
            fprintf(file,"name:%s\n",students[i].name);
            fprintf(file,"grades: ");

            for(int j=1;j<=maxsub;j++)
            {
                fprint(file,"%lf",students[i].grades[j]);
            }
            fprintf(file,"\n\n");
        }
        fclose(file);
        printf("GradeBook saved to file Succesfully!!");
    }
}

