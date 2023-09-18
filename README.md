Easy "clone and go" repository for a libopencm3 based project.

# Instructions
 1. git clone --recurse-submodules https://github.com/libopencm3/libopencm3-template.git your-project
 2. cd your-project
 3. make -C libopencm3 # (Only needed once)
 4. make -C my-project

If you have an older git, or got ahead of yourself and skipped the ```--recurse-submodules```
you can fix things by running ```git submodule update --init``` (This is only needed once)

# Directories
* my-project contains your application
* my-common-code contains something shared.

# As a template
You should replace this with your _own_ README if you are using this
as a template.


# prerequisites
Openocd
gdb-multiarch
binutils-arm-none-eabi // confirm

# flashing commands
Work in progres:
for some reason flashing in this repository lefts uc in a reset state:
    "Can not connect to target. Please use 'connect under reset"
Workaround is to push reset button and use "make flash" after that, ecu can be reflashed via stflash or make flash.
TODO: figure out what is misconfigured in openocd settings or ld layout...

    make flash    
    st-flash write awesomesauce.bin 0x8000000
    st-flash write bin/stm32/nucleo-f446re.bin 0x8000000