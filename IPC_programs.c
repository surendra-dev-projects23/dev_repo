
/******************************************************************************
Threads
*******************************************************************************/
#include<pthread.h>
void *Myfunction()
{
    int a ,b,sum,sub;
    printf("enter two numbers: ");
    scanf("%d%d",&a,&b);
    sum = a + b;
    sub = a - b;
    printf("sum is : %d\n",sum);
    printf("sub is : %d\n",sub);
}
int main()
{
    pthread_t thread1;
    pthread_create(&thread1, NULL, Myfunction,NULL);
    pthread_join(thread1,NULL);
    printf("Inside the main program");
    for(int i = 5; i<10; i++)
    {
        printf("%d\n",i);
        sleep(2);
    }

    return 0;
}
/******************************************************************************
Race condition
*******************************************************************************/

#include <stdio.h>
#include<pthread.h>
#include<semaphore.h>
int shared = 1;
void *Myfun1()
{
    int x ;
    x = shared;
    printf("thread1 reads the valus of shared vaiable : %d\n",x);
    x++;
    printf("increments the local variable %d\n",x);
    sleep(2);
    shared = x;
    printf("the local updated valus assigns to shared variable %d\n",shared);
}
void *Myfun2()
{
    int y ;
    y = shared;
    printf("thread2 reads the valus of shared vaiable : %d\n",y);
    y--;
    printf("decrements the local variable %d\n",y);
    sleep(2);
    shared = y;
    printf("the local updated valus assigns to shared variable %d\n",shared);
}
int main()
{
    pthread_t thread1,thread2;
    pthread_create(&thread1,NULL,Myfun1,NULL);
    pthread_create(&thread2,NULL,Myfun2,NULL);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    printf("value of shared variable at final: %d\n", shared);
    return 0;
}

-------------------------------------------------
/******************************************************************************
Semaphore 
//sem_init(&s,0,1);  //initialize semaphore variable,
 1st arg is address of semaphore variable.2nd arg value is 0 (0 -> shared b/w threads & 1 -> for processor),3rd arg is initial val for binary sempahore default val is 1.
*******************************************************************************/

#include <stdio.h>
#include<pthread.h>
#include<semaphore.h>
int shared = 1;
sem_t s;
void *Myfun1()
{
    sem_wait(&s);
    int x ;
    x = shared;
    printf("thread1 reads the valus of shared vaiable : %d\n",x);
    x++;
    printf("increments the local variable %d\n",x);
    sleep(2);
    shared = x;
    printf("the local updated valus assigns to shared variable %d\n",shared);
    sem_post(&s);
}
void *Myfun2()
{
    sem_wait(&s);
    int y ;
    y = shared;
    printf("thread2 reads the valus of shared vaiable : %d\n",y);
    y--;
    printf("decrements the local variable %d\n",y);
    sleep(2);
    shared = y;
    printf("the local updated valus assigns to shared variable %d\n",shared);
    sem_post(&s);
}
int main()
{
    sem_init(&s,0,1);
    pthread_t thread1,thread2;
    pthread_create(&thread1,NULL,Myfun1,NULL);
    pthread_create(&thread2,NULL,Myfun2,NULL);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    printf("value of shared variable at final: %d\n", shared);
    return 0;
}
/******************************************************************************
Mutex

*******************************************************************************/

#include <stdio.h>
#include<pthread.h>
#include<semaphore.h>
int shared = 1;
pthread_mutex_t loc;
void *Myfun1()
{
    pthread_mutex_lock(&loc);
    int x ;
    x = shared;
    printf("thread1 reads the valus of shared vaiable : %d\n",x);
    x++;
    printf("increments the local variable %d\n",x);
    sleep(2);
    shared = x;
    printf("the local updated valus assigns to shared variable %d\n",shared);
    pthread_mutex_unlock(&loc);
}
void *Myfun2()
{
    pthread_mutex_lock(&loc);
    int y ;
    y = shared;
    printf("thread2 reads the valus of shared vaiable : %d\n",y);
    y--;
    printf("decrements the local variable %d\n",y);
    sleep(2);
    shared = y;
    printf("the local updated valus assigns to shared variable %d\n",shared);
    pthread_mutex_unlock(&loc);
}
int main()
{
    pthread_mutex_init(&loc,NULL);
    pthread_t thread1,thread2;
    pthread_create(&thread1,NULL,Myfun1,NULL);
    pthread_create(&thread2,NULL,Myfun2,NULL);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    printf("value of shared variable at final: %d\n", shared);
    return 0;
}
/******************************************************************************
Deadlock

*******************************************************************************/

#include <stdio.h>
#include<pthread.h>
#include<semaphore.h>
pthread_mutex_t first_mutex,second_mutex;
void *Myfun1()
{
    printf("thread1 is trying to acquire first_mutex\n");
    pthread_mutex_lock(&first_mutex);
    printf("thread1 is acquired first_mutex\n");
    sleep(2);
    printf("thread1 is trying............. to acquire second_mutex\n");
    pthread_mutex_lock(&second_mutex);
    printf("thread1 acquired second_mutex.....not happen");
}
void *Myfun2()
{
    printf("thread2 is trying to acquire second_mutex\n");
    pthread_mutex_lock(&second_mutex);
    printf("thread2 is acquired second_mutex\n");
    sleep(2);
    printf("thread2 is trying........... to acquire first_mutex\n");
    pthread_mutex_lock(&first_mutex);
    printf("thread2 acquired second_mutex.....not happen");
}
int main()
{
    pthread_mutex_init(&first_mutex,NULL);
    pthread_mutex_init(&second_mutex,NULL);
	
    pthread_t thread1,thread2;
    pthread_create(&thread1,NULL,Myfun1,NULL);
    pthread_create(&thread2,NULL,Myfun2,NULL);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    printf("Thread joined");
    return 0;
}

Output:
thread2 is trying to acquire second_mutex
thread2 is acquired second_mutex
thread1 is trying to acquire first_mutex
thread1 is acquired first_mutex
thread2 is trying........... to acquire first_mutex
thread1 is trying............. to acquire second_mutex
--------------------------------------------------------------------------------
ps -ef ->List all Running Process
ps -aux ->Lists all Running Processes Filtered by CPU or Memory Usage
ps -p <PID> ->List Processes with a Given PID
/******************************************************************************
#include<unistd.h>
int pipe(int pipefd[2]);
pipe() function creates a unidirectional pipe for IPC. On success it return two file descriptors pipefd[0] and pipefd[1].
 pipefd[0] is the reading end of the pipe. So, the process which will receive the data should use this file descriptor. 
pipefd[1] is the writing end of the pipe. So, the process that wants to send the data should use this file descriptor.


*******************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(void)
{
    int fd[2],n;// 0 ->read & 1-> write
    pipe(fd);
    pid_t pid;
    char buff[100];
    pid = fork();
    if (pid > 0)
    {
        printf("parent passing value to child\n");
        write(fd[1],"HELLO DNSR\n",11);
		wait(NULL);
    }
    else
    {
        printf("iam child received the data from my parent process\n");
        int n = read(fd[0],buff,sizeof(buff)); // read and store it on buffer 
        //int n is used to store how many characters was the read system call able to read not what it read. Only the count
        write(1,buff,n); // print on the screen how much data received.
        printf("%d\n",n);
        
    }
}
o/p:
parent passing value to child
iam child received the data from my parent process
HELLO DNSR
11
-------------------------------------------------------------------
Providea a queue for waiting threads inside the critical section.
condition variable: 
=========================
=>Condition variables provide yet another way for threads to synchronize. 
     While mutexes implement synchronization by controlling thread access to data, 
     condition variables allow threads to synchronize based upon the actual value of data.

=>A condition variable is always used in conjunction with a mutex lock. 

Threads can wait on a condition variable. 

When you want to sleep a thread, condition variable can be used. In C under Linux, there is a function pthread_cond_wait() to wait or sleep. 
On the other hand, there is a function pthread_cond_signal() to wake up sleeping or waiting thread.
 
The pthread_cond_wait() release a lock specified by mutex and wait on condition cond variable. 
The pthread_cond_signal() wake up threads waiting for the condition variable. 

=>pthread_cond_wait()
      should be called while mutex is locked and it will automatically release the mutex while it waits
      when wakes up, mutex will be automatically locked for use by the thread
programmer is responsible for unlocking mutex when the thread is finished with it
=> pthread_cond_signal()
       should be called after mutex is locked
       must unlock mutex in order for pthread_cond_wait() routine to complete
	   
The above code works, but it wastes CPU time, because the main thread continually loops, checking the state of the variable avail.
 A condition variable remedies this problem. It allows a thread to sleep (wait) until another thread notifies (signals) it that it must do something.

#include <stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
pthread_mutex_t loc;
pthread_cond_t cond;
int MAX = 20;
int count = 0;
void *PrintEven()
{
  while(count<MAX)
  {
    pthread_mutex_lock(&loc);
    while(count%2 != 0)
    {
        pthread_cond_wait(&cond,&loc);
    }
    printf("%d ", count++);
    pthread_mutex_unlock(&loc);
    pthread_cond_signal(&cond);
  }
}
void *PrintOdd()
{
    while(count<MAX)
    {
      pthread_mutex_lock(&loc);
      while(count%2 != 1)
      {
          pthread_cond_wait(&cond,&loc);
      }
      printf("%d ", count++);
      pthread_mutex_unlock(&loc);
     pthread_cond_signal(&cond);
    }
      
}
int main()
{
    pthread_mutex_init(&loc,NULL);
    pthread_cond_init(&cond,NULL);
    pthread_t thread1,thread2;
    pthread_create(&thread1,NULL,PrintEven,NULL);
    pthread_create(&thread2,NULL,PrintOdd,NULL);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
     pthread_mutex_destroy(&loc);
    pthread_cond_destroy(&cond);
    //printf("value of shared variable at final: %d\n", shared);
    return 0;
}

