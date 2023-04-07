//Raimundo Oliva y Matias Fonseca

/* crear 3 hebras H1, H2 y H3 (las hebras hijas no crean nuevas hijas), donde cada hebra hija
se identifica al momento de ser creado (¡envía un mensaje tal como “H1 creado!”). */
        
#include <stdio.h>
#include <string.h>
#include <pthread.h>

void *thread_function(void *arg)
{
    char *name = (char*)arg;
    printf("%s creado!\n", name);
    return NULL;
}

int main()
{
    pthread_t H1,H2,H3;
    char n1[10], n2[10], n3[10];
    strcpy(n1, "H1");
    strcpy(n2, "H2");
    strcpy(n3, "H3");
    pthread_create(&H1, NULL, thread_function, n1);
    pthread_create(&H2, NULL, thread_function, n2);
    pthread_create(&H3, NULL, thread_function, n3);
    pthread_join(H1, NULL);
    pthread_join(H2, NULL);
    pthread_join(H3, NULL);
    printf("Todas las hebras han acabado su proceso.\n");
    return 0;
}


