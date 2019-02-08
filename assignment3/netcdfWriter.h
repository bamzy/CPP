#include <rarray>
#include <netcdf>
#include <iostream>
const std::string FILE_NAME = "assignment3.nc";
static const int NC_ERR = 2;
int netcdfWriter(rarray<int,2>  new_number_of_ants, int length);
