/*
 * Copyright (C) 2011 Andrea Mazzoleni
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __UNIX_H
#define __UNIX_H

#define O_BINARY 0 /**< Not used in Unix. */
#define O_SEQUENTIAL 0 /**< In Unix posix_fadvise() shall be used. */

/* Check if we have nanoseconds support */
#if HAVE_STRUCT_STAT_ST_MTIM_TV_NSEC
#define STAT_NSEC(st) (st)->st_mtim.tv_nsec /* Linux */
#elif HAVE_STRUCT_STAT_ST_MTIMENSEC
#define STAT_NSEC(st) (st)->st_mtimensec /* NetBSD */
#elif HAVE_STRUCT_STAT_ST_MTIMESPEC_TV_NSEC
#define STAT_NSEC(st) (st)->st_mtimespec.tv_nsec /* FreeBSD, Mac OS X */
#else
/**
 * If nanoseconds are not supported, we report the special FILE_MTIME_NSEC_INVALID value,
 * to mark that it's undefined.
 * This result in not having it saved into the content file as a dummy 0.
 */
#define STAT_NSEC(st) -1
#endif

/**
 * Open a file with the O_NOATIME flag to avoid to update the acces time.
 */
int open_noatime(const char* file, int flags);

/**
 * Check if the specified file is hidden.
 */
int dirent_hidden(struct dirent* dd);

/**
 * Return a description of the file type.
 */
const char* stat_desc(struct stat* st);

#endif
