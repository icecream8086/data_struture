#include <stdio.h>
#include <stdlib.h>

void beauty_print()
{
    char line[81] = "";
    for (int i = 0; i < 80; i++)
    {
        line[i] = '*';
    }
    printf("%s\n", line);
}

typedef struct student
{
    int id;
    char name[20];
    float score1;
    float score2;
    float score3;
    float average;
    struct student *next;
} Student;

Student *create_student()
{
    Student *s = (Student *)malloc(sizeof(Student));
    s->next = NULL;
    return s;
}

void input_studnets(Student *s)
{
    printf("请输入学号\n");
    scanf("%d", &(s->id));
    printf("name\n");
    scanf("%s", &(s->name));
    printf("成绩\n");
    scanf("%f %f %f", &(s->score1), &(s->score2), &(s->score3));
    s->average = (s->score1 + s->score2 + s->score3) / 3;
}

void find_max_average_student(Student *head)
{
    Student *max_student = head;
    Student *current = head->next;
    while (current != NULL)
    {
        if (current->average > max_student->average)
        {
            /* code */
            max_student = current;
        }
        current = current->next;
        beauty_print();
        printf("最高分学生信息：\n");
        printf("学号：%d\n", max_student->id);
        printf("姓名：%s\n", max_student->name);
        printf("平均分：%f\n", max_student->average);
        printf("成绩1：%f\n", max_student->score1);
        printf("成绩2：%f\n", max_student->score2);
        printf("成绩3：%f\n", max_student->score3);
        beauty_print();
    }
}

void find_highest_aveage_score(Student *head)
{
    Student *max_student = head;
    Student *current = head->next;
    while (current != NULL)
    {
        if (current->average > max_student->average)
        {
            /* code */
            max_student = current;
        }
        current = current->next;
        beauty_print();
        printf("最高分学生信息：\n");
        printf("学号：%d\n", max_student->id);
        printf("姓名：%s\n", max_student->name);
        printf("平均分：%f\n", max_student->average);
        printf("成绩1：%f\n", max_student->score1);
        printf("成绩2：%f\n", max_student->score2);
        printf("成绩3：%f\n", max_student->score3);
        beauty_print();
    }
}
int main(int argc, char const *argv[])
{

    Student *head = create_student();
    Student *current = head;
    int i;
    for ( i = 0; i < 3; i++)
    {
        /* code */
        current->next = create_student();
        input_studnets(current->next);
        current = current->next;
    }
    find_max_average_student(head);
    find_highest_aveage_score(head);
    current = head;
    while (current != NULL)
    {
        Student *temp = current;
        current = current->next;
        free(temp);
    }
    // free up ram
}
