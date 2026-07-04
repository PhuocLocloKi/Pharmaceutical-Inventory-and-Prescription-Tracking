#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "PrescriptionManager.h"

// ===== GLOBAL INPUT =====
char patient[50];
char phone[20];
char date[20];
char id[20];
int qty;
float total = 0;

// ===== FIX QUAN TRỌNG: PHẢI CÓ doctors =====
	char doctors[5][50] = {
	    "Dr. John Smith",
	    "Dr. Emily Brown",
	    "Dr. David Lee",
	    "Dr. Anna White",
	    "Dr. Michael Tran"
	};
	char pharmacists[5][50] = {
	    "Nguyen Thi Thu Hang",
	    "Tran Van Minh",
	    "Le Thi Hong Anh",
	    "Pham Quoc Bao",
	    "Vo Thi Kim Chi"
	};
// Create a prescription and process medicine sales
void createInvoice(Medicine *list, int size, Invoice *invoices, int *invoiceCount)
{
    printf("\n===== CREATE PRESCRIPTION =====\n");

    if (*invoiceCount >= 100)
    {
        printf("Invoice list is full!\n");
        return;
    }

    total = 0;

    // FIX INPUT BUFFER
    getchar();

    printf("Patient Name: ");
    fgets(patient, sizeof(patient), stdin);
    patient[strcspn(patient, "\n")] = '\0';

    printf("Phone Number: ");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\n")] = '\0';

    printf("Issue Date: ");
    fgets(date, sizeof(date), stdin);
    date[strcspn(date, "\n")] = '\0';

    while (1)
    {
        printf("\nEnter Medicine ID (0 to finish): ");
        scanf("%s", id);

        if (strcmp(id, "0") == 0)
            break;

        int found = -1;

        for (int i = 0; i < size; i++)
        {
            if (strcmp(list[i].id, id) == 0)
            {
                found = i;
                break;
            }
        }

        if (found == -1)
        {
            printf("Medicine not found!\n");
            continue;
        }

        printf("Enter Quantity: ");
        scanf("%d", &qty);

        if (qty > list[found].quantity)
        {
            printf("Insufficient stock!\n");
            continue;
        }

        total += list[found].price * qty;
        list[found].quantity -= qty;

        printf("Added: %s x%d\n", list[found].name, qty);
    }

    // Select Doctor
    int d;
    printf("\nSelect Doctor:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d. %s\n", i + 1, doctors[i]);
    }

    printf("Enter Choice: ");
    scanf("%d", &d);

    if (d < 1 || d > 5)
        d = 1;
    

	int d_pharm;
	
	printf("\nSelect Pharmacist:\n");
	for (int i = 0; i < 5; i++)
	{
	    printf("%d. %s\n", i + 1, pharmacists[i]);
	}
	
	printf("Enter Choice: ");
	scanf("%d", &d_pharm);
	
	if (d_pharm < 1 || d_pharm > 5)
	    d_pharm = 1;

    // ===== PRINT INVOICE =====
	printf("\n===== INVOICE =====\n");
	printf("Patient: %s\n", patient);
	printf("Phone number: %s\n", phone);
	printf("Date: %s\n", date);
	printf("Doctor: %s\n", doctors[d - 1]);
	printf("Pharmacist: %s\n", pharmacists[d_pharm - 1]);
	printf("Total amount: %.0f\n", total);

    // SAVE INTO ARRAY
    strcpy(invoices[*invoiceCount].patient, patient);
    strcpy(invoices[*invoiceCount].phone, phone);
    strcpy(invoices[*invoiceCount].date, date);
    strcpy(invoices[*invoiceCount].doctor, doctors[d - 1]);
    invoices[*invoiceCount].total = total;
    strcpy(invoices[*invoiceCount].pharmacist, pharmacists[d_pharm - 1]);
    (*invoiceCount)++;
}

 // Display prescription history
void printInvoices(Invoice *invoices, int invoiceCount)
{
    printf("\n===== PRESCRIPTION HISTORY =====\n");

    if (invoiceCount == 0)
    {
        printf("No invoices available!\n");
        return;
    }

    for (int i = 0; i < invoiceCount; i++)
    {
        printf("\n--- INVOICE %d ---\n", i + 1);
        printf("Patient: %s\n", invoices[i].patient);
        printf("Doctor: %s\n", invoices[i].doctor);
        printf("Pharmacist: %s\n", invoices[i].pharmacist);
        printf("Phone number: %s\n", invoices[i].phone);
        printf("Date: %s\n", invoices[i].date);
        printf("Total amount: %.0f\n", invoices[i].total);
    }
}


// Search prescriptions by patient or doctor
void showDirectory(Invoice *invoices, int invoiceCount)
{
    int choice;
    char key[50];

    printf("\n================ CASE 10 ================\n");

    printf("\n===========  PRESCRIPTION DIRECTORY ===========\n");

    for (int i = 0; i < invoiceCount; i++)
    {
        printf("%d.  %s | %s | %s\n",
               i + 1,
		       invoices[i].patient,
		       invoices[i].doctor,
		       invoices[i].pharmacist);
    }

    printf("\n1.Search by Patient Name\n");
    printf("2. Search by Doctor Name\n");
    printf("Select: ");
    scanf("%d", &choice);
    getchar();

    // PATIENT SEARCH
    if (choice == 1)
    {
        printf("\nEnter Patient Name: ");
        fgets(key, sizeof(key), stdin);
        key[strcspn(key, "\n")] = '\0';

        int found = 0;

        for (int i = 0; i < invoiceCount; i++)
        {
            if (strcmp(invoices[i].patient, key) == 0)
            {
                printf("\n=== RESULT ===\n");
                printf("Patient: %s\n", invoices[i].patient);
                printf("Doctor : %s\n", invoices[i].doctor);
                printf("Pharmacist: %s\n", invoices[i].pharmacist); 
                printf("Phone number: %s\n", invoices[i].phone);
                printf("Date: %s\n", invoices[i].date);
                printf("Total amount: %.0f\n", invoices[i].total);
                found = 1;
            }
        }

        if (!found)
            printf("Prescription not found!\n");
    }

    // DOCTOR SEARCH
    else if (choice == 2)
    {
        printf("\nEnter Doctor Name: ");
        fgets(key, sizeof(key), stdin);
        key[strcspn(key, "\n")] = '\0';

        int found = 0;

        for (int i = 0; i < invoiceCount; i++)
        {
            if (strcmp(invoices[i].doctor, key) == 0)
            {
                printf("\n=== RESULT ===\n");
                printf("Patitent: %s\n", invoices[i].patient);
                printf("Doctor: %s\n", invoices[i].doctor);
                printf("Phone number: %s\n", invoices[i].phone);
                printf("Date: %s\n", invoices[i].date);
                printf("Total amount: %.0f\n", invoices[i].total);
                found = 1;
            }
        }

        if (!found)
            printf("Prescription not found!\n");
    }
}
void assignPharmacist(Invoice *invoices, int invoiceCount)
{
    char key[50];
    char pharm[50];

    printf("\n===== ASSIGN PHARMACIST =====\n");

    printf("Enter Patient Name: ");
    getchar();
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';

    int found = -1;

    for (int i = 0; i < invoiceCount; i++)
    {

        if (strstr(invoices[i].patient, key) != NULL)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        printf("Prescription Found!\n");
        return;
    }

    printf("Order found: %s\n", invoices[found].patient);

    printf("Enter the pharmacist name: ");
    fgets(pharm, sizeof(pharm), stdin);
    pharm[strcspn(pharm, "\n")] = '\0';

    strcpy(invoices[found].pharmacist, pharm);

    printf("Assigned Successfully!\n");
}