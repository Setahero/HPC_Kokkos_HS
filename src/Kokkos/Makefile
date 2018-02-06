KOKKOS_SETTINGS=KOKKOS_SRC_PATH=/home/andrey/Schreibtisch/kokkos CXX=/home/andrey/Schreibtisch/kokkos/bin/nvcc_wrapper KOKKOS_DEVICES=Serial,OpenMP KOKKOS_ARCH=Kepler30 GTEST_PATH=/home/andrey/Schreibtisch/kokkos/tpls/gtest KOKKOS_PATH=/home/andrey/Schreibtisch/kokkos_build/install

all:
	$(MAKE) -f /home/andrey/Schreibtisch/Hauptseminar/refactored-broccoli/src/Kokkos/build/Makefile KOKKOS_SRC_PATH=/home/andrey/Schreibtisch/kokkos CXX=/home/andrey/Schreibtisch/kokkos/bin/nvcc_wrapper KOKKOS_DEVICES=Cuda,Serial,OpenMP KOKKOS_ARCH=Kepler30 CUDA_PATH=/usr/local/cuda-9.0 GTEST_PATH=/home/andrey/Schreibtisch/kokkos/tpls/gtest KOKKOS_CUDA_OPTIONS=enable_lambda,force_uvm KOKKOS_PATH=/home/andrey/Schreibtisch/kokkos_build/install

test: all
	$(MAKE) -f /home/andrey/Schreibtisch/Hauptseminar/refactored-broccoli/src/Kokkos/build/Makefile KOKKOS_SRC_PATH=/home/andrey/Schreibtisch/kokkos CXX=/home/andrey/Schreibtisch/kokkos/bin/nvcc_wrapper KOKKOS_DEVICES=Cuda,Serial,OpenMP KOKKOS_ARCH=Kepler30 CUDA_PATH=/usr/local/cuda-9.0 GTEST_PATH=/home/andrey/Schreibtisch/kokkos/tpls/gtest KOKKOS_CUDA_OPTIONS=enable_lambda,force_uvm KOKKOS_PATH=/home/andrey/Schreibtisch/kokkos_build/install test

clean:
	$(MAKE) -f /home/andrey/Schreibtisch/Hauptseminar/refactored-broccoli/src/Kokkos/build/Makefile KOKKOS_SRC_PATH=/home/andrey/Schreibtisch/kokkos CXX=/home/andrey/Schreibtisch/kokkos/bin/nvcc_wrapper KOKKOS_DEVICES=Cuda,Serial,OpenMP KOKKOS_ARCH=Kepler30 CUDA_PATH=/usr/local/cuda-9.0 GTEST_PATH=/home/andrey/Schreibtisch/kokkos/tpls/gtest KOKKOS_CUDA_OPTIONS=enable_lambda,force_uvm KOKKOS_PATH=/home/andrey/Schreibtisch/kokkos_build/install clean
