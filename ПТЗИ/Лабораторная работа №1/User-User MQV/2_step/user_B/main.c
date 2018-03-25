#include "libraries.h"

int main(int argc, char const *argv[]) {

  // Создание сокета для отправки сообщений пользователю A
  struct sockaddr_in user_addr_b_send;
  user_addr_b_send.sin_family = AF_INET;
  user_addr_b_send.sin_addr.s_addr = htonl(INADDR_ANY);
  user_addr_b_send.sin_port = 0;
  int sock_send;
  if ((sock_send = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    perror("Не получен socket\n");
  if (bind(sock_send, (struct sockaddr *)&user_addr_b_send,
           sizeof(user_addr_b_send)))
    perror("Вызов bind от сервера неудачен\n");
  int addr_lenght_send = sizeof(user_addr_b_send);
  if (getsockname(sock_send, (struct sockaddr *)&user_addr_b_send,
                  (socklen_t *)&addr_lenght_send))
    perror("Вызов getsockname неудачен\n");
  printf("Пользователь B: номер порта для отправки сообщений %i\n",
         ntohs(user_addr_b_send.sin_port));
  // Создание сокета для приема сообщений от пользователя A
  struct sockaddr_in user_addr_b_recv;
  user_addr_b_recv.sin_family = AF_INET;
  user_addr_b_recv.sin_addr.s_addr = htonl(INADDR_ANY);
  user_addr_b_recv.sin_port = 0;
  int sock_recv;
  if ((sock_recv = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    perror("Не получен socket\n");
  if (bind(sock_recv, (struct sockaddr *)&user_addr_b_recv,
           sizeof(user_addr_b_recv)))
    perror("Вызов bind от сервера неудачен\n");
  int addr_lenght_receiv = sizeof(user_addr_b_recv);
  if (getsockname(sock_recv, (struct sockaddr *)&user_addr_b_recv,
                  (socklen_t *)&addr_lenght_receiv))
    perror("Вызов getsockname неудачен\n");
  printf("Пользователь B: номер порта для получения сообщений %i\n",
         ntohs(user_addr_b_recv.sin_port));
  // Ввод IP адреса и порта пользователя A
  char *addres = (char *)malloc(13 * sizeof(char));
  printf("Пользователь B: введите IP адрес пользователя A: ");
  fgets(addres, 13, stdin);
  int user_a_port;
  printf("Пользователь B: введите порт пользователя A: ");
  scanf("%i", &user_a_port);
  struct in_addr user_ip_a;
  inet_aton(addres, &user_ip_a);
  struct sockaddr_in user_addr_a;
  user_addr_a.sin_family = AF_INET;
  user_addr_a.sin_addr.s_addr = user_ip_a.s_addr;
  user_addr_a.sin_port = htons(user_a_port);
  // Считывание данных для пользователя B, полученные на первом шаге
  mpz_t p, g, q, b, A, B;
  mpz_inits(p, g, q, b, A, B, 0);
  FILE *user_b;
  user_b = fopen("user_B_p.txt", "r");
  mpz_inp_str(p, user_b, 16);
  fclose(user_b);
  user_b = fopen("user_B_g.txt", "r");
  mpz_inp_str(g, user_b, 16); // Генератор
  fclose(user_b);
  user_b = fopen("user_B_q.txt", "r");
  mpz_inp_str(q, user_b, 16);
  fclose(user_b);
  user_b = fopen("user_B_b.txt", "r");
  mpz_inp_str(b, user_b, 16); // Секретное число пользователя B
  fclose(user_b);
  user_b = fopen("user_B_A.txt", "r");
  mpz_inp_str(A, user_b, 16); // Открытое число пользователя A
  fclose(user_b);
  user_b = fopen("user_B_B.txt", "r");
  mpz_inp_str(B, user_b, 16); // Открытое число пользователя B
  fclose(user_b);
  // Генерация открыто сеансокого ключа
  mpz_t y, Y;
  gen_y(q, &y);
  gen_Y(p, g, y, &Y);
  // Отправка открытого сеансокого ключа пользователю A
  char send_message[257];
  memset(send_message, 0, sizeof(send_message));
  mpz_get_str(send_message, 16, Y);
  if (sendto(sock_send, send_message, sizeof(send_message), 0,
             (struct sockaddr *)&user_addr_a, sizeof(user_addr_a)) < 0)
    perror("Проблема с sendto.\n");
  // Получение открытого сеансокого ключа от пользователя A
  int msgLength;
  char recv_message[257];
  while (1) {
    if ((msgLength = recvfrom(sock_recv, recv_message, 257, 0, NULL, NULL)) < 0)
      perror("Плохой socket клиента.\n");
    else
      break;
  }
  FILE *convers = fopen("convers.txt", "w");
  fprintf(convers, "%s", recv_message);
  fclose(convers);
  convers = fopen("convers.txt", "r");
  mpz_t X;
  mpz_init(X);
  mpz_inp_str(X, convers, 16);
  // Вычисление числа Sb
  mpz_t e, d, sb;
  gen_d_e(256, X, Y, &d, &e);
  gen_sb(p, X, A, d, e, b, y, q, &sb);
  printf("-----------------------------------------------------------------\n");
  gmp_printf("Пользователь B: ключ Sb %Zx\n", sb);
  printf("-----------------------------------------------------------------\n");
}
