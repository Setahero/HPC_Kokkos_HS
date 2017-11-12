#include <cstdint>
#include <iostream>
#include <vector>
#include <boost/program_options.hpp>


//	Standard values, if not specified	//

double dx = 1.0;
double dy = 1.0;
double k = 1.0;		//Heattransfer Coefficient
double dt = 0.05;	//Timestep
int iteration = 5; 


double array[10][10]={{0.0}};
double array_new[10][10]={{0.0}};

//	For printing purpose	//

template< typename T, size_t N, size_t M >
void printArray( T(&theArray)[N][M]  ) {
    for ( int x = 0; x < N; x ++ ) {
        for ( int y = 0; y < M; y++ ) {
            std::cout << " " << theArray[x][y] << " " << " ";
        } 
        std::cout << "\n";
    }
}

//	Checking, if accesing out of bounds element	//

int checkBounds(int i){
	if (i<0){
		return 9;
	}else if (i==10)
	{
		return 0;
	}
}

// 2D Stencil implementation	//

double computeNewNode(double arr[][10], int i, int j){
	double x = dx*dx;
	double y = dy*dy;

	return ((arr[checkBounds(i-1)][j] + arr[checkBounds(i+1)][j] - 2*arr[i][j])/
		x) + ((arr[i][checkBounds(j-1)] + arr[i][checkBounds(j+1)] - 2*arr[i][j])/y);
}



int main(int argc, char* argv[])
{
    
    namespace po = boost::program_options;
    po::options_description desc("Allowed options");
    desc.add_options()
                ("options,o", "Print this Message")
                ("iteration,i", po::value<int>(&iteration), "Set Iterations, standart 5")
                ("timestep, t", po::value<double>(&dt),"Set timestep, standart 0.05")
                ("heattrans, h",po::value<double>(&k),"Set heattransfer coefficent, standart 1.0")
                ;

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if(vm.count("help")) {
        std::cout << desc << "\n";
        return 1;
    }

    //Setting the heat in the left corner

    for (size_t i = 1; i <= 1; ++i)
    {
    	for (size_t j = 1; j <= 1; ++j)
    	{
    		array[i][j]=1.0;
    		array_new[i][j]=1.0;
    	}
    }

	for (int i = 1; i <= iteration; ++i)
	{
	    std::swap(array,array_new);

	    for (int i = 0; i <= 9; ++i)
	    {
	    	for (int j = 0; j <= 9; ++j)
	    	{

	    		/*double dtheta = ((array[i-1][j] + array[i+1][j] - 2*array[i][j])/
	    					dx*dx) + ((array[i][j-1] + array[i][j+1] - 
	    					2*array[i][j])/dy*dy);
	    		*/
	    		array_new[i][j] = array[i][j] + k*computeNewNode(array,i,j)*dt;

	    	}
	    }
	}
	printArray(array_new);
}