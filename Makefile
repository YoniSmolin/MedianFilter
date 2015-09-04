MedianFilter: MainProgram.cpp MedianFilterGPU.o MedianFilterCPU.o
	nvcc -g MainProgram.cpp MedianFilterGPU.o MedianFilterCPU.o -lopencv_core -lopencv_imgproc -lopencv_highgui --pre-include MedianFilters.hpp -o MainProgram 

MedianFilterCPU.o: MedianFilterCPU.cpp MedianFilters.hpp
	g++ -g -Wall -c MedianFilterCPU.cpp 
	
MedianFilterGPU.o: MedianFilterGPU.cu MedianFilters.hpp
	nvcc -g -c MedianFilterGPU.cu 

clean:
	rm -f *.o MedianProgram
