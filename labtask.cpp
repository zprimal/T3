//Lab Task

#include <mpi.h>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <fstream>


using namespace std;

int main (int argc, char* argv[]) {
    // Initialize the MPI environment
    MPI_Init (NULL, NULL);

    int world_size, count = 0;
    MPI_Comm_size (MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    // each process will have a "rank" (just an ID) in the communicator
    int rank;
	int data;
	int color;
	fstream file;

    MPI_Comm_rank (MPI_COMM_WORLD, &rank);

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

	//Every process read data from file, add 1 to data and rewrite (overwrite) data to the file

  if (rank == 0) {
	cout << "\033[" << color << "m" << "Process " << rank << " access the file" << endl;
	file.open ("data.txt", ios::in | ios::out);
	file >> data;
	cout << "\033[" << color << "m" << "Process " << rank << " reads " << data << " from the file" << endl;
	data = data + 1;
}
  else if (rank == 1) {
        cout << "\033[" << color << "m" << "Process " << rank << " access the file" << endl;
        file.open ("data.txt", ios::in | ios::out);
        file >> data;
     	  cout << "\033[" << color << "m" << "Process " << rank << " reads " << data << " from the file" << endl;
        data = + 1;
        file << data << endl;
     	  cout << "\033[" << color << "m" << "Process " << rank << " writes " << data << " to the file" << endl;
   }

   else if (rank == 2) {
     cout << "\033[" << color << "m" << "Process " << rank << " access the file" << endl;
     file.open ("data.txt", ios::in | ios::out);
     file >> data;
     cout << "\033[" << color << "m" << "Process " << rank << " reads " << data << " from the file" << endl;
     data = + 1;
     file << data << endl;
     cout << "\033[" << color << "m" << "Process " << rank << " writes " << data << " to the file" << endl;

   }
   else if (rank == 3) {
     cout << "\033[" << color << "m" << "Process " << rank << " access the file" << endl;
     file.open ("data.txt", ios::in | ios::out);
     file >> data;
     cout << "\033[" << color << "m" << "Process " << rank << " reads " << data << " from the file" << endl;
     data = + 1;
     file << data << endl;
     cout << "\033[" << color << "m" << "Process " << rank << " writes " << data << " to the file" << endl;

   }
   else if (rank == 4) {
     cout << "\033[" << color << "m" << "Process " << rank << " access the file" << endl;
     file.open ("data.txt", ios::in | ios::out);
     file >> data;
     cout << "\033[" << color << "m" << "Process " << rank << " reads " << data << " from the file" << endl;
     data = + 1;
     file << data << endl;
     cout << "\033[" << color << "m" << "Process " << rank << " writes " << data << " to the file" << endl;
   }
   else if (rank == 5) {
     cout << "\033[" << color << "m" << "Process " << rank << " access the file" << endl;
     file.open ("data.txt", ios::in | ios::out);
     file >> data;
     cout << "\033[" << color << "m" << "Process " << rank << " reads " << data << " from the file" << endl;
     data = + 1;
     file << data << endl;
     cout << "\033[" << color << "m" << "Process " << rank << " writes " << data << " to the file" << endl;

   }
   else if (rank == 6) {
     cout << "\033[" << color << "m" << "Process " << rank << " access the file" << endl;
     file.open ("data.txt", ios::in | ios::out);
     file >> data;
     cout << "\033[" << color << "m" << "Process " << rank << " reads " << data << " from the file" << endl;
     data = + 1;
     file << data << endl;
     cout << "\033[" << color << "m" << "Process " << rank << " writes " << data << " to the file" << endl;

   }
   else if (rank == 7) {
     cout << "\033[" << color << "m" << "Process " << rank << " access the file" << endl;
     file.open ("data.txt", ios::in | ios::out);
     file >> data;
     cout << "\033[" << color << "m" << "Process " << rank << " reads " << data << " from the file" << endl;
     data = + 1;
     file << data << endl;
     cout << "\033[" << color << "m" << "Process " << rank << " writes " << data << " to the file" << endl;

   }
   else if (rank == 8) {
     cout << "\033[" << color << "m" << "Process " << rank << " access the file" << endl;
     file.open ("data.txt", ios::in | ios::out);
     file >> data;
     cout << "\033[" << color << "m" << "Process " << rank << " reads " << data << " from the file" << endl;
     data = + 1;
     file << data << endl;
     cout << "\033[" << color << "m" << "Process " << rank << " writes " << data << " to the file" << endl;

   }

   else if (rank == 9) {
     cout << "\033[" << color << "m" << "Process " << rank << " access the file" << endl;
     file.open ("data.txt", ios::in | ios::out);
     file >> data;
     cout << "\033[" << color << "m" << "Process " << rank << " reads " << data << " from the file" << endl;
     data = + 1;
     file << data << endl;
     cout << "\033[" << color << "m" << "Process " << rank << " writes " << data << " to the file" << endl;

   }
   else if (rank == 10) {
     cout << "\033[" << color << "m" << "Process " << rank << " access the file" << endl;
     file.open ("data.txt", ios::in | ios::out);
     file >> data;
     cout << "\033[" << color << "m" << "Process " << rank << " reads " << data << " from the file" << endl;
     data = + 1;
     file << data << endl;
     cout << "\033[" << color << "m" << "Process " << rank << " writes " << data << " to the file" << endl;

   }


 else {
   	file.close();
 }




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
