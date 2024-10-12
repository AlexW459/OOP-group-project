run: main
	./main

main: main_temp.cpp Game.cpp Game.h Branch.cpp Player.cpp Player.h Tree.cpp Branch.h Tree.h WateringAction.cpp FertilisingAction.cpp PruningAction.cpp Timeline.h WateringAction.h FertilisingAction.h Printable.h PruningAction.h Timeline.h Clickable.h
	g++ main_temp.cpp Game.cpp Branch.cpp Player.cpp Player.h Tree.cpp WateringAction.cpp FertilisingAction.cpp PruningAction.cpp Timeline.cpp -o main -I/usr/include/opencv4 -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc

test: test.cpp Game.cpp Game.h Branch.cpp Player.cpp Player.h Tree.cpp Branch.h Tree.h WateringAction.cpp FertilisingAction.cpp  PruningAction.cpp Timeline.h WateringAction.h FertilisingAction.h Printable.h PruningAction.h Timeline.h Clickable.h
	g++ test.cpp Game.cpp Branch.cpp Player.cpp Player.h Tree.cpp WateringAction.cpp FertilisingAction.cpp PruningAction.cpp Timeline.cpp -o main -I/usr/include/opencv4 -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc