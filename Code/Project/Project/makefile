ofiles = App.o Bill.o Chef.o Customer.o Dish.o Engine.o Facade.o Floor.o Kitchen.o Manager.o Menu.o Tab.o Table.o TableIterator.o Visitor.o Waiter.o 
gpp_o = g++ -c -static

main: $(ofiles)
	g++ -static $(ofiles) -o main

App.o: Facade.h Engine.h App.cpp
	$(gpp_o) App.cpp 

Bill.o: Bill.h Table.h Bill.cpp
	$(gpp_o) Bill.cpp

Chef.o: Visitor.h Kitchen.h Waiter.h Dish.h Chef.h Chef.cpp
	$(gpp_o) Chef.cpp

Customer.o: Dish.h Table.h Bill.h Visitor.h Manager.h Customer.h Customer.cpp
	$(gpp_o) Customer.cpp

Dish.o: Menu.h Customer.h Dish.h Dish.cpp
	$(gpp_o) Dish.cpp

Engine.o: Floor.h Engine.h Engine.cpp
	$(gpp_o) Engine.cpp

Facade.o: Engine.h Facade.h Facade.cpp
	$(gpp_o) Facade.cpp

Floor.o: Customer.h Waiter.h Table.h Tab.h Manager.h Chef.h Floor.h Floor.cpp
	$(gpp_o) Floor.cpp

Kitchen.o: Floor.h Engine.h Kitchen.h Kitchen.cpp
	$(gpp_o) Kitchen.cpp

Manager.o: Visitor.h Manager.h Manager.cpp
	$(gpp_o) Manager.cpp

Menu.o: Dish.h Menu.h Menu.cpp
	$(gpp_o) Menu.cpp

Tab.o: Floor.h Tab.h Tab.cpp
	$(gpp_o) Tab.cpp

Table.o: Table.h Floor.h Table.h Table.cpp
	$(gpp_o) Table.cpp

TableIterator.o: Table.h TableIterator.h TableIterator.cpp
	$(gpp_o) TableIterator.cpp

Visitor.o: Customer.h Table.h Visitor.h Visitor.cpp
	$(gpp_o) Visitor.cpp

Waiter.o: Floor.h Chef.h Visitor.h Waiter.h Waiter.cpp
	$(gpp_o) Waiter.cpp

run: main
	./main

clean:
	rm *.o main