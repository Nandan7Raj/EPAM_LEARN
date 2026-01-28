//
// Created by NandanRaj on 25-01-2026.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Contact
{
    char name[50];
    char phone[20];
};
struct Contact* addContact(struct Contact* contacts_array, int* current_size, const struct Contact* new_contact);
const struct Contact* findContact(const struct Contact* contacts_array, int current_size, const char* search_name);
void displayAllContacts(const struct Contact* contacts_array, int current_size);
void cleanupContacts(struct Contact** contacts_array, int* current_size);
void getInput(struct Contact* newCont);
void printContact(const struct Contact* user);

int main()
{
    struct Contact* contact = NULL;
    static int choice,cur_size=0;
    while(choice!=3)
    {   printf("\ncur_size== %d\n",cur_size);
        printf("Choose from below options:\n");
        printf("0. For adding new contact.\n");
        printf("1. For finding a contact.\n");
        printf("2. For  displaying all contacts.\n");
        printf("3. For Exiting\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0:
            printf("so you want to add new contact.\n");
            struct Contact* newCont= malloc(sizeof(*newCont));
            getInput(newCont);


            while(newCont==NULL || findContact(contact,cur_size,newCont->name)!=NULL)
            {
                if(newCont==NULL)
                    printf("intput was unsuccessful.\n");
                else
                    printf("User name exist in contacts.\n");
                getInput(newCont);
            }
            contact = addContact(contact, &cur_size, newCont);
                free(newCont);

            break;

            case 1:
            printf("Enter name of user whose contact you want to search: ");
            char searchName[50];
            scanf(" %[^\n]",searchName);
            const struct Contact* foundContact = findContact(contact,cur_size,searchName);
            if(foundContact==NULL)
                printf("There is no such user.");
            else
                printContact(foundContact);
            break;

            case 2:
            printf("All contacts are. \n");
            displayAllContacts(contact, cur_size);
            break;

            case 3:
            printf("so you want to exit.\n");
            cleanupContacts( &contact , &cur_size);
            break;

            default:
            printf("make a valid choice\n");
        }
    }

    if(contact!=NULL)
    {
    free(contact);
    contact=NULL;
    }
    printf("Thank You\n");

    return 0;
}

struct Contact* addContact(struct Contact* contacts_array, int* current_size, const struct Contact* new_contact)
{
    struct Contact* temp =NULL;
    if(contacts_array==NULL)
    {
       temp =malloc(sizeof(struct Contact));
    }
    else
    {
        temp= realloc(contacts_array,(*current_size+1)*sizeof(struct Contact));
    }
     if (temp == NULL) {
        // Allocation failed, original memory still valid
        return contacts_array;
    }
    contacts_array = temp;
    strcpy(contacts_array[*current_size].phone,new_contact->phone);
    strcpy(contacts_array[*current_size].name,new_contact->name);
    (*current_size)++;
    return contacts_array;
}

const struct Contact* findContact(const struct Contact* contacts_array, int current_size, const char* search_name)
{
     for(int i=0;i<current_size;i++)
     {
        if(strcmp((contacts_array+i)->name,search_name)==0)
        return (contacts_array+i);
     }
     return NULL;
}

void displayAllContacts(const struct Contact* contacts_array, int current_size)
{
    if(current_size==0)
     printf("No contact data prsent\n");

    for(int i=0;i<current_size;i++)
    {
        printContact(contacts_array+i);
    }
}
void cleanupContacts(struct Contact** contacts_array, int* current_size) {
    if (*contacts_array != NULL) {
        free(*contacts_array);
        *contacts_array = NULL;
    }
    *current_size = 0;
    printf("All memory freed\n");
}

void getInput(struct Contact* newCont)
{   if(newCont==NULL)
     printf("can not take input in NULL\n");
    char input_name[50],input_phone[50];
    printf("Enter name: ");
    scanf(" %49[^\n]",input_name);

    printf("Enter phone No. ");
    scanf(" %49[^\n]",input_phone);
    strcpy(newCont->name,input_name);
    strcpy(newCont->phone,input_phone);

}
void printContact(const struct Contact* user)
{
    printf("Name: %s\nPhone: %s\n",user->name,user->phone);
}