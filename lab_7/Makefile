.PHONY: all build run test clean

BUILD_DIR = build

MAIN_EXEC = main_lab7
TEST_EXEC = tests_lab7

CMAKE = cmake
MAKE = make
RM = rm -rf

all: build

build: clean
	@echo "Создание директории сборки..."
	$(CMAKE) -S . -B $(BUILD_DIR)
	$(MAKE) -C $(BUILD_DIR)

run:
	@echo "Запуск основного приложения..."
	./$(BUILD_DIR)/$(MAIN_EXEC)

test:
	@echo "Запуск тестов..."
	./$(BUILD_DIR)/$(TEST_EXEC)

clean:
	@echo "Очистка директории сборки..."
	$(RM) $(BUILD_DIR)
