#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"

static char helpMessage();
static char *concatenate();
static char *getPath();
static char *createDir();
static void setupDir();

char
helpMessage() {
    fprintf(stderr, "latex template system\n");
    fprintf(stderr, "options:\n");
    fprintf(stderr, "\t-t  type of template\n");
    fprintf(stderr, "\t-n  name of project\n");
}

char
*concatenate(const char *a, const char *b, const char *c) {
    size_t alen = strlen(a);
    size_t blen = strlen(b);
    size_t clen = strlen(c);
    char *res = malloc(alen + blen + clen + 1);
    if (res) {
        memcpy(res, a, alen);
        memcpy(res + alen, b, blen);
        memcpy(res + alen + blen, c, clen + 1);
    }

    return res;
}

char
*getPath() {
    FILE *fp;
    int size = 1025;
    char *path = malloc(size);

    fp = popen("pwd", "r");
    if (fp == NULL) {
        fprintf(stderr, "commnad <pwd> not installed to system\n");
        exit(1);
    }

    fgets(path, size, fp);
    path[strcspn(path, "\n")] = 0;
    path = strcat(path, "/");

    return path;
}

char
*createDir() {
    char *command = "mkdir ";
    char *fullCommand = concatenate(command, getPath(), name);
    char *path = getPath();
    char *fullPath = strcat(path, name);

    system(fullCommand);
    return fullPath;
}

void
setupDir(char *path) {
    char *templateLocation = concatenate(templateLocation/*foreward slash*/, type, ".tex");
}

int
main(int argc, char *argv[]) {

    /*
     * args
     *  - "-n" for name of project
     *  - "-t" for type of template
     *  - "-h" for help message
     */
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-t") == 0) {
            i++;
            type = argv[i];
        } else if (strcmp(argv[i], "-n") == 0) {
            i++;
            name = argv[i];
        } else if (strcmp(argv[i], "-h") == 0) {
            helpMessage();
            return 0;
        }
    }

    printf("Name: %s\nType: %s\n", name, type);

    char *path = createDir();
    printf("%s\n", path);
    setupDir(path);
}
