/* GStreamer
 * Copyright (C) 2014 Wim Taymans <wtaymans@redhat.com>
 *
 * gstcahcefile.h:
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include <glib.h>

#ifndef __GST_SPARSE_FILE_H__
#define __GST_SPARSE_FILE_H__

typedef struct _GstSparseFile GstSparseFile;

GstSparseFile * gst_sparse_file_new          (void);
void            gst_sparse_file_free         (GstSparseFile *file);

gboolean        gst_sparse_file_set_fd       (GstSparseFile *file, gint fd);
void            gst_sparse_file_clear        (GstSparseFile *file);

gsize           gst_sparse_file_write        (GstSparseFile *file,
                                              gsize offset,
                                              gconstpointer data,
                                              gsize count,
                                              gsize *available,
                                              GError **error);

gsize           gst_sparse_file_read         (GstSparseFile *file,
                                              gsize offset,
                                              gpointer data,
                                              gsize count,
                                              gsize *remaining,
                                              GError **error);

guint           gst_sparse_file_n_ranges         (GstSparseFile *file);
gboolean        gst_sparse_file_get_range_before (GstSparseFile *file, gsize offset,
                                                  gsize *start, gsize *stop);
gboolean        gst_sparse_file_get_range_after  (GstSparseFile *file, gsize offset,
                                                  gsize *start, gsize *stop);



#endif /* __GST_SPARSE_FILE_H__ */