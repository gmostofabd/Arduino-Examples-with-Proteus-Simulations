/*
 * _7seg_max7219.h
 *
 * Created: 6/13/2021 12:24:48 PM
 *  Author: Adithya
 */ 

// This is the library that used for 7 segment LED display.....

#ifndef MAX7219_H_7SEG
#define MAX7219_H_7SEG

#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>

#ifndef	MAX7219_DIN_PIN_7SEG	
#define  MAX7219_DIN_PIN_7SEG		PB3
#endif	/* !MAX7219_DIN_PIN */

#ifndef	MAX7219_CLK_PIN_7SEG
# define	MAX7219_CLK_PIN_7SEG	PB5
#endif	/* !MAX7219_CLK_PIN */

#ifndef	MAX7219_CS_PIN_7SEG
# define	MAX7219_CS_PIN_7SEG		PB4
#endif	/* !MAX7219_CS_PIN */

/**
 * Initialize display driver.
 * Clock pin, data pin and chip select pin
 * are defined at the top of this file.
 */
void MAX7219_init_7SEG(void);

/**
 * Set status of a single pixel.
 * @param row: row number from range <0, 7>
 * @param col: column number from range <0, 7>
 */
void MAX7219_set_pixel_7SEG(uint8_t row, uint8_t col, bool value);

/**
 * Set all 8 LEDs in a row.
 * @param row: row number from range <0, 7>
 * @param value: row value (each bit represents a LED in a row, i.e. 0b00001111)
 */
void MAX7219_set_row_7SEG(uint8_t row, uint8_t value);

/**
 * Set all 8 LEDs in a column.
 * @param column: column number from range <0, 7>
 * @param value: column value (each bit represents a LED in a column, i.e. 0b00001111)
 */
void MAX7219_set_column_7SEG(uint8_t column, uint8_t value);

/**
 * Set brightness of the display.
 * @param value: intensity from range <0, 15>
 */
void MAX7219_set_intensity_7SEG(uint8_t value);

/**
 * Clear display. 
 */
void MAX7219_clear_7SEG(void);

#define MAX7219_REG_NOOP                (0x00)
#define MAX7219_REG_DIGIT0              (0x01)
#define MAX7219_REG_DIGIT1              (0x02)
#define MAX7219_REG_DIGIT2              (0x03)
#define MAX7219_REG_DIGIT3              (0x04)
#define MAX7219_REG_DIGIT4              (0x05)
#define MAX7219_REG_DIGIT5              (0x06)
#define MAX7219_REG_DIGIT6          (0x07)
#define MAX7219_REG_DIGIT7          (0x08)
#define MAX7219_REG_DECODEMODE		(0x09)
#define MAX7219_REG_INTENSITY		(0x0A)
#define MAX7219_REG_SCANLIMIT		(0x0B)
#define MAX7219_REG_SHUTDOWN		(0x0C)
#define MAX7219_REG_DISPLAYTEST		(0x0F)

#define MAX7219_DIN_HIGH()              (PORTB |= _BV(MAX7219_DIN_PIN_7SEG))
#define MAX7219_DIN_LOW()               (PORTB &= ~_BV(MAX7219_DIN_PIN_7SEG))
#define MAX7219_CLK_HIGH()              (PORTB |= _BV(MAX7219_CLK_PIN_7SEG))
#define MAX7219_CLK_LOW()               (PORTB &= ~_BV(MAX7219_CLK_PIN_7SEG))
#define MAX7219_CS_HIGH()               (PORTB |= _BV(MAX7219_CS_PIN_7SEG))
#define MAX7219_CS_LOW()                (PORTB &= ~_BV(MAX7219_CS_PIN_7SEG))

static uint8_t MAX7219_state_7SEG[8] = {0, 0, 0, 0, 0, 0, 0, 0};

static void MAX7219_write_7SEG(uint8_t value)
{
	uint8_t i;

	__asm("nop");
	for (i = 0; i < 8; ++i, value <<= 1) {
		MAX7219_CLK_LOW();
		__asm("nop");
		if (value & 0x80) {
			MAX7219_DIN_HIGH();
			} else {
			MAX7219_DIN_LOW();
		}
		MAX7219_CLK_HIGH();
	}
}

static void MAX7219_send_7SEG(uint8_t reg, uint8_t data)
{

	MAX7219_CS_HIGH();
	MAX7219_write_7SEG(reg);
	MAX7219_write_7SEG(data);
	MAX7219_CS_LOW();
	__asm("nop");
	MAX7219_CS_HIGH();
}

void MAX7219_init_7SEG(void)
{

	DDRB |= _BV(MAX7219_DIN_PIN_7SEG)|_BV(MAX7219_CLK_PIN_7SEG)|_BV(MAX7219_CS_PIN_7SEG);
	MAX7219_send_7SEG(MAX7219_REG_DECODEMODE, 0x00);
	MAX7219_send_7SEG(MAX7219_REG_SCANLIMIT, 0x07);
	MAX7219_send_7SEG(MAX7219_REG_INTENSITY, 0x0f);
	MAX7219_send_7SEG(MAX7219_REG_DISPLAYTEST, 0x00);
	MAX7219_send_7SEG(MAX7219_REG_SHUTDOWN, 0x01);
}

void MAX7219_set_pixel_7SEG(uint8_t row, uint8_t col, bool value)
{
	uint8_t data;

	if (row > 7 || col > 7)
	return;

	data = 1 << col;
	if (value) {
		MAX7219_state_7SEG[row] |= data;
		} else {
		MAX7219_state_7SEG[row] &= ~data;
	}

	MAX7219_send_7SEG(row + 1, MAX7219_state_7SEG[row]);
}

void MAX7219_set_row_7SEG(uint8_t row, uint8_t value)
{

	if (row > 7)
	return;

	MAX7219_state_7SEG[row] = value;
	MAX7219_send_7SEG(row + 1, value);
}

void MAX7219_set_column_7SEG(uint8_t column, uint8_t value)
{
	uint8_t i;

	if (column > 7)
	return;

	for (i = 0; i < 8; ++i) {
		MAX7219_set_pixel_7SEG(i, column, !!((value >> i) & 0x01));
	}
}

void MAX7219_set_intensity_7SEG(uint8_t value)
{

	if (value > 15)
	return;

	MAX7219_send_7SEG(MAX7219_REG_INTENSITY, value);
}

void MAX7219_clear_7SEG(void)
{
	uint8_t i;

	for (i = 0; i < 8; ++i) {
		if (MAX7219_state_7SEG[i]) {
			MAX7219_state_7SEG[i] = 0;
			MAX7219_send_7SEG(i + 1, 0);
		}
	}
}




#endif /* 7SEG_MAX7219_H_ */
