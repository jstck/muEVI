#ifndef _MENU_H
#define _MENU_H


#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#ifndef SSD1306_128_64
#error("Display type incorrect, please change Adafruit_SSD1306.h to use SSD1306_128_64 (128x64) display.");
#endif


#define MENU_ROW_HEIGHT 9
#define MENU_HEADER_OFFSET 3

#define OLED_RESET 4

void initDisplay();
void showVersion();
void menu();
void drawSensorPixels();

int readTrills();
void setFPS(int trills);
void clearFPS(int trills);


//display states
#define DISPLAYOFF_IDL 0
#define MAIN_MENU 1
#define PATCH_VIEW 2
#define BREATH_ADJ_IDL 10
#define BREATH_ADJ_THR 11
#define BREATH_ADJ_MAX 12
#define PORTAM_ADJ_IDL 20
#define PORTAM_ADJ_THR 21
#define PORTAM_ADJ_MAX 22
#define PITCHB_ADJ_IDL 30
#define PITCHB_ADJ_THR 31
#define PITCHB_ADJ_MAX 32
#define EXTRAC_ADJ_IDL 40
#define EXTRAC_ADJ_THR 41
#define EXTRAC_ADJ_MAX 42
#define VIBRAT_ADJ_IDL 50
#define VIBRAT_ADJ_THR 51
#define VIBRAT_ADJ_DPT 52
#define CTOUCH_ADJ_IDL 60
#define CTOUCH_ADJ_THR 61
#define SETUP_BR_MENU 80
#define SETUP_CT_MENU 90
#define ROTATOR_MENU 100
#define VIBRATO_MENU 110

#endif //_MENU_H