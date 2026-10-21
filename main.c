#include <stdio.h>
#include <stdbool.h>
#define NUM_RODAS 4

typedef struct {
    char nome[30];
    float velocidade;
    bool sinalValido;
} SensorABS;

bool verificarSensor(SensorABS sensor) {
    if (!sensor.sinalValido) {
        return false;
    }

    if (sensor.velocidade < 0 ||
        sensor.velocidade > 300) {
        return false;
    }

    return true;
}

void diagnosticarSensor(SensorABS sensor) {
    printf("\nSensor: %s\n", sensor.nome);

    if (!verificarSensor(sensor)) {
        printf("Resultado: sinal invalido!\n");
        printf("Verificar sensor, chicote e conexoes.\n");
    } else {
        printf("Velocidade: %.1f km/h\n",
               sensor.velocidade);
        printf("Sinal dentro dos limites definidos.\n");
    }
}

int main(void) {
    SensorABS rodas[NUM_RODAS] = {
        {"Dianteira esquerda", 80.0, true},
        {"Dianteira direita", 79.0, true},
        {"Traseira esquerda", 0.0, false},
        {"Traseira direita", 81.0, true}
    };

    printf("=== DIAGNOSTICO ABS ===\n");

    for (int i = 0; i < NUM_RODAS; i++) {
        diagnosticarSensor(rodas[i]);
    }

    printf("\n=== FIM DO DIAGNOSTICO ===\n");

    return 0;
}
