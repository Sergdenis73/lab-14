#include <stdio.h>
#include <string.h>

int count_substring_occurrences(const char *s1, const char *s2) {
    int count = 0;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    if (len2 == 0 || len2 > len1) {
        return 0;
    }
    
    for (int i = 0; i <= len1 - len2; i++) {
        int match = 1;
        for (int j = 0; j < len2; j++) {
            if (s1[i + j] != s2[j]) {
                match = 0;
                break;
            }
        }
        if (match) {
            count++;
            // Якщо підрядки не повинні перекриватися, додаємо:
            // i += len2 - 1;
        }
    }
    
    return count;
}

int main() {
    system("chcp 65001");
    char s1[1000], s2[1000];
    
    printf("Введіть рядок S1: ");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = '\0'; // Видаляємо символ нового рядка
    
    printf("Введіть підрядок S2: ");
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = '\0'; // Видаляємо символ нового рядка
    
    int occurrences = count_substring_occurrences(s1, s2);
    printf("Кількість входжень підрядка S2 у рядок S1: %d\n", occurrences);
    
    return 0;
}