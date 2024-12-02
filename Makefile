COMPILE = g++ -Wall -Werror -std=c++11

%: %.cpp
	$(COMPILE) $< -o $@+

ci:
	-@rm -f l b
	touch l b

clean: 
	-@rm -f */*+ l b
