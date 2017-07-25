# ARDUINO_NANOPB
Simple String NanoPB encode and decode library. 

# Use:
 * Import to your Arduino libraries folder.
 * Import <ARDUINO_NANOPB.h> to your sketch.
 
 ```
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
```


You can adjust the size of your String:
```
/* Struct definitions */
typedef struct _SimpleMessage {
    char request[256];
/* @@protoc_insertion_point(struct:SimpleMessage) */
} SimpleMessage;

/* Maximum encoded size of messages (where known) */
#define SimpleMessage_size                       259
```
See how to build your custom library in [NanoPB](https://github.com/nanopb/nanopb) repository.
