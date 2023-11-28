COMPILE = g++ -Wall -Werror -std=c++11

day%: day%.cpp
	$(COMPILE) $< -o $@+

clean: 
	-@rm -f */*+
