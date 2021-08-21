/* 
 * File:   Oled.h
 * Author: dev-user
 *
 * Created on October 30, 2020, 10:07 AM
 */

#ifndef OLED_H
#define	OLED_H

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef __PIC32M
#include "../IncSystemDefs/PICDEFS32.h"
#include "../Lib32Peripherals.X/I2C.h"
#else
#include "../IncSystemDefs/PICDEFS.h"
#include "../LibPeripherals.X/i2c.h"
#endif
    
#ifdef __USE_OLEDDISP__
#define swap(a, b) { int16_t t = a; a = b; b = t; }
    
#define BLACK 0
#define WHITE 1
#define INVERSE 2
    
#define SSD1306_LCDWIDTH                  128
#define SSD1306_LCDHEIGHT                 64

//fundamental commands from DS Table 9-1, page 28
#define SSD1306_SETCONTRAST 0x81
#define SSD1306_DISPLAYALLON_RESUME 0xA4
#define SSD1306_DISPLAYALLON 0xA5
#define SSD1306_NORMALDISPLAY 0xA6
#define SSD1306_INVERTDISPLAY 0xA7
#define SSD1306_DISPLAYOFF 0xAE
#define SSD1306_DISPLAYON 0xAF
    
//HW Config Commands from DS Table 9-1, page 31
#define SSD1306_SETSTARTLINE 0x40       //0x40 - 0x7F, set display start line, low 6 bits indicate start line, resets to 0x00
#define SSD1306_SEGREMAP 0xA0           //0xA0/0xA1, set segment re-map, A0 = column addr 0 mapped to SEG0, 0xA1 = column addr 127 is mapped to SEG0
#define SSD1306_SETMULTIPLEX 0xA8       //0xA8 + data byte, Low 6 bits of data byte are used for setting multiplex ratio
#define SSD1306_COMSCANINC 0xC0         //COM Output Direction, normal, increment from COM0 to COM[N-1]
#define SSD1306_COMSCANDEC 0xC8         //COM Output Direction, invers, decrement from COM[N-1] to COM0
#define SSD1306_SETDISPLAYOFFSET 0xD3   //0xD3 + data byte, Display Offset, set vertical shift by COM from 0 - 63, reset value is 0
#define SSD1306_SETCOMPINS 0xDA         //0xDA + data byte, Set COM Pins HW Cfg, data byte can be 0b00XX0010, A4 = 0 -> Sequential COM pin cfg, A4 = 1 -> Alt COM pin cfg (reset value)
                                        //      A5 = 0 -> Disable COM Left/Right Remap (reset value), A5 = 1 -> Enable COM Left/Right Remap
//Timing and Driving Scheme Setting Commands from DS Table 9-1, page 32
#define SSD1306_SETDISPLAYCLOCKDIV 0xD5 //0xD5 + data byte, Display Clock Divider ratio, Bits [7:4] set osc freq, Bits [3:0] set divider, defaults to middle freq with 1:1 divider
#define SSD1306_SETPRECHARGE 0xD9       //0xD9 + data byte, Set Pre-Charge Period, Bits [7:4] set phase 2 period, Bits [3:0] set phase 1 period, both can go up to 15 DCLKs, 0 is invalid for both
#define SSD1306_SETVCOMDETECT 0xDB      //0xDB + data byte, Set Vcomh Deselect Level, data byte is 0b0XXX0000, A[6:4] == 000 -> 0.6VCC, 010 -> 0.77VCC (reset value), 011 -> 0.83VCC
#define SSD1306_NOP 0xE3                //No Operation command

//Address Setting Commands from DS Table 9-1, page 30
#define SSD1306_SETLOWCOLUMN 0x00       //Valid 0-F, set lower nibble of column start address register for page addressing mode using X[3:0] as data bits, (only for page addressing mode)
#define SSD1306_SETHIGHCOLUMN 0x10      //Valid 0x10-0x1F, set higher nibble of column start address register for page addressing mode using X[3:0] as data bits, (only for page addressing mode)
#define SSD1306_MEMORYMODE 0x20         //0x20 + data byte, Only Bits [1:0] in data byte are valid, 00 -> Horizontal addressing mode, 01 -> vertical addressing mode, 10 -> page addressing mode (reset value), 11 -> invalid
#define SSD1306_COLUMNADDR 0x21         //0x21 + data byte 1 + data byte 2, set column start and end addresses, first data byte is start address, second is end address, 0-127 valid for both, only valid in H or V addressing mode (reset values are start:0 end:127)
#define SSD1306_PAGEADDR   0x22         //0x22 + data byte 1 + data byte 2, set page start and end addresses, first data byte is start address, second is end addres, 0-7 valid for both, only valid in H or V addressing mode (reset value is start:0 end:7)
#define SSD1306_PAGESTARTADDR 0xB0      //Command is 0xB0-0xB7 where low 3 bits select page start address for page addressing mode, only valid in page addressing mode
    
//Scroll Setting Commands from DS Table 9-1, page 28
#define SSD1306_RIGHT_HORIZONTAL_SCROLL 0x26    //0x26 + 6 data bytes (A-F), Right Horizontal Scroll
#define SSD1306_LEFT_HORIZONTAL_SCROLL 0x27     //0x27 + 6 data bytes (A-F), Left Horizontal Scroll
#define SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 0x29   //0x29 + 6 data bytes (A-F), Vertical and Right Horizontal Scroll
#define SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL 0x2A    //0x2A + 6 data bytes (A-F), Vertical and Left Horizontal Scroll
                                                //  Databytes A,E&F: Dummy, must be 0x00, 0x00 and 0xFF respectively
                                                //  Databyte B: Define Scroll Start Page Address, values 0-7 select pages 0-7 respectively
                                                //  Databyte B: Define Time Interval between each scroll step in frame freq, 0->5fr, 1->64fr, 2->128fr, 3->256fr, 4->3fr, 5->4fr, 6->25fr & 7->2fr
                                                //  Databyte B: Define Scroll End Page Address, values 0-7 select pages 0-7 respectively
#define SSD1306_DEACTIVATE_SCROLL 0x2E          //0x2E, Deactivate Scroll, turn off autoscroll system
#define SSD1306_ACTIVATE_SCROLL 0x2F            //0x2F, Activate Scroll, turn on autoscroll system
#define SSD1306_SET_VERTICAL_SCROLL_AREA 0xA3   //0xA3 + data byte 1 + data byte 2, Vertical Scroll Area, Data byte 1 sets number of rows in top fixed area, Data byte 2 sets number of rows to scroll

//Charge Pump Commands from DS Table 2.1, page 62 (appended appnote at end of document)
#define SSD1306_CHARGEPUMP 0x8D         //0x8D + data byte, data byte can only be 0x10 or 0x14 for disable or enable chargepump
#define SSD1306_EXTERNALVCC 0x10        //available data byte for disabling charge pump
#define SSD1306_SWITCHCAPVCC 0x14       //available data byte for enabling charge pump
                                        //      charge pump enable must follow sequence: (starting from display off) write 0x8D, 0x14, 0xAF
    
uint8_t  oled_addr;
bool     oled_extvcc;
uint8_t  oled_cmd_data[6];    //max number of databytes is 6 for scrolling commands
STATUS_T OledInit(uint8_t setAddr, bool isExtVcc);
STATUS_T OledCmd(uint8_t cmd, uint8_t dataCnt);

STATUS_T OledClearDisplay(void);
STATUS_T OledWriteDisplay(void);
STATUS_T OledWriteDisplayFixed(uint8_t screenVal);
STATUS_T OledInvertDisplay(bool i);
STATUS_T OledDim(bool dim);

// Scrolling Routines

STATUS_T OledStartScrollRight(uint8_t start, uint8_t stop);
STATUS_T OledStartScrollLeft(uint8_t start, uint8_t stop);
STATUS_T OledStartScrollDiagRight(uint8_t start, uint8_t stop);
STATUS_T OledStartScrollDiagLeft(uint8_t start, uint8_t stop);
STATUS_T OledStopScroll(void);

// Drawing Routines

STATUS_T OledDrawPixel(int16_t x, int16_t y, uint16_t color);
STATUS_T OledDrawChar(int16_t x, int16_t y, unsigned char c, uint16_t  color, uint16_t bg, uint8_t size);
STATUS_T OledDrawString(uint8_t x, uint8_t y, char* str, bool apply);
STATUS_T OledDrawStringWrap(uint8_t x, uint8_t y, char* str);
STATUS_T OledDrawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);
STATUS_T OledDrawFastHLineInternal(int16_t x, int16_t y, int16_t w, uint16_t color);
STATUS_T OledDrawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
STATUS_T OledDrawFastVLineInternal(int16_t x, int16_t __y, int16_t __h, uint16_t color);
STATUS_T OledDrawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
STATUS_T OledDrawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
STATUS_T OledFillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
STATUS_T OledFillScreen(uint16_t color);
STATUS_T OledDrawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
STATUS_T OledDrawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t color);
STATUS_T OledFillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
STATUS_T OledFillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint16_t color);
STATUS_T OledDrawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
STATUS_T OledFillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
STATUS_T OledDrawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color);
STATUS_T OledFillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color);
STATUS_T OledDrawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color, uint16_t bg);    //Unverified as of 10/31/20
STATUS_T OledDrawXBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color);                //Unverified as of 10/31/20

STATUS_T OledDrawGlobe(void);

static const unsigned char font[] = {
	0x00, 0x00, 0x00, 0x00, 0x00,   //0-4
	0x3E, 0x5B, 0x4F, 0x5B, 0x3E,   //5-9
	0x3E, 0x6B, 0x4F, 0x6B, 0x3E,   //10-14
	0x1C, 0x3E, 0x7C, 0x3E, 0x1C,   //15-19
	0x18, 0x3C, 0x7E, 0x3C, 0x18,   //20-24
	0x1C, 0x57, 0x7D, 0x57, 0x1C,
	0x1C, 0x5E, 0x7F, 0x5E, 0x1C,   //30-34
	0x00, 0x18, 0x3C, 0x18, 0x00,
	0xFF, 0xE7, 0xC3, 0xE7, 0xFF,   //40-44
	0x00, 0x18, 0x24, 0x18, 0x00,
	0xFF, 0xE7, 0xDB, 0xE7, 0xFF,   //50-54
	0x30, 0x48, 0x3A, 0x06, 0x0E,
	0x26, 0x29, 0x79, 0x29, 0x26,   //60-64
	0x40, 0x7F, 0x05, 0x05, 0x07,
	0x40, 0x7F, 0x05, 0x25, 0x3F,   //70-74
	0x5A, 0x3C, 0xE7, 0x3C, 0x5A,
	0x7F, 0x3E, 0x1C, 0x1C, 0x08,   //80-84
	0x08, 0x1C, 0x1C, 0x3E, 0x7F,
	0x14, 0x22, 0x7F, 0x22, 0x14,   //90-94
	0x5F, 0x5F, 0x00, 0x5F, 0x5F,
	0x06, 0x09, 0x7F, 0x01, 0x7F,   //100-104
	0x00, 0x66, 0x89, 0x95, 0x6A,
	0x60, 0x60, 0x60, 0x60, 0x60,   //110-114
	0x94, 0xA2, 0xFF, 0xA2, 0x94,
	0x08, 0x04, 0x7E, 0x04, 0x08,   //120-124
	0x10, 0x20, 0x7E, 0x20, 0x10,
	0x08, 0x08, 0x2A, 0x1C, 0x08,   //130-134
	0x08, 0x1C, 0x2A, 0x08, 0x08,
	0x1E, 0x10, 0x10, 0x10, 0x10,   //140-144
	0x0C, 0x1E, 0x0C, 0x1E, 0x0C,
	0x30, 0x38, 0x3E, 0x38, 0x30,   //150-154
	0x06, 0x0E, 0x3E, 0x0E, 0x06,
	0x00, 0x00, 0x00, 0x00, 0x00,   //160-164
	0x00, 0x00, 0x5F, 0x00, 0x00,
	0x00, 0x07, 0x00, 0x07, 0x00,   //170-174
	0x14, 0x7F, 0x14, 0x7F, 0x14,
	0x24, 0x2A, 0x7F, 0x2A, 0x12,   //180-184
	0x23, 0x13, 0x08, 0x64, 0x62,
	0x36, 0x49, 0x56, 0x20, 0x50,   //190-194
	0x00, 0x08, 0x07, 0x03, 0x00,
	0x00, 0x1C, 0x22, 0x41, 0x00,   //200-204
	0x00, 0x41, 0x22, 0x1C, 0x00,
	0x2A, 0x1C, 0x7F, 0x1C, 0x2A,   //210-214
	0x08, 0x08, 0x3E, 0x08, 0x08,
	0x00, 0x80, 0x70, 0x30, 0x00,   //220-224
	0x08, 0x08, 0x08, 0x08, 0x08,
	0x00, 0x00, 0x60, 0x60, 0x00,   //230-234
	0x20, 0x10, 0x08, 0x04, 0x02,
	0x3E, 0x51, 0x49, 0x45, 0x3E,   //240-244
	0x00, 0x42, 0x7F, 0x40, 0x00,
	0x72, 0x49, 0x49, 0x49, 0x46,   //250-254
	0x21, 0x41, 0x49, 0x4D, 0x33,
	0x18, 0x14, 0x12, 0x7F, 0x10,
	0x27, 0x45, 0x45, 0x45, 0x39,
	0x3C, 0x4A, 0x49, 0x49, 0x31,
	0x41, 0x21, 0x11, 0x09, 0x07,
	0x36, 0x49, 0x49, 0x49, 0x36,
	0x46, 0x49, 0x49, 0x29, 0x1E,
	0x00, 0x00, 0x14, 0x00, 0x00,
	0x00, 0x40, 0x34, 0x00, 0x00,
	0x00, 0x08, 0x14, 0x22, 0x41,
	0x14, 0x14, 0x14, 0x14, 0x14,
	0x00, 0x41, 0x22, 0x14, 0x08,
	0x02, 0x01, 0x59, 0x09, 0x06,
	0x3E, 0x41, 0x5D, 0x59, 0x4E,
	0x7C, 0x12, 0x11, 0x12, 0x7C,
	0x7F, 0x49, 0x49, 0x49, 0x36,
	0x3E, 0x41, 0x41, 0x41, 0x22,
	0x7F, 0x41, 0x41, 0x41, 0x3E,
	0x7F, 0x49, 0x49, 0x49, 0x41,
	0x7F, 0x09, 0x09, 0x09, 0x01,
	0x3E, 0x41, 0x41, 0x51, 0x73,
	0x7F, 0x08, 0x08, 0x08, 0x7F,
	0x00, 0x41, 0x7F, 0x41, 0x00,
	0x20, 0x40, 0x41, 0x3F, 0x01,
	0x7F, 0x08, 0x14, 0x22, 0x41,
	0x7F, 0x40, 0x40, 0x40, 0x40,
	0x7F, 0x02, 0x1C, 0x02, 0x7F,
	0x7F, 0x04, 0x08, 0x10, 0x7F,
	0x3E, 0x41, 0x41, 0x41, 0x3E,
	0x7F, 0x09, 0x09, 0x09, 0x06,
	0x3E, 0x41, 0x51, 0x21, 0x5E,
	0x7F, 0x09, 0x19, 0x29, 0x46,
	0x26, 0x49, 0x49, 0x49, 0x32,
	0x03, 0x01, 0x7F, 0x01, 0x03,
	0x3F, 0x40, 0x40, 0x40, 0x3F,
	0x1F, 0x20, 0x40, 0x20, 0x1F,
	0x3F, 0x40, 0x38, 0x40, 0x3F,
	0x63, 0x14, 0x08, 0x14, 0x63,
	0x03, 0x04, 0x78, 0x04, 0x03,
	0x61, 0x59, 0x49, 0x4D, 0x43,
	0x00, 0x7F, 0x41, 0x41, 0x41,
	0x02, 0x04, 0x08, 0x10, 0x20,
	0x00, 0x41, 0x41, 0x41, 0x7F,
	0x04, 0x02, 0x01, 0x02, 0x04,
	0x40, 0x40, 0x40, 0x40, 0x40,
	0x00, 0x03, 0x07, 0x08, 0x00,
	0x20, 0x54, 0x54, 0x78, 0x40,
	0x7F, 0x28, 0x44, 0x44, 0x38,
	0x38, 0x44, 0x44, 0x44, 0x28,
	0x38, 0x44, 0x44, 0x28, 0x7F,
	0x38, 0x54, 0x54, 0x54, 0x18,
	0x00, 0x08, 0x7E, 0x09, 0x02,
	0x18, 0xA4, 0xA4, 0x9C, 0x78,
	0x7F, 0x08, 0x04, 0x04, 0x78,
	0x00, 0x44, 0x7D, 0x40, 0x00,
	0x20, 0x40, 0x40, 0x3D, 0x00,
	0x7F, 0x10, 0x28, 0x44, 0x00,
	0x00, 0x41, 0x7F, 0x40, 0x00,
	0x7C, 0x04, 0x78, 0x04, 0x78,
	0x7C, 0x08, 0x04, 0x04, 0x78,
	0x38, 0x44, 0x44, 0x44, 0x38,
	0xFC, 0x18, 0x24, 0x24, 0x18,
	0x18, 0x24, 0x24, 0x18, 0xFC,
	0x7C, 0x08, 0x04, 0x04, 0x08,
	0x48, 0x54, 0x54, 0x54, 0x24,
	0x04, 0x04, 0x3F, 0x44, 0x24,
	0x3C, 0x40, 0x40, 0x20, 0x7C,
	0x1C, 0x20, 0x40, 0x20, 0x1C,
	0x3C, 0x40, 0x30, 0x40, 0x3C,
	0x44, 0x28, 0x10, 0x28, 0x44,
	0x4C, 0x90, 0x90, 0x90, 0x7C,
	0x44, 0x64, 0x54, 0x4C, 0x44,
	0x00, 0x08, 0x36, 0x41, 0x00,
	0x00, 0x00, 0x77, 0x00, 0x00,
	0x00, 0x41, 0x36, 0x08, 0x00,
	0x02, 0x01, 0x02, 0x04, 0x02,
	0x3C, 0x26, 0x23, 0x26, 0x3C,
	0x1E, 0xA1, 0xA1, 0x61, 0x12,
	0x3A, 0x40, 0x40, 0x20, 0x7A,
	0x38, 0x54, 0x54, 0x55, 0x59,
	0x21, 0x55, 0x55, 0x79, 0x41,
	0x22, 0x54, 0x54, 0x78, 0x42, // a-umlaut
	0x21, 0x55, 0x54, 0x78, 0x40,
	0x20, 0x54, 0x55, 0x79, 0x40,
	0x0C, 0x1E, 0x52, 0x72, 0x12,
	0x39, 0x55, 0x55, 0x55, 0x59,
	0x39, 0x54, 0x54, 0x54, 0x59,
	0x39, 0x55, 0x54, 0x54, 0x58,
	0x00, 0x00, 0x45, 0x7C, 0x41,
	0x00, 0x02, 0x45, 0x7D, 0x42,
	0x00, 0x01, 0x45, 0x7C, 0x40,
	0x7D, 0x12, 0x11, 0x12, 0x7D, // A-umlaut
	0xF0, 0x28, 0x25, 0x28, 0xF0,
	0x7C, 0x54, 0x55, 0x45, 0x00,
	0x20, 0x54, 0x54, 0x7C, 0x54,
	0x7C, 0x0A, 0x09, 0x7F, 0x49,
	0x32, 0x49, 0x49, 0x49, 0x32,
	0x3A, 0x44, 0x44, 0x44, 0x3A, // o-umlaut
	0x32, 0x4A, 0x48, 0x48, 0x30,
	0x3A, 0x41, 0x41, 0x21, 0x7A,
	0x3A, 0x42, 0x40, 0x20, 0x78,
	0x00, 0x9D, 0xA0, 0xA0, 0x7D,
	0x3D, 0x42, 0x42, 0x42, 0x3D, // O-umlaut
	0x3D, 0x40, 0x40, 0x40, 0x3D,
	0x3C, 0x24, 0xFF, 0x24, 0x24,
	0x48, 0x7E, 0x49, 0x43, 0x66,
	0x2B, 0x2F, 0xFC, 0x2F, 0x2B,
	0xFF, 0x09, 0x29, 0xF6, 0x20,
	0xC0, 0x88, 0x7E, 0x09, 0x03,
	0x20, 0x54, 0x54, 0x79, 0x41,
	0x00, 0x00, 0x44, 0x7D, 0x41,
	0x30, 0x48, 0x48, 0x4A, 0x32,
	0x38, 0x40, 0x40, 0x22, 0x7A,
	0x00, 0x7A, 0x0A, 0x0A, 0x72,
	0x7D, 0x0D, 0x19, 0x31, 0x7D,
	0x26, 0x29, 0x29, 0x2F, 0x28,
	0x26, 0x29, 0x29, 0x29, 0x26,
	0x30, 0x48, 0x4D, 0x40, 0x20,
	0x38, 0x08, 0x08, 0x08, 0x08,
	0x08, 0x08, 0x08, 0x08, 0x38,
	0x2F, 0x10, 0xC8, 0xAC, 0xBA,
	0x2F, 0x10, 0x28, 0x34, 0xFA,
	0x00, 0x00, 0x7B, 0x00, 0x00,
	0x08, 0x14, 0x2A, 0x14, 0x22,
	0x22, 0x14, 0x2A, 0x14, 0x08,
	0x55, 0x00, 0x55, 0x00, 0x55, // #176 (25% block) missing in old code
	0xAA, 0x55, 0xAA, 0x55, 0xAA, // 50% block
	0xFF, 0x55, 0xFF, 0x55, 0xFF, // 75% block
	0x00, 0x00, 0x00, 0xFF, 0x00,
	0x10, 0x10, 0x10, 0xFF, 0x00,
	0x14, 0x14, 0x14, 0xFF, 0x00,
	0x10, 0x10, 0xFF, 0x00, 0xFF,
	0x10, 0x10, 0xF0, 0x10, 0xF0,
	0x14, 0x14, 0x14, 0xFC, 0x00,
	0x14, 0x14, 0xF7, 0x00, 0xFF,
	0x00, 0x00, 0xFF, 0x00, 0xFF,
	0x14, 0x14, 0xF4, 0x04, 0xFC,
	0x14, 0x14, 0x17, 0x10, 0x1F,
	0x10, 0x10, 0x1F, 0x10, 0x1F,
	0x14, 0x14, 0x14, 0x1F, 0x00,
	0x10, 0x10, 0x10, 0xF0, 0x00,
	0x00, 0x00, 0x00, 0x1F, 0x10,
	0x10, 0x10, 0x10, 0x1F, 0x10,
	0x10, 0x10, 0x10, 0xF0, 0x10,
	0x00, 0x00, 0x00, 0xFF, 0x10,
	0x10, 0x10, 0x10, 0x10, 0x10,
	0x10, 0x10, 0x10, 0xFF, 0x10,
	0x00, 0x00, 0x00, 0xFF, 0x14,
	0x00, 0x00, 0xFF, 0x00, 0xFF,
	0x00, 0x00, 0x1F, 0x10, 0x17,
	0x00, 0x00, 0xFC, 0x04, 0xF4,
	0x14, 0x14, 0x17, 0x10, 0x17,
	0x14, 0x14, 0xF4, 0x04, 0xF4,
	0x00, 0x00, 0xFF, 0x00, 0xF7,
	0x14, 0x14, 0x14, 0x14, 0x14,
	0x14, 0x14, 0xF7, 0x00, 0xF7,
	0x14, 0x14, 0x14, 0x17, 0x14,
	0x10, 0x10, 0x1F, 0x10, 0x1F,
	0x14, 0x14, 0x14, 0xF4, 0x14,
	0x10, 0x10, 0xF0, 0x10, 0xF0,
	0x00, 0x00, 0x1F, 0x10, 0x1F,
	0x00, 0x00, 0x00, 0x1F, 0x14,
	0x00, 0x00, 0x00, 0xFC, 0x14,
	0x00, 0x00, 0xF0, 0x10, 0xF0,
	0x10, 0x10, 0xFF, 0x10, 0xFF,
	0x14, 0x14, 0x14, 0xFF, 0x14,
	0x10, 0x10, 0x10, 0x1F, 0x00,
	0x00, 0x00, 0x00, 0xF0, 0x10,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xF0, 0xF0, 0xF0, 0xF0, 0xF0,
	0xFF, 0xFF, 0xFF, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xFF, 0xFF,
	0x0F, 0x0F, 0x0F, 0x0F, 0x0F,
	0x38, 0x44, 0x44, 0x38, 0x44,
	0xFC, 0x4A, 0x4A, 0x4A, 0x34, // sharp-s or beta
	0x7E, 0x02, 0x02, 0x06, 0x06,
	0x02, 0x7E, 0x02, 0x7E, 0x02,
	0x63, 0x55, 0x49, 0x41, 0x63,
	0x38, 0x44, 0x44, 0x3C, 0x04,
	0x40, 0x7E, 0x20, 0x1E, 0x20,
	0x06, 0x02, 0x7E, 0x02, 0x02,
	0x99, 0xA5, 0xE7, 0xA5, 0x99,
	0x1C, 0x2A, 0x49, 0x2A, 0x1C,
	0x4C, 0x72, 0x01, 0x72, 0x4C,
	0x30, 0x4A, 0x4D, 0x4D, 0x30,
	0x30, 0x48, 0x78, 0x48, 0x30,
	0xBC, 0x62, 0x5A, 0x46, 0x3D,
	0x3E, 0x49, 0x49, 0x49, 0x00,
	0x7E, 0x01, 0x01, 0x01, 0x7E,
	0x2A, 0x2A, 0x2A, 0x2A, 0x2A,
	0x44, 0x44, 0x5F, 0x44, 0x44,
	0x40, 0x51, 0x4A, 0x44, 0x40,
	0x40, 0x44, 0x4A, 0x51, 0x40,
	0x00, 0x00, 0xFF, 0x01, 0x03,
	0xE0, 0x80, 0xFF, 0x00, 0x00,
	0x08, 0x08, 0x6B, 0x6B, 0x08,
	0x36, 0x12, 0x36, 0x24, 0x36,
	0x06, 0x0F, 0x09, 0x0F, 0x06,
	0x00, 0x00, 0x18, 0x18, 0x00,
	0x00, 0x00, 0x10, 0x10, 0x00,
	0x30, 0x40, 0xFF, 0x01, 0x01,
	0x00, 0x1F, 0x01, 0x01, 0x1E,
	0x00, 0x19, 0x1D, 0x17, 0x12,
	0x00, 0x3C, 0x3C, 0x3C, 0x3C,
	0x00, 0x00, 0x00, 0x00, 0x00  // #255 NBSP
};

#ifdef	__cplusplus
}
#endif

#endif  //__USE_OLEDDISP__
#endif	/* OLED_H */
