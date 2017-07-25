#include "ARDUINO_NANOPB.h"

/**
 * [ARDUINO_NANOPB constructor]
 */
ARDUINO_NANOPB::ARDUINO_NANOPB(){};

/**
 * [nanoEncoder encode message]
 * @param  msg [pointer to char array]
 * @return     [encoded uint8_t array]
 */
uint8_t* ARDUINO_NANOPB::nanoEncoder(char* msg) {
  SimpleMessage message = SimpleMessage_init_zero;

  /* Create a stream that will write to our buffer. */
  pb_ostream_t stream = pb_ostream_from_buffer(buffer, sizeof(buffer));

  /* Fill in the lucky number */
  strcpy(message.request, msg);

  /* Now we are ready to encode the message! */
  status = pb_encode(&stream, SimpleMessage_fields, &message);
  message_length = stream.bytes_written;

  /* Then just check for any errors.. */
  if (!status) {
    Serial.print(PB_GET_ERROR(&stream));
  }
  return buffer;
}

/**
 * [nanoDecoder decode message]
 * @param  buffer [encoded uint8_t array]
 * @return        [decoded pointer to char array]
 */
char* ARDUINO_NANOPB::nanoDecoder(uint8_t buffer[NANOPB_BUFFER_SIZE]) {
  /* Allocate space for the decoded message. */
  SimpleMessage message = SimpleMessage_init_zero;

  /* Create a stream that reads from the buffer. */
  pb_istream_t stream = pb_istream_from_buffer(buffer, message_length);

  /* Now we are ready to decode the message. */
  status = pb_decode(&stream, SimpleMessage_fields, &message);

  /* Check for errors... */
  if (!status) {
    Serial.print(PB_GET_ERROR(&stream));
  }
  return message.request;
}
