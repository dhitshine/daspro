#include <stdio.h>

typedef struct {
	int day;
	int month;
	int year;
} date;

typedef struct {
	char type;
	date packaging;
	date expiration;
} meats;

typedef struct {
	char type;
	date received;
} produce;

typedef struct {
	date expiration;
} dairy;

typedef struct {
	date expiration;
	int aisle;
	char side;
} canned;

typedef struct {
	char category;
	int aisle;
	char side;
} nonfoods;

typedef struct {
	char name[21];
	int cost;
	char category;
	union {
		meats m;
		produce p;
		dairy d;
		canned c;
		nonfoods n;
	} detail;

} Product;

void scan_meat(meats *meat){
	scanf(" %c", &meat->type);
	scanf("%d %d %d", &meat->packaging.day, &meat->packaging.month, &meat->packaging.year);
	scanf("%d %d %d", &meat->expiration.day, &meat->expiration.month, &meat->expiration.year);
}

void scan_produce(produce *prod){
	scanf(" %c", &prod->type);
	scanf("%d %d %d", &prod->received.day, &prod->received.month, &prod->received.year);
}

void scan_dairy(dairy *dr){
	scanf("%d %d %d", &dr->expiration.day, &dr->expiration.month, &dr->expiration.year);
}

void scan_canned(canned *can){
	scanf("%d %d", &can->expiration.month, &can->expiration.year);
	scanf("%d %c", &can->aisle, &can->side);
}

void scan_nonfoods(nonfoods *nf){
	scanf(" %c", &nf->category);
	scanf("%d %c", &nf->aisle, &nf->side);
}

void scan_product(Product *product){
	scanf("%s %d %c", product->name, &product->cost, &product->category);
	switch(product->category){
		case 'M':
			scan_meat(&product->detail.m);
			break;
		case 'P':
			scan_produce(&product->detail.p);
			break;
		case 'D':
			scan_dairy(&product->detail.d);
			break;
		case 'C':
			scan_canned(&product->detail.c);
			break;
		case 'N':
			scan_nonfoods(&product->detail.n);
			break;
		default:
			break;
	}
}

void print_product(Product *product){
	printf("\nProduct name    : %s\n", product->name);
	printf("Cost            : %d (cents)\n", product->cost);
	printf("Category        : %c\n", product->category);
	switch(product->category){
		case 'M':
			printf("Meat type       : %c\n", product->detail.m.type);
			printf("Packaging date  : %d %d %d (dd mm yy)\n", product->detail.m.packaging.day, product->detail.m.packaging.month, product->detail.m.packaging.year);
			printf("Expiration date : %d %d %d (dd mm yy)\n", product->detail.m.expiration.day, product->detail.m.expiration.month, product->detail.m.expiration.year);
			break;
		case 'P':
			printf("Produce type    : %c\n", product->detail.p.type);
			printf("Received date   : %d %d %d (dd mm yy)\n", product->detail.p.received.day, product->detail.p.received.month, product->detail.p.received.year);
			break;
		case 'D':
			printf("Expiration date : %d %d %d (dd mm yy)\n", product->detail.d.expiration.day, product->detail.d.expiration.month, product->detail.d.expiration.year);
			break;
		case 'C':
			printf("Expiration date : %d %d (mm yy)\n", product->detail.c.expiration.month, product->detail.c.expiration.year);
			printf("Aisle Side      : %d%c\n", product->detail.c.aisle, product->detail.c.side);
			break;
		case 'N':
			printf("Nonfood type    : %c\n", product->detail.n.category);
			printf("Aisle           : %d%c\n", product->detail.n.aisle, product->detail.n.side);
			break;
	}
}

int main(){
	Product product;
	scan_product(&product);
	print_product(&product);
}

