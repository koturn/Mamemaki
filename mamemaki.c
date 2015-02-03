/*!
 * @file mamemaki.c
 * @brief Mamemaki as Monte Carlo method: "Oni ha soto, Fuku ha uchi".
 * @author koturn
 * @date 2015-02-03
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#if defined(__cplusplus) && __cplusplus >= 201103L
#  include <cstdint>
#elif (defined(_MSC_VER) && _MSC_VER >= 1600) || \
      (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L)
#  include <stdint.h>
#else
#  ifndef UINT32_T
#    define UINT32_T  unsigned int
#  endif
typedef UINT32_T uint32_t;
#endif
#define XOR128_MAX  0xffffffffU


static void
xor128_seed(unsigned int s);

static uint32_t
xor128(void);


#define SQUARE(x)  ((x) * (x))
#define N_TRIAL    100000000
#define TOLERANCE  0.00025
#ifndef M_PI
#  define M_PI  acos(-1)
#endif


static uint32_t seed128[4];




/*!
 * @brief Entry point of this program
 * @return Exit-status
 */
int
main(void)
{
  size_t i;
  unsigned int n_hit = 0;
  double x, y, pi;

  xor128_seed((uint32_t) time(NULL));
  for (i = 0; i < N_TRIAL; i++) {
    x = xor128() / (XOR128_MAX + 1.0);
    y = xor128() / (XOR128_MAX + 1.0);
    if (SQUARE(x) + SQUARE(y) < 1.0) {
      n_hit++;
    }
  }
  pi = n_hit * 4.0 / N_TRIAL;
  printf("Calculated PI = %f\n", pi);
  if (fabs(pi - M_PI) < TOLERANCE) {
    printf("鬼を追い払うことができました\n");
  } else {
    printf("鬼を追い払うことができませんでした...\n");
  }
  return EXIT_SUCCESS;
}


/*!
 * @brief Set random seed for xor128
 * @param [in] s  Value for random seed
 */
static void
xor128_seed(uint32_t s)
{
  uint32_t i;
  for (i = 1; i <= 4; i++) {
    seed128[i - 1] = s = 1812433253U * (s ^ (s >> 30)) + i;
  }
}


/*!
 * @brief Generate a random number with Xorshift
 * @return Random number
 */
static uint32_t
xor128(void)
{
  uint32_t t = (seed128[0] ^ (seed128[0] << 11));
  seed128[0] = seed128[1];
  seed128[1] = seed128[2];
  seed128[2] = seed128[3];
  return seed128[3] = (seed128[3] ^ (seed128[3] >> 19)) ^ (t ^ (t >> 8));
}
