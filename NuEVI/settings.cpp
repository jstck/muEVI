#include <EEPROM.h>
#include <Arduino.h>

#include "settings.h"
#include "midi.h"

void writeSetting(uint8_t address, uint16_t value){
  union {
    byte v[2];
    uint16_t val;
  } data;
  data.val = value;
  EEPROM.write(address, data.v[0]);
  EEPROM.write(address+1, data.v[1]);
}

uint16_t readSetting(uint8_t address){
  union {
    byte v[2];
    uint16_t val;
  } data;
  data.v[0] = EEPROM.read(address);
  data.v[1] = EEPROM.read(address+1);
  return data.val;
}



void readSettings(nueviconfig* c){
  EEPROM.get(0, c);
}


void dumpSettings(const nueviconfig* c) {
  uint8_t *sysex_data;

const char *header = "NuEVIc00"; //NuEVI config dump 00

  //Build an array of all the config prefixed with manufacturer id + "nuevi config dump" signal
  //Array is size of config + 11 bytes, 3 bytes id and 8 bytes header
  sysex_data = (uint8_t*)malloc(3 + strlen(header) + sizeof(nueviconfig));

  

  memcpy(sysex_data, sysex_id, 3);
  memcpy(sysex_data+3, header, strlen(header));
  memcpy(sysex_data+3+strlen(header), c, sizeof(nueviconfig));

  usbMIDI.sendSysEx(sizeof(sysex_data), sysex_data);
}