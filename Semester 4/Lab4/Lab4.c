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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 26

// Пара, состоящая из символа и его частоты
typedef struct pair {
  char key;
  unsigned int val;
} pair;

// Хэш-таблица, массив пар и его размер
typedef struct hash_table {
  pair *table;
  unsigned int size;

} hash_table;

// Хэш-функция, возвращает индекс буквы [0, 25]
int hash(char c) { return tolower(c) - 'a'; }

// Возращает указатель на хэш-таблицу, который должен быть освобожден после использования
hash_table *hash_init(unsigned int size) {
  hash_table *ht = malloc(sizeof(hash_table));
  ht->table = calloc(size * sizeof(pair), sizeof(pair));
  ht->size = size;

  return ht;
}

void hash_table_free(hash_table *ht) {
  free(ht->table);
  free(ht);
}

// Увеличивает частоту буквы в хэш-таблице
void hash_table_increment(hash_table *ht, char key) {
  key = tolower(key);
  int index = hash(key);

  if (ht->table[index].key == key) {
    ht->table[index].val++;
    return;
  }

  ht->table[index].key = key;
  ht->table[index].val = 1;
}

// Удаляет букву из хэш-таблицы
// 0 - при успехе, 1 - если буквы нет
int hash_table_remove(hash_table *ht, char key) {
  key = tolower(key);
  int index = hash(key);

  if (ht->table[index].key == key) {
    ht->table[index].key = '\0';
    ht->table[index].val = 0;
    return 0;
  }

  return 1;
}

unsigned int hash_table_get_val(const hash_table *ht, char key) {
  int index = hash(key);

  if (ht->table[index].key == key) {
    return ht->table[index].val;
  }

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
      hash_table_increment(ht, text[i]);
  }

  if (hash_table_write_to_file(ht, "output.txt") != 0) {
    printf("Error writing to file\n");
    hash_table_free(ht);
    free(text);
    return 1;
  }

  char key;
  printf("Enter key: ");
  scanf("%c", &key);

  unsigned int val = hash_table_get_val(ht, key);
  printf("%c: %u\n", key, val);

  hash_table_free(ht);
  free(text);

  return 0;
}