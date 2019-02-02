#ifndef PLAY_H
#define PLAY_H

unsigned char play_data[] = {
	0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 
	0x00, 0x00, 0x00, 0x0D, 0x49, 0x48, 0x44, 0x52, 0x00, 
	0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x18, 0x08, 0x06, 
	0x00, 0x00, 0x00, 0xE0, 0x77, 0x3D, 0xF8, 0x00, 0x00, 
	0x00, 0x04, 0x67, 0x41, 0x4D, 0x41, 0x00, 0x00, 0xB1, 
	0x8F, 0x0B, 0xFC, 0x61, 0x05, 0x00, 0x00, 0x00, 0x01, 
	0x73, 0x52, 0x47, 0x42, 0x00, 0xAE, 0xCE, 0x1C, 0xE9, 
	0x00, 0x00, 0x00, 0x20, 0x63, 0x48, 0x52, 0x4D, 0x00, 
	0x00, 0x7A, 0x26, 0x00, 0x00, 0x80, 0x84, 0x00, 0x00, 
	0xFA, 0x00, 0x00, 0x00, 0x80, 0xE8, 0x00, 0x00, 0x75, 
	0x30, 0x00, 0x00, 0xEA, 0x60, 0x00, 0x00, 0x3A, 0x98, 
	0x00, 0x00, 0x17, 0x70, 0x9C, 0xBA, 0x51, 0x3C, 0x00, 
	0x00, 0x00, 0x06, 0x62, 0x4B, 0x47, 0x44, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0xF9, 0x43, 0xBB, 0x7F, 0x00, 
	0x00, 0x00, 0x09, 0x70, 0x48, 0x59, 0x73, 0x00, 0x00, 
	0x00, 0x48, 0x00, 0x00, 0x00, 0x48, 0x00, 0x46, 0xC9, 
	0x6B, 0x3E, 0x00, 0x00, 0x00, 0xFA, 0x49, 0x44, 0x41, 
	0x54, 0x48, 0xC7, 0xED, 0x93, 0xB1, 0x4A, 0x03, 0x41, 
	0x10, 0x86, 0xE7, 0x5F, 0x72, 0x85, 0x72, 0xAD, 0x0F, 
	0x60, 0x61, 0x69, 0x69, 0x27, 0x47, 0x6E, 0x59, 0xF0, 
	0x09, 0x7C, 0x84, 0x24, 0x82, 0xB5, 0x98, 0x47, 0x10, 
	0x1F, 0x41, 0xDF, 0x20, 0xE9, 0xAE, 0x4A, 0x60, 0x67, 
	0x4F, 0xAF, 0x0C, 0x29, 0x44, 0x6C, 0x92, 0xCA, 0xDE, 
	0xC2, 0x07, 0x38, 0xD8, 0x49, 0xA3, 0x90, 0x22, 0xC9, 
	0xED, 0x85, 0x4B, 0x11, 0xB8, 0xAF, 0xDD, 0x7F, 0xE6, 
	0x63, 0x66, 0x58, 0xA2, 0x96, 0x16, 0x6B, 0xED, 0x73, 
	0x96, 0x65, 0xA7, 0xFB, 0xD6, 0xAB, 0xAA, 0x00, 0x80, 
	0x87, 0x38, 0x8E, 0xBF, 0x9C, 0x73, 0x37, 0x07, 0x11, 
	0x10, 0x11, 0x89, 0xC8, 0xB9, 0x88, 0x4C, 0x98, 0x79, 
	0x54, 0x14, 0xC5, 0x59, 0xE3, 0x82, 0x35, 0x6E, 0xCB, 
	0xB2, 0x5C, 0x38, 0xE7, 0xFA, 0x22, 0x82, 0x90, 0x82, 
	0xCA, 0x10, 0x33, 0xCB, 0x96, 0xD5, 0xBD, 0x79, 0xEF, 
	0x07, 0xC6, 0x98, 0x65, 0x93, 0x13, 0xAC, 0xAF, 0xAD, 
	0x0B, 0xE0, 0x83, 0x99, 0x1F, 0xF3, 0x3C, 0xEF, 0x34, 
	0x2E, 0xF8, 0xE3, 0x84, 0x88, 0x9E, 0xBC, 0xF7, 0x73, 
	0x6B, 0xED, 0xD5, 0x21, 0x04, 0xFF, 0x5C, 0x28, 0xA5, 
	0xAE, 0x37, 0x3D, 0x74, 0xEA, 0x76, 0xDA, 0xC0, 0x3B, 
	0x80, 0x81, 0xD6, 0x7A, 0xD1, 0xB4, 0xE0, 0x17, 0xC0, 
	0x30, 0x4D, 0xD3, 0x57, 0x00, 0xB2, 0x2D, 0xB4, 0xAF, 
	0x60, 0x1C, 0x45, 0xD1, 0x7D, 0x92, 0x24, 0x3F, 0x55, 
	0xC1, 0xBA, 0x82, 0x6F, 0x00, 0x77, 0x5A, 0xEB, 0x69, 
	0x68, 0x41, 0xE8, 0x91, 0xBD, 0x88, 0xBC, 0x28, 0xA5, 
	0x2E, 0xEB, 0x34, 0x0F, 0x9D, 0xE0, 0x93, 0x88, 0x7A, 
	0xC6, 0x98, 0x59, 0xCD, 0x69, 0xC3, 0xD8, 0xF5, 0x89, 
	0x5A, 0x8E, 0x83, 0x15, 0x25, 0x2A, 0x4F, 0x62, 0x6D, 
	0x2D, 0xB3, 0xC4, 0x00, 0x00, 0x00, 0x25, 0x74, 0x45, 
	0x58, 0x74, 0x64, 0x61, 0x74, 0x65, 0x3A, 0x63, 0x72, 
	0x65, 0x61, 0x74, 0x65, 0x00, 0x32, 0x30, 0x31, 0x39, 
	0x2D, 0x30, 0x32, 0x2D, 0x30, 0x32, 0x54, 0x31, 0x38, 
	0x3A, 0x30, 0x34, 0x3A, 0x31, 0x33, 0x2B, 0x30, 0x30, 
	0x3A, 0x30, 0x30, 0x14, 0xA3, 0xB6, 0xFF, 0x00, 0x00, 
	0x00, 0x25, 0x74, 0x45, 0x58, 0x74, 0x64, 0x61, 0x74, 
	0x65, 0x3A, 0x6D, 0x6F, 0x64, 0x69, 0x66, 0x79, 0x00, 
	0x32, 0x30, 0x31, 0x39, 0x2D, 0x30, 0x32, 0x2D, 0x30, 
	0x32, 0x54, 0x31, 0x38, 0x3A, 0x30, 0x34, 0x3A, 0x31, 
	0x33, 0x2B, 0x30, 0x30, 0x3A, 0x30, 0x30, 0x65, 0xFE, 
	0x0E, 0x43, 0x00, 0x00, 0x00, 0x28, 0x74, 0x45, 0x58, 
	0x74, 0x73, 0x76, 0x67, 0x3A, 0x62, 0x61, 0x73, 0x65, 
	0x2D, 0x75, 0x72, 0x69, 0x00, 0x66, 0x69, 0x6C, 0x65, 
	0x3A, 0x2F, 0x2F, 0x2F, 0x74, 0x6D, 0x70, 0x2F, 0x6D, 
	0x61, 0x67, 0x69, 0x63, 0x6B, 0x2D, 0x63, 0x32, 0x63, 
	0x55, 0x51, 0x47, 0x58, 0x54, 0x2E, 0x5E, 0x98, 0xD0, 
	0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4E, 0x44, 0xAE, 
	0x42, 0x60, 0x82
};
unsigned long play_size = 569;

#endif // PLAY_H

