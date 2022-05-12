#include "minitalk.h"

static volatile int signalPid = -1;
void    get_pid(int sig, siginfo_t *info, void *context)
{
	signalPid = info->si_pid;
	return ;
}

int main(int argc, char **argv)
{
	struct sigaction	sa;

	printf("PID: %d\n", getpid());       //display PID for kill()
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = get_pid;
	sigaction(SIGUSR1, &sa, NULL);
	pause();                           //wait for a signal
	printf("PID of signal sender = %d\n", signalPid);
	return (0);
}