#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char* StringInput()
{
    char* dev;
    *dev = '\n';
    FILE* file = stdin;
    char chr;
    char* str = (char*) malloc(sizeof(char));
    int str_len = 1;
    int end = 0;
    //setbuf(file, NULL);
    while (!end)
    {
        chr = fgetc(file);
        if(chr == *dev || chr == '\n' || chr == EOF)
        {
            if(chr == '\n') *dev = '\n';
            end = 1;
            break;
        }
        if(!(str_len == 1 && chr == ' ')){
            str[str_len - 1] = chr;
            str_len++;
            str = (char*) realloc(str, str_len);
        }
    }
    str[str_len - 1] = '\0';
    return str;
}

char* GetString()
{
    int len = 0; // изначально строка пуста
    int capacity = 1; // ёмкость контейнера динамической строки (1, так как точно будет '\0')
    char *s = (char*) malloc(sizeof(char)); // динамическая пустая строка
    char c = getchar(); // символ для чтения данных
    while (c != '\n') 
    {
        s[(len)++] = c; // заносим в строку новый символ
        // если реальный размер больше размера контейнера, то увеличим его размер
        if (len >= capacity) 
        {
            capacity *= 2; // увеличиваем ёмкость строки в два раза
            s = (char*) realloc(s, capacity * sizeof(char)); // создаём новую строку с увеличенной ёмкостью
        }
        c = getchar(); // считываем следующий символ
    }
    s[len] = '\0'; // завершаем строку символом конца строки
    return s;
}

int InputInt(int* val)
{
    
    char* str = GetString();
    for(int i = 0; i < strlen(str); i++)
    {
        if (!isdigit(str[i]) && !(i == 0 && str[0] == '-')) return 0;
    }
    *val = atoi(str);
    if(*val > 0){
        return 1;
    }
    return -1;
}

int InputLong(long* val)
{
    char* str = GetString();
    for(int i = 0; i < strlen(str); i++)
    {
        if (!isdigit(str[i]) && !(i == 0 && str[0] == '-')) return 0;
    }
    *val = atoll(str);
    return 1;
}

