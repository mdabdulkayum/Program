#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
int main()
{
    system("cls");


    int gc[2], cc[2], lc[2], tc, waiver, total[4];


    printf("\n\n\t\tWelcome to DIU Semister Fee Calculator");

    manual:

    printf("\n\nHow many 'General Course '(GC) Cradit do you want to take? Enter here: ");
    scanf("%d",&gc[0]); 
    printf("How many 'Core Course'(CC) Cradit do you want to take? Enter here: ");
    scanf("%d",&cc[0]);
    printf("How many 'Laboratory Course'(LC) Cradit do you want to take? Enter here: ");
    scanf("%d",&lc[0]);
    printf("How much waiver will you get? Enter here: ");
    scanf("%d",&waiver);

    gc[1]=gc[0]*3200;
    cc[1]=cc[0]*4900;
    lc[1]=lc[0]*5000;
    tc=gc[0]+cc[0]+lc[0];
    total[0]=gc[1]+cc[1]+lc[1];
    total[1]=total[0]+20250;
    waiver=total[0]*waiver/100;
    total[2]=total[0]-waiver;
    total[3]=total[1]-waiver;


    printf("\n\nFor 'Genarel Course'(GC): %d Tk\n",gc[1]);
    printf("For 'Core Course'(CC): %d Tk\n",cc[1]);
    printf("For 'Laboratory Course'(LC): %d Tk\n\n",lc[1]);

    printf("You are taken %d Cadit, The cost is: %d Tk\n\n",tc,total[0]);
    printf("With 13500Tk Registation Fee The Amount Is: %d Tk\n\n",total[1]);
    printf("You are got %d Tk waiver\n\n", waiver);
    printf("The total cost is: %d\n\n", total[3]);

    printf("Are you want to repeat these calculation? Y/N");
    if(toupper(getch())=='Y')
    {
        goto manual;
    }
    else
    {
        exit(1);
    }

    getch();
    return 0;
}
