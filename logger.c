#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "logger.h"

void logging(struct loggerconf *config, char loglevel, char *message)
{
    FILE *fp = fopen(config -> filename, config -> filemode);

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    char *logstr = NULL;

    switch (loglevel) {
        case 'd':
            logstr = "DEBUG";
            break;
        case 'i':
            logstr = "INFO";
            break;
        case 'w':
            logstr = "WARNING";
            break;
        case 'e':
            logstr = "ERROR";
            break;
        case 'c':
            logstr = "CRITICAL";
            break;
        default:
            exit(-1);
    }

    fprintf(fp, "(%d-%02d-%02d %02d:%02d:%02d) [%s] %s", \
                                    tm.tm_year + 1900, tm.tm_mon + 1,  \
                                    tm.tm_mday, tm.tm_hour, tm.tm_min, \
                                    tm.tm_sec, logstr, message);

    fclose(fp);
}