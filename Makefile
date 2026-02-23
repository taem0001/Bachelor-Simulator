CXX        = g++
INC_DIR    = simulator/include
CXXFLAGS   = -std=c++20 -Wall -Wextra -I$(INC_DIR)

SRC_DIR   = simulator/src
TEST_DIR  = tests
OBJ_DIR   = build
BIN_DIR   = bin

TARGET_SIM  = $(BIN_DIR)/sim
TARGET_TEST = $(BIN_DIR)/test

SIM_MAIN   = $(SRC_DIR)/main.cpp
SIM_SRCS   = $(filter-out $(SIM_MAIN), $(wildcard $(SRC_DIR)/*.cpp))
TEST_SRCS  = $(wildcard $(TEST_DIR)/*.cpp) $(wildcard $(TEST_DIR)/unit/*.cpp)

SIM_OBJS   = $(SIM_SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
SIM_MAIN_O = $(OBJ_DIR)/main.o
TEST_OBJS  = $(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR)/test_%.o,$(TEST_SRCS))

all: simulator

simulator: $(TARGET_SIM)

tests: $(TARGET_TEST)

$(TARGET_SIM): $(SIM_OBJS) $(SIM_MAIN_O) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TARGET_TEST): $(SIM_OBJS) $(TEST_OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/test_%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I$(TEST_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(BIN_DIR)

re: fclean all

.PHONY: all simulator tests clean fclean re