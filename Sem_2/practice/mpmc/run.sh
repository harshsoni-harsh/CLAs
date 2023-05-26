# gnome-terminal --command="avr-gcc -g -mmcu=atmega328p -o main.elf array_transfer.S"


# gnome-terminal --command="simavr -g -m atmega328p main.elf"


gnome-terminal --tab --title="tab 1" --command="bash -c 'avr-gcc -g -mmcu=atmega328p -o main.elf array_transfer.S; simavr -g -m atmega328p main.elf; $SHELL'"  --tab --title="tab 2" --command="bash -c 'avr-gdb main.elf; target remote localhost:1234; tui enable; $SHELL'"
