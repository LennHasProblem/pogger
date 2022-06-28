#ifndef LOGGER_H
#define LOGGER_H

struct loggerconf {
    char *filename;
    char *filemode;
};

void logging(struct loggerconf *config, char loglevel, char *message);

#endif // LOGGER_H