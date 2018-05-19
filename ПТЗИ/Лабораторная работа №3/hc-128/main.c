#include "ecrypt_h/ecrypt-sync.h"
#include <memory.h>
#include <stdio.h>

ECRYPT_ctx ctx;

int main (int argc, char* argv[])
  {
  u8 K [16], IV [16], in [100], out [100];
  memset (K, 0, 16);
  memset (IV, 0, 16);
  memset (in, 0, 100);
  if (argc > 1) for (int i = 0; argv[1][i]; i++) K[i] = argv[1][i];
  if (argc > 2) for (int i = 0; argv[2][i]; i++) IV[i] = argv[2][i];
  printf ("K = %s  IV = %s\n", K, IV);
  ECRYPT_init ();
  ECRYPT_keysetup (&ctx, K, 128, 128);
  ECRYPT_ivsetup (&ctx, IV);
  ECRYPT_encrypt_bytes (&ctx, in, out, 100);
  for (int i = 0; i < 100; i++) printf ("%0x", out[i]);
  printf ("\n");
  return 0;
  }
