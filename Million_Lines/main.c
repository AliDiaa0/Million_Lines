#include "main.h"

FILE* hea; int header;
FILE* fp; int ret;
int i;
char path[1000]; int x; char cmd[1100]; char hpath[1100]; char cpath[1100];

int million_code(int argc, char* argv[]) {
    x = 0;
    while (argv[0][x] != '\0') {
        path[x] = argv[0][x];
        x++;
    }
    path[x] = '\0';

    for (; x >= 0; x--) {
        if (path[x] == '\\') {
            path[x] = '\0';
            break;
        }
    }
    if (x < 0) return 1;

    strcat(path, "\\BUFFERCODEHAHA");

    strcpy(cmd, "mkdir \"");
    strcat(cmd, path);
    strcat(cmd, "\"");
    if (system(cmd)) return 1;

    strcpy(hpath, path);
    strcat(hpath, "\\main.h");

    hea = fopen(hpath, "w");
    if (!hea) return 1;

    fprintf(hea, "#pragma once\n#include <stdio.h>\n\n");
    for (header = 0; header <= 1000000; header++) {
        fprintf(hea, "void haha%d();\n", header);
    }
    fclose(hea);
    
    strcpy(cpath, path);
    strcat(cpath, "\\main.c");

    fp = fopen(cpath, "w");
    if (!fp) return 1;

    fprintf(fp, "#include <stdio.h>\n#include \"main.h\"\n\n");

    i = 1;
    while (i <= 1000000) {
        fprintf(fp, "void haha%d() {}\n", i);
        i++;
    }

    fprintf(fp, "\nint main() {\n    printf(\"Hello, world.\\n\");\n    getchar();\n    return 0;\n}");

    fclose(fp);
    return 0;
}

int main(int argc, char* argv[]) {
    return million_code(argc, argv);
}
