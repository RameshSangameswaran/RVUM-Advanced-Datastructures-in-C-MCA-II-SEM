#include <stdio.h>
#define MAX 5
// Linear Queue
int lq[MAX];
int front1 = -1, rear1 = -1;
// Circular Queue
int cq[MAX];
int front2 = -1, rear2 = -1;
// Deque
int dq[MAX];
int front3 = -1, rear3 = -1;
/* ================= LINEAR QUEUE ================= */
void insertLQ(int item)
{
if(rear1 == MAX - 1)
printf("Linear Queue Overflow\n");
else
{
if(front1 == -1)
front1 = 0;
lq[++rear1] = item;
}
}
void deleteLQ()
{
if(front1 == -1 || front1 > rear1)
printf("Linear Queue Underflow\n");
else
{
printf("Deleted Element = %d\n", lq[front1]);
front1++;
}
}
void displayLQ()
{
int i;
if(front1 == -1 || front1 > rear1)
{
printf("Queue Empty\n");
return;
}
printf("Linear Queue: ");
for(i = front1; i <= rear1; i++)
printf("%d ", lq[i]);
printf("\n");
}
/* ================= CIRCULAR QUEUE ================= */
void insertCQ(int item)
{
if((rear2 + 1) % MAX == front2)
{
printf("Circular Queue Overflow\n");
return;
}
if(front2 == -1)
front2 = rear2 = 0;
else
rear2 = (rear2 + 1) % MAX;
cq[rear2] = item;
}
void deleteCQ()
{
if(front2 == -1)
{
printf("Circular Queue Underflow\n");
return;
}
printf("Deleted Element = %d\n", cq[front2]);
if(front2 == rear2)
front2 = rear2 = -1;
else
front2 = (front2 + 1) % MAX;
}
void displayCQ()
{
int i;
if(front2 == -1)
{
printf("Queue Empty\n");
return;
}
printf("Circular Queue: ");
i = front2;
while(1)
{
printf("%d ", cq[i]);
if(i == rear2)
break;
i = (i + 1) % MAX;
}
printf("\n");
}
/* ================= DEQUE ================= */
void insertFront(int item)
{
if((front3 == 0 && rear3 == MAX - 1) ||
(front3 == rear3 + 1))
{
printf("Deque Overflow\n");
return;
}
if(front3 == -1)
{
front3 = rear3 = 0;
}
else if(front3 == 0)
{
front3 = MAX - 1;
}
else
{
front3--;
}
dq[front3] = item;
}
void insertRear(int item)
{
if((front3 == 0 && rear3 == MAX - 1) ||
(front3 == rear3 + 1))
{
printf("Deque Overflow\n");
return;
}
if(front3 == -1)
{
front3 = rear3 = 0;
}
else if(rear3 == MAX - 1)
{
rear3 = 0;
}
else
{
rear3++;
}
dq[rear3] = item;
}
void deleteFront()
{
if(front3 == -1)
{
printf("Deque Underflow\n");
return;
}
printf("Deleted Element = %d\n", dq[front3]);
if(front3 == rear3)
front3 = rear3 = -1;
else if(front3 == MAX - 1)
front3 = 0;
else
front3++;
}
void deleteRear()
{
if(front3 == -1)
{
printf("Deque Underflow\n");
return;
}
printf("Deleted Element = %d\n", dq[rear3]);
if(front3 == rear3)
front3 = rear3 = -1;
else if(rear3 == 0)
rear3 = MAX - 1;
else
rear3--;
}
void displayDeque()
{
int i;
if(front3 == -1)
{
printf("Deque Empty\n");
return;
   }
   printf("Deque: ");
   i = front3;
   while(1)
   {
       printf("%d ", dq[i]);
       if(i == rear3)
         break;
       i = (i + 1) % MAX;
   }
   printf("\n");
}
/* ================= MAIN ================= */
int main()
{
    int choice, item;
    do
    {
        printf("\n===== QUEUE OPERATIONS =====\n");
        printf("1. Linear Queue Insert\n");
        printf("2. Linear Queue Delete\n");
        printf("3. Display Linear Queue\n");
        printf("4. Circular Queue Insert\n");
        printf("5. Circular Queue Delete\n");
        printf("6. Display Circular Queue\n");
        printf("7. Deque Insert Front\n");
        printf("8. Deque Insert Rear\n");
        printf("9. Deque Delete Front\n");
        printf("10. Deque Delete Rear\n");
        printf("11. Display Deque\n");
        printf("12. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter Item: ");
                scanf("%d", &item);
                insertLQ(item);
                break;
            case 2:
                deleteLQ();
                break;
            case 3:
                displayLQ();
                break;
            case 4:
                printf("Enter Item: ");
                scanf("%d", &item);
                insertCQ(item);
                break;
            case 5:
                deleteCQ();
                break;
            case 6:
                displayCQ();
                break;
            case 7:
                printf("Enter Item: ");
                scanf("%d", &item);
                insertFront(item);
                break;
            case 8:
                printf("Enter Item: ");
                scanf("%d", &item);
                insertRear(item);
                break;
            case 9:
                deleteFront();
                break;
            case 10:
                deleteRear();
                break;
            case 11:
                displayDeque();
                break;
            case 12:
                printf("Program Terminated\n");
                break;
            default:
                printf("Invalid Choice\n");
        }
    } while(choice != 12);
    return 0;
}
//
// Created by rvu on 11/25/26.
//
