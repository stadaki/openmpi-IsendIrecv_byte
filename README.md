# openmpi/IsendIrecv_byte

OpenMPI non-blocking communications sample


## Environment

	Debian wheezy

## Setup

        $ sudo apt-get install libopenmpi-dev openmpi-bin

## Building

        $ make
        mpic++ -g -O2    IsendIrecv_byte.cpp   -o IsendIrecv_byte

## Running

        $ make test
	mpirun -np 8 ./IsendIrecv_byte
	rank = 3 : src rank = 1 : value = 9.42
	rank = 4 : src rank = 2 : value = 12.56
	rank = 2 : src rank = 0 : value = 6.28
	rank = 1 : src rank = 7 : value = 3.14
	rank = 5 : src rank = 3 : value = 15.7
	rank = 0 : src rank = 6 : value = 25.12
	rank = 6 : src rank = 4 : value = 18.84
	rank = 7 : src rank = 5 : value = 21.98
