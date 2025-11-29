#ifndef RNG_H
#define RNG_H

#include <stdint.h>

// Estructura de un generador PCG independiente
typedef struct {
  uint64_t state;
  uint64_t inc;
} RNG;

// Inicializa el generador con semilla y secuencia
void rng_seed(RNG *rng, uint64_t seed, uint64_t seq);

// Devuelve un número aleatorio de 32 bits
uint32_t rng_next_u32(RNG *rng);

// Devuelve un número entero en el rango [min, max]
int rng_range(RNG *rng, int min, int max);

// Devuelve un flotante en el rango [0, 1)
float rng_float01(RNG *rng);

// Devuelve un flotante en un rango arbitrario
float rng_float(RNG *rng, float min, float max);

// Devuelve true o false (50/50)
int rng_bool(RNG *rng);

#endif
