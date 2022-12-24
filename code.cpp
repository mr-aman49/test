#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NEWSPAPERS 5

typedef struct {
char *name;
double price[7];
} Newspaper;

typedef struct {
Newspaper *newspapers[MAX_NEWSPAPERS];
int count;
} NewspaperList;

NewspaperList *init_newspaper_list() {
NewspaperList *list = (NewspaperList *)malloc(sizeof(NewspaperList));
list->count = 0;
return list;
}

void add_newspaper(NewspaperList *list, Newspaper *newspaper) {
if (list->count == MAX_NEWSPAPERS) {
printf("Error: cannot add more newspapers to list.\n");
return;
}

list->newspapers[list->count] = newspaper;
list->count++;
}

typedef struct {
Newspaper *newspaper;
int days[7];
double cost;
} Subscription;

Subscription *init_subscription(Newspaper *newspaper) {
Subscription *sub = (Subscription *)malloc(sizeof(Subscription));
sub->newspaper = newspaper;
memset(sub->days, 0, 7 * sizeof(int));
sub->cost = 0.0;
return sub;
}

void add_day(Subscription *sub, int day) {
if (day < 0 || day > 6) {
printf("Error: invalid day %d\n", day);
return;
}

sub->days[day] = 1;
sub->cost += sub->newspaper->price[day];
}

typedef struct {
Subscription *subscriptions[MAX_NEWSPAPERS];
int count;
double cost;
} SubscriptionList;

SubscriptionList *init_subscription_list() {
SubscriptionList *list = (SubscriptionList *)malloc(sizeof(SubscriptionList));
list->count = 0;
list->cost = 0.0;
return list;
}

void add_subscription(SubscriptionList *list, Subscription *sub) {
if (list->count == MAX_NEWSPAPERS) {
printf("Error: cannot add more subscriptions to list.\n");
return;
}

list->subscriptions[list->count] = sub;
list->count++;
list->cost += sub->cost;
}

void print_subscription_list(SubscriptionList *list) {
for (int i = 0; i < list->count; i++) {
Subscription *sub = list->subscriptions[i];
printf("%s: ", sub->newspaper->name);
for (int j = 0; j < 7; j++) {
if (sub->days[j]) {
printf("%d ", j);
}
}
printf("(%.2lf)\n", sub->cost);
}
printf("Total cost: %.2lf\n", list->cost);
}