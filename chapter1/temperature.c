#include <stdio.h>
#include <string.h>

float convertFahrenheitToCelsius(float fahr) {
    return (5.0/9.0) * (fahr - 32.0);
}

float convertCelsiusToFahrenheit(float celsius) {
    return (celsius * 1.8) + 32.0;
}

main() {
    return alternativeApproach();

    float fahr, celsius;
    float lower, upper, step;

    char* fahr_string = "Fahrenheit";
    printf("%s Celsius\n", fahr_string);

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        celsius = convertFahrenheitToCelsius(fahr);
        printf(
            "%*.0f %-.1f\n",
            (int)strlen(fahr_string),
            fahr,
            celsius
        );
        fahr += step;
    }

    char* celsius_string = "Celsius";
    printf("%s Fahrenheit\n", celsius_string);

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;
    while (celsius <= upper) {
        fahr = convertCelsiusToFahrenheit(celsius);
        printf(
            "%*.0f %-.1f\n",
            (int)sizeof(celsius_string) - 1,
            celsius,
            fahr
        );
        celsius += step;
    }
}

#define LOWER 0
#define UPPER 300
#define STEP 20

alternativeApproach() {
    int fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
        printf("%3d %6.1f\n", fahr, convertFahrenheitToCelsius(fahr));

    printf("\n");

    /* print in reverse order */
    for (fahr = UPPER; fahr >= LOWER; fahr -= STEP)
        printf("%3d %6.1f\n", fahr, convertFahrenheitToCelsius(fahr));
}
