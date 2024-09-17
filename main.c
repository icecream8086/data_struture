#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Num_Students 30

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
        student[i].average = (student[i].score[0] + student[i].score[1] + student[i].score[2]) / Num_Students;
    }
}

void find_highest_score(Student student[], int num_students)
{
    int i;
    float highest_score = -1;
    Student top_student;
    for (i = 0; i < num_students; ++i)
    {
        if (student[i].average > highest_score)
        {
            highest_score = student[i].average;
            top_student = student[i];
        }
    }
    printf("Top Student\n");
    printf("Name: %s\n", top_student.name);
    printf("Average score: %.2f\n", top_student.average);
}

void find_lowest_score(Student student[], int num_students)
{
    int i;
    float lowest_score = 1000;
    Student low_student;
    for (i = 0; i < num_students; ++i)
    {
        if (student[i].average < lowest_score)
        {
            lowest_score = student[i].average;
            low_student = student[i];
        }
    }
    printf("Low Student\n");
    printf("Name: %s\n", low_student.name);
    printf("Average score: %.2f\n", low_student.average);
}
void calc_total_average_score(Student student[], int num_students)
{
    int i;
    float total_average = 0;
    for (i = 0; i < num_students; ++i)
    {
        total_average = total_average + student[i].average;
    }
    total_average = total_average / Num_Students;
    printf("total Average Score\n");
    printf("Average: %.2f\n", total_average);
}
void beauty_print()
{
    char line[81] = "";
    for(int i = 0; i < 80; i++)
    {
        line[i] = '*';
    }
    printf("%s\n", line);
}

void print_student(Student student[], int num_students)
{
    int i;
    for (i = 0; i < num_students; ++i)
    {
        beauty_print();
        printf("student  %d\n", student[i].id);
        printf("Name: %s\n", student[i].name);
        printf("Score 1: %.2f\n", student[i].score[0]);
        printf("Score 2: %.2f\n", student[i].score[1]);
        printf("Score 3: %.2f\n", student[i].score[2]);
        printf("Average: %.2f\n", student[i].average);
        beauty_print();
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

        printf("Enter student %d id: ", i + 1);
        scanf("%d", &student[i].id);
        if (student[i].id < 0 || student[i].id > Num_Students)
        {
            printf("Invalid input Student_id \n");
            exit(1);
        }
        printf("Enter student %d name: ", i + 1);
        scanf("%s", student[i].name);
        if (strlen(student[i].name) == 0 || strcmp(student[i].name, " ") == 0)
        {
            printf("Invalid input Student_name \n");
            exit(1);
        }
        printf("Enter student %d score 1: ", i + 1);
        scanf("%f", &student[i].score[0]);
        float x = student[i].score[0];
        if (x < 0 || x > 200)
        {
            printf("Invalid input Student_score \n");
            exit(1);
        }

        printf("Enter student %d score 2: ", i + 1);
        scanf("%f", &student[i].score[1]);
        printf("Enter student %d score 3: ", i + 1);
        scanf("%f", &student[i].score[2]);
    }
    beauty_print();
    calc_average(student, Num_Students);
    print_student(student, Num_Students);

    beauty_print();
    find_highest_score(student, Num_Students);
    beauty_print();
    find_lowest_score(student, Num_Students);
    beauty_print();
    calc_total_average_score(student, Num_Students);

}