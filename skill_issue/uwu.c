#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    const char *responses[] = {
        "skill issue.",
        "probaste reiniciarlo?",
        "borralo a la mierda.",
        "estas cocido lil bro.",
    };
    int totalResponses = sizeof(responses) / sizeof(responses[0]);
    char input[256];

    printf("EL BOT GALACTICO PHANTOM ULTRA SUPER 44 MAGNUM ULTIMATE MAKANKOSAPPO\n\n");
    while (1) {
        printf("En que ayudo papu\n> ");

        fgets(input, sizeof(input), stdin);
        int randomIndex = rand() % totalResponses;

        printf("\n %s", responses[randomIndex]);
        printf("\n espero haberte ayudado\n\n");
    }

    return 0;
}
