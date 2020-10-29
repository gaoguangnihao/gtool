

#include "headers.h"

static void usage();

void help(char **token, int len)
{
	GLogD("help enter");
	usage();
}

static struct 
{
	char* cmd;
	void (*cmdFunc) (char **token, int len);
	char* msg;
} gtoolCmd[] = {
	{"prop", prop_main, "set and get system prop."},
	{"help", help, "this cmd is for help"},
	{"thread", thread_main, "test thread"},
	{"cpu", cpu_main, "cpu used info"},
	{"daemon", daemon_main, "daemon"},
	{"binderclient", binder_main, "binderclient"},
	{"draw",gralloc_main, "gralloc test"},
	{"test",do_main, "test"},
	{"quit", NULL, "quit program"},
	{NULL, NULL, NULL}
};

static void usage() {
	int i;
	printf("gtool make by guang.gao@tcl.com for mobile device. version %s\n", VERSION);
	printf("Usage:\n"
                "\t\t\t<command> <opts..>\n");
	for (i = 0; gtoolCmd[i].cmd; i ++) {
		printf("%-10s\t%-8s\n", gtoolCmd[i].cmd, gtoolCmd[i].msg);
	}
}

int main(int argc, char const *argv[])
{
	char cmd[255];
	char bufTemp[255] = {'\0'};
	char *buf = NULL;
	char* token[10] = {0};
	char *delim = " ";
	char *saveptr1;
	char *quit_func = "quit";
	int match = 0;
	int paramLen = 0;

	usage();

	while(1) {
		paramLen = 0;
		memset(bufTemp, '\0', sizeof(bufTemp));
		printf("\n>");
		fgets(cmd, 255, stdin);
		GLogD("cmd:%s.", cmd);
		strncpy(bufTemp, cmd, strlen(cmd) - 1); // remove \n at end of cmd
		GLogD("bufTemp:%s. len:%d", bufTemp, strlen(bufTemp));
		if (!bufTemp[0]) {  /// input is null
			usage();
			return 0;
		}
		buf = bufTemp;
		GLogD("buf:%s.", buf);
		
		while ((token[paramLen] = strtok_r(buf, delim, &saveptr1)) != NULL) {
			GLogD("buf = %s, token[%d] = %s, saveptr1 = %s \n", buf, paramLen, token[paramLen], saveptr1);
			paramLen ++;
			buf = NULL;
		}

		if (!strncmp(token[0], quit_func, 5)) {
			break;
		}

		int i;
		for (i = 0; gtoolCmd[i].cmd; i ++) {
			if (!strncmp(token[0], gtoolCmd[i].cmd, strlen(gtoolCmd[i].cmd))) {
				GLogD("run cmd:%s  len:%d\n", token[0], paramLen);
				gtoolCmd[i].cmdFunc(token, paramLen);
				match = 1;
			}
		}

		if (!match) {
			usage();
		}
	}
	return 0;
}