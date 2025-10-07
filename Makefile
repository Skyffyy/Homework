# ==============================
#        Homework Makefile
# ==============================

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -I .

# Output directory
EXE_DIR = executable

# ==============================
#          TASKS 3
# ==============================

task3_1:
	$(CC) ./SimpleCalculator3.1.c ./mynumber.c ./mystring.c -o $(EXE_DIR)/task3_1.o $(CFLAGS)

task3_2:
	$(CC) ./SumAllNumbers3.2.c ./mynumber.c -o $(EXE_DIR)/task3_2.o $(CFLAGS)

task3_3:
	$(CC) ./NumberStatistics3.3.c ./mynumber.c -o $(EXE_DIR)/task3_3.o $(CFLAGS)

task3_4:
	$(CC) ./NumberBaseConverter3.4.c ./mynumber.c -o $(EXE_DIR)/task3_4.o $(CFLAGS)

tasks3: task3_1 task3_2 task3_3 task3_4


# ==============================
#          TASKS 4
# ==============================

task4_1:
	$(CC) ./StringLenngthCounter4.1.c ./mystring.c -o $(EXE_DIR)/task4_1.o $(CFLAGS)

task4_2:
	$(CC) ./StringOperations4.2.c ./mystring.c -o $(EXE_DIR)/task4_2.o $(CFLAGS)

task4_3:
	$(CC) ./WordSearch4.3.c ./mystring.c -o $(EXE_DIR)/task4_3.o $(CFLAGS)

tasks4: task4_1 task4_2 task4_3


# ==============================
#          TASKS 5
# ==============================

task5_1:
	$(CC) ./SimpleFlags5.1.c ./mynumber.c ./mystring.c -o $(EXE_DIR)/task5_1.o $(CFLAGS)

task5_2:
	$(CC) ./FlagswithValues5.2.c ./mynumber.c ./mystring.c -o $(EXE_DIR)/task5_2.o $(CFLAGS)

task5_3:
	$(CC) ./MixedArgumentsParser5.3.c ./mynumber.c ./mystring.c -o $(EXE_DIR)/task5_3.o $(CFLAGS)

task5_4:
	$(CC) ./ConfigurationOverride5.4.c ./mynumber.c ./mystring.c -o $(EXE_DIR)/task5_4.o $(CFLAGS)

tasks5: task5_1 task5_2 task5_3 task5_4


# ==============================
#          TASKS 6
# ==============================

task6_1:
	$(CC) ./FileDisplay6.1.c ./mynumber.c ./mystring.c -o $(EXE_DIR)/task6_1.o $(CFLAGS)

task6_2:
	$(CC) ./SimpleFileStatistics6.2.c ./mynumber.c ./mystring.c -o $(EXE_DIR)/task6_2.o $(CFLAGS)

tasks6: task6_1 task6_2


# ==============================
#          MAIN TARGETS
# ==============================

all: tasks3 tasks4 tasks5 tasks6

clean:
	rm -f $(EXE_DIR)/*.o


# ==============================
#             HELP
# ==============================

help:
	@echo ""
	@echo "=============================="
	@echo "          MAKE HELP"
	@echo "=============================="
	@echo ""
	@echo "[Usage]"
	@echo "  make <target>"
	@echo ""
	@echo "[Main targets]"
	@echo "  all       – build all tasks"
	@echo "  clean     – remove all compiled files"
	@echo "  help      – show this help menu"
	@echo ""
	@echo "[Tasks 3]"
	@echo "  task3_1 – SimpleCalculator3.1"
	@echo "  task3_2 – SumAllNumbers3.2"
	@echo "  task3_3 – NumberStatistics3.3"
	@echo "  task3_4 – NumberBaseConverter3.4"
	@echo ""
	@echo "[Tasks 4]"
	@echo "  task4_1 – StringLengthCounter4.1"
	@echo "  task4_2 – StringOperations4.2"
	@echo "  task4_3 – WordSearch4.3"
	@echo ""
	@echo "[Tasks 5]"
	@echo "  task5_1 – SimpleFlags5.1"
	@echo "  task5_2 – FlagsWithValues5.2"
	@echo "  task5_3 – MixedArgumentsParser5.3"
	@echo "  task5_4 – ConfigurationOverride5.4"
	@echo ""
	@echo "[Tasks 6]"
	@echo "  task6_1 – FileDisplay6.1"
	@echo "  task6_2 – SimpleFileStatistics6.2"
	@echo ""
	@echo "Example: make task5_3"
	@echo ""

.PHONY: all clean help \
	task3_1 task3_2 task3_3 task3_4 \
	task4_1 task4_2 task4_3 \
	task5_1 task5_2 task5_3 task5_4 \
	task6_1 task6_2 \
	tasks3 tasks4 tasks5 tasks6
