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
int x = 5;
int y = 5;

std::vector<std::vector<double>> array;
std::vector<std::vector<double>> array_new;
/*double array[10][10]={{0.0}};
double array_new[10][10]={{0.0}};
*/
//	For printing purpose	//

template < typename T> void printVector(std::vector<std::vector<T> >myvec){ 
	for(int x=0; x<myvec.size();x++){ 
		for(int y=0;y<myvec.at(x).size();y++){ 
			std::cout << " " << myvec.at(x).at(y) << "  "; 
		} 
		std::cout << "\n"; 
	} 
}

//	Checking, if accesing out of bounds element	//

int checkBounds(int i){

	//std::cout << "$$ "<< i << " $$" << "\n";
	if (i<0){
		return x-1;
	}else if (i==x)
	{
		return 0;
	}
	return i;
}

// 2D Stencil implementation	//

double computeNewNode(std::vector<std::vector<double>> arr, int i, int j){
	double x = dx*dx;
	double y = dy*dy;
	//std::cout << i << " " << j << " "<< "\n";

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
                ("sizex, sx", po::value<int>(&x), "Set number of columns ")
                ("sizey, sy", po::value<int>(&y), "Set number of rows")
                ;

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);




    if(vm.count("help")) {
        std::cout << desc << "\n";
        return 1;
    }

    //Setting the heat in the left corner

	array=std::vector<std::vector<double>>(x,std::vector<double>(y,0.0));
	array_new=std::vector<std::vector<double>>(x,std::vector<double>(y,0.0));
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

	    for (int i = 0; i <= x-1; ++i)
	    {
	    	for (int j = 0; j <= x-1; ++j)
	    	{

	    		/*double dtheta = ((array[i-1][j] + array[i+1][j] - 2*array[i][j])/
	    					dx*dx) + ((array[i][j-1] + array[i][j+1] - 
	    					2*array[i][j])/dy*dy);
	    		*/
	    		array_new[i][j] = array[i][j] + k*computeNewNode(array,i,j)*dt;

	    	}
	    }
	}
	printVector(array_new);
}