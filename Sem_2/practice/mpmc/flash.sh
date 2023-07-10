avr-gcc -g -mmcu=atmega328p -o main.elf $1
avr-objcopy -j .text -j .data -O ihex main.elf main.hex
sudo avrdude -v -c arduino -p atmega328p -P /dev/ttyACM0 -b 115200 -D -U flash:w:main.hex:i