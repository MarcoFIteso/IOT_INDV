#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>


int main(int argc, char * argv[]) {
    FILE * urand = NULL;
    FILE * led = NULL;
    unsigned char byte;
    char * led_path = "/sys/class/leds/gpio-led/brightness";

    urand = fopen("/dev/urandom", "rb");
    if (!urand) {
        printf("Error: fopen /dev/urandom");
        return -1;
    }

    while (1) {
        size_t r = fread(&byte, 1, 1, urand);

        led = fopen(led_path, "w");
        if (!led) {
            printf("No se pudo abrir %s\n", led_path);
            break;
        }
        if (byte > 128) {
            if (fputs("1\n", led) == EOF) {
                printf("Error: fputs");
                fclose(led);
                break;
            }
        } else {
            if (fputs("0\n", led) == EOF) {
                printf("Error: fputs");
                fclose(led);
                break;
            }
        }
        fflush(led);
        fclose(led);
        // esperar 1 segundo
        sleep(1);
    }
}
