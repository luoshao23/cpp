#include <iostream>
#include <string>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 5

struct thread_data{
    int thread_id;
    char *message;
};

void* say_hello(void *threadarg)
{
    struct thread_data *my_data;

    my_data = (struct thread_data *) threadarg;

    cout << "ID: " << my_data->thread_id;
    cout << " Message: " << my_data->message << endl;
    pthread_exit(NULL);
}

int main()
{
    pthread_t tids[NUM_THREADS];
    struct thread_data td[NUM_THREADS];

    for(int i = 0; i < NUM_THREADS; i++)
    {
        cout << "main(): creating thread, " << i << endl;
        td[i].thread_id = i;
        td[i].message = (char *)strcat("This Message" , "as");
        int ret = pthread_create(&tids[i], NULL, say_hello, (void *)&(td[i]));
        if (ret)
        {
            cout << "pthread_create error: code=" << ret << endl;
            exit(-1);
        }

    }
    pthread_exit(NULL);
}