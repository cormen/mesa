/* -*- mode: C; c-file-style: "k&r"; tab-width 4; indent-tabs-mode: t; -*- */

/*
 * Copyright (C) 2014 Rob Clark <robclark@freedesktop.org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Authors:
 *    Rob Clark <robclark@freedesktop.org>
 */

#include "pipe/p_defines.h"
#include "util/u_format.h"

#include "fd4_util.h"

/* convert pipe format to vertex buffer format: */
enum a4xx_vtx_fmt
fd4_pipe2vtx(enum pipe_format format)
{
	switch (format) {
	/* 8-bit buffers. */
	case PIPE_FORMAT_R8_UNORM:
		return VFMT4_NORM_UBYTE_8;

	case PIPE_FORMAT_R8_SNORM:
		return VFMT4_NORM_BYTE_8;

	case PIPE_FORMAT_R8_UINT:
	case PIPE_FORMAT_R8_USCALED:
		return VFMT4_UBYTE_8;

	case PIPE_FORMAT_R8_SINT:
	case PIPE_FORMAT_R8_SSCALED:
		return VFMT4_BYTE_8;

	/* 16-bit buffers. */
	case PIPE_FORMAT_R16_UNORM:
	case PIPE_FORMAT_Z16_UNORM:
		return VFMT4_NORM_USHORT_16;

	case PIPE_FORMAT_R16_SNORM:
		return VFMT4_NORM_SHORT_16;

	case PIPE_FORMAT_R16_UINT:
	case PIPE_FORMAT_R16_USCALED:
		return VFMT4_USHORT_16;

	case PIPE_FORMAT_R16_SINT:
	case PIPE_FORMAT_R16_SSCALED:
		return VFMT4_SHORT_16;

	case PIPE_FORMAT_R16_FLOAT:
		return VFMT4_FLOAT_16;

	case PIPE_FORMAT_R8G8_UNORM:
		return VFMT4_NORM_UBYTE_8_8;

	case PIPE_FORMAT_R8G8_SNORM:
		return VFMT4_NORM_BYTE_8_8;

	case PIPE_FORMAT_R8G8_UINT:
	case PIPE_FORMAT_R8G8_USCALED:
		return VFMT4_UBYTE_8_8;

	case PIPE_FORMAT_R8G8_SINT:
	case PIPE_FORMAT_R8G8_SSCALED:
		return VFMT4_BYTE_8_8;

	/* 24-bit buffers. */
	case PIPE_FORMAT_R8G8B8_UNORM:
		return VFMT4_NORM_UBYTE_8_8_8;

	case PIPE_FORMAT_R8G8B8_SNORM:
		return VFMT4_NORM_BYTE_8_8_8;

	case PIPE_FORMAT_R8G8B8_UINT:
	case PIPE_FORMAT_R8G8B8_USCALED:
		return VFMT4_UBYTE_8_8_8;

	case PIPE_FORMAT_R8G8B8_SINT:
	case PIPE_FORMAT_R8G8B8_SSCALED:
		return VFMT4_BYTE_8_8_8;

	/* 32-bit buffers. */
	case PIPE_FORMAT_A8B8G8R8_UNORM:
	case PIPE_FORMAT_A8R8G8B8_UNORM:
	case PIPE_FORMAT_B8G8R8A8_UNORM:
	case PIPE_FORMAT_R8G8B8A8_UNORM:
		return VFMT4_NORM_UBYTE_8_8_8_8;

	case PIPE_FORMAT_R8G8B8A8_SNORM:
		return VFMT4_NORM_BYTE_8_8_8_8;

	case PIPE_FORMAT_R8G8B8A8_UINT:
	case PIPE_FORMAT_R8G8B8A8_USCALED:
		return VFMT4_UBYTE_8_8_8_8;

	case PIPE_FORMAT_R8G8B8A8_SINT:
	case PIPE_FORMAT_R8G8B8A8_SSCALED:
		return VFMT4_BYTE_8_8_8_8;

	case PIPE_FORMAT_R16G16_SSCALED:
	case PIPE_FORMAT_R16G16_SINT:
		return VFMT4_SHORT_16_16;

	case PIPE_FORMAT_R16G16_FLOAT:
		return VFMT4_FLOAT_16_16;

	case PIPE_FORMAT_R16G16_UINT:
	case PIPE_FORMAT_R16G16_USCALED:
		return VFMT4_USHORT_16_16;

	case PIPE_FORMAT_R16G16_UNORM:
		return VFMT4_NORM_USHORT_16_16;

	case PIPE_FORMAT_R16G16_SNORM:
		return VFMT4_NORM_SHORT_16_16;

	case PIPE_FORMAT_R10G10B10A2_UNORM:
		return VFMT4_NORM_UINT_10_10_10_2;

	case PIPE_FORMAT_R10G10B10A2_SNORM:
		return VFMT4_NORM_INT_10_10_10_2;

	case PIPE_FORMAT_R10G10B10A2_UINT:
	case PIPE_FORMAT_R10G10B10A2_USCALED:
		return VFMT4_UINT_10_10_10_2;

	case PIPE_FORMAT_R10G10B10A2_SSCALED:
		return VFMT4_INT_10_10_10_2;

	/* 48-bit buffers. */
	case PIPE_FORMAT_R16G16B16_FLOAT:
		return VFMT4_FLOAT_16_16_16;

	case PIPE_FORMAT_R16G16B16_SINT:
	case PIPE_FORMAT_R16G16B16_SSCALED:
		return VFMT4_SHORT_16_16_16;

	case PIPE_FORMAT_R16G16B16_UINT:
	case PIPE_FORMAT_R16G16B16_USCALED:
		return VFMT4_USHORT_16_16_16;

	case PIPE_FORMAT_R16G16B16_SNORM:
		return VFMT4_NORM_SHORT_16_16_16;

	case PIPE_FORMAT_R16G16B16_UNORM:
		return VFMT4_NORM_USHORT_16_16_16;

	case PIPE_FORMAT_R32_FLOAT:
	case PIPE_FORMAT_Z32_FLOAT:
		return VFMT4_FLOAT_32;

	case PIPE_FORMAT_R32_FIXED:
		return VFMT4_FIXED_32;

	/* 64-bit buffers. */
	case PIPE_FORMAT_R16G16B16A16_UNORM:
		return VFMT4_NORM_USHORT_16_16_16_16;

	case PIPE_FORMAT_R16G16B16A16_SNORM:
		return VFMT4_NORM_SHORT_16_16_16_16;

	case PIPE_FORMAT_R16G16B16A16_UINT:
	case PIPE_FORMAT_R16G16B16A16_USCALED:
		return VFMT4_USHORT_16_16_16_16;

	case PIPE_FORMAT_R16G16B16A16_SINT:
	case PIPE_FORMAT_R16G16B16A16_SSCALED:
		return VFMT4_SHORT_16_16_16_16;

	case PIPE_FORMAT_R32G32_FLOAT:
		return VFMT4_FLOAT_32_32;

	case PIPE_FORMAT_R32G32_FIXED:
		return VFMT4_FIXED_32_32;

	case PIPE_FORMAT_R16G16B16A16_FLOAT:
		return VFMT4_FLOAT_16_16_16_16;

	/* 96-bit buffers. */
	case PIPE_FORMAT_R32G32B32_FLOAT:
		return VFMT4_FLOAT_32_32_32;

	case PIPE_FORMAT_R32G32B32_FIXED:
		return VFMT4_FIXED_32_32_32;

	/* 128-bit buffers. */
	case PIPE_FORMAT_R32G32B32A32_FLOAT:
		return VFMT4_FLOAT_32_32_32_32;

	case PIPE_FORMAT_R32G32B32A32_FIXED:
		return VFMT4_FIXED_32_32_32_32;

/* TODO probably need gles3 blob drivers to find the 32bit int formats:
	case PIPE_FORMAT_R32G32B32A32_SNORM:
	case PIPE_FORMAT_R32G32B32A32_UNORM:
	case PIPE_FORMAT_R32G32B32A32_SINT:
	case PIPE_FORMAT_R32G32B32A32_UINT:

	case PIPE_FORMAT_R32_UINT:
	case PIPE_FORMAT_R32_SINT:
	case PIPE_FORMAT_A32_UINT:
	case PIPE_FORMAT_A32_SINT:
	case PIPE_FORMAT_L32_UINT:
	case PIPE_FORMAT_L32_SINT:
	case PIPE_FORMAT_I32_UINT:
	case PIPE_FORMAT_I32_SINT:

	case PIPE_FORMAT_R32G32_SINT:
	case PIPE_FORMAT_R32G32_UINT:
	case PIPE_FORMAT_L32A32_UINT:
	case PIPE_FORMAT_L32A32_SINT:
*/

	default:
		return ~0;
	}
}

/* convert pipe format to texture sampler format: */
enum a4xx_tex_fmt
fd4_pipe2tex(enum pipe_format format)
{
	switch (format) {
	case PIPE_FORMAT_L8_UNORM:
	case PIPE_FORMAT_A8_UNORM:
	case PIPE_FORMAT_I8_UNORM:
		return TFMT4_NORM_UINT_8;

	case PIPE_FORMAT_B8G8R8A8_UNORM:
	case PIPE_FORMAT_B8G8R8X8_UNORM:
	case PIPE_FORMAT_R8G8B8A8_UNORM:
	case PIPE_FORMAT_R8G8B8X8_UNORM:
	case PIPE_FORMAT_B8G8R8A8_SRGB:
	case PIPE_FORMAT_B8G8R8X8_SRGB:
	case PIPE_FORMAT_R8G8B8A8_SRGB:
	case PIPE_FORMAT_R8G8B8X8_SRGB:
		return TFMT4_NORM_UINT_8_8_8_8;

	case PIPE_FORMAT_Z24X8_UNORM:
		return TFMT4_NORM_UINT_X8Z24;

	case PIPE_FORMAT_Z24_UNORM_S8_UINT:
		return TFMT4_NORM_UINT_8_8_8_8;

//	case PIPE_FORMAT_Z16_UNORM:
//		return TFMT4_NORM_UINT_8_8;
//
	case PIPE_FORMAT_R16G16B16A16_FLOAT:
	case PIPE_FORMAT_R16G16B16X16_FLOAT:
		return TFMT4_FLOAT_16_16_16_16;

	case PIPE_FORMAT_R32G32B32A32_FLOAT:
	case PIPE_FORMAT_R32G32B32X32_FLOAT:
		return TFMT4_FLOAT_32_32_32_32;

	// TODO add more..

	default:
		return ~0;
	}
}

/* convert pipe format to MRT / copydest format used for render-target: */
enum a4xx_color_fmt
fd4_pipe2color(enum pipe_format format)
{
	switch (format) {
	case PIPE_FORMAT_B8G8R8A8_UNORM:
	case PIPE_FORMAT_B8G8R8X8_UNORM:
	case PIPE_FORMAT_R8G8B8A8_UNORM:
		return RB4_R8G8B8A8_UNORM;

	case PIPE_FORMAT_Z16_UNORM:
		return RB4_Z16_UNORM;

	case PIPE_FORMAT_Z24X8_UNORM:
	case PIPE_FORMAT_Z24_UNORM_S8_UINT:
		/* for DEPTHX_24_8, blob driver also seems to use R8G8B8A8 fmt.. */
		return RB4_R8G8B8A8_UNORM;

	case PIPE_FORMAT_R8_UNORM:
	case PIPE_FORMAT_L8_UNORM:
	case PIPE_FORMAT_A8_UNORM:
		return RB4_A8_UNORM;
//
//	case PIPE_FORMAT_R16G16B16A16_FLOAT:
//	case PIPE_FORMAT_R16G16B16X16_FLOAT:
//		return RB4_R16G16B16A16_FLOAT;
//
//	case PIPE_FORMAT_R32G32B32A32_FLOAT:
//	case PIPE_FORMAT_R32G32B32X32_FLOAT:
//		return RB4_R32G32B32A32_FLOAT;

	// TODO add more..

	default:
		return ~0;
	}
}

/* we need to special case a bit the depth/stencil restore, because we are
 * using the texture sampler to blit into the depth/stencil buffer, *not*
 * into a color buffer.  Otherwise fd4_tex_swiz() will do the wrong thing,
 * as it is assuming that you are sampling into normal render target..
 */
enum pipe_format
fd4_gmem_restore_format(enum pipe_format format)
{
	switch (format) {
	case PIPE_FORMAT_Z24X8_UNORM:
	case PIPE_FORMAT_Z24_UNORM_S8_UINT:
	case PIPE_FORMAT_Z16_UNORM:
		return PIPE_FORMAT_B8G8R8A8_UNORM;
	default:
		return format;
	}
}

/* TODO share w/ a3xx?? */
enum a3xx_color_swap
fd4_pipe2swap(enum pipe_format format)
{
	switch (format) {
	case PIPE_FORMAT_B8G8R8A8_UNORM:
	case PIPE_FORMAT_B8G8R8X8_UNORM:
	case PIPE_FORMAT_B8G8R8A8_SRGB:
	case PIPE_FORMAT_B8G8R8X8_SRGB:
		return WXYZ;

	case PIPE_FORMAT_A8R8G8B8_UNORM:
	case PIPE_FORMAT_X8R8G8B8_UNORM:
	case PIPE_FORMAT_A8R8G8B8_SRGB:
	case PIPE_FORMAT_X8R8G8B8_SRGB:
		return ZYXW;

	case PIPE_FORMAT_A8B8G8R8_UNORM:
	case PIPE_FORMAT_X8B8G8R8_UNORM:
	case PIPE_FORMAT_A8B8G8R8_SRGB:
	case PIPE_FORMAT_X8B8G8R8_SRGB:
		return XYZW;

	case PIPE_FORMAT_R8G8B8A8_UNORM:
	case PIPE_FORMAT_R8G8B8X8_UNORM:
	case PIPE_FORMAT_Z24X8_UNORM:
	case PIPE_FORMAT_Z24_UNORM_S8_UINT:
	default:
		return WZYX;
	}
}

static inline enum a4xx_tex_swiz
tex_swiz(unsigned swiz)
{
	switch (swiz) {
	default:
	case PIPE_SWIZZLE_RED:   return A4XX_TEX_X;
	case PIPE_SWIZZLE_GREEN: return A4XX_TEX_Y;
	case PIPE_SWIZZLE_BLUE:  return A4XX_TEX_Z;
	case PIPE_SWIZZLE_ALPHA: return A4XX_TEX_W;
	case PIPE_SWIZZLE_ZERO:  return A4XX_TEX_ZERO;
	case PIPE_SWIZZLE_ONE:   return A4XX_TEX_ONE;
	}
}

uint32_t
fd4_tex_swiz(enum pipe_format format, unsigned swizzle_r, unsigned swizzle_g,
		unsigned swizzle_b, unsigned swizzle_a)
{
	const struct util_format_description *desc =
			util_format_description(format);
	unsigned char swiz[4] = {
			swizzle_r, swizzle_g, swizzle_b, swizzle_a,
	}, rswiz[4];

	util_format_compose_swizzles(desc->swizzle, swiz, rswiz);

	return A4XX_TEX_CONST_0_SWIZ_X(tex_swiz(rswiz[0])) |
			A4XX_TEX_CONST_0_SWIZ_Y(tex_swiz(rswiz[1])) |
			A4XX_TEX_CONST_0_SWIZ_Z(tex_swiz(rswiz[2])) |
			A4XX_TEX_CONST_0_SWIZ_W(tex_swiz(rswiz[3]));
}