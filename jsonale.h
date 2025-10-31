// jsonale.h
// 
// JSONALE Project External API Header
// Version 0.0.1 Core v0 Built 251108 
// 
//
// *******   *****   *****   *     *    ***    *        *******
//      *   *       *     *  **    *   *   *   *        *
//      *   *       *     *  * *   *  *     *  *        *
//      *    ****   *     *  *  *  *  *******  *        *****
//      *        *  *     *  *   * *  *     *  *        *
//  *   *        *  *     *  *    **  *     *  *        *
//   ***    *****    *****   *     *  *     *  *******  *******
// 
// 
// Project Jsonale: A Binary JSON Superset Implementation
//
// @Original Co-author: Nathmath/Katz/DOF Studio
// @Copyright Author: DOF-Studio
// @License: MIT https://mit-license.org
// @GitHub: dof-studio/JSONALE https://github.com/dof-studio/JSONALE
// @Motto: Galgames are all we need.
//

#pragma once

/* ==== jsonale.h ========================================================= */
#ifndef JSONALE_H
#define JSONALE_H

#include <stddef.h>

#include "header/jsmacro.h"
#include "header/jstypdf.h"
#include "header/jsenumr.h"

/* 
 * Public API Declaration
 */

JSONALE_C_API JsonaleErr   jsonale_open(
	JSONALE_ARG_IN_ JSONALE_ARG_NNLABLE JsonaleCStrConst          path,
	JSONALE_ARG_IN_ JSONALE_ARG_NNLABLE JsonaleCStrConst          mode,
	JSONALE_ARG_OUT JSONALE_ARG_NLNFRCE JsonaleCtxPtrRef          out_ctx
);
JSONALE_C_API JsonaleErr   jsonale_bind(
	JSONALE_ARG_IN_ JSONALE_ARG_NNLABLE JsonaleCtxPtr             ctx,
	JSONALE_ARG_IN_ JSONALE_ARG_NNLABLE JsonaleCtxConstPtrLst     bind_ctxs,
	JSONALE_ARG_IN_ JSONALE_ARG_NNLABLE JsonaleCStrConst          mode
);
JSONALE_C_API JsonaleErr   jsonale_close(
	JSONALE_ARG_IN_ JSONALE_ARG_NNLABLE JsonaleCtxPtrRef          ctx
);
JSONALE_C_API JsonaleErr   jsonale_error(
	JSONALE_ARG_IN_ JSONALE_ARG_NNLABLE JsonaleCtxConstPtr        ctx
);

JSONALE_C_API JsonaleErr   jsonale_get_root(
	JSONALE_ARG_IN_ JSONALE_ARG_NNLABLE JsonaleCtxPtr             ctx,
	JSONALE_ARG_OUT JSONALE_ARG_NLNFRCE JsonaleNodePtrRef         out_root
);
JSONALE_C_API JsonaleErr   jsonale_find(
	JSONALE_ARG_IN_ JSONALE_ARG_NNLABLE JsonaleCtxPtr             ctx,
	JSONALE_ARG_IN_ JSONALE_ARG_NNLABLE JsonaleNodeConstPtr       parent,
	JSONALE_ARG_IN_ JSONALE_ARG_NNLABLE JsonaleCStrConst          key,
	JSONALE_ARG_OUT JSONALE_ARG_NLNFRCE JsonaleNodePtrRef         out_node
);

JSONALE_C_API JsonaleErr   jsonale_iter_begin(
	JSONALE_ARG_IN_ JSONALE_ARG_NNLABLE JsonaleCtxPtr             ctx,
	JSONALE_ARG_IN_ JSONALE_ARG_NNLABLE JsonaleNodeConstPtr       parent,
	JSONALE_ARG_OUT JSONALE_ARG_NLNFRCE JsonaleNodePtrRef         out_iter
);
JSONALE_C_API JsonaleErr   jsonale_iter_next(
	JSONALE_ARG_IN_ JSONALE_ARG_NNLABLE JsonaleCtxPtr             ctx,
	JSONALE_ARG_IN_ JSONALE_ARG_NNLABLE JsonaleNodePtr            iter,
	JSONALE_ARG_OUT JSONALE_ARG_NLNFRCE JsonaleNodePtrRef         out_next
);

JSONALE_C_API JsonaleErr   jsonale_get_value(
	JSONALE_ARG_IN_ JSONALE_ARG_NNLABLE JsonaleNodeConstPtr       node,
	JSONALE_ARG_OUT JSONALE_ARG_NNLABLE void*                     data,
	JSONALE_ARG_OUT JSONALE_ARG_NLNFRCE size_t*                   len
);
JSONALE_C_API JsonaleErr   jsonale_get_int64(
	JSONALE_ARG_IN_ JSONALE_ARG_NNLABLE JsonaleNodeConstPtr       node,
	JSONALE_ARG_IN_ JSONALE_ARG_NOTAPTR bool                      enable_cast,
	JSONALE_ARG_OUT JSONALE_ARG_NLNFRCE int64_t*                  out
);
JSONALE_C_API JsonaleErr   jsonale_get_uint64(
	JSONALE_ARG_IN_ JSONALE_ARG_NNLABLE JsonaleNodeConstPtr       node,
	JSONALE_ARG_IN_ JSONALE_ARG_NOTAPTR bool                      enable_cast,
	JSONALE_ARG_OUT JSONALE_ARG_NLNFRCE uint64_t*                 out
);
JSONALE_C_API JsonaleErr   jsonale_get_double(
	JSONALE_ARG_IN_ JSONALE_ARG_NNLABLE JsonaleNodeConstPtr       node,
	JSONALE_ARG_IN_ JSONALE_ARG_NOTAPTR bool                      enable_cast,
	JSONALE_ARG_OUT JSONALE_ARG_NLNFRCE double*                   out
);
JSONALE_C_API JsonaleErr   jsonale_get_string(
	JSONALE_ARG_IN_ JSONALE_ARG_NNLABLE JsonaleNodeConstPtr       node,
	JSONALE_ARG_IN_ JSONALE_ARG_NOTAPTR bool                      enable_cast,
	JSONALE_ARG_OUT JSONALE_ARG_NLNFRCE char**                    out_str,
	JSONALE_ARG_OUT JSONALE_ARG_NLNFRCE size_t*                   out_len
);

JSONALE_C_API JsonaleErr   jsonale_set_value(
	JSONALE_ARG_IN_ JSONALE_ARG_NNLABLE JsonaleCtxPtr             ctx,
	JSONALE_ARG_IN_ JSONALE_ARG_NNLABLE JsonaleNodePtr            node,
	JSONALE_ARG_IN_ JSONALE_ARG_NNLABLE const void*               data,
	JSONALE_ARG_IN_ JSONALE_ARG_NOTAPTR size_t                    len
);
JSONALE_C_API JsonaleErr   jsonale_add_child(
	JSONALE_ARG_IN_ JSONALE_ARG_NNLABLE JsonaleCtxPtr             ctx,
	JSONALE_ARG_IN_ JSONALE_ARG_NNLABLE JsonaleNodePtr            parent,
	JSONALE_ARG_IN_ JSONALE_ARG_NNLABLE JsonaleNodeConstPtr       child
);
JSONALE_C_API JsonaleErr   jsonale_free(
	JSONALE_ARG_IN_ JSONALE_ARG_NNLABLE void**                    data
);

JSONALE_C_API JsonaleErr   jsonale_save(
	JSONALE_ARG_IN_ JSONALE_ARG_NNLABLE JsonaleCtxPtr             ctx,
	JSONALE_ARG_IN_ JSONALE_ARG_NNLABLE JsonaleCStrConst          path
);

#endif /* JSONALE_H */
