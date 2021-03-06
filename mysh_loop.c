/* mysh loop main source file
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

#include "mysh_execute.h"
#include "mysh_readline.h"
#include "mysh_split.h"

#include <stdio.h>

void mysh_loop(void) {
    char * line;
    char ** args;
    int status = 0;

    do {
        printf("%s", "> ");
        line = mysh_readline();
        args = mysh_split(line);
        status = mysh_execute(args);
    }while(status);
}

