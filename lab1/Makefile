CPPFLAGS = -std=c++11
all: main.exe

# name of rule/target: list of dependent files
main.exe: openningMessage.o main.o QA.o	
	g++ -o $@ $(CPPFLAGS) openningMessage.o main.o QA.o

# meta rule: generate any_name.o file
# any .o file depends on its corresponding .cpp file
%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@ 

clean:
	del  *.o *.exe
# On Windows, use: del *.o *.exe
# On Linux or MacOS, use: rm -f *.o *.exe

depend:
	path\to\UnxUtils\usr\local\wbin\makedepend -o.o $(SRCS)

#haha
