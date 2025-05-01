#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *trim(char *s) {
    while (*s == '0' && *(s + 1)) s++;
    return s;
}

char *mul(const char *x, int d) {
    int len = strlen(x), c = 0, i;
    char *r = malloc(len + 3);
    if (!r) return NULL;
    r[len + 2] = '\0';
    for (i = len - 1; i >= 0; --i) {
        int t = (x[i] - '0') * d + c;
        r[i + 1] = t % 10 + '0'; 
        c = t / 10;
    }
    r[0] = c ? c + '0' : '0';
    char *trimmed = trim(r);
    if (trimmed != r) memmove(r, trimmed, strlen(trimmed) + 1);
    return r;
}

char *sub(const char *a, const char *b) {
    int la = strlen(a), lb = strlen(b), i, c = 0, ml = la > lb ? la : lb;
    char *r = malloc(ml + 1);
    if (!r) return NULL;
    r[ml] = 0;
    for (i = 0; i < ml; ++i) {
        int ai = i < la ? a[la - 1 - i] - '0' : 0;
        int bi = i < lb ? b[lb - 1 - i] - '0' : 0;
        int d = ai - bi - c;
        if (d < 0) {
            d += 10;
            c = 1;
        } else c = 0;
        r[ml - 1 - i] = d + '0';
    }
    char *trimmed = trim(r);
    if (trimmed != r) memmove(r, trimmed, strlen(trimmed) + 1);
    return r;
}

int cmp(const char *a, const char *b) {
    int la = strlen(a);
    int lb = strlen(b);
    char *a_copy = malloc(la + 1);
    char *b_copy = malloc(lb + 1);
    if (!a_copy || !b_copy) {
        if (a_copy) free(a_copy);
        if (b_copy) free(b_copy);
        return 0;
    }
    strcpy(a_copy, a);
    strcpy(b_copy, b);
    char *a_trimmed = trim(a_copy);
    char *b_trimmed = trim(b_copy);
    la = strlen(a_trimmed);
    lb = strlen(b_trimmed);
    int result = (la != lb) ? (la - lb) : strcmp(a_trimmed, b_trimmed);
    free(a_copy);
    free(b_copy);
    return result;
}

char **divide_strings(char *a, char *b) {
    if (!a || !b || strlen(b) == 0 || (strlen(b) == 1 && b[0] == '0')) return NULL;
    
    char **result = malloc(2 * sizeof(char *));
    if (!result) return NULL;
    
    if (strlen(a) == 1 && a[0] == '0') {
        result[0] = malloc(2);
        result[1] = malloc(2);
        if (result[0] && result[1]) {
            strcpy(result[0], "0");
            strcpy(result[1], "0");
            return result;
        }
        if (result[0]) free(result[0]);
        if (result[1]) free(result[1]);
        free(result);
        return NULL;
    }
    
    if (cmp(a, b) < 0) {
        result[0] = malloc(2);
        result[1] = malloc(strlen(a) + 1);
        if (result[0] && result[1]) {
            strcpy(result[0], "0");
            strcpy(result[1], a);
            return result;
        }
        if (result[0]) free(result[0]);
        if (result[1]) free(result[1]);
        free(result);
        return NULL;
    }
    
    size_t a_len = strlen(a);
    size_t b_len = strlen(b);
    
    char *current = malloc(a_len + 1);
    if (!current) {
        free(result);
        return NULL;
    }
    current[0] = '\0';
    
    char *quotient = malloc(a_len + 1);
    if (!quotient) {
        free(current);
        free(result);
        return NULL;
    }
    
    size_t q_pos = 0;
    
    for (size_t i = 0; i < a_len; i++) {
        char next_digit[2] = {a[i], '\0'};
        strcat(current, next_digit);
        
        if (current[0] == '0' && strlen(current) > 1) {
            memmove(current, current + 1, strlen(current));
        }
        
        if (cmp(current, b) < 0) {
            quotient[q_pos++] = '0';
            continue;
        }
        
        int count = 0;
        while (cmp(current, b) >= 0) {
            char *new_current = sub(current, b);
            if (!new_current) {
                free(current);
                free(quotient);
                free(result);
                return NULL;
            }
            
            strcpy(current, new_current);
            free(new_current);
            count++;
        }
        
        quotient[q_pos++] = count + '0';
    }
    
    quotient[q_pos] = '\0';
    
    char *trimmed_q = trim(quotient);
    if (strlen(trimmed_q) == 0) {
        trimmed_q = "0";
    }
    
    result[0] = malloc(strlen(trimmed_q) + 1);
    result[1] = malloc(strlen(current) + 1);
    
    if (!result[0] || !result[1]) {
        if (result[0]) free(result[0]);
        if (result[1]) free(result[1]);
        free(result);
        free(current);
        free(quotient);
        return NULL;
    }
    
    strcpy(result[0], trimmed_q);
    strcpy(result[1], current);
    
    free(current);
    free(quotient);
    
    return result;
}

int main() {
    char **res = divide_strings("123456789123456789123456789", "987654321");
    if (res) {
        printf("Quotient: %s\n", res[0]);
        printf("Remainder: %s\n", res[1]);
        free(res[0]);
        free(res[1]);
        free(res);
    } else {
        printf("Error in division\n");
    }
    return 0;
}



/*tests que va a pasar:
#include <criterion/criterion.h>

char **divide_strings(char *, char *);

Test(the_divide_strings_function, should_pass_some_sample_assertions) {
  char **actual = divide_strings("0", "5");
  cr_assert_str_eq(*actual, "0", "0 / 5 == 0");
  cr_assert_str_eq(*(actual + 1), "0", "0 %% 5 == 0");
  free(*actual);
  free(*(actual + 1));
  free(actual);
  actual = divide_strings("4", "5");
  cr_assert_str_eq(*actual, "0", "4 / 5 == 0");
  cr_assert_str_eq(*(actual + 1), "4", "4 %% 5 == 4");
  free(*actual);
  free(*(actual + 1));
  free(actual);
  actual = divide_strings("10", "2");
  cr_assert_str_eq(*actual, "5", "10 / 2 == 5");
  cr_assert_str_eq(*(actual + 1), "0", "10 %% 2 == 0");
  free(*actual);
  free(*(actual + 1));
  free(actual);
  actual = divide_strings("20", "3");
  cr_assert_str_eq(*actual, "6", "20 / 3 == 6");
  cr_assert_str_eq(*(actual + 1), "2", "20 %% 3 == 2");
  free(*actual);
  free(*(actual + 1));
  free(actual);
  actual = divide_strings("60", "5");
  cr_assert_str_eq(*actual, "12", "60 / 5 == 12");
  cr_assert_str_eq(*(actual + 1), "0", "60 %% 5 == 0");
  free(*actual);
  free(*(actual + 1));
  free(actual);
  actual = divide_strings("219", "11");
  cr_assert_str_eq(*actual, "19", "219 / 11 == 19");
  cr_assert_str_eq(*(actual + 1), "10", "219 %% 11 == 10");
  free(*actual);
  free(*(actual + 1));
  free(actual);
  actual = divide_strings("729", "9");
  cr_assert_str_eq(*actual, "81", "729 / 9 == 81");
  cr_assert_str_eq(*(actual + 1), "0", "729 %% 9 == 0");
  free(*actual);
  free(*(actual + 1));
  free(actual);
  actual = divide_strings("1000", "10");
  cr_assert_str_eq(*actual, "100", "1000 / 10 == 100");
  cr_assert_str_eq(*(actual + 1), "0", "1000 %% 10 == 0");
  free(*actual);
  free(*(actual + 1));
  free(actual);
  actual = divide_strings("600001", "100");
  cr_assert_str_eq(*actual, "6000", "600001 / 100 == 6000");
  cr_assert_str_eq(*(actual + 1), "1", "600001 %% 100 == 1");
  free(*actual);
  free(*(actual + 1));
  free(actual);
}

*/
