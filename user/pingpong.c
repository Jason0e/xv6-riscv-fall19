#include <kernel/types.h>
#include <user/user.h>

int main(int argc, char const *argv[])
{
	int parent_fd[2],child_fd[2];
	//father write , son read
	pipe(parent_fd);
	//father read , son write
	pipe(child_fd);
	int id = fork();
	char message[100];
	if (id != 0)
	{
		write(parent_fd[1],"ping",4);
		close(parent_fd[1]);
		read(child_fd[0],message,sizeof(message));
		printf("%d: received %s\n", getpid(),message);
	}else
    {
		write(child_fd[1],"pong",4);
		close(child_fd[1]);
		read(parent_fd[0],message,sizeof(message));
	    printf("%d: received %s\n", getpid(),message);
	}
	exit();

	return 0;
}