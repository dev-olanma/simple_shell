#include "pod.h"

int main(void)
{
    char buffer[1024];
    write(STDOUT_FILENO, "Enter a line of text: ", 22);
    fgets(buffer, 1024, stdin);
    write(STDOUT_FILENO, "You entered: ", 13);
    write(STDOUT_FILENO, buffer, strlen(buffer));
    return 0;
}
