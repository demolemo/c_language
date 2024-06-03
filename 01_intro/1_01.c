#include <stdio.h>

int main() {
    printf("hello, ");
    printf("world!");
    printf("\n");

    /* comment line in c */
    /* all escape sequences in c */

    printf("\a"); /* bell symbol */
    printf("\b"); /* backspace */
    printf("\f"); /* formfeed */
    printf("\n"); /* newline */
    printf("\r"); /* carirage return */
    printf("\n"); /* newline */
    printf("\t"); /* horizontal tab*/
    printf("\v"); /* vertical tab*/
    printf("\\"); /* backslash */
    printf("\'"); /* single quotation mark */
    printf("\""); /* double quotation mark */
    printf("\?"); /* question mark */
    char str[] = "Hello\0World!"; /* null character */
    printf("The string is: %s\n", str);
}
