CXX = g++
CXXFLAGS = -O3 -std=c++17

# Folders
SRC_DIR = ./source
TEST_DIR = ./tests
GTEST_DIR = ./external/googletest/googletest
GTEST_INC = $(GTEST_DIR)/include
GTEST_SRC = $(GTEST_DIR)/src/gtest-all.cc
GTEST_OBJ = gtest-all.o
GTEST_LIB = libgtest.a

# Output binaries
APP = program.exe
TEST_APP = runTests.exe

# === Build main app ===
all:
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/*.cpp -o $(APP)

# === Manually build GoogleTest ===
gtest:
	$(CXX) $(CXXFLAGS) -I$(GTEST_INC) -I$(GTEST_DIR) -c $(GTEST_SRC) -o $(GTEST_OBJ)
	ar rcs $(GTEST_LIB) $(GTEST_OBJ)

# === Build and run tests ===
test: gtest
	$(CXX) $(CXXFLAGS) -I$(GTEST_INC) $(TEST_DIR)/*.cpp \
    $(filter-out $(SRC_DIR)/main.cpp, $(wildcard $(SRC_DIR)/*.cpp)) \
    $(GTEST_LIB) -o $(TEST_APP)
	./$(TEST_APP)
	
# === Clean up ===
clean:
	del /Q *.exe *.o *.a 2>nul || exit 0
