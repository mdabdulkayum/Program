
#include<stdio.h>
#include<conio.h>
#include<string.h>

struct suggestion
{
        char book[2000];
        char name[20];
}s;

int main()
{
system("cls");

   char choice;


    struct suggestion cp={"\t1. Beginning C by Ivor Horton\n\t2. C: How to program by Deitel, Deitel\n\t3. The C programming language by Dennis Ritch\n\t4. Computer Programming (Bangla) by Tamim sahriar Subin\n"},javaScript={"\t1. Eloquent Javascript : A Mordern introduction to programming By Marjin Heverbeke\n\t2. Javascript : The Definitive guide By David Flanagan\n\t3. Effective Javascript By David Herman\n\t4. You don't know JS By Kzle Simpson"},java={"\t1. Java : How To Program By Deitel, Deitel\n\t2. Head First Java By Bert Bates\n\t3. Java Complete Reference By Herbert Schildt \n\t4. Thinking In Java By Bruce Eckel"}, php={"\t1. PHP in Action : Objects, Design, Agilitz By Daginn Reiersol\n\t2. Programming PHP : Creating Dznamic Web Pages By Kevin Tatroe\n\t3. PHP and MySQL Web Development By Laura Thompson\n\t4. PHP & MySQL Novice to Ninja By Tom Butler"}, python={"\t1. Python Crash Course By Eric Matthews\n\t2. Head First Python By paul Berrz\n\t3. Python Poriciti (Bangla) By Tamim Shahriar Subeen\n\t4. Sohoj Vasay Python (bangla) By Maksudur Rahman"};


    printf("\n\t\t\tEnter your name:");
    scanf("\n");
     scanf("%[^\n]%*c",s.name);
     printf("\n\t\t\tHello %s Welcome to counselling system",s.name);

    printf("\n\n\t\t > Press any key to Answere some question");
    printf("\n\t\t > press E to Exit             ");
    choice=toupper(getch());
    if (choice=='E')
    {
      exit(1);
    }
    else
    {
        printf("\n\n\tN.B. To show your DEDICATION  \n\tIf your option is 'A', then you click 'A' One times. If your option is 'B', then you click 'B' Two times. If your option is 'C', then you click 'C' Three times.                                                            ");


        printf("\n\nAre you student of cse?");
		printf("\n\nA.Yes\t\tB.No");
		if (toupper(getch())=='A')
	    {
            printf("\n\nDo you like programming?");
		    printf("\n\nA.Yes\t\tB.No\n\nC.Intarested");
            if (toupper(getch())=='A')
		    {
              printf("\n\nDo you know any programming Language?");
              printf("\n\nA.Yes\t\tB.No");
              if (toupper(getch())=='A')
              {
                  printf("\n\nWhat language do you want to learn?");
                  printf("\n\nA.C/C++\t\tB.JavaScript\n\nC.Java\t\tD.PHP\n\nE.Python\tF.Other Language");
                  if (toupper(getch())=='A')
                  {
                      printf("\n\n\tFor C/C++ you can follow these books: \n%s",cp.book);
                  }
                  else if (toupper(getch())=='B')
                  {
                      printf("\n\n\tFor JavaScript you can follow these books: \n%s",javaScript.book);
                  }
                  else if (toupper(getch())=='C')
                  {
                      printf("\n\n\tFor Java you can follow these books: \n%s",java.book);
                  }
                  else if (toupper(getch())=='D')
                  {
                      printf("\n\n\tFor PHP you can follow these books: \n%s",php.book);
                  }
                  else if (toupper(getch())=='E')
                  {
                      printf("\n\n\tFor Python you can follow these books: \n%s",python.book);
                  }
                  else if (toupper(getch())=='F')
                  {
                      printf("\n\n\t\tSorry, we do not have any other topics available at this time.");
                  }
                  else
                  {
                      exit(1);
                  }
              }
              else if (toupper(getch())=='B')
              {
                  printf("\n\tYou can start with C programming and follow these book: \n%s",cp.book);
              }
              else
              {
                  exit(1);
              }
          }
          else if (toupper(getch())=='B')
          {
              printf("\n\n\tSorry, we do not have any other topics available at this time.");
          }
          else if (toupper(getch())=='C')
          {
              printf("\n\tYou can start with C programming and follow these book: \n%s",cp.book);
          }
          else
          {
              exit(1);
          }
      }
      else if(toupper(getch())=='B')
      {
          printf("\n\n\tSorry, we do not have any other topics available at this time.");
      }
      else
      {
          exit(1);
      }
    }

    getch();
    return 0;
}