#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "companylib.h"


int main(void)
{
    f = fopen("The Company.txt", "a+");
    if (f == NULL)
    {
        printf("File does not exist\n");
        exit(1);
    }

    loadEmployees();

    int inputChoice;
    int prevChoice = -1;
    int searchChoice;

    while (1)  // Infinite loop
    {
        while (1)
        {
            printf("\nPress 1 for Add a New Employee.");
            printf("\nPress 2 for Search for Employee.");
            printf("\nPress 3 for Sorting.");
            printf("\nPress 4 for Modify.");
            printf("\nPress 5 for Delete an Employee.");
            printf("\nPress 6 for print the Employees.");
            printf("\nPress 0 to Exit and Save.");

            char input[10];

            printf("\nEnter The Number: ");
            scanf("%s", input);

            if (!isNumeric(input))
            {
                flag = 1;
                printf("The choise Must Be Only Numbers.\n\n");
                sleep(2);
                system("cls");
            }
            else
            {
                inputChoice = atoi(input);
                break;
            }
        }
        switch (inputChoice)
        {
        case 1:
            system("cls");
            ADDEMPLOYEE();
            sleep(2);
            system("cls");
            prevChoice = 1;
            break;

        case 2:
            do
            {
                system("cls");
                searchByName(searchName, totalNumberOfEmployees);
                prevChoice = 2;

                printf("\nPress 1 for another search.");
                printf("\nPress 0 to go back to the main menu.");

                do
                {
                    printf("\nEnter The Number: ");
                    scanf("%d", &searchChoice);

                    if (searchChoice == 0)
                    {
                        system("cls");
                        break;
                    }
                    else if (searchChoice != 1)
                    {
                        printf("Invalid choice during another search!\n");
                    }
                }
                while (searchChoice != 0 && searchChoice != 1);
            }
            while (searchChoice == 1);

            break;

case 3:
    while (1)
    {
        system("cls");
        printf("\nPress 1 for Sort By Name.");
        printf("\nPress 2 for Sort By Date Of Birthday.");
        printf("\nPress 3 for Sort By Salary.");
        printf("\nPress 00 to go back.");

        char input[10];

        printf("\nEnter The Number: ");
        scanf("%s", input);

        if (!isNumeric(input))
        {
            flag = 1;
            printf("The choice Must Be Only Numbers.\n\n");
            sleep(2);
            system("cls");
        }
        else
        {
            inputChoice = atoi(input);

            if (inputChoice == 0)
            {
                inputChoice = prevChoice;
                system("cls");
                break;
            }
            else
            {
                switch (inputChoice)
                {
                case 1:
                    system("cls");
                    sortByName();
                    break;
                case 2:
                    system("cls");
                    sortByDOB();
                    break;
                case 3:
                    system("cls");
                    sortBySalary();
                    break;
                default:
                    printf("Invalid choice for sorting!\n");
                    break;
                }

                printEmployees();
                prevChoice = 3;
                break;
            }
        }
    }
    break;


        case 4:
            system("cls");
            modifyFieldByID();
            prevChoice = 4;
            break;

        case 5:
            system("cls");
            deleteEmployeeByID();
            sleep(2);
            system("cls");
            prevChoice = 5;
            break;

        case 6:
            system("cls");
            printEmployees();
            prevChoice = 6;
            break;

        case 0:
            printf("Exiting the program.\n");
            fclose(f);
            return 0;  // Exit the program

        default:
            printf("Invalid choice!\n");
            sleep(2);
            system("cls");
        }
    }

    fclose(f);
    return 0;
}