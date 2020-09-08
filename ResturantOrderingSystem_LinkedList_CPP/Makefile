pex2: main.o Orders_List.o
        g++ main.o Load_Orders.o -o pex2

main.o: main.cpp Orders_List.h
        g++ -c main.cpp

Orders_List.o: Orders_List.cpp Orders_List.h
        g++ -c Orders_List.cpp

clean:
        rm *.o pex2
