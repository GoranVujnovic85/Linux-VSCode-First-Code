/* Задатак
Модификовати пример "first commit" тако да се створе 3 нити на основу једне функције, при чему свака програмска нит има
свој идентификатор (1, 2 i 3).
Помоћу објеката искључивог приступа и дељених променљивих, реализовати механизам смењивања нити тако да се на екрану исписује
123123123123123123123123123123…….
то јест, да се прво активира нит 1, па нит 2 а затим нит 3, 100 пута. После 100 исписа, нити се завршавају.
Механизам за смењивање нити треба да обезбеди да нит након свог исписа сигнализира наредној нити да може да испише свој
идентификатор.
Задатак реализовати помоћу објекта искључивог приступа и дељене променљиве. Пошто приступ дељеној променљивој представља критичну секцију нити, потребно ју је заштитити коришћењем објекта искључивог приступа. Све три програмске нити реализовати истом функцијом којој се прослеђује идентификатор програмске нити.
Уколико се између два приступа критичној секцији уметне пауза (помоћу функције Sleep), програм ће се брже завршити. Зашто?
*/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

static pthread_mutex_t cs_mutex;


void* print (void *pParam)
{
    int c = *(char*)pParam;
   
    for (int i = 0 ; i < 100 ; i++)
    {
        pthread_mutex_lock(&cs_mutex);
        
        printf("%c", c);  
        fflush(stdout);

        pthread_mutex_unlock(&cs_mutex);

        sleep(1);
    }

    return 0;
}

int main (void)
{
    pthread_t hPrint1;
    pthread_t hPrint2;
    pthread_t hPrint3;

    /* Argumenti niti. */
    char c1 = '1';
    char c2 = '2';
    char c3 = '3';

    pthread_mutex_init(&cs_mutex, NULL);

    pthread_create(&hPrint1, NULL, print, (void*)&c1);
    pthread_create(&hPrint2, NULL, print, (void*)&c2);
    pthread_create(&hPrint3, NULL, print, (void*)&c3);

    pthread_join(hPrint1, NULL);
    pthread_join(hPrint2, NULL);
    pthread_join(hPrint3, NULL);

    pthread_mutex_destroy(&cs_mutex);

    return 0;
}