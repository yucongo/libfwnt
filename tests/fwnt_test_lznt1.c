/*
 * Library LZNT1 decompression testing program
 *
 * Copyright (C) 2009-2016, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <memory.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include <stdio.h>

#include "fwnt_test_libcerror.h"
#include "fwnt_test_libcstring.h"
#include "fwnt_test_libfwnt.h"
#include "fwnt_test_macros.h"
#include "fwnt_test_unused.h"

uint8_t fwnt_test_lznt1_compressed_byte_stream[ 4064 ] = {
	0x67, 0xb8, 0x00, 0x09, 0x09, 0x20, 0x20, 0x20, 0x47, 0x4e, 0x55, 0x00, 0x20, 0x4c, 0x45, 0x53,
	0x53, 0x45, 0x52, 0x20, 0x00, 0x47, 0x45, 0x4e, 0x45, 0x52, 0x41, 0x4c, 0x20, 0x80, 0x50, 0x55,
	0x42, 0x4c, 0x49, 0x43, 0x20, 0x00, 0x18, 0x60, 0x45, 0x4e, 0x53, 0x45, 0x0a, 0x00, 0x90, 0x11,
	0x08, 0x56, 0x00, 0x65, 0x72, 0x73, 0x69, 0x6f, 0x6e, 0x20, 0x33, 0x00, 0x2c, 0x20, 0x32, 0x39,
	0x20, 0x4a, 0x75, 0x6e, 0x00, 0x65, 0x20, 0x32, 0x30, 0x30, 0x37, 0x0a, 0x0a, 0x00, 0x20, 0x43,
	0x6f, 0x70, 0x79, 0x72, 0x69, 0x67, 0x40, 0x68, 0x74, 0x20, 0x28, 0x43, 0x29, 0x02, 0x28, 0x20,
	0x00, 0x46, 0x72, 0x65, 0x65, 0x20, 0x53, 0x6f, 0x66, 0x00, 0x74, 0x77, 0x61, 0x72, 0x65, 0x20,
	0x46, 0x6f, 0x20, 0x75, 0x6e, 0x64, 0x61, 0x74, 0x00, 0x7a, 0x2c, 0x20, 0x00, 0x49, 0x6e, 0x63,
	0x2e, 0x20, 0x3c, 0x68, 0x74, 0x00, 0x74, 0x70, 0x3a, 0x2f, 0x2f, 0x66, 0x73, 0x66, 0x00, 0x2e,
	0x6f, 0x72, 0x67, 0x2f, 0x3e, 0x0a, 0x20, 0x40, 0x45, 0x76, 0x65, 0x72, 0x79, 0x6f, 0x00, 0x54,
	0x69, 0x00, 0x73, 0x20, 0x70, 0x65, 0x72, 0x6d, 0x69, 0x74, 0x00, 0x74, 0x65, 0x64, 0x20, 0x74,
	0x6f, 0x20, 0x63, 0x01, 0x00, 0x5d, 0x20, 0x61, 0x6e, 0x64, 0x20, 0x64, 0x69, 0x00, 0x73, 0x74,
	0x72, 0x69, 0x62, 0x75, 0x74, 0x65, 0x2a, 0x20, 0x00, 0x2b, 0x62, 0x00, 0x4f, 0x6d, 0x01, 0x1c,
	0x69, 0x65, 0x00, 0x73, 0x0a, 0x20, 0x6f, 0x66, 0x20, 0x74, 0x68, 0x01, 0x00, 0x39, 0x6c, 0x69,
	0x63, 0x65, 0x6e, 0x73, 0x65, 0x00, 0x20, 0x64, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x08, 0x74,
	0x2c, 0x20, 0x00, 0x2f, 0x20, 0x63, 0x68, 0x61, 0x00, 0x6e, 0x67, 0x69, 0x6e, 0x67, 0x20, 0x69,
	0x74, 0x02, 0x20, 0x00, 0x12, 0x6e, 0x6f, 0x74, 0x20, 0x61, 0x6c, 0x80, 0x6c, 0x6f, 0x77, 0x65,
	0x64, 0x2e, 0x0a, 0x80, 0x5f, 0xbc, 0x20, 0x54, 0x01, 0x1d, 0x80, 0x29, 0x82, 0x6f, 0x02, 0x25,
	0x65, 0x83, 0x93, 0x00, 0x65, 0x73, 0x73, 0x65, 0x72, 0x20, 0x47, 0x65, 0x00, 0x6e, 0x65, 0x72,
	0x61, 0x6c, 0x20, 0x50, 0x75, 0x12, 0x62, 0x80, 0x2f, 0x20, 0x4c, 0x84, 0x31, 0x69, 0x6e, 0x63,
	0x80, 0x6f, 0x72, 0x70, 0x6f, 0x72, 0x61, 0x74, 0x80, 0x40, 0xa0, 0x74, 0x68, 0x65, 0x20, 0x74,
	0x00, 0x5b, 0x73, 0x02, 0x55, 0xa0, 0x63, 0x6f, 0x6e, 0x64, 0x69, 0x81, 0x77, 0x73, 0x81, 0x4c,
	0x5d, 0x85, 0x2c, 0x33, 0x03, 0x53, 0x83, 0x2d, 0x0b, 0x2a, 0x0a, 0x04, 0x2a, 0x2c, 0x80, 0x20,
	0x73, 0x75, 0x70, 0x70, 0x6c, 0x65, 0x81, 0x5d, 0x09, 0x00, 0x7f, 0x62, 0x79, 0x00, 0x6b, 0x65,
	0x20, 0x61, 0x64, 0x17, 0x83, 0x26, 0x80, 0x41, 0x02, 0x8d, 0x73, 0x01, 0x54, 0x73, 0x20, 0x6c,
	0x1b, 0x00, 0x88, 0x01, 0x12, 0x65, 0x00, 0x65, 0x00, 0x64, 0x20, 0x20, 0x30, 0x08, 0x2e, 0x20,
	0x41, 0x07, 0x15, 0x44, 0x65, 0x66, 0x69, 0x12, 0x6e, 0x83, 0x42, 0x2e, 0x20, 0x01, 0x73, 0x41,
	0x73, 0x20, 0x04, 0x75, 0x73, 0x00, 0x0c, 0x68, 0x65, 0x72, 0x65, 0x69, 0x30, 0x6e, 0x2c, 0x20,
	0x22, 0x82, 0x4c, 0x44, 0x1e, 0x22, 0x20, 0xb8, 0x72, 0x65, 0x66, 0x80, 0x78, 0x81, 0x5c, 0x12,
	0x2c, 0x4c, 0x02, 0x43, 0x5a, 0x0a, 0x13, 0x43, 0x2c, 0x82, 0x3d, 0x01, 0x41, 0x22, 0x01, 0x98,
	0x47, 0x9c, 0x50, 0x4c, 0xdd, 0x13, 0x14, 0x12, 0xc2, 0x31, 0x22, 0x54, 0x40, 0x53, 0x80, 0x4c,
	0x69, 0x62, 0x72, 0x61, 0x72, 0x79, 0xc9, 0x11, 0x0e, 0x61, 0xc0, 0x7b, 0xc0, 0x26, 0x80, 0x30,
	0x77, 0x6f, 0x72, 0x6b, 0xe8, 0x20, 0x67, 0x6f, 0x00, 0x03, 0x6e, 0x40, 0x03, 0x82, 0x49, 0x00,
	0x76, 0x29, 0x05, 0x51, 0x0a, 0x6f, 0x40, 0x22, 0x72, 0x80, 0x4e, 0x61, 0x6e, 0x49, 0xc0, 0x25,
	0x20, 0x41, 0x40, 0x54, 0x69, 0x63, 0xc2, 0x9f, 0x20, 0x10, 0x6f, 0x72, 0x20, 0x61, 0x00, 0xac,
	0x6d, 0x62, 0x69, 0x85, 0x01, 0x0e, 0x57, 0x81, 0x11, 0x61, 0x73, 0x20, 0x64, 0x81, 0x4a, 0x43,
	0x01, 0x12, 0x86, 0x52, 0x41, 0x6e, 0x20, 0x22, 0xc8, 0x0d, 0x22, 0x21, 0xc1, 0x8d, 0x61, 0x6e,
	0x79, 0x20, 0x02, 0x1e, 0x74, 0x68, 0x80, 0x61, 0x74, 0x20, 0x6d, 0x61, 0x6b, 0x65, 0x02, 0x54,
	0x13, 0x41, 0x75, 0x00, 0x1a, 0x69, 0x6e, 0xc0, 0x7f, 0x66, 0x61, 0x63, 0x00, 0x65, 0x20, 0x70,
	0x72, 0x6f, 0x76, 0x69, 0x64, 0x38, 0x65, 0x64, 0x0a, 0x84, 0x6f, 0x44, 0x32, 0xc3, 0xa2, 0x77,
	0x68, 0x98, 0x69, 0x63, 0x68, 0x45, 0xa1, 0xc2, 0x29, 0x77, 0x69, 0x00, 0xac, 0x3c, 0x62, 0x61,
	0x41, 0x66, 0x80, 0xd7, 0xc1, 0x50, 0x04, 0x0c, 0x2e, 0x0a, 0x09, 0x83, 0x70, 0x6e, 0x67, 0xc0,
	0x2c, 0x73, 0x75, 0x62, 0x63, 0xf8, 0x6c, 0x61, 0x73, 0x02, 0x94, 0xc0, 0x41, 0x82, 0x02, 0x86,
	0x2d, 0x83, 0x89, 0x53, 0x84, 0x0d, 0x01, 0x17, 0x64, 0x65, 0x80, 0x90, 0x64, 0x80, 0x0d, 0x6d,
	0x90, 0x6f, 0x64, 0x65, 0x0a, 0x80, 0xb4, 0x75, 0x73, 0xc1, 0xbf, 0x0d, 0xd2, 0x14, 0x20, 0xcb,
	0x14, 0x22, 0x30, 0x41, 0x20, 0x22, 0x43, 0x1e, 0x6f, 0x88, 0x24, 0xe3, 0x1f, 0xa3, 0x1f, 0xc0,
	0x1b, 0x64, 0x75, 0x63, 0x1d, 0xc3, 0x2e, 0x63, 0x82, 0x04, 0x41, 0x0b, 0x00, 0x2b, 0x6c, 0x69,
	0x6e, 0x0a, 0x6b, 0xa3, 0x0c, 0x0a, 0x49, 0x2e, 0x77, 0x69, 0x74, 0x68, 0xcd, 0x60, 0x31, 0x65,
	0x00, 0x67, 0x22, 0x3a, 0x2e, 0x20, 0x00, 0x6e, 0xa0, 0x24, 0x00, 0x61, 0x72, 0x74, 0x69, 0x63,
	0x75, 0x6c, 0x61, 0xee, 0x72, 0xc1, 0x79, 0x49, 0x6f, 0xe4, 0x18, 0x0a, 0x02, 0x07, 0xe3, 0x25,
	0xa1, 0x22, 0x09, 0x0a, 0x12, 0x20, 0x77, 0xc0, 0x36, 0x6d, 0x61, 0x64, 0x65, 0xf1, 0xa1, 0x1d,
	0x61, 0x6c, 0x73, 0xe0, 0x84, 0x40, 0x7a, 0x80, 0x12, 0x21, 0x05, 0xdc, 0x22, 0x4c, 0x20, 0x11,
	0xe0, 0x2f, 0x44, 0x96, 0x22, 0x42, 0x1a, 0x61, 0x4a, 0x14, 0x22, 0x4d, 0x20, 0x62, 0x6d, 0xc0,
	0x68, 0x43, 0x6f, 0x72, 0x30, 0x72, 0x65, 0x73, 0x70, 0xc1, 0x74, 0xa0, 0x2b, 0x53, 0x6f, 0x80,
	0x75, 0x72, 0x63, 0x65, 0x22, 0x20, 0x66, 0xb0, 0x43, 0xa0, 0x6d, 0x65, 0x61, 0x6e, 0x73, 0xc1,
	0x17, 0x0a, 0x71, 0x06, 0x03, 0x42, 0x06, 0x8e, 0x13, 0x2c, 0x20, 0x65, 0x78, 0x63, 0x6c, 0xc4,
	0x75, 0x64, 0x83, 0x21, 0x79, 0x20, 0x73, 0xe2, 0x0b, 0x80, 0x57, 0xbf, 0x60, 0x31, 0x61, 0x0c,
	0x80, 0x86, 0x86, 0x83, 0x8e, 0x07, 0x60, 0x0d, 0x61, 0xe0, 0x96, 0x95, 0x40, 0x88, 0x73, 0x80,
	0x48, 0x72, 0x40, 0x1a, 0x69, 0x6e, 0x80, 0x1c, 0x8c, 0x6f, 0x6c, 0x02, 0x58, 0x00, 0x6d, 0x72,
	0x65, 0x0a, 0xaa, 0x45, 0xcf, 0x68, 0x2d, 0xc3, 0x70, 0xe1, 0x9b, 0x26, 0x49, 0x6e, 0x6b, 0x20,
	0x08, 0x04, 0x21, 0x37, 0xe7, 0x20, 0x6b, 0x19, 0xa9, 0x35, 0x43, 0x00, 0x46, 0x3d, 0x21, 0x6f,
	0x62, 0xb0, 0x6a, 0x65, 0x63, 0x74, 0xe2, 0x19, 0xe1, 0x7e, 0x2f, 0xc0, 0x26, 0x3f, 0x48, 0x1c,
	0x66, 0x22, 0x0a, 0x13, 0xa0, 0xa5, 0x28, 0x22, 0xa0, 0xc1, 0x61, 0x0a, 0x01, 0x81, 0xba, 0x75,
	0x74, 0x69, 0x6c, 0x69, 0x74, 0x79, 0x01, 0x61, 0x66, 0x67, 0x72, 0x61, 0x6d, 0x73, 0x20, 0x6e,
	0xcc, 0x65, 0x65, 0x40, 0x67, 0x62, 0x08, 0x72, 0x65, 0x43, 0x4d, 0xc1, 0x28, 0xe1, 0xcf, 0x24,
	0x66, 0x72, 0x6f, 0x6d, 0xe2, 0x32, 0xca, 0x0c, 0xc1, 0xbd, 0x03, 0x87, 0x2f, 0xa1, 0x06, 0x53,
	0x79, 0x73, 0x74, 0x65, 0x6d, 0x1f, 0x84, 0x4f, 0x80, 0xc5, 0x85, 0xb0, 0xca, 0x49, 0x22, 0x23,
	0x31, 0x2e, 0x20, 0x60, 0x45, 0x78, 0x63, 0x65, 0x70, 0x61, 0x33, 0xc1, 0xa0, 0x53, 0x1f, 0x80,
	0x1c, 0x22, 0xde, 0x45, 0x06, 0x44, 0x9b, 0x82, 0x05, 0x59, 0x6f, 0x75, 0x85, 0x40, 0x80, 0x79,
	0x80, 0x20, 0x6e, 0x76, 0x65, 0x79, 0x20, 0x6d, 0xbe, 0x63, 0xa1, 0x91, 0x60, 0x2d, 0x22, 0x84,
	0xe0, 0xdd, 0x00, 0xc7, 0x73, 0x03, 0x08, 0xc8, 0x73, 0x20, 0x33, 0xc1, 0x24, 0x20, 0x34, 0xe3,
	0x08, 0x07, 0x95, 0x81, 0x22, 0x5c, 0x6f, 0x75, 0x74, 0x20, 0x62, 0x65, 0x61, 0x1c, 0xfe, 0x62,
	0xc1, 0xe4, 0xa1, 0x71, 0xe4, 0x06, 0xc0, 0x06, 0x88, 0xd1, 0x60, 0xaa, 0x02, 0x0f, 0x1c, 0x32,
	0x2e, 0xe0, 0x97, 0x61, 0x0e, 0x41, 0x06, 0x4d, 0x6f, 0x64, 0x28, 0x69, 0x66, 0x69, 0x27, 0x3c,
	0x73, 0x42, 0x04, 0x49, 0x66, 0x9c, 0x20, 0x79, 0xc1, 0x13, 0x81, 0x03, 0x43, 0x13, 0x70, 0x79,
	0x65, 0x18, 0x33, 0xc4, 0x35, 0x92, 0x22, 0x2c, 0x20, 0xa0, 0x25, 0x90, 0x02, 0x72, 0x20, 0xd7,
	0x60, 0x42, 0x70, 0x04, 0x33, 0x52, 0x73, 0xb0, 0x01, 0x0a, 0x80, 0x4c, 0x83, 0x19, 0x81, 0x57,
	0x61, 0x61, 0x20, 0x66, 0x75, 0x6e, 0x63, 0xc2, 0x11, 0xe7, 0x00, 0x1f, 0x11, 0x1c, 0x41, 0x12,
	0x62, 0x65, 0x23, 0x6b, 0x41, 0x08, 0x80, 0x44, 0xbb, 0x10, 0x46, 0xf8, 0x18, 0x0a, 0x92, 0x52,
	0x40, 0x67, 0x12, 0x34, 0x20, 0x46, 0x05, 0x86, 0x28, 0x09, 0x5a, 0x21, 0x73, 0x20, 0x61, 0x72,
	0x67, 0x02, 0x7b, 0x8c, 0x20, 0x70, 0x30, 0x4e, 0x51, 0x14, 0x68, 0x65, 0x6e, 0xd2, 0x1d, 0x43,
	0x36, 0x03, 0x60, 0x13, 0x69, 0x6e, 0x76, 0x6f, 0xe0, 0x2c, 0x29, 0xea, 0x2c, 0x91, 0x01, 0x6e,
	0x33, 0x0e, 0x61, 0x2a, 0x18, 0x77, 0x0e, 0x13, 0x0d, 0x17, 0x40, 0x40, 0x30, 0x62, 0xc1, 0x45,
	0x3a, 0x11, 0x70, 0x20, 0x61, 0x29, 0xf6, 0x20, 0xa3, 0x19, 0xa9, 0x6f, 0x2c, 0x16, 0x5b, 0x70,
	0x05, 0x90, 0x5d, 0xb2, 0x13, 0xc3, 0xd0, 0x5d, 0x40, 0x1d, 0x67, 0x6f, 0x6f, 0x64, 0x60, 0x0b,
	0x11, 0x4c, 0x74, 0x65, 0x66, 0xa0, 0x3b, 0x74, 0x20, 0x0f, 0x01, 0x92, 0x40, 0x86, 0x75, 0xcf,
	0x80, 0x8d, 0xe1, 0x0d, 0x42, 0x14, 0x81, 0x26, 0x65, 0x76, 0x00, 0x87, 0x80, 0x1e, 0xf9, 0xfa,
	0x66, 0x64, 0x6f, 0x40, 0x62, 0x01, 0x39, 0x72, 0x7d, 0x72, 0x5a, 0xf1, 0x03, 0x17, 0x9d, 0x14,
	0x12, 0x0d, 0xf7, 0x11, 0x73, 0x50, 0x31, 0x6c, 0x20, 0x6f, 0xbd, 0xc0, 0x7e, 0x61, 0xc0, 0x85,
	0xb2, 0x1a, 0x41, 0x91, 0x00, 0x08, 0x6d, 0xc0, 0x8e, 0x58, 0x20, 0x20, 0x77, 0x00, 0x68, 0xe0,
	0x06, 0x72, 0xd0, 0x12, 0x72, 0xd2, 0x74, 0x91, 0x1d, 0x69, 0x74, 0x50, 0x93, 0x75, 0xd0, 0x88,
	0xa0, 0x64, 0xe0, 0x72, 0x65, 0x6d, 0x61, 0x69, 0x30, 0x4b, 0x91, 0x4b, 0x30, 0x22, 0xb0, 0x66,
	0x75, 0x6c, 0x2c, 0x60, 0x6f, 0xe2, 0x0f, 0x62, 0xe7, 0x0f, 0xa1, 0x54, 0x88, 0x50, 0x4c, 0x2c,
	0x20, 0x72, 0x56, 0x6e, 0xb1, 0x97, 0x3f, 0xe4, 0x26, 0xff, 0x86, 0x60, 0x30, 0x91, 0x67, 0xa1,
	0x0b, 0x99, 0x13, 0x20, 0x61, 0xe9, 0xa3, 0x75, 0x62, 0x6c, 0xd0, 0x8f, 0x6f, 0xd3, 0x13, 0xf1,
	0x9a, 0x52, 0x28, 0x70, 0x33, 0x2e, 0x20, 0x4f, 0x83, 0x42, 0x31, 0x45, 0x81, 0x9f, 0x6f, 0xe7,
	0xe3, 0x92, 0x82, 0x2b, 0x80, 0x0d, 0x72, 0x69, 0x90, 0x58, 0x62, 0x3c, 0x44, 0x29, 0x08, 0x20,
	0x48, 0x65, 0x10, 0x5d, 0x72, 0x20, 0x46, 0x69, 0xfc, 0x6c, 0x65, 0x93, 0x2c, 0x41, 0x5b, 0xd9,
	0x46, 0x11, 0x10, 0xf1, 0x0e, 0x6b, 0x26, 0x1f, 0x82, 0x38, 0xe8, 0x98, 0xf0, 0x00, 0xb0, 0x78,
	0xd5, 0x05, 0x0a, 0x61, 0x20, 0xba, 0x68, 0x73, 0x05, 0x66, 0x70, 0x05, 0x43, 0x0a, 0xc0, 0x24,
	0x70, 0xf0, 0x67, 0x9f, 0xa1, 0x04, 0xa1, 0x1b, 0xf4, 0x07, 0x90, 0x69, 0x6c, 0x3d, 0x73, 0x75,
	0xc0, 0x7a, 0xf9, 0x03, 0x08, 0x0a, 0x63, 0x90, 0x51, 0xd5, 0x23, 0x92, 0x9e, 0xd0, 0x12, 0xc2,
	0x33, 0xf8, 0x63, 0x68, 0x6f, 0x20, 0xa1, 0x5c, 0x24, 0x60, 0x21, 0x31, 0xa9, 0xf0, 0x69, 0x71,
	0x67, 0xa2, 0x64, 0x0a, 0x6d, 0x65, 0x0f, 0x00, 0x08, 0x51, 0x21, 0x6c, 0xae, 0x69, 0x80, 0xae,
	0xe0, 0x2e, 0x70, 0xae, 0x6e, 0xf0, 0x2f, 0x72, 0x60, 0x8a, 0xe2, 0x6c, 0x41, 0x1d, 0x61, 0x6d,
	0x65, 0x10, 0x0c, 0x90, 0x38, 0x62, 0x36, 0x11, 0x70, 0xaf, 0x75, 0x63, 0x74, 0x00, 0x27, 0x0a,
	0x6c, 0x61, 0x47, 0x10, 0x07, 0xb0, 0x1e, 0xa1, 0x53, 0x61, 0x63, 0x63, 0x20, 0x99, 0x6f, 0x2e,
	0x72, 0x50, 0x02, 0x01, 0x58, 0x60, 0x6d, 0x6c, 0x80, 0x0f, 0x63, 0x72, 0xd2, 0x6f, 0x00, 0x01,
	0x69, 0x6e, 0xc0, 0x78, 0x65, 0x06, 0x3b, 0x53, 0xa9, 0xcd, 0x60, 0x50, 0x70, 0x50, 0x64, 0xd0,
	0xaa, 0x28, 0x74, 0xd0, 0x35, 0x40, 0x03, 0x58, 0x66, 0x65, 0x77, 0x60, 0x4a, 0xa1, 0x02, 0x73,
	0xa1, 0x40, 0x6c, 0xe0, 0x65, 0x6e, 0x67, 0x74, 0x68, 0xe0, 0x35, 0x40, 0x06, 0x20, 0xb4, 0xcc,
	0x20, 0x62, 0x60, 0x3a, 0x25, 0x12, 0x66, 0x6f, 0x11, 0xb3, 0xa0, 0x1b, 0x51, 0x86, 0x34, 0x47,
	0x69, 0x76, 0xb2, 0x8e, 0x6d, 0xa0, 0x94, 0x6e, 0x9c, 0x74, 0x20, 0xe0, 0x0c, 0x50, 0x10, 0xc3,
	0x24, 0x65, 0x61, 0x60, 0x13, 0xff, 0x82, 0xbb, 0x14, 0x25, 0x39, 0x1c, 0x32, 0x41, 0x50, 0x17,
	0xc1, 0x24, 0x85, 0x1f, 0xe0, 0x10, 0xff, 0xa2, 0xa9, 0xa1, 0x6e, 0xc0, 0xb9, 0xd0, 0xbe, 0x55,
	0x02, 0x55, 0x83, 0x12, 0x54, 0x61, 0x2e, 0xfb, 0x70, 0x02, 0xd0, 0x42, 0x65, 0xd1, 0x03, 0x25,
	0x57, 0x02, 0x8c, 0x20, 0x04, 0xf4, 0x9f, 0xa5, 0xd2, 0x27, 0x20, 0xb0, 0x2e, 0x41, 0x63, 0xf0,
	0x89, 0x70, 0x61, 0x9b, 0xff, 0x41, 0x1e, 0x39, 0x08, 0x22, 0x2f, 0xe1, 0xa4, 0x07, 0x43, 0xc4,
	0x5d, 0x72, 0x06, 0x32, 0x2e, 0xef, 0xb4, 0xc4, 0x81, 0x06, 0xe5, 0xc4, 0x92, 0x05, 0x34, 0x01,
	0x58, 0xb8, 0x91, 0x93, 0x2a, 0x3f, 0xfe, 0x60, 0xeb, 0x8a, 0x54, 0x47, 0x7f, 0x23, 0x80, 0x33,
	0xc0, 0x3c, 0x2c, 0x0a, 0x46, 0x74, 0x00, 0x47, 0x10, 0x4f, 0x6f, 0x67, 0x65, 0xb0, 0x0a, 0x72,
	0x09, 0x10, 0x84, 0x66, 0x66, 0xd1, 0x63, 0x76, 0x65, 0x6c, 0x79, 0x7f, 0xa1, 0x18, 0xc1, 0x22,
	0x10, 0x8b, 0x00, 0xd0, 0x80, 0x77, 0xd9, 0x5a, 0xf4, 0x19, 0x0a, 0xc3, 0x3d, 0x85, 0x95, 0x15,
	0x63, 0x6f, 0x6e, 0x74, 0xe0, 0x40, 0x30, 0x26, 0x2f, 0xb0, 0x15, 0x61, 0x10, 0x7b, 0x09, 0x81,
	0x24, 0x72, 0xa1, 0x44, 0x73, 0x65, 0xe6, 0x0a, 0xd0, 0x1f, 0xa0, 0x1c, 0x65, 0x72, 0xf1, 0x39,
	0x80, 0x36, 0x50, 0xb1, 0xf0, 0x62, 0x75, 0x67, 0x67, 0xd1, 0x00, 0x62, 0x30, 0x59, 0x07, 0x21,
	0x26, 0x23, 0x43, 0x66, 0xb2, 0x97, 0x64, 0x6f, 0x20, 0x22, 0x1f, 0x6f, 0x66, 0xff, 0x10, 0x5f,
	0x60, 0x27, 0xbf, 0x22, 0xbf, 0x22, 0x80, 0xb2, 0x52, 0x18, 0xbe, 0x22, 0x0b, 0x0a, 0xff, 0x71,
	0x20, 0x21, 0x18, 0xa1, 0x0b, 0xdf, 0x22, 0x11, 0xdd, 0x21, 0x0c, 0xdf, 0x22, 0x20, 0x24, 0xdb,
	0xdf, 0x22, 0x80, 0xcf, 0x64, 0xe3, 0xae, 0xdf, 0x22, 0x20, 0xdb, 0x22, 0x5b, 0x08, 0x3f, 0xff,
	0x22, 0x02, 0xe2, 0x30, 0x79, 0xff, 0x22, 0xc0, 0xf3, 0xfa, 0x22, 0x20, 0x63, 0x8e, 0x29, 0x10,
	0xf0, 0x7f, 0xc7, 0x32, 0x0b, 0x64, 0x69, 0x73, 0x30, 0x39, 0xbc, 0x79, 0x73, 0x70, 0x84, 0x45,
	0xf4, 0x83, 0x34, 0x40, 0xc9, 0x75, 0x91, 0x18, 0xa1, 0xb1, 0x0f, 0x65, 0x78, 0x65, 0x63, 0x80,
	0x92, 0x6f, 0x30, 0xdb, 0x3b, 0x63, 0x94, 0x41, 0x23, 0x65, 0x2e, 0x03, 0x86, 0x97, 0x75, 0x12,
	0x61, 0x6d, 0x18, 0x6f, 0x6e, 0x67, 0xc4, 0x13, 0x80, 0x61, 0x73, 0xb7, 0x00, 0x6e, 0x6f, 0x74,
	0x69, 0x63, 0x65, 0x73, 0x2c, 0x00, 0x20, 0x61, 0x73, 0x20, 0x77, 0x65, 0x6c, 0x6c, 0x01, 0x01,
	0x70, 0x61, 0x20, 0x72, 0x65, 0x66, 0x65, 0x72, 0x00, 0x65, 0x6e, 0x63, 0x65, 0x20, 0x64, 0x69,
	0x72, 0x00, 0x65, 0x63, 0x74, 0x69, 0x6e, 0x67, 0x20, 0x74, 0x00, 0x68, 0x65, 0x20, 0x75, 0x73,
	0x65, 0x72, 0x20, 0x04, 0x74, 0x6f, 0x01, 0x2c, 0x0a, 0x20, 0x20, 0x20, 0x63, 0x00, 0x6f, 0x70,
	0x69, 0x65, 0x73, 0x20, 0x6f, 0x66, 0x01, 0x02, 0x38, 0x47, 0x4e, 0x55, 0x20, 0x47, 0x50, 0x4c,
	0x10, 0x20, 0x61, 0x6e, 0x64, 0x00, 0x1e, 0x69, 0x73, 0x20, 0x12, 0x6c, 0x00, 0xb2, 0x6e, 0x73,
	0x00, 0x86, 0x6f, 0x63, 0x75, 0x40, 0x6d, 0x65, 0x6e, 0x74, 0x2e, 0x0a, 0x01, 0x68, 0x64, 0x00,
	0x29, 0x20, 0x44, 0x6f, 0x20, 0x6f, 0x6e, 0x65, 0x81, 0x05, 0x6e, 0x66, 0x6f, 0x6c, 0x6c, 0x6f,
	0x77, 0x00, 0x62, 0x06, 0x3a, 0x02, 0x1f, 0x00, 0x57, 0x20, 0x30, 0x29, 0x20, 0x43, 0x20, 0x6f,
	0x6e, 0x76, 0x65, 0x79, 0x02, 0x58, 0x4d, 0x69, 0x20, 0x6e, 0x69, 0x6d, 0x61, 0x6c, 0x00, 0x12,
	0x72, 0x72, 0x40, 0x65, 0x73, 0x70, 0x6f, 0x6e, 0x64, 0x01, 0x8f, 0x53, 0x88, 0x6f, 0x75, 0x72,
	0x00, 0xa0, 0x75, 0x6e, 0x64, 0x01, 0x93, 0x21, 0x00, 0x9c, 0x74, 0x65, 0x72, 0x6d, 0x04, 0x8c,
	0x69, 0x73, 0xbb, 0x01, 0x69, 0x01, 0x49, 0x4c, 0x03, 0x83, 0x00, 0xdf, 0x02, 0x95, 0x65, 0x0c,
	0x44, 0x08, 0x41, 0x70, 0x70, 0x80, 0x52, 0x61, 0x74, 0x69, 0x6f, 0x02, 0x6e, 0x80, 0x0c, 0x64,
	0x65, 0x20, 0x69, 0x6e, 0x20, 0x40, 0x61, 0x20, 0x66, 0x6f, 0x72, 0x6d, 0x05, 0x20, 0x73, 0x80,
	0x75, 0x69, 0x74, 0x61, 0x62, 0x6c, 0x65, 0x01, 0x0a, 0x07, 0x83, 0x22, 0x84, 0x38, 0x82, 0x36,
	0x74, 0x68, 0x61, 0x74, 0x20, 0xe2, 0x70, 0x00, 0x05, 0x69, 0x74, 0x2c, 0x82, 0x55, 0x84, 0x90,
	0x85, 0x1e, 0xa1, 0x00, 0x9e, 0x6f, 0x6d, 0x62, 0x69, 0x01, 0x76, 0x72, 0x80, 0xaa, 0x30, 0x6c,
	0x69, 0x6e, 0x6b, 0x02, 0x13, 0x89, 0x3b, 0x77, 0x69, 0x04, 0x74, 0x68, 0x00, 0x3a, 0x6d, 0x6f,
	0x64, 0x69, 0x66, 0x00, 0x69, 0x65, 0x64, 0x20, 0x76, 0x65, 0x72, 0x73, 0xd9, 0x81, 0x47, 0x6f,
	0x66, 0x85, 0x22, 0x01, 0xbd, 0x4c, 0x00, 0x1d, 0x00, 0x0e, 0x06, 0x56, 0x04, 0x0e, 0x00, 0xc2,
	0x70, 0x72, 0x6f, 0x64, 0x75, 0x29, 0x80, 0x80, 0x61, 0x20, 0x06, 0x1d, 0x43, 0x03, 0x36, 0x64,
	0x20, 0xe0, 0x57, 0x6f, 0x72, 0x6b, 0x2c, 0x01, 0x66, 0x00, 0x1d, 0x85, 0x22, 0x10, 0x6d, 0x61,
	0x6e, 0x6e, 0x00, 0x95, 0x73, 0x70, 0x65, 0xc2, 0x63, 0x03, 0x34, 0x62, 0x79, 0x20, 0x73, 0x01,
	0xee, 0xc0, 0x3e, 0x7e, 0x36, 0x0d, 0x71, 0x80, 0x40, 0x80, 0x77, 0x81, 0x60, 0xc0, 0x5a, 0x45,
	0x10, 0x43, 0x0e, 0x6f, 0x0f, 0x60, 0x03, 0x75, 0x81, 0x5a, 0x31, 0x29, 0x20, 0x55, 0x09, 0x40,
	0x7b, 0x61, 0x20, 0x86, 0x4c, 0x73, 0x68, 0x61, 0x72, 0x01, 0xc0, 0x2c, 0x6c, 0x69, 0x62, 0x72,
	0x61, 0x72, 0x79, 0x00, 0x20, 0x6d, 0x65, 0x63, 0x68, 0x61, 0x6e, 0x69, 0xcc, 0x73, 0x6d, 0xc1,
	0x52, 0x40, 0x87, 0x6e, 0x6b, 0xc1, 0x71, 0x82, 0x3f, 0x85, 0x88, 0x29, 0x4c, 0x43, 0x0b, 0x2e,
	0x20, 0x20, 0x41, 0x47, 0x12, 0x8f, 0x87, 0x0e, 0xc0, 0x95, 0xc1, 0x8e, 0x02, 0x5e, 0x28, 0x61,
	0x29, 0x81, 0xa4, 0x04, 0x73, 0x20, 0x00, 0x61, 0x72, 0x75, 0x6e, 0x20, 0x74, 0xa8, 0x69, 0x6d,
	0x65, 0xc5, 0x2a, 0x61, 0x41, 0xa7, 0x79, 0x85, 0x35, 0x01, 0x04, 0x15, 0x20, 0x61, 0x6c, 0x72,
	0x65, 0x61, 0x64, 0x78, 0x79, 0x20, 0x70, 0x00, 0x92, 0x40, 0xa4, 0x80, 0xa1, 0x46, 0x6d, 0x27,
	0x62, 0x73, 0x40, 0x0c, 0x6d, 0x70, 0x75, 0x80, 0x91, 0xc5, 0x10, 0x73, 0x20, 0x79, 0x73, 0x74,
	0x65, 0x6d, 0x43, 0x7d, 0x28, 0x62, 0x50, 0x29, 0x20, 0x77, 0x69, 0x00, 0xc8, 0x6f, 0x80, 0x7b,
	0x61, 0xcc, 0x74, 0x65, 0x80, 0x10, 0x41, 0x02, 0x6c, 0x79, 0x40, 0x05, 0xd2, 0x6f, 0x9f, 0x05,
	0x11, 0x44, 0xc7, 0x45, 0x20, 0x02, 0x2e, 0x00, 0x31, 0x69, 0x6e, 0x00, 0x1a, 0x00, 0x66, 0x61,
	0x63, 0x65, 0x2d, 0x63, 0x6f, 0x6d, 0xee, 0x70, 0x40, 0xa0, 0xc1, 0x98, 0xc5, 0x42, 0x20, 0x43,
	0x7b, 0x85, 0x10, 0x04, 0x7d, 0x04, 0x2e, 0x20, 0x02, 0xc8, 0x65, 0x29, 0x20, 0x50, 0x72, 0x08,
	0x6f, 0x76, 0x69, 0x40, 0xab, 0x49, 0x6e, 0x73, 0x74, 0xc8, 0x61, 0x6c, 0x6c, 0xc3, 0xaf, 0x49,
	0x6e, 0xc1, 0xad, 0xc2, 0x02, 0x60, 0x2c, 0x20, 0x62, 0x75, 0x74, 0x00, 0x37, 0x40, 0x27, 0x69,
	0x00, 0x66, 0x20, 0x79, 0x6f, 0x75, 0x20, 0x77, 0x6f, 0x20, 0x75, 0x6c, 0x64, 0x20, 0x6f, 0xc0,
	0x59, 0x72, 0x77, 0x04, 0x69, 0x73, 0x42, 0x49, 0x62, 0x65, 0x20, 0x72, 0x65, 0x6c, 0x71, 0x75,
	0x00, 0x7c, 0xe0, 0x75, 0x6f, 0xe1, 0x19, 0x62, 0x0a, 0x73, 0xd8, 0x75, 0x63, 0x68, 0x20, 0x47,
	0x66, 0x09, 0x20, 0xe3, 0x5d, 0x2d, 0x45, 0x67, 0x61, 0x13, 0x24, 0x7e, 0x03, 0x24, 0x6f, 0x6e,
	0xa0, 0x0d, 0x63, 0x83, 0x20, 0x78, 0x65, 0x78, 0x74, 0xa1, 0x2b, 0x62, 0x1d, 0xee, 0x09, 0x83,
	0x73, 0x6e, 0xda, 0x65, 0xc0, 0x8e, 0x73, 0xc1, 0x42, 0x60, 0x06, 0x69, 0xe3, 0x18, 0x42, 0x87,
	0xf0, 0x65, 0x78, 0x65, 0x63, 0x80, 0x30, 0x33, 0x62, 0xa1, 0x35, 0x21, 0x0f, 0x27, 0x0a, 0x5d,
	0x41, 0x17, 0x21, 0x61, 0x64, 0x20, 0x20, 0x5a, 0x72, 0x65, 0xf7, 0xe0, 0x29, 0x20, 0x6e, 0x41,
	0x4b, 0x6f, 0x65, 0x6e, 0x81, 0x01, 0x44, 0x4c, 0x3f, 0x6f, 0x12, 0x6e, 0x87, 0x46, 0x6e, 0x6b,
	0x47, 0x6e, 0x2e, 0x20, 0x28, 0x8e, 0x49, 0x22, 0x72, 0xc1, 0x29, 0xc0, 0x7c, 0x20, 0x6f, 0x70,
	0xc2, 0x86, 0x18, 0x34, 0x64, 0x30, 0x43, 0x7f, 0x95, 0x31, 0x20, 0x6d, 0x75, 0x20, 0x73, 0x74,
	0x20, 0x61, 0x63, 0xe2, 0x3c, 0x6e, 0x79, 0xfb, 0xc1, 0x17, 0x60, 0x11, 0x20, 0xba, 0x9a, 0x61,
	0xa8, 0xab, 0x6d, 0xe8, 0x16, 0x03, 0x20, 0x60, 0x64, 0x65, 0x2e, 0x20, 0x49, 0x83, 0x3b, 0xaa,
	0x11, 0x31, 0xfe, 0x2c, 0x02, 0x3e, 0x82, 0x0e, 0x40, 0x84, 0x62, 0x3a, 0xe1, 0x0d, 0xc9, 0x13,
	0x21, 0x08, 0xfb, 0xc8, 0x45, 0x04, 0x85, 0x20, 0x3f, 0x84, 0xc0, 0xac, 0x84, 0x3e, 0x41, 0x08,
	0x60, 0x44, 0x4f, 0x60, 0x66, 0x84, 0x84, 0x2c, 0xab, 0xc3, 0xb3, 0x2e, 0x29, 0x41, 0x56, 0x35,
	0xf6, 0x2e, 0x80, 0x03, 0xc2, 0xa0, 0x64, 0x20, 0x5b, 0x81, 0x81, 0xc0, 0xc6, 0x02, 0x87, 0xd2,
	0x59, 0x40, 0x53, 0x6d, 0x61, 0xe0, 0x71, 0x6c, 0x20, 0x61, 0x40, 0x82, 0xc3, 0x03, 0x85, 0xc0,
	0x62, 0x69, 0x6c, 0x69, 0x74, 0x61, 0xcb, 0x42, 0x48, 0x0b, 0xa0, 0x88, 0xc0, 0x41, 0x77, 0x60,
	0x9a, 0x20, 0x62, 0x61, 0x73, 0xd7, 0x40, 0x32, 0x20, 0x96, 0x40, 0x1a, 0x0a, 0x65, 0x6a, 0x73,
	0x61, 0x61, 0xa1, 0x99, 0x3b, 0xe1, 0x00, 0x22, 0xb8, 0x73, 0x20, 0x3e, 0x60, 0xb6, 0x25, 0x8f,
	0x74, 0x6f, 0x74, 0x67, 0x65, 0x00, 0x06, 0x72, 0x63, 0x75, 0xa2, 0x60, 0x85, 0x0d, 0x0a, 0xfb,
	0x91, 0x0d, 0xa0, 0xe2, 0x20, 0x08, 0x2e, 0x00, 0x8c, 0xa0, 0xc7, 0xa1, 0x10, 0x01, 0x03, 0x9c,
	0x63, 0x6f, 0x20, 0xb4, 0x80, 0x10, 0x00, 0x0e, 0x74, 0x68, 0x80, 0x59, 0xfd, 0x4a, 0xcc, 0x63,
	0xc3, 0xd6, 0x82, 0x5e, 0x41, 0x90, 0xa4, 0x1e, 0x05, 0x11, 0x69, 0xc7, 0x83, 0x00, 0x83, 0x40,
	0x49, 0x72, 0x0a, 0x63, 0x68, 0x6f, 0x80, 0xd4, 0xc3, 0xa0, 0xb5, 0x83, 0x39, 0x64, 0x6f, 0x20,
	0x62, 0x20, 0x14, 0x85, 0x50, 0xfb, 0xac, 0xe3, 0x20, 0x9e, 0x41, 0x25, 0x49, 0x42, 0x97, 0xa3,
	0x5d, 0xc0, 0x11, 0x45, 0x0c, 0x43, 0x62, 0x88, 0xab, 0x9f, 0x73, 0x61, 0x6d, 0x65, 0x20, 0x80,
	0x72, 0x9e, 0x6b, 0xc3, 0x27, 0x41, 0x37, 0x23, 0x28, 0xa4, 0x31, 0x79, 0x2c, 0x40, 0x3e, 0x7b,
	0x86, 0x04, 0x03, 0x04, 0x6e, 0xb0, 0x53, 0x22, 0x13, 0x75, 0x05, 0x77, 0x12, 0x2c, 0x3f, 0x01,
	0x04, 0x83, 0x0e, 0x70, 0x07, 0x24, 0x0d, 0x0d, 0x78, 0xa0, 0x05, 0x63, 0x65, 0x47, 0xd0, 0x7f,
	0xf3, 0x61, 0xc0, 0x53, 0x47, 0x69, 0x76, 0x42, 0x53, 0x6d, 0xf1, 0xd0, 0x70, 0x6e, 0x74, 0x20,
	0x90, 0x14, 0x50, 0x0f, 0x03, 0x19, 0x70, 0x06, 0x1b, 0xb1, 0x57, 0x71, 0x72, 0x64, 0x46, 0x20,
	0x92, 0x1f, 0x70, 0x61, 0x72, 0x61, 0x70, 0x4c, 0x66, 0x20, 0x69, 0x74, 0x31, 0x07, 0x60, 0x53,
	0x61, 0x0f, 0x78, 0x0c, 0xd5, 0x5b, 0x64, 0x20, 0x63, 0x48, 0x65, 0x78, 0x70, 0x6c, 0x66, 0x61,
	0x00, 0x83, 0x10, 0x8b, 0x77, 0x68, 0x40, 0x8c, 0xe1, 0x8a, 0x66, 0x9e, 0x69, 0xc3, 0x7f, 0x31,
	0x04, 0x76, 0x38, 0x31, 0x41, 0x75, 0x6e, 0x56, 0x0f, 0x0f, 0xf1, 0x4e, 0x35, 0x17, 0xf6, 0x12,
	0xc2, 0x0b, 0x36, 0x2e, 0x20, 0x52, 0x64, 0x65, 0x76, 0x40, 0x53, 0x64, 0x20, 0x84, 0x58, 0x2a,
	0x8f, 0x4c, 0x64, 0x65, 0x73, 0x51, 0x91, 0x47, 0x65, 0xc0, 0x75, 0x40, 0x8a, 0x50, 0x2c, 0x75,
	0x62, 0x10, 0x85, 0xda, 0x0f, 0x54, 0xb0, 0x11, 0x46, 0x72, 0x00, 0x65, 0x65, 0x20, 0x53, 0x6f,
	0x66, 0x74, 0x77, 0x79, 0x61, 0x24, 0x46, 0x6f, 0x50, 0x13, 0x53, 0x5b, 0xd2, 0x2f, 0x31, 0x03,
	0x73, 0x2e, 0x68, 0xe0, 0x58, 0x63, 0x06, 0xd0, 0x3f, 0x2f, 0xb0, 0x4b, 0x6e, 0x65, 0xf2, 0x77,
	0xc5, 0x80, 0x73, 0x0a, 0x64, 0x64, 0xd1, 0x37, 0x1f, 0x07, 0x18, 0x07, 0xe0, 0x20, 0x66, 0x72,
	0x6f, 0x6d, 0x92, 0x70, 0x82, 0x9a, 0x10, 0x71, 0xd8, 0x2e, 0x20, 0x53, 0x21, 0x5d, 0xd0, 0x04,
	0x0a, 0xa4, 0x85, 0xa0, 0x9e, 0x03, 0x91, 0x6c, 0x00, 0x60, 0x73, 0x69, 0x6d, 0x69, 0x6c, 0x61,
	0x02, 0x72, 0x01, 0x40, 0x73, 0x70, 0x69, 0x72, 0x69, 0x74, 0xbf, 0x42, 0x03, 0xf0, 0x0a, 0x05,
	0x72, 0x14, 0x03, 0x03, 0x65, 0xb0, 0x0a, 0x0a, 0x40, 0x8a, 0x03, 0xb0, 0xa1, 0x01, 0x03, 0x64,
	0x65, 0x74, 0x61, 0x69, 0x6c, 0x91, 0x01, 0x03, 0x61, 0x64, 0x64, 0xf0, 0x74, 0x73, 0x20, 0x01,
	0x0b, 0x17, 0x20, 0x47, 0x90, 0x6c, 0x81, 0x98, 0x72, 0xb1, 0x41, 0x63, 0x65, 0x72, 0x64, 0x6e,
	0x73, 0x62, 0x14, 0x45, 0x61, 0x70, 0x65, 0xe4, 0x04, 0x20, 0x8d, 0x90, 0x1c, 0x67, 0xf0, 0x20,
	0xc1, 0x96, 0x64, 0x69, 0x73, 0xf1, 0xa5, 0x30, 0x75, 0x69, 0x73, 0x68, 0x21, 0x19, 0x15, 0x02,
	0x6e, 0x75, 0xf0, 0x6d, 0x62, 0x65, 0x72, 0x22, 0x4e, 0xe0, 0x21, 0xa6, 0x3e, 0x60, 0xaa, 0x53,
	0x40, 0x33, 0x90, 0x12, 0x63, 0x65, 0xf0, 0x03, 0x64, 0x80, 0x21, 0x20, 0x9d, 0x05, 0x8d, 0x73,
	0xf0, 0x30, 0x80, 0x80, 0xa0, 0x2f, 0x65, 0x72, 0x90, 0x09, 0xbc, 0x6e, 0x20, 0x23, 0x04, 0x20,
	0x2a, 0x34, 0x05, 0x3f, 0x14, 0x20, 0x5f, 0x1b, 0xe9, 0x31, 0x2b, 0x20, 0x22, 0xd0, 0x17, 0x61,
	0x10, 0x30, 0x90, 0x75, 0x10, 0x93, 0xf1, 0xe4, 0x03, 0x22, 0x0a, 0x61, 0xd1, 0xa2, 0x00, 0xaf,
	0x11, 0x6b, 0xf0, 0x9e, 0xf9, 0x81, 0x08, 0x68, 0x61, 0x50, 0x2d, 0xf1, 0x2b, 0xd4, 0x60, 0x60,
	0x1a, 0x16, 0x3b, 0xaf, 0xf2, 0x39, 0x50, 0x7e, 0xc0, 0x10, 0x10, 0x1d, 0x0a, 0x10, 0x33, 0x64,
	0x40, 0x4d, 0x40, 0x6f, 0x6e, 0x73, 0x20, 0x65, 0x69, 0x20, 0x03, 0x72, 0xdb, 0xe3, 0x26, 0x20,
	0x0b, 0x70, 0xf3, 0x1f, 0x97, 0x0a, 0x20, 0xf0, 0x07, 0x90, 0x04, 0x4d, 0x2e, 0x08, 0x0a, 0x97,
	0x02, 0xd2, 0x47, 0x65, 0x20, 0x7f, 0x25, 0x64, 0xdf, 0x72, 0x25, 0x85, 0x13, 0x80, 0x28, 0x33,
	0x55, 0x83, 0x13, 0x0a, 0xe0, 0x71, 0x86, 0x13, 0xdc, 0x64, 0x6f, 0xb0, 0x0c, 0x11, 0x4d, 0x13,
	0x14, 0x79, 0x30, 0x56, 0xa4, 0x0e, 0xf7, 0xa4, 0x13, 0xf5, 0x30, 0x47, 0x27, 0x0a, 0x0f, 0x13,
	0x01, 0x13, 0x24, 0x67, 0x80, 0x5c, 0xfd, 0xc0, 0x4c, 0x6f, 0x41, 0xa0, 0xc0, 0x13, 0xb5, 0x04,
	0x80, 0x0c, 0x01, 0x12, 0x4f, 0x04, 0xd2, 0x20, 0xbb, 0x32, 0x20, 0x65, 0x10, 0x03, 0x20, 0x1f,
	0x0e, 0x9f, 0x33, 0xff, 0x13, 0x0e, 0x91, 0x65, 0x00, 0x70, 0xb1, 0x05, 0x85, 0x60, 0xdf, 0x21,
	0xdf, 0x21, 0x00, 0x2a, 0x00, 0x78, 0x79, 0x20, 0x63, 0x61, 0x6e, 0x20, 0x64, 0x31, 0x80, 0xb0,
	0x64, 0x65, 0x0a, 0x60, 0x42, 0x30, 0x04, 0x72, 0x20, 0xc0, 0x66, 0x75, 0x74, 0x75, 0x72, 0x65,
	0x16, 0x37, 0xcf, 0x0f, 0xcb, 0xdf, 0x22, 0x12, 0x4e, 0x20, 0x60, 0xae, 0x6c, 0x6c, 0xc2, 0x21,
	0x80, 0x54, 0x61, 0x63, 0x4b, 0x72, 0x6f, 0x78, 0x79, 0x00, 0xa5, 0xc2, 0x0c, 0x63, 0x2e, 0x20,
	0x40, 0x9a, 0x70, 0xa4, 0xf2, 0xa6, 0x66, 0x81, 0x80, 0x65, 0x70, 0x7c, 0x74, 0x61, 0xc1, 0xd5,
	0x24, 0x1e, 0x85, 0x12, 0xb0, 0x64, 0xa1, 0xc4, 0x61, 0x02, 0x6e, 0x91, 0x02, 0x61, 0x75, 0x74,
	0x68, 0x6f, 0x72, 0xfc, 0x69, 0x7a, 0xb2, 0x0e, 0x02, 0xb3, 0xe1, 0x26, 0x90, 0x27, 0x14, 0x16,
	0x72, 0x06, 0xdf, 0x95, 0x03, 0x81, 0x78, 0x30, 0x0c, 0x55, 0x32, 0xf0, 0x36, 0x00, 0x0f, 0x00,
	0x1f, 0x01, 0xff, 0x1f, 0x01, 0x1f, 0x01, 0x1f, 0x01, 0x1f, 0x01, 0x1f, 0x01, 0x1f, 0x01, 0x1f,
	0x01, 0x1f, 0x01, 0xff, 0x1f, 0x01, 0x1f, 0x01, 0x1f, 0x01, 0x1f, 0x01, 0x1f, 0x01, 0x1f, 0x01,
	0x1f, 0x01, 0x1f, 0x01, 0xff, 0x1f, 0x01, 0x1f, 0x01, 0x1f, 0x01, 0x1f, 0x01, 0x1f, 0x01, 0x1f,
	0x01, 0x1f, 0x01, 0x1f, 0x01, 0x1f, 0x1f, 0x01, 0x1f, 0x01, 0x1f, 0x01, 0x1f, 0x01, 0x18, 0x01 };

/* Tests the libfwnt_lznt1_decompress function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_lznt1_decompress(
     void )
{
	uint8_t uncompressed_data[ 8192 ];

	libcerror_error_t *error      = NULL;
	size_t uncompressed_data_size = 8192;
	int result                    = 0;

	/* Must uncompressed data must be 4k block aligned
	 * even though effective resulting data will be 7640 bytes in size
	 */
	result = libfwnt_lznt1_decompress(
	          fwnt_test_lznt1_compressed_byte_stream,
	          4064,
	          uncompressed_data,
	          &uncompressed_data_size,
	          &error );

	FWNT_TEST_FPRINT_ERROR( error )

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "uncompressed_data_size",
	 uncompressed_data_size,
	 8192 );

	return( 1 );

on_error:
	return( 0 );
}

/* The main program
 */
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc FWNT_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] FWNT_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc FWNT_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] FWNT_TEST_ATTRIBUTE_UNUSED )
#endif
{
	FWNT_TEST_UNREFERENCED_PARAMETER( argc )
	FWNT_TEST_UNREFERENCED_PARAMETER( argv )

	/* TODO add tests for libfwnt_lznt1_compress */

	FWNT_TEST_RUN(
	 "libfwnt_lznt1_decompress",
	 fwnt_test_lznt1_decompress );

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

