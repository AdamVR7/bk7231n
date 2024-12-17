# Минимальная версия CMake
cmake_minimum_required(VERSION 3.10)

# Название проекта
project(BK7231N_Firmware C ASM)

# Определение используемой toolchain
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)

# Установка флагов компиляции
set(COMPILE_FLAGS "-mcpu=cortex-m3 -mthumb -O2 -Wall -ffunction-sections -fdata-sections")
set(LINKER_FLAGS "-T ${CMAKE_SOURCE_DIR}/link.ld -Wl,--gc-sections")

# Добавление исходников
set(SRC_FILES
    ${CMAKE_SOURCE_DIR}/main.c
    ${CMAKE_SOURCE_DIR}/system.c
    ${CMAKE_SOURCE_DIR}/os_api.c
)

# Установка флагов для сборки
add_executable(firmware.elf ${SRC_FILES})
target_compile_options(firmware.elf PRIVATE ${COMPILE_FLAGS})
target_link_options(firmware.elf PRIVATE ${LINKER_FLAGS})

# Генерация бинарного файла из ELF
add_custom_command(TARGET firmware.elf POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary firmware.elf firmware.bin
    COMMENT "Converting ELF to BIN"
)
