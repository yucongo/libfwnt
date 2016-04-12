/*
 * Windows NT Access Contol Entry (ACE) functions
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

#if !defined( _LIBFWNT_INTERNAL_ACCESS_CONTROL_ENTRY_H )
#define _LIBFWNT_INTERNAL_ACCESS_CONTROL_ENTRY_H

#include <common.h>
#include <types.h>

#include "libfwnt_extern.h"
#include "libfwnt_libcerror.h"
#include "libfwnt_types.h"

#if defined( __cplusplus )
extern "C" {
#endif

/* The Windows NT Access Control Entry is formatted as following:
 * header: type, flags, size
 * data
 */

typedef struct libfwnt_internal_access_control_entry libfwnt_internal_access_control_entry_t;

struct libfwnt_internal_access_control_entry
{
	/* The type
	 */
	uint8_t type;

	/* The flags
	 */
	uint8_t flags;
};

LIBFWNT_EXTERN \
int libfwnt_access_control_entry_initialize(
     libfwnt_access_control_entry_t **access_control_entry,
     libcerror_error_t **error );

LIBFWNT_EXTERN \
int libfwnt_access_control_entry_free(
     libfwnt_access_control_entry_t **access_control_entry,
     libcerror_error_t **error );

LIBFWNT_EXTERN \
int libfwnt_access_control_entry_copy_from_byte_stream(
     libfwnt_access_control_entry_t *access_control_entry,
     const uint8_t *byte_stream,
     size_t byte_stream_size,
     int byte_order,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBFWNT_INTERNAL_ACCESS_CONTROL_ENTRY_H ) */

