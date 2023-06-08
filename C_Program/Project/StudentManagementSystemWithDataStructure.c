
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>

struct node
{
    int id;
    char name[20];
    float cgpa;
    struct node *next;
}*head, *newNode, *temp, *delete, *last;

        int i, n, choice, pass, id;


void student();
void teacher();
void createList();
void display();
void search_tec();
void search_std();
void edit_info();
void addNew();
void deleteById();
void deleteAll();

int main()
{
    printf("\n\n\t\t\t-----Welcome to student management system-----");
    while(1)
    {
            main_manu:
    printf("\n\n\tWho are you?");
    printf("\n\n\t1.Student");
    printf("\n\n\t2.Teacher");
    printf("\n\n\t0.Exit\n");

    printf("\n\tEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            student();
            break;

        case 2:
            printf("\n\tEnter your password: ");
            scanf("%d",&pass);
            switch(pass)
            {
                case 4043:
                    teacher();
                    break;

                default:
                    printf("\n\n\tIncorrect password....\n\n");
                    goto main_manu;
            }

        case 0:
            exit(0);
            break;

        default:
            printf("\n\n\tWrong choice....\n\n");
    }
    }
    return 0;
}

void student()
{
    if(head==NULL)
    {
        printf("\nRecord is not published...\n");
    }
    else
    {
        printf("\n\n\tSearch by ID");
        search_std();
    }
}

void teacher()
{
    while(1)
    {
    printf("\n\n\t1.Upload student information");
    printf("\n\n\t2.Display information");
    printf("\n\n\t3.Search by ID");
    printf("\n\n\t4.Edit information");
    printf("\n\n\t5.Add New");
    printf("\n\n\t6.Delete by ID");
    printf("\n\n\t7.Delete All Information");
    printf("\n\n\t9.Main Menu");
    printf("\n\n\t0.Exit\n");
    printf("\n\n\tEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            createList();
            break;

        case 2:
            display();
            break;

        case 3:
            search_tec();
            break;

        case 4:
            edit_info();
            break;

        case 5:
            addNew();
            break;

        case 6:
            deleteById();
            break;

        case 7:
            deleteAll();
            break;

        case 9:
            main();
            break;

        case 0:
            exit(0);
            break;

        default:
        printf("\n\n\tWrong choice....\n\n");
    }
    }
}

void createList()
{
    printf("\n\tEnter total student: ");
    scanf("%d",&n);
    head = (struct node*)malloc(sizeof(struct node));
    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
    printf("\n\n\tEnter information----");
    printf("\n\tID: ");
    scanf("%d",&head->id);
    printf("\tName: ");
    scanf("%s",&head->name);
    printf("\tCGPA: ");
    scanf("%f",&head->cgpa);
    head->next = NULL;

    temp = head;
    for(i=2; i<=n; i++)
    {
        newNode = (struct node*)malloc(sizeof(struct node));
        if(newNode == NULL)
        {
            printf("Unallocate the memory.\n");
            break;
        }
        else
        {
            printf("\n\tID: ");
            scanf("%d",&newNode->id);
            printf("\tName: ");
            scanf("%s",&newNode->name);
            printf("\tCGPA: ");
            scanf("%f",&newNode->cgpa);
            newNode->next = NULL;

            temp->next = newNode;
            temp = temp->next;
        }
    }
    }
    printf("\n\n\tInformation updated succesfully.");

    printf("\n\n\t\tPress 'Enter' to go teacher's menu");
    getch();
}

void display()
{
    if(head==NULL)
    {
        printf("\nRecord is empty...\n");
    }
    else
    {
    temp = head;
    while(temp != NULL)
    {
        printf("\n\tID: %d",temp->id);
        printf("\n\tName: %s",temp->name);
        printf("\n\tCGPA: %.2f\n\n",temp->cgpa);
        temp = temp->next;
    }
    printf("\n\n\t\tPress 'Enter' to go teacher's menu");
    getch();
    }
}

void search_tec()
{
    printf("\n\n\tEnter ID: ");
    scanf("%d",&id);
    if(head == NULL)
    {
        printf("\n\tList is empty.");
        teacher();
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            if(temp->id == id)
            {
                printf("\n\n\tInformation found");
                printf("\n\tID: %d",temp->id);
                printf("\n\tName: %s",temp->name);
                printf("\n\tCGPA: %.2f\n\n",temp->cgpa);
                break;
            }
            else
            {
                temp = temp->next;
            }
        }
        printf("\n\n\t\tPress 'Enter' to go teacher's menu");
        getch();
    }
}

void search_std()
{
    printf("\n\n\tEnter ID: ");
    scanf("%d",&id);
    if(head == NULL)
    {
        printf("\n\tList is empty.");
        printf("\n\n\t\tPress 'Enter' to go main menu");
        getch();
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            if(temp->id == id)
            {
                printf("\n\n\tInformation found");
                printf("\n\tID: %d",temp->id);
                printf("\n\tName: %s",temp->name);
                printf("\n\tCGPA: %.2f\n\n",temp->cgpa);
                break;
            }
            else
            {
                temp = temp->next;
            }
        }
        printf("\n\n\t\tPress 'Enter' to go main menu");
        getch();
    }
}

void edit_info()
{
    printf("\n\n\tEnter ID: ");
    scanf("%d",&id);
    if(head == NULL)
    {
        printf("\n\tList is empty.");
        teacher();
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            if(temp->id == id)
            {
                printf("\n\n\tInformation found");
                printf("\n\tID: %d",temp->id);
                printf("\n\tName: %s",temp->name);
                printf("\n\tCGPA: %.2f\n\n",temp->cgpa);

                printf("\n\n\tEnter New Information");
                printf("\n\tEnter new ID: ");
                scanf("%d",&temp->id);
                printf("\tEnter new Name: ");
                scanf("%s",&temp->name);
                printf("\tEnter new CGPA: ");
                scanf("%f",&temp->cgpa);

                printf("\n\n\tInformation updated succesfully...");
                break;
            }
            else
            {
                temp = temp->next;
            }
        }
        printf("\n\n\t\tPress 'Enter' to go teacher's menu");
        getch();
    }
    
}

void addNew()
{
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL)
    {
        printf("Unallocate the memory.\n");
        teacher();
    }
    else
    {
        printf("\n\n\tAdd Information");
        printf("\n\tEnter ID: ");
        scanf("%d",&newNode->id);
        printf("\tEnter Name: ");
        scanf("%s",&newNode->name);
        printf("\tEnter CGPA: ");
        scanf("%f",&newNode->cgpa);

        newNode->next = NULL;
        temp = head;
        while(temp != NULL && temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;

        printf("\n\n\tInformation added succesfully...");
        printf("\n\n\t\tPress 'Enter' to go teacher's menu");
        getch();
    }
    
}


void deleteById()
{
    printf("\n\n\tEnter ID: ");
    scanf("%d",&id);
    if(head == NULL)
    {
        printf("\n\tList is empty.");
        teacher();
    }
    else
    {
        temp = head;
        last = head;
        while(temp != NULL)
        {
            if(temp->id == id)
            {
                printf("\n\n\tInformation found");
                printf("\n\tID: %d",temp->id);
                printf("\n\tName: %s",temp->name);
                printf("\n\tCGPA: %.2f\n\n",temp->cgpa);
                
                printf("\n\n\t\t----DO YOU WANT TO DELETE THIS RECORD?(Y/N)----");
                if(toupper(getch()) == 'Y')
                {
                    delete = temp;
                    last->next = temp->next;

                    printf("\n\n\tID: %d Information delete succesfully...",delete->id);
                    free(delete);
                    printf("\n\n\t\tPress 'Enter' to go teacher's menu");
                    getch();
                }
                else if(toupper(getch()) == 'N')
                {
                    teacher();
                }
            }
            else
            {
                last = temp;
                temp = temp->next;
            }
        }
    }
}

void deleteAll()
{
    if(head == NULL)
    {
        printf("List is empty.\n");
        teacher();
    }
    else
    {
        printf("\n\n\t\t----DO YOU WANT TO DELETE ALL RECORD?(Y/N)----");
        if(toupper(getch()) == 'Y')
        {
            while(head != NULL)
            {
                temp = head;
                head = head->next;
                free(temp);
            }
            printf("\n\n\tAll Information delete succesfully...");
            printf("\n\n\t\tPress 'Enter' to go teacher's menu");
            getch();
        }
        else if(toupper(getch()) == 'N')
        {
            teacher();
        }
    }
}