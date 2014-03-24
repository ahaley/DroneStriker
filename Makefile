DIR = DroneStroker.CLI
FILES = $(DIR)/DroneStriker.cpp \
				$(DIR)/Target.cpp \
				$(DIR)/DroneStroker.CLI.cpp
CFLAGS = `pkg-config --cflags opencv`
LIBS = `pkg-config --libs opencv`

all:
	g++ $(CFLAGS) $(LIBS) $(FILES) -o DroneStriker
				
