/*Author: Drago*/
/*Date: Feb 21 2019*/

struct Cat_Grade
{
    float score1;
    float score2;
    float score3;
    float Cumulative;
};

struct Data
{
    char student_name[40];
    int student_ID;
    struct Cat_Grade Cat1;
    struct Cat_Grade Cat2;
    struct Cat_Grade Cat3;
    struct  Cat_Grade Cat4;
    float Current_Grade;
    float Final_Grade;
};

typedef struct Node
{
    struct Data Student;
    struct Node *next;
} Node;

int main(int argc, char *argv[]);
void insertNode(struct Node **headPrtPtr, Node *newNode);
void deleteNode(struct Node **headPtrPtr, int id);
