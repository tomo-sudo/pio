
cc = g++ -g -std=c++11
prom = t1
deps = $(shell find ./ -name "*.h")
src = $(shell find ./ -name "*.cpp")
obj = $(src:%.cpp=%.o) 
 
$(prom): $(obj)
	$(cc) -o $(prom) $(obj)
 
%.o: %.cpp $(deps)
	$(cc) -c $< -o $@
 
clean:
	rm -rf $(obj) $(prom)


