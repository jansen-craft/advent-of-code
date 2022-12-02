# Generic make rules for advent 
CCFLAGS=clang++ -std=c++20 -Wall

a:
	@ echo "\tuse: make day<*>"

day% : day%.cpp
	@ $(CCFLAGS) $< -o $@-run
	@ echo "\trun: ./$@-run"

clean:
	- rm -f day*-run
