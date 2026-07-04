#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MedicineManager.h"



// Display all medicines in the inventory
void addMedicine(Medicine *list, int *size)
{
    Medicine m;

    printf("\n=====ADD NEW MEDICINE =====\n");

    printf("Enter Medicine ID: ");
    scanf("%s", m.id);

    // Check for duplicate IDs
    for(int i = 0; i < *size; i++)
    {
        if(strcmp(list[i].id, m.id) == 0)
        {
            printf("ID already exists!\n");
            return;
        }
    }

    getchar();

    printf("Enter medicine name: ");
    fgets(m.name, sizeof(m.name), stdin);
    m.name[strcspn(m.name, "\n")] = '\0';

    printf("Enter medicine price: ");
    scanf("%f", &m.price);

    printf("Enter quantity: ");
    scanf("%d", &m.quantity);

    getchar();

    printf("Enter ingredients: ");
    fgets(m.ingredients, sizeof(m.ingredients), stdin);
    m.ingredients[strcspn(m.ingredients, "\n")] = '\0';

    printf("Enter dosage: ");
    fgets(m.dosage, sizeof(m.dosage), stdin);
    m.dosage[strcspn(m.dosage, "\n")] = '\0';

    printf("Enter category: ");
    fgets(m.category, sizeof(m.category), stdin);
    m.category[strcspn(m.category, "\n")] = '\0';

    printf("Enter expiry date: ");
    fgets(m.expiry, sizeof(m.expiry), stdin);
    m.expiry[strcspn(m.expiry, "\n")] = '\0';

    printf("Enter packaging information: "); 
	fgets(m.packaging, sizeof(m.packaging), stdin); 
	m.packaging[strcspn(m.packaging, "\n")] = '\0';

    list[*size] = m;
    (*size)++;

    printf("\nMedicine added successfully!\n");
}

void updateMedicine(Medicine *list, int size)
{
    char id[20];
    int index = -1;

    printf("\n Enter medicine ID to update: ");
    scanf("%s", id);

    // Search medicine by ID
    for(int i = 0; i < size; i++)
    {
        if(strcmp(list[i].id, id) == 0)
        {
            index = i;
            break;
        }
    }

    if(index == -1)
    {
        printf(" Medicine not found!\n");
        return;
    }

    int choice;

    printf("\n1. Price\n");
    printf("2. Stock quantity\n");
    printf("3. Ingredients\n");
    printf("4. Packaging\n");
    printf("5. Category\n");
    printf("6. Dosage\n");
    printf("7. Expiry date\n");
    printf("0. Finish update\n");

    printf("\nEnter selection: ");
    scanf("%d", &choice);

    while(choice != 0)
    {
        switch(choice)
        {
            case 1:
                printf("Enter new price: ");
                scanf("%f", &list[index].price);
                printf("Update successful!\n");
                break;

            case 2:
                printf("Enter new stock quantity: ");
                scanf("%d", &list[index].quantity);
                printf("Update successful!\n");
                break;

            case 3:
                getchar();
                printf("Enter new ingredients: ");
                fgets(list[index].ingredients,
                      sizeof(list[index].ingredients),
                      stdin);

                list[index].ingredients[
                    strcspn(list[index].ingredients, "\n")
                ] = '\0';

                printf("Update successful!\n");
                break;

            case 4:
                getchar();
                printf("Enter new packaging: ");
                fgets(list[index].packaging,
                      sizeof(list[index].packaging),
                      stdin);

                list[index].packaging[
                    strcspn(list[index].packaging, "\n")
                ] = '\0';

                printf("Update successful!\n");
                break;

            case 5:
                getchar();
                printf("Enter new category: ");
                fgets(list[index].category,
                      sizeof(list[index].category),
                      stdin);

                list[index].category[
                    strcspn(list[index].category, "\n")
                ] = '\0';

                printf("Update successful!\n");
                break;

            case 6:
                getchar();
                printf(" Enter new dosage: ");
                fgets(list[index].dosage,
                      sizeof(list[index].dosage),
                      stdin);

                list[index].dosage[
                    strcspn(list[index].dosage, "\n")
                ] = '\0';

                printf("Update successful!\n");
                break;

            case 7:
                getchar();
                printf(" Enter new expiry date: ");
                fgets(list[index].expiry,
                      sizeof(list[index].expiry),
                      stdin);

                list[index].expiry[
                    strcspn(list[index].expiry, "\n")
                ] = '\0';

                printf("Update successful!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

        printf("\nEnter your next selection (0 to exit): ");
        scanf("%d", &choice);
    }

    printf("Exit the update function....\n");
}


// Delete a medicine from the inventory
void deleteMedicine(Medicine *list, int *size)
{
    char id[20];
    int index = -1;
    char confirm;

    printf("\n===== Delete Medicine =====\n");

    printf("Enter medicine ID to delete: ");
    scanf("%s", id);

    // Search medicine
    for(int i = 0; i < *size; i++)
    {
        if(strcmp(list[i].id, id) == 0)
        {
            index = i;
            break;
        }
    }

    if(index == -1)
    {
        printf("Medicine not found!\n");
        return;
    }

    printf("Are you sure you want to delete(Y/N): ");
    scanf(" %c", &confirm);

    if(confirm == 'Y' || confirm == 'y')
    {
        // Shift elements to the left
        for(int i = index; i < *size - 1; i++)
        {
            list[i] = list[i + 1];
        }

        (*size)--;

        printf("Delete successful!\n");
    }
    else
    {
        printf("Delete operation cancelled!\n");
    }
}

// Search medicine by ID
void searchMedicineByID(Medicine *list, int size)
{
    char id[20];
    int found = 0;

    printf("\nEnter medicine ID: ");
    scanf("%s", id);

    for(int i = 0; i < size; i++)
    {
        if(strcmp(list[i].id, id) == 0)
        {
            printf("\n===== Medicine Information =====\n");

            printf("ID: %s\n", list[i].id);
            printf("Medicine Name: %s\n", list[i].name);
            printf("Price: %.0f\n", list[i].price);
            printf("Stock Quantity: %d\n", list[i].quantity);
            printf("Ingredients: %s\n", list[i].ingredients);
            printf("Packaging: %s\n", list[i].packaging);
            printf("Category: %s\n", list[i].category);
            printf("Dosage: %s\n", list[i].dosage);
            printf("Expiry Date: %s\n", list[i].expiry);

            found = 1;
            break;
        }
    }

    if(!found)
    {
        printf("Medicine not found!\n");
    }
}


// Search medicine by name
void searchMedicineByName(Medicine *list, int size)
{
    char name[50];
    int found = 0;

    getchar();

    printf("\nEnter medicine name: ");
    fgets(name, sizeof(name), stdin);

    name[strcspn(name, "\n")] = '\0';

    for(int i = 0; i < size; i++)
    {
        if(strcmp(list[i].name, name) == 0)
        {
            printf("\n===== Medicine Information =====\n");

            printf("ID: %s\n", list[i].id);
            printf("Medicine Name: %s\n", list[i].name);
            printf("Price: %.0f\n", list[i].price);
            printf("Stock Quantity: %d\n", list[i].quantity);
            printf("Ingredients: %s\n", list[i].ingredients);
            printf("Packaging: %s\n", list[i].packaging);
            printf("Category: %s\n", list[i].category);
            printf("Dosage: %s\n", list[i].dosage);
            printf("Expiry Date: %s\n", list[i].expiry);

            found = 1;
        }
    }

    if(!found)
    {
        printf("Medicine not found!\n");
    }
}


//sortPriceAscending()
void sortPriceAscending(Medicine *list, int size)
{
    Medicine temp;

    for(int i = 0; i < size - 1; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(list[i].price > list[j].price)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}


//sortPriceDescending()
void sortPriceDescending(Medicine *list, int size)
{
    Medicine temp;

    for(int i = 0; i < size - 1; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(list[i].price < list[j].price)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

//sortByExpiry()
void sortByExpiry(Medicine *list, int size)
{
    Medicine temp;

    for(int i = 0; i < size - 1; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            int e1 = atoi(list[i].expiry);
            int e2 = atoi(list[j].expiry);

            if(e1 > e2)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

//deleteExpiredMedicine()
void deleteExpiredMedicine(Medicine *list, int *size)
{
    printf("\n===== Delete Expired Medicines =====\n");

    int current = 40; // Simulated current month

    int i = 0;
    int found = 0;

    while (i < *size)
    {
        int expiryMonth = atoi(list[i].expiry);
        //if no numeric expiry value
        
        if (expiryMonth == 0)
        {   
            i++;
            continue;
        }

        if (expiryMonth < current)
        {
            printf("\n[Expired medicine removed] %s - %s (EXPIRY DATE: %s)\n",
                   list[i].id,
                   list[i].name,
                   list[i].expiry);

            // dồn trái
            for (int j = i; j < *size - 1; j++)
            {
                list[j] = list[j + 1];
            }

            (*size)--;
            found = 1;
        }
        else
        {
            i++;
        }
    }

    if (!found)
    {
        printf("No expired medicines found!\n");
    }
    else
    {
        printf("\nAll expired medicines have been removed!\n");
    }
}
