
# This is what the board identifies as for rebooting
PORT=/dev/ttyUSB0

# What the board is
BOARD=arduino:avr:nano


# Targets:
#
#     make          
#         Compile the ino
#
#     make install
#         Compile the ino and upload it to the board
#
#     make watch
#         Wait for changes to the file and compile automatically. Requires
#         `entr` to operate (sudo apt install entr)
#
#     make clean
#         Delete the build folder

SKETCH=$(shell basename $$(pwd))
INO=${SKETCH}.ino
SUBDIR=$(subst :,.,${BOARD})
BIN=build/${SUBDIR}/${SKETCH}.ino.hex
ELF=build/${SUBDIR}/${SKETCH}.ino.elf
MAP=build/${SUBDIR}/${SKETCH}.ino.map

${BIN}: ${INO} 
	@echo "Sketch is" ${INO}
	@arduino-cli compile -b ${BOARD} ${SKETCH}


install: ${BIN}
	arduino-cli upload -b ${BOARD} -p ${PORT}

clean:
	@rm -rf build

watch:
	@echo ${INO} | entr -c -s 'make'

