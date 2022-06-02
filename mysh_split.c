/* mysh splitting line source file
 * Copyright (C) 2022 Erdem Ersoy (eersoy93)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** mysh_split(char * line) {
    int tokbuffsize = 64;
    int position = 0;

    char ** tokens = malloc(tokbuffsize * sizeof(char *));
    char * tokendl = "\r\t\n\a ";
    char * token = NULL;

    if (!tokens) {
        fprintf(stderr, "mysh token buffer allocation error!\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, tokendl);
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= tokbuffsize) {
            tokbuffsize += tokbuffsize;
            tokens = realloc(tokens, tokbuffsize * sizeof(char *));
            if (!tokens) {
                fprintf(stderr, "mysh token buffer allocation error!\n");
                exit(EXIT_FAILURE);
            }
        }
        
        token = strtok(NULL, tokendl);
    }
    tokens[position] = NULL;
    return tokens;
}

