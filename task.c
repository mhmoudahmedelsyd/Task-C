#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define NUM_OF_USER 100


struct User
{
    char username[20];
    char email[50];
    char password[20];
    union 
    {
         bool ActiveBool;
         int ActiveInt;
    }ActiveFlag;
    

};

struct User users[NUM_OF_USER];

int UsersCounter = 0;

bool is_valid_email(char* email) {
    return strchr(email, '@') != NULL && strchr(email, '.') != NULL;
}

void RegisterMthod()
{

    printf("Enter a email: ");
    scanf("%s", users[UsersCounter].email);
    for(int i=0;i<UsersCounter;i++)
    {
        if(strcmp(users[UsersCounter].email,users[i].email)==0)
        {
            
            printf("Email already exists. Registration failed.\n");
            return;

        } 

    }

     if (!is_valid_email(users[UsersCounter].email)) {
        printf("Invalid email format. Registration failed.\n");
        return ;
    }
  
   printf("Enter a username: ");
    scanf("%s", users[UsersCounter].username);
  

    printf("Enter a password: ");
    scanf("%s", users[UsersCounter].password);
    char flagInput[10];
    printf("Enter the active flag (1/0 or true/false): ");
    scanf("%s", flagInput);
    if (strcmp(flagInput, "1") == 0 || strcasecmp(flagInput, "true") == 0) {
        users[UsersCounter].ActiveFlag.ActiveBool = true;
        users[UsersCounter].ActiveFlag.ActiveInt = 1;
    } else if (strcmp(flagInput, "0") == 0 || strcasecmp(flagInput, "false") == 0) {
        users[UsersCounter].ActiveFlag.ActiveBool = false;
        users[UsersCounter].ActiveFlag.ActiveInt = 0;
    } else {
        printf("Invalid flag input. Registration failed.\n");
        return;
    }


    printf("Registration successful..\n");
    UsersCounter++;
}


void LoginMethod()
{
    char email[50];
    char password[20];

    printf("Enter your email: ");
    scanf("%s", email);

    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < UsersCounter; i++)
    {
        if (strcmp(email, users[i].email) == 0 && strcmp(password, users[i].password) == 0)
        {
            if(users[i].ActiveFlag.ActiveBool==true||users[UsersCounter].ActiveFlag.ActiveInt==1 ){
            printf("Login successful..\n");
            return;
            }else{
                printf("Your Are Not Active:\n");
                return ;
            }

           
        }
    }

    printf("Login failed. Invalid email or password.\n");
}

int main()
{


    int choice;

    while (true)
    {
        printf("Choose an option:\n");
        printf("1- Register\n");
        printf("2- Login\n");
        printf("3- Exit\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            RegisterMthod();
            break;
        case 2:
            LoginMethod();
            break;
        case 3:
            printf("Goodbye..\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
            return 0;
        }
    }

    return 0;
}
