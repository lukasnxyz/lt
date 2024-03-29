/* See LICENSE file for copyright and license details.
 *
 * latex template system is designed to make creating new latex
 * projects much easier by using user predefined-templates, placing it
 * into a custom directory and renaming it to what the user has specified
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"

static void helpMessage();
static char *concatenate(const char *, const char *, const char *);
static char *getPath();
static char *createDir();
static void setupDir(char *);

static char *name;
static char *type;

void
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
    fullPath = strcat(fullPath, "/");

    system(fullCommand);
    return fullPath;
}

void
setupDir(char *path) {
    char *template = concatenate(templatesLocation, type, ".tex");
    char *oldPath = concatenate(path, type, ".tex");
    char *newPath = concatenate(path, name, ".tex");
    strcat(template, " ");
    strcat(oldPath, " ");

    system(concatenate("cp ", template, path));
    system(concatenate("mv ", oldPath, newPath));
}

int
main(int argc, char *argv[]) {

    if (argc == 1) {
        helpMessage();
        return 0;
    }

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

    char *path = createDir();
    setupDir(path);
    free(path);
}
