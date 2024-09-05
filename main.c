#include <stdio.h>
#include <stdlib.h>

#define Num_Students 3

typedef struct
{
    int id;
    char name[50];
    float score[3];
    float average;
} Student;

void calc_average(Student student[], int num_students)
{
    int i;
    for (i = 0; i < num_students; ++i)
    {
        /* code */
        student[i].average = (student[i].score[0] + student[i].score[1] + student[i].score[2]) / 3;
    }
}

void print_student(Student student[], int num_students)
{
    int i;
    for (i = 0; i < num_students; ++i)
    {
        /* code */
        printf("+++++++++++++++++++++++++++++++++++++++++++\n");
        printf("Student %d\n", student[i].id);
        printf("Name: %s\n", student[i].name);
        printf("Score 1: %.2f\n", student[i].score[0]);
        printf("Score 2: %.2f\n", student[i].score[1]);
        printf("Score 3: %.2f\n", student[i].score[2]);
        printf("Average: %.2f\n", student[i].average);
        printf("+++++++++++++++++++++++++++++++++++++++++++\n");
    }
}
int main()
{
    Student student[Num_Students];
    Student top_student;
    float highest_score = -1;
    int i;
    for (i = 0; i < Num_Students; ++i)
    {
        /* code */
        printf("Enter student %d id: ", i + 1);
        scanf("%d", &student[i].id);
        printf("Enter student %d name: ", i + 1);
        scanf("%s", student[i].name);
        printf("Enter student %d score 1: ", i + 1);
        scanf("%f", &student[i].score[0]);
        printf("Enter student %d score 2: ", i + 1);
        scanf("%f", &student[i].score[1]);
        printf("Enter student %d score 3: ", i + 1);
        scanf("%f", &student[i].score[2]);
    }
    calc_average(student, Num_Students);
    print_student(student, Num_Students);
    for ( i = 0; i < Num_Students; ++i)
    {
        /* code */
        if (student[i].average > highest_score)
        {
            highest_score = student[i].average;
            top_student = student[i];

        }
    }
    printf("+++++++++++++++++++++++++++++++++++++++++++\n");
    printf("Top Student\n");
    printf("Name: %s\n", top_student.name);
    
}
