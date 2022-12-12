#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define DEFAULT_NUM_TIMES_EAT 3
#define NUM_PHILOSOPHERS 5

// Struct para armazenar os dados de cada filósofo
typedef struct
{
    long id;
    int num_forks;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int num_times_eat;
    int times_eaten;
    pthread_mutex_t *forks;
} Philosopher;

pthread_t philosophers[NUM_PHILOSOPHERS];
pthread_mutex_t forks[NUM_PHILOSOPHERS];

long get_time(struct timeval timestamp)
{
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    return (current_time.tv_sec - timestamp.tv_sec) * 1000 + (current_time.tv_usec - timestamp.tv_usec) / 1000;
}

// Função que simula a comida de um filósofo
void *simular_comida(void *arg)
{
    Philosopher *philosopher = (Philosopher *)arg;
    long id = philosopher->id;
    int num_forks = philosopher->num_forks;
    int left_fork = id;
    int right_fork = (id + 1) % num_forks;

    // Inicializa o timestamp para o início da simulação
    struct timeval timestamp;
    gettimeofday(&timestamp, NULL);

    while (1)
    {
        // Calcula o timestamp atual
        long time_since_start = get_time(timestamp);

        // Verifica se o filósofo morreu
        if (time_since_start > philosopher->time_to_die)
        {
            printf("%ld %d died\n", time_since_start, id);
            break;
        }

        // Try to pick up forks
        if (pthread_mutex_lock(&forks[left_fork]) == 0 && pthread_mutex_lock(&forks[right_fork]) == 0)
        {
            printf("%ld %d has taken a fork\n", time_since_start, id);
            printf("%ld %d has taken a fork\n", time_since_start, id);
        }

        // Eat
        printf("%ld %d is eating\n", time_since_start, id);
        // usleep(philosopher->time_to_eat * 1000);
        philosopher->times_eaten++;

        // Put down forks
        pthread_mutex_unlock(&forks[left_fork]);
        pthread_mutex_unlock(&forks[right_fork]);

        // Verifica se o filósofo já comeu o suficiente e deve parar
        if (philosopher->num_times_eat > 0 && philosopher->times_eaten >= philosopher->num_times_eat)
        {
            pthread_exit(NULL);
        }

        // Sleep
        printf("%ld %d is sleeping\n", time_since_start, id);
        usleep(philosopher->time_to_sleep * 1000);

        // Think
        printf("%ld %d is thinking\n", time_since_start, id);
        // usleep(philosopher->time_to_sleep * 1000);
    }
}

int main(int argc, char *argv[])
{
    if (argc < 5 || argc > 6)
    {
        fprintf(stderr, "Uso: %s number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
    }
    // Lê os argumentos da linha de comando
    int num_philosophers = atoi(argv[1]);
    int time_to_die = atoi(argv[2]);
    int time_to_eat = atoi(argv[3]);
    int time_to_sleep = atoi(argv[4]);
    int num_times_eat = (argc == 6) ? atoi(argv[5]) : 0;

    // Inicializa mutexes para os garfos
    //    pthread_mutex_t forks[num_philosophers];
    for (int i = 0; i < num_philosophers; i++)
    {
        if (pthread_mutex_init(&forks[i], NULL) != 0)
        {
            fprintf(stderr, "Erro ao inicializar mutex para garfo %d.\n", i);
            return 1;
        }
    }

    // Cria threads para filósofos
    //    pthread_t philosophers[num_philosophers];
    Philosopher philosopher_data[num_philosophers];
    for (int i = 0; i < num_philosophers; i++)
    {
        // Inicializa os dados para cada filósofo
        philosopher_data[i].id = i;
        philosopher_data[i].num_forks = num_philosophers;
        philosopher_data[i].time_to_die = time_to_die;
        philosopher_data[i].time_to_eat = time_to_eat;
        philosopher_data[i].time_to_sleep = time_to_sleep;
        philosopher_data[i].num_times_eat = num_times_eat;
        philosopher_data[i].times_eaten = 0;
        philosopher_data[i].forks = forks;

        // Cria a thread para o filósofo
        if (pthread_create(&philosophers[i], NULL, simular_comida, &philosopher_data[i]) != 0)
        {
            fprintf(stderr, "Erro ao criar thread para filósofo %d.\n", i);
            return 1;
        }
    }

    // Aguarda as threads dos filósofos terminarem
    for (int i = 0; i < num_philosophers; i++)
    {
        if (pthread_join(philosophers[i], NULL) != 0)
        {
            fprintf(stderr, "Erro ao unir thread para filósofo %d.\n", i);
            return 1;
        }
    }

    // Limpa os mutexes dos garfos
    for (int i = 0; i < num_philosophers; i++)
    {
        pthread_mutex_destroy(&forks[i]);
    }

    return 0;
}