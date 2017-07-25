#ifndef SENSOR_ARDUINO_NANOPB_H
#define SENSOR_ARDUINO_NANOPB_H

#if ARDUINO >= 100
#include "Arduino.h"
#endif

#include <pb_encode.h>
#include <pb_decode.h>
#include <simple.pb.h>

#define NANOPB_BUFFER_SIZE 256

class ARDUINO_NANOPB {
 private:
  uint8_t buffer[NANOPB_BUFFER_SIZE];
  size_t message_length;
  bool status;

 public:
  /**
   * [ARDUINO_NANOPB constructor]
   */
  ARDUINO_NANOPB();

  /**
   * [nanoEncoder encode message]
   * @param  msg [pointer to char array]
   * @return     [encoded uint8_t array]
   */
  uint8_t* nanoEncoder(char* msg);
  /**
   * [nanoDecoder decode message]
   * @param  buffer [encoded uint8_t array]
   * @return        [decoded pointer to char array]
   */
  char* nanoDecoder(uint8_t buffer[NANOPB_BUFFER_SIZE]);
};
#endif
