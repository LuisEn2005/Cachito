#include "RNG.h"

static inline uint32_t pcg_output(uint64_t state) {
  uint32_t xorshifted = ((state >> 18u) ^ state) >> 27u;
  uint32_t rot = state >> 59u;
  return (xorshifted >> rot) | (xorshifted << ((-rot) & 31));
}

void rng_seed(RNG *rng, uint64_t seed, uint64_t seq) {
  rng->state = 0u;
  rng->inc = (seq << 1u) | 1u;
  rng_next_u32(rng);
  rng->state += seed;
  rng_next_u32(rng);
}

uint32_t rng_next_u32(RNG *rng) {
  uint64_t oldstate = rng->state;
  rng->state = oldstate * 6364136223846793005ULL + (rng->inc | 1u);
  return pcg_output(oldstate);
}

int rng_range(RNG *rng, int min, int max) {
  uint32_t r = rng_next_u32(rng);
  return (r % (max - min + 1)) + min;
}

float rng_float01(RNG *rng) {
  return (rng_next_u32(rng) >> 8) * (1.0f / 16777216.0f);
}

float rng_float(RNG *rng, float min, float max) {
  return rng_float01(rng) * (max - min) + min;
}

int rng_bool(RNG *rng) {
  return rng_next_u32(rng) & 1;
}
