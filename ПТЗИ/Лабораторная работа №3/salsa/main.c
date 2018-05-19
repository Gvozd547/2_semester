#include "ecrypt_h/ecrypt-sync.h"
#include <memory.h>
#include <stdio.h>

ECRYPT_ctx ctx;

int main(int argc, char const *argv[]) {

  /*
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
  */

  // инициалицация структуры состояния генератора
  ECRYPT_init();
  u8 key[16];
  memset(key, 0, 16);
  printf("Введите секретный ключ: ");
  scanf("%s", key);
  // установка секретного ключа в структуру
  ECRYPT_keysetup(&ctx, key, 128, 128);
  u8 iv[16];
  memset(iv, 0, 16);
  printf("Введите инициализирующий вектор: ");
  scanf("%s", iv);
  // установка секретного ключа в структуру
  ECRYPT_ivsetup(&ctx, iv);
  u8 plaintext[100], ciphertext[100];
  memset(plaintext, 0, 100);
  memset(ciphertext, 0, 100);
  printf("Введите шифруемый текст: ");
  scanf("%s", plaintext);
  // шифрование
  ECRYPT_encrypt_bytes(&ctx, plaintext, ciphertext, 100);
  printf("Зашифрованный текст: ");
  for (int i = 0; i < 100; i++)
    printf("%0x", ciphertext[i]);
  printf("\n");
  // расшифровка
  ECRYPT_encrypt_bytes(&ctx, ciphertext, plaintext, 100);
  printf("Расшифрованный текст: %s\n", plaintext);
  return 0;
}
