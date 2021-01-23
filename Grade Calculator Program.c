#include <stdio.h>
// student struct
struct student
{
    char name[80];
    int studentID;
    int midtermGrade;
    int finalGrade;
    int courseGrade;
    char status;
};

// define functions
void accept(struct student[], int);
void statistics(struct student[], int);
void find(struct student[], int, int);

// main function
int main()
{
    struct student data[20];
    int n, studentID;
    char choice;
    printf("*****Grade Calculator Program*****\n\n\n");
	// description
	printf("Decription : A simple grade calculator for a set of students together with statistics and search functions.\n\n");
    while (1){
    	// menu
        printf("*****MENU*****\n");
        printf("Press A to add new record.\n");
        printf("Press F to find a record.\n");
        printf("Press S to show basic statistics.\n");
        printf("Press Q to exit.\n");
        printf("\nEnter choice: ");
        scanf(" %c",&choice);
        if(choice == 'A' || choice == 'a'){ 
        	/*
        	When selected, the user will be asked to enter name,
			student id, midterm grade and final grade. The program will then compute
			course grade and pass fail status for that student and keep in the struct.
			*/
	        printf("\nNumber of records you want to enter? : ");
	    	scanf("%d", &n);
	    	accept(data, n);
	    }
	    else if(choice == 'F' || choice == 'f'){
	    	/*
        	When selected, the user will be asked to enter student id
			and the program will display, name, id, midterm grade, final grade, course
			grade and pass/fail status for that student. If not found, display that the
			record does not exist.
			*/
            printf("\nEnter student ID to search : ");
            scanf("%d", &studentID);
            find(data, n, studentID);
        }
        else if(choice == 'S' || choice == 's'){
        	/*
        	Based on all entries, it will compute the statistics
			and display (number of passed, failed students and average course grade,
			number of students)	
			*/
            statistics(data, n); 
        }
        else if(choice == 'Q' || choice == 'q'){
        	/*
        	When selected, it will exit the program. The records will be deleted
			automatically since they are not saved to a file.
			*/
            break; 
        }
        else{
        	// invalid choice
        	printf("Invalid choice");
        	break;
		}
    }
    return 0;
}

// to add a new record
void accept(struct student list[80], int s)
{
    int i;
    for (i = 0; i < s; i++)
    {
    	// student ID
        printf("\nEnter data for Record #%d", i + 1);
        printf("\nEnter studentID : ");
        scanf("%d", &list[i].studentID);
        fflush(stdin);
        // name
        printf("Enter name : ");
        gets(list[i].name);
		// midterm grade
        printf("Enter midterm grade : ");
        scanf("%d", &list[i].midtermGrade);
        // final grade
        printf("Enter final grade : ");
        scanf("%d", &list[i].finalGrade);
        // course grade
        list[i].courseGrade = 0.4 * list[i].midtermGrade + 0.6 * list[i].finalGrade;
        // Pass/Fail Status
        if(list[i].courseGrade < 60){
        	list[i].status = '-';
		}
        else if(list[i].courseGrade >= 60){
        	list[i].status = '+';
		}
    } 
}
// to show basic statistics
void statistics(struct student list[80], int s)
{
	// number of students
    printf("\nNumber of students: %d\n",s);
    // number of number of passed, failed students
    int i, sum1 = 0, sum2 = 0, sum3 = 0;
	for (i = 0; i < s; i++)
    {
    	if(list[i].status == '+'){
    		sum1 += 1;
		}
		else{
			sum2+=1;
		}
    }
	printf("Number of passed students: %d\n",sum1); 
	printf("Number of failed students: %d\n",sum2);
	// average course grade
	for (i = 0; i < s; i++)
    {
    	sum3 += list[i].courseGrade;
	}
	printf("Average course grade: %d\n",sum3/s); 
}
// to find a record
void find(struct student list[80], int s, int number)
{
    int i;
    for (i = 0; i < s; i++)
    {
        if (list[i].studentID == number)
        {
            printf("\n\nStudent ID: %d\nName: %s\nMidterm Grade: %d\nFinal Grade: %d\nCourse Grade: %d\nPass/Fail Status: %c\n", list[i].studentID, list[i].name, list[i].midtermGrade, list[i].finalGrade, list[i].courseGrade, list[i].status);
            return ;
        } 
    }
    printf("Record not Found\n");
}
