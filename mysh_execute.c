/* mysh launching process source file
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
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int mysh_execute(char ** args) {
    pid_t pid = 0;
    int status = 0;

    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("mysh");
        }
        exit(EXIT_FAILURE);
    }
    else if (pid < 0) {
        perror("mysh");
    }
    else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!(WIFEXITED(status)) && !(WIFSIGNALED(status)));
    }

    return 1;
}

