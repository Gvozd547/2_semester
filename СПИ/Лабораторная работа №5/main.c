#include "libraries.h"

int main() {

  srand(time(NULL));
  int count;
  printf("Введите время работы(число циклов): ");
  scanf("%i", &count);
  int t_between_req = 0; // время между заявками
  //Переменные для СМО с 1 узлом
  int t_service_1node = 0; // время обслуживания заявки
  int sum_1node = 0;       // число обработанных заявок
  int queue_1node = 0;     // длина очереди
  //Переменные для СМО с 3 узломи
  int t_service_3node[3] = {0, 0, 0};
  int sum_3node = 0;
  int queue_3node = 0;

  for (size_t k = 0; k < count; k++) {

    // Генерация времени между заявками
    if (t_between_req == 0) {
      queue_1node++;
      queue_3node++;
      double rand_num = (rand() % 9 + 1) / 10.0;
      t_between_req = (int)(-log(1 - rand_num) * 10);
    } else
      t_between_req--;

    // Для СМО с 1 узлом
    // Загрузка новой заявки в узел и генерация времени обработки
    if ((t_service_1node == 0) && (queue_1node > 0)) {
      queue_1node--;
      sum_1node++;
      double rand_num = (rand() % 9 + 1) / 10.0;
      t_service_1node = (int)((-log(1 - rand_num) / 0.6) * 10);
    }
    // Уменьшение времени для узла
    if (t_service_1node > 0) {
      t_service_1node--;
    }

    // Для СМО с 3 узломи
    // Загрузка новой заявки в узел и генерация времени обработки
    for (size_t i = 0; i < 3; i++) {
      if (queue_3node == 0)
        break;
      if (t_service_3node[i] == 0) {
        queue_3node--;
        sum_3node++;
        double rand_num = (rand() % 9 + 1) / 10.0;
        t_service_3node[i] = (int)((-log(1 - rand_num) / 0.2) * 10);
      }
    }
    // Уменьшение времени для узлов
    for (size_t i = 0; i < 3; i++) {
      if (t_service_3node[i] > 0) {
        t_service_3node[i]--;
      }
    }
  }

  printf("------------------------------------------------------------\n");
  printf("Очередь для СМО с 1 узлом : %i\n", queue_1node);
  printf("Число обслуженных заявок для СМО с 1 узлом: %i\n", sum_1node);
  printf("------------------------------------------------------------\n");
  printf("Очередь для СМО с 3 узломи : %i\n", queue_3node);
  printf("Число обслуженных заявок для СМО с 3 узломи: %i\n", sum_3node);
  printf("------------------------------------------------------------\n");
  return 0;
}
