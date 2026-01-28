# include <stdio.h>

#define subjects 6 // Total Subject in Semester Exam

// Function Declarations (To Make Program Easy & clean)

void studentdetails(char name[],int *roll, int marks[]); //(* is pointer)
int totalmarks(int marks[]);
float Percentage(int total);
float CGPA(float percent);
int Pass(int marks[]);
void Result(char name[], int roll, int marks[],int total,float percent,float cgpa);


//Taking Student Details & Marks
void studentdetails(char name[],int *roll,int marks[])
{
    int i;

    printf("Enter Student Name:");
    scanf("%s",name);
    printf("Enter Roll Number:");
    scanf("%d",roll);

    for (i=0; i<subjects; i++)
    {
        printf("Enter Marks of Suject %d:",i+1);
        scanf("%d",&marks[i]);
    }
}

// Calculating Total Marks
int totalmarks(int marks[])
{
    int i , sum=0;
    
    for(i=0;i<subjects;i++)
    {
        sum=sum+marks[i];
    }
    return sum;
}

// Calculating Percentage
float Percentage (int total)
{
    return total /(float) subjects;
}

// Calculating CGPA
float CGPA(float percent)
{
    return percent /10;
}

// Checking Pass or Fail
int Pass(int marks[])
{
    int i;
    for (i=0; i<subjects ; i++)
    {
        if (marks[i]<39) 
        return 0;
    }
    return 1;
}

// Fianl Result
void Result(char name[],int roll ,int marks[],int total ,float percent,float cgpa)
{
    int i;

    printf("\n----- Semester Exam Result -----\n");
    printf("Student Name:%s\n",name);
    printf("Roll No :%d\n",roll);

    for (i=0; i<subjects ; i++)
    {
        printf("Subject %d Marks : %d\n",i+1,marks[i]);

    }

    printf("Total Marks :%d\n",total);
    printf("Percentage  :%.2f\n",percent);
    printf("CGPA  :%.2f\n",cgpa);

    if (Pass(marks) ==0)
    {
        printf("Result : Fail\n");
    }
    else
    {
        
    printf("Result :Pass\n");
    

    if (percent >=75)
    printf("Grade : A\n");

    else if (percent >=60)
    printf("Grade : B\n");

    else if (percent >=50)
    printf("Grade : C\n");

    else
    printf("Grade : D\n");
    
    }

    // Main Function
void main()
{
    char name[40];
    int roll;
    int marks[subjects];
    int total;
    float percent,cgpa;

    studentdetails(name ,&roll,marks);

    total=totalmarks(marks);
    percent=Percentage(total);
    cgpa=CGPA(percent);

    Result(name,roll,marks,total,percent,cgpa);
}


}
