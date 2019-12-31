
#include <unistd.h>

#include "headers.h"

#define CPU_FILE "/proc/stat"

typedef struct cpu_data
{
	char name[20];
	unsigned int user;
	unsigned int nice;
	unsigned int system;
	unsigned int idle;
} CPU_DATA;

void get_cpu(CPU_DATA *data) {
	GLogD("get_CPU enter");
	char buf[256];
	FILE* fd = fopen(CPU_FILE, "r");
	fgets(buf, sizeof(buf), fd);
	GLogD("get_CPU buf:%s", buf);
	sscanf(buf, "%s %u %u %u %u", data->name, &data->user, &data->nice, 
		&data->system, &data->idle);
}

int cal_cpu(CPU_DATA *data_old, CPU_DATA *data_new) {
	unsigned long ot, nt;
	unsigned long ut, st;
	float used;

	GLogD("cal_cpu old:%s %u %u %u %u\n new:%s %u %u %u %u", 
		data_old->name, &data_old->user, &data_old->nice, &data_old->system, &data_old->idle,
		data_new->name, &data_new->user, &data_new->nice, &data_new->system, &data_new->idle);

	ot = (unsigned long) (data_old->user + data_old->nice + data_old->system + data_old->idle);
	nt = (unsigned long) (data_new->user + data_new->nice + data_new->system + data_new->idle);

	ut = (unsigned long) (data_new->user - data_old->user);
	st = (unsigned long) (data_new->system - data_new->system);

	GLogD("nt = %u, ot = %u, nt - ot = %u", nt, ot, nt - ot);
	if ((nt - ot ) != 0 ) {
		GLogD("ut = %u, st = %u, ut + st = %u", ut, st, ut + st);
		used = (int)((ut + st) * 100 / (nt - ot));	
	} else {
		used = 0;
	}
	return used;
}

int cpu_main(char **token, int len) {
	GLogD("cpu main enter");

	CPU_DATA cpu_data_old, cpu_data_new;

	get_cpu(&cpu_data_old);

	sleep(10);
	get_cpu(&cpu_data_new);

	printf("%f\n", cal_cpu(&cpu_data_old, &cpu_data_new));

	return 0;
}