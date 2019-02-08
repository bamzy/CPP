# Makefile to compile netcdf read and write example

CXX=g++
CXXFLAGS=-std=c++11 -O2 -g -Wall
LDLIBS=-lnetcdf_c++4

#uncomment the following line and substutute the right path where the
#rarray header is located (if rarray header is not found)
#CPPFLAGS=-I/hereisrarray/include


all: antsontable

antsontable: antsontable.o dataInitiation.o calculateAntsStats.o printReport.o randomAntsMove.o randomizePartition.o zeroInitArray.o netcdfWriter.o
	${CXX} ${LDFLAGS} -o $@ $^ ${LDLIBS}

calculateAntsStats.o: calculateAntsStats.cc calculateAntsStats.h
	${CXX} ${CPPFLAGS} ${CXXFLAGS} -c -o $@ $<

printReport.o: printReport.cc printReport.h
	${CXX} ${CPPFLAGS} ${CXXFLAGS} -c -o $@ $<

randomAntsMove.o: randomAntsMove.cc randomAntsMove.h
	${CXX} ${CPPFLAGS} ${CXXFLAGS} -c -o $@ $<

dataInitiation.o: dataInitiation.cc dataInitiation.h
	${CXX} ${CPPFLAGS} ${CXXFLAGS} -c -o $@ $<

randomizePartition.o: randomizePartition.cc randomizePartition.h
	${CXX} ${CPPFLAGS} ${CXXFLAGS} -c -o $@ $<

zeroInitArray.o: zeroInitArray.cc zeroInitArray.h
	${CXX} ${CPPFLAGS} ${CXXFLAGS} -c -o $@ $<

netcdfWriter.o: netcdfWriter.cc netcdfWriter.h
	${CXX} ${CPPFLAGS} ${CXXFLAGS} -c -o $@ $<

	#linking object files togather 
#	g++  antsontable.o dataInitiation.o  calculateAntsStats.o printReport.o randomAntsMove.o zeroInitArray.o randomizePartition.o netcdfWriter.o -o antsontable
	#run the executable file and store the results in output.dat
#	./antsontable > output.dat

clean:
	\rm -f calculateAntsStats.o antsontable.o antsontable netcdfWriter.o zeroInitArray.o dataInitiation.o printReport.o calculateAntsStats.o randomizePartition.o randomAntsMove.o randomAntsMove.o assignment3.nc 
