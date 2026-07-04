#ifndef MEDICINE_H
#define MEDICINE_H

//Store information about a medicine
typedef struct {
    char id[20];
    char name[50];
    float price;
    int quantity;
    char ingredients[100];
    char dosage[50];
    char packaging[50];
    char category[50];
    char expiry[20];
    
} Medicine;


//Display all medicines in the inventory
void printAllMedicines(Medicine *list, int size);

#endif