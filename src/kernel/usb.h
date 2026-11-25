// RPG-OS - USB Driver Header
#ifndef USB_H
#define USB_H

#include "types.h"

// USB-Konstanten
#define USB_CLASS_PER_INTERFACE   0
#define USB_CLASS_AUDIO           1
#define USB_CLASS_COMM            2
#define USB_CLASS_HID             3
#define USB_CLASS_PHYSICAL        5
#define USB_CLASS_IMAGE           6
#define USB_CLASS_PRINTER         7
#define USB_CLASS_MASS_STORAGE    8
#define USB_CLASS_HUB             9
#define USB_CLASS_CDC_DATA        0x0a
#define USB_CLASS_SMART_CARD      0x0b
#define USB_CLASS_CONTENT_SECURITY 0x0d
#define USB_CLASS_VIDEO           0x0e
#define USB_CLASS_WIRELESS        0xdc
#define USB_CLASS_APPLICATION     0xfe
#define USB_CLASS_VENDOR_SPEC     0xff

// USB-Typen
#define USB_TYPE_STANDARD   0
#define USB_TYPE_CLASS      1
#define USB_TYPE_VENDOR     2

// USB-Request-Types
#define USB_REQ_GET_STATUS        0
#define USB_REQ_CLEAR_FEATURE     1
#define USB_REQ_SET_FEATURE       3
#define USB_REQ_SET_ADDRESS       5
#define USB_REQ_GET_DESCRIPTOR    6
#define USB_REQ_SET_DESCRIPTOR    7
#define USB_REQ_GET_CONFIGURATION 8
#define USB_REQ_SET_CONFIGURATION 9
#define USB_REQ_GET_INTERFACE     10
#define USB_REQ_SET_INTERFACE     11
#define USB_REQ_SYNCH_FRAME       12

// USB-Descriptoren
#define USB_DESC_DEVICE           1
#define USB_DESC_CONFIG           2
#define USB_DESC_STRING           3
#define USB_DESC_INTERFACE        4
#define USB_DESC_ENDPOINT         5
#define USB_DESC_HID              0x21
#define USB_DESC_REPORT           0x22

// Externe USB-Funktionen
void usb_init();
void usb_hub_init();
void usb_device_enumerate();
void usb_keyboard_init();
void usb_mouse_init();
uint8_t usb_inb(uint16_t port);
void usb_outb(uint16_t port, uint8_t value);

#endif // USB_H
