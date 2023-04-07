//Raimundo Oliva y Matias Fonseca

/*
Implementar solución en C Linux que, mediante uso de hebras, 
el programa principal cree una hebra hija H1 la cual crea una hebra hija H2, y H2 
crea otra hebra hija H3. Cada hebra hija se identifica al momento de ser creado y
al momento de terminar su ejecución. Por ejemplo, “H1 creado” y “H1 termina”, 
donde cada hebra madre espera a que su hija termine (puede usar pthread_join(..) 
para que una hebra espera a que otra termine – ver ejemplo hebras2.c).
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *H3_function(void *arg)
{
    int thread_num = *(int *)arg;
    printf("H3 creada!.\n");
    printf("H3 terminada!.\n");
    return NULL;
}

void *H2_function(void *arg)
{
    int thread_num = *(int *)arg;
    pthread_t H3;
    int H3_arg = 3;
    printf("H2 creada!\n");
    pthread_create(&H3, NULL, H3_function, &H3_arg);
    pthread_join(H3, NULL);
    printf("H2 terminada!.\n");
    return NULL;
}

void *H1_function(void *arg)
{
    int thread_num = *(int *)arg;
    pthread_t H2;
    int H2_arg = 2;
    printf("H1 creada!\n");
    pthread_create(&H2, NULL, H2_function, &H2_arg);
    pthread_join(H2, NULL);
    printf("H1 terminada!.\n");
    return NULL;
}

int main()
{
    pthread_t H1;
    int H1_arg = 1;
    pthread_create(&H1, NULL, H1_function, &H1_arg);
    pthread_join(H1, NULL);
    return 0;
}

