//Lab Task 3
// mpicxx labtask3.cpp -o labtask3
// mpirun -np 30 -host localhost ./labtask3

#include <mpi.h>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <fstream>

#define TAG_NAME_RESOLUTION 	0
#define TAG_NAME_REGISTRATION 	1
#define TAG_NORMAL_MESSAGE		2

using namespace std;

int main (int argc, char* argv[]) {
    // Initialize the MPI environment
    MPI_Init (NULL, NULL);

    int world_size, count = 0;
    MPI_Comm_size (MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    // each process will have a "rank" (just an ID) in the communicator
   int rank, next, prev, flag;
	int data;
	int color;
   int token = 0;
	fstream file;

    MPI_Comm_rank (MPI_COMM_WORLD, &rank);
    next = (rank+world_size+1)%world_size;
    prev = (rank+world_size-1)%world_size;
	//Process 0 execute this code
	//Clear the file if it exists and start with a value of 0
	if (rank == 0) {
		file.open ("data.txt", ios::out | ios::trunc);
		file << 0 << endl;
		file.close();
	}

	//wait for every process to reach this point
	MPI_Barrier(MPI_COMM_WORLD);
	color = 30 + rank % 10;


   while (true) {
      MPI_Request req;
      MPI_Status stat;
      if (rank == token) {
         cout << "\033[" << color << "m" << "Process " << rank << " has the token" << endl;
      	cout << "\033[" << color << "m" << "Process " << rank << " access the file" << endl;
      	file.open ("data.txt", ios::in | ios::out);
      	file >> data;
      	cout << "\033[" << color << "m" << "Process " << rank << " reads " << data << " from the file" << endl;
      	data = data + 1;
      	file.seekg (0, file.beg);
      	file << data << endl;
      	cout << "\033[" << color << "m" << "Process " << rank << " writes " << data << " to the file" << endl;
         token = token+1;
         cout << "\033[" << color << "m" << "Process " << rank << " sending token to Node " << next << endl;
         MPI_Send (&token, 1, MPI_INT, next, TAG_NAME_RESOLUTION, MPI_COMM_WORLD);
      	file.close();
         break;
      } else {
         //Try to recieve
         MPI_Irecv (&token, 1, MPI_INT, prev, TAG_NAME_RESOLUTION, MPI_COMM_WORLD, &req);
         MPI_Test(&req, &flag, &stat);

         if (!flag) {
            //If nothing
            //token=0;
            MPI_Request_free(&req);
         }
      }
   }
   cout << "\033[" << color << "m" << "Process " << rank << " is now waiting" << endl;
	MPI_Barrier(MPI_COMM_WORLD);

	//Process 0 execute this code
	//Print out the final value of the file
	if (rank == 0) {
		file.open ("data.txt", ios::in);
		file >> data;
		cout << "The final value of the file is " << data << endl;
		file.close();
	}

    cout << "\033[0m";
    // Finalize the MPI environment.
    MPI_Finalize();
}
