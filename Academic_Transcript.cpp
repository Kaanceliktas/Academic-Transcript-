#include<conio.h>
#include<stdio.h>
#include<windows.h>
//#include<process.h>


struct student //The struct statement defines a new data type, with more than one member.
{
 int rollno;
 char name[50];
 int p_marks,c_marks,m_marks,e_marks,cs_marks;
 float per;
 char grade;
 int std;
}st;
 FILE *fptr;
void write_student() // To create a log file and getting the informations from user.
   {
    fptr=fopen("student.dat","ab"); //"ab" Open a binary file in append mode for writing at the end of the file.
    printf("\nPlease Enter The New Details of student \n");
    printf("\nEnter The school number of student ");
    scanf("%d",&st.rollno);
    fflush(stdin);
    printf("\n\nEnter The Name of student ");
    gets(st.name);
    printf("\nEnter The marks in Electric and Electronic out of 100 : ");
    scanf("%d",&st.p_marks);
    printf("\nEnter The marks in Software Engineering out of 100 : ");
    scanf("%d",&st.c_marks);
    printf("\nEnter The marks in Discreate Computional Structures out of 100 : ");
    scanf("%d",&st.m_marks);
    printf("\nEnter The marks in History out of 100 : ");
    scanf("%d",&st.e_marks);
    printf("\nEnter The marks in Differantial Equations out of 100 : ");
    scanf("%d",&st.cs_marks);
    st.per=(st.p_marks+st.c_marks+st.m_marks+st.e_marks+st.cs_marks)/5.0;
    if(st.per>=80)
       st.grade='A';
    else if(st.per>=60 &&st.per<80)
      st.grade='B';
    else if(st.per>=35 &&st.per<60)
      st.grade='C';
    else
     st.grade='F';
    fwrite(&st,sizeof(st),1,fptr); //( points to block of memory, specifies the number of bytes of each item, number of items to be written, pointer to the file where data items will be written)
    fclose(fptr);
    printf("\n\nStudent Record Has Been Created ");
    getch();
}



void display_all() // To display all records of the class.
{
	
    system("cls"); // To clean the screen
    printf("\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n");
    fptr=fopen("student.dat","rb"); // "rb" Open a binary file for reading
    while((fread(&st,sizeof(st),1,fptr))>0)
    {
      printf("\nSchool Number of Student : %d",st.rollno);
      printf("\nName of student : %s",st.name);
      printf("\nMarks in Electric and Electronic : %d",st.p_marks);
      printf("\nMarks in Software Engineering : %d",st.c_marks);
      printf("\nMarks in Discreate Computional Structures : %d",st.m_marks);
      printf("\nMarks in History : %d",st.e_marks);
      printf("\nMarks in Differantial Equations : %d",st.cs_marks);
      printf("\nPercentage of student is  : %.2f",st.per);
      printf("\nGrade of student is : %c",st.grade);
      printf("\n\n====================================\n");
      getch();
    }
    fclose(fptr);
    getch();
    
   
}



void display_sp(int n) // To display specific records of the student.
{
    int flag=0;
    fptr=fopen("student.dat","rb");
    while((fread(&st,sizeof(st),1,fptr))>0)
    {
     if(st.rollno==n) // Function to return if n is 1
        {
        system("cls");
            printf("\nSchool number of student : %d",st.rollno);
            printf("\nName of student : %s",st.name);
            printf("\nMarks in Electric and Electronic : %d",st.p_marks);
            printf("\nMarks in Software Engineering : %d",st.c_marks);
            printf("\nMarks in Discreate Computional Structures : %d",st.m_marks);
            printf("\nMarks in History : %d",st.e_marks);
            printf("\nMarks in Differantial Equations : %d",st.cs_marks);
            printf("\nPercentage of student is  : %.2f",st.per);
            printf("\nGrade of student is : %c",st.grade);
         flag=1; // To read and call specific things.
        }
    }
    fclose(fptr);
if(flag==0)
 printf("\n\nrecord not exist");
    getch();
}



void modify_student() // To modify added student.
{
    int no,found=0;
   system("cls");
    printf("\n\n\tTo Modify ");
    printf("\n\n\tPlease Enter The school number of student");
    scanf("%d",&no);
    fptr=fopen("student.dat","rb+"); // "rb+" Open a binary file for both reading and writing.
    while((fread(&st,sizeof(st),1,fptr))>0 && found==0)
    {
    if(st.rollno==no)
           {
            printf("\nSchool number of student : %d",st.rollno);
            printf("\nName of student : %s",st.name);
            printf("\nMarks in Electric and Electronic : %d",st.p_marks);
            printf("\nMarks in Software Engineering : %d",st.c_marks);
            printf("\nMarks in Discreate Computional Structures : %d",st.m_marks);
            printf("\nMarks in History : %d",st.e_marks);
            printf("\nMarks in Differantial Equations : %d",st.cs_marks);
            printf("\nPercentage of student is  : %.2f",st.per);
            printf("\nGrade of student is : %c",st.grade);
            printf("\nPlease Enter The New Details of student \n");
            printf("\nEnter The id number of student ");
            scanf("%d",&st.rollno);
            fflush(stdin); // To clear the output and move the file.
            printf("\n\nEnter The Name of student ");
            gets(st.name);
            printf("\nEnter The marks in Electric and Electronic out of 100 : ");
            scanf("%d",&st.p_marks);
            printf("\nEnter The marks in Software Engineering out of 100 : ");
            scanf("%d",&st.c_marks);
            printf("\nEnter The marks in Discreate Computional Structures out of 100 : ");
            scanf("%d",&st.m_marks);
            printf("\nEnter The marks in History out of 100 : ");
            scanf("%d",&st.e_marks);
            printf("\nEnter The marks in Differantial Equations out of 100 : ");
            scanf("%d",&st.cs_marks);
            st.per=(st.p_marks+st.c_marks+st.m_marks+st.e_marks+st.cs_marks)/5.0;
            if(st.per>=60)
               st.grade='A';
            else if(st.per>=50 && st.per<60)
               st.grade='B';
            else if(st.per>=33 && st.per<50)
               st.grade='C';
            else
               st.grade='F';
            fseek(fptr,-(long)sizeof(st),1); // To move information in file which associated with a given file to a specific position.
            fwrite(&st,sizeof(st),1,fptr);
            printf("\n\n\t Record Updated");
            found=1;
           }
         }
    fclose(fptr);
    if(found==0)
    printf("\n\n Record Not Found ");
    getch();
}





void delete_student() // To delete added student from file.
   {
    int no;
    FILE *fptr2; // Creating a new file to move the informations.
    system("cls");
    printf("\n\n\n\tDelete Record");
    printf("\n\nPlease Enter The school number of student You Want To Delete");
    scanf("%d",&no);
    fptr=fopen("student.dat","rb"); // Opened first file.

    fptr2=fopen("Temp.dat","wb"); // Opened second file.
    rewind(fptr); // To back first file.
    while((fread(&st,sizeof(st),1,fptr))>0)
    {
       if(st.rollno!=no)
       {
      fwrite(&st,sizeof(st),1,fptr2); // Write the informations to second file.
       }
    }
    fclose(fptr2);
    fclose(fptr);
    remove("student.dat"); // Delete first file.
    rename("Temp.dat","student.dat"); // Rename second file as first file.
    printf("\n\n\tRecord Deleted ..");
    getch();
}



    void class_result() // To display transkript of class with colourfull.
    {
     system("cls");
     fptr=fopen("student.dat","rb");
     if(fptr==NULL) // if there is no file, it will show error message.
     {
       printf("ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Entry Menu to create File");
       printf("\n\n\n Program is closing ....");
       getch();
       exit(0);
     }

     printf("\n\n\t\tALL STUDENTS RESULT \n\n");
      printf("\033[1;31m"); // For changing the colour of STUDENTS RESULT.
      printf("====================================================================\n");
      printf("S.No.       Name       P   C   M   E   CS  AVG   Grade\n");
      printf("====================================================================\n");
      printf("\033[0m"); // For changing the colour of STUDENTS RESULT.
      while((fread(&st,sizeof(st),1,fptr))>0)
     {
       printf("\033[0;32m"); // For changing the colour of STUDENTS RESULT.
       printf("%-10d %-10s %-3d %-3d %-3d %-3d %-3d %-3.2f  %-1c\n",st.rollno,st.name,st.p_marks,st.c_marks,st.m_marks,st.e_marks,st.cs_marks,st.per,st.grade);
       printf("\033[0m"); // For changing the colour of STUDENTS RESULT.
     }
     fclose(fptr);
     getch();
}



   void result() // The display result menu section.
   {
    int ans,rno;
    char ch;
    system("cls");
    printf("\n\n\nRESULT MENU");
    printf("\n\n\n1. Class Result\n\n2. Student Report Card\n\n3.Back to Main Menu\n");
    printf("\n\n\nEnter Choice (1/2)? \n");
    scanf("%d",&ans);
    switch(ans)
    {
     case 1 : class_result();break;
     case 2 : {
        do{
        char ans;
        system("cls");
        printf("\n\nEnter School Number Of Student : ");
        scanf("%d",&rno);
        display_sp(rno);
        printf("\n\nDo you want to See More Result (y/n)?\n");
        scanf("%c",&ans);
        }while(ans=='y'||ans=='Y');
        break;
           }
     case 3: break;
     default:  printf("\a");
    }
 }


void intro() // To display intro part.
{
 
    
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                  WELCOME                  =");
    printf("\n\t\t\t        =                    TO                     =");
    printf("\n\t\t\t        =               Student Record              =");
    printf("\n\t\t\t        =                 MANAGEMENT                =");
    printf("\n\t\t\t        =                   SYSTEM                  =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t\t\tBeykoz University, Kaan Celiktas");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t\t\t\t\t2020");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getch();

}

void entry_menu() // To display entry/editing menu section.
{
    char ch2;
   system("cls");
  printf("\n\n\n\tENTRY MENU");
  printf("\n\n\t1.CREATE STUDENT RECORD");
  printf("\n\n\t2.DISPLAY ALL STUDENTS RECORDS");
  printf("\n\n\t3.SEARCH STUDENT RECORD ");
  printf("\n\n\t4.MODIFY STUDENT RECORD");
  printf("\n\n\t5.DELETE STUDENT RECORD");
  printf("\n\n\t6.BACK TO MAIN MENU");
  printf("\n\n\tPlease Enter Your Choice (1-6) ");
  ch2=getche();
  switch(ch2)
  {
    case '1': system("cls");
          write_student();
          break;
    case '2': display_all();break;
    case '3':  {
           int num;
           system("cls");
           printf("\n\n\tPlease Enter The school number ");
           scanf("%d",&num);
           display_sp(num);
           }
           break;
      case '4': modify_student();break;
      case '5': delete_student();break;
      case '6': break;
      default:printf("\a");entry_menu();
   }
}
int main() // To display first menu section.
{
  char ch;
  intro();
  do
    {
      system("cls");
      printf("\n\n\n\tMAIN MENU");
      printf("\n\n\t01. RESULT MENU");
      printf("\n\n\t02. ENTRY/EDIT MENU");
      printf("\n\n\t03. EXIT");
      printf("\n\n\tPlease Select Your Option (1-3) ");
      ch=getche();
      switch(ch)
      {
         case '1': system("cls");
               result();
               break;
          case '2': entry_menu();
                break;
          case '3':exit(0);
          default :printf("\a");
    }
    }while(ch!='3');
     return 0;
}
