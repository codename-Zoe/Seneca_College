#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stock.h"

#define MAX_STOCK_ENTRIES 100
#define STOCK_FROM_STDIN 1

int main(void){
    struct StockRecord storeStock[MAX_STOCK_ENTRIES] = { {{0, 0, 0.0, 0}, 0, 0.0} };
    struct SalesRecord saleItems[MAX_ITEMS_IN_SALE];
    struct SalesRecord topSellers[5];

    int  numStockItems = 0, numSales = 0, numSaleItems, totalSaleItems = 0, cat;
    double sale, totalSales = 0.0;

    // Read existing stock from stdin
    printf("Enter current stock in format amount, category, price, byWeight, name (0 amount to end):\n");

    numStockItems = readStockItems(storeStock, MAX_STOCK_ENTRIES, STOCK_FROM_STDIN); //how many items in stock

    printf("\n");
    centreText(70, '*', " Seneca Groceries - Opening Stock ");
    printf("\n");
    centreText(70, '=', "");
    printf("\n");
    printStockReport(storeStock, numStockItems);
    printf("\n");
    centreText(70, '*', " Now in Sales Mode ");
    printf("\n");
    centreText(70, '=', "");
    printf("\n");

    do
    {
        numSaleItems = readSale(storeStock, numStockItems, saleItems);
        if (numSaleItems > 0)
        {
            sale = printSalesReport(storeStock, saleItems, numSaleItems);
            totalSales += sale;
            totalSaleItems += numSaleItems;
            numSales++;
        }
    } while (numSaleItems > 0);

    printf("\n");
    centreText(70, '*', " End of Day Summary ");
    printf("\n");
    centreText(70, '=', "");
    printf("\n");
    printf("%35s%8.2lf\n", "Cost of items sold before taxes", totalSales);
    printf("%35s%8d\n", "Number of Sales", numSales);
    printf("%35s%8.2lf\n\n", "Average items per sale", totalSaleItems / (double)numSales);

    printf("\n");
    centreText(70, '*', " Closing Stock ");
    printf("\n");
    centreText(70, '=', "");
    printf("\n");
    printStockReport(storeStock, numStockItems);
    printf("\n");

    for (cat = 0; cat < 5; cat++)
    {
        getTopSellers(storeStock, numStockItems, topSellers, 3, cat);
        printTopSellers(storeStock, topSellers, 3, cat);
    }
    for (cat = 5; cat < NUM_CATS; cat++)
    {
        getTopSellers(storeStock, numStockItems, topSellers, 2, cat);
        printTopSellers(storeStock, topSellers, 2, cat);
    }
    return 0;
}