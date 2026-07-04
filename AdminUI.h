#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "medicine.h"
#include "medicineManager.h"
#include "PrescriptionManager.h"

/**
 * @brief Entry point of the Pharmacy Inventory and Prescription Management System.
 *
 * This function initializes medicine and invoice data,
 * displays the main menu, processes user selections,
 * and calls the corresponding management functions
 * until the user chooses to exit the program.
 *
 * @return Returns 0 when the program terminates successfully.
 */
int main(void);

#endif