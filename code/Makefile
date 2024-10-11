run: main
	./main

main: main_temp.cpp Branch.cpp Tree.cpp Branch.h Tree.h WateringAction.cpp FertilisingAction.cpp Printable.cpp PruningAction.cpp Timeline.h WateringAction.h FertilisingAction.h Printable.h PruningAction.h Timeline.h
	g++ main.cpp Branch.cpp Tree.cpp WateringAction.cpp FertilisingAction.cpp Printable.cpp PruningAction.cpp Timeline.cpp -o main -I/usr/include/opencv4 -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc

test: test.cpp Branch.cpp Tree.cpp Branch.h Tree.h WateringAction.cpp FertilisingAction.cpp Printable.cpp PruningAction.cpp Timeline.h WateringAction.h FertilisingAction.h Printable.h PruningAction.h Timeline.h
	g++ main.cpp Branch.cpp Tree.cpp WateringAction.cpp FertilisingAction.cpp Printable.cpp PruningAction.cpp Timeline.cpp -o main -I/usr/include/opencv4 -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc