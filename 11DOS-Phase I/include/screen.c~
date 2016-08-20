#include "screen.h"

int cursorX = 0, cursorY = 0;
const uint8 sw = 80, sh = 25, sd = 2;	//define screen width, height and depth
int color = 0x0F;	//system color

void clearLine(uint8 from, uint8 to){
	uint16 i = sw * from * sd;			//start of clearing address
	string vidmem = (string)0xb8000;	//address of the start of video memory
	for(i;i<(sw*to*sd);i++){	
		vidmem[i] = 0x0;					//set cleared address to zero
	}
}

void updateCursor(){						//0x3D4 and 0x3D5 are cursor position port in X86
	unsigned temp;
	temp = cursorY * sw + cursorX;	//position = y*screen width + x
	outportb(0x3D4, 14);					//CRT control register: select cursor location
	outportb(0x3D5, temp >> 8);		//send high byte to port
	outportb(0x3D4, 15);					//CRT control register: select low byte
	outportb(0x3D5, temp);				//send low byte to port
}

void clearScreen(){
	clearLine(0,sh-1);
	cursorX = 0;
	cursorY = 0;
	updateCursor();
}

void scrollUp(uint8 lineNumber){
	string vidmem = (string)0xb8000;
	uint16 i = 0;
	for (i;i<sw*(sh-1)*sd;i++){
		vidmem[i] = vidmem[i+sw*sd*lineNumber];	//move the screen up by lineNumber
	}
	clearLine(sh-1-lineNumber, sh-1);				//clear the cleared lines
	if((cursorY - lineNumber) < 0){					//prevent cursor to go off screen
		cursorX = 0;
		cursorY = 0;
	}else{
		cursorY -= lineNumber;
	}
	updateCursor();
}

void newLineCheck(){				//scroll up is the new line goes off screen
	if(cursorY >= sh-1){
		scrollUp(1);	
	}
}

void printch(char c){
	string vidmem = (string) 0xb8000;
	switch(c){
		case (0x08):	//backspace
			if(cursorX > 0){ //ignore if cursorX = 0
				cursorX--;	//move the cursor back by 1
				vidmem[(cursorY*sw+cursorX)*sd] = 0x00;	//delete the last char			
			}
			break;
		case (0x09):	//tab
			cursorX = (cursorX + 8)&~(8-1);	//move the cursor by 
			break;
		case ('\r'):	//carriage return
			cursorX = 0;
			break;
		case ('\n'):	//new line
			cursorX = 0;
			cursorY++;
			break;
		default:		//by default, print the character c and make next 
			vidmem[(cursorY*sw+cursorX)*sd] = c;
			vidmem[(cursorY*sw+cursorX)*sd+1] = 0x0F;
			cursorX++;
			break;
	}
	if(cursorX >= sw){	//move to next line if reaches the end
		cursorX = 0;
		cursorY++;
	}
	newLineCheck();
	updateCursor();
}

void print(string ch){
	uint16 i = 0;
	uint8 length = strlength(ch);
	for(i;i<length;i++){
		printch(ch[i]);	
	}
}
