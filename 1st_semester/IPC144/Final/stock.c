#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "stock.h"

#define NUM_CATS 7
#define MAX_ITEMS_IN_SALE 100

int readStockItems(struct StockRecord stockrecord[], int max, int STOCK_FROM_STDIN){
	int i, count = 0;

	if (STOCK_FROM_STDIN == 1) {
		for (i = 0; i < max; i++){
			scanf(" %f, %d, %f, %d, %30[^\n]", &stockrecord[i].quantity,
				  &stockrecord[i].product.category, &stockrecord[i].product.price,
				  &stockrecord[i].product.byWeight, stockrecord[i].item);
			clearKeyboard();
			
			if (stockrecord[i].quantity == 0) {
				break;
			}

			if (stockrecord[i].product.category < 1 ||
				stockrecord[i].product.category > 7) {
				printf("Invalid Category - Enter a number between 1 and 7: ");
				scanf(" %d, %f, %d, %30[^\n]", &stockrecord[i].product.category,
					  &stockrecord[i].product.price, &stockrecord[i].product.byWeight,
					  stockrecord[i].item);
				clearKeyboard();
			}

			if (stockrecord[i].product.byWeight != 1 &&
				stockrecord[i].product.byWeight != 0 ) {
				printf("Invalid soldBYWeight - Enter a number between 0 and 1: ");
				scanf(" %d, %40[^\n]", &stockrecord[i].product.byWeight,
					  stockrecord[i].item);
				clearKeyboard();
			}
			stockrecord[i].product.ID = i + 1;
			count++;
		}
	}
	return count;
}

void printStockReport(struct StockRecord stockrecord[], int numStockItems){
	int i; 
	printf("  ID                        Product        Category   Price   Quantity\n");
	for (i = 0; i < numStockItems; i++) {
		printf("%4d%31s%16s%8.2f%11.0f\n", stockrecord[i].product.ID,
			   stockrecord[i].item,getCatName(stockrecord[i].product.category),
			   stockrecord[i].product.price, stockrecord[i].quantity);
	}
}

int readSale(struct StockRecord stockrecord[],
	           int numStockItems, struct SalesRecord salesrecord[]){
	int i, index, count = 0;

	for (i = 0; i < numStockItems; i++) {
		printf("Enter a product ID to purchase, and the quantity (0 to stop): ");
		scanf(" %d, %f", &salesrecord[i].stockrecord.product.ID,
			  &salesrecord[i].stockrecord.quantity);
		clearKeyboard();

	if (salesrecord[i].stockrecord.product.ID == 0) {
		break;
	}

	if (salesrecord[i].stockrecord.product.ID < 1 ||
		salesrecord[i].stockrecord.product.ID > numStockItems) {
		printf("Invalid Product - Enter a number between 1 and %d: ",
			   numStockItems);
		scanf(" %d, %f", &salesrecord[i].stockrecord.product.ID,
			  &salesrecord[i].stockrecord.quantity);
		clearKeyboard();
	}
	if (salesrecord[i].stockrecord.quantity < 0.10 ||
		salesrecord[i].stockrecord.quantity > 100.00) {
		printf("Invalid quantity - Enter a number between 0.10 and 100.00: ");
		scanf(" %d, %f", &salesrecord[i].stockrecord.product.ID,
			  &salesrecord[i].stockrecord.quantity);
		clearKeyboard();
	}
	
	index = getID(stockrecord, salesrecord[i].stockrecord.product.ID, numStockItems);

	if(stockrecord[index].quantity < salesrecord[i].stockrecord.quantity) {
		salesrecord[i].stockrecord.quantity = stockrecord[index].quantity;
	}
	else {
		salesrecord[i].stockrecord.quantity = salesrecord[i].stockrecord.quantity;
	}
	strcpy(salesrecord[i].stockrecord.item, stockrecord[index].item);
	salesrecord[i].stockrecord.product.price = stockrecord[index].product.price;
	salesrecord[i].stockrecord.product.category = stockrecord[index].product.category;
	stockrecord[index].numsold = salesrecord[i].stockrecord.quantity;
	stockrecord[index].quantity -= salesrecord[i].stockrecord.quantity;
	count++;
	}
	return count;
}

float printSalesReport(struct StockRecord storeStock[],
	  struct SalesRecord salesrecord[], int numsaleitems){
	int i;
	float total = 0.0, taxTotal = 0.0, tax = 0.13;

	printf("\n");
	centreText(70, '*', " Seneca Groceries ");
	printf("\n");
	centreText(70, '=', "");
	printf("\n");
	for (i = 0; i < numsaleitems; i++) {
		printf("%33s %8.2f %7.2f\n", salesrecord[i].stockrecord.item,
		   salesrecord[i].stockrecord.product.price,
	      (salesrecord[i].stockrecord.product.price * salesrecord[i].stockrecord.quantity));
		if (salesrecord[i].stockrecord.product.category == 6 ||
			salesrecord[i].stockrecord.product.category == 7) {
			taxTotal += salesrecord[i].stockrecord.product.price * tax;
		}	
		total += salesrecord[i].stockrecord.product.price * salesrecord[i].stockrecord.quantity;
	}
	printf("Purchase Total %35.2f\n", total);
	printf("Tax %46.2f\n", taxTotal);
	printf("Total %44.2f\n", total+taxTotal);
	printf("Thank you for shopping at Seneca!\n");
	printf("\n");
	return total;
}

void getTopSellers(struct StockRecord stockrecord[],
	 int numstock, struct SalesRecord topsellers[], int num, int cat){
	int i, k = 0;
	struct SalesRecord temp[MAX_ITEMS_IN_SALE] = { 0 };
	for (i = 0; i < numstock; i++) {
		if (stockrecord[i].product.category == cat + 1) {
			if (stockrecord[i].numsold > 0) {
				temp[k].stockrecord.numsold = stockrecord[i].numsold;
				strcpy(temp[k].stockrecord.item, stockrecord[i].item);
				k++;
			}
		}
	}
	sortTopSeller(temp, k + 1);
	for (i = 0; i < num; i++) {
		topsellers[i] = temp[i];
		if (strlen(temp[i].stockrecord.item) == 0) {
			strcpy(topsellers[i].stockrecord.item, "<none>");
			topsellers[i].stockrecord.numsold = 0.00;
		}
	}
}

void printTopSellers(struct StockRecord stockrecord[],
	 struct SalesRecord topsellers[], int num, int cat) {
	int i;
	printTopSellersCat(cat+1);
	printf("\n");
	printf("Rank                       Product    Sales\n");
	for (i = 0; i < num; i++) {
		printf("%4d%30s%9.2f\n", i + 1, topsellers[i].stockrecord.item,
			   topsellers[i].stockrecord.numsold);
	}
	return;
}

void centreText(int num, char symbol, char sentence[]){
	int i;
	int length = strlen(sentence);
	int symLength = (num - length) / 2;

	if (length == 0) {
		for (i = 0; i < num; i++) {
			printf("%c", symbol);
		}
	}
	else if ((num - length) % 2 == 0) {
		for (i = 0; i < symLength; i++) {
			printf("%c", symbol);
		}
		printf("%s", sentence);
		for (i = 0; i < symLength; i++) {
			printf("%c", symbol);
		}
	}
	else {
		for (i = 0; i < symLength; i++) {
			printf("%c", symbol);
		}
		printf("%s", sentence);
		for (i = 0; i <= symLength; i++) {
			printf("%c", symbol);
		}
	}
}

char* getCatName(int catNum){
	char* category = { 0 };
	switch (catNum) {
		case 1:
			category = "Produce";
			break;
		case 2:
			category = "bakery";
			break;
		case 3:
			category = "meat";
			break;
		case 4:
			category = "dairy";
			break;
		case 5:
			category = "baking";
			break;
		case 6:
			category = "house wares";
			break;
		case 7:
			category = "miscellaneous";
			break;
	}
	return category;
}

int getID(struct StockRecord stockrecord[], int ID, int numStockItems) {
	int i, index = -1;
	for (i = 0; i < numStockItems; i++) {
		if (stockrecord[i].product.ID == ID) {
			index = i;
		}
	}
	return index;
}

void sortTopSeller(struct SalesRecord salesrecord[], int num){
	int i, j;
	struct SalesRecord temp;

	for (i = num - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (salesrecord[j].stockrecord.numsold <
				salesrecord[j+1].stockrecord.numsold) {
				temp = salesrecord[j];
				salesrecord[j] = salesrecord[j + 1];
				salesrecord[j + 1] = temp;
			}
		}
	}
}

void printTopSellersCat(int cat) {
	switch (cat) {
	case 1:
		centreText(50, '-', " Top 3 sellers in produce ");
		break;
	case 2:
		centreText(50, '-', " Top 3 sellers in bakery ");
		break;
	case 3:
		centreText(50, '-', " Top 3 sellers in meat ");
		break;
	case 4:
		centreText(50, '-', " Top 3 sellers in dairy ");
		break;
	case 5:
		centreText(50, '-', " Top 3 sellers in baking ");
		break;
	case 6:
		centreText(50, '-', " Top 2 sellers in house wares ");
		break;
	case 7:
		centreText(50, '-', " Top 2 sellers in miscellaneous ");
		break;
	default:
		break;
	}
	return;
}

void clearKeyboard(void){
	while (getchar() != '\n');
}