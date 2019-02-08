#ifndef TEMP4DPARAMETERSH
#define TEMP4DPARAMETERSH

#include <string>

// This is the name of the data file we will create. 


// We are writing 4D data, a 2 x 6 x 12 lvl-lat-lon grid, with 2
// timesteps of data.
const int NLVL = 2;
const int NLAT = 6;
const int NLON = 12;
const int NREC = 2;

// Names of things. 
const std::string LVL_NAME = "level";
const std::string LAT_NAME = "latitude";
const std::string LON_NAME = "longitude";
const std::string REC_NAME = "time";
const std::string TEMP_NAME = "temperature";

// These are used to construct some example data. 
const float SAMPLE_TEMP = 9.0;
const float START_LAT = 25.0;
const float START_LON = -125.0;

const std::string UNITS = "units";
const std::string DEGREES_EAST =  "degrees_east";
const std::string DEGREES_NORTH = "degrees_north";

// For the units attributes. 
const std::string TEMP_UNITS = "celsius";
const std::string LAT_UNITS = "degrees_north";
const std::string LON_UNITS = "degrees_east";

#endif
