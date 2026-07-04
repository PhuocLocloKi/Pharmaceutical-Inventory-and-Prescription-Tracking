#include <stdio.h>
#include <stdlib.h>

#include "AdminUI.h"
#include"medicine.h"
#include"medicineManager.h"
#include <string.h>
#include "PrescriptionManager.h"
int main() {
    int choice;
    
    Medicine list[100];
    int size = 0;
    
    Invoice invoices[100];
    int invoiceCount = 0;
    
    
    strcpy(list[0].id, "MED001");
	strcpy(list[0].name, "Calcium Premium");
	list[0].price = 920000;
	strcpy(list[0].ingredients, "Canxi, Vitamin D3, K2, Magie");
	strcpy(list[0].packaging, "Box of 120 tablets");
	strcpy(list[0].category, "joint bone");
	strcpy(list[0].expiry, "36 months");
	list[0].quantity = 50;
    strcpy(list[0].dosage, "2 tablets/day");
	size++;
	
	strcpy(list[1].id, "MED002");
	strcpy(list[1].name, "Omexxel Bone Health");
	list[1].price = 539000;
	strcpy(list[1].ingredients, "Canxi, Collagen, Vitamin D3");
	strcpy(list[1].packaging, "Box of 60 tablets");
	strcpy(list[1].category, "joint bone");
	strcpy(list[1].expiry, "36 months");
	list[1].quantity = 35;
    strcpy(list[1].dosage, "1 tablets/day");
	size++;
	
	strcpy(list[2].id, "MED003");
	strcpy(list[2].name, "Calci K-2");
	list[2].price = 513000;
	strcpy(list[2].ingredients, "Canxi, Kẽm, Magie");
	strcpy(list[2].packaging, "Box of 60 tablets");
	strcpy(list[2].category, "joint bone");
	strcpy(list[2].expiry, "36 months");
	list[2].quantity = 40;
    strcpy(list[2].dosage, "1 tablets/day");
	size++;
	
	strcpy(list[3].id, "MED004");
	strcpy(list[3].name, "Kudos Bone");
	list[3].price = 126000;
	strcpy(list[3].ingredients, "Canxi, Vitamin D3, K2");
	strcpy(list[3].packaging, "Box of 20 tablets");
	strcpy(list[3].category, "joint bone");
	strcpy(list[3].expiry, "36 months");
	list[3].quantity = 25;
    strcpy(list[3].dosage, "1 tablets/day");
	size++;
	
	strcpy(list[4].id, "MED005");
	strcpy(list[4].name, "Kids Smart Calcium");
	list[4].price = 540000;
	strcpy(list[4].ingredients, "Canxi, Vitamin D3");
	strcpy(list[4].packaging, "Box of 50 tablets");
	strcpy(list[4].category, "Vitamin D");
	strcpy(list[4].expiry, "36 months");
	list[4].quantity = 30;
    strcpy(list[4].dosage, "1 tablets/day");
	size++;
	
	strcpy(list[5].id, "MED006");
	strcpy(list[5].name, "Calci K2 Nordic");
	list[5].price = 365000;
	strcpy(list[5].ingredients, "Canxi, Magie, Vitamin D3");
	strcpy(list[5].packaging, "HBox of 60 tablets");
	strcpy(list[5].category, "joint bone");
	strcpy(list[5].expiry, "36 months");
	list[5].quantity = 45;
    strcpy(list[5].dosage, "2 tablets/day");
	size++;
	
	strcpy(list[6].id, "MED007");
	strcpy(list[6].name, "Omega 3 Plus");
	list[6].price = 920000;
	strcpy(list[6].ingredients, "Omega 3, DHA, EPA");
	strcpy(list[6].packaging, "Box of 60 tablets");
	strcpy(list[6].category, "Omega 3");
	strcpy(list[6].expiry, "36 months");
	list[6].quantity = 20;
    strcpy(list[6].dosage, "2 tablets/day");
	size++;
	
	strcpy(list[7].id, "MED008");
	strcpy(list[7].name, "Omega 3-6-9");
	list[7].price = 622000;
	strcpy(list[7].ingredients, "Omega 3, 6, 9");
	strcpy(list[7].packaging, "6 blisters/20 tabs");
	strcpy(list[7].category, "Omega 3");
	strcpy(list[7].expiry, "36 months");
	list[7].quantity = 18;
    strcpy(list[7].dosage, "2 tablets/day");
	size++;
	
	strcpy(list[8].id, "MED009");
	strcpy(list[8].name, "Liquid Zinc Kids");
	list[8].price = 380000;
	strcpy(list[8].ingredients, "cream, Vitamin C, D3");
	strcpy(list[8].packaging, "200 ml bottle");
	strcpy(list[8].category, "immunity");
	strcpy(list[8].expiry, "24 months");
	list[8].quantity = 22;
    strcpy(list[8].dosage, "5 mL/day");
	size++;
	
	strcpy(list[9].id, "MED010");
	strcpy(list[9].name, "Fixderma SPF 55+");
	list[9].price = 363200;
	strcpy(list[9].ingredients, "Titanium dioxide");
	strcpy(list[9].packaging, "75 g tube");
	strcpy(list[9].category, "Sun Protection");
	strcpy(list[9].expiry, "Unknown");
	list[9].quantity = 15;
    strcpy(list[9].dosage, "Topical use");
	size++;
	
	strcpy(list[10].id, "MED011");
	strcpy(list[10].name, "Vitamin C 500mg");
	list[10].price = 260000;
	strcpy(list[10].ingredients, "Vitamin C");
	strcpy(list[10].packaging, "Box of 40 tablets");
	strcpy(list[10].category, "Vitamin C");
	strcpy(list[10].expiry, "36 months");
	list[10].quantity = 60;
    strcpy(list[10].dosage, "1 tablet/day");
	size++;
	
	strcpy(list[11].id, "MED012");
	strcpy(list[11].name, "Elasten Collagen");
	list[11].price = 2301000;
	strcpy(list[11].ingredients, "Collagen, Vitamin C");
	strcpy(list[11].packaging, "Box of 30 ampoules");
	strcpy(list[11].category, "Skin Care");
	strcpy(list[11].expiry, "30 months");
	list[11].quantity = 12;
    strcpy(list[11].dosage, "1 sachet/day");
	size++;
	
	strcpy(list[12].id, "MED013");
	strcpy(list[12].name, "G-TEEN Kenko");
	list[12].price = 1240000;
	strcpy(list[12].ingredients, "Multivitamins, DHA");
	strcpy(list[12].packaging, "Box of 30 sachets");
	strcpy(list[12].category, "Vitamin");
	strcpy(list[12].expiry, "36 months");
	list[12].quantity = 28;
    strcpy(list[12].dosage, "1 sachet/day");
	size++;

    

    do {
    	
        printf("\n============================================\n");
        printf("  INVENTORY & PRESCRIPTION MANAGEMENT SYSTEM\n");
        printf("             PHARMACARE SYSTEM               \n");
        printf("============================================\n");

		printf("1.  Add New Medicine\n");
		printf("2.  Update Medicine Information\n");
		printf("3.  Delete Medicine By ID\n");
		printf("4.  Search Medicine\n");
		printf("5.  Display Medicine List\n");
		printf("6.  Sort Medicines\n");
		printf("7.  Delete Expired Medicines\n");
		printf("8.  Create Prescription / Sell Medicine\n");
		printf("9.  View Prescription History\n");
		printf("10. Search Prescription\n");
		printf("11. Assign Prescription To Pharmacist\n");
		printf("0.  Save Data And Exit\n");
		
		printf("------------------------------------\n");
		printf("Enter Choice: ");
		scanf("%d", &choice);

        switch (choice) {
        	
            // Add a new medicine to the inventory
            case 1:
                addMedicine(list, &size);
                break;

            // Update medicine
            case 2:
                updateMedicine(list, size);
                break;


	        // Delete a medicine from the inventory
            case 3:
                deleteMedicine(list, &size);
                break;


            // Search medicine by ID or name
            case 4:{
                int subChoice;

               printf("\n===== SEARCH MEDICINE =====\n");
			   printf("1. Search By ID\n");
               printf("2. Search By Name\n");

			   printf("Enter Choice: ");
			   scanf("%d", &subChoice);
               
               switch(subChoice){
               	case 1:
               		searchMedicineByID(list, size);
                    break;
                
                case 2:
                	searchMedicineByName(list, size);
                    break;
                    
                default:
                	printf("Invalid Choice!\n");
			   }

			
			    break;
            }
            
            
            // Display all medicines in the inventory
            case 5:
                printAllMedicines(list, size);
                break;

            //Sort Medicines
            case 6:
            {
			
	            int subChoice;
				int priceChoice = 0;
				
				printf("\n===== SORT MEDICINES =====\n");
				printf("1. Sort By Price\n");
				printf("2. Sort By Expiry Date\n");
				printf("Enter Choice: ");
				scanf("%d", &subChoice);
				
				if(subChoice == 1)
				{
				    printf("\n===== Sort By Price =====\n");
				    printf("1. Price Ascending \n");
				    printf("2. Price Descending \n");
				    printf("Enter Choice: ");
				    scanf("%d", &priceChoice);
				}
				
				if(subChoice == 1)
				{
				    if(priceChoice == 1)
				    {
				        sortPriceAscending(list, size);
				        printf("\nSort By Price Ascending Successfully!\n");
				        
				        printAllMedicines(list, size);
				    }
				    else if(priceChoice == 2)
				    {
				        sortPriceDescending(list, size);
				        printf("\nSort By Price Descending Successfully!\n");
				        
				        printAllMedicines(list, size);
				    }
				    else
				    {
				        printf("\nInvalid Choice!\n");
				    }
				}
				else if(subChoice == 2)
				{
				    sortByExpiry(list, size);
				    printf("\nSort By Expiry Date Successfully!\n");
				    printAllMedicines(list, size);
				}
				else
				{
				    printf("\nInvalid Choice!\n");
				}
                break;
            }
            
            
            // Remove expired medicines from inventory
            case 7:
                deleteExpiredMedicine(list, &size);
                break;


            // Create a prescription and process medicine sales
            case 8:
            	createInvoice(list, size, invoices, &invoiceCount);
                break;


              // Display prescription history
            case 9:
                printInvoices(invoices, invoiceCount);
                break;


            // Search prescriptions by patient or doctor
            case 10:
                showDirectory(invoices, invoiceCount);      

		        break;
            
            
            //Assign Prescription to Pharmacist
            case 11:
				assignPharmacist(invoices, invoiceCount);
                break;
 
            
			// Save data and exit the system.
            case 0:
                printf("Save Data...\n");
                printf("Exit Program...\n");
                break;


            default:
                printf("Invalid Choice!\n");
        }

    }while (choice != 0);

    return 0;

    

}