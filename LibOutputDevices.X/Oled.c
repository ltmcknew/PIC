#include "Oled.h"

#ifdef __USE_OLEDDISP__

static uint8_t buffer[SSD1306_LCDHEIGHT * SSD1306_LCDWIDTH / 8] = { 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x80, 0x80, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xF8, 0xE0, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80,
0x80, 0x80, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0xFF,
0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00,
0x80, 0xFF, 0xFF, 0x80, 0x80, 0x00, 0x80, 0x80, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x80, 0x80,
0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x8C, 0x8E, 0x84, 0x00, 0x00, 0x80, 0xF8,
0xF8, 0xF8, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xE0, 0xE0, 0xC0, 0x80,
0x00, 0xE0, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0xC7, 0x01, 0x01,
0x01, 0x01, 0x83, 0xFF, 0xFF, 0x00, 0x00, 0x7C, 0xFE, 0xC7, 0x01, 0x01, 0x01, 0x01, 0x83, 0xFF,
0xFF, 0xFF, 0x00, 0x38, 0xFE, 0xC7, 0x83, 0x01, 0x01, 0x01, 0x83, 0xC7, 0xFF, 0xFF, 0x00, 0x00,
0x01, 0xFF, 0xFF, 0x01, 0x01, 0x00, 0xFF, 0xFF, 0x07, 0x01, 0x01, 0x01, 0x00, 0x00, 0x7F, 0xFF,
0x80, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x7F, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x01, 0xFF,
0xFF, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x03, 0x0F, 0x3F, 0x7F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0xC7, 0xC7, 0x8F,
0x8F, 0x9F, 0xBF, 0xFF, 0xFF, 0xC3, 0xC0, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xFC, 0xFC,
0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xF8, 0xF8, 0xF0, 0xF0, 0xE0, 0xC0, 0x00, 0x01, 0x03, 0x03, 0x03,
0x03, 0x03, 0x01, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01,
0x03, 0x01, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x03, 0x03, 0x00, 0x00,
0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x01, 0x03, 0x01, 0x00, 0x00, 0x00, 0x03,
0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF9, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x1F, 0x0F,
0x87, 0xC7, 0xF7, 0xFF, 0xFF, 0x1F, 0x1F, 0x3D, 0xFC, 0xF8, 0xF8, 0xF8, 0xF8, 0x7C, 0x7D, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x0F, 0x07, 0x00, 0x30, 0x30, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xC0, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0xC0, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0x3F, 0x1F,
0x0F, 0x07, 0x1F, 0x7F, 0xFF, 0xFF, 0xF8, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xF8, 0xE0,
0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x00, 0x00,
0x00, 0xFC, 0xFE, 0xFC, 0x0C, 0x06, 0x06, 0x0E, 0xFC, 0xF8, 0x00, 0x00, 0xF0, 0xF8, 0x1C, 0x0E,
0x06, 0x06, 0x06, 0x0C, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0xFC,
0xFE, 0xFC, 0x00, 0x18, 0x3C, 0x7E, 0x66, 0xE6, 0xCE, 0x84, 0x00, 0x00, 0x06, 0xFF, 0xFF, 0x06,
0x06, 0xFC, 0xFE, 0xFC, 0x0C, 0x06, 0x06, 0x06, 0x00, 0x00, 0xFE, 0xFE, 0x00, 0x00, 0xC0, 0xF8,
0xFC, 0x4E, 0x46, 0x46, 0x46, 0x4E, 0x7C, 0x78, 0x40, 0x18, 0x3C, 0x76, 0xE6, 0xCE, 0xCC, 0x80,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0F, 0x1F, 0x1F, 0x3F, 0x3F, 0x3F, 0x3F, 0x1F, 0x0F, 0x03,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x00, 0x00,
0x00, 0x0F, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x00, 0x00, 0x03, 0x07, 0x0E, 0x0C,
0x18, 0x18, 0x0C, 0x06, 0x0F, 0x0F, 0x0F, 0x00, 0x00, 0x01, 0x0F, 0x0E, 0x0C, 0x18, 0x0C, 0x0F,
0x07, 0x01, 0x00, 0x04, 0x0E, 0x0C, 0x18, 0x0C, 0x0F, 0x07, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x00,
0x00, 0x0F, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x07,
0x07, 0x0C, 0x0C, 0x18, 0x1C, 0x0C, 0x06, 0x06, 0x00, 0x04, 0x0E, 0x0C, 0x18, 0x0C, 0x0F, 0x07,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static uint8_t globe_bmp[16*12 + 3] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0x03, 0x00, 0x00, 0xE0, 0x18, 0x1E, 0x00, 0x00, 
0x20, 0x00, 0x3C, 0x00, 0x00, 0x10, 0x00, 0xF0, 0x00, 0x00, 0x08, 0x00, 0xD8, 0x01, 0x00, 0x00, 
0x00, 0x90, 0x03, 0x00, 0x00, 0x00, 0x20, 0x07, 0x00, 0x18, 0xF0, 0x01, 0x07, 0x00, 0x3C, 0xE0, 
0x03, 0x02, 0x00, 0x78, 0x81, 0x09, 0x02, 0x00, 0xF0, 0x11, 0x01, 0x22, 0x00, 0xF8, 0x27, 0x01, 
0x30, 0x00, 0xF8, 0x23, 0x00, 0x34, 0x00, 0xF8, 0x33, 0x00, 0x70, 0x00, 0xF8, 0xF3, 0x00, 0x70, 
0x00, 0xF8, 0xF7, 0x00, 0x60, 0x00, 0xFC, 0x7F, 0x00, 0x20, 0x00, 0xFC, 0xFF, 0x00, 0x20, 0x00, 
0xFE, 0x7F, 0x00, 0x20, 0x00, 0xFE, 0x3F, 0x00, 0x20, 0x00, 0xFC, 0x1F, 0x00, 0x00, 0x00, 0xFC, 
0x1F, 0x00, 0x00, 0x00, 0xF8, 0x0F, 0x00, 0x00, 0x00, 0xF8, 0x0F, 0x00, 0x00, 0x00, 0x30, 0x00, 
0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 
0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x1F, 0x00, 
0x00, 0x00, 0xE0, 0x7F, 0x00, 0x00, 0x00, 0xF0, 0x3F, 0x00, 0x00, 0x00, 0xF0, 0x1F, 0x00, 0x00, 
0x00, 0xE0, 0x07, 0x00, 0x00, 0x00, 0xC0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00
};

STATUS_T OledInit(uint8_t setAddr, bool isExtVcc)
{    
    oled_addr = setAddr;
    oled_extvcc = isExtVcc;

    OledCmd(SSD1306_DISPLAYOFF,0);

    oled_cmd_data[0] = 0x80;
    OledCmd(SSD1306_SETDISPLAYCLOCKDIV,1);

    oled_cmd_data[0] = 0x3F;
    OledCmd(SSD1306_SETMULTIPLEX,1);

    oled_cmd_data[0] = 0x00;
    OledCmd(SSD1306_SETDISPLAYOFFSET,1);

    OledCmd(SSD1306_SETSTARTLINE | 0x0,0);
    if(oled_extvcc){
        oled_cmd_data[0] = 0x10;
        OledCmd(SSD1306_CHARGEPUMP,1);

        oled_cmd_data[0] = 0x9F;
        OledCmd(SSD1306_SETCONTRAST,1);

        oled_cmd_data[0] = 0x22;
        OledCmd(SSD1306_SETPRECHARGE,1);
    } else {
        oled_cmd_data[0] = 0x14;
        OledCmd(SSD1306_CHARGEPUMP,1);

        oled_cmd_data[0] = 0xCF;
        OledCmd(SSD1306_SETCONTRAST,1);

        oled_cmd_data[0] = 0xF1;
        OledCmd(SSD1306_SETPRECHARGE,1);
    }
    oled_cmd_data[0] = 0x00;
    OledCmd(SSD1306_MEMORYMODE,1);

    OledCmd(SSD1306_SEGREMAP | 0x1,0);

    OledCmd(SSD1306_COMSCANDEC,0);

    oled_cmd_data[0] = 0x12;
    OledCmd(SSD1306_SETCOMPINS,1);

    oled_cmd_data[0] = 0x40;
    OledCmd(SSD1306_SETVCOMDETECT,1);

//    OledCmd(SSD1306_DISPLAYALLON,data,0);
    OledCmd(SSD1306_DISPLAYALLON_RESUME,0);
    
    OledCmd(SSD1306_NORMALDISPLAY,0);

    OledCmd(SSD1306_DISPLAYON,0);
        
    return STAT_SUCCESS;
}

STATUS_T OledCmd(uint8_t cmd, uint8_t dataCnt)
{
    I2C1_buff_out[0] = 0x80;
    I2C1_buff_out[1] = cmd;
    
    uint8_t i, totalCnt = 2*dataCnt + 2;
    for(i = 0; i < dataCnt; i++){
        I2C1_buff_out[2*i+2] = 0x80;
        I2C1_buff_out[2*i+3] = oled_cmd_data[i];
    }
    if(I2C1Write(totalCnt,oled_addr) == totalCnt)
        return STAT_SUCCESS;
    
    return STAT_FAIL;
}

STATUS_T OledWriteDisplay(void)
{
        
    oled_cmd_data[0] = 0x00;
    oled_cmd_data[1] = SSD1306_LCDWIDTH-1;
    OledCmd(SSD1306_COLUMNADDR,2);
    
    oled_cmd_data[0] = 0;
    oled_cmd_data[1] = 7;
    OledCmd(SSD1306_PAGEADDR,2);

    // I2C
    uint16_t i;
    for (i=0; i<(1024); i++) {  //128*64/8
        
        // send a bunch of data in one xmission
        I2C1_buff_out[0] = 0x40;
        
        uint8_t x;
        for (x=0; x<16; x++) {
            I2C1_buff_out[x+1] = buffer[i];
            i++;
        }
        i--;
        I2C1Write(x+1,oled_addr);
    }
}

STATUS_T OledWriteDisplayFixed(uint8_t screenVal)
{
        
    oled_cmd_data[0] = 0x00;
    oled_cmd_data[1] = SSD1306_LCDWIDTH-1;
    OledCmd(SSD1306_COLUMNADDR,2);
    
    oled_cmd_data[0] = 0;
    oled_cmd_data[1] = 7;
    OledCmd(SSD1306_PAGEADDR,2);

    // I2C
    uint16_t i;
    for (i=0; i<(1024); i++) {  //128*64/8
        
        // send a bunch of data in one xmission
        I2C1_buff_out[0] = 0x40;
        
        uint8_t x;
        for (x=0; x<16; x++) {
            I2C1_buff_out[x+1] = screenVal;
            i++;
        }
        i--;
        I2C1Write(x+1,oled_addr);
    }
}

STATUS_T OledInvertDisplay(bool i)
{
    if (i) {
        OledCmd(SSD1306_INVERTDISPLAY,0);
    } else {
        OledCmd(SSD1306_NORMALDISPLAY,0);
    }
}

// the most basic function, set a single pixel
STATUS_T OledDrawPixel(int16_t x, int16_t y, uint16_t color)
{    
    if ((x < 0) || (x >= SSD1306_LCDWIDTH) || (y < 0) || (y >= SSD1306_LCDHEIGHT))
        return STAT_FAIL;
    
//    // check rotation, move pixel around if necessary
//    switch (disp->rotation) {
//    case 1:
//        swap(x, y);
//        x = SSD1306_LCDWIDTH - x - 1;
//        break;
//    case 2:
//        x = SSD1306_LCDWIDTH - x - 1;
//        y = SSD1306_LCDHEIGHT - y - 1;
//        break;
//    case 3:
//        swap(x, y);
//        y = SSD1306_LCDHEIGHT - y - 1;
//        break;
//    }  

    // x is which column
    switch (color) 
    {
      case WHITE:   buffer[x+ (y/8)*SSD1306_LCDWIDTH] |=  (1 << (y&7)); break;
      case BLACK:   buffer[x+ (y/8)*SSD1306_LCDWIDTH] &= ~(1 << (y&7)); break; 
      case INVERSE: buffer[x+ (y/8)*SSD1306_LCDWIDTH] ^=  (1 << (y&7)); break; 
    }
    
    return STAT_SUCCESS;
}

STATUS_T OledDrawChar(int16_t x, int16_t y, unsigned char c, uint16_t  color, uint16_t bg, uint8_t size)
{
    if ((x >= SSD1306_LCDWIDTH) || // Clip right
        (y >= SSD1306_LCDHEIGHT) || // Clip bottom
        ((x + 6 * size - 1) < 0) || // Clip left
        ((y + 8 * size - 1) < 0))   // Clip top
            return STAT_FAIL;

//    if(!disp->_cp437 && (c >= 176)) c++; // Handle 'classic' charset behavior
    
    int8_t i;
    for (i=0; i<6; i++ ) {        
        uint8_t line;
        if (i == 5) 
            line = 0x0;
        else 
            line = font[(c*5)+i];
        
        int8_t j;
        for (j = 0; j<8; j++) {            
            if (line & 0x1) {
                if (size == 1) // default size
                    OledDrawPixel(x+i, y+j, color);
                else {  // big size
//                    fillRect(x+(i*size), y+(j*size), size, size, color);
                } 
            } else if (bg != color) {
                if (size == 1) // default size
                    OledDrawPixel(x+i, y+j, bg);
                else {  // big size
//                    fillRect(x+i*size, y+j*size, size, size, bg);
                }
            }
            line >>= 1;
        }
    }
    
    return STAT_SUCCESS;
}

STATUS_T OledDrawString(uint8_t x, uint8_t y, char* str, bool apply)
{
    /*  Char X's: 0,6,18,24,30,36,42,48,54,60,68,72,78,84,90,96,102,108,114,120
     *  Char Y's: 0,8,16,24,32,40,48,56
     */
    uint16_t i, x0, y0, len = strlen(str);
    
    if(len > 20)
        return STAT_FAIL;
    
    for(i = 0; i < 20; i++){
        x0 = (i%20)*6;
//        y0 = (i/20)*8;
        if(i < len)
            OledDrawChar(x+x0,y/*+y0*/,str[i],WHITE,BLACK,1);
        else
            OledDrawChar(x+x0,y/*+y0*/,0x00,WHITE,BLACK,1);
    }
    if(apply)
        OledWriteDisplay();
    
    return STAT_SUCCESS;
}

STATUS_T OledDrawStringWrap(uint8_t x, uint8_t y, char* str)
{
    /*  Char X's: 0,6,18,24,30,36,42,48,54,60,68,72,78,84,90,96,102,108,114,120
     *  Char Y's: 0,8,16,24,32,40,48,56
     */
    uint16_t i, x0, y0, len = strlen(str);
    for(i = 0; i < len; i++){
        x0 = (i%20)*6;
        y0 = (i/20)*8;
            OledDrawChar(x+x0,y+y0,str[i],WHITE,BLACK,1);
    }
    OledWriteDisplay();
    
    return STAT_SUCCESS;
}

// clear everything
STATUS_T OledClearDisplay(void)
{
    memset(buffer, 0, (SSD1306_LCDWIDTH*SSD1306_LCDHEIGHT/8));
    OledWriteDisplay();
    
    return STAT_SUCCESS;
}

// Dim the display
// dim = true: display is dimmed
// dim = false: display is normal
STATUS_T OledDim(bool dim) 
{
    uint8_t contrast;

    if (dim) {
        contrast = 0; // Dimmed display
    } else {
        if (oled_extvcc) {
            contrast = 0x9F;
        } else {
            contrast = 0xCF;
        }
    }
    // the range of contrast to too small to be really useful
    // it is useful to dim the display
    oled_cmd_data[0] = contrast;
    OledCmd(SSD1306_SETCONTRAST,1);
}

// Scrolling Routines

STATUS_T OledStartScrollRight(uint8_t start, uint8_t stop)
{
    oled_cmd_data[0] = 0x00;
    oled_cmd_data[1] = start;
    oled_cmd_data[2] = 0x00;
    oled_cmd_data[3] = stop;
    oled_cmd_data[4] = 0x00;
    oled_cmd_data[5] = 0xFF;
    OledCmd(SSD1306_RIGHT_HORIZONTAL_SCROLL,6); //configure right horiz scolling
    OledCmd(SSD1306_ACTIVATE_SCROLL,0);         //activate scrolling
}

// startscrollleft
// Activate a right handed scroll for rows start through stop
// Hint, the display is 16 rows tall. To scroll the whole display, run:
// display.scrollright(0x00, 0x0F) 
STATUS_T OledStartScrollLeft(uint8_t start, uint8_t stop)
{
    oled_cmd_data[0] = 0x00;
    oled_cmd_data[1] = start;
    oled_cmd_data[2] = 0x00;
    oled_cmd_data[3] = stop;
    oled_cmd_data[4] = 0x00;
    oled_cmd_data[5] = 0xFF;
    OledCmd(SSD1306_LEFT_HORIZONTAL_SCROLL,6); //configure right horiz scolling
    OledCmd(SSD1306_ACTIVATE_SCROLL,0);         //activate scrolling
}

// startscrolldiagright
// Activate a diagonal scroll for rows start through stop
// Hint, the display is 16 rows tall. To scroll the whole display, run:
// display.scrollright(0x00, 0x0F) 
STATUS_T OledStartScrollDiagRight(uint8_t start, uint8_t stop)
{
    oled_cmd_data[0] = 0x00;
    oled_cmd_data[1] = SSD1306_LCDHEIGHT;
    OledCmd(SSD1306_SET_VERTICAL_SCROLL_AREA,2); //configure right horiz scolling
    oled_cmd_data[0] = 0x00;
    oled_cmd_data[1] = start;
    oled_cmd_data[2] = 0x00;
    oled_cmd_data[3] = stop;
    oled_cmd_data[4] = 0x01;
    OledCmd(SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL,5); //configure right horiz scolling
    OledCmd(SSD1306_ACTIVATE_SCROLL,0);         //activate scrolling
}

// startscrolldiagleft
// Activate a diagonal scroll for rows start through stop
// Hint, the display is 16 rows tall. To scroll the whole display, run:
// display.scrollright(0x00, 0x0F) 
STATUS_T OledStartScrollDiagLeft(uint8_t start, uint8_t stop)
{
    oled_cmd_data[0] = 0x00;
    oled_cmd_data[1] = SSD1306_LCDHEIGHT;
    OledCmd(SSD1306_SET_VERTICAL_SCROLL_AREA,2); //configure right horiz scolling
    oled_cmd_data[0] = 0x00;
    oled_cmd_data[1] = start;
    oled_cmd_data[2] = 0x00;
    oled_cmd_data[3] = stop;
    oled_cmd_data[4] = 0x01;
    OledCmd(SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL,5); //configure right horiz scolling
    OledCmd(SSD1306_ACTIVATE_SCROLL,0);         //activate scrolling
}

STATUS_T OledStopScroll(void)
{
    OledCmd(SSD1306_DEACTIVATE_SCROLL,0);         //deactivate scrolling
}


// Begin Drawing Routines, Handles Most Shapes

STATUS_T OledDrawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color)
{
    bool bSwap = false;
//    switch(disp->rotation) { 
//    case 0:
//        // 0 degree rotation, do nothing
//        break;
//    case 1:
//        // 90 degree rotation, swap x & y for rotation, then invert x
//        bSwap = true;
//        swap(x, y);
//        x = SSD1306_LCDWIDTH - x - 1;
//        break;
//    case 2:
//        // 180 degree rotation, invert x and y - then shift y around for height.
//        x = SSD1306_LCDWIDTH - x - 1;
//        y = SSD1306_LCDHEIGHT - y - 1;
//        x -= (w-1);
//        break;
//    case 3:
//        // 270 degree rotation, swap x & y for rotation, then invert y  and adjust y for w (not to become h)
//        bSwap = true;
//        swap(x, y);
//        y = SSD1306_LCDHEIGHT - y - 1;
//        y -= (w-1);
//        break;
//    }

    if(bSwap) { 
        return OledDrawFastVLineInternal(x, y, w, color);
    } else { 
        return OledDrawFastHLineInternal(x, y, w, color);
    }
}

STATUS_T OledDrawFastHLineInternal(int16_t x, int16_t y, int16_t w, uint16_t color)
{
    // Do bounds/limit checks
    if(y < 0 || y >= SSD1306_LCDHEIGHT) { return STAT_FAIL; }

    // make sure we don't try to draw below 0
    if(x < 0) { 
        w += x;
        x = 0;
    }

    // make sure we don't go off the edge of the display
    if( (x + w) > SSD1306_LCDWIDTH) { 
        w = (SSD1306_LCDWIDTH - x);
    }

    // if our width is now negative, punt
    if(w <= 0) { return STAT_FAIL; }

    // set up the pointer for  movement through the buffer
    register uint8_t *pBuf = buffer;
    // adjust the buffer pointer for the current row
    pBuf += ((y/8) * SSD1306_LCDWIDTH);
    // and offset x columns in
    pBuf += x;

    register uint8_t mask = 1 << (y&7);

    switch (color) 
    {
    case WHITE:
        while(w--) { *pBuf++ |= mask; };
        break;
    case BLACK:
        mask = ~mask;
        while(w--) { *pBuf++ &= mask; };
        break;
    case INVERSE:
        while(w--) { *pBuf++ ^= mask; };
        break;
    }
    
    return STAT_SUCCESS;
}

STATUS_T OledDrawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color)
{
    bool bSwap = false;
//    switch(disp->rotation) { 
//    case 0:
//        break;
//    case 1:
//        // 90 degree rotation, swap x & y for rotation, then invert x and adjust x for h (now to become w)
//        bSwap = true;
//        swap(x, y);
//        x = SSD1306_LCDWIDTH - x - 1;
//        x -= (h-1);
//        break;
//    case 2:
//        // 180 degree rotation, invert x and y - then shift y around for height.
//        x = SSD1306_LCDWIDTH - x - 1;
//        y = SSD1306_LCDHEIGHT - y - 1;
//        y -= (h-1);
//        break;
//    case 3:
//        // 270 degree rotation, swap x & y for rotation, then invert y 
//        bSwap = true;
//        swap(x, y);
//        y = SSD1306_LCDHEIGHT - y - 1;
//        break;
//    }

    if(bSwap) { 
        return OledDrawFastHLineInternal(x, y, h, color);
    } else {
        return OledDrawFastVLineInternal(x, y, h, color);
    }
}

STATUS_T OledDrawFastVLineInternal(int16_t x, int16_t __y, int16_t __h, uint16_t color)
{
    // do nothing if we're off the left or right side of the screen
    if(x < 0 || x >= SSD1306_LCDWIDTH) { return STAT_FAIL; }

    // make sure we don't try to draw below 0
    if(__y < 0) { 
        // __y is negative, this will subtract enough from __h to account for __y being 0
        __h += __y;
        __y = 0;
    } 

    // make sure we don't go past the height of the display
    if( (__y + __h) > SSD1306_LCDHEIGHT) { 
        __h = (SSD1306_LCDHEIGHT - __y);
    }

    // if our height is now negative, punt 
    if(__h <= 0) { 
        return STAT_FAIL;
    }

    // this display doesn't need ints for coordinates, use local byte registers for faster juggling
    register uint8_t y = __y;
    register uint8_t h = __h;


    // set up the pointer for fast movement through the buffer
    register uint8_t *pBuf = buffer;
    // adjust the buffer pointer for the current row
    pBuf += ((y/8) * SSD1306_LCDWIDTH);
    // and offset x columns in
    pBuf += x;

    // do the first partial byte, if necessary - this requires some masking
    register uint8_t mod = (y&7);
    if(mod) {
        // mask off the high n bits we want to set 
        mod = 8-mod;

        // note - lookup table results in a nearly 10% performance improvement in fill* functions
        // register uint8_t mask = ~(0xFF >> (mod));
        static uint8_t premask[8] = {0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE };
        register uint8_t mask = premask[mod];

        // adjust the mask if we're not going to reach the end of this byte
        if( h < mod) { 
            mask &= (0XFF >> (mod-h));
        }

        switch (color) 
        {
        case WHITE:
            *pBuf |=  mask;
            break;
        case BLACK:
            *pBuf &= ~mask;
            break;
        case INVERSE:
            *pBuf ^=  mask;
            break;
        }

        // fast exit if we're done here!
        if(h<mod) { return STAT_SUCCESS; }

        h -= mod;

        pBuf += SSD1306_LCDWIDTH;
    }

    // write solid bytes while we can - effectively doing 8 rows at a time
    if(h >= 8) { 
        if (color == INVERSE)  {          // separate copy of the code so we don't impact performance of the black/white write version with an extra comparison per loop
            do  {
                *pBuf=~(*pBuf);

                // adjust the buffer forward 8 rows worth of data
                pBuf += SSD1306_LCDWIDTH;

                // adjust h & y (there's got to be a faster way for me to do this, but this should still help a fair bit for now)
                h -= 8;
            } while(h >= 8);
        }
        else 
        {
            // store a local value to work with 
            register uint8_t val = (color == WHITE) ? 255 : 0;

            do  {
                // write our value in
                *pBuf = val;

                // adjust the buffer forward 8 rows worth of data
                pBuf += SSD1306_LCDWIDTH;

                // adjust h & y (there's got to be a faster way for me to do this, but this should still help a fair bit for now)
                h -= 8;
            } while(h >= 8);
        }
    }

    // now do the final partial byte, if necessary
    if(h) {
        mod = h & 7;
        // this time we want to mask the low bits of the byte, vs the high bits we did above
        // register uint8_t mask = (1 << mod) - 1;
        // note - lookup table results in a nearly 10% performance improvement in fill* functions
        static uint8_t postmask[8] = {0x00, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F };
        register uint8_t mask = postmask[mod];
        switch (color) 
        {
        case WHITE:
            *pBuf |=  mask;
            break;
        case BLACK:
            *pBuf &= ~mask;
            break;
        case INVERSE:
            *pBuf ^=  mask;
            break;
        }
    }
    
    return STAT_SUCCESS;
}

STATUS_T OledDrawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color)
{
    int16_t steep = abs(y1 - y0) > abs(x1 - x0);
    if (steep) {
        swap(x0, y0);
        swap(x1, y1);
    }

    if (x0 > x1) {
        swap(x0, x1);
        swap(y0, y1);
    }

    int16_t dx, dy;
    dx = x1 - x0;
    dy = abs(y1 - y0);

    int16_t err = dx / 2;
    int16_t ystep;

    if (y0 < y1) {
        ystep = 1;
    } else {
        ystep = -1;
    }

    for (; x0<=x1; x0++) {
        if (steep) {
            OledDrawPixel(y0, x0, color);
        } else {
            OledDrawPixel(x0, y0, color);
        }
        err -= dy;
        if (err < 0) {
            y0 += ystep;
            err += dx;
        }
    }
    
    return STAT_SUCCESS;
}

STATUS_T OledDrawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color)
{
    OledDrawFastHLine(x, y, w, color);
    OledDrawFastHLine(x, y+h-1, w, color);
    OledDrawFastVLine(x, y, h, color);
    OledDrawFastVLine(x+w-1, y, h, color);
    
    return STAT_SUCCESS;
}

STATUS_T OledFillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color)
{
    // Update in subclasses if desired!
    int16_t i;
    for (i=x; i<x+w; i++) {
        OledDrawFastVLine(i, y, h, color);
    }
    
    return STAT_SUCCESS;
}

STATUS_T OledFillScreen(uint16_t color)
{
    return OledFillRect(0, 0, SSD1306_LCDWIDTH, SSD1306_LCDHEIGHT, color);
}

STATUS_T OledDrawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color)
{
    int16_t f = 1 - r;
    int16_t ddF_x = 1;
    int16_t ddF_y = -2 * r;
    int16_t x = 0;
    int16_t y = r;

    OledDrawPixel(x0  , y0+r, color);
    OledDrawPixel(x0  , y0-r, color);
    OledDrawPixel(x0+r, y0  , color);
    OledDrawPixel(x0-r, y0  , color);

    while (x<y) {
        if (f >= 0) {
            y--;
            ddF_y += 2;
            f += ddF_y;
        }
        x++;
        ddF_x += 2;
        f += ddF_x;

        OledDrawPixel(x0 + x, y0 + y, color);
        OledDrawPixel(x0 - x, y0 + y, color);
        OledDrawPixel(x0 + x, y0 - y, color);
        OledDrawPixel(x0 - x, y0 - y, color);
        OledDrawPixel(x0 + y, y0 + x, color);
        OledDrawPixel(x0 - y, y0 + x, color);
        OledDrawPixel(x0 + y, y0 - x, color);
        OledDrawPixel(x0 - y, y0 - x, color);
    }
    
    return STAT_SUCCESS;
}

STATUS_T OledDrawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t color)
{
    int16_t f     = 1 - r;
    int16_t ddF_x = 1;
    int16_t ddF_y = -2 * r;
    int16_t x     = 0;
    int16_t y     = r;

    while (x<y) {
        if (f >= 0) {
            y--;
            ddF_y += 2;
            f     += ddF_y;
        }
        x++;
        ddF_x += 2;
        f     += ddF_x;
        if (cornername & 0x4) {
            OledDrawPixel(x0 + x, y0 + y, color);
            OledDrawPixel(x0 + y, y0 + x, color);
        } 
        if (cornername & 0x2) {
            OledDrawPixel(x0 + x, y0 - y, color);
            OledDrawPixel(x0 + y, y0 - x, color);
        }
        if (cornername & 0x8) {
            OledDrawPixel(x0 - y, y0 + x, color);
            OledDrawPixel(x0 - x, y0 + y, color);
        }
        if (cornername & 0x1) {
            OledDrawPixel(x0 - y, y0 - x, color);
            OledDrawPixel(x0 - x, y0 - y, color);
        }
    }
    
    return STAT_SUCCESS;
}

STATUS_T OledFillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color)
{
    OledDrawFastVLine(x0, y0-r, 2*r+1, color);
    return OledFillCircleHelper(x0, y0, r, 3, 0, color);
}

STATUS_T OledFillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint16_t color)
{
    int16_t f     = 1 - r;
    int16_t ddF_x = 1;
    int16_t ddF_y = -2 * r;
    int16_t x     = 0;
    int16_t y     = r;

    while (x<y) {
        if (f >= 0) {
            y--;
            ddF_y += 2;
            f     += ddF_y;
        }
        x++;
        ddF_x += 2;
        f     += ddF_x;

        if (cornername & 0x1) {
            OledDrawFastVLine(x0+x, y0-y, 2*y+1+delta, color);
            OledDrawFastVLine(x0+y, y0-x, 2*x+1+delta, color);
        }
        if (cornername & 0x2) {
            OledDrawFastVLine(x0-x, y0-y, 2*y+1+delta, color);
            OledDrawFastVLine(x0-y, y0-x, 2*x+1+delta, color);
        }
    }
    
    return STAT_SUCCESS;
}

STATUS_T OledDrawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color)
{
    OledDrawLine(x0, y0, x1, y1, color);
    OledDrawLine(x1, y1, x2, y2, color);
    OledDrawLine(x2, y2, x0, y0, color);
    
    return STAT_SUCCESS;
}

STATUS_T OledFillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color)
{
    int16_t a, b, y, last;

    // Sort coordinates by Y order (y2 >= y1 >= y0)
    if (y0 > y1) {
        swap(y0, y1); swap(x0, x1);
    }
    if (y1 > y2) {
        swap(y2, y1); swap(x2, x1);
    }
    if (y0 > y1) {
        swap(y0, y1); swap(x0, x1);
    }

    if(y0 == y2) { // Handle awkward all-on-same-line case as its own thing
        a = b = x0;
        if(x1 < a)      a = x1;
        else if(x1 > b) b = x1;
        if(x2 < a)      a = x2;
        else if(x2 > b) b = x2;
        OledDrawFastHLine(a, y0, b-a+1, color);
        return;
    }

    int16_t
        dx01 = x1 - x0,
        dy01 = y1 - y0,
        dx02 = x2 - x0,
        dy02 = y2 - y0,
        dx12 = x2 - x1,
        dy12 = y2 - y1;
    int32_t
        sa   = 0,
        sb   = 0;

    // For upper part of triangle, find scanline crossings for segments
    // 0-1 and 0-2.  If y1=y2 (flat-bottomed triangle), the scanline y1
    // is included here (and second loop will be skipped, avoiding a /0
    // error there), otherwise scanline y1 is skipped here and handled
    // in the second loop...which also avoids a /0 error here if y0=y1
    // (flat-topped triangle).
    if(y1 == y2) last = y1;   // Include y1 scanline
    else         last = y1-1; // Skip it

    for(y=y0; y<=last; y++) {
        a   = x0 + sa / dy01;
        b   = x0 + sb / dy02;
        sa += dx01;
        sb += dx02;
        /* longhand:
        a = x0 + (x1 - x0) * (y - y0) / (y1 - y0);
        b = x0 + (x2 - x0) * (y - y0) / (y2 - y0);
        */
        if(a > b) swap(a,b);
        OledDrawFastHLine(a, y, b-a+1, color);
    }

    // For lower part of triangle, find scanline crossings for segments
    // 0-2 and 1-2.  This loop is skipped if y1=y2.
    sa = dx12 * (y - y1);
    sb = dx02 * (y - y0);
    for(; y<=y2; y++) {
        a   = x1 + sa / dy12;
        b   = x0 + sb / dy02;
        sa += dx12;
        sb += dx02;
        /* longhand:
        a = x1 + (x2 - x1) * (y - y1) / (y2 - y1);
        b = x0 + (x2 - x0) * (y - y0) / (y2 - y0);
        */
        if(a > b) swap(a,b);
        OledDrawFastHLine(a, y, b-a+1, color);
    }
    
    return STAT_SUCCESS;
}

STATUS_T OledDrawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color)
{
    // smarter version
    OledDrawFastHLine(x0+radius  , y0    , w-2*radius, color); // Top
    OledDrawFastHLine(x0+radius  , y0+h-1, w-2*radius, color); // Bottom
    OledDrawFastVLine(x0    , y0+radius  , h-2*radius, color); // Left
    OledDrawFastVLine(x0+w-1, y0+radius  , h-2*radius, color); // Right
    // draw four corners
    OledDrawCircleHelper(x0+radius    , y0+radius    , radius, 1, color);
    OledDrawCircleHelper(x0+w-radius-1, y0+radius    , radius, 2, color);
    OledDrawCircleHelper(x0+w-radius-1, y0+h-radius-1, radius, 4, color);
    OledDrawCircleHelper(x0+radius    , y0+h-radius-1, radius, 8, color);
    
    return STAT_SUCCESS;
}

STATUS_T OledFillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color)
{
    // smarter version
    OledFillRect(x0+radius, y0, w-2*radius, h, color);

    // draw four corners
    OledFillCircleHelper(x0+w-radius-1, y0+radius, radius, 1, h-2*radius-1, color);
    OledFillCircleHelper(x0+radius    , y0+radius, radius, 2, h-2*radius-1, color);
    
    return STAT_SUCCESS;
}

STATUS_T OledDrawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color, uint16_t bg)
{
    int16_t i, j, byteWidth = (w + 7) / 8;
  
    for(j=0; j<h; j++) {
        for(i=0; i<w; i++ ) {
            if(*(bitmap + j * byteWidth + i / 8) & (128 >> (i & 7))) {
                OledDrawPixel(x+i, y+j, color);
            }
            else {
                OledDrawPixel(x+i, y+j, bg);
            }
        }
    }
    
    return STAT_SUCCESS;
}

STATUS_T OledDrawXBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color)
{
    int16_t i, j, byteWidth = (w + 7) / 8;
  
    for(j=0; j<h; j++) {
        for(i=0; i<w; i++ ) {
            if(*(bitmap + j * byteWidth + i / 8) & (1 << (i % 8))) {
                OledDrawPixel(x+i, y+j, color);
            }
        }
    }
    
    return STAT_SUCCESS;
}

STATUS_T OledDrawGlobe(void){
//    return OledDrawBitmap(64-20,40-20,globe_bmp,40,39,WHITE,BLACK);
    return OledDrawXBitmap(64-20,40-20,globe_bmp,40,39,WHITE);
}

#endif //__USE_OLEDDISP__