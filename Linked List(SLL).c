#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "lab4.h"
#define FLASE 0
#define TRUE 1
/*Author: Zhengqi Dong*/
/*Date: Feb 21 2019*/

/*Insert an node */
void insertNode(struct Node **headPtrPtr, Node *newNode)
{
    struct Node *currentPtr;
    struct Node *previousPtr;

    /*Initializing the pointer*/
    currentPtr = *headPtrPtr;
    if(*headPtrPtr == NULL)
    {
        /*The case where the list is empty*/
        *headPtrPtr = newNode;
        newNode->next = NULL;
    }
    else if((*headPtrPtr)->Student.student_ID > newNode->Student.student_ID)
    {
        newNode->next = *headPtrPtr;
        *headPtrPtr = newNode;
    }
    else
    {
        while( (currentPtr != NULL) &&  (currentPtr->Student.student_ID < newNode->Student.student_ID))
        {
            previousPtr = currentPtr;
            currentPtr = currentPtr -> next;
        } /*Maintain the iteration of currentPtr or trailing pointer*/
        if(currentPtr == NULL) /*The case where we reached the end of file*/
        {
            previousPtr->next = newNode;
            newNode->next = NULL;
        }
        else
        {
            /*Where we insert the node*/
            previousPtr->next = newNode;
            newNode->next = currentPtr;
        }
    }
    return;
}


/*if we find a matched id we delete it from list and return TRUE, if doesn't exist we return FALSE, return something for debugging*/
void deleteNode(struct Node **headNode, int id)
{
    struct Node *currentPtr;

    currentPtr = *headNode;
    /*First, if the list is empty*/
    if(*headNode == NULL)
    {
        return;
    }
    else if(*headNode->Student.student_ID == id)
    {
        /*First node is the node we need to delete*/
        *headNode = *currentPtr->next;
        free(currentPtr);
    }
    else
    {
        struct Node *previousPtr;
        /*Maintaining the iteration of currentPtr*/
        while( (currentPtr != NULL) &&  (currentPtr->Student.student_ID != id))
        {
            previousPtr = currentPtr;
            currentPtr = currentPtr ->next;
        }

        if(currentPtr==NULL)
        {
            /*Where the List is empty or id doesn't exist*/
            printf("Error, the ID doesn't in the list!\n");
            return;
        }
        else if(currentPtr->Student.student_ID == id)
        {
            /*Where the case the id had been found*/
            previousPtr->next = currentPtr->next;
            free(currentPtr);
        }
    }
    return;
}

/*Filling all information that read from FILE pointer for one node*/
Node *getAndFillNode(FILE *inFile)
{

    struct Node *newNodePtr;
    /*Allocating a new memory space for newNodePtr*/
    newNodePtr = malloc(sizeof(Node));

    if(newNodePtr == NULL)
    {
        printf("Fail to allocate the memory space.\n");
        return(NULL);
    }

    /*Storing the data to newNode*/
    /*return NULL pointer, if we reached the end of file*/
    if(fscanf(inFile, "%[^\n]",newNodePtr->Student.student_name) == EOF)
    {
        free(newNodePtr);
        return(NULL);
    }
    else
    {
        getc(inFile); /*?Where is safe to put this getChar()? --> Here is find, if we read to the end of file, the above statement will return NULL Pointer*/
    }
    printf("%s\n", newNodePtr->Student.student_name);

    /*Store the data to newNodePtr*/
    fscanf(inFile, "%d", &newNodePtr->Student.student_ID);
    getc(inFile);

    /*Since each categories have different name, so we cannot use nested loop to iterate four categories, so we have store the score separately in four loop.*/
    /*??Anyway we could use loop to reduce the code??*/
    fscanf(inFile, "%f", &newNodePtr->Student.Cat1.score1);
    getc(inFile);
    fscanf(inFile, "%f", &newNodePtr->Student.Cat1.score2);
    getc(inFile);
    fscanf(inFile, "%f", &newNodePtr->Student.Cat1.score3);
    getc(inFile);

    fscanf(inFile, "%f", &newNodePtr->Student.Cat2.score1);
    getc(inFile);
    fscanf(inFile, "%f", &newNodePtr->Student.Cat2.score2);
    getc(inFile);
    fscanf(inFile, "%f", &newNodePtr->Student.Cat2.score3);
    getc(inFile);

    fscanf(inFile, "%f", &newNodePtr->Student.Cat3.score1);
    getc(inFile);
    fscanf(inFile, "%f", &newNodePtr->Student.Cat3.score2);
    getc(inFile);
    fscanf(inFile, "%f", &newNodePtr->Student.Cat3.score3);
    getc(inFile);

    fscanf(inFile, "%f", &newNodePtr->Student.Cat4.score1);
    getc(inFile);
    fscanf(inFile, "%f", &newNodePtr->Student.Cat4.score2);
    getc(inFile);
    fscanf(inFile, "%f", &newNodePtr->Student.Cat4.score3);
    getc(inFile);
    printf("THe first and last score's are: %f and %f\n", newNodePtr->Student.Cat1.score1, newNodePtr->Student.Cat4.score3);

    /*each score has 3 floating point values separated by spaces*/
    /*Store the cumCat1*/
    newNodePtr->Student.Cat1.Cumulative = computeCumulative(&(newNodePtr->Student.Cat1));
    /*Store the cumCat2*/
    newNodePtr->Student.Cat2.Cumulative = computeCumulative(&(newNodePtr->Student.Cat2));
    /*Store the cumCat3*/
    newNodePtr->Student.Cat3.Cumulative = computeCumulative(&(newNodePtr->Student.Cat3));
    /*Store the cumCat4*/
    newNodePtr->Student.Cat4.Cumulative = computeCumulative(&(newNodePtr->Student.Cat4));

    /*Store the current grade*/
    newNodePtr->Student.Current_Grade = computeCurrentGrade(&(newNodePtr->Student));
    /*Set all Final Grade to -1*/
    newNodePtr->Student.Final_Grade = -1;
    printf("The last cumGrade and current Grade and final Grader are: %.2f, %.2f, %.2f\n",newNodePtr->Student.Cat4.Cumulative, newNodePtr->Student.Current_Grade, newNodePtr->Student.Final_Grade);
    return newNodePtr;
}

/*Printing all the infromation in the whole list*/
void printList(struct Node **headNode)
{
    struct Node *tmpNode;
    tmpNode = *headNode;

    while(tmpNde != NULL)
    {
        printLine(tmpNode->Student);
        tmpNode = tmpNode->next;
    }
    return;
}

void printHeader(char *Category_Names)
{
	printf("\nStudent Name\t   Student ID#\tQuizzes\t\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t\tCurrent\tFinal\n",
	(char*)Category_Names+15,(char *)Category_Names+30,(char *)Category_Names+45);
	printf("\t\t\t\t  1       2       3       Cum\t   1       2       3     Cum\t   1       2       3       Cum     1       2       3      Cum\tGrade\tGrade\n");

}


/* lab4main.c will hold main() and no other functions*/
int main( int argc, char *argv[] )
{
    /*Get the name of file*/
    char *inputName; /*this should be a char pointer to the first argument*/
    char *outputName;
    /*File pointer*/
    FILE *input_file;
    FILE *output_file;
    /*Names of each categories, we use a static array of string, so the content can't be changed*/
    char catName[4][15];
    /*Linked list: the first node, number of students*/
    void (*funcArr[6])(struct Node*, char *catName);  /*function pointer*/
    Node *headNode = NULL; /*To show a list is empty*/
    Node *newNode = NULL;
    int option; /*The functions for user to choose*/
    int countStd; /*Count the number of student store in the list*/
    int i;

    inputName = argv[1];
    outputName = argv[2];


    /*For testing the filename read in correctly*/
    printf( "argv[1]:  %s\n", argv[1] );
    printf( "argv[2]:  %s\n", argv[2] );


    /*Open the file*/
    /* FILE *fopen(const char *pathname, const char *mode);
     void perror(const char *s); --> print a system error message
    */
    input_file = fopen(inputName,"r");
    if(input_file == NULL)
    {
        perror(inputName);
        exit(EXIT_FAILURE);
    }

    /*Write to a file*/
    output_file = fopen(outputName, "w");
    if(output_file == NULL)
    {
        perror(outputName);
        exit(EXIT_FAILURE);
    }

    /*Read the file, process the data, and store the data in order to calculate the grades for a class.*/
    /*Storing the names of each categories, Quiz, Midterm, homework, final*/
    /*fscanf take 3 argument, input_file address, format specifier, variables names*/
    fscanf(input_file, "%s\t%s\t%s\t%s\n", catName[0], catName[1],catName[2],catName[3]);
    printf("%s\t%s\t%s\t%s\n", catName[0], catName[1],catName[2],catName[3]);
    /*for(i = 0; i<4; i++)
    {
        if(fscanf(input_file,"%s", &(catName[i][0])) == 1){
        	getc(input_file);
        }
    }
    */
    /*Storing student's information into Linked List: Use a temporary pointer of pointer to a Node, so that we could change the address of the newNode pointer*/

    /*Use a newNode to get the newNode and append to the list, we stop the loop until a NULL pointer is returned*/
    printf("Reading student information from file \"class_records\"\n");/*For indicating the starting point of constructing Linked List*/
    newNode = getAndFillNode(input_file);
    /* insertNode(&headNode, newNode);*/
    countStd = 0;
    while((newNode)!=NULL)
    {
        int x;
        countStd += 1;
        x = insertNode(&headNode, newNode);
        newNode = getAndFillNode(input_file);
        if(x = 0)
        {
            printf("Fail to insert studnet %s!\n", newNode->Student.student_name);
        }
    }
    printf("A total of %d student records were read from the file class_records\n", countStd);
    printf("Finish data constructing\n");
    printf("\n");
    /*Finish data constructing*/
    /*Processing data */

    /*Initialization For function pointers*/
    funcArr[0] = &opt1PrintSingleStudentByID;
    funcArr[1] = &opt2PrintSingleStudentByName;
    funcArr[2] = &opt3PrintAllStudents;
    funcArr[3] = &opt4RecalculateSingleStudentByID;
    funcArr[4] = &opt5ReculculateAllStudents;
    funcArr[5] = &opt6InsertNewScore;
    funcArr[6] = &opt7CalculateFinalGrade;
    option = getOption();

    while(option != 10)
    {
        switch (option)
        {
        case 1:
            funcArr[0](headNode,&catName[0][0]);
            break;
        case 2:
            funcArr[1](headNode,&catName[0][0]);
            break;
        case 3:
            funcArr[2](headNode,&catName[0][0]);
            break;
        case 4:
            funcArr[3](headNode,&catName[0][0]);
            break;
        case 5:
            funcArr[4](headNode,&catName[0][0]);
            break;
        case 6:
            funcArr[5](headNode,&catName[0][0]);
            break;
        case 7:
            funcArr[6](headNode,&catName[0][0]);
            break;
        case 8:
            opt8AddNewStudentFromStdin(headNode, &catName[0][0]);
            break;
        case 9:
            opt9DeleteSingleStudentByID(&headNode);
            break;
        case 10:
            writeClassToDisk(headNode, &catName[0][0], output_file);
            break;
        default:
            break;
        }
        printf("\n\n");
        option = getOption();
    }

    /*The option 10, where all the current record in the linked list out to disk using output file name from the command line, and would also free all dynamically allocated memory*/
    /*Close the file*/
    if(fclose(input_file) != 0)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    if(fclose(output_file)!= 0)
    {
        perror("fclose"); /*fclose - close a stream */
        exit(EXIT_FAILURE); /* perror - write error messages to standard error */
    }
    /*free all the Node*/
    freeAllNode(headNode);
    exit(EXIT_SUCCESS);
}



