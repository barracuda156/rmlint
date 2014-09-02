/*
 *  This file is part of rmlint.
 *
 *  rmlint is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  rmlint is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with rmlint.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors:
 *
 *  - Christopher <sahib> Pahl 2010-2014 (https://github.com/sahib)
 *  - Daniel <SeeSpotRun> T.   2014-2014 (https://github.com/SeeSpotRun)
 *
 * Hosted on http://github.com/sahib/rmlint
 *
 */

#include "../formats.h"
#include "../preprocess.h"

#include <glib.h>
#include <stdio.h>
#include <string.h>


typedef struct RmFmtHandlerPyScript {
    RmFmtHandler parent;
    RmFile *last_original;
} RmFmtHandlerPyScript;

static const char *PY_SCRIPT_TEMPLATE_HEAD =
    ""
    ;


static const char *PY_SCRIPT_TEMPLATE_FOOT =
    ""
    ;

static void rm_fmt_head(RmSession *session, RmFmtHandler *parent, FILE *out) {
    RmFmtHandlerPyScript *self = (RmFmtHandlerPyScript *)parent;

}

static char *rm_fmt_py_escape_path(char *path) {
    return rm_util_strsub(path, "'", "\\'");
}

static void rm_fmt_elem(RmSession *session, G_GNUC_UNUSED RmFmtHandler *parent, FILE *out, RmFile *file) {
    RmFmtHandlerPyScript *self = (RmFmtHandlerPyScript *)parent;

    char *dupe_path = rm_fmt_py_escape_path(file->path);


    g_free(dupe_path);
}

static void rm_fmt_foot(G_GNUC_UNUSED RmSession *session, RmFmtHandler *parent, FILE *out) {
    fprintf(
        out, PY_SCRIPT_TEMPLATE_FOOT
    );
}

static RmFmtHandlerPyScript PY_SCRIPT_HANDLER_IMPL = {
    .parent = {
        .size = sizeof(PY_SCRIPT_HANDLER_IMPL),
        .name = "py",
        .head = rm_fmt_head,
        .elem = rm_fmt_elem,
        .prog = NULL,
        .foot = rm_fmt_foot
    },
    .last_original = NULL
};

RmFmtHandler *PY_SCRIPT_HANDLER = (RmFmtHandler *) &PY_SCRIPT_HANDLER_IMPL;