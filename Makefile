### CSCI561 - Fall 2014 - Sample Makefile

### Example for a C++ agent:
agent: main.cpp
	g++ main.cpp -o agent

run: agent
	./agent
