#ifndef MEDICINEMANAGER_H
#define MEDICINEMANAGER_H

#include "Medicine.h"


//Add a new medicine to the inventory, collects medicine information from the user, and stores it in the medicine list
void addMedicine(Medicine *list, int *size);

// Update medicine information by searching for a medicine ID and modifying the selected details
void updateMedicine(Medicine *list, int size);

// Delete a medicine from the inventory by searching for its ID and removing it from the list
void deleteMedicine(Medicine *list, int *size);

// Search for a medicine by ID and display its information
void searchMedicineByID(Medicine *list, int size);

// Search for a medicine by name and display its information
void searchMedicineByName(Medicine *list, int size);

// Sort medicines in ascending order based on price
void sortPriceAscending(Medicine *list, int size);

// Sort medicines in descending order based on price
void sortPriceDescending(Medicine *list, int size);

// Sort medicines according to their expiry dates
void sortByExpiry(Medicine *list, int size);

// Remove expired medicines from the inventory list
void deleteExpiredMedicine(Medicine *list, int *size);

// Display all medicines in a formatted table
void printAllMedicines(Medicine *list, int size);
#endif 

