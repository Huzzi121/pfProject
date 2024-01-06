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

    for(int i=0;i<maxsub;++i)
    {
        printf("Enter grade for subject %d:",i+1);
        scanf("%lf",&students[*numstd].grades[i]);
    }

    (*numstd)++;
    printf("Student added successfully!\n");
    }
    else
    {
        printf("Max number of student reached!\n");
    }
}

    void filehandling(struct Student students[],int numstd)
    {
        FILE *file=fopen("gradebook.txt","w");
        if(file==NULL)
        {
            printf("Error opening file!!\n");
            return; //or we can also use exit(1) also;
        }

        for(int i=0;i<numstd;++i)
        {
            fprintf(file,"name:%s\n",students[i].name);
            fprintf(file,"grades: ");

            for(int j=0;j<maxsub;++j)
            {
                fprintf(file,"%.2lf",students[i].grades[j]);
            }
            fprintf(file,"\n");
        }
        fclose(file);
        printf("GradeBook saved to file Succesfully!!\n");
    }

    void displayresult(struct Student students[],int numstd)
    {
        printf("\nGradeBook Result Card\n");

        for(int i=0;i<numstd;++i)
        {
            printf("Student Name: %s\n",students[i].name);
            printf("Subject Grades: ");

            for(int j=0;j<maxsub;++j)
            {
                printf("%.2lf",students[i].grades[j]);
            }

            printf("\n");
        }
    }

int main()
{
    struct Student students[maxstd];
    int numstd=0;
    int choice;

    

       
        while (1)
        {
           
            printf("\nStudent Gradebook Menu:\n");
            printf("1. Add Student\n");
            printf("2. Save to File\n");
            printf("3. Display Report\n");
            printf("4. Exit\n");
            printf("Enter your choice (1/2/3/4): ");
             scanf("%d", &choice);
             if(choice==1)
             {
                addstd(students,&numstd);
             }
             else if(choice==2)
             {
                filehandling(students,numstd); 
             }
             else if(choice==3)
             {
                displayresult(students,numstd);
             }
             else if(choice==4)
             {
                printf("Exiting...");
                exit(0);
             }
             else
             {
                printf("invalid choice. Please enter 1,2,3 or 4.\n");
    
             }


        }
       
        return 0;


}
/*  i copied this code to dev C++ and file handling wasa working perfectly
    i think its an ide problem which is out of my capacity to fix so kindly
    sir bear with me.*/