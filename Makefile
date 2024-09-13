run: main
	./main

main: main.cpp
	g++ main.cpp -o main -I/usr/include/opencv4 -lopencv_core -lopencv_highgui -lopencv_imgcodecs