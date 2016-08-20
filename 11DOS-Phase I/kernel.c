#include "include/kb.h"
#include "include/isr.h"
#include "include/idt.h"
#include "include/util.h"
#include "include/shell.h"

void kmain(){
	isr_install();
	clearScreen();
	print("--------------------------------------------------------------------------------");
	print("                   __ __ _____ _______ ______ _____ _    _  \n");
	print("                  /_ /_ |  __ \\__   __|  ____/ ____| |  | |\n");
	print("                   | || | |  | | | |  | |__ | |    | |__| |\n");
	print("                   | || | |  | | | |  |  __|| |    |  __  |\n");
	print("                   | || | |__| | | |  | |___| |____| |  | |\n");
	print("                   |_||_|_____/  |_|  |______\\_____|_|  |_|\n");
	print("--------------------------------------------------------------------------------");
	print("                              Welcome to 11DOS!\n");
	print("Please enter your command (Enter 'help' for list of commands)\n");              
	launch_shell(0);
}
