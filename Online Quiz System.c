/*
DSA MINI PROJECT

ONLINE QUIZ SYSTEM

GROUP MEMBERS:

1) CB20112 NURUL ISMA NADIYA BINTI ISMAIL (LEADER)
2) CB20116 ATHIRAH NAJIHAH BINTI ZULKIFILI
3) CD20090 LEONG CUI SHAN
4) CB20119 NURUL IMAN BINTI NORDIN
5) CB20129 WAN MUHAMMMAD FAZRUL HAQIMI BIN WAN YUSOFF
6) CB20124 TUAN ROSLINDA BINTI TUAN RANI

=========== Flow of Online Quiz System ===========
LECTURER can:
1) Login/sign up
2) Insert questions and marks (not exceed 10)
3) Enter duration time for the question
4) Enter and search students' marks
5) Enter students' marks based on their attempt and sort from low to high marks

STUDENT can:
1) Login/sign up
2) Insert, modify, delete answers and view total marks
*/

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>

#define MAXQUEUE 5
#define MAXSIZE 10
#define maxsize 10
#define lecturer "suzana"
#define Lpass "123456"
#define student "faizal"
#define Spass "246810"

#define TRUE 1
#define FALSE 0

//nested structure
struct User{
    struct Lecture{
      char L_name[100], L_email[50], L_phoneNo[11];
      char L_username[20], L_password[10];
    }l;

    struct Student{
      char S_name[100], S_email[50], S_phoneNo[11];
      char S_username[20], S_password[10], codeAttempt[10];
    }s;
};

//structure total mark for lecturer and students
struct Assessment_results{
  int marks[10];
  int totalMark;
};

//structure answers for students
struct Answer{
	int answer;
	struct Answer *ptrnext;
};

struct Answer *headptr, *newptr, *curptr;

int insert(int, struct Assessment_results);
void display(int);
void deleted();
void modify();

int queue[MAXQUEUE];
int front=0;
int rear=MAXQUEUE-1;
int count = 0;
int time;
char ch;

void enqueue(int);
void dequeue();
void display_time();

void seq_search(int [],int,int);
int calcMark(int, struct Assessment_results);
void mark_sort(int [],int);

int main(){

  struct User info;
  struct Assessment_results result;

  headptr=NULL;
  int choice;
  int status = 1;
  int i=0;
  int x=0;
  int c=0;
  char question[300];
  result.totalMark=0;
  int k, num_attempt, record[maxsize];

  char role, acc;

  int y, index;
  int z, num_elements, data[MAXSIZE];
  int search_key;

  printf("Do you have an account? (Y = YES / N = NO): ");
  scanf(" %c", &acc);

  printf("Please choose your role (L = Lecture / S = Student): ");
  scanf(" %c", &role);

  if(acc == 'y' || acc == 'Y'){
    if(role == 'l' || role == 'L'){
      do{
        printf("\n========= LOGIN =========\n\n");
        printf("Enter your username: ");
        scanf("%s", &info.l.L_username); //nested structure for all scanf from login to sign up
        printf("Enter your password: ");
        scanf("%s", &info.l.L_password);

        if(strcmp(info.l.L_username, "suzana")==0){
            if(strcmp(info.l.L_password, "123456")==0){
                printf("\nLogin Successful!");
            }

            else{
                printf("\nWrong password!\n");
            }
        }

        else{
            printf("\nPlease enter your correct username and password!\n");
        }
      }while (strcmp(info.l.L_username, lecturer) != 0 || strcmp(info.l.L_password, Lpass) != 0);
    }

    else{
      do{
        printf("\n========= LOGIN =========\n\n");
        printf("Enter your username: ");
        scanf("%s", &info.s.S_username);
        printf("Enter your password: ");
        scanf("%s", &info.s.S_password);

        if(strcmp(info.s.S_username, "faizal")==0){
            if(strcmp(info.s.S_password, "246810")==0){
                printf("\nLogin Successful!");
            }

            else{
                printf("\nWrong password\n");
            }
        }

        else{
            printf("\nPlease enter your correct username and password!\n");
        }
      }while (strcmp(info.s.S_username, student) != 0 || strcmp(info.s.S_password, Spass) != 0);
    }
  }

  else{
    if(role == 'l' || role == 'L'){
        printf("\n========= SIGN UP =========\n\n");
        printf("Enter your name: ");
        scanf("%s", &info.l.L_name);
        printf("Enter your email: ");
        scanf("%s", &info.l.L_email);
        printf("Enter your phone number: ");
        scanf("%s", &info.l.L_phoneNo);
        printf("Enter your username: ");
        scanf("%s", &info.l.L_username);
        printf("Enter your password: ");
        scanf("%s", &info.l.L_password);

        printf("\n\nSUCCESSFULLY SIGN UP");
        printf("\nLecturer's name: %s", &info.l.L_name);
        printf("\nLecturer's email: %s", &info.l.L_email);
        printf("\nLecturer's phone number: %s", &info.l.L_phoneNo);
        printf("\nLecturer's username: %s", &info.l.L_username);
        printf("\nLecturer's password: %s", &info.l.L_password);
    }

    else{
        printf("\n========= SIGN UP =========\n\n");
        printf("Enter your name: ");
        scanf("%s", &info.s.S_name);
        printf("Enter your email: ");
        scanf("%s", &info.s.S_email);
        printf("Enter your phone number: ");
        scanf("%s", &info.s.S_phoneNo);
        printf("Enter your username: ");
        scanf("%s", &info.s.S_username);
        printf("Enter your password: ");
        scanf("%s", &info.s.S_password);
        printf("Enter your code attempt: ");
        scanf("%s", &info.s.codeAttempt);

        printf("\n\nSUCCESSFULLY SIGN UP");
        printf("\nStudent's name: %s", &info.s.S_name);
        printf("\nStudent's email: %s", &info.s.S_email);
        printf("\nStudent's phone number: %s", &info.s.S_phoneNo);
        printf("\nStudent's username: %s", &info.s.S_username);
        printf("\nStudent's password: %s", &info.s.S_password);
        printf("\nStudent's code attempt: %s", &info.s.codeAttempt);
    }
  }
        //MATH QUIZ
        if(role == 'L' || role == 'l'){
            printf("\n\nThe total number of question: ");
            scanf("%d", &i);

            for(x=0; x<i; x++){
                printf("Question %d: ", x+1);
                scanf(" %[^\n]s", &question[i]);
                printf("Mark: ");
                scanf("%d", &result.marks[i]);
            }

            //queue
            do{
                printf("\n\n[-------Duration Time Menu-------]\n");
                printf("\nA - Key in quiz duration time ");
                printf("\nB - Delete quiz duration time");
                printf("\nD - Display quiz duration time list");
                printf("\nX - Exit Menu");
                printf("\n\nPlease enter your choice : ");

                scanf(" %c",&ch);
                ch=toupper(ch);

                switch (ch){
                case 'A':printf("\nPlease enter the duration time for quiz (in minutes): ");
                          scanf("%d",&time); //read in a value of duration time
                          enqueue(time); //call enqueue function
                          break;

                case 'B':printf("\nDelete the queue");
                          dequeue(); //call dequeue function
                          break;

                case 'D':display_time(); //call display time function
                          break;

                case 'X':printf("\nExit queue menu");
                          break;

                default: printf("\nInvalid entry. Please select 'A','B','D','X'\n");
                }
            }while (ch!='X');

            //linear sequential search
            printf("\n\nHow many student's mark you want to enter: ");
            scanf("%d",&num_elements);

            for(y=0; y<num_elements; y++){
                printf("\nEnter mark student %d: ", y+1);
                scanf("%d",&data[y]);
            }
            //read in a value for number of elements
            printf("\nEnter student's mark for searching: ");
            scanf("%d",&search_key);

            //call the sequential search function
            seq_search(data, num_elements, search_key);

            //display the searched elements
            printf("\n========== SEARCHED RESULT ==========\n\n");
            for(z=0; z<num_elements; z++){
                if (data[z] == search_key){
                  printf("%d marks is found at student number %d!\n", search_key, z+1);
                  break;
                }
            }

            if(z==num_elements)
                printf("%d marks isn't present in the list!\n", search_key);

            //bubble sort
            printf("\nEnter number of attempt: ");
            scanf("%d",&num_attempt);

            for(k=0; k<num_attempt; k++)
            {
                printf("\nEnter mark for each attempt: ");
                scanf("%d",&record[k]);
            }

            mark_sort(record, num_attempt);

            printf("\nBelow is the marks sorted in ascending order: ");
            for(k=0; k<num_attempt; k++)
                printf(" %d",record[k]);
        }

        if(role == 'S' || role == 's'){
        do{
            printf("\n\n================= QUESTIONS ==================");
            printf("\n1. What is the answer for 6 additional with 5?");
            printf("\n2. What is the answer for 15 substract with 7?");
            printf("\n3. What is the answer for 7 multiple with 4?");
            printf("\n4. What is the answer for 45 divided by 5?");
            printf("\n5. What is the answer for (4 + 4) X (5-3)?");
            printf("\n================= QUESTIONS ==================");

            //linked list
            printf("\n\n1 - Input your answers");
            printf("\n2 - Delete your answers");
            printf("\n3 - Modify your answers");
            printf("\n4 - Display answers");
            printf("\n5 - Exit");
            printf("\n\nEnter choice: ");
            scanf("%d", &choice);

            switch(choice){
            case 1:

                printf("\n====== Question %d ======\n",c+1);
                result.totalMark = insert(c, result);
                c++;
                break;

            case 2:
                c--;
                deleted();
                break;

            case 3: modify();
                break;

            case 4:
                display(c);
                break;

            case 5:
                printf("\n\nTHANK YOU! GOOD LUCK!!\n");
                status = 0;
                break;

            default:
                printf("\n\nINVALID INPUT\n\n");
                break;
            }

        }while(status == 1);

        printf("\nTotal Mark = %d", result.totalMark);
    }

    return 0;
}

//linked list
int insert(int c, struct Assessment_results result){
    newptr=(struct Answer*)malloc(sizeof(struct Answer));
    printf("Enter your answer: ");
    scanf("%d", &newptr->answer);
    printf("========================\n");

    result.totalMark = calcMark(c, result);

    if (headptr==NULL){
        headptr=newptr;
        newptr->ptrnext=NULL;
    }

    else{
        newptr->ptrnext=headptr;
        headptr=newptr;
    }

    return result.totalMark;
}

//linked list
int calcMark(int c, struct Assessment_results result){

    if (c == 0){
        if (newptr->answer == 11){
            result.marks[c] = 2;
            result.totalMark = result.totalMark + result.marks[c];
        }
    }

    else if (c == 1){
        if (newptr->answer == 8){
            result.marks[c] = 2;
            result.totalMark = result.totalMark + result.marks[c];
        }
    }

    else if (c == 2){
        if (newptr->answer == 28){
            result.marks[c] = 2;
            result.totalMark = result.totalMark + result.marks[c];
        }
    }

    else if (c == 3){
        if (newptr->answer == 9){
            result.marks[c] = 2;
            result.totalMark = result.totalMark + result.marks[c];
        }
    }

    else if (c == 4){
        if (newptr->answer == 16){
            result.marks[c] = 2;
            result.totalMark = result.totalMark + result.marks[c];
        }
    }
    return result.totalMark;
}

//linked list
void deleted(){
    if(headptr != NULL){
        curptr = headptr;
        headptr = curptr->ptrnext;
        free(curptr);
        printf("\n========================\nThe last answer deleted.\n========================\n");
    }

    else{
        printf("There is nothing to delete!!\n\n");
    }
}

//linked list
void modify(){
    int modify, newAnswer;

    printf("\nWhich answer you want to modify? Answer: ");
    scanf("%d", &modify);

    curptr = headptr;

    while(curptr->answer != newAnswer){
         if(curptr->answer == modify){
            printf("Enter your new answer: ");
            scanf("%d", &newAnswer);
            curptr->answer = newAnswer;
            printf("\nYour answer successful changed.\n");
            printf("\nThe new answer is %d.", curptr->answer);
         }

         else{
                curptr = curptr->ptrnext;
         }
    }
}

//linked list
void display(int c){
    if (headptr==NULL){
		printf("\nEmpty list");
		return;
	}else{

        curptr=headptr;

	printf("\n====== Answer Review ======\n");
	do{
        printf("\nQuestion %d: ", c);
		printf("%d",curptr->answer);
		printf("\n");

		curptr=curptr->ptrnext;
		c--;
	} while(curptr !=NULL);
	printf("===========================\n");
	}
}

//queue
void enqueue(int time){
	if(count==MAXQUEUE){
	printf("\n!!! Queue OVERFLOW - can't insert into queue !!!");
	}

	else{
		rear=(rear+1)%MAXQUEUE;
		count++;
		queue[rear]=time;
	}
    display_time();
}

//queue
void dequeue(){
	if (count==0){
	printf("\n!!! Queue UNDERFLOW - can't delete queue !!!");
	}

	else{
		front=(front+1)%MAXQUEUE;
		count--;
	}
    display_time();
}

//queue
void display_time(){
	int i=front;
	int j=count;

	printf("\n\nList of duration time for quiz : ");

	if(count==0)
	printf("\nThe duration time list is empty");

	else{
		while (j!=0){
			printf("%d \t",queue[i]);
			i=(i+1)%MAXQUEUE;
			j--;
		}
	}
}

//linear sequential search
void seq_search(int data[],int num_elements, int search_key){
	int i;

	for(i=0;i<num_elements;i++){
		if(data[i]==search_key){
			printf("\nStudent's mark found!\n");
			return;
		}
	}//lecturer search student based on marks

	printf("\nSorry, no match found\n");
	return;
}

//bubble sort
void mark_sort(int record[],int num_attempt){
	int  temp, k;

	while (num_attempt>1){
		num_attempt--;

		for(k=0;k<num_attempt;k++){
			if (record[k]>record[k+1]){
				temp=record[k];
				record[k]=record[k+1];
				record[k+1]=temp;
			}
		}
	}
}

