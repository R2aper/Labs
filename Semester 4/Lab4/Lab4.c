/*
!Требуется написать программу на языке С++.
*    Данные считываются из входного файла input.txt
*    Результат выводится в выходной файл output.txt
!Необходимо
*    составить  хеш-таблицу, содержащую буквы и количество их вхождений в считанном тексте
*    реализовать функции добавления, удаления и поиска элементов в хеш-таблице.
*    в программе:
*        считать входной файл input.txt, содержащий текст на английском языке.
*        вывести полученную таблицу в файл output.txt.
*        сделать поиск введенной  с клавиатуры буквы в хеш-таблице и вывести значение на экран.

*/

#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 26
#define HASH_CODE 5381
#define QUADRATIC_PROBING(index, attempt) ((index + attempt * attempt) % TABLE_SIZE)

// Пара, состоящая из символа и его частоты
typedef struct pair {
  char key;
  size_t val;
} pair;

// Хэш-таблица, массив пар и его размер. Открытая адресация с квадратичным пробированием
typedef struct hash_table {
  pair *table;
  size_t size;
} hash_table;

// Освободить после использования
char *to_string(char key) {
  char *str = malloc(2 * sizeof(char));
  str[0] = key;
  str[1] = '\0';
  return str;
}

// Хэш-функция, алгоритм djb2
size_t hash(const char *str) {
  size_t hash = HASH_CODE;
  int c;

  while ((c = *str++)) {
    hash = ((hash << 5) + hash) + c; // hash * 33 + c
  }

  return hash;
}

// Возращает указатель на хэш-таблицу, который должен быть освобожден после использования
hash_table *hash_init(unsigned int size) {
  hash_table *ht = malloc(sizeof(hash_table));
  ht->table = calloc(size * sizeof(pair), sizeof(pair));
  for (int i = 0; i < size; i++)
    ht->table[i].key = '\0';

  ht->size = size;

  return ht;
}

void hash_table_free(hash_table *ht) {
  free(ht->table);
  free(ht);
}

// Увеличивает частоту буквы в хэш-таблице
void hash_table_increment(hash_table *ht, char key) {
  char *str = to_string(key);
  int index = hash(str) % TABLE_SIZE;

  for (int i = 0; i < ht->size; i++) {
    int current = QUADRATIC_PROBING(index, i); // Квадратичный шаг

    if (ht->table[current].key == '\0') { // Если буквы нет
      ht->table[current].key = key;
      ht->table[current].val = 1;
      free(str);
      return;
    }

    if (ht->table[current].key == key) {
      ht->table[current].val++;
      free(str);
      return;
    }
  }

  free(str);
}

// Удаляет букву из хэш-таблицы
// 0 - при успехе, 1 - если буквы нет
int hash_table_remove(hash_table *ht, char key) {
  char *str = to_string(key);
  int index = hash(str) % TABLE_SIZE;

  for (int i = 0; i < ht->size; i++) {
    int current = QUADRATIC_PROBING(index, i); // Квадратичный шаг

    if (ht->table[current].key == key) {
      ht->table[current].key = '\0';
      ht->table[current].val = 0;
      free(str);
      return 0;
    }
  }

  free(str);
  return 1;
}

size_t hash_table_get_val(const hash_table *ht, char key) {
  char *str = to_string(key);
  int index = hash(str) % TABLE_SIZE;

  for (int i = 0; i < ht->size; i++) {
    int current = QUADRATIC_PROBING(index, i); // Квадратичный шаг

    if (ht->table[current].key == key) {
      free(str);
      return ht->table[current].val;
    }
  }

  free(str);
  return 0;
}

void hash_table_print(const hash_table *ht) {
  for (int i = 0; i < ht->size; i++) {
    if (ht->table[i].key != '\0')
      printf("%c: %u\n", ht->table[i].key, ht->table[i].val);
  }
}

int hash_table_write_to_file(const hash_table *ht, const char *filename) {
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  for (int i = 0; i < ht->size; i++) {
    if (ht->table[i].key != '\0')
      fprintf_s(file, "%c: %u\n", ht->table[i].key, ht->table[i].val);
  }

  fclose(file);
  return 0;
}

char *read_text_file(const char *filename) {
  FILE *file = fopen(filename, "rb");
  if (!file)
    return NULL;

  // Определяем размер файла
  if (fseek(file, 0, SEEK_END)) {
    fclose(file);
    return NULL;
  }

  long file_size = ftell(file);
  if (errno != 0) {
    perror("ftell");
    fclose(file);
    return NULL;
  }

  rewind(file);

  // Выделяем память (+1 для нуль-терминатора)
  char *buffer = (char *)malloc(file_size + 1);
  if (!buffer) {
    fclose(file);
    return NULL;
  }

  // Читаем данные и проверяем целостность
  size_t bytes_read = fread(buffer, 1, file_size, file);
  if (bytes_read != (size_t)file_size) {
    free(buffer);
    fclose(file);
    return NULL;
  }

  // Добавляем нуль-терминатор
  buffer[file_size] = '\0';
  fclose(file);
  return buffer;
}

int main() {
  char *text = read_text_file("input.txt");
  if (!text) {
    printf("Error reading file\n");
    return 1;
  }

  int size = strlen(text);

  hash_table *ht = hash_init(TABLE_SIZE);

  for (int i = 0; i < size; i++) {
    if (isalpha(text[i]))
      hash_table_increment(ht, tolower(text[i]));
  }

  if (hash_table_write_to_file(ht, "output.txt") != 0) {
    printf("Error writing to file\n");
    hash_table_free(ht);
    free(text);
    return 1;
  }

  char key1, key2;
  printf("Enter key: ");
  scanf(" %c", &key1);

  size_t val = hash_table_get_val(ht, key1);
  printf("%c: %zu\n", key1, val);

  printf("Enter key to remove: ");
  scanf(" %c", &key2);

  if (hash_table_remove(ht, key2) != 0) {
    printf("No key to remove!\n");
  }

  printf("%u\n", hash_table_get_val(ht, key2));

  hash_table_free(ht);
  free(text);

  return 0;
}
