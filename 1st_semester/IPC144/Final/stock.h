#define NUM_CATS 7
#define MAX_ITEMS_IN_SALE 100

struct Product
{
	int ID;
	int category;
	float price;
	int byWeight;
};

struct StockRecord
{
	struct Product product;
	char item[31];
	float quantity;
	float numsold; 
};

struct SalesRecord
{
	struct StockRecord stockrecord;
};

int readStockItems(struct StockRecord stockrecord[], int max, int STOCK_FROM_STDIN);
void centreText(int num, char symbol, char sentence[]);
void printStockReport(struct StockRecord storestock[], int numstockitems);
int readSale(struct StockRecord storeStock[], int numStockItems, struct SalesRecord salesrecord[]);
float printSalesReport(struct StockRecord storeStock[], struct SalesRecord salesrecord[], int numsaleitems);
void getTopSellers(struct StockRecord storestock[], int numstock, struct salesrecord topsellers[], int num, int cat);
void printTopSellers(struct StockRecord storestock[], struct salesrecord topsellers[], int num, int cat);
char* getCatName(int catNum);
int getID(struct StockRecord stockrecord[], int ID, int numStockItems);
void sortTopSeller(struct SalesRecord salesrecord[], int num);
void printTopSellersCat(int cat);
void clearKeyboard(void);