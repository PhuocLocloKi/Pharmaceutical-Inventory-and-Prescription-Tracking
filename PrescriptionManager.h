#ifndef PRESCRIPTION_H
#define PRESCRIPTION_H

#include "Medicine.h"

typedef struct {
    char patient[50];
    char doctor[50];
    char phone[20];
    char date[20];
    float total;
    
    char pharmacist[50];
} Invoice;


// Creates a new prescription invoice, records patient information, medicine purchases, and assigns a doctor and pharmacist
void createInvoice(Medicine *list, int size, Invoice *invoices, int *invoiceCount);

// Displays the complete prescription history with patient, doctor, pharmacist, and payment details
void printInvoices(Invoice *invoices, int invoiceCount);

// Searches and displays prescription records by patient name or doctor name
void showDirectory(Invoice *invoices, int invoiceCount);

// Assigns or updates a pharmacist for an existing prescription invoice
void assignPharmacist(Invoice *invoices, int invoiceCount);


// Displays all patients stored in the prescription system
void showPatients();

// Displays all doctors available in the prescription system
void showDoctors();
// Searches for a prescription record by patient name
void searchPatient(char name[]);

// Searches for a prescription record by doctor name
void searchDoctor(char name[]);
#endif


