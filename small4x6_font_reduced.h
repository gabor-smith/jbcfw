#ifndef Small4x6PL_font_h
#define Small4x6PL_font_h


const uint8_t Small4x6PL[] PROGMEM =//KEEP: ADEOSLPTH c
{
5, 7, '/', 'C',   // -width, height, firstChar, lastChar
        /*0x03, 0x00, 0x00, 0x00, 0x00, 0x00,      //  
        0x01, 0x2F, 0x00, 0x00, 0x00, 0x00,      // !
        0x03, 0x03, 0x00, 0x03, 0x00, 0x00,      // "
        0x05, 0x14, 0x3E, 0x14, 0x3E, 0x14,      // #
        0x05, 0x24, 0x2A, 0x7F, 0x2A, 0x12,      // $
        0x03, 0x31, 0x0C, 0x23, 0x00, 0x00,      // %
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00,      // &
        0x03, 0x02, 0x05, 0x02, 0x00, 0x00,      // '
        0x02, 0x1E, 0x21, 0x00, 0x00, 0x00,      // (
        0x02, 0x21, 0x1E, 0x00, 0x00, 0x00,      // )
        0x05, 0x14, 0x08, 0x1C, 0x08, 0x14,      // *
        0x03, 0x08, 0x1C, 0x08, 0x00, 0x00,      // +
        0x02, 0x40, 0x20, 0x00, 0x00, 0x00,      // ,
        0x03, 0x08, 0x08, 0x08, 0x00, 0x00,      // -
        0x01, 0x20, 0x00, 0x00, 0x00, 0x00,      // .*/
        0x03, 0x02, 0x05, 0x02, 0x00, 0x00,      // '      // /
        0x04, 0x1E, 0x21, 0x21, 0x1E, 0x00,      // 0
        0x03, 0x22, 0x3F, 0x20, 0x00, 0x00,      // 1
        0x04, 0x32, 0x29, 0x29, 0x26, 0x00,      // 2
        0x04, 0x11, 0x25, 0x25, 0x1A, 0x00,      // 3
        0x04, 0x18, 0x14, 0x12, 0x3F, 0x00,      // 4
        0x04, 0x27, 0x25, 0x25, 0x19, 0x00,      // 5
        0x04, 0x1E, 0x25, 0x25, 0x18, 0x00,      // 6
        0x04, 0x01, 0x31, 0x09, 0x07, 0x00,      // 7
        0x04, 0x1A, 0x25, 0x25, 0x1A, 0x00,      // 8
        0x04, 0x06, 0x29, 0x29, 0x1E, 0x00,      // 9
        0x04, 0x3E, 0x09, 0x09, 0x3E, 0x00,      // A      // :
        0x04, 0x3F, 0x21, 0x21, 0x1E, 0x00,      // D      // ;
        0x04, 0x3F, 0x25, 0x25, 0x21, 0x00,      // E      // <
        0x04, 0x1E, 0x21, 0x21, 0x1E, 0x00,      // O      // =
        0x04, 0x12, 0x25, 0x25, 0x18, 0x00,      // S      // >
        0x04, 0x3F, 0x20, 0x20, 0x20, 0x00,      // L      // ?
        0x04, 0x3F, 0x09, 0x09, 0x06, 0x00,      // P      // @
        0x03, 0x01, 0x3F, 0x01, 0x00, 0x00,      // T      // A
        0x04, 0x3F, 0x04, 0x04, 0x3F, 0x00,      // H      // B
        0x04, 0x1C, 0x22, 0x22, 0x14, 0x00,      // c      // C
        //0x04, 0x3F, 0x21, 0x21, 0x1E, 0x00,      // D
        //0x04, 0x3F, 0x25, 0x25, 0x21, 0x00,      // E
        /*0x04, 0x3F, 0x05, 0x05, 0x01, 0x00,      // F
        0x04, 0x1E, 0x21, 0x29, 0x1A, 0x00,      // G
        0x04, 0x3F, 0x04, 0x04, 0x3F, 0x00,      // H
        0x01, 0x3F, 0x00, 0x00, 0x00, 0x00,      // I
        0x04, 0x11, 0x21, 0x21, 0x1F, 0x00,      // J
        0x04, 0x3F, 0x04, 0x0A, 0x31, 0x00,      // K
        0x04, 0x3F, 0x20, 0x20, 0x20, 0x00,      // L
        0x05, 0x3F, 0x02, 0x1C, 0x02, 0x3F,      // M
        0x04, 0x3F, 0x02, 0x04, 0x3F, 0x00,      // N
        0x04, 0x1E, 0x21, 0x21, 0x1E, 0x00,      // O
        0x04, 0x3F, 0x09, 0x09, 0x06, 0x00,      // P
        0x04, 0x1E, 0x21, 0x21, 0x5E, 0x00,      // Q
        0x04, 0x3F, 0x09, 0x09, 0x36, 0x00,      // R
        0x04, 0x12, 0x25, 0x25, 0x18, 0x00,      // S
        0x03, 0x01, 0x3F, 0x01, 0x00, 0x00,      // T
        0x04, 0x1F, 0x20, 0x20, 0x1F, 0x00,      // U
        0x05, 0x03, 0x0C, 0x30, 0x0C, 0x03,      // V
        0x05, 0x0F, 0x30, 0x0C, 0x30, 0x0F,      // W
        0x05, 0x31, 0x0A, 0x04, 0x0A, 0x31,      // X
        0x05, 0x01, 0x02, 0x3C, 0x02, 0x01,      // Y
        0x04, 0x31, 0x29, 0x25, 0x23, 0x00,      // Z
        0x02, 0x3F, 0x21, 0x00, 0x00, 0x00,      // [
        0x05, 0x01, 0x02, 0x04, 0x08, 0x10,      // BackSlash
        0x02, 0x21, 0x3F, 0x00, 0x00, 0x00,      // ]
        0x03, 0x02, 0x01, 0x02, 0x00, 0x00,      // ^
        0x04, 0x40, 0x40, 0x40, 0x40, 0x00,      // _
        0x02, 0x01, 0x02, 0x00, 0x00, 0x00,      // `
        0x05, 0x10, 0x2A, 0x2A, 0x1C, 0x20,      // a
        0x04, 0x1F, 0x24, 0x22, 0x1C, 0x00,      // b
        0x04, 0x1C, 0x22, 0x22, 0x14, 0x00,      // c
        0x04, 0x1C, 0x22, 0x24, 0x3F, 0x00,      // d
        0x04, 0x1C, 0x2A, 0x2A, 0x0C, 0x00,      // e
        0x03, 0x04, 0x3E, 0x05, 0x00, 0x00,      // f
        0x04, 0x4C, 0x52, 0x52, 0x2C, 0x00,      // g
        0x04, 0x3F, 0x04, 0x04, 0x38, 0x00,      // h
        0x01, 0x3D, 0x00, 0x00, 0x00, 0x00,      // i
        0x03, 0x40, 0x40, 0x3D, 0x00, 0x00,      // j
        0x04, 0x3F, 0x08, 0x14, 0x20, 0x00,      // k
        0x02, 0x1F, 0x20, 0x00, 0x00, 0x00,      // l
        0x05, 0x3C, 0x02, 0x0C, 0x02, 0x3C,      // m
        0x04, 0x3E, 0x02, 0x02, 0x3C, 0x00,      // n
        0x04, 0x1C, 0x22, 0x22, 0x1C, 0x00,      // o
        0x04, 0x7E, 0x12, 0x12, 0x0C, 0x00,      // p
        0x04, 0x0C, 0x12, 0x12, 0x7E, 0x00,      // q
        0x04, 0x3E, 0x04, 0x02, 0x02, 0x00,      // r
        0x04, 0x24, 0x2A, 0x2A, 0x12, 0x00,      // s
        0x03, 0x02, 0x1F, 0x22, 0x00, 0x00,      // t
        0x04, 0x1E, 0x20, 0x20, 0x3E, 0x00,      // u
        0x05, 0x0E, 0x10, 0x20, 0x10, 0x0E,      // v
        0x05, 0x0E, 0x30, 0x0C, 0x30, 0x0E,      // w
        0x05, 0x22, 0x14, 0x08, 0x14, 0x22,      // x
        0x04, 0x0E, 0x50, 0x50, 0x3E, 0x00,      // y
        0x04, 0x32, 0x2A, 0x2A, 0x26, 0x00,      // z
        0x03, 0x04, 0x1A, 0x21, 0x00, 0x00,      // {
        0x01, 0x3F, 0x00, 0x00, 0x00, 0x00,      // |
        0x03, 0x21, 0x1A, 0x04, 0x00, 0x00,      // }
        0x04, 0x02, 0x01, 0x02, 0x01, 0x00,      // ~
        0x05, 0x7F, 0x41, 0x41, 0x41, 0x7F,     // 

        /*0x04, 0x3E, 0x09, 0x09, 0x3E, 0x00,      // Ą
        0x04, 0x1C, 0x26, 0x23, 0x22, 0x00,      // 
        0x05, 0x3F, 0x25, 0x25, 0x61, 0x40,      // ‚
        0x04, 0x3F, 0x24, 0x22, 0x20, 0x00,      // 
        0x04, 0x3E, 0x05, 0x0B, 0x3C, 0x00,      // „
        0x04, 0x1C, 0x26, 0x23, 0x1C, 0x00,      // …
        0x04, 0x04, 0x2E, 0x2B, 0x12, 0x00,      // †
        0x04, 0x22, 0x36, 0x2B, 0x26, 0x00,      // ‡
        0x04, 0x29, 0x39, 0x2D, 0x2B, 0x00,      // 

        0x05, 0x10, 0x2A, 0x2A, 0x7C, 0x40,      // ą
        0x04, 0x1C, 0x22, 0x23, 0x14, 0x00,      // Š
        0x04, 0x1C, 0x2A, 0x6A, 0x4C, 0x00,      // ‹
        0x03, 0x08, 0x1F, 0x22, 0x00, 0x00,      // Ś
        0x04, 0x3C, 0x06, 0x05, 0x38, 0x00,      // Ť
        0x04, 0x1C, 0x22, 0x22, 0x1D, 0x00,      // Ž
        0x04, 0x24, 0x2A, 0x2B, 0x12, 0x00,      // Ź
        0x04, 0x32, 0x2B, 0x2A, 0x26, 0x00,      // 
        0x04, 0x32, 0x2A, 0x2B, 0x26, 0x00,*/      // ‘

        //0x05, 0x3E, 0x55, 0x61, 0x55, 0x3E,      // ’
        //0x05, 0x3E, 0x65, 0x51, 0x65, 0x3E,      // “
};

#endif

