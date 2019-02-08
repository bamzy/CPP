#include "netcdfWriter.h"


using namespace std;
using namespace netCDF;
using namespace netCDF::exceptions;

inline bool fileExist (const std::string& name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }   
}
int netcdfWriter(rarray<int,2>  new_number_of_ants, int length){
	try
	{  	   
	
		if (fileExist(FILE_NAME)){
			// Create the file.
			NcFile dataFile(FILE_NAME, NcFile::write);
			NcDim xDim = dataFile.addDim("x", length);
			NcDim yDim = dataFile.addDim("y", length);

			// Define the variable. The type of the variable in this case is
			// ncInt (32-bit integer).
			vector<NcDim> dims;
			dims.push_back(xDim);
			dims.push_back(yDim);
			NcVar data = dataFile.addVar("numberOfAnts", ncInt, dims);
			data.putVar(new_number_of_ants.data());

		}
		else {
			NcFile dataFile(FILE_NAME, NcFile::replace);
			// Create netCDF dimensions
			NcDim xDim = dataFile.addDim("x", length);
			NcDim yDim = dataFile.addDim("y", length);

			// Define the variable. The type of the variable in this case is
			// ncInt (32-bit integer).
			vector<NcDim> dims;
			dims.push_back(xDim);
			dims.push_back(yDim);
			NcVar data = dataFile.addVar("numberOfAnts", ncInt, dims);
			data.putVar(new_number_of_ants.data());
		}
	}
	catch(NcException& e)
	{e.what();
		return NC_ERR;
	}
	
	

	// Write the data to the file. Although netCDF supports
	// reading and writing subsets of data, in this case we write all
	// the data in one operation.
	



	cout << "*** SUCCESS writing  file " << FILE_NAME << "!" << endl;

}



