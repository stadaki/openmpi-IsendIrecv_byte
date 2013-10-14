#include <iostream>
#include <mpi.h>

struct parameter {
	int src_rank;
	double value;
};

int main(int argc, char *argv[])
{
	MPI::Init(argc, argv);

	int rank = MPI::COMM_WORLD.Get_rank();
	int procs = MPI::COMM_WORLD.Get_size();

	int dest_rank = (rank + 1) % procs;
	int src_rank = (rank - 1 + procs) % procs;

	parameter send_param;
	send_param.src_rank = src_rank;
	send_param.value = 3.14 * (rank + 1);
	parameter recv_param;
	recv_param.src_rank = -1;
	recv_param.value = -1;

	const int TAG = 0;
	MPI::Request request[2];
	request[0] = MPI::COMM_WORLD.Isend(
			&send_param, sizeof(struct parameter), MPI_BYTE, 
			dest_rank, TAG);
	request[1] = MPI::COMM_WORLD.Irecv(
			&recv_param, sizeof(struct parameter), MPI_BYTE,
			src_rank, TAG);
	MPI::Request::Waitall(2, request);

	std::cout << "rank = " << rank
		  << " : src rank = " << recv_param.src_rank
		  << " : value = " << recv_param.value << std::endl;

	MPI::Finalize();
}
