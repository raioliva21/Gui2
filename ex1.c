//Raimundo Oliva y Matias Fonseca

/* Implementar solución en C Linux que mediante el uso de hebras el programa principal
cree exactamente 8 “procesos ligeros” en total, donde cada proceso 
muestra su nombre (el nombre corresponde a un parámetro que la función de cada hebra recibe). 
Por ejemplo, “Hebra1” para la hebra 1, “Hebra2” para la hebra 2, y así sucesivamente.*/

#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg)
{
    int thread_num = *(int *)arg;
    printf("Hebra numero %d!\n", thread_num);
    return NULL;
}

int main()
{
    pthread_t threads[8];
    int numbers[8] = {1,2,3,4,5,6,7,8};
    
    for (int i = 0; i < 8; i++) {
        pthread_create(&threads[i], NULL, thread_function, &numbers[i]);
        pthread_join(threads[i], NULL);
    }
    
    printf("Todas las hebras han acabado su proceso.\n");
    return 0;
}
