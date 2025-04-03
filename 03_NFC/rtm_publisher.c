#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#include "rt.h"

extern void create_subscriber_thread(uint32_t client_id);

rt_table_t publisher_rt_table;

rt_table_t *publisher_get_rt_table() { return &publisher_rt_table; }

void main_menu()
{
	int choice;
	while(1) {
		printf("Publisher Menu\n");
		printf("1. Add/Update rt table entry\n");
		printf("2. Delete rt table entry\n");
		printf("3. Dump rt table\n");
		printf("Enter Choice :");
		choice = 0;
		scanf("%d", &choice);
		switch(choice) {
			case 1: {
				char dest[16];
				char mask;
				char oif[32];
				char gw[16];
				printf("Enter Destination :");
				scanf("%s", dest);
				printf("Mask : ");
				scanf("%hhd", &mask);
				printf("Enter oif name :");
				scanf("%s", oif);
				printf("Enter Gateway IP :");
				scanf("%s", gw);
                                printf("\n---------------------------\n");
				rt_add_or_update_rt_entry(
				    publisher_get_rt_table(), dest, mask, gw,
				    oif);
				printf("\n---------------------------\n");
			} break;
			case 2:
				bool deleted = false;
				char dest[16];
                                char mask;
				printf("Enter Destination :");
                                scanf("%s", dest);
                                printf("Mask : ");
                                scanf("%hhd", &mask);
				printf("\n---------------------------\n");
				rt_delete_rt_entry(publisher_get_rt_table(), dest, mask);
				printf("\n---------------------------\n");
				break;
			case 3:
				rt_dump_rt_table(publisher_get_rt_table());
				break;
			default:;
		}
	}
}

void *publisher_thread_fn(void *arg)
{
	/* Add some default entries in rt table */
	 printf("\n---------------------------\n");
	rt_add_or_update_rt_entry(publisher_get_rt_table(), "122.1.1.1", 32,
				  "10.1.1.1", "eth1");
	 printf("\n---------------------------\n");
	rt_add_or_update_rt_entry(publisher_get_rt_table(), "122.1.1.2", 32,
				  "10.1.1.2", "eth1");
	 printf("\n---------------------------\n");
	rt_add_or_update_rt_entry(publisher_get_rt_table(), "122.1.1.3", 32,
				  "10.1.1.3", "eth1");
	printf("\n---------------------------\n");
        printf("\n---------DUMP TABLE------------------\n");
	rt_dump_rt_table(publisher_get_rt_table());
	printf("\n-------------------------------------\n");
	main_menu();
}

void create_publisher_thread()
{
	pthread_attr_t attr;
	pthread_t pub_thread;

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	pthread_create(&pub_thread, &attr, publisher_thread_fn, (void *)0);
}

int main(int argc, char **argv)
{
	rt_init_rt_table(&publisher_rt_table);
	/* Create Subscriber threads */
	create_subscriber_thread(1);
	sleep(1);

	create_subscriber_thread(2);
	sleep(1);

	create_subscriber_thread(3);
	sleep(1);
	/* Create publisher thread*/
	printf("-----------------------------------------");
	create_publisher_thread();
	pthread_exit(0);
	return 0;
}
