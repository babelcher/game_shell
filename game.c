#include <msp430g2553.h>
#include "game.h"
#include "../LCD/LCD.h"

/*
 * Created: 10 Nov 2013
 * Author: C15Brandon.Belcher
 * Description: Implements the logic behind the
 * game display on the LCD in the black box in Lab 5
 * of ECE 382.
 */
unsigned char initPlayer() {
	return 0x80;
}

void printPlayer(unsigned char player) {
	writeCommandByte(player);
	writeDataByte('*');
}

void clearPlayer(unsigned char player) {
	writeCommandByte(player);
	writeDataByte(' ');
}

//move the player according to which button was pressed
unsigned char movePlayer(unsigned char player, unsigned char direction) {
	switch (direction) {
	case UP:
		if (player >= 0xC0 && player <= 0xC7) {
			player -= 0x40;
		}
		break;
	case DOWN:
		if (player >= 0x80 && player <= 0x87) {
			player += 0x40;
		}
		break;
	case LEFT:
		if ((player > 0x80 && player <= 0x87) || (player > 0xC0 && player <= 0xC7)) {
			player -= 0x01;
		}
		break;
	case RIGHT:
		if ((player >= 0x80 && player < 0x87) || (player >= 0xC0 && player < 0xC7)) {
			player += 0x01;
		}
		break;

	}

	return player;
}

//check to see if the player is the bottom left block of the LCD
char didPlayerWin(unsigned char player) {
	return player == 0xC7;
}
