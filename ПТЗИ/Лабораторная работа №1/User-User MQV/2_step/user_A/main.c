#include "libraries.h"

int main(int argc, char const *argv[]) {

  // Создание сокета для отправки сообщений пользователю B
  struct sockaddr_in user_addr_a_send;
  user_addr_a_send.sin_family = AF_INET;
  user_addr_a_send.sin_addr.s_addr = htonl(INADDR_ANY);
  user_addr_a_send.sin_port = 0;
  int sock_send;
  if ((sock_send = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    perror("Не получен socket\n");
  if (bind(sock_send, (struct sockaddr *)&user_addr_a_send,
           sizeof(user_addr_a_send)))
    perror("Вызов bind от сервера неудачен\n");
  int addr_lenght_send = sizeof(user_addr_a_send);
  if (getsockname(sock_send, (struct sockaddr *)&user_addr_a_send,
                  (socklen_t *)&addr_lenght_send))
    perror("Вызов getsockname неудачен\n");
  printf("Пользователь A: номер порта для отправки сообщений %i\n",
         ntohs(user_addr_a_send.sin_port));
  // Создание сокета для приема сообщений от пользователя B
  struct sockaddr_in user_addr_a_recv;
  user_addr_a_recv.sin_family = AF_INET;
  user_addr_a_recv.sin_addr.s_addr = htonl(INADDR_ANY);
  user_addr_a_recv.sin_port = 0;
  int sock_recv;
  if ((sock_recv = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    perror("Не получен socket\n");
  if (bind(sock_recv, (struct sockaddr *)&user_addr_a_recv,
           sizeof(user_addr_a_recv)))
    perror("Вызов bind от сервера неудачен\n");
  int addr_lenght_receiv = sizeof(user_addr_a_recv);
  if (getsockname(sock_recv, (struct sockaddr *)&user_addr_a_recv,
                  (socklen_t *)&addr_lenght_receiv))
    perror("Вызов getsockname неудачен\n");
  printf("Пользователь A: номер порта для получения сообщений %i\n",
         ntohs(user_addr_a_recv.sin_port));
  // Ввод IP адреса и порта пользователя B
  char *addres = (char *)malloc(13 * sizeof(char));
  printf("Пользователь A: введите IP адрес пользователя B: ");
  fgets(addres, 13, stdin);
  int user_b_port;
  printf("Пользователь A: введите порт пользователя B: ");
  scanf("%i", &user_b_port);
  struct in_addr user_ip_b;
  inet_aton(addres, &user_ip_b);
  struct sockaddr_in user_addr_b;
  user_addr_b.sin_family = AF_INET;
  user_addr_b.sin_addr.s_addr = user_ip_b.s_addr;
  user_addr_b.sin_port = htons(user_b_port);
  // Считывание данных для пользователя A, полученные на первом шаге
  mpz_t p, g, q, a, A, B;
  mpz_inits(p, g, q, a, A, B, 0);
  FILE *user_a;
  user_a = fopen("user_A_p.txt", "r");
  mpz_inp_str(p, user_a, 16);
  fclose(user_a);
  user_a = fopen("user_A_g.txt", "r");
  mpz_inp_str(g, user_a, 16); // Генератор
  fclose(user_a);
  user_a = fopen("user_A_q.txt", "r");
  mpz_inp_str(q, user_a, 16);
  fclose(user_a);
  user_a = fopen("user_A_a.txt", "r");
  mpz_inp_str(a, user_a, 16); // Секретное число пользователя A
  fclose(user_a);
  user_a = fopen("user_A_A.txt", "r");
  mpz_inp_str(A, user_a, 16); // Открытое число пользователя A
  fclose(user_a);
  user_a = fopen("user_A_B.txt", "r");
  mpz_inp_str(B, user_a, 16); // Открытое число пользователя B
  fclose(user_a);
  // Генерация открыто сеансокого ключа
  mpz_t x, X;
  gen_x(q, &x);
  gen_X(p, g, x, &X);
  // Получение открытого сеансокого ключа от пользователя B
  int msgLength;
  char recv_message[257];
  while (1) {
    if ((msgLength = recvfrom(sock_recv, recv_message, 256, 0, NULL, NULL)) < 0)
      perror("Плохой socket клиента.\n");
    else
      break;
  }
  FILE *convers = fopen("convers.txt", "w");
  fprintf(convers, "%s", recv_message);
  fclose(convers);
  convers = fopen("convers.txt", "r");
  mpz_t Y;
  mpz_init(Y);
  mpz_inp_str(Y, convers, 16);
  // Отправка открытого сеансокого ключа пользователю B
  char send_message[257];
  memset(send_message, 0, sizeof(send_message));
  mpz_get_str(send_message, 16, X);
  if (sendto(sock_send, send_message, 257, 0, (struct sockaddr *)&user_addr_b,
             sizeof(user_addr_b)) < 0)
    perror("Проблема с sendto.\n");
  // Вычисление числа Sa
  mpz_t e, d, sa;
  gen_d_e(256, X, Y, &d, &e);
  gen_sa(p, Y, B, e, d, a, x, q, &sa);
  printf("-----------------------------------------------------------------\n");
  gmp_printf("Пользователь A: ключ Sa %Zx\n", sa);
  printf("-----------------------------------------------------------------\n");
}
