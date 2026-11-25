/**
 * RPG-OS - USB Driver
 */

#include "usb.h"
#include "types.h"

// USB-I/O-Ports (OHCI)
#define USB_OHCI_HCCBASE  0xD0000000
#define USB_OHCI_OHCI     0xD0001000

// PCI-Konfigurations-Space
#define PCI_CONFIG_ADDRESS 0xCF8
#define PCI_CONFIG_DATA    0xCFC

// USB-Controller-Register (OHCI)
#define OHCI_HcRevision       0x00
#define OHCI_HcControl        0x04
#define OHCI_HcCommandStatus  0x08
#define OHCI_HcInterruptStatus 0x0C
#define OHCI_HcInterruptMask   0x10
#define OHCI_HcHCCA           0x14
#define OHCI_HcPeriodCurrentED 0x18
#define OHCI_HcControlHeadED  0x1C
#define OHCI_HcBulkHeadED     0x20
#define OHCI_HcDoneHead       0x24
#define OHCI_HcFrameInterval  0x28
#define OHCI_HcFmRemaining    0x2C
#define OHCI_HcFmNumber       0x30
#define OHCI_HcPeriodStart    0x34
#define OHCI_HcLSThreshold    0x38

// Hilfsfunktion: PCI konfigurieren
static uint32_t pci_read_config(uint8_t bus, uint8_t slot, uint8_t func, uint8_t offset) {
    uint32_t address = (1 << 31) | ((uint32_t)bus << 16) | ((uint32_t)slot << 11) | 
                       ((uint32_t)func << 8) | offset;
    outl(PCI_CONFIG_ADDRESS, address);
    return inl(PCI_CONFIG_DATA);
}

// USB-Controller initialisieren
void usb_init() {
    // PCI-Controller durchsuchen
    uint32_t id = pci_read_config(0, 0x12, 0, 0);
    
    // USB-Controller finden (Vendor ID 0x8086 = Intel)
    if (id == 0x808624C2) {
        // OHCI-Controller
        outl(0xCF8, 0x80000040);
        uint32_t base = inl(0xCFC);
        base &= 0xFFF0;
        
        // OHCI-Register initialisieren
        volatile uint32_t* ohci = (volatile uint32_t*)base;
        ohci[OHCI_HcControl / 4] = 0;  // HcControl = 0 (Reset)
    }
}

// USB-Hub initialisieren
void usb_hub_init() {
    // Hub-Port-Status lesen
    // TODO: Implementierung
}

// USB-Geräte aufzählen
void usb_device_enumerate() {
    // Geräte-Enumeration
    // TODO: Implementierung
}

// USB-Tastatur initialisieren
void usb_keyboard_init() {
    // USB-Tastatur-Setup
    // TODO: Implementierung
}

// USB-Maus initialisieren
void usb_mouse_init() {
    // USB-Maus-Setup
    // TODO: Implementierung
}

// USB Einlesen (byte)
uint8_t usb_inb(uint16_t port) {
    return inb(port);
}

// USB Ausgeben (byte)
void usb_outb(uint16_t port, uint8_t value) {
    outb(port, value);
}
