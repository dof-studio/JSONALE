/* ==== jsonale.h ========================================================= */
#ifndef JSONALE_H
#define JSONALE_H

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#define JSONALE_MAGIC        0x4a534c00u   /* "\0JSL" little‑endian */
#define JSONALE_VERSION      0x0001u       /* current version = 1 */

/* 
 *  bit7  bit6  bit5  bit4  bit3  bit2  bit1  bit0
 *  -------------------------------------------------
 *  7   6   5   4   3   2   1   0
 *  |---|---|---|---|---|---|---|---|
 */
#define JSONALE_TYPE_MASK_REAL        0x0Fu   /* low 4 bits */
#define JSONALE_TYPE_FLAG_ARRAY       0x10u
#define JSONALE_TYPE_FLAG_OBJECT      0x20u
#define JSONALE_TYPE_FLAG_KEY         0x40u
#define JSONALE_TYPE_FLAG_MAPDESC     0x80u

/* real type
 *  0x0  : NULL
 *  0x1  : Boolean
 *  0x2  : Int8   … 0x9 : Uint64
 *  0xA  : Float
 *  0xB  : Double
 *  0xC  : ShortString (≤8 bytes, no NUL)
 *  0xD  : C‑String (NUL terminated, length stored in desc)
 *  0xE  : Binary (raw bytes, length stored in desc)
 *  0xF  : Reserved / future
 */
enum {
    JSONALE_RT_NULL          = 0x0,
    JSONALE_RT_BOOL          = 0x1,
    JSONALE_RT_INT8          = 0x2,
    JSONALE_RT_UINT8         = 0x3,
    JSONALE_RT_INT16         = 0x4,
    JSONALE_RT_UINT16        = 0x5,
    JSONALE_RT_INT32         = 0x6,
    JSONALE_RT_UINT32        = 0x7,
    JSONALE_RT_INT64         = 0x8,
    JSONALE_RT_UINT64        = 0x9,
    JSONALE_RT_FLOAT         = 0xA,
    JSONALE_RT_DOUBLE        = 0xB,
    JSONALE_RT_SHORTSTR      = 0xC,
    JSONALE_RT_CSTR          = 0xD,
    JSONALE_RT_BINARY        = 0xE,
};

/* ---------- err code ----------
 */
typedef enum {
    JSONALE_OK               = 0,
    JSONALE_ERR_IO           = 1,
    JSONALE_ERR_EOF          = 2,
    JSONALE_ERR_BADMAGIC     = 3,
    JSONALE_ERR_UNSUPVER     = 4,
    JSONALE_ERR_BADTYPE      = 5,
    JSONALE_ERR_NOMEM        = 6,
    JSONALE_ERR_NOTFOUND     = 7,
    JSONALE_ERR_INVALIDARG   = 8,
    JSONALE_ERR_INCOMPATIBLE = 9,
    JSONALE_ERR_WRITEFAIL    = 10,
    JSONALE_ERR_INTERNAL     = 0xFF
} JsonaleErr;


typedef struct JsonaleCtx   JsonaleCtx;
typedef struct JsonaleNode  JsonaleNode;


JsonaleCtx *jsonale_open(const char *path, const char *mode);
void        jsonale_close(JsonaleCtx *ctx);

int jsonale_get_root(JsonaleCtx *ctx, JsonaleNode **out_root);
int jsonale_find(JsonaleCtx *ctx,
                const JsonaleNode *parent,
                const char *key,
                JsonaleNode **out_node);
int jsonale_iter_begin(JsonaleCtx *ctx,
                      const JsonaleNode *parent,
                      JsonaleNode **out_iter);
int jsonale_iter_next(JsonaleCtx *ctx,
                      JsonaleNode *iter,
                      JsonaleNode **out_next);
int jsonale_get_int64(const JsonaleNode *node, int64_t *out);
int jsonale_get_uint64(const JsonaleNode *node, uint64_t *out);
int jsonale_get_double(const JsonaleNode *node, double *out);
int jsonale_get_string(const JsonaleNode *node,
                       char **out_str, size_t *out_len);
int jsonale_set_value(JsonaleCtx *ctx,
                     JsonaleNode *node,
                     const void *data, size_t len);
int jsonale_add_child(JsonaleCtx *ctx,
                     JsonaleNode *parent,
                     const JsonaleNode *child);
int jsonale_save(JsonaleCtx *ctx, const char *path);
int jsonale_error(const JsonaleCtx *ctx);

#endif /* JSONALE_H */
