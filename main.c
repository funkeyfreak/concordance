#include <stdio.h>

#include "fileHelper.h"

int main(int argc, char **argv) {
    fileH file = newFileHelper(argv[1]);
    concordance(file);
    freeFileHelper(file);
    return 0;
}

