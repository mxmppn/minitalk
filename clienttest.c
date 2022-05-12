#include "minitalk.h"

int	main(int ac, char **av)
{
    pid_t   ue_pid;

    ue_pid = atoi(av[1]);
	kill(ue_pid, SIGUSR1);
	return (0);
}