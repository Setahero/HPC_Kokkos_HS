#include <cstdint>
#include <iostream>
#include <vector>
#include <boost/program_options.hpp>


double dx = 1.0;
double dy = 1.0;
double k = 1.0;
double dt = 0.05;
int iteration = 5;

double array[10][10]={{0.0}};
double array_new[10][10]={{0.0}};

template< typename T, size_t N, size_t M >
void printArray( T(&theArray)[N][M]  ) {
    for ( int x = 0; x < N; x ++ ) {
        for ( int y = 0; y < M; y++ ) {
            std::cout << " " << theArray[x][y] << " " << " ";
        } 
        std::cout << "\n";
    }
}




int main(int argc, char* argv[])
{
    
    namespace po = boost::program_options;
    po::options_description desc("Allowed options");
    desc.add_options()
                ("help,h", "Print this Message")
                ("iteration,i", po::value<int>(&iteration), "Set Iterations, standart 5")
                ;

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if(vm.count("help")) {
        std::cout << desc << "\n";
        return 1;
    }

    //Setting the heat in the left corner

    for (size_t i = 1; i <= 6; ++i)
    {
    	for (size_t j = 1; j <= 6; ++j)
    	{
    		array[i][j]=1.0;
    		array_new[i][j]=1.0;
    	}
    }

	for (int i = 1; i <= iteration; ++i)
	{
	    std::swap(array,array_new);
	    for (int i = 1; i <= 8; ++i)
	    {
	    	for (int j = 1; j <= 8; ++j)
	    	{

	    		double dtheta = ((array[i-1][j] + array[i+1][j] - 2*array[i][j])/
	    					dx) + ((array[i][j-1] + array[i][j+1] - 
	    					2*array[i][j])/1.0);
	    		array_new[i][j] = array[i][j] + k*dtheta*dt;

	    	}
	    }
	}
	printArray(array_new);
}