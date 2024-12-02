COMPILE = g++ -Wall -Werror -std=c++11

%: %.cpp
	$(COMPILE) $< -o $@+

clean: 
	-@rm -f */*+
